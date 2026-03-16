#include <iostream>
#include <fstream>
#include <string>

int main()
{
	{
		std::ofstream file;
		file.open("./data/File.txt");

		file << "Connor" << std::endl;
		file << "Rochelle" << std::endl;
		file << "Eliott" << std::endl;
		file << "Dominic" << std::endl;

		file.close();
	}

	{
		std::ifstream file;
		file.open("./data/File.txt");

		std::string name1, name2;
		file >> name1;
		file >> name2;

		file.close();
	}

	return 0;
}
