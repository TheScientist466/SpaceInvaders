#include "Headers/ObjectManager.h"
#include "Headers/Global.h"

#include <iostream>

int main()
{
    ObjectManager objs;
    Global g(&objs);
    g.startLooping();
    return 0;
}