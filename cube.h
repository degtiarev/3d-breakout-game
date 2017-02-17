#ifndef CUBE_H
#define CUBE_H
#include <vector>

#include <parametrics/gmpplane>
#include <parametrics/gmpsphere>
#include <parametrics/gmpcylinder>
#include <scene/gmsceneobject>

#include <collision_interface.h>

#include <memory.h>

class Cube : public GMlib::SceneObject {
    GM_SCENEOBJECT(Cube)
    public:
    // 6 planes
     std::vector <GMlib::PPlane<float>*> planes;
    // 12 edges
    //  std::vector <GMlib::PCylinder<float>> cylinders;
    // 8 vertices
    // std::vector <GMlib::PSphere<float>> spheres;

    double x;
    double y;
    double z;

    double a;
    \
    GMlib::Material color;

    Cube(double, double, double, double, GMlib::Material);
    ~Cube();

    void create();

protected:
    // void localSimulate(double dt) override;

private:


}; // END class Cube


#endif // CUBE_H
