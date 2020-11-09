#include <iostream>
#include <cmath>


class Vector
{
private:
    float xpos;
    float ypos;
    float zpos;

public:
    Vector()
	{
        this->xpos = 0;
        this->ypos = 0;
        this->zpos = 0;
    }

    Vector(float x, float y, float z)
	{
        xpos = x;
        ypos = y;
        zpos = z;
    }

    float getX()
	{
        return xpos;
    }

    float getY()
	{
        return ypos;
    }

    float getZ()
	{
        return zpos;
    }

    void setToNormal(float x1, float y1, float z1, float x2, float y2, float z2)
	{
        this->xpos = x2 - x1;
        this->ypos = y2 - y1;
        this->zpos = z2 - z1;
    }
};






class Operations : public Vector
{
    private:
        Vector AB;
        Vector BC;
    public:
        static float lenghtOfVector(Vector& Vector)
		{
            return (sqrt(std::pow(Vector.getX(), 2) + std::pow(Vector.getY(), 2) + std::pow(Vector.getZ(), 2)));
        }

        static Vector AdditionOfVectors(Vector a, Vector b)
		{
            return Vector ((a.getX() + b.getX()), 
                (a.getY() + b.getY()),
                (a.getZ() + b.getZ()));
        }
        static Vector SubstractionOfVectors(Vector a, Vector b)
		{
            return Vector ((a.getX() - b.getX()), 
                (a.getY() - b.getY()),
                (a.getZ() - b.getZ()));
        }

        static float innerProduct(Vector a, Vector b)
		{
            return (a.getX() * b.getX()+ a.getY() * b.getY() + a.getZ() * b.getZ());
        }



        static Vector vectorProduct(Vector& a, Vector& b)
		{
            return Vector(a.getY() * b.getZ() - a.getZ() * b.getY(),
                -(a.getX() * b.getZ() - a.getZ() * b.getX()),
                a.getX() * b.getY() - a.getY() * b.getX());
        }
};




int main() {
    Vector addit;
    Vector substr;
    Vector vect;
    Vector AB;
    AB.setToNormal(2, -3, -3, 1, 2, 1);
    Vector BC;
    BC.setToNormal(0, 1, -3, 1, 1, 2);
    addit = Operations::AdditionOfVectors(AB, BC);
    substr = Operations::SubstractionOfVectors(AB, BC);
    std::cout << "Addition: " << "x:" << addit.getX() << " y:" << addit.getY() << " z:" << addit.getZ() << "\n";
    std::cout << "Subtraction: " << "x:" << substr.getX() << " y:" << substr.getY() << " z:" << substr.getZ() << "\n";
    std::cout << "Scalar product of vectors: "<< Operations::innerProduct(AB, BC) << "\n";
    std::cout << "Lenght a: "<< Operations::lenghtOfVector(AB) << "\n";
    std::cout << "Lenght b: "<< Operations::lenghtOfVector(BC) << "\n";
    vect = Operations::vectorProduct(AB, BC);
    std::cout <<"x:" << vect.getX() << " y:" << vect.getY() << " z:" << vect.getZ() << "\n";

}