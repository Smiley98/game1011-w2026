#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

void Example1();
void Example2();
void Example3();
void Example4();

void SaveName(std::string file, std::string name);

void SaveNames(std::string file_name, std::vector<std::string> names);
void LoadNames(std::string file_name, std::vector<std::string>& names);

struct Game
{
	int lives_count;
	int achievements_count;

	int health;
	int mana;
};

int main()
{
	//Example1();
	//Example2();
	//Example3();
	Example4();
	return 0;
}

void Example1()
{
	// Note -- files "truncate" by default meaning they wipe their data when you save/load them
	// (You must re-save ALL your data to a file even if you're adding something like a 5th name)

	const std::string file_name = "./data/File.txt";
	std::vector<std::string> names = { "Connor", "Rochelle", "Eliott", "Dominic" };

	SaveNames(file_name, names);

	for (int i = 0; i < names.size(); i++)
		names[i].clear();

	LoadNames(file_name, names);
	
	for (int i = 0; i < names.size(); i++)
		std::cout << names[i] << std::endl;
}

void Example2()
{
	const std::string file_name = "./data/Murphy.txt";

	{
		std::ofstream file;
		file.open(file_name);

		file << "Jayne Murphy" << std::endl;
		file << "47 Jones Circle" << std::endl;
		file << "Almond, NC 28702";

		file.close();
	}
	
	{
		std::ifstream file;
		file.open(file_name);

		// Read the file word-by-word until we've reached the end
		std::vector<std::string> text;

		while (!file.eof())
		{
			// Read file word-by-word
			//std::string word;
			//file >> word;
			//std::getline(file, word, ' ');	// <-- Delimiter is ' '

			// Read file line-by-line
			std::string line;
			std::getline(file, line);			// <-- Delimiter is '\n' by default
			text.push_back(line);
		}

		for (int i = 0; i < text.size(); i++)
			std::cout << text[i] << std::endl;
	}
}

void Example3()
{
	// Note that the file no longer truncates since we're opening with ios::app
	const std::string file_name = "./data/File.txt";

	std::vector<std::string> names = { "Connor", "Rochelle", "Eliott", "Dominic" };
	SaveName(file_name, names[0]);
	SaveName(file_name, names[1]);
	SaveName(file_name, names[2]);
	SaveName(file_name, names[3]);
}

void Example4()
{
	const std::string file_name = "./data/File.bin";

	{
		Game game;
		game.achievements_count = 10;
		game.lives_count = 3;
		game.health = 100;
		game.mana = 50;

		std::ofstream file;
		file.open(file_name, std::ios::binary);
		file.write((char*)&game, sizeof(Game));
		file.close();
	}

	{
		Game game;
		
		std::ifstream file;
		file.open(file_name, std::ios::binary);
		file.read((char*)&game, sizeof(Game));
		file.close();
	}
}

void SaveName(std::string file_name, std::string name)
{
	std::ofstream file;
	file.open(file_name, std::ios::app);
	file << name << std::endl;
	file.close();
}

void SaveNames(std::string file_name, std::vector<std::string> names)
{
	std::ofstream file;
	file.open(file_name);

	for (int i = 0; i < names.size(); i++)
		file << names[i] << std::endl;

	file.close();
}

void LoadNames(std::string file_name, std::vector<std::string>& names)
{
	std::ifstream file;
	file.open(file_name);

	for (int i = 0; i < names.size(); i++)
		file >> names[i];

	file.close();
}
