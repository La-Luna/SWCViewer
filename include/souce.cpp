#include<iostream>
#include"swcfiledata.h"
#include"neurogeometry.h"
using namespace std;
int main(){
    //读一个oldfile.swc
    //shared_ptr<SwcFileData> oldfiledata=make_shared<SwcFileData>("","test.swc");
    string filename="test";
    SwcFileData* oldfiledata=new SwcFileData("",filename+".swc"); 
    NeuroGeometry* neurogeo=new NeuroGeometry(oldfiledata);
    //对swcfiledata做一些操作
    //操作0：把neuropointslist中的数据都输出
    //oldfiledata->printNeuropointsList();
    //操作1：得到soma点的位置
    //vec3 somapos=oldfiledata->getSomaPosition();
    //操作2:找到所有在soma的sphere内的点，并把这些点输出到newfile.swc中,已经在构造函数中执行
    //操作3：找到所有半径比较大的points、
    //neurogeo->findLargeRadiusPoints();
    //操作4：把所有points的半径都置为固定值
    neurogeo->changePointsRadius();
    //操作5:把所有的points类型设置为3
    neurogeo->changePointsType();
    //neurogeo->printpointlist("after change radius:the newneuropointslist ",neurogeo->newneuropointslist);
    //输出到newfile.swc中
    string newfilename=filename+"new"+".swc";
    neurogeo->createNewSwcFIle(newfilename,"newneuropointlist",neurogeo->newneuropointslist);



    delete oldfiledata;
    return 1;
}