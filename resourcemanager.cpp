#include"resourcemanager.h"
#include "LPolyMesh.h"
std::map<QString,Shader> ResourceManager::map_shaders;

//ResourceManager::ResourceManager(objectionchoice mode,string fpath,string fname) {
//    //if (mode == swctype) {
//		renderneurite = new RenderNeurite(fpath, fname);
//		rendersoma = new Rendersoma();
//    //}
//    //else if(mode == meshtype) {
//    //    mesh = new LPolyMesh(fpath, fname);
//    //}
//    //rendersoma->init();
//
//
//	
//	//rendersoma->init();
//}
ResourceManager::ResourceManager( string fpath, string fname) {
	//if (mode == swctype) {
	renderneurite = new RenderNeurite(fpath, fname);
	rendersoma = new Rendersoma();
	//}
	//else if(mode == meshtype) {
	//    mesh = new LPolyMesh(fpath, fname);
	//}
	//rendersoma->init();



	//rendersoma->init();
}
 Shader ResourceManager::loadShader(const QString& name,const QString&vshaderfile,const QString& fshaderfile,const QString& gshaderfile){
    Shader shader;
    shader.compile(vshaderfile,fshaderfile,gshaderfile==NULL?NULL:gshaderfile);
    map_shaders[name]=shader;
    return map_shaders[name];
 }

 Shader ResourceManager::getShader(const QString& name){
     return map_shaders[name];

 }

void ResourceManager::clear(){
     for(std::map<QString,Shader>::iterator iter=map_shaders.begin();iter!=map_shaders.end();iter++){
         delete iter->second.shaderProgram;
     }
}
