#include <iostream>


class Soldier{
protected:
    int size;
public:
    int *array;

    Soldier(int size){
        this->size = size;
        this->array = new int[size];
        for(int i=0; i < size; i++){
            array[i] = i;


        }
        std::cout << "Constructor" << "\n";
    }

    Soldier(const Soldier& first){
        this->size = first.size;
        this->array = new int[first.size];
        std::cout << "Copy constructor\n";
        for (int i = 0; i < size; i++) {
            this->array[i] = first.array[i];
        }

    }

    Soldier& operator = (const Soldier& first){
        this->size = first.size;

        if(this->array != nullptr){
            delete this->array;
        }

        this->array = new int[first.size];
        for (int i = 0; i < size; i++) {
            this->array[i] = first.array[i];
        }
        return *this;
    }

    ~Soldier(){
        std::cout << "Destructor\n";
        delete[] array;
    }

    int getSize(){
        return this->size;
    }
    friend std::ostream &operator<<(std::ostream &out, const Soldier &other);


};

int function() {
    return 0;
}

std::ostream &operator<<(std::ostream &out, const Soldier &other) {
    for (int i = 0; i < other.size; i++)
    {
        out << other.array[i] << " ";
    }
    return out;
}


int main(){
    Soldier one(5);
    Soldier two(10);
    Soldier two2(one);
    std::cout<< two2<<"\n";
    std::cout << two.getSize() << "\n";
    two = one;
    std::cout << two.getSize() << "\n";
    std::cout << two << "\n";
    return 0;
}