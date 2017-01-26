#include "simulator.h"



Simulator::Simulator(GMlib::Scene &scene) : _scene{scene} {}


void Simulator::setupSimulator()
{
    _dspheres.push_back(std::make_unique<Dynsphere>());
    _dspheres.push_back(std::make_unique<Dynsphere>());
    _dspheres.push_back(std::make_unique<Dynsphere>());
    _dspheres.push_back(std::make_unique<Dynsphere>());

    _dspheres.back()->setMaterial(GMlib::GMmaterial::chrome());
    _dspheres.at(0)->setMaterial(GMlib::GMmaterial::obsidian());
    _dspheres.at(1)->setMaterial(GMlib::GMmaterial::plastic());
    _dspheres.at(2)->setMaterial(GMlib::GMmaterial::polishedGreen());


    _dspheres.back()->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));
    _dspheres.at(0)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));
    _dspheres.at(1)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));
    _dspheres.at(2)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));

    _dspheres.back()->velocity=GMlib::Vector<double,3> (20.0f, 10.0f, 0.0f);
    _dspheres.at(0)->velocity=GMlib::Vector<double,3> (10.0f, -10.0f, 0.0f);
    _dspheres.at(1)->velocity=GMlib::Vector<double,3> (15.0f, -10.0f, 0.0f);
    _dspheres.at(2)->velocity=GMlib::Vector<double,3> (25.0f, 10.0f, 0.0f);

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

    _planes.push_back(std::make_unique<Plane>
                      (GMlib::Point<float,3>(-10.0f, -10.0f, 0.0f),
                       GMlib::Vector<float,3>(20.0f, 0.0f, 0.0f),
                       GMlib::Vector<float,3>(0.0f, 20.0f, 0.0f)));



    _scene.insert(&_controller);


    //        _planes.push_back(std::make_unique<Plane>
    //                          (GMlib::Point<float,3>(-10.0f, -10.0f, 20.0f),
    //                           GMlib::Vector<float,3>(20.0f, 0.0f, 0.0f),
    //                           GMlib::Vector<float,3>(0.0f, 0.0f, -20.0f)));


    //        _planes.push_back(std::make_unique<Plane>
    //                          (GMlib::Point<float,3>(10.0f, -10.0f, 20.0f),
    //                           GMlib::Vector<float,3>(0.0f, 20.0f, 0.0f),
    //                           GMlib::Vector<float,3>(0.0f, 0.0f, -20.0f)));

    //        _planes.push_back(std::make_unique<Plane>
    //                          (GMlib::Point<float,3>(10.0f, 10.0f, 20.0f),
    //                           GMlib::Vector<float,3>(-20.0f, 0.0f, 0.0f),
    //                           GMlib::Vector<float,3>(0.0f, 0.0f, -20.0f)));

    //        _planes.push_back(std::make_unique<Plane>
    //                          (GMlib::Point<float,3>(-10.0f, 10.0f, 20.0f),
    //                           GMlib::Vector<float,3>(0.0f, -20.0f, 0.0f),
    //                           GMlib::Vector<float,3>(0.0f, 0.0f, -20.0f)));


    for (const auto& sphere : _dspheres)
        prepareAndInsert(sphere , 10, 10, 1 ,1);

    for (const auto& plane : _planes)
        prepareAndInsert(plane , 10, 10, 1 ,1);

}
