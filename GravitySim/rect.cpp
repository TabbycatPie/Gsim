#include "rect.h"


Rect::Rect(Vector2D *start_pos, int w, int h):Model(start_pos,w,h){
    Model::start_pos = start_pos;
    Model::end_pos = new Vector2D(start_pos->x+w,start_pos->y+h);
}

bool Rect::contain(Vector2D *point)
{
    if(point->x > Model::start_pos->x && point->x < Model::end_pos->x){
        if(point->y > Model::start_pos->y && point->y < Model::end_pos->y){
            return true;
        }else
            return false;
    }else
        return false;
}
