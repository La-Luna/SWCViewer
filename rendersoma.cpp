#include"rendersoma.h"
#include"global.h"
#include<cmath>
#include"math.h"
#include<iostream>
Rendersoma::Rendersoma(){
    this->init();
}
Rendersoma::~Rendersoma(){
    my_context->glDeleteVertexArrays(1,&VAO);
    delete[] sphereindexes;
    delete[] spherevertices;
}
float* Rendersoma::calSphereCoord(int& num, float radius, int level){
    //delta，float[],+color
    int array_size = (level + 1)*(level + 1) * 6;
    float* array = new float[array_size];
    //double dtheta, dphi;
    //dtheta = (2 * PI) / level;
    //dphi = PI / level;
    float dtheta = 360.0 / level;
    float dphi = 180.0 / level;

    float cx, cy, cz;

    for (int i = 0; i <= level; i++){//phi
        for (int j = 0; j <= level; j++){//theta
            float phi_temp =angle2radian(i*dphi) ;
            float theta_temp =angle2radian(j*dtheta) ;
            cx = radius*std::sin(phi_temp)*std::cos(theta_temp);
            cy = radius*std::cos(phi_temp);
            cz = radius*std::sin(phi_temp)*std::sin(theta_temp);
            int curpos = (i*(level+1) + j) * 6;

            array[curpos + 0] = cx;
            array[curpos + 1] = cy;
            array[curpos + 2] = cz;
            array[curpos + 3] = 0.0;
            array[curpos + 4] = 0.0;
            array[curpos + 5] = 1.0;

        }
    }
//	for (int i = 0; i < array_size; i++){
//		if (i % 6 == 0)cout << endl;
//		cout << array[i] << " ";
//	}
    num = array_size;
    return array;

}
unsigned int*  Rendersoma::calTriangleIndex(int& size_triangleindex, int level){
    //data
    int indexarray_size = level*level * 2 * 3;
    unsigned int* indexarray = new unsigned int[indexarray_size];
    unsigned int upl, upr, botl, botr;

    //for ,upl,upr,botl,botr
    for (int i = 0; i < level; i++){
        for (int j = 0; j < level; j++){
            upr = i*(level+1)+j; upl = upr + 1;
            botr =upr + level+1; botl = botr + 1;
            int curpos = (i*level + j) * 6;
            indexarray[curpos + 0] = upr;
            indexarray[curpos + 1] = upl;
            indexarray[curpos + 2] = botr;

            indexarray[curpos + 3] = botr;
            indexarray[curpos + 4] = botl;
            indexarray[curpos + 5] = upl;
        }
    }
//	for (int i = 0; i < indexarray_size; i++){
//		if (i % 6 == 0)cout << endl;
//		cout << indexarray[i] << " ";
//	}
    size_triangleindex = indexarray_size;
    return indexarray;

}
void Rendersoma::init(){
    my_context=QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();

    //generate vertices
    int size_spherevcertices;
    spherevertices= calSphereCoord(size_spherevcertices,1.0,12);

    //generate indexes;

    sphereindexes=calTriangleIndex(size_triangles_index,12);


    my_context->glGenVertexArrays(1,&VAO);
    my_context->glGenBuffers(1,&VBO);
    my_context->glGenBuffers(1,&EBO);

    my_context->glBindVertexArray(VAO);
    my_context->glBindBuffer(GL_ARRAY_BUFFER,VBO);
    my_context->glBufferData(GL_ARRAY_BUFFER,size_spherevcertices*4,spherevertices,GL_STATIC_DRAW);
    //my_context->glBufferData(GL_ARRAY_BUFFER,sizeof(cubevertices),cubevertices,GL_STATIC_DRAW);
    my_context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    my_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER,size_triangles_index*4,sphereindexes,GL_STATIC_DRAW);

    my_context->glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);
    my_context->glEnableVertexAttribArray(0);
    my_context->glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)(3*sizeof(float)));
    my_context->glEnableVertexAttribArray(1);

    my_context->glBindBuffer(GL_ARRAY_BUFFER,0);
    my_context->glBindVertexArray(0);


}
void Rendersoma::draw(){
    my_context->glBindVertexArray(VAO);
    //my_context->glDrawArrays(GL_TRIANGLES,0,36);
   my_context->glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    my_context->glDrawElements(GL_TRIANGLES,size_triangles_index,GL_UNSIGNED_INT,0);
}

