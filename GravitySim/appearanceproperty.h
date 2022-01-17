#ifndef APPEARANCEPROPERTY_H
#define APPEARANCEPROPERTY_H

#include<model.h>
class AppearanceProperty
{
public:
    AppearanceProperty(Model* shape,bool visable);
    Model* shape;
    bool visable;
};

#endif // APPEARANCEPROPERTY_H
