#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
	vector<string> hydrocarbon;
	vector<vector<string>> allHydrocarbons;
	string chemName;
	string form;
	int i = 0;
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
		while (file >> chemName >> form)
		{
			vector<string> newVector;
			allHydrocarbons.push_back(newVector);
			allHydrocarbons[i].push_back(chemName);
			allHydrocarbons[i].push_back(form);
			i++;
		}
		
		for (size_t i = 0; i < allHydrocarbons.size(); i++)
		{
			cout << allHydrocarbons[i][0] << " " << allHydrocarbons[i][1] << endl;
		}
		cout << "======================" << endl;
		for (size_t i = 0; i < allHydrocarbons.size(); i++)
		{
			cout << allHydrocarbons[i][0] << " " << allHydrocarbons[i][1] << endl;
		}
	}
	cin.get();
	cin.get();
	return 0;
}