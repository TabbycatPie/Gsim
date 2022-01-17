#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include <scene.h>

class PhysicsEngine
{
public:
    PhysicsEngine(Scene* sc);
    Scene* cur_sc;
    void updatePhysicalStatus(double dtime);
private:
    void updateForceStatus();
    void updateVelocityStatus(double dtime);
    void updatePositionStatus(double dtime);
};

#endif // PHYSICSENGINE_H
