#ifndef CUBEMATRIX_H
#define CUBEMATRIX_H
#include <vector>


class CubeMatrix
{
public:

    CubeMatrix(int, int, int);

    std::vector<std::vector<std::vector<int> > > array3D;
    int height;
    int width;
    int depth;


};

#endif // CUBEMATRIX_H
