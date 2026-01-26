#include <iostream>

class Object
{
public:
	Object()
	{
		count++;
		std::cout << "Object " << count << " created" << std::endl;
	}

	~Object()
	{
		std::cout << "Object " << count << " destroyed" << std::endl;
		count--;
	}

private:
	// "static" member-variables are shared between all object instances.
	// In this case, its what allows us to keep track of how many objects have been created/destroyed!
	static int count;
};

int Object::count = 0;

void Example1();

int main()
{
	Example1();
	return 0;
}

void Example1()
{
	// Heap-allocated objects get destroyed "at-will", meaning whenever we call operator delete / delete[]
	Object* obj1 = new Object[4];	// Prints "Object created"   x4
	delete[] obj1;					// Prints "Object destroyed" x4

	// Stack-allocated objects get destroyed when they go out of scope (in this case, after the Example1() function exits)
	Object obj2[3];					// Prints "Object created"   x3
}									// Prints "Object destroyed" x3
