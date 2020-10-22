#include <iostream>
#include<string>


class place {

private:
    std::string city, street;

    int house, apartment;
    static int count_;

public:


    place()
    {
        std::cout << "default constructor" << std::endl;
        count_++;
    }
    place(std::string d_city, std::string d_street, int d_house, int d_apartment)
    {
        city = d_city;
        street = d_street;
        house = d_house;
        apartment = d_apartment;
        count_++;

    }
    std::string get_city()
    {
        return city;
    }
    std::string get_street()
    {
        return street;
    }
    int get_number_of_house()
    {
        return house;
    }
    int get_apartment_number()
    {
        return apartment;
    }

    place(const place& other)
    {

        city = other.city;
        street = other.street;
        house = other.house;
        apartment = other.apartment;
        std::cout << "Copy constructor" << "\n";
        count_++;
    }
    ~place()
    {
        std::cout << "destructor" << std::endl;
    }
    static int get_count_number()
    {
        return count_;
    }
	static void stf()
    {
        
        count_;
        count_ = -5;
        std::cout << "Suka:" << count_<< std::endl;
        
        
        
    }
};
int place::count_ = 0;


int main()
{
    place object_1;
    place object_2("Rubberize", " Dobro", 22, 56);
    place object_3 = object_2;
    std::cout << object_2.get_city() << " " << object_2.get_street() << " " << object_2.get_number_of_house() << " " << object_2.get_apartment_number() << "\n";
    place::stf();
    std::cout << "number of objects: " << place::get_count_number() << std::endl;
    
    
}