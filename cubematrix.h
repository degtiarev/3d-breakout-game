#ifndef CUBEMATRIX_H
#define CUBEMATRIX_H
#include <vector>

#include <parametrics/gmpplane>
#include <parametrics/gmpsphere>
#include <parametrics/gmpcylinder>
#include <scene/gmsceneobject>

#include <collision_interface.h>
#include "cuboid.h"

#include <memory>


class CubeMatrix
{
public:

    CubeMatrix(int height, int width, int depth, double startX, double startY, double startZ, double a);

    std::vector<std::shared_ptr<Cuboid>> array3D;
    int height;
    int width;
    int depth;

    double startX;
    double startY;
    double startZ;

    double a;

    std::shared_ptr<Cuboid> getElement (int x, int y, int z);

    std::vector<std::shared_ptr<Cuboid> > getArray3D() const;
};

#endif // CUBEMATRIX_H
