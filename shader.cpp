#include"shader.h"
#include<QOpenGLShader>
Shader::Shader(){}

void Shader::compile(const QString& vshaderfile,const QString& fshadefile,const QString& gshaderfile){

    QOpenGLShader vertexhshader(QOpenGLShader::Vertex);
    bool success=vertexhshader.compileSourceFile(vshaderfile);
    if(!success){
        qDebug()<<"ERROR::SHADER::VERTEX::COMPILATION_FAILED"<<endl;
        qDebug()<<vertexhshader.log()<<endl;
    }

    QOpenGLShader fragmentShader(QOpenGLShader::Fragment);
    success=fragmentShader.compileSourceFile(fshadefile);
    if(!success){
        qDebug()<<"ERROR::SHADER::FRAGMENT::COMPILATION_FAILED"<<endl;
        qDebug()<<fragmentShader.log()<<endl;
    }

    shaderProgram=new QOpenGLShaderProgram();
    shaderProgram->addShader(&vertexhshader);
    shaderProgram->addShader(&fragmentShader);
    success=shaderProgram->link();
    if(!success){
        qDebug()<<"ERROR::SHADER::PROGRAM::LINK_FAILED"<<endl;
        qDebug()<<shaderProgram->log()<<endl;
    }
}

Shader::~Shader(){}
void Shader::setMat4(const QString& name,const QMatrix4x4& value){
    GLuint loc=this->shaderProgram->uniformLocation(name);
    shaderProgram->setUniformValue(loc,value);
}

void Shader::setInt(const QString& name,const GLuint& value){
    GLuint loc=this->shaderProgram->uniformLocation(name);
    shaderProgram->setUniformValue(loc,value);
}
