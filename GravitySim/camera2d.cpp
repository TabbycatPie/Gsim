#include "camera2d.h"



Camera2D::Camera2D(Rect *view)
{
    this->view = view;
}

void Camera2D::setCallback(void (*cb)())
{
    this->CameraMovementCallBack = cb;
    this->callable = true;
}

void Camera2D::MoveVertical(int step)
{
    this->view->getStart_pos()->y += step;
    this->view->getEnd_pos()->y += step;
    this->MovementCall();
}

void Camera2D::MoveHorizone(int step)
{
    this->view->getStart_pos()->x += step;
    this->view->getEnd_pos()->x += step;
    this->MovementCall();
}

void Camera2D::Zoom(double step)
{
    this->view->getStart_pos()->x *= (1.0+step);
    this->view->getStart_pos()->y *= (1.0+step);
    this->view->getEnd_pos()->x *= (1.0+step);
    this->view->getEnd_pos()->y *= (1.0+step);
    this->MovementCall();

}

void Camera2D::MovementCall()
{
    if(callable){
        this->CameraMovementCallBack();
    }
}
