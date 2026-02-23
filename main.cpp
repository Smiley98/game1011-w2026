#include <iostream>
#include <string>

struct Character
{
	// "virtual" means that if the same function exists in a derived class, the compiler will run that funciton instead!
	virtual std::string Greet()
	{
		return "Default greeting";
	}
};

struct Player : public Character
{
	// "override" is not required, but it makes the code easier to read (as a reminder its a virtual method)
	std::string Greet() override
	{
		return "Hello there kind traveller :)";
	}
};

struct Enemy : public Character
{
	// "override" is not required, but it makes the code easier to read (as a reminder its a virtual method)
	std::string Greet() override
	{
		return "You won't stand a chance!";
	}
};

int main()
{
	Player player;
	Enemy enemy;

	Character* characters[2] = { &player, &enemy };
	for (int i = 0; i < 2; i++)
	{
		Character& character = *characters[i];
		//characters[i]->Greet();
		std::cout << character.Greet() << std::endl;
	}

	//std::cout << player.Greet() << std::endl;
	//std::cout << enemy.Greet() << std::endl;

	return 0;
}
