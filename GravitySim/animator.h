#ifndef ANIMATOR_H
#define ANIMATOR_H
#include <render.h>
#include <physicsengine.h>
class Animator
{
public:
    Animator(Render* render,PhysicsEngine* pe,double time_step);
    Render* cur_render;
    PhysicsEngine* cur_pe;
    double cur_time;
    double time_step;
    void NextFrame();
    void Play();
    void Pause();
private:
    bool playing = false;

};

#endif // ANIMATOR_H
