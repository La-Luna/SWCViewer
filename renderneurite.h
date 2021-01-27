#ifndef RENDERNEURITE_H
#define RENDERNEURITE_H

#include<QOpenGLFunctions_3_3_Core>
#include"include/neurogeometry.h"
//class NeuroGeometry;
class RenderNeurite{
public:
    RenderNeurite(string fpath, string fname);
    ~RenderNeurite();
    void init(string fpath,string fname);
    void draw();
    void drawNeuroNode();
    void drawNeuriteLine();
private:
    int pointsnum=0;
    int  verticesnum=0;
    int verticecoverbit=0;

    int indexarraysize;

    int neurodeverticesize;
    int neurodeindexarraysize;

    int lineverticessize;
    //int* vertexindexarray;
    vector<unsigned int> vertexindexarray;
    vector<unsigned int> neurodevertexindexarray;

    vector<float> vertices;
    vector<float>  neurodevertices;
    vector<float> linevertices;
    NeuroGeometry* neurogeo;

    GLuint VAO,VBO,EBO;

    GLuint nodeVAO,nodeVBO,nodeEBO;

    GLuint lineVAO,lineVBO,lineEBO;


    QOpenGLFunctions_3_3_Core* my_context;
};

#endif // RENDERNEURITE_H
