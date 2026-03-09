#include <iostream>
#include <string>

template<typename T>
T Square(T n);

template<typename T>
void Swap(T& a, T& b);

template<typename A, typename B, typename C>
void Print3Types(A a, B b, C c);

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
	int a = Square(2);
	float b = Square(2.5f);
}

void Example2()
{
	int a = 5;
	int b = 10;
	std::string first = "Connor";
	std::string last = "Smiley";
	Swap(a, b);
	Swap(first, last);
}

void Example3()
{
	Print3Types(1, 69.420f, "Hello <generic> world!");
}

template<typename T>
T Square(T n)
{
	return n * n;
}

template<typename T>
void Swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

template<typename A, typename B, typename C>
void Print3Types(A a, B b, C c)
{
	std::cout << "Value 1: " << a << "\nValue 2: " << b << "\nValue 3: " << c << std::endl;
}
