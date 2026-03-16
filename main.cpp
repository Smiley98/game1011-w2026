#include <iostream>
#include <fstream>

int main()
{
	std::ofstream out_file;
	out_file.open("./data/File.txt");
	out_file.close();
	return 0;
}
