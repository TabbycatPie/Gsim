#include "animator.h"

#include <QThread>


Animator::Animator(Render *render, PhysicsEngine *pe, double time_step)
{
   this->cur_pe = pe;
   this->cur_time = 0.0;
   this->time_step = time_step;
   this->cur_render = render;
}

void Animator::NextFrame()
{
    cur_pe->updatePhysicalStatus(time_step);
    cur_render->updateOutput();
    cur_time += time_step;
}

void Animator::Play()
{
    this->playing = true;
    int i = 100;
    while(i--){
        NextFrame();
        QThread::msleep(1000*time_step);
    }
}

void Animator::Pause()
{
    this->playing = false;
}
