#include "gravitysim.h"
#include "ui_gravitysim.h"
#include <QPainter>
#include <render.h>
#include <scene.h>
#include <camera2d.h>
#include <physicsproperty.h>
#include <appearanceproperty.h>
#include <circle.h>
#include <rect.h>
#include <animator.h>
#include<QPushButton>
#include <QKeyEvent>
Render* pub_render;
void updateRender(){
    pub_render->updateOutput();
}

GravitySim::GravitySim(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GravitySim)
{
    ui->setupUi(this);

    Camera2D* cam = new Camera2D(new Rect(new Vector2D(0,0),1000,1000));
    Scene* s = new Scene(new Rect(new Vector2D(0,0),100000,100000));
    pub_render = new Render(cam,s,ui->canvas);
    cam->setCallback(updateRender);
    //sun
    PhysicsProperty *pp = new PhysicsProperty(new Vector2D(0,0),5,new Vector2D(300,300),new Vector2D(0,0));
    Circle* c = new Circle(new Vector2D(100,100),20,true);
    c->setColor(255,80,80);
    AppearanceProperty *ap = new AppearanceProperty(c,true);
    GameObject* sun = new GameObject(pp,ap);
    s->go_list.push_back(sun);
    //earth
    PhysicsProperty* pp_earth = new PhysicsProperty(new Vector2D(100,0),1,new Vector2D(300,500),new Vector2D(0,0));
    Circle* c_earth = new Circle(new Vector2D(50,50),10,true);
    c_earth->setColor(80,80,255);
    AppearanceProperty* ap_earth = new AppearanceProperty(c_earth,true);
    GameObject* earth = new GameObject(pp_earth,ap_earth);
    s->go_list.push_back(earth);

    //moon
    PhysicsProperty* pp_moon = new PhysicsProperty(new Vector2D(200,0),1,new Vector2D(300,600),new Vector2D(0,0));
    Circle* c_moon = new Circle(new Vector2D(20,20),5,true);
    c_moon->setColor(80,255,80);
    AppearanceProperty* ap_moon = new AppearanceProperty(c_moon,true);
    GameObject* moon = new GameObject(pp_moon,ap_moon);
    s->go_list.push_back(moon);


    PhysicsEngine* pe = new PhysicsEngine(s);
    Animator *am = new Animator(pub_render,pe,0.05);

    connect(ui->btn_next,&QPushButton::clicked,this,[=]{
        am->NextFrame();
    });
    connect(ui->btn_play,&QPushButton::clicked,this,[=]{
        am->Play();
    });
    connect(ui->btn_pause,&QPushButton::clicked,this,[=]{
        am->Pause();
    });
}

GravitySim::~GravitySim()
{
    delete ui;
}


void GravitySim::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key::Key_Up){
        pub_render->cur_cam->MoveVertical(10);
    }
    if(ev->key() == Qt::Key::Key_Down){
        pub_render->cur_cam->MoveVertical(-10);
    }
    if(ev->key() == Qt::Key::Key_Left){
        pub_render->cur_cam->MoveHorizone(-10);
    }
    if(ev->key() == Qt::Key::Key_Right){
        pub_render->cur_cam->MoveHorizone(10);
    }

}

