#ifndef FEMOBJECT_H
#define FEMOBJECT_H

// gmlib
#include <gmCoreModule>
#include <gmSceneModule>
#include <gmParametricsModule>
#include <gmTrianglesystemModule>

#include "node.h"

class Femobject : public GMlib::TriangleFacets<float>
{

private:
    GMlib::DMatrix<float> A;
    GMlib::DVector <float> b;
    GMlib::ArrayLX<Node> nodes;

    float max=1;
    float min =-1;

    bool forceSwitcher = true;
    double force =0.0;


public:
    Femobject():GMlib::TriangleFacets<float>(50) {}
    GMlib::Vector<GMlib::Vector<float,2>,3> vectorArrays (GMlib::TSEdge<float> *edg);
    GMlib::Vector<GMlib::Vector<float, 2>, 3> vectorArray(GMlib::TSTriangle<float>* tr, Node *node);
    void updateHeight ( float h );

    void localSimulate(double dt) override;

    void regualTriangualtion(int n, int m, float r, bool doTriangulateDelaunay);
    // void regualTriangualtion(int n, int m, float r);
    void randomTriangulation(int n, float r);
    void computation();
    int randomMinMax (int min, int max);

};

#endif // FEMOBJECT_H
