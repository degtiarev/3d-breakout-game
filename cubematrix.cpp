#include "cubematrix.h"

CubeMatrix::CubeMatrix(int height, int width, int depth)
{
    this->height=height;
    this->width=width;
    this->depth=depth;

    // Set up sizes. (HEIGHT x WIDTH)
    array3D.resize(height);
    for (int i = 0; i < height; ++i) {
        array3D[i].resize(width);

        for (int j = 0; j < width; ++j)
            array3D[i][j].resize(depth);
    }


   for (int i = 0; i < height; ++i)
        for (int j = 0; j < height; ++j)
             for (int k = 0; k < height; ++k)
             {
                   if (k==0);

             }

//     Put some values in
//    array3D[1][2][5] = 6.0;
//    array3D[3][1][4] = 5.5;


}
