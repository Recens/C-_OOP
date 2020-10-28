#include <iostream>
#include <string>
#define PI 3.14159265358979323846


class Point
{
protected:
    
public:
    double xpos, ypos, sym=0;
    Point()
    {
        xpos = 0; ypos = 0;
    }
    Point(double x, double y)
    {
        xpos = x;
        ypos = y;
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
    Figure()
    {
        area = 0;
        perimeter = 0;
    };
	double get_area()
	{
        return area;
	}
	double get_perimeter()
	{
        return perimeter;
	}
	
    static void creator()
    {
        std::cout << "Figure \n";
    }
};



class Circle : public Figure
{
public:
    float radius;
	void set_circle(float radius_)
	{
        radius=radius_;
	}
    float get_circle()
	{
        return radius;
	}
    Circle(float radius, int xpos, int ypos)
	{
        area = PI * radius * radius;
        std::cout << "circle area = "<< area<<std::endl;
	}
};


class Polygon : public Figure
{
public:
	Polygon()
	{
		
	}
	Polygon( Point& first, Point& second, Point& third,
         Point& forth, Point& fifth)
	{
        
        perimeter = Segment::len(first, second) + Segment::len(second, third) + Segment::len(third, forth) + Segment::len(forth, fifth) + Segment::len(fifth, first);
        std::cout << "Polygon perimeter = "<<perimeter << std::endl;
	}
   

};

class Rectangle : public Polygon
{
protected:
public:
	public:
		Rectangle(Point& first, Point& second, Point& third, Point& forth)
        {
		    std::cout << "Rectangle created\n";
		    area = Segment::len(first, second) * Segment::len(second, third);
            std::cout << "Rectangle area = " << area << std::endl;
		}
        void symmetry(Point& first, Point& second, Point& third, Point forth, Point& symm)
		{
            sym = Segment::len(first, symm) * 2;
            first.xpos = first.xpos + sym;
            first.ypos = first.ypos + sym;
            sym = Segment::len(second, symm) * 2;
            second.xpos = second.xpos + sym;
            second.ypos = second.ypos + sym;
            sym = Segment::len(third, symm) * 2;
            third.xpos = third.xpos + sym;
            third.ypos = third.ypos + sym;
            sym = Segment::len(forth, symm) * 2;
            forth.xpos = forth.xpos + sym;
            forth.ypos = forth.ypos + sym;
			
            std::cout << "symm = " << first.xpos << first.ypos << std::endl;
            std::cout << "symm = " << second.xpos << second.ypos << std::endl;
            std::cout << "symm = " << third.xpos << third.ypos << std::endl;
            std::cout << "symm = " << forth.xpos << forth.ypos << std::endl;
			
		}
};

class Triangle : public Polygon
{
protected:
public:
    Triangle( Point& first,  Point& second,  Point& third)
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
    void parallel(Point& first, Point& second, Point& third, Point& Vector) {
        first.xpos += Vector.xpos;
        second.xpos += Vector.xpos;
        third.xpos += Vector.xpos;

        first.ypos += Vector.ypos;
        second.ypos += Vector.ypos;
        third.ypos += Vector.ypos;
    }

};



int main()
{
    Point point (4,5);
	
    Point p_1(3,4);
    Point p_2(4, 5);
    std::cout << "segment length = " << Segment::len(p_1, p_2) << std::endl;
	
    Point t_1(0, 0);
    Point t_2(4, 1);
	Point t_3(2, 5);
    Point vector(5,5);
    Triangle t(t_1, t_2, t_3);
    t.parallel(t_1, t_2, t_3, vector);
	
    Circle c_1(4, 3, 7);
	
   
    Point pl_1(3,1);
    Point pl_2(2,3);
    Point pl_3(5,6);
    Point pl_4(8,3);
    Point pl_5(7,1);
    Polygon pl(pl_1, pl_2, pl_3, pl_4, pl_5);

    Point rc_1(0,0);
    Point rc_2(0,4);
    Point rc_3(6,4);
    Point rc_4(6,0);
    Point symm(5,5);
    Rectangle rec(rc_1,rc_2,rc_3,rc_4);
    rec.symmetry(rc_1, rc_2, rc_3, rc_4, symm);
	

}