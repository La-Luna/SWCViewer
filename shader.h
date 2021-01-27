#ifndef SHADER_H
#define SHADER_H
#include<QDebug>
#include<QOpenGLShader>
#include<QOpenGLShaderProgram>
#include<QString>
#include<QMatrix4x4>

class Shader{
public:
    Shader();

    void compile(const QString& vshaderfile,const QString& fshadefile,const QString& gshaderfile=NULL);
    ~Shader();
    QOpenGLShaderProgram *shaderProgram;//resourcemanager可以删除



public:
    void setMat4(const QString& name,const QMatrix4x4& value);
    void setInt(const QString& name,const GLuint& value);



    Shader& use(){
        shaderProgram->bind();
        return *this;
    }
};




#endif // SHADER_H
