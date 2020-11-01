#include <iostream>
#include <string>


class personnel
{
public:
	std::string name;
	std::string profession;
	float experience;
	virtual void data(std::string Name, std::string prof, float exp) = 0;
};

class working : public personnel
{
public:
	void data(std::string Name, std::string prof, float exp) override
	{
		name = Name;
		profession = prof;
		experience = exp;
		std::cout << "Name: " << name << std::endl << "Profession: " << profession << std::endl << "Experience: " << experience << " years" << std::endl;
		std::cout<<std::endl;
	};

};

class engineer : public personnel
{
public:
	void data(std::string Name, std::string prof, float exp) override
	{
		name = Name;
		profession = prof;
		experience = exp;
		std::cout << "Name: " << name << std::endl << "Profession: " << profession << std::endl << "Experience: " << experience << " years" << std::endl;
		std::cout<<std::endl;
	}
};

class administration : public personnel
{
public:
	void data(std::string Name, std::string prof, float exp) override
	{
		name = Name;
		profession = prof;
		experience = exp;
		std::cout << "Name: " << name << std::endl << "Profession: " << profession << std::endl << "Experience: " << experience << " years" << std::endl;
		std::cout << std::endl;
	}
};

int main()
{
	working work;
	work.data("Bob", "Working", 2.5);
	engineer eng;
	eng.data("Bill", "Engineer", 5);
	administration admin;
	admin.data("Johny","Administration",3);
    
}

