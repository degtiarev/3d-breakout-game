#include "cube.h"

Cube::~Cube() {

    // if(_cube) remove(_cube.get());
}


Cube::Cube(double x, double y, double z)
{

    this->x=x;
    this->y=y;
    this->z=z;

    auto pPlane = new GMlib::PPlane<float>
            (GMlib::Point<float,3>(-10.0f, 10.0f, 20.0f),
             GMlib::Vector<float,3>(0.0f, -20.0f, 0.0f),
             GMlib::Vector<float,3>(0.0f, 0.0f, -20.0f));


    planes.push_back(pPlane);
    planes[0]->toggleDefaultVisualizer();
    // for (auto i=0; i<planes.size(); i++)
    planes[0]->replot();
    this->insert(planes[0]);
    setSurroundingSphere(planes[0]->getSurroundingSphere());

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
