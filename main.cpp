#include <iostream>
#include <string>

enum CharacterType
{
	TYPE_PLAYER,
	TYPE_ENEMY
};

struct Character
{
	// "virtual" means that if the same function exists in a derived class, the compiler will run that funciton instead!
	virtual std::string Greet()
	{
		return "Default greeting";
	}

	// "Pure-virtual function" --> If a class contains a pure-virtual function, then the class is considered "abstract".
	// Abstract classes cannot be instantiated. Pure-virtual functions MUST be implemented within derived classes.
	virtual CharacterType Type() = 0;
	virtual std::string TypeName() = 0;
};

struct Player : public Character
{
	// "override" is not required, but it makes the code easier to read (as a reminder its a virtual method)
	std::string Greet() override
	{
		return "Hello there kind traveller :)";
	}

	CharacterType Type() override
	{
		return TYPE_PLAYER;
	}

	std::string TypeName() override
	{
		return "Player";
	}
};

struct Enemy : public Character
{
	// "override" is not required, but it makes the code easier to read (as a reminder its a virtual method)
	std::string Greet() override
	{
		return "You won't stand a chance!";
	}

	CharacterType Type() override
	{
		return TYPE_ENEMY;
	}

	std::string TypeName() override
	{
		return "Enemy";
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
		std::cout << character.TypeName() << ": " << character.Greet() << std::endl;
	}

	//std::cout << player.Greet() << std::endl;
	//std::cout << enemy.Greet() << std::endl;

	return 0;
}
