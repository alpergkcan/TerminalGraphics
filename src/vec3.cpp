#include "vec3.h"


vec3::vec3()
{
    x = y = z = 0;
}

vec3::vec3(double _x,double _y,double _z)
{
    x = _x; y = _y; z = _z;
}

vec3 vec3::operator*(const double rhs)
{
    return vec3(x*rhs,y*rhs,z*rhs);
}

vec3 vec3::operator*(const float rhs)
{
    return vec3(x*rhs,y*rhs,z*rhs);
}

vec3 vec3::operator+(const vec3& rhs)
{
    return vec3(x+rhs.x, y+rhs.y, z+rhs.z);
}

vec3 vec3::operator-(const vec3& rhs)
{
    vec3 temp;
    temp.x = x-rhs.x;
    temp.y = y-rhs.y;
    temp.z = z-rhs.z;
    return temp;
}


double vec3::operator[](int ind)
{
    switch(ind)
    {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            break;
    }
	return ERROR;
}

void vec3::normalize()
{
    double mag = magnitude();
    x /= mag;
    y /= mag;
    z /= mag;
}

double vec3::magnitude() const
{
    return sqrt(x*x + y*y + z*z);
}

vec3 vec3::normalized() const
{
    double mag = magnitude();
    return vec3(x/mag,y/mag,z/mag);

}

vec3 vec3::cross_product(vec3 u, vec3 v)
{
    return vec3(u.y*v.z-u.z*v.y,
    -(u.x*v.z-u.z*v.x),
    u.x*v.y-u.y*v.x);
}