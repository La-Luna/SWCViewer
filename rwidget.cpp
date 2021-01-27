#include "rwidget.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include"shader.h"
#include<QKeyEvent>
#include<QPoint>

#include<QString>
#include<string>

#include "resourcemanager.h"




RenderWindow::RenderWindow()
{
    this->setWindowTitle("RenderSWC");
}
RenderWindow::~RenderWindow(){
    delete res;
}

void RenderWindow::initializeGL() {
    my_context=QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();
    ResourceManager::loadShader("neurite",":/shader/triangle.vert",":/shader/triangle.frag");
    ResourceManager::loadShader ("soma",":/shader/cube.vert",":/shader/cube.frag");

    //renderneurite=new RenderNeurite();
    //rendersoma=new Rendersoma();


    //renderneurite->init();
    //rendersoma->init();
    //res = new ResourceManager(swctype,"", "test4.swc");
    res = new ResourceManager("", "test2.swc");
    //string fname = "Bigmax_White_OBJ.obj";
    //res = new ResourceManager(meshtype, "", fname);//!!

    //从改变顶点数据，生成一张新的obj开始。



    my_time.start();
    my_context->glEnable(GL_DEPTH_TEST);


    //cameraPos=QVector3D(0.0f,0.0f,300.0f);
    cameraPos=QVector3D(0.0f,0.0f,3.0f);
    cameraFront=QVector3D(0.0f,0.0f,-1.0f);
    cameraUp=QVector3D(0.0f,1.0f,0.0f);

    deltaTime=0.0f;
    lastFrame=0.0f;

    yaw=-90.0f;
    pitch=0.0f;
    lastX=800/2.0f;
    lastY=400/2.0f;
    fov=45.0;




}
void RenderWindow::resizeGL(int w,int h){
    my_context->glViewport(0,0,w,h);
}
void RenderWindow::paintGL(){
    GLfloat currentFrame=(GLfloat)my_time.elapsed()/100;
    deltaTime=currentFrame-lastFrame;
    lastFrame=currentFrame;

    my_context->glClearColor(0.2f,0.2f,0.3f,1.0f);
    my_context->glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 projection;
    projection.perspective(60.0f,(GLfloat)width()/(GLfloat)height(),0.1f,1000.0f);
    QMatrix4x4 model;
    QMatrix4x4 view;
    view.lookAt(cameraPos,cameraPos+cameraFront,cameraUp);
    //transform.translate(QVector3D());
    //elapsed返回自start()函数开始的毫秒


    ResourceManager::getShader("neurite").use();
    ResourceManager::getShader("neurite").setMat4("model",model);
    ResourceManager::getShader("neurite").setMat4("projection",projection);
    ResourceManager::getShader("neurite").setMat4("view",view);

    res->renderneurite->draw();
    //renderneurite->drawNeuroNode();
    //renderneurite->drawNeuriteLine();
    my_context->glUseProgram(0);

    ResourceManager::getShader("soma").use();
    ResourceManager::getShader("soma").setMat4("model",model);
    ResourceManager::getShader("soma").setMat4("projection",projection);
    ResourceManager::getShader("soma").setMat4("view",view);
    res->rendersoma->draw();

    my_context->glUseProgram(0);




    update();
}
void RenderWindow::keyPressEvent(QKeyEvent *event){
    GLfloat cameraspeed=2.5*deltaTime;
    if(event->key()==Qt::Key_W){
        cameraPos+=cameraFront*cameraspeed;
    }
    if(event->key()==Qt::Key_S){
        cameraPos-=cameraFront*cameraspeed;

    }
    if(event->key()==Qt::Key_A){
        cameraPos+=(QVector3D::crossProduct(cameraFront,cameraUp).normalized())*cameraspeed;
    }
    if(event->key()==Qt::Key_D){
        cameraPos-=(QVector3D::crossProduct(cameraFront,cameraUp).normalized())*cameraspeed;
    }
    if(event->key()==Qt::Key_Q){
        cameraPos+=cameraUp*cameraspeed;
    }
    if(event->key()==Qt::Key_E){
        cameraPos-=cameraUp*cameraspeed;
    }

}
void RenderWindow::mouseMoveEvent(QMouseEvent* event){
    GLfloat xpos=event->pos().x();
    GLfloat ypos=event->pos().y();

    if(fistmouse){
        lastX=event->pos().x();
        lastY=event->pos().y();
        fistmouse=false;
    }

    GLfloat xoffset=xpos-lastX;
    GLfloat yoffset=ypos-lastY;
    lastX=xpos;
    lastY=ypos;

    GLfloat sensitivity=0.001f;
    xoffset*=sensitivity;
    yoffset*=sensitivity;

    yaw-=xoffset;
    pitch+=yoffset;


    if(pitch>89.0f)pitch=89.0f;
    if(pitch<-89.0f)pitch=-89.0f;

    QVector3D front(cos(yaw)*cos(pitch),sin(pitch),sin(yaw)*cos(pitch));

    cameraFront=front.normalized();

}

void RenderWindow::wheelEvent(QWheelEvent* event){
    QPoint offset=event->angleDelta();
    if(fov >= 1.0f && fov <=45.0f)
        fov -= ((GLfloat)offset.y())/20;
    if(fov < 1.0f)
        fov = 1.0f;
    if(fov > 45.0f)
        fov = 45.0f;

}
