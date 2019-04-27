#include "mat2.hpp"

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