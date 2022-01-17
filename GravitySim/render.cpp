#include "render.h"

#include <qpainter.h>


Render::Render(Camera2D *cam, Scene *scene, QWidget *output)
{
    this->cur_cam = cam;
    this->cur_scene = scene;
    setOutputWindow(output);
}

void Render::setOutputWindow(QWidget *window)
{
    this->output = window;
}

void Render::DrawFrame()
{
    QPainter painter(this->output);
    painter.setRenderHint(QPainter:: Antialiasing, true);

    for(unsigned long long i =0;i<cur_scene->go_list.size();i++){
        GameObject *gtemp = cur_scene->go_list.data()[i];
        if(cur_cam->view->contain(gtemp->pp->position)){
            painter.setPen(QPen(QColor(gtemp->ap->shape->color.data()[0],gtemp->ap->shape->color.data()[1],gtemp->ap->shape->color.data()[2]),3));
            painter.setBrush(QBrush(QColor(gtemp->ap->shape->color.data()[0],gtemp->ap->shape->color.data()[1],gtemp->ap->shape->color.data()[2])));
            Vector2D* reltV2d = new Vector2D((*gtemp->pp->position - *cur_cam->view->getStart_pos()));
            painter.drawEllipse(reltV2d->x - gtemp->ap->shape->getWidth()/2.0,reltV2d->y - gtemp->ap->shape->getWidth()/2.0,gtemp->ap->shape->getWidth(),gtemp->ap->shape->getHeight());
            delete reltV2d;
        }

    }
}

void Render::Erase()
{
    QPainter painter(this->output);
    painter.setRenderHint(QPainter:: Antialiasing, true);
    //painter.setBrush(QBrush(QColor(0,0,0)));
    painter.eraseRect(0,0,1000,1000);
}

void Render::updateOutput()
{
    //Erase();
    DrawFrame();
}
