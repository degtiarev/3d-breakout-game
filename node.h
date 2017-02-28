#ifndef NODE_H
#define NODE_H

// gmlib
#include <gmCoreModule>
#include <gmSceneModule>
#include <gmParametricsModule>
#include <gmTrianglesystemModule>


class Node
{
private:
        GMlib::TSVertex<float> * _vt; //vertex

public:
    Node();
    Node(GMlib::TSVertex<float>& nodeVert);

    GMlib::Array<GMlib::TSTriangle<float> *> getAdjacentTriangles();
    GMlib::TSEdge <float> * getNeighborEdge(Node &n);

    bool isThis (GMlib::TSVertex<float> * _vt);
    void updateZ(float z);

};

#endif // NODE_H
