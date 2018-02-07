#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

struct Formula//Formula objects
{
	string formulaName;
	//Chemical Formula
	vector<string> chemicals;
	//vector containing names of all hydrocarbons with specified chemical formula
	int Cnumber;
	//number of carbon atoms
	int Hnumber;

};

void createFormula(string name_ofForm, string name_ofChem, vector<Formula> &AllFormulas)//Creates new formula object and adds it to vector
{
	Formula newFormula;
	newFormula.formulaName = name_ofForm;
	newFormula.chemicals.push_back(name_ofChem);
	AllFormulas.push_back(newFormula);
}

string CHnums(const Formula& any_formula)//Finds the amount of carbon and hydrogen atoms in Hydrocarbon
{
	int endNum;
	//Will serve as index in the chemical formula where the number ends
	for (size_t a = 1; a < any_formula.formulaName.length(); a++)
	{
		if (any_formula.formulaName[a] > 57)//Checks to see when the formula hits a letter
		{
			endNum = a;
			a = any_formula.formulaName.length();
			//ends loop once a letter is hit
		}
	}
	int carbonAtoms = stoi(any_formula.formulaName.substr(1, endNum));
	string carbonName = any_formula.formulaName.substr(1, endNum);
	//extracts substring where # of C atoms appears  
	//converts the string to an int
	int hydrogenAtoms = stoi(any_formula.formulaName.substr(endNum + 1, any_formula.formulaName.length()));
	string hydrogenName = any_formula.formulaName.substr(endNum + 1, any_formula.formulaName.length());
	string bothNames = carbonName + " " + hydrogenName;
	return bothNames;
}

int carbonNum(Formula any_formula)//converts string of carbon number to int
{
	int ind;
	for (size_t y = 0; y < CHnums(any_formula).length(); y++)
	{
		if ((char)CHnums(any_formula)[y] == ' ')
			ind = y;
	}
	int carbon = stoi(CHnums(any_formula).substr(0, ind));
	return carbon;
}

int hydrogenNum(Formula any_formula)//converts string of hydrogen number to an int
{
	int inx;
	for (size_t y = 0; y < CHnums(any_formula).length(); y++)
	{
		if ((char)CHnums(any_formula)[y] == ' ')
			inx = y;
	}
	int hydrogen = stoi(CHnums(any_formula).substr(inx + 1, CHnums(any_formula).length()));
	return hydrogen;
}

void setCnums(vector<Formula> &AllFormulas)//loops through all formulas and sets there Cnumber(amount of carbon atoms)
{
	for (size_t f = 0; f < AllFormulas.size(); f++)
	{
		AllFormulas[f].Cnumber = carbonNum(AllFormulas[f]);
	}
}

void setHnums(vector<Formula> &AllFormulas)//loops through all formulas and sets there Hnumber(amount of hydrogen atoms)
{
	for (size_t x = 0; x < AllFormulas.size(); x++)
	{
		AllFormulas[x].Hnumber = hydrogenNum(AllFormulas[x]);
	}
}

void sortHC(vector<Formula> &AllFormulas)//Sorts all formulas in vector based on Cnumber from lowest to highest
{
	vector<Formula> FormulaHolder;
	//Serves as vector temporarily holding all Formulas as they are added in the correct order
	vector<Formula> EraseHolder;
	//Serves as vector that will hold all the Formulas that will be looped through on the next iteration
	while (AllFormulas.size()>0)
	{
		int min = AllFormulas[0].Cnumber;
		//Sets minimum value as the Cnumber of the first formula
		int index = 0;
		for (size_t in = 0; in < AllFormulas.size(); in++)
		{
			if (AllFormulas[in].Cnumber < min)//if the Cnumber is less than the minimum that Cnumber becomes the new minimum
			{
				min = AllFormulas[in].Cnumber;
				index = in;
				//The index of the Formula with the minimum Cnumber is saved
			}
		}
		FormulaHolder.push_back(AllFormulas[index]);
		//Adds the Formula with the minimum value Cnumber from AllFormulas to the temporary array 
		for (int e = 0; e < index; e++)
		{
			EraseHolder.push_back(AllFormulas[e]);
		}
		for (size_t h = index + 1; h < AllFormulas.size(); h++)
		{
			EraseHolder.push_back(AllFormulas[h]);
		}
		//Loops used to copy all formulas before and after the formula with the minimum Cnumber
		AllFormulas = EraseHolder;
		//Basically removes the minimum Cnumber formula from the vector
		EraseHolder.clear();
		//Clears temporary vector so it can be used in the loop again
	}

	AllFormulas = FormulaHolder;
	//Sets our primary vector into the sorted vector
}

int main()
{
	vector<Formula> AllFormulas;
	string chemicalName;
	string carbonForm;
	cout << "Enter file name" << endl;//prompts user for file
	string filename;
	cin >> filename;
	fstream file(filename);
	if (!file)
	{
		cerr << "Unable to open file" << endl;//error message
	}
	else
	{
		while (file >> chemicalName >> carbonForm)//Reads file for hydrocarbon names and chemical formulas
		{
			bool newHydrocarbon = true;
			for (size_t p = 0; p < AllFormulas.size(); p++)
			{
				if (AllFormulas[p].formulaName == carbonForm)
				{
					newHydrocarbon = false;
					AllFormulas[p].chemicals.push_back(chemicalName);
					//If the chemical formulais already in the vector no Formula object is created 
					//Instead a chemical formulas vector object of hydrocarbons gains a new string object
				}
			}
			if (newHydrocarbon)
			createFormula(carbonForm, chemicalName, AllFormulas);
			//Creates a new Formula object
		}

		setCnums(AllFormulas);//sets number of carbon atoms for all Formula objects

		setHnums(AllFormulas);//sets number of hydrogen atoms for all Formula objects

		sortHC(AllFormulas);//sorts Formulas

		for (size_t i = 0; i < AllFormulas.size(); i++)
		{
			cout << AllFormulas[i].formulaName << endl << "========" << endl;
			//Prints chemical formula
			for (size_t o = 0; o < AllFormulas[i].chemicals.size(); o++)
			{
				cout << AllFormulas[i].chemicals[o] << endl;
				//Prints all corresponding hydrocarbons below
			}
			cout << endl;
		}
	}
	
	cin.get();
	cin.get();
}