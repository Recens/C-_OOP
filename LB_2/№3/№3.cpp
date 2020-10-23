#include <iostream>
#include <string>
#define M_PI 3.14159265358979323846


class Point
{
protected:
    
public:
    double xpos, ypos;
    Point()
    {
        xpos = 0; ypos = 0;
    }
    Point(double a, double b)
    {
        xpos = a;
        ypos = b;
        std::cout << "add point" << std::endl;
    }
};

class Segment : public Point
{
public:
    double lenght;
	Segment()
    {
        lenght = 0;
    }
   static int len (const Point& oth, const Point& unoth)
    {
       return  sqrt(pow(unoth.xpos - oth.xpos, 2) + pow(unoth.ypos - oth.ypos, 2));
       
    }
	

};


class Figure : public Segment
{
protected:
    double area, perimeter;
public:
    
    static void creator()
    {
        std::cout << "Nothing to create\n";
    }
};



class Circle : public Figure
{
public:
    float radius;
	void set_circle(float radius)
	{
        this->radius=radius;
	}
    float get_circle()
	{
        return radius;
	}
    Circle(float radius, int xpos, int ypos)
	{
        area = M_PI * radius * radius;
        std::cout << "circle area = "<< area<<std::endl;
	}
};


class Polygon : public Figure
{
public:
	Polygon()
	{
		
	}
	Polygon(const Point& first, const Point& second, const Point& third,
        const Point& forth, const Point& fifth)
	{
        
        perimeter = Segment::len(first, second) + Segment::len(second, third) + Segment::len(third, forth) + Segment::len(forth, fifth) + Segment::len(fifth, first);
        std::cout << "Polygon perimeter = "<<perimeter << std::endl;
	}
   

};

class Rectangle : public Polygon
{
protected:
public:
    


};

class Triangle : public Polygon
{
protected:
public:
    Triangle(const Point& first, const Point& second, const Point& third)
    {
        if (Segment::len(first, second) + Segment::len(first, third) > Segment::len(third, second))
        {
            if (Segment::len(second, first) + Segment::len(second, third) > Segment::len(third, first))
            {
                if (Segment::len(third, first) + Segment::len(third, second) > Segment::len(first, second))
                {
                    std::cout << "triangle correct\n";

                }
                else
                {
                    std::cout << "triangle not correct\n";
                }
            }
            else
            {
                std::cout << "triangle not correct\n";
            }
        }
        else
        {
            std::cout << "triangle not correct\n";
        }
    }

};



int main()
{
    Point pobj(4,5);
    Point p_1(3,4);
    Point p_2(4, 5);
    Point t_1(5, 2);
    Point t_2(8, 3);
	Point t_3(10, 11);
    std::cout << "segment length = " <<Segment::len(p_1, p_2)<<std::endl;
    Circle c_1(4, 3, 7);
    Triangle t(t_1, t_2, t_3);
    Point pl_1(3,1);
    Point pl_2(2,3);
    Point pl_3(5,6);
    Point pl_4(8,3);
    Point pl_5(7,1);
    Polygon pl(pl_1, pl_2, pl_3, pl_4, pl_5);
	

}