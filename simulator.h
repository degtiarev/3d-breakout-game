#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <collision_library.h>
#include <gmParametricsModule>
#include <vector>
#include "cuboid.h"
#include "cubematrix.h"
#include <typeinfo>

#include <gmSceneModule>

//helper types
using DynSphere = collision::DynamicPhysObject<GMlib::PSphere<float>>;
using Plane = collision::StaticPhysObject<GMlib::PPlane<float>>;
//using DynSpherePtrVector = std::vector<DynSphere*>; //raw pointer
//using PlanePtrVector =  std::vector<Plane*>;        //raw pointer
using DynSphereVector = std::vector<std::unique_ptr<DynSphere>>;
using PlaneVector =  std::vector<std::unique_ptr<Plane>>;
using CubeVector =  std::vector<std::shared_ptr<Cuboid>>;


//class SimulationController : public GMlib::SceneObject
//{
//    GM_SCENEOBJECT (SimulationController)
//    public:
//        SimulationController()=default;

//    void add(Dynsphere* const sphere);
//    void add(Plane* const plane);


//protected:
//    void localSimulate(double dt) override final;

//private:

//  PlaneVector _planes;
//    DynSphereVector _dspheres;

//};



class Simulator{
public:
    explicit Simulator (GMlib::Scene& scene );

    void setupSimulator();

     collision::StaticPhysObject<GMlib::PPlane<float>>* _controll_plane;

private:

    GMlib::Scene& _scene;
    collision::collision_controller   _controller;
    PlaneVector _planes;
    DynSphereVector _dspheres;
    CubeVector _cubes;

    template<typename T>
    void prepareAndInsert (const std::unique_ptr<T>& obj, int m1, int m2, int d1, int d2);
    template<typename T>
    void prepareAndInsert (const std::shared_ptr<T>& obj, int m1, int m2, int d1, int d2);



};

template <typename T> inline
void Simulator::prepareAndInsert(const std::unique_ptr<T>& obj, int m1, int m2, int d1, int d2)
{
    obj->toggleDefaultVisualizer();
    obj->replot(m1, m2, d1, d2);
    _scene.insert(obj.get());
    _controller.add(obj.get());

   if (typeid(obj)!=typeid(std::make_unique<DynSphere> ()))
    {GMlib::Array<GMlib::Visualizer*> &visus = obj->getVisualizers();
    for( int i = 0; i < visus.getSize(); i++ ) visus[i]->toggleDisplayMode();}

}

template <> inline
void Simulator::prepareAndInsert<Cuboid>(const std::shared_ptr<Cuboid>& obj, int m1, int m2, int d1, int d2)
{
    _scene.insert(obj.get());

    for (const  auto& plane : obj->getPlanes())
        _controller.add(plane.get());
}



#endif // SIMULATOR_H
