#include <iostream>
#include <string>
#include <cstdlib> //C standard library --> gives us access to the rand() function for random number generation!

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
	// srand "seeds" our random number generator, meaning it bases RNG on a unique number so our program randomizes differently each run!
	// We know time (second since 1970) to be an ever-changing unique number, which makes it great for seeding!
	// Note: you might NOT want to seed your rand function when testing. Determinism makes testing easier.
	srand(time(0));

	const int character_count = 10;
	Character* characters[character_count];
	for (int i = 0; i < character_count; i++)
	{
		// % 2 gives us random numbers between 0 and 1 (% 5 would give between 0 and 4)
		int n = rand() % 2;

		if (n == 0)
			characters[i] = new Player;
		else
			characters[i] = new Enemy;
	}

	for (int i = 0; i < character_count; i++)
	{
		Character& character = *characters[i];
		std::cout << character.TypeName() << ": " << character.Greet() << std::endl;
	}

	return 0;
}
