#include <iostream>
#include <string>

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

class Test
{
	// "Friends can see each other's privates"
	friend Test MakeTest(std::string name, int number);

public:

	// "Default constructor" --> used for default initialization
	Test()
	{
		number = 0;
	}

	// "Overloaded constructor" --> used for custom initialization
	Test(int n)
	{
		number = n;
	}

	Test(std::string s)
	{
		name = s;
	}

private:
	std::string name;
	int number;
};

Test MakeTest(std::string name, int number);
void Example1();
void Example2();
void Example3();

int main()
{
	//Example1();
	//Example2();
	Example3();
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

void Example2()
{
	Test test_default;		// Making an object without any parenthesis uses the default constructor
	Test test_custom1(10);	// Making an object with values inside parenthesis uses the overloaded constructor!
	Test test_custom2("Connor");
	// test_custom2.number is now uninitialized since its overloaded string constructor doesn't set number!!
	// This is why I recommend you avoid constructors and either initialize every object manually,
	// or you make a separate function that explicitly handles initialization (see Example3)!
}

void Example3()
{
	Test test1 = MakeTest("Connor", 1);
	Test test2 = MakeTest("Connor", 10);
	Test test3 = MakeTest("Connor", 100);
}

Test MakeTest(std::string name, int number)
{
	Test test;
	test.number = number;
	test.name = name;
	return test;
}
