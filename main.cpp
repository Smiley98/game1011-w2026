#include <iostream>

void StackOverflow()
{
	std::cout << "This is NOT a good idea" << std::endl;
	StackOverflow();
}

int main()
{
	//StackOverflow(); // Call this... if you dare!
	return 0;
}
