#include <iostream>
#include <fstream>
#include <string>
#include <array>

int main()
{
	std::array<std::string, 4> names =
	{
		"Connor", "Rochelle", "Eliott", "Dominic"
	};

	{
		std::ofstream file;
		file.open("./data/File.txt");

		for (int i = 0; i < names.size(); i++)
			file << names[i] << std::endl;

		file.close();
	}

	for (int i = 0; i < names.size(); i++)
		names[i].clear();

	{
		std::ifstream file;
		file.open("./data/File.txt");
		
		for (int i = 0; i < names.size(); i++)
			file >> names[i];

		file.close();
	}

	for (int i = 0; i < names.size(); i++)
		std::cout << names[i] << std::endl;

	return 0;
}
