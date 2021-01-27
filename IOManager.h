#pragma once
#include <string>
#include <iostream>
#include <vector>


#include"LPolyMesh.h"


namespace Lunacad {
	namespace polymesh {
		struct IOOptions
		{
			bool vert_has_normal;
			bool vert_has_texture;
			bool vert_has_color;

			bool face_has_color;
			bool face_has_texture;

			bool color_has_alpha;

			IOOptions() :vert_has_color(false), vert_has_texture(false), vert_has_normal(false), face_has_color(false), face_has_texture(false), color_has_alpha(false) {}
			void clear() {
				vert_has_normal = false;
				vert_has_texture = false;
				vert_has_color = false;

				face_has_color = false;
				face_has_texture = false;

				color_has_alpha = false;
			}

		};
	
		bool loadMesh(std::string fpath, std::string fname);
		bool loadMesh(std::string fpath, std::string fname, IOOptions& opt);



		class OBJReader {
		public:

			OBJReader() {};
			~OBJReader() {};
			
			bool read(); 

		};


	}
}