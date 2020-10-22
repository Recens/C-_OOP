#include <iostream>
#include <string>

class Figure
{
protected:
    double type, xpos, ypos;
public:
    Figure() { int type = 0; xpos = 0; ypos = 0; }
    static void creator()
    {
        std::cout << "Nothing to create\n";
    }
};

class Point : public Figure
{
protected:
public:
    Point()
    {
        type = 1; xpos = 0; ypos = 0;
    }
    void set_values(int a, int b)
    {
        xpos = a;
        ypos = b;
    }
};

class Circle : public Figure
{
protected:
    float radius;
public:
    Circle()
    {
        type = 2; xpos = 0; ypos = 0;
    }

};


class Polygon : public Figure
{
protected:
    int count_of_side;
public:
    Polygon()
    {
        type = 3; xpos = 0; ypos = 0;
    }

};

class Rectangle : public Polygon
{
protected:
public:
    Rectangle()
    {
        type = 4; xpos = 0; ypos = 0;
    }


};

class Triangle : public Polygon
{
protected:
public:
    Triangle()
    {
        type = 5; xpos = 0; ypos = 0;
    }

};



int main()
{
    Point pobj;
    std::cout << "Hello World!\n";
}