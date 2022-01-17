#ifndef RECT_H
#define RECT_H
#include <vector2d.h>
#include <model.h>
class Rect:public Model
{
public:
    Rect(Vector2D* start_pos,int w,int h);;
    Vector2D* start_pos;
    Vector2D* end_pos;
    bool contain(Vector2D *point) override;
};

#endif // RECT_H
