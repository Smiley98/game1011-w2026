#include <iostream>
#include <string>

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

	void Jump() { }
	void MakeSound() { }
};

struct BumbleBee : public Insect
{
	void Fly() { }
	void String() { }
	void MakeHoney() { }
};

int main()
{
	Grasshopper grasshopper;
	grasshopper.jump_distance = 100;
	grasshopper.jump_height = 10;
	grasshopper.antenna_count = 2;

	BumbleBee bee;
	bee.Fly();
	bee.food = "Flowers";
	bee.antenna_count = 2;
	return 0;
}
