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

    double currentX=startX+a/2;
    double currentY=startY+a/2;
    double currentZ=startZ+a/2;

    array3D.resize(height*width*depth);


    for (int i = 0; i < depth; ++i)
    {
        for (int j = 0; j < width; ++j)
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

                int element =  i + depth * (j + width * k);
                array3D[element] = std::make_unique<Cuboid> (currentX, currentY, currentZ, a, color, element);


                currentX+=a;

            }
            currentX=startX+a/2;
            currentY+=a;
        }

        currentZ+=a;
        currentY=startY+a/2;
        currentX=startX+a/2;
    }
}

std::vector<std::shared_ptr<Cuboid> > CubeMatrix::getArray3D() const
{
    return array3D;
}


std::shared_ptr<Cuboid> CubeMatrix::getElement(int x, int y, int z)
{
    return array3D [z + depth * (y + width * x)];
}
