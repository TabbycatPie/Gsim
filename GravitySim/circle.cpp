#include "circle.h"

Circle::Circle(Vector2D *start_pos,int d):Model(start_pos,d,d)
{
    Model::start_pos = start_pos;
    Model::end_pos = new Vector2D(start_pos->x+d,start_pos->y+d);
}

Circle::Circle(Vector2D *center, int r, bool cc):Model(center,r,r)
{
    if(cc){
    int temp = (int)r;
    Model::start_pos = new Vector2D(center->x-(double)temp,center->y-(double)temp);
    Model::end_pos = new Vector2D(center->x + temp,center->y + temp);
    delete center;
    }
    else{
       Circle(center,2*r);
    }
}

double Circle::getR()
{
    return (Model::end_pos->x - Model::start_pos->x)/2.0;
}

Vector2D* Circle::getCenter()
{
    return new Vector2D((*Model::start_pos + *Model::end_pos)*0.5);
}

void Circle::setColor(int r, int g, int b)
{
    Model::color.data()[0] = r;
    Model::color.data()[1] = g;
    Model::color.data()[2] = b;
}

bool Circle::contain(Vector2D *point)
{
    if((*point - getCenter()).getMod() < this->getR())
        return true;
    else
        return false;
}
