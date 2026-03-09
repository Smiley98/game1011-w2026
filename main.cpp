//int Square(int n)
//{
//	return n * n;
//}
//
//float Square(float n)
//{
//	return n * n;
//}

// "Dog" is the name of our generic type;
// "The Square function outputs a generic number given a generic number input"
// Just like regular variables, your generic variable can be named whatever you like
// (Dog, in my case)!
template<typename Dog>
Dog Square(Dog n)
{
	return n * n;
}

int main()
{
	int a = Square(2);
	float b = Square(2.5f);
	return 0;
}
