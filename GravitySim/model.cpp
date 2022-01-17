#include "model.h"
#include <vector2d.h>
Model::Model(Vector2D *start_pos, int w, int h)
{
    this->start_pos = start_pos;
    this->end_pos = new Vector2D(start_pos->x + w,start_pos->y + h);
    this->color.push_back(255);//r
    this->color.push_back(255);//g
    this->color.push_back(255);//b
}

int Model::getWidth()
{
    return this->end_pos->x - this->start_pos->x;
}

int Model::getHeight()
{
    return this->end_pos->y - this->start_pos->y;
}

Vector2D *Model::getEnd_pos() const
{
    return end_pos;
}

void Model::setEnd_pos(Vector2D *value)
{
    end_pos = value;
}

Vector2D *Model::getStart_pos() const
{
    return start_pos;
}

void Model::setStart_pos(Vector2D *value)
{
    start_pos = value;
}

