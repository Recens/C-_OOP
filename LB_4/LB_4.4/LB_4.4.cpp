#include <iostream>

class Point {
private:
    int* size;
    
public:
    int cordinat[400];
    Point() {};
    Point(int size) {
        int value;
        this->size = new int(size);
        for (int i = 0; i < getsize() * 2; i++) {
            std::cout << " Enter coordinate: " << (i + 1)<< " ";
            std::cin >> value;
            std::cout<<"\n";

            setcordinat(value, i);
        }

    }

    int getsize() {
        return *(size);
    }

    void setcordinat(int value, int i) {
        cordinat[i] = value;
    }


    std::string getcordinat()
	{
        for (int i = 0; i < getsize() * 2; i++) {
            std::cout << cordinat[i] << " ";
            
        }
        return "\n";
    }

    static Point compositionObject(Point first, Point second) {
        for (int i = 0; i < first.getsize();) {
            return Point(first.getsize());
        }
    }

    void Composition(Point first, Point second, Point& Third) {
        int value;
        std::cout << "Element Composition: " << "\n";
        for (int i = 0; i < first.getsize() * 2; i++) {
            value = (first.cordinat[i] + second.cordinat[i]);
            std::cout << "value: " << value << "\n";
            Third.setcordinat(value, i);
        }
    }
    void Substraction(Point exampleOne, Point exampleTwo, Point& Third) {
        int value;
        std::cout << "Element Subtractions: " << "\n";
        for (int i = 0; i < exampleOne.getsize() * 2; i++) {
            value = (exampleOne.cordinat[i] - exampleTwo.cordinat[i]);
            std::cout << "value: " << value << "\n";
            Third.setcordinat(value, i);
        }
    }
};

int main()
{
    Point v_1(2);
    Point v_2(2);
    std::cout << v_1.getcordinat();
    std::cout << v_2.getcordinat();
    Point v_3;
    Point sub;
    v_3 = Point::compositionObject(v_2, v_1);
    sub = Point::compositionObject(v_1, v_2);
    v_3.Composition(v_1, v_2, v_3);
	sub.Substraction(v_1, v_2, sub);
    std::cout << "Composition vector: " << v_3.getcordinat() << " " << "\n";
    std::cout << "Substraction vector: " << sub.getcordinat() << " " << "\n";
    std::cout << "Hello World!\n";
}
