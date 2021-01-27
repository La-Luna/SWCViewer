#ifndef RENDERSOMA_H
#define RENDERSOMA_H

#include<QOpenGLFunctions_3_3_Core>

class Rendersoma{
public:
    Rendersoma();
    ~Rendersoma();
    void init();
    void draw();
    float* calSphereCoord(int& num,float radius,int level);
    unsigned int* calTriangleIndex(int& size_triangleindex,int level);
    int size_triangles_index;

private:
    QOpenGLFunctions_3_3_Core *my_context;
    GLuint VBO,VAO,EBO;
    float* spherevertices;
    unsigned int* sphereindexes;
};

#endif // RENDERSOMA_H
