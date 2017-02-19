#include "cubematrix.h"

 CubeMatrix::CubeMatrix(int height, int width, int depth, double startX, double startY, double startZ, double a)
{
    this->height=height;
    this->width=width;
    this->depth=depth;

    this->startX = startX;
    this->startY = startY;
    this->startZ = startZ;
    this->a=a;

//    double currentX=startX+a/2;
//    double currentY=startY+a/2;
//    double currentZ=startZ+a/2;

    array3D.resize(height*width+depth);


    for (int i = 0; i < height; ++i){
        for (int j = 0; j < height; ++j)
        {
            for (int k = 0; k < height; ++k)
            {
                GMlib::Material color;
                if (i==0) color= GMlib::GMmaterial::polishedRed();
                if (i==1) color = GMlib::GMmaterial::copper();
                if (i==2) color = GMlib::GMmaterial::bronze();
                if (i==3) color = GMlib::GMmaterial::polishedGold();
                if (i==4) color = GMlib::GMmaterial::polishedGreen();
                if (i==5) color = GMlib::GMmaterial::turquoise();
                if (i>=6) color = GMlib::GMmaterial::blackRubber();

                    //array3D[i*j+k] = std::shared_ptr<Cuboid> (currentX, currentY, currentZ, a, color);

            }
        }

    }
}

std::shared_ptr<Cuboid> CubeMatrix::getElement(int x, int y, int z)
{
    return array3D[x*y+z];
}
