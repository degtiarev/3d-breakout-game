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

    //    _planes.push_back(std::make_unique<Plane>
    //                      (GMlib::Point<float,3>(-10.0f, -10.0f, 5.0f),
    //                       GMlib::Vector<float,3>(20.0f, 0.0f, 0.0f),
    //                       GMlib::Vector<float,3>(0.0f, 0.0f, -5.0f)));


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

    //    _planes.push_back(std::make_unique<Plane>
    //                      (GMlib::Point<float,3>(-10.0f, -10.0f, 0.0f),
    //                       GMlib::Vector<float,3>(20.0f, 0.0f, 0.0f),
    //                       GMlib::Vector<float,3>(0.0f, 20.0f, 0.0f)));
    //  _planes.back()->setOpaque(true);

    //  ************************************************************************



    //  big planes  ***********************************************************
    /*        _planes.push_back(std::make_unique<Plane>
                              (GMlib::Point<float,3>(-10.0f, -10.0f, 20.0f),
                               GMlib::Vector<float,3>(20.0f, 0.0f, 0.0f),
                               GMlib::Vector<float,3>(0.0f, 0.0f, -20.0f)));


            _planes.push_back(std::make_unique<Plane>
                              (GMlib::Point<float,3>(10.0f, -10.0f, 20.0f),
                               GMlib::Vector<float,3>(0.0f, 20.0f, 0.0f),
                               GMlib::Vector<float,3>(0.0f, 0.0f, -20.0f)));

            _planes.push_back(std::make_unique<Plane>
                              (GMlib::Point<float,3>(10.0f, 10.0f, 20.0f),
                               GMlib::Vector<float,3>(-20.0f, 0.0f, 0.0f),
                               GMlib::Vector<float,3>(0.0f, 0.0f, -20.0f)));

            _planes.push_back(std::make_unique<Plane>
                              (GMlib::Point<float,3>(-10.0f, 10.0f, 20.0f),
                               GMlib::Vector<float,3>(0.0f, -20.0f, 0.0f),
                             GMlib::Vector<float,3>(0.0f, 0.0f, -20.0f))); */
    //  ************************************************************************




    _cubes.push_back(std::make_unique< Cube>(0,0,0,5, GMlib::GMmaterial::jade() ));
    _cubes.push_back(std::make_unique< Cube>(1,2,1,3, GMlib::GMmaterial::copper() ));
    _cubes.push_back(std::make_unique< Cube>(3,10,1,4, GMlib::GMmaterial::snow() ));
    _cubes.push_back(std::make_unique< Cube>(-3,2,1,4, GMlib::GMmaterial::blackRubber() ));
    _cubes.push_back(std::make_unique< Cube>(5,-1,1,4, GMlib::GMmaterial::obsidian() ));
    _cubes.push_back(std::make_unique< Cube>(8,2,0,5, GMlib::GMmaterial::sapphire()));


    //    std::cout<<_cubes[0].getPos();


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


    for (const auto& cube : _cubes)
        prepareAndInsert(cube , 10, 10, 1 ,1);
    for (const auto& plane : _planes)
        prepareAndInsert(plane , 10, 10, 1 ,1);
    for (const auto& sphere : _dspheres)
        prepareAndInsert(sphere , 10, 10, 1 ,1);



    _scene.insert(&_controller);

}
