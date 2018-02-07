#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <string>

using namespace std;

int main()
{
	string line;
	int count = 0;
	cout << "Type in file name.";//prompts user for file name
	string filename;
	cin >> filename;
	fstream file(filename);
	if (!file)
	{
		cerr << "Unable to open file";//prints error message
	}

	else
	{
		while (getline(file, line))
		{
			cout << line << endl;//prints file line by line
			count++;//counts number of lines
		}
		cout << "Number of lines: " << count;//prints nnumber of lines
	}
	cin.get();
	cin.get();
	return 0;
}