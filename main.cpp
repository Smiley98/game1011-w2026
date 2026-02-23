#include <iostream>
#include <string>

struct Character
{
	std::string Greet()
	{
		return "Default greeting";
	}
};

struct Player : public Character
{
	std::string Greet()
	{
		return "Hello there kind traveller :)";
	}
};

struct Enemy : public Character
{
	std::string Greet()
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
