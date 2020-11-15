#include <iostream>

class Array{
private:
    int **matrix;
    int size;
public:

    Array(){
        this->size = 1;
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

    Array operator +(const Array &other){
        Array temp;
        if(this->size == other.size){
            for (int i = 0; i < this->size; i++) {
                for (int j = 0; j < this->size; j++) {
                    temp.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
                }
            }
            return temp;
        }
        else{
            temp.matrix[0][0] = 0;
            return temp;
        }
    }
    ~Array(){
        std::cout<<"Destrucrot worked\n";
        for(int i=0;i<size;i++){
            delete matrix[i];
        }
        delete[] matrix;
    }
};

int main(){
    Array arr1(4);
    Array arr2(2);
    Array arr3(1);
    arr1.showData();
    arr2.showData();
    arr3.showData();
    arr3=arr2=arr1;
    arr1.showData();
    arr2.showData();
    arr3.showData();

    return 0;
}