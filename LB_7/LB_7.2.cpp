#include <iostream>

class Array{
private:
    int **matrix;
    int size;
public:

    Array(){
        this->size = 1;
        this->matrix=new int* [size];
    }


    Array(int size){
        this->size = size;
        this->matrix= new int*[size];
        for (int i=0;i<size;i++){
            matrix[i]=new int[size];
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = 1 + rand() % 9;
            }
        }
    }

    void showData(){
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }

    }

    Array operator +(const Array &other) {
        Array temp(this->size);
        temp.showData();
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                temp.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
            }
        }
        return temp;


    }

    ~Array(){
        std::cout<<"Destructor the worked\n";
        for(int i=0;i<size;i++){
            delete matrix[i];
        }
        delete[] matrix;
    }
};

int main(){
    Array arr1(4);
    Array arr2(4);
    arr1.showData();
    arr2.showData();
    Array arr3 = arr1+arr2;
    arr3.showData();

    return 0;
}