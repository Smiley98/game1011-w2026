float Add(float a, float b)
{
	return a + b;
}

float Sub(float a, float b)
{
	return a - b;
}

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

int main()
{
	float a1 = 5.0f;
	float b1 = 10.0f;
	float c1 = Add(a1, b1);
	float d1 = Sub(a1, b1);

	int a2 = 5;
	int b2 = 10;
	int c2 = Add(a2, b2);
	int d2 = Sub(a2, b2);

	return 0;
}
