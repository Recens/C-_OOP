#include <iostream>
#include<string>


class place{

private:
    std::string city, street;

    int house, apartment;

public:
    
	
    place()
    {
        std::cout << "Warning" << std::endl;
        std::string city = " ";
        std::string street = " ";
        int house = 0;
        int apartment = 0;
    }
	place(std::string city, std::string street, int house, int apartment )
    {
        city = city;
        street = street;
        house = house;
        apartment = apartment;
	    
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
        std::cout << "Сopy constructor" << "\n";
    }
    ~place()
    {
        std::cout << "destructor" << std::endl;
    }
};
int main()
{
    place object_1;
    place object_2("Rubezhnoe", "st.osvoboditelya", 22, 56);
    place object_3 = object_2;
    std::cout << object_2.get_city() << " " << object_2.get_street() << " " << object_2.get_number_of_house() << " " << object_2.get_apartment_number() << "\n";
}
