#include "gameobject.h"


GameObject::GameObject(PhysicsProperty *pp, AppearanceProperty *ap)
{
    this->pp = pp;
    this->ap = ap;
}
