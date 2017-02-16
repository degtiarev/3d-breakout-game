#include "cube.h"

Cube::~Cube() {

    // if(_cube) remove(_cube.get());
}


Cube::Cube(double x, double y, double z, double a)
{

    this->x=x;//0
    this->y=y;//0
    this->z=z;//0
    this->a=a;//2

    //south
    planes.push_back( new GMlib::PPlane<float>
                      (GMlib::Point<float,3>(-5.0f, -10.0f, 5.0f),
                       GMlib::Vector<float,3>(10.0f, 0.0f, 0.0f),
                       GMlib::Vector<float,3>(0.0f, 0.0f, -10.0f)));
    //east
    planes.push_back( new GMlib::PPlane<float>
                      (GMlib::Point<float,3>(5.0f, -10.0f, 5.0f),
                       GMlib::Vector<float,3>(0.0f, 10.0f, 0.0f),
                       GMlib::Vector<float,3>(0.0f, 0.0f, -10.0f)));
    //north
    planes.push_back( new GMlib::PPlane<float>
                      (GMlib::Point<float,3>(5.0f, 0.0f, 5.0f),
                       GMlib::Vector<float,3>(-10.0f, 0.0f, 0.0f),
                       GMlib::Vector<float,3>(0.0f, 0.0f, -10.0f)));
    //west
    planes.push_back( new GMlib::PPlane<float>
                      (GMlib::Point<float,3>(-5.0f, 0.0f, 5.0f),
                       GMlib::Vector<float,3>(0.0f, -10.0f, 0.0f),
                       GMlib::Vector<float,3>(0.0f, 0.0f, -10.0f)));
    //floor
    planes.push_back( new GMlib::PPlane<float>
                      (GMlib::Point<float,3>(-5.0f, -10.0f, -5.0f),
                       GMlib::Vector<float,3>(10.0f, 0.0f, 0.0f),
                       GMlib::Vector<float,3>(0.0f, 10.0f, 0.0f)));

    //ceiling
    planes.push_back( new GMlib::PPlane<float>
                      (GMlib::Point<float,3>(-5.0f, -10.0f, 5.0f),
                       GMlib::Vector<float,3>(10.0f, 0.0f, 0.0f),
                       GMlib::Vector<float,3>(0.0f, 10.0f, 0.0f)));


    for (const auto& plane : planes)
    {
        plane->toggleDefaultVisualizer();
        plane->replot();
        this->insert(plane);
        setSurroundingSphere(plane->getSurroundingSphere());
    }

}

void Cube::create() {

    //    if(_cube) return;

    //    GMlib::Vector<float,3> d = evaluate(0.0f,0.0f,0,0)[0][0];
    //    _torus = std::make_unique<TestTorus,float,float,float>(1.5f,0.5f,0.5f);


    //    _torus->translate(d + d.getNormalized()*2.0f);
    //    _torus->rotate( GMlib::Angle(90), GMlib::Vector<float,3>( 0.0f, 1.0f, 0.0f) );
    //    _torus->toggleDefaultVisualizer();
    //    _torus->replot(200,200,1,1);
    //    _torus->setMaterial(GMlib::GMmaterial::Emerald);
    //    insert(_torus.get());
}

//void
//TestTorus::localSimulate(double dt) {

//    rotate( GMlib::Angle(90) * dt, GMlib::Vector<float,3>( 0.0f, 0.0f, 1.0f ) );
//    rotate( GMlib::Angle(180) * dt, GMlib::Vector<float,3>( 1.0f, 1.0f, 0.0f ) );
//}
