#ifndef MODEL_H
#define MODEL_H
#include<vector>
#include<vector2d.h>
using namespace std;
class Model
{
public:
    Model(Vector2D* start_pos,int w,int h);
    int getWidth();
    int getHeight();
    Vector2D* start_pos;
    Vector2D* end_pos;
    std::vector<int> color;
    virtual bool contain(Vector2D *point)=0;
    Vector2D *getStart_pos() const;
    void setStart_pos(Vector2D *value);
    Vector2D *getEnd_pos() const;
    void setEnd_pos(Vector2D *value);
};

#endif // MODEL_H
