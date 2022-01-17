#ifndef CAMERA2D_H
#define CAMERA2D_H
#include<rect.h>

class Camera2D
{
public:
    Camera2D(Rect *view);
    void setCallback(void (*cb)());
    Rect* view;
    void MoveVertical(int step);
    void MoveHorizone(int step);
    void Zoom(double step);
    void (*CameraMovementCallBack)();
private:
    void MovementCall();
    bool callable = false;
};

#endif // CAMERA2D_H
