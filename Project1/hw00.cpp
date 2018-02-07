
#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include <istream>
#include <fstream>


using namespace std;



int findRotation(string filename)//finds the rotation
{

	string rotation;
	int r = 0;
	int end = 0;

	ifstream file(filename);

	while (getline(file, rotation) && end == 0)
	{
		r = (int)rotation[0] - 48;
		end++;
	}

	return r;
}


string decypher(string word, string filename) //Takes a string and translates it 
{


	string newWord = "";

	newWord += char(word.at(0));
	for (int i = 1; i < word.length(); i++)
	{
		if (word[i] > 96 && word[i] < 102)
		{
			newWord += char(123 - (findRotation(filename) - (word[i] - 97)));
		}
		else
		{
			if (word[i] == 32 || word[i] == 46)
			{
				newWord += char(word.at(i));
			}
			else
			{
				newWord += char(word.at(i) - findRotation(filename));
			}
		}
	}

	return newWord;

}

int main()
{
	cout << "Enter file name" << endl;

	string filename;
	cin >> filename;
	fstream file(filename);
	if (!file)//Checks to see if file exists
	{
		cout << "Unable to open" << endl;
	}

	else
	{
		cout << endl;
	}

	vector<string> lines;

	string line;
	string b;

	while (getline(file, line))//creates vector containing lines
	{

		b = line;
		lines.push_back(b);
	}
	file.close();

	for (int p = lines.size() - 1; p >= 1; p--)//prints decyphered text line by line
	{
		cout << decypher(lines[p], filename) << endl;
	}



	cin.get();
	cin.get();

}
