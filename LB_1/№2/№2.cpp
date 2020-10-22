#include <iostream>
#include <string>


class place
{

public:
    std::string* city;
    std::string* street;
    int* house;
    int* apartment;
    place()
    {
        std::cout << "default constructor" << "\n";
    }
    place(std::string default_city, std::string default_avenue, int default_house_number, int default_apartments_number)
    {
        city = new std::string(default_city);
        street = new std::string(default_avenue);
        house = new int(default_house_number);
        apartment = new int(default_apartments_number);
    }
    std::string get_city()
    {
        return *city;
    }
    std::string get_street()
    {
        return *street;
    }
    int get_number_of_house()
    {
        return *house;
    }
    int get_apartment_number()
    {
        return *apartment;
    }
    place(const place& other)
    {
        
        city = other.city;
        street = other.street;
        house = other.house;
        apartment = other.apartment;
        std::cout << "Сopy constructor" << "\n";
    }
    ~place()
    {
        std::cout << "destructor " << "\n";
    }
};


int main()
{
    place object_1;
    place object_2("Rubezhnoe", "st.osvoboditelya", 22, 56);
    place object_3 = object_2;
    std::cout << object_2.get_city() << " " << object_2.get_street() << " " << object_2.get_number_of_house() << " " << object_2.get_apartment_number() << "\n";
}