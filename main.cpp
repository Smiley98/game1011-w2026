#include <string>

template<typename T>
T Square(T n);

template<typename T>
void Swap(T& a, T& b);

void Example1();
void Example2();

int main()
{
	//Example1();
	Example2();
	
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