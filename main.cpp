template<typename T>
T Square(T n);

// Must pass by reference otherwise values will be copied (swap will fail)!
void Swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
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
	Swap(a, b);
}

int main()
{
	//Example1();
	Example2();
	
	return 0;
}

template<typename T>
T Square(T n)
{
	return n * n;
}