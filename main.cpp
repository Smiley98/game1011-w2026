#include <iostream>
#include <string>

void Example1();
void Example2();

int main()
{
	Example1();
	Example2();
	return 0;
}

struct Insect
{
	int exoskeleton_strength;
	int legs_count;
	int eyes_count;
	int antenna_count;
	int volume;
	bool can_fly;
	std::string food;
	std::string name;
};

struct Grasshopper : public Insect
{
	int jump_distance;
	int jump_height;
	int wingspawn;

	void Jump() {}
	void MakeSound() {}
};

struct BumbleBee : public Insect
{
	void Fly() {}
	void String() {}
	void MakeHoney() {}
};

struct Person
{
	std::string name;
};

struct CollegePerson : public Person
{
	std::string program_name;
};

struct Faculty : public CollegePerson
{
};

struct Student : public CollegePerson
{	
	Faculty* teacher;
};

struct Worker : public Person
{
};

void Example1()
{
	Grasshopper grasshopper;
	grasshopper.jump_distance = 100;
	grasshopper.jump_height = 10;
	grasshopper.antenna_count = 2;

	BumbleBee bee;
	bee.Fly();
	bee.food = "Flowers";
	bee.antenna_count = 2;
}

void Example2()
{
	Faculty person;
	person.name = "Connor";
	person.program_name = "Game Development";

	Student student;
	student.name = "Jahmaal";
	student.teacher = &person;
	std::cout << student.teacher->program_name << std::endl;

	Worker worker;
	//worker.program_name;

	// Initially, both Student & Faculty shared the program_name field.
	// We lifted program_name to be part of Person since it was common to both Student & Faculty.
	// As our program evolved, we introduced a Worker class that is also a Person, yet didn't attend college.
	// Hence, the program_name field is inapplicable to worker, so we added an intermediate class called
	// CollegePerson to conveniently lift program_name to Student & Faculty without adding it to Worker.
}
