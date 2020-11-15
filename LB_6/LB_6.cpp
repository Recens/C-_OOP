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
    int Qrep(){
        return height*weight;
    }
    void printdata(){
        std::cout<<"Soldier`s data: \n";
        std::cout<<"Last name soldeir: "<<last_name<<"\n";
        std::cout<<"His height: "<<height<<" (m)"<<"\n";
        std::cout<<"His weight: "<<weight<<" (kg)"<<"\n";


    }
};
class educated_soldier : public Soldier{
private:
    int educ;
public:

    educated_soldier(std::string last_name,float height,float weight,int educ)
    {
        this->last_name=last_name;
        this->height=height;
        this->weight=weight;
        this->educ=educ;
    }
    int educated(){
        switch (educ) {
            case 1: {
                return 2 * Qrep();

            }
            case 2: {
                return 0.5 * Qrep();

            }
            case 3: {
                return Qrep();

            }
        }
        return 0;
    }
    void educdata(){
        std::cout<<"Soldier`s data: \n";
        std::cout<<"Last name soldeir: "<<last_name<<"\n";
        std::cout<<"His height: "<<height<<" (m)"<<"\n";
        std::cout<<"His weight: "<<weight<<" (kg)"<<"\n";
        std::cout<<"His coefficient: ";
    }

};
int main()
{
    std::string name;
    float height,weight;
    int educ;
    std::cout<<"Enter your data:\n"<<"\n";
    std::cout<<"Your last name: "; std::cin>>name;std::cout<<"\n";
    std::cout<<"Your height (m) : "; std::cin>>height;std::cout<<"\n";
    std::cout<<"Your weight: (kg)";std::cin>>weight;std::cout<<"\n";
    std::cout<<"Your educated (1,2,3)\n1 - higher;\n2- secondary;\n3 - elementary;\nYour option: ";std::cin>>educ;
    educated_soldier sol_1(name,height,weight,educ);
    sol_1.educdata();
    std::cout <<sol_1.educated();
}