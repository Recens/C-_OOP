#include <iostream>


template<typename T>
class Arr{
private:
    T* arr;
    int size;
public:

    Arr(T* arr, int size){
        this->arr = arr;
        this->size = size;
    }

    void show(){
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";

        }
        std::cout<<"\n";
    }

    void showFromEnd(){
        for(int i = size; i >= 0; i--){
            std::cout << arr[i] << "\n";
        }
    }

    void sort(){
        for(int i = 0; i < size - 1; i++){
            for (int j = 0; j < size - i - 1; j++) {
                if(arr[j] > arr[j + 1]){
                    auto temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    Arr(const Arr& Other){
        this->size = Other.size;
        this->arr = new T[Other.size];
        std::cout << "Copy constructor\n";
        for (int i = 0; i < size; i++) {
            this->arr[i] = Other.arr[i];
        }
    }

    ~Arr(){
        delete [] arr;
    }



};

float generateFloat(double a, double b)
{
    return ((b - a) * ((double) rand() / RAND_MAX)) + a;
}

int main(){

    auto* arr = new float [10];

    for(int i=0; i < 10; i++){
        arr[i] = generateFloat(0, 3);
    }

    auto* arr2 = new int [10];

    for(int i=0; i < 10; i++){
        arr2[i] = 1 + rand() % 9;
    }


    Arr<float> obj1(arr, 10);
    std::cout << "\n";
    obj1.show();
    obj1.sort();
    std::cout << "Sorted: \n";
    obj1.show();


    Arr<int> obj2(arr2, 10);
    obj2.show();
    obj2.sort();
    std::cout << "Sorted: \n";
    obj2.show();

    Arr<float> obj3(obj1);
    obj3.show();
}