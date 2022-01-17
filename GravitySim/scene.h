#ifndef SCENE_H
#define SCENE_H
#include<vector>
#include<gameobject.h>
#include<rect.h>
using namespace std;
class Scene
{
public:
    Scene(Rect* space);
    std::vector<GameObject*> go_list;
    Rect* space;
};

#endif // SCENE_H
