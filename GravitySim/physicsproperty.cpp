#include "physicsproperty.h"


PhysicsProperty::PhysicsProperty(Vector2D* v, double mass, Vector2D* pos, Vector2D* f)
{
    this->v = v;
    this->mass = mass;
    this->position = pos;
    this->force = f;
}
