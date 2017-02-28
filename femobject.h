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
    GMlib::DMatrix<float> A; // stiffness matrix
    GMlib::DVector <float> b; // load vector
    GMlib::ArrayLX<Node> nodes;

    float max = 1;
    float min =-1;

    bool forceSwitcher = true;
    double force = 0.0;


public:
    Femobject():GMlib::TriangleFacets<float>(50) {}
    // get VectorArrays that are not on diagonal, that have adjacent edge
    GMlib::Vector<GMlib::Vector<float,2>,3> getVectorArrays (GMlib::TSEdge<float> *edge);
    // get VectorArray if on diagonal
    GMlib::Vector<GMlib::Vector<float, 2>, 3> getVectorArray(GMlib::TSTriangle<float>* tr, Node *node);
    void updateHeight ( float h );

    void localSimulate(double dt) override;

    void makeRegualTriangualtion(int n, int m, float r, bool doTriangulateDelaunay);
    void makeRandomTriangulation(int n, float r);

    void computeStiffnessmatrix();
    int randomMinMax (int min, int max);

};

#endif // FEMOBJECT_H
