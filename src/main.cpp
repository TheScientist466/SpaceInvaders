#include "Headers/ObjectManager.h"
#include "Headers/Global.h"

int main()
{
    ObjectManager objs;
    Global g(&objs);
    g.startLooping();
    return 0;
}