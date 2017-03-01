#include "simulator.h"



Simulator::Simulator(GMlib::Scene &scene) : _scene{scene} {}

void Simulator::SimulateReplotSim()
{
    myFemObject1->replot();
    myFemObject2->replot();
}


void Simulator::setupSimulator()
{
    //    _dspheres.push_back(std::make_unique<Dynsphere>());
    //    _dspheres.push_back(std::make_unique<Dynsphere>());
    //    _dspheres.push_back(std::make_unique<Dynsphere>());
    //    _dspheres.push_back(std::make_unique<Dynsphere>());
    //    _dspheres.push_back(std::make_unique<Dynsphere>());
    //    _dspheres.push_back(std::make_unique<Dynsphere>());
    //    _dspheres.push_back(std::make_unique<Dynsphere>());
    //    _dspheres.push_back(std::make_unique<Dynsphere>());

    //    _dspheres.back()->setMaterial(GMlib::GMmaterial::chrome());
    //    _dspheres.at(0)->setMaterial(GMlib::GMmaterial::obsidian());
    //    _dspheres.at(1)->setMaterial(GMlib::GMmaterial::plastic());
    //    _dspheres.at(2)->setMaterial(GMlib::GMmaterial::polishedGreen());
    //    _dspheres.at(3)->setMaterial(GMlib::GMmaterial::brass());
    //    _dspheres.at(4)->setMaterial(GMlib::GMmaterial::sapphire());
    //    _dspheres.at(5)->setMaterial(GMlib::GMmaterial::gold());
    //    _dspheres.at(6)->setMaterial(GMlib::GMmaterial::jade());
    //    _dspheres.at(7)->setMaterial(GMlib::GMmaterial::pewter());

    //    _dspheres.back()->translateGlobal(GMlib::Vector<float,3> (0.0f,0.0f, 2.0f));
    //    _dspheres.at(0)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));
    //    _dspheres.at(1)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));
    //    _dspheres.at(2)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));
    //    _dspheres.at(3)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));
    //    _dspheres.at(4)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));
    //    _dspheres.at(5)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));
    //    _dspheres.at(6)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));

    //    _dspheres.back()->velocity=GMlib::Vector<double,3> (0.0f, -10.0f, 0.0f);
    //    _dspheres.at(0)->velocity=GMlib::Vector<double,3> (1.0f, 10.0f, 0.0f);
    //    _dspheres.at(1)->velocity=GMlib::Vector<double,3> (2.0f, -10.0f, 0.0f);
    //    _dspheres.at(2)->velocity=GMlib::Vector<double,3> (3.0f, 10.0f, 0.0f);
    //    _dspheres.at(3)->velocity=GMlib::Vector<double,3> (4.0f, -10.0f, 0.0f);
    //    _dspheres.at(4)->velocity=GMlib::Vector<double,3> (5.0f, 10.0f, 0.0f);
    //    _dspheres.at(5)->velocity=GMlib::Vector<double,3> (6.0f, -10.0f, 0.0f);
    //    _dspheres.at(6)->velocity=GMlib::Vector<double,3> (7.0f, 10.0f, 0.0f);
    //    _dspheres.at(7)->velocity=GMlib::Vector<double,3> (8.0f, -10.0f, 0.0f);

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


    //    _scene.insert(&_controller);


    // big planes
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


    //    auto cube = std::make_unique< Cube>(1.0,3.3,4.4);

    //    prepareAndInsert(cube,10,10,1,1);



    //    for (const auto& sphere : _dspheres)
    //        prepareAndInsert(sphere , 10, 10, 1 ,1);

    //    for (const auto& plane : _planes)
    //        prepareAndInsert(plane , 10, 10, 1 ,1);


    myFemObject1 = new Femobject();
    myFemObject1->makeRandomTriangulation(50, 5);
    myFemObject1->computeStiffnessmatrix();
    myFemObject1->updateHeight(1);
    myFemObject1->toggleDefaultVisualizer();
    myFemObject1->setMaterial(GMlib::GMmaterial::sapphire());
    myFemObject1->translate( GMlib::Vector<float,3>( 10.0f, 0.0f, 0.0f ) );
    _scene.insert(myFemObject1);

    myFemObject2 = new Femobject();
    myFemObject2->makeRegualTriangualtion(15, 5, 5, true);
    myFemObject2->computeStiffnessmatrix();
    myFemObject2->updateHeight(1);
    myFemObject2->toggleDefaultVisualizer();
    myFemObject2->setMaterial(GMlib::GMmaterial::polishedGreen());
    _scene.insert(myFemObject2);


}
