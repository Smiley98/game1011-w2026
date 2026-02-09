#include <iostream>
#include <string>

void Example1();
void Example2();
void Example3();
void Example4();

int main()
{
	Example1();
	Example2();
	Example3();
	Example4();
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

struct Transform
{
	float x;
	float y;
	float angle;
	float scale;
};

struct Sprite
{
	int* pixels;
};

struct Collider
{
	float radius;
	float height;
};

struct Player : public Transform, public Sprite, public Collider {};
struct Trap : public Transform, public Collider {};
struct Decoration : public Transform, public Sprite {};

void Example3()
{
	Player player;
	Trap trap;
	Decoration decoration;
}

struct Base
{
	Base()
	{
		private_value = 5;
		protected_value = 15;
	}

	int public_value;

	// Protected members are visible within base & derived classes, but nowhere else (similar to private)
protected:
	int protected_value;

private:
	int private_value;
};

struct Derived : public Base
{
	void SetProtectedValue(int v) { protected_value = v; }
};

void Example4()
{
	Derived obj;
	obj.public_value = 10;
	obj.SetProtectedValue(20);
	//std::cout << obj.protected_value << std::endl;	// inaccessible
	//std::cout << obj.private_value << std::endl;		// inaccessible
}
