template<typename T>
T Square(T n);

// This wouldn't compile if we didn't forward-declare Square (top-down still)
void Test()
{
	int a = Square(2);
}

int main()
{
	Test();
	int a = Square(2);
	float b = Square(2.5f);
	return 0;
}

template<typename T>
T Square(T n)
{
	return n * n;
}