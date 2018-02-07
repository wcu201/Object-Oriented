
#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include <istream>
#include <fstream>


using namespace std;

//int findRotation()//finds the rotation
//{
//	string rotation;
//	int r = 0;
//	int end = 0;
//	string file_name;
//	cin >> file_name;
//	fstream the_file(file_name);
//	if (!the_file)//Checks to see if file exists
//	{
//		cout << "Unable to open" << endl;
//	}
//
//	else
//	{
//
//
//		while (getline(the_file, rotation) && end == 0)
//		{
//			r = (int)rotation[0] - 48;
//			end++;
//		}
//	}
//
//	return r;
//}

int findRotation()//finds the rotation
{

	string rotation;
	int r = 0;
	int end = 0;

	ifstream file("encrypted.txt");

	while (getline(file, rotation) && end == 0)
	{
		r = (int)rotation[0] - 48;
		end++;
	}

	return r;
}


string decypher(string word) //Takes a string and translates it 
{


	string newWord = "";

	newWord += char(word.at(0));
	for (int i = 1; i < word.length(); i++)
	{
		if (word[i] > 96 && word[i] < 102)
		{
			newWord += char(123 - (findRotation() - (word[i] - 97)));
		}
		else
		{
			if (word[i] == 32 || word[i] == 46)
			{
				newWord += char(word.at(i));
			}
			else
			{
				newWord += char(word.at(i) - findRotation());
			}
		}
	}

	return newWord;

}

int main()
{
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
		cout << decypher(lines[p]) << endl;
	}



	cin.get();
	cin.get();

}
