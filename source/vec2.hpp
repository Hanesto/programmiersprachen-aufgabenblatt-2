# ifndef VEC2_HPP
# define VEC2_HPP
// Vec2 data type definition
struct Vec2
{
    float x = 0.0f;
    float y = 0.0f;

    Vec2& operator += (Vec2 const& v);
    Vec2& operator -= (Vec2 const& v);
    Vec2& operator *= (float s);
    Vec2& operator /= (float s);
};

Vec2& Vec2::operator += (Vec2 const& v)
{
    x += v.x;
    y += v.y;
    return *this;
}

Vec2& Vec2::operator -= (Vec2 const& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

Vec2& Vec2::operator *= (float s)
{
    x = x*s;
    y = y*s;
    return *this;
}

Vec2& Vec2::operator /= (float s)
{
    x = x/s;
    y = y/s;
    return *this;
}

# endif // VEC2_HPP