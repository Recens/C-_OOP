#include <iostream>

class Point {
private:
    int* size;
    
public:
    int coordinat[400];
    Point() {};
    Point(int size) {
        int value;
        this->size = new int(size);
        for (int i = 0; i < getsize() * 2; i++) {
            std::cout << "Please, enter coordinate: " << (i + 1)<< " ";
            std::cin >> value;
            setcoordinat(value, i);
        }
    }

    int getsize() {
        return *(size);
    }

    void setcoordinat(int value, int i) {
        coordinat[i] = value;
    }


    std::string getcoordinat()
	{
        for (int i = 0; i < getsize() * 2; i++) {
            std::cout << coordinat[i] << " ";
            
        }
        return "\n";
    }

    static Point compositionObject(Point first, Point second) {
        for (int i = 0; (i < first.getsize() and second.getsize());) {
            return Point(first.getsize());
        }
    }

    void Composition(Point first, Point second, Point& Third) {
        int value;
        std::cout << "Element Composition: " << "\n";
        for (int i = 0; i < first.getsize() * 2; i++) {
            value = (first.coordinat[i] + second.coordinat[i]);
            std::cout << "value : " << value << "\n";
            Third.setcoordinat(value, i);
        }
    }
    void Substraction(Point exampleOne, Point exampleTwo, Point& Third) {
        int value;
        std::cout << "Element Subtractions: " << "\n";
        for (int i = 0; i < exampleOne.getsize() * 2; i++) {
            value = (exampleOne.coordinat[i] - exampleTwo.coordinat[i]);         
            std::cout << "value : " << value << "\n";
            Third.setcoordinat(value,i);
        }
    }
};

int main()
{
    Point v_1(2);
    Point v_2(2);
    std::cout << v_1.getcoordinat();
    std::cout << v_2.getcoordinat();
    Point v_3;
    Point sub;
    v_3 = Point::compositionObject(v_2, v_1);
    sub = Point::compositionObject(v_1, v_2);
    v_3.Composition(v_1, v_2, v_3);
	sub.Substraction(v_1, v_2, sub);
    std::cout << " - Composition vector" << "\4" << v_3.getcoordinat() << " " << "\n";
    std::cout << " - Substraction vector" <<"\4"<< sub.getcoordinat() << " ";
    std::cout << "\n";
    std::cout << "Hello World!\n";
}
