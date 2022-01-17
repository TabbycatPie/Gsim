#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <physicsproperty.h>
#include "appearanceproperty.h"

class GameObject
{
public:
    GameObject(PhysicsProperty* pp,AppearanceProperty* ap);
    PhysicsProperty *pp;
    AppearanceProperty *ap;
};

#endif // GAMEOBJECT_H
