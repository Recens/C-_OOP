#include <iostream>

class Arr{
private:
    int **matrix;
    int size;
public:

    Arr(){
        this->size = 1;
        this->matrix=new int* [size];
    }


    Arr(int size){
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

    Arr operator +(const Arr &other) {
        Arr temp(this->size);
        temp.showData();
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                temp.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
            }
        }
        return temp;


    }

    ~Arr(){
        std::cout<<"Destructor the worked\n";
        for(int i=0;i<size;i++){
            delete matrix[i];
        }
        delete[] matrix;
    }
};

int main(){
    Arr arr1(4);
    Arr arr2(4);
    arr1.showData();
    arr2.showData();
    Arr arr3 = arr1 + arr2;
    arr3.showData();

    return 0;
}