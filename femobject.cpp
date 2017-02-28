#include "femobject.h"

int Femobject::randomMinMax(int nMin, int nMax)
{
    return nMin + (int)((double)rand() / (RAND_MAX+1) * (nMax-nMin+1));
}

void Femobject::makeRegualTriangualtion(int n, int m, float r, bool switcher)
{
    //n - number of nodes on first internal circle (number of points on first row)
    //m - number of circles (number of rows)
    //r - radius

    // start from external (boundary) circle
    auto start_pt = GMlib::Point<float,2>(0,0);
    this->insertAlways(start_pt);

    for(int i=0; i<m; i++){
        for(int j=0; j<n*(i+1); j++){

            GMlib::Angle rotationAngle = (j*M_2PI)/(n*(i+1));
            GMlib::SqMatrix<float,2> rotationMatrix(rotationAngle,GMlib::Vector<float,2>(1,0),GMlib::Vector<float,2>(0,1));
            GMlib::Point<float,2> point = rotationMatrix * GMlib::Vector<float,2>((((i+1)*r)/m),0);

            this->insertAlways(point);
        }
    }
    if (switcher){
        this->triangulateDelaunay();}
}

void Femobject::makeRandomTriangulation(int n, float r)
{
    // n - number of nodes
    GMlib::Point<float,2> start_pt (0,0);
    auto rn = 4; //regular n
    auto m = n/rn; // number of circles

    makeRegualTriangualtion(rn,m,r,false);

    auto nm_coeff = std::max((M_PI/(sqrt(3)*(sin(M_PI/2)*sin(M_PI/2))+2-n))*(1/2*n), 1.1);
    auto num = 1+n*nm_coeff; // nubmer of points

    // shuffle cycle
    int t = n*0.8; // number of swaps
    for(int i=0; i<t; i++)
    {
        auto p1 = (*this)[randomMinMax(0,this->getSize())];
        auto p2 = (*this)[randomMinMax(0,this->getSize())];

        std::swap(p1,p2);
    }

    for (int j = 0; j < num*rn; j++)
    {
        int todelete = randomMinMax(0,this->getSize()-1);

        auto distVector = GMlib::Vector<float,2>( start_pt-(*this)[todelete]);
        double dist = distVector.getLength();

        if (std::abs(dist - r) > 0.01)
        {
            this->removeIndex(todelete);
        }

    }

    this->triangulateDelaunay();
}

GMlib::Vector<GMlib::Vector<float, 2>, 3> Femobject::getVectorArray(GMlib::TSTriangle<float>* tr, Node *node)
{
    GMlib::Point<float,2> p0,p1,p2;
    GMlib::Vector<GMlib::Vector<float,2>,3> d; //output
    GMlib::Array<GMlib::TSVertex<float>*> v = tr->getVertices();

    if (node->isThis(v[1])){
        std::swap(v[0],v[1]);
        std::swap(v[1],v[2]);
    }
    if (node->isThis(v[2])){
        std::swap(v[0],v[2]);
        std::swap(v[1],v[2]);
    }
    p0 = v[0]->getParameter();
    p1 = v[1]->getParameter();
    p2 = v[2]->getParameter();

    d[0] = p1 - p0;
    d[1] = p2 - p0;
    d[2] = p2 - p1;

    return d;
}

void Femobject::computeStiffnessmatrix()
{
    for (int i=0;i<this->size();i++)
        if (!(this->getVertex(i)->boundary()))
            nodes+= Node((*this)[i]);

    A.setDim(nodes.getSize(),nodes.getSize());
    b.setDim(nodes.getSize());

    //set zeroes in _A
    for(int i=0; i<A.getDim1();i++)
        for (int j=0;j<A.getDim2();j++)
            A[i][j] = 0;

    //computation
    for (int i=0; i<nodes.getSize(); i++){

        //Non diagonal elements
        GMlib::Vector<GMlib::Vector<float,2>,3> d;
        for (int j=0;j<i;j++){

            GMlib::TSEdge<float>* edg = nodes[i].getNeighborEdge(nodes[j]);
            if (edg != NULL){

                d = getVectorArrays(edg);
                auto d0 = d[0];
                auto d1 = d[1];
                auto d2 = d[2];

                auto dd =  1/ (std::abs(d0 * d0));

                auto dh1 = dd * (d1 * d0);
                auto dh2 = dd * (d2 * d0);

                auto area1 = std::abs(d0^d1);
                auto area2 = std::abs(d0^d2);

                auto h1 = dd * (area1 * area1);
                auto h2 = dd * (area2 * area2);

                A[i][j] = (dh1 * (1 - dh1) / h1 - dd) * area1 * 0.5 + (dh2 * (1 - dh2) / h2 - dd) * area2 * 0.5;

                A[j][i] = A[i][j];
            }
        }

        GMlib::Array <GMlib::TSTriangle<float>*> tr = nodes[i].getAdjacentTriangles();

        float Tk =0.0;
        for (int k=0;k<tr.getSize();k++){
            d = getVectorArray(tr[k], &nodes[i]);
            auto d0 = d[0];
            auto d1 = d[1];
            auto d2 = d[2];

            Tk += (d2 * d2) / (std::abs(d0 ^ d1) * 2);
        }
        A[i][i] = Tk;
    }

    for (int i=0;i<nodes.getSize();i++){

        GMlib::Array <GMlib::TSTriangle<float>*> tr = nodes[i].getAdjacentTriangles();

        float bsum = 0;
        for (int k=0;k<tr.getSize();k++)
            bsum += tr[k]->getArea2D()/3;

        b[i] = bsum;
    }

    A.invert();
}

void Femobject::updateHeight(float f)
{
    GMlib::DVector<float> x1;
    x1.setDim(nodes.getSize());
    x1 = (f*b);
    GMlib::DVector<float> x = A*x1;

    for (int i=0;i<nodes.getSize();i++)
        this->nodes[i].updateZ(x[i]);
}

void Femobject::localSimulate(double dt)
{
    if (forceSwitcher)
        force+=dt;
    else
        force -=dt;

    if (force>=max)
        forceSwitcher = false;
    if (force<=min)
        forceSwitcher = true;

    updateHeight(force);

    this->replot();

}

GMlib::Vector<GMlib::Vector<float, 2>, 3> Femobject::getVectorArrays(GMlib::TSEdge<float>* edge)
{

    GMlib::Array<GMlib::TSTriangle<float>*> tr = edge->getTriangle();

    GMlib::Array<GMlib::TSVertex<float>*>   v1 = tr[0]->getVertices();
    GMlib::Array<GMlib::TSVertex<float>*>   v2 = tr[1]->getVertices();

    GMlib::Vector<GMlib::Vector<float,2>,3> d; //output
    GMlib::Point<float,2> p0,p1,p2,p3;

    p0 = edge->getFirstVertex()->getParameter();
    p1 = edge->getLastVertex()->getParameter();

    //p2
    for(int i=0;i<3;i++)
        if(v1[i]!=edge->getFirstVertex() && v1[i]!=edge->getLastVertex())
            p2 = v1[i]->getParameter();

    //p3
    for(int i=0;i<3;i++)
        if(v2[i]!=edge->getFirstVertex() && v2[i]!=edge->getLastVertex())
            p3 = v2[i]->getParameter();


    d[0] = p1 - p0;
    d[1] = p2 - p0;
    d[2] = p3 - p0;

    return d;
}
