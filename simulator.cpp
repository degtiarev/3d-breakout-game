#include "simulator.h"



Simulator::Simulator(GMlib::Scene &scene) : _scene{scene} {}


void Simulator::setupSimulator()
{
    _dspheres.push_back(std::make_unique<Dynsphere>());
    _dspheres.back()->velocity=GMlib::Vector<double,3> (1.0f, 1.0f, 0.0f);

    _planes.push_back(std::make_unique<Plane>
                      (GMlib::Point<float,3>(-10.0f, -10.0f, 5.0f),
                       GMlib::Vector<float,3>(20.0f, 0.0f, 0.0f),
                       GMlib::Vector<float,3>(0.0f, 0.0f, -5.0f)));


    _planes.push_back(std::make_unique<Plane>
                      (GMlib::Point<float,3>(10.0f, -10.0f, 5.0f),
                       GMlib::Vector<float,3>(0.0f, 20.0f, 0.0f),
                       GMlib::Vector<float,3>(0.0f, 0.0f, -5.0f)));

    _planes.push_back(std::make_unique<Plane>
                      (GMlib::Point<float,3>(10.0f, 10.0f, 5.0f),
                       GMlib::Vector<float,3>(-20.0f, 0.0f, 0.0f),
                       GMlib::Vector<float,3>(0.0f, 0.0f, -5.0f)));

    _planes.push_back(std::make_unique<Plane>
                      (GMlib::Point<float,3>(-10.0f, 10.0f, 5.0f),
                       GMlib::Vector<float,3>(0.0f, -20.0f, 0.0f),
                       GMlib::Vector<float,3>(0.0f, 0.0f, -5.0f)));


_scene.insert(&_controller);


//    _planes.push_back(std::make_unique<Plane>
//                      (GMlib::Point<float,3>(-10.0f, -10.0f, 20.0f),
//                       GMlib::Vector<float,3>(20.0f, 0.0f, 0.0f),
//                       GMlib::Vector<float,3>(0.0f, 0.0f, -20.0f)));


//    _planes.push_back(std::make_unique<Plane>
//                      (GMlib::Point<float,3>(10.0f, -10.0f, 20.0f),
//                       GMlib::Vector<float,3>(0.0f, 20.0f, 0.0f),
//                       GMlib::Vector<float,3>(0.0f, 0.0f, -20.0f)));

//    _planes.push_back(std::make_unique<Plane>
//                      (GMlib::Point<float,3>(10.0f, 10.0f, 20.0f),
//                       GMlib::Vector<float,3>(-20.0f, 0.0f, 0.0f),
//                       GMlib::Vector<float,3>(0.0f, 0.0f, -20.0f)));

//    _planes.push_back(std::make_unique<Plane>
//                      (GMlib::Point<float,3>(-10.0f, 10.0f, 20.0f),
//                       GMlib::Vector<float,3>(0.0f, -20.0f, 0.0f),
//                       GMlib::Vector<float,3>(0.0f, 0.0f, -20.0f)));


    for (const auto& sphere : _dspheres)
        prepareAndInsert(sphere , 10, 10, 1 ,1);

    for (const auto& plane : _planes)
        prepareAndInsert(plane , 10, 10, 1 ,1);

}
