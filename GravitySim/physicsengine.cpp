#include "physicsengine.h"
#include <gameobject.h>
#include <math.h>
PhysicsEngine::PhysicsEngine(Scene* sc)
{
    this->cur_sc = sc;
}

void PhysicsEngine::updatePhysicalStatus(double dtime)
{
    updateForceStatus();
    updateVelocityStatus(dtime);
    updatePositionStatus(dtime);
}

void PhysicsEngine::updateForceStatus()
{
    //clear last force status
    for(unsigned long long i =0; i<cur_sc->go_list.size();i++){
        GameObject* tempgo = cur_sc->go_list.data()[i];
        delete tempgo->pp->force;
        tempgo->pp->force = new Vector2D(0,0);
    }
    for(unsigned long long i =0; i<cur_sc->go_list.size();i++){
        GameObject* tempgo = cur_sc->go_list.data()[i];
        Vector2D* gof1 = tempgo->pp->force;
        Vector2D* gop1 = tempgo->pp->position;
        double gom1 = tempgo->pp->mass;
        for(unsigned long long j =i+1;j<cur_sc->go_list.size();j++){
            GameObject* tempgo2= cur_sc->go_list.data()[j];
            Vector2D* gof2 = tempgo2->pp->force;
            Vector2D* gop2 = tempgo2->pp->position;
            double gom2 = tempgo2->pp->mass;
            //calculat total force
            double gf_val = 1000000 * (gom1 * gom2)/(*gop1-*gop2).getModSquar();
            Vector2D f12 = (*gop2 - *gop1);
            f12.Normalize();
            f12 = f12 * gf_val;
            *gof1 = *gof1 + f12;
            f12 = f12 * (-1.0);
            *gof2 = *gof2 + f12;
        }
    }
}

void PhysicsEngine::updateVelocityStatus(double dtime)
{
    for(unsigned long long i =0; i<cur_sc->go_list.size();i++){
        GameObject* tempgo = cur_sc->go_list.data()[i];
        Vector2D* gov = tempgo->pp->v;
        double gom = tempgo->pp->mass;
        Vector2D* gof = tempgo->pp->force;
        gov->x += gof->x/gom*dtime;
        gov->y += gof->y/gom*dtime;
    }
}

void PhysicsEngine::updatePositionStatus(double dtime)
{
    for(unsigned long long i =0; i<cur_sc->go_list.size();i++){
        GameObject* tempgo = cur_sc->go_list.data()[i];
        Vector2D* gov = tempgo->pp->v;
        Vector2D* gop = tempgo->pp->position;
        gop->x += gov->x * dtime;
        gop->y += gov->y * dtime;
    }
}
