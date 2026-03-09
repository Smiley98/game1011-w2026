#include <iostream>
#include <string>
#include <vector>

template<typename T>
T Square(T n);

template<typename T>
void Swap(T& a, T& b);

template<typename A, typename B, typename C>
void Print3Types(A a, B b, C c);

void Example1();
void Example2();
void Example3();
void Example4();

class IntArray
{
public:

private:

};

int main()
{
	//Example1();
	//Example2();
	//Example3();
	Example4();
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
	Print3Types("Hello <generic> world!", 69.420f, 1);
}

void Example4()
{
	// This is the C# equivalent of List<int>(); (Dynamic Array)
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);
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
