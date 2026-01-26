#include <iostream>

class Object
{
public:
	Object()
	{
		std::cout << "Object created" << std::endl;
	}

	~Object()
	{
		std::cout << "Object destroyed" << std::endl;
	}

private:
};

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
