#include <iostream>
#include <string>

void StackOverflow()
{
	std::cout << "This is NOT a good idea" << std::endl;
	StackOverflow();
}

void HopefullyNotAStackOverflow(int count)
{
	if (count > 0)
	{
		std::cout << "This is NOT a good idea" << std::endl;
		HopefullyNotAStackOverflow(count - 1);
	}
}

int Frequency(char c, std::string str, int pos)
{
	if (pos == str.length())
		return 0;

	if (str[pos] == c)
		return 1 + Frequency(c, str, pos + 1);
	else
		return 0 + Frequency(c, str, pos + 1);
}

int main()
{
	// Call this... if you dare!
	//StackOverflow(); 

	// This is the recursive equivalent of a for-loop that counts from 0-9!
	//HopefullyNotAStackOverflow(10);
	
	// Whether its variables or functions, they all take up stack space!
	//HopefullyNotAStackOverflow(20000); <--- stack overflow
	//char data[1024]; <-- fine cause its only 1 kilobyte
	//char data[1024 * 1024]; <-- stack overflow because its 1 megabyte (our stack must be < 1 megabyte by default)!!!

	std::string name = "Connor";
	int count = Frequency('n', name, 0);

	return 0;
}
