#ifndef RENDER_H
#define RENDER_H
#include<camera2d.h>
#include <qwidget.h>
#include<scene.h>
class Render
{
public:
    Render(Camera2D* cam,Scene* scene,QWidget* output);

    Camera2D* cur_cam;
    Scene* cur_scene;

    void setOutputWindow(QWidget* window);
    void DrawFrame();
    void Erase();
    void updateOutput();
private:
    QWidget* output;
};

#endif // RENDER_H
