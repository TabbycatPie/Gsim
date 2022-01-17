#ifndef CIRCLE_H
#define CIRCLE_H
#include <vector2d.h>
#include <model.h>
class Circle:public Model
{
public:
    Circle(Vector2D *start_pos, int d);
    Circle(Vector2D *center,int r,bool cc);
    Vector2D* start_pos;
    Vector2D* end_pos;
    double getR();
    Vector2D *getCenter();
    void setColor(int r,int g,int b);

    bool contain(Vector2D *point) override;
};

#endif // CIRCLE_H
