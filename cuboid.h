#ifndef CUBE_H
#define CUBE_H
#include <vector>

#include <parametrics/gmpplane>
#include <parametrics/gmpsphere>
#include <parametrics/gmpcylinder>
#include <scene/gmsceneobject>

#include <collision_interface.h>
#include <collision_library.h>

#include <memory>

class Cuboid : public GMlib::SceneObject {
    GM_SCENEOBJECT(Cuboid)
    public:
        // 6 planes
        std::vector<std::shared_ptr<collision::StaticPPlane>> planes;
    // 12 edges
    //  std::vector <GMlib::PCylinder<float>> cylinders;
    // 8 vertices
    // std::vector <GMlib::PSphere<float>> spheres;

    double x;
    double y;
    double z;

    double a;
    double b;
    double c;

    bool isExist=true;

    GMlib::Material color;

    int id;

    Cuboid(double x, double y, double z, double a, double b, double c, GMlib::Material color, bool isCeilingExist, int id) ;

    Cuboid(double x, double y, double z, double a, GMlib::Material color, bool isCeilingExist, int id )
        : Cuboid (x, y, z, a, a, a, color, isCeilingExist, id) {}
    Cuboid(double x, double y, double z, double a, GMlib::Material color, int id)
        : Cuboid (x, y, z, a, a, a, color, true, id) {}
    Cuboid(double x, double y, double z, double a, double b, double c, GMlib::Material color, int id)
        : Cuboid (x, y, z, a, b, c, color, true, id) {}

    ~Cuboid();

    std::vector<std::shared_ptr<collision::StaticPPlane> > getPlanes() const;

    bool getIsExist() const;

    void setIsExist(bool value);

protected:

private:


}; // END class Cube


#endif // CUBE_H
