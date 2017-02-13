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



public:
    GMlib::TSVertex<float> * _vt; //vertex

    Node();
    Node(GMlib::TSVertex<float>& nodeVert);

    GMlib::Array<GMlib::TSTriangle<float> *> getTriangles();
    GMlib::TSEdge <float> * neighbour(Node &n);
    bool isThis (GMlib::TSVertex<float> * _vt);

    void setZ(float z);



};

#endif // NODE_H
