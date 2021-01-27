
#include"renderneurite.h"
#include"include/swcfiledata.h"
#include"include/neurogeometry.h"
//class NeuroGeometry;

//NeuroGeometry* neurogeo;
RenderNeurite::RenderNeurite(string fpath, string fname){
    this->init(fpath, fname);
}

RenderNeurite::~RenderNeurite(){
    my_context->glDeleteVertexArrays(1,&VAO);
    delete this->neurogeo;
    //delete this->vertexindexarray;
}

void RenderNeurite::init(string fpath, string fname){
    //vao vbo part
    //read swc data
    my_context=QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();


    SwcFileData* oldfiledata=new SwcFileData(fpath,fname);
    //SwcFileData* oldfiledata=new SwcFileData("","test2.swc");
    neurogeo=new NeuroGeometry(oldfiledata);

    //float* vertices=neurogeo->getlinedata(this->pointsnum);//line
    vertices=neurogeo->getCylinderVerticeArray(this->verticesnum);//triangle,cylendar
    std::cout<<"the neuropoints num : "<<this->neurogeo->neuropointslist.size()<<std::endl;
    vertexindexarray=neurogeo->getFaceIndexArray(this->indexarraysize);

    this->verticecoverbit=this->verticesnum*4;//triangle,cylendar
    //this->verticesnum=this->pointsnum*2;//line
    //this->verticecoverbit=this->pointsnum*2*6*4;//line
    my_context->glGenVertexArrays(1,&VAO);
    my_context->glGenBuffers(1,&VBO);
    my_context->glGenBuffers(1,&EBO);

    my_context->glBindVertexArray(VAO);
    my_context->glBindBuffer(GL_ARRAY_BUFFER,VBO);
    my_context->glBufferData(GL_ARRAY_BUFFER,this->verticecoverbit,&vertices[0],GL_STATIC_DRAW);//triangle,cylendar
    //my_context->glBufferData(GL_ARRAY_BUFFER,this->verticecoverbit,vertices,GL_STATIC_DRAW);//line
    my_context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    my_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER,indexarraysize*4,&vertexindexarray[0],GL_STATIC_DRAW);

    my_context->glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);
    my_context->glEnableVertexAttribArray(0);
    my_context->glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)(3*sizeof(float)));
    my_context->glEnableVertexAttribArray(1);

    my_context->glBindBuffer(GL_ARRAY_BUFFER,0);
    my_context->glBindVertexArray(0);


    //神经元节点元的数据（球）
    neurodevertices=neurogeo->getNeuroNodeVerticeArray(this->neurodeverticesize);
    std::cout<<"the neurodevertices size is : "<<this->neurodevertices.size()<<std::endl;
    std::cout<<"the sizeof float is : "<<sizeof(float)<<std::endl;
    neurodevertexindexarray=neurogeo->getNeuroNodeFaceIndexArray(this->neurodeindexarraysize);

    my_context->glGenVertexArrays(1,&nodeVAO);
    my_context->glGenBuffers(1,&nodeVBO);
    my_context->glGenBuffers(1,&nodeEBO);

    my_context->glBindVertexArray(nodeVAO);
    my_context->glBindBuffer(GL_ARRAY_BUFFER,nodeVBO);
    my_context->glBufferData(GL_ARRAY_BUFFER,this->neurodeverticesize*4,&(this->neurodevertices[0]),GL_STATIC_DRAW);//???
    my_context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,nodeEBO);
    my_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER,this->neurodeindexarraysize*4,&(this->neurodevertexindexarray[0]),GL_STATIC_DRAW);
    my_context->glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);
    my_context->glEnableVertexAttribArray(0);
    my_context->glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*(sizeof(float)),(void*)(3*sizeof(float)));
    my_context->glEnableVertexAttribArray(1);

    my_context->glBindBuffer(GL_ARRAY_BUFFER,0);
    my_context->glBindVertexArray(0);


    //神经元节点的数据（线段）
    linevertices=neurogeo->getlinedata(this->lineverticessize);

    my_context->glGenVertexArrays(1,&lineVAO);
    my_context->glGenBuffers(1,&lineVBO);

    my_context->glBindVertexArray(lineVAO);
    my_context->glBindBuffer(GL_ARRAY_BUFFER,lineVBO);
    my_context->glBufferData(GL_ARRAY_BUFFER,this->lineverticessize*4,&(this->linevertices[0]),GL_STATIC_DRAW);//???
    my_context->glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);
    my_context->glEnableVertexAttribArray(0);
    my_context->glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*(sizeof(float)),(void*)(3*sizeof(float)));
    my_context->glEnableVertexAttribArray(1);

    my_context->glBindBuffer(GL_ARRAY_BUFFER,0);
    my_context->glBindVertexArray(0);

}

void RenderNeurite::drawNeuriteLine(){
    my_context->glBindVertexArray(lineVAO);
    my_context->glLineWidth(3);//line
    my_context->glDrawArrays(GL_LINES,0,this->lineverticessize);//line
    //my_context->glPointSize(4);
    //my_context->glDrawArrays(GL_POINTS,0,this->lineverticessize);
}

void RenderNeurite::draw(){

    my_context->glBindVertexArray(VAO);
    //my_context->glLineWidth(3);//line
    //my_context->glDrawArrays(GL_LINES,0,this->verticesnum);//line

    my_context->glDrawElements(GL_TRIANGLES,this->indexarraysize,GL_UNSIGNED_INT,0);//triangle,cylendar
   // my_context->glPointSize(4);
   //my_context->glDrawArrays(GL_POINTS,0,this->indexarraysize);

}
    void RenderNeurite::drawNeuroNode(){
        my_context->glBindVertexArray(nodeVAO);
        //my_context->glLineWidth(3);//line
        //my_context->glDrawArrays(GL_LINES,0,this->verticesnum);//line
//869184
         //my_context->glDrawElements(GL_TRIANGLES,869184,GL_UNSIGNED_INT,0);
       // std::cout<<"the neurodeface index array size is : "<<this->neurodeindexarraysize<<std::endl;
        my_context->glDrawElements(GL_TRIANGLES,this->neurodeindexarraysize,GL_UNSIGNED_INT,0);//triangle,cylendar
        //my_context->glPointSize(4);
        //my_context->glDrawArrays(GL_POINTS,0,this->neurodeindexarraysize);
    }
