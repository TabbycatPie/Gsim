#ifndef PHYSICSPROPERTY_H
#define PHYSICSPROPERTY_H
#include <vector2d.h>

class PhysicsProperty
{
public:
    PhysicsProperty(Vector2D* v,double mass,Vector2D* pos,Vector2D* f);
    Vector2D* v;
    double mass;
    Vector2D* position;
    Vector2D* force;
};

#endif // PHYSICSPROPERTY_H
