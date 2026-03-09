int Square(int n)
{
	return n * n;
}

// Need to overload for floats because our input of 2.5f truncates to 2
int main()
{
	int a = Square(2);
	float b = Square(2.5f);
	return 0;
}
