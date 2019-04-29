#include "mat2.hpp"

#include <math.h>

//Matrix-Matrix Multiplikation
Mat2& Mat2::operator *=(Mat2 const& m)
{
    e_00 = (m.e_00 * e_00) + (m.e_01 * e_10);
    e_01 = (m.e_00 * e_01) + (m.e_01 * e_11);
    e_10 = (m.e_10 * e_00) + (m.e_11 * e_10);
    e_11 = (m.e_10 * e_01) + (m.e_11 * e_11);
}

Mat2 operator *(Mat2 const& m, Mat2 const& n)
{
    Mat2 answer;

    answer.e_00 = (m.e_00 * n.e_00) + (m.e_01 * n.e_10);
    answer.e_01 = (m.e_00 * n.e_01) + (m.e_01 * n.e_11);
    answer.e_10 = (m.e_10 * n.e_00) + (m.e_11 * n.e_10);
    answer.e_11 = (m.e_10 * n.e_01) + (m.e_11 * n.e_11);

    return answer;
}

//Vektor-Matrix Multiplikation
Vec2 operator *(Mat2 const& m, Vec2 const& v)
{
    Vec2 answer;

    answer.x = (m.e_00 * v.x) + (m.e_01 * v.y);
    answer.y = (m.e_10 * v.x) + (m.e_11 * v.y);
    return answer;
}

Vec2 operator *(Vec2 const& v, Mat2 const& m)
{
    Vec2 answer;

    answer.x = (m.e_00 * v.x) + (m.e_01 * v.y);
    answer.y = (m.e_10 * v.x) + (m.e_11 * v.y);
    return answer;

}

//Determinante
float Mat2::det() const
{
    float det;
    det = (e_00 * e_11) - (e_01 * e_10);
    return det;
}

//inverse Matrix
Mat2 inverse (Mat2 const& m)
{
    Mat2 einheitsM;

    //Rechnung bitte hier rein

    return einheitsM;
}

//transponierte Matrix
Mat2 transpose (Mat2 const& m)
{
    Mat2 erg;

    erg.e_00 = m.e_00;
    erg.e_10 = m.e_01;
    erg.e_01 = m.e_10;
    erg.e_11 = m.e_11;

    return erg;
}

Mat2 make_rotation_mat2(float phi)
{
    Mat2 rotMat;

    rotMat.e_00 = cos(phi);
    rotMat.e_01 = -sin(phi);
    rotMat.e_10 = sin(phi);
    rotMat.e_11 = cos(phi);
    
    return rotMat;
}