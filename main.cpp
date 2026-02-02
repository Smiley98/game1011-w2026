#include <iostream>

class ShallowCopy
{
public:
	ShallowCopy()
	{
		std::cout << "Default constructor called" << std::endl;
		numbers_count = 10;
		numbers = new int[numbers_count];
		for (int i = 0; i < numbers_count; i++)
		{
			numbers[i] = i * 10;
		}
	}

	ShallowCopy(const ShallowCopy& c)
	{
		std::cout << "Copy constructor called" << std::endl;

		// Shallow copy because we're copying an 8-byte pointer rather than all the memory
		numbers = c.numbers;
		numbers_count = c.numbers_count;
	}

	void ResetNumbers()
	{
		for (int i = 0; i < numbers_count; i++)
		{
			numbers[i] = i;
		}
	}

	void PrintNumbers()
	{
		for (int i = 0; i < numbers_count; i++)
		{
			std::cout << numbers[i] << std::endl;
		}
	}

private:
	int* numbers;
	int numbers_count;
};

class DeepCopy
{
public:
	DeepCopy()
	{
		std::cout << "Default constructor called" << std::endl;
		numbers_count = 10;
		numbers = new int[numbers_count];
		for (int i = 0; i < numbers_count; i++)
		{
			numbers[i] = i * 10;
		}
	}

	DeepCopy(const DeepCopy& c)
	{
		std::cout << "Copy constructor called" << std::endl;

		// Deep copy because we're allocating separate memory
		numbers = new int[c.numbers_count];
		for (int i = 0; i < c.numbers_count; i++)
			numbers[i] = c.numbers[i];
		numbers_count = c.numbers_count;
	}

	void ResetNumbers()
	{
		for (int i = 0; i < numbers_count; i++)
		{
			numbers[i] = i;
		}
	}

	void PrintNumbers()
	{
		for (int i = 0; i < numbers_count; i++)
		{
			std::cout << numbers[i] << std::endl;
		}
	}

private:
	int* numbers;
	int numbers_count;
};

void CopyExampleShallow();
void CopyExampleDeep();

// Homework: Read week 3 slides 1-14 for information on the copy-assignment operator (very similar to the copy-constructor)!
// Quiz 2 & Quiz 3 test you on all things operator-overloading!
void Example1();

int main()
{
	//CopyExampleShallow();
	//CopyExampleDeep();
	Example1();

	return 0;
}

void CopyExampleShallow()
{
	int A[] = { 1, 2, 3, 4 };

	// B is a "shallow copy" of A since its pointing to A.
	int* B = A;

	// Therefore, whenever A changes, B also changes!
	A[2] = 50;

	// Prints 50 because A == B
	//std::cout << B[2];

	std::cout << "Shallow copy example:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "A at " << i << " is " << A[i] << std::endl;
		std::cout << "B at " << i << " is " << B[i] << std::endl;
	}
	std::cout << std::endl;
}

void CopyExampleDeep()
{
	int A[] = { 1, 2, 3, 4 };
	int B[4];
	for (int i = 0; i < 4; i++)
	{
		B[i] = A[i];
	}

	A[2] = 50;

	// Prints 3 because B is a deep copy of A
	//std::cout << B[2];

	std::cout << "Deep copy example:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "A at " << i << " is " << A[i] << std::endl;
		std::cout << "B at " << i << " is " << B[i] << std::endl;
	}
}

void Example1()
{
	ShallowCopy A;
	ShallowCopy B(A);
	A.ResetNumbers();

	std::cout << "A's numbers:" << std::endl;
	A.PrintNumbers();
	std::cout << "B's numbers (same as A's numbers):" << std::endl;
	B.PrintNumbers();
	// A & B have the same numbers because B points to A since its a shallow-copy

	DeepCopy C;
	DeepCopy D(C);
	C.ResetNumbers();

	std::cout << "C's numbers:" << std::endl;
	C.PrintNumbers();
	std::cout << "D's numbers (different than C's numbers):" << std::endl;
	D.PrintNumbers();
}
