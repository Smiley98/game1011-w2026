#include <iostream>
#include <string>

void Example1();
void Example2();
void Example3();
void Example4();
void Example5();

// Extra practice 1: Write comments in each function explaining what they do
// Extra practice 2: Create Add, Sub, Mul, and Div functions that take in two numbers and output the result
int main()
{
	Example1();
	Example2();
	Example3();
	Example4();
	Example5();

	return 0;
}

void Example1()
{
	int health = 100 + 50;
	float mana = 50.75f - 25.25f;
	double speed = 25.3245234598023485902 * 2.222222222 / 1.111111111;
	unsigned long long defense = 18446744073709551615;
	std::cout << "Player has " << health << " health." << std::endl;
	std::cout << "Player has " << mana << " mana." << std::endl;
	std::cout << "Player has " << speed << " speed." << std::endl;
	std::cout << "Defense before overflow: " << defense << std::endl;

	int numerator = 10;
	defense++;
	//numerator /= defense; // Cannot divide by zero!!!
	std::cout << "Defense after overflow: " << defense << std::endl;
}

void Example2()
{
	const char* message = "Hello world!";	// String literal --> array of characters
	std::string message2 = "Hello";
	message2 += " world!";					// C++ strings (std::string) allow you to combine text
	std::cout << message << std::endl;
	std::cout << message2 << std::endl;
}

void Example3()
{
	int health = 100;
	bool can_fight = health >= 100;
	if (can_fight)
	{
		std::cout << "Ready for battle!" << std::endl;
	}
	else
	{
		std::cout << "You must rest, warrior..." << std::endl;
	}
}

void Example4()
{
	std::cout << std::endl << "Count by 1s from 0 to 9" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "i is " << i << std::endl;
	}

	std::cout << std::endl << "Count by 2s from 0 to 8" << std::endl;
	for (int i = 0; i < 10; i += 2)
	{
		std::cout << "i is " << i << std::endl;
	}

	std::cout << std::endl << "Count in powers of 2 from 0 to 8" << std::endl;
	for (int i = 1; i < 10; i *= 2)
	{
		std::cout << "i is " << i << std::endl;
	}

	std::cout << std::endl << "Count by 1 from 9 to 0" << std::endl;
	int counter = 10;
	while (counter > 0)
	{
		counter--;
		std::cout << "Counter is " << counter << std::endl;
	}
	std::cout << std::endl;
}

void Example5()
{
	// What NOT to do (very tedious to output each string to the console individually)
	//std::string item1 = "Sword";
	//std::string item2 = "Shield";
	//std::string item3 = "Bow";
	//std::string item4 = "Staff";
	//std::string item5 = "Mace";
	//
	//std::cout << item1 << std::endl;
	//std::cout << item2 << std::endl;
	//std::cout << item3 << std::endl;
	//std::cout << item4 << std::endl;
	//std::cout << item5 << std::endl;

	std::string items[5];
	items[0] = "Sword";
	items[1] = "Shield";
	items[2] = "Bow";
	items[3] = "Staff";
	items[4] = "Mace";

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Item " << i + 1 << " is a " << items[i] << std::endl;
	}
}
