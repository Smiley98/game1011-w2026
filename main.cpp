#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

void Example1();
void Example2();

void SaveNames(std::string file, std::vector<std::string> names);
void LoadNames(std::string file, std::vector<std::string>& names);

int main()
{
	//Example1();
	Example2();
	return 0;
}

void Example1()
{
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

void SaveNames(std::string file_name, std::vector<std::string> names)
{
	{
		std::ofstream file;
		file.open(file_name);

		for (int i = 0; i < names.size(); i++)
			file << names[i] << std::endl;

		file.close();
	}
}

void LoadNames(std::string file_name, std::vector<std::string>& names)
{
	std::ifstream file;
	file.open(file_name);

	for (int i = 0; i < names.size(); i++)
		file >> names[i];

	file.close();
}
