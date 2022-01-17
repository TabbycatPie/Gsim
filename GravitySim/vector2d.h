#ifndef VECTOR2D_H
#define VECTOR2D_H


class Vector2D
{
public:
    Vector2D(double x,double y);
    Vector2D(Vector2D* v2d);
    double getMod();
    double getModSquar(); //get mod^2
    void Normalize();
    Vector2D operator+(const Vector2D& v2d);
    Vector2D operator+(const double& x);
    Vector2D operator*(const double& x);
    Vector2D operator-(const Vector2D& v2d);
    Vector2D operator-(const double& x);
    double dot(const Vector2D& v2d);
    double x;
    double y;

    double fastSqurReci(double number);
};

#endif // VECTOR2D_H
