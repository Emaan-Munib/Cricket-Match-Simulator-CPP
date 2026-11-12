#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int Task()
{
	string Filename = "India.txt";
	ifstream infile(Filename);
	if (!infile.is_open())
	{
		cout << "FILE NOT FOUND\n";
		exit(-1);
	}
	string line;
	while (getline(infile, line))
	{
		cout << line<<endl;
	}
	infile.close();
	return 0;
}