#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include<QMainWindow>
#include<QOpenGLWidget>
#include<QDebug>
#include<QOpenGLFunctions_3_3_Core>
#include<QOpenGLTexture>
#include<QTime>

#include"shader.h"
#include"resourcemanager.h"
#include"global.h"

namespace Ui {
    class RenderWindow;
}

class RenderWindow : public QOpenGLWidget
{
public:
   RenderWindow();
   ~RenderWindow();

   virtual void resizeGL(int w,int h);
   virtual void paintGL();
   virtual void initializeGL();
   void keyPressEvent(QKeyEvent *event);
   void mouseMoveEvent(QMouseEvent* event);
   void wheelEvent(QWheelEvent* event);
   GLuint a;
public:

    //render selection
    //enum objectionchoice{ swc,mesh };

    //GLuint VBO,VAO;

    ResourceManager* res;


    QTime my_time;

    QVector3D cameraPos;
    QVector3D cameraFront;
    QVector3D cameraUp;
    GLfloat deltaTime;
    GLfloat lastFrame;

    GLboolean fistmouse;
    GLfloat yaw;
    GLfloat pitch;
    GLfloat lastX;
    GLfloat lastY;
    GLfloat fov;

    QOpenGLFunctions_3_3_Core *my_context;

};

#endif // RENDERWINDOW_H
