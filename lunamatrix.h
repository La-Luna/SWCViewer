#ifndef LUNAMATRIX_H
#define LUNAMATRIX_H
#include"include/vec3.h"

class LMatrix4
{

public:
    LMatrix4(){
        for (int i = 0; i < 16; i++){
            if (i % 5 == 0)matrix[i] = 1;
            else matrix[i] = 0;
        }
    }
    LMatrix4(const float array[16]);
    LMatrix4(float a0, float a1, float a2, float a3,//col 1
        float a4, float a5, float a6, float a7,//col2
        float a8, float a9, float a10, float a11,//col3
        float a12, float a13, float a14, float a15//col4
        );
    LMatrix4(const LMatrix4& tm);

    float matrix[16];
    vec4 operator*(const vec4& temp)const;
    LMatrix4 operator*(const LMatrix4& A)const;


};

#endif // LUNAMATRIX_H
