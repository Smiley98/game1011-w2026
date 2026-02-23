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

	std::cout << player.Greet() << std::endl;
	std::cout << enemy.Greet() << std::endl;

	return 0;
}
