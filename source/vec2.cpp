#include <iostream>
#include "vec2.hpp"
/*
    Vec2& Vec2::operator += (Vec2 const& v)
    {
        x = x + v.x;
        y = y + v.y;
        return *this;
    }

    Vec2& Vec2::operator -= (Vec2 const& v)
    {
        x = x - v.x;
        y = y - v.y;
        return *this;
    }
*/
    int main()
    {
        try
        {
            Vec2 a; // requires that 0.0f == a . x and 0.0f == a.y

            if (a.x != 0.0f || a.y != 0.0f) {
                throw 0;
            }       

            Vec2 b{5.1f , -9.3f}; // requires that 5.1 f == approx (a.y) and -9.3 f == approx (b.y)    
        }
        catch(int)
        {
            std::cout << "Eine der Standardinitialisierungen ist nicht null" << '\n';
        }  
    }
