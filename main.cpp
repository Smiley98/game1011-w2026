#include <iostream>
#include <string>
#include <vector>

void Example1();	// Intro to recursion
void Example2();	// Binary search

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
	// Base case (when to end recursion)
	if (pos == str.length())
		return 0;

	// Recursive cases (keep going until we're reached the end of the string)
	if (str[pos] == c)
		return 1 + Frequency(c, str, pos + 1);
	else
		return 0 + Frequency(c, str, pos + 1);
}

int Factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * Factorial(n - 1);
}

int Fibonacci(int n)
{
	if (n <= 0)
		return 0;	// Base case A

	else if (n == 1)
		return 1;	// Base case B

	else            // Recursive case
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}


int LinearSearch(std::vector<int> arr, int first, int last, int value)
{
	for (int i = first; i <= last; i++)
	{
		if (arr[i] == value)
			return i;
	}
	return -1;
}

int BinarySearch(std::vector<int> arr, int first, int last, int value)
{
	// Base case -- everything has been searched, so indicate nothing was found (-1)
	if (first > last)
		return -1;

	int middle = (first + last) / 2;

	// Return position if desired element is at position!
	if (arr[middle] == value)
		return middle;

	// Otherwise, subdivide right/left depending on whether our value is > or < arr[middle]!
	if (arr[middle] < value)
		return BinarySearch(arr, middle + 1, last, value);
	else
		return BinarySearch(arr, first, middle - 1, value);
}

int main()
{
	//Example1();
	Example2();
	return 0;
}

void Example1()
{
	// Call this... if you dare!
	//StackOverflow(); 

	// This is the recursive equivalent of a for-loop that counts from 0-9!
	//HopefullyNotAStackOverflow(10);

	// Whether its variables or functions, they all take up stack space!
	//HopefullyNotAStackOverflow(20000); <--- stack overflow
	//char data[1024]; <-- fine cause its only 1 kilobyte
	//char data[1024 * 1024]; <-- stack overflow because its 1 megabyte (our stack must be < 1 megabyte by default)!!!

	int count = Frequency('n', "Connor", 0);
	int fact = Factorial(6);
	int fib = Fibonacci(3);
}

void Example2()
{
	std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a = LinearSearch(numbers, 0, numbers.size() - 1, 2);
	int b = BinarySearch(numbers, 0, numbers.size() - 1, 2);
	if (b != -1)
		std::cout << "Value found at index " << b << std::endl;
}
