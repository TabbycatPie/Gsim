#include "vector2d.h"
#include "math.h"
Vector2D::Vector2D(double x,double y)
{
    this->x = x;
    this->y = y;
}

Vector2D::Vector2D(Vector2D *v2d)
{
    this->x = v2d->x;
    this->y = v2d->y;
}


double Vector2D::getMod()
{
    return sqrt(x*x+y*y);
}

double Vector2D::getModSquar()
{
    return x*x+y*y;
}

double Vector2D::fastSqurReci(double number)
{
    long long i;
        double x2, y;
        const double threehalfs = 1.5;

        x2 = number * 0.5;
        y = number;
        i = *(long long*)& y;
        i = 0x5fe6eb50c7b537a9 - (i >> 1);
        y = *(double*) &i;
        y = y * (threehalfs - (x2 * y * y));
        y = y * (threehalfs - (x2 * y * y));

        return y;
}

void Vector2D::Normalize()
{
    double r = fastSqurReci(getModSquar());
    x = x*r;
    y = y*r;
}

Vector2D Vector2D::operator+(const Vector2D &v2d)
{
    return  Vector2D(v2d.x + this->x,v2d.y + this->y);
}

Vector2D Vector2D::operator+(const double &x)
{
    return  Vector2D(x + this->x,x + this->y);
}

Vector2D Vector2D::operator*(const double &x)
{
    return  Vector2D(x * this->x,x * this->y);
}
Vector2D Vector2D::operator-(const Vector2D &v2d)
{
    return  Vector2D(this->x - v2d.x,this->y - v2d.y);
}

Vector2D Vector2D::operator-(const double &x)
{
    return  Vector2D(this->x - x,this->y -x);
}

double Vector2D::dot(const Vector2D &v2d)
{
    return v2d.x*this->x+v2d.y * this->y;
}
