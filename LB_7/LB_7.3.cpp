#include <iostream>
#include <string>

class  Soldier{
protected:
    std::string last_name;
    float height, weight;

public:
    Soldier(){
        std::string last_name="0";
        float height=0;
        float weight=0;
        double q=0;
    }
    float get_height(){
        return height;
    }
    float get_weight(){
        return weight;
    }

    Soldier(std::string last_name, float height, float weight){
        this-> last_name=last_name;
        this->height=height;
        this->weight=weight;
    }


    Soldier& operator = (const Soldier& sol_1){
        this->weight=sol_1.weight;
        this->height=sol_1.height;
        return *this;
    };
    friend std::ostream &operator<<(std::ostream &out, const Soldier &other);
};

std::ostream &operator<<(std::ostream &out, const Soldier &other) {
    out<<"Soldier`s data: "<<other.last_name<<"\n"<<"His height: "<<other.height<<"\n"<<"His weight: "<<other.weight<<"\n";
    return out;
}


int main()
{
    Soldier sol_1 ("Stan",1.9, 85.7);
    Soldier sol_2 ("Bill",2.1, 98.45);
    std::cout << sol_1;
    std::cout << sol_2;
    sol_2 = sol_1;
    std::cout << sol_2;
}