#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Sandwich//Task 1 sandwhich class
{
private://private sandwich objects
	const int bread;//Bread will never be changed
	int cheese;
	double mayo;
	int tomato;
	double mustard;
public:
	Sandwich(int tomato = 2, int cheese = 1, double mustard = .05, double mayo = 1) : bread(2), cheese(cheese), mayo(mayo), tomato(tomato), mustard(mustard) {}
	//Sandwich constructor initializer list
	void display() const
	{
		cout << "Bread: " << bread << endl;
		cout << "Cheese: " << cheese << endl;
		cout << "Mayo: " << mayo << endl;
		cout << "Tomato: " << tomato << endl;
		cout << "Mustard: " << mustard << endl;
		cout << endl;
	}


int getBread() const
{
	return bread;
}
int getCheese() const
{
	return cheese;
}
double getMayo() const
{
	return mayo;
}
int getTomato() const
{
	return tomato;
}
double getMustard() const
{
	return mustard;
}


//Setter methods
void setCheese(int newCheese)
{
	cheese = newCheese;
}
void setMayo(double newMayo)
{
	mayo = newMayo;
}
void setTomato(int newTomato)
{
	tomato = newTomato;
}
void setMustard(double newMustard)
{
	mustard = newMustard;
}

};
	int main()
	{

	}