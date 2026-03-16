#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string names[4] =
	{
		"Connor", "Rochelle", "Eliott", "Dominic"
	};

	{
		std::ofstream file;
		file.open("./data/File.txt");

		for (int i = 0; i < 4; i++)
			file << names[i] << std::endl;

		file.close();
	}

	for (int i = 0; i < 4; i++)
		names[i].clear();

	{
		std::ifstream file;
		file.open("./data/File.txt");
		
		for (int i = 0; i < 4; i++)
			file >> names[i];

		file.close();
	}

	for (int i = 0; i < 4; i++)
		std::cout << names[i] << std::endl;

	return 0;
}
