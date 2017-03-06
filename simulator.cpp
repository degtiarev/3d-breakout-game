#include "simulator.h"



Simulator::Simulator(GMlib::Scene &scene) : _scene{scene} {}


void Simulator::setupSimulator()
{

    //testing spheres ***********************************************************
    //    _dspheres.push_back(std::make_unique<DynSphere>());
    //    _dspheres.push_back(std::make_unique<DynSphere>());
    //    _dspheres.push_back(std::make_unique<DynSphere>());
    //    _dspheres.push_back(std::make_unique<DynSphere>());
    //    _dspheres.push_back(std::make_unique<DynSphere>());
    //    _dspheres.push_back(std::make_unique<DynSphere>());
    //    _dspheres.push_back(std::make_unique<DynSphere>());
    //    _dspheres.push_back(std::make_unique<DynSphere>());

    //    _dspheres.back()->setMaterial(GMlib::GMmaterial::chrome());
    //    _dspheres.at(0)->setMaterial(GMlib::GMmaterial::obsidian());
    //    _dspheres.at(1)->setMaterial(GMlib::GMmaterial::plastic());
    //    _dspheres.at(2)->setMaterial(GMlib::GMmaterial::polishedGreen());
    //    _dspheres.at(3)->setMaterial(GMlib::GMmaterial::brass());
    //    _dspheres.at(4)->setMaterial(GMlib::GMmaterial::sapphire());
    //    _dspheres.at(5)->setMaterial(GMlib::GMmaterial::gold());
    //    _dspheres.at(6)->setMaterial(GMlib::GMmaterial::jade());
    //    _dspheres.at(7)->setMaterial(GMlib::GMmaterial::pewter());

    //    _dspheres.back()->translateGlobal(GMlib::Vector<float,3>(5.0f,0.0f, 30.0f));
    //    _dspheres.at(0)->translateGlobal(GMlib::Vector<float,3> (0.0f, 5.0f, 20.0f));
    //    _dspheres.at(1)->translateGlobal(GMlib::Vector<float,3> (10.0f, 0.0f, 30.0f));
    //    _dspheres.at(2)->translateGlobal(GMlib::Vector<float,3> (0.0f, 10.0f, 20.0f));
    //    _dspheres.at(3)->translateGlobal(GMlib::Vector<float,3> (5.0f, 0.0f, 30.0f));
    //    _dspheres.at(4)->translateGlobal(GMlib::Vector<float,3> (0.0f, 5.0f, 20.0f));
    //    _dspheres.at(5)->translateGlobal(GMlib::Vector<float,3> (-5.0f, 0.0f, 30.0f));
    //    _dspheres.at(6)->translateGlobal(GMlib::Vector<float,3> (0.0f, -5.0f, 20.0f));

    //    _dspheres.back()->velocity=GMlib::Vector<double,3> (0.0f, -10.0f, 0.0f);
    //    _dspheres.at(0)->velocity=GMlib::Vector<double,3> (1.0f, 10.0f, 0.0f);
    //    _dspheres.at(1)->velocity=GMlib::Vector<double,3> (2.0f, -10.0f, 0.0f);
    //    _dspheres.at(2)->velocity=GMlib::Vector<double,3> (3.0f, 10.0f, 0.0f);
    //    _dspheres.at(3)->velocity=GMlib::Vector<double,3> (4.0f, -10.0f, 0.0f);
    //    _dspheres.at(4)->velocity=GMlib::Vector<double,3> (5.0f, 10.0f, 0.0f);
    //    _dspheres.at(5)->velocity=GMlib::Vector<double,3> (6.0f, -10.0f, 0.0f);
    //    _dspheres.at(6)->velocity=GMlib::Vector<double,3> (7.0f, 10.0f, 0.0f);
    //    _dspheres.at(7)->velocity=GMlib::Vector<double,3> (8.0f, -10.0f, 0.0f);

    //    _dspheres.back()->velocity=GMlib::Vector<double,3>(0.0f, 0.0f, 0.0f);
    //    _dspheres.at(0)->velocity=GMlib::Vector<double,3> (0.0f, 0.0f, 0.0f);
    //    _dspheres.at(1)->velocity=GMlib::Vector<double,3> (0.0f, 0.0f, 0.0f);
    //    _dspheres.at(2)->velocity=GMlib::Vector<double,3> (0.0f, 0.0f, 0.0f);
    //    _dspheres.at(3)->velocity=GMlib::Vector<double,3> (0.0f, 0.0f, 0.0f);
    //    _dspheres.at(4)->velocity=GMlib::Vector<double,3> (0.0f, 0.0f, 0.0f);
    //    _dspheres.at(5)->velocity=GMlib::Vector<double,3> (0.0f, 0.0f, 0.0f);
    //    _dspheres.at(6)->velocity=GMlib::Vector<double,3> (0.0f, 0.0f, 0.0f);
    //    _dspheres.at(7)->velocity=GMlib::Vector<double,3> (0.0f, 0.0f, 0.0f);

    //        _planes.push_back(std::make_unique<Plane>
    //                          (GMlib::Point<float,3>(-10.0f, -10.0f, 5.0f),
    //                           GMlib::Vector<float,3>(20.0f, 0.0f, 0.0f),
    //                           GMlib::Vector<float,3>(0.0f, 0.0f, -5.0f)));


    //    _planes.push_back(std::make_unique<Plane>
    //                      (GMlib::Point<float,3>(10.0f, -10.0f, 5.0f),
    //                       GMlib::Vector<float,3>(0.0f, 20.0f, 0.0f),
    //                       GMlib::Vector<float,3>(0.0f, 0.0f, -5.0f)));

    //    _planes.push_back(std::make_unique<Plane>
    //                      (GMlib::Point<float,3>(10.0f, 10.0f, 5.0f),
    //                       GMlib::Vector<float,3>(-20.0f, 0.0f, 0.0f),
    //                       GMlib::Vector<float,3>(0.0f, 0.0f, -5.0f)));

    //    _planes.push_back(std::make_unique<Plane>
    //                      (GMlib::Point<float,3>(-10.0f, 10.0f, 5.0f),
    //                       GMlib::Vector<float,3>(0.0f, -20.0f, 0.0f),
    //                       GMlib::Vector<float,3>(0.0f, 0.0f, -5.0f)));

    //        _planes.push_back(std::make_unique<Plane>
    //                          (GMlib::Point<float,3>(-10.0f, -10.0f, 0.0f),
    //                           GMlib::Vector<float,3>(20.0f, 0.0f, 0.0f),
    //                           GMlib::Vector<float,3>(0.0f, 20.0f, 0.0f)));
    //  _planes.back()->setOpaque(true);

    //  ************************************************************************



    //    _planes.push_back(std::make_unique<Plane>
    //                      (GMlib::Point<float,3>(-10.0f, -10.0f, 0.0f),
    //                       GMlib::Vector<float,3>(20.0f, 0.0f, 0.0f),
    //                       GMlib::Vector<float,3>(0.0f, 20.0f, 0.0f)));


    //    _planes.push_back(std::make_unique<Plane>
    //                      (GMlib::Point<float,3>(-10.0f, -10.0f, 10.0f),
    //                       GMlib::Vector<float,3>(20.0f, 0.0f, 0.0f),
    //                       GMlib::Vector<float,3>(0.0f, 20.0f, 0.0f)));

    //    _dspheres.push_back(std::make_unique<DynSphere> ());
    //    _dspheres.back()->translateGlobal(GMlib::Vector<float,3> (0.0f,0.0f, 10.0f));
    //    _dspheres.back()->velocity=GMlib::Vector<double,3> (0.0f, 0.0f, -1.0f);
    //    _dspheres.back()->setMaterial(GMlib::GMmaterial::chrome());




    _planes.push_back(std::make_unique<Plane>
                      (GMlib::Point<float,3>(0.0f, 0.0f, 35.0f),
                       GMlib::Vector<float,3>(0.0f, 5.0f, 0.0f),
                       GMlib::Vector<float,3>(8.0f, 0.0f, 0.0f)));

    //     _planes.push_back(std::make_unique<Plane>
    //                          (GMlib::Point<float,3>(-50, -50, 80.0f),
    //                           GMlib::Vector<float,3>(100.0f, 0.0f, 0.0f),
    //                           GMlib::Vector<float,3>(0.0f, 100.0f, 0.0f)));

    _controll_plane= (_planes.at(0).get());

    _cubes.push_back(std::make_unique<Cuboid>(0 ,0 ,0 ,30 ,20 , 60 ,GMlib::GMmaterial::brass(), false, INT_MAX));

    std::shared_ptr<CubeMatrix> matrix = std::make_shared< CubeMatrix>(6, 4, 6, -15, -10, -30, 5);
    for (const auto& cube : matrix->getArray3D())
        _cubes.push_back(cube);

    _dspheres.push_back(std::make_unique<DynSphere> ());
    _dspheres.back()->setRadius(2.5);
    _dspheres.back()->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 10.0f));
    _dspheres.back()->velocity=GMlib::Vector<double,3> (0.0f, 0.0f, -30.0f);
    _dspheres.back()->setMaterial(GMlib::GMmaterial::blackPlastic());

    //        _dspheres.push_back(std::make_unique<DynSphere> ());
    //        _dspheres.back()->setRadius(2.5);
    //        _dspheres.back()->translateGlobal(GMlib::Vector<float,3> (-5.0f, 0.0f, 10.0f));
    //        _dspheres.back()->velocity=GMlib::Vector<double,3> (0.0f, 0.0f, -40.0f);
    //        _dspheres.back()->setMaterial(GMlib::GMmaterial::bronze());

    //        _dspheres.push_back(std::make_unique<DynSphere> ());
    //        _dspheres.back()->setRadius(2.5);
    //        _dspheres.back()->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 10.0f));
    //        _dspheres.back()->velocity=GMlib::Vector<double,3> (0.0f, 0.0f, -50.0f);
    //        _dspheres.back()->setMaterial(GMlib::GMmaterial::chrome());

    //        _dspheres.push_back(std::make_unique<DynSphere> ());
    //        _dspheres.back()->setRadius(2.5);
    //        _dspheres.back()->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 10.0f));
    //        _dspheres.back()->velocity=GMlib::Vector<double,3> (0.0f, 0.0f, -70.0f);
    //        _dspheres.back()->setMaterial(GMlib::GMmaterial::ruby());


    for (const auto& cube : _cubes)
        prepareAndInsert(cube , 10, 10, 1 ,1);
    for (const auto& plane : _planes)
        prepareAndInsert(plane , 10, 10, 1 ,1);
    for (const auto& sphere : _dspheres)
        prepareAndInsert(sphere , 10, 10, 1 ,1);

    _scene.insert(&_controller);

}
