#pragma once
#include <iostream>
#include <vector>

#include "LPolyMesh_Base.h"
#include "MemoryPool.h"

namespace Lunacad {

	namespace polymesh {


class LPolyMesh {
private:
	std::vector<LVert*> vertices_;
	std::vector<LEdge*> edges_;
	std::vector<LHalfEdge*> half_edges_;
	std::vector<LPolyFace*> polygons_;

public:
	LPolyMesh() {}
	~LPolyMesh();


public:
	MemoryPool<LHalfEdge> poolHE;
	MemoryPool<LVert> poolV;
	MemoryPool<LEdge> poolE;
	MemoryPool<LPolyFace> poolF;


	//
};


	}


}

