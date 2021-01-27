#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include<map>
#include<QString>

#include"shader.h"
#include"rendersoma.h"
#include"renderneurite.h"
#include "LPolyMesh.h"
using namespace Lunacad::polymesh;
class ResourceManager{
public:
    static std::map<QString,Shader> map_shaders;
	Rendersoma* rendersoma=NULL;
	RenderNeurite* renderneurite=NULL;
    //mesh resource
    //LPolyMesh mesh;


    static Shader loadShader(const QString& name,const QString&vshaderfile,const QString&fshaderfile,const QString& gshdaderfile=NULL);
    static Shader getShader(const QString& name);

    static void clear();



    public:
    ResourceManager() {};
    //ResourceManager(objectionchoice mode,string fpath, string fname);
    ResourceManager( string fpath, string fname);
    ~ResourceManager() { delete renderneurite; delete rendersoma; }
	//std::string fname = "test4.swc";
	//std::string fpath = "";
};

#endif // RESOURCEMANAGER_H
