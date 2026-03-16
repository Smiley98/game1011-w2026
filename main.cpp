#include <iostream>
#include <fstream>

int main()
{
	std::ofstream out_file;
	out_file.open("./data/File.txt");

	out_file << "Connor" << std::endl;
	out_file << "Rochelle" << std::endl;
	out_file << "Eliott" << std::endl;
	out_file << "Dominic" << std::endl;

	out_file.close();
	return 0;
}
