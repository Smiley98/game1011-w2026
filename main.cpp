#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

void Example1();

void SaveNames(std::string file, std::vector<std::string> names);
void LoadNames(std::string file, std::vector<std::string>& names);

int main()
{
	//for (int i = 0; i < names.size(); i++)
	//	std::cout << names[i] << std::endl;
	//
	Example1();

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
