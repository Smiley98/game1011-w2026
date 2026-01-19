#include <iostream>
#include <cmath>

void Example1();
void Example2();

int main()
{
	//Example1();
	Example2();
	return 0;
}

class Circle
{
public:
	float GetRadius() { return radius; }
	void SetRadius(float r)
	{
		// Setters only make sense if they do some form of validation.
		// In this case, we ensure that our circle's radius cannot be negative!
		r = std::max(r, 0.0f);
		radius = r;
	}

private:
	float radius;
};

void Example1()
{
	Circle circle;
	//circle.radius = -1.0f; <-- compiler error because radius is private (inaccessible)
	circle.SetRadius(-1.0f);
}

void Example2()
{
	// Declare a "pointer to an integer" named ptr, which initially points to nothing (nullptr = "nothing")
	int* ptr = nullptr;
	int a = 5;
	int b = 10;

	// Assign ptr to the address of a ('&' = "address-of")
	ptr = &a;
	std::cout << "Pointer address at a: " << ptr << std::endl;
	std::cout << "Pointer value at a: " << *ptr << std::endl;
	// *ptr means "dereference", which looks up the value in the address stored by the pointer
	// In this case, we get the value 5 because ptr stores the address of a

	ptr = &b;
	std::cout << "Pointer address at b: " << ptr << std::endl;
	std::cout << "Pointer value at b: " << *ptr << std::endl;
	// Change the address of ptr to be that of b.
	// Now we see b's address in the console when we output the pointer itself,
	// and we see the value of b (10) when we dereference our pointer!
}
