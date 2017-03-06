#include "cuboid.h"

void Cuboid::setIsExist(bool value)
{
    isExist = value;
}

Cuboid::Cuboid(double x, double y, double z, double a, double b, double c, GMlib::Material color, bool isCeilingExist, int id)
{
    this->x=x;//0
    this->y=y;//0
    this->z=z;//0
    this->a=a;//2
    this->b=b;//2
    this->c=c;//2

    this->id=id;

    double a1=a/2;
    double b1=b/2;
    double c1=c/2;

    this->color=color;

    //south
    planes.push_back( std::make_unique<collision::StaticPPlane>
                      (GMlib::Point<float,3>(x+a1, y+b1, z+c1),
                       GMlib::Vector<float,3>(-a, 0.0f, 0.0f),
                       GMlib::Vector<float,3>(0.0f, 0.0f, -c)));

    //north
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(x+a1, y-b1, z-c1),
                      GMlib::Vector<float,3>(-a, 0.0f, 0.0f),
                      GMlib::Vector<float,3>(0.0f, 0.0f, c)));


    //west
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(x-a1, y-b1, z-c1),
                      GMlib::Vector<float,3>(0.0f, b, 0.0f),
                      GMlib::Vector<float,3>(0.0f, 0.0f, c)));

    //east
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(x+a1, y-b1, z+c1),
                      GMlib::Vector<float,3>(0.0f, b, 0.0f),
                      GMlib::Vector<float,3>(0.0f, 0.0f, -c)));

    //floor
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(x-a1, y-b1, z-c1),
                      GMlib::Vector<float,3>(a, 0.0f, 0.0f),
                      GMlib::Vector<float,3>(0.0f, b, 0.0f)));


    //ceiling
    if ( isCeilingExist)
        planes.push_back(std::make_unique<collision::StaticPPlane>
                         (GMlib::Point<float,3>(x-a1, y-b1, z+c1),
                          GMlib::Vector<float,3>(a, 0.0f, 0.0f),
                          GMlib::Vector<float,3>(0.0f, b, 0.0f)));



    for ( auto& plane : planes)
    {
        plane->setId(id);
        plane->toggleDefaultVisualizer();
        plane->replot();
        plane->setMaterial(color);
        this->insert(plane.get());
    }
    setSurroundingSphere(GMlib::Sphere<float,3>(GMlib::Point<float,3>(0.0f,0.0f,0.0f),1.0f));
}


Cuboid::~Cuboid() {

    std::cout<<"destructor";
}

std::vector<std::shared_ptr<collision::StaticPPlane> > Cuboid::getPlanes() const
{
    return planes;
}

bool Cuboid::getIsExist() const
{
    return isExist;
}
