#include "node.h"

Node::Node()
{

}

Node::Node(GMlib::TSVertex<float>& nodeVert)
{
    _vt = &nodeVert;
}

GMlib::Array<GMlib::TSTriangle<float >* > Node::getAdjacentTriangles()
{
    return this->_vt->getTriangles();
}

GMlib::TSEdge<float> *Node::getNeighborEdge(Node &n)
{
    GMlib::Array<GMlib::TSEdge<float>*> edg=_vt->getEdges();

    for (int i=0; i<edg.size(); i++)
    {
        if (n.isThis(edg[i]->getOtherVertex(* _vt)))
            return edg[i];
    }

    return NULL;
}

bool Node::isThis(GMlib::TSVertex<float> *vt)
{
    if (vt==_vt) return true;
    return false;
}


void Node::updateZ(float z)
{
    this->_vt->setZ(z);
}


