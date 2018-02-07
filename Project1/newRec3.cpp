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


	//Getter methods
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


//Truck class that will hold sandwiches
class SandwichTruck
{
private:
	vector<Sandwich> allSandwiches;//vector which holds sandwhich objects
public:
	void checkBeforeLeaving() const//method that checks and displays all sandwhiches in the truck
	{
		for (int i = 0; i < allSandwiches.size(); i++)
		{
			cout << "Customer " << i + 1 << endl << "==========" << endl;
			allSandwiches[i].display();
		}
	}
	void insertSandwich(const Sandwich& newSandwich)//places a sandwhich in the truck
	{
		allSandwiches.push_back(newSandwich);
	}

	int checkMustard(int index)//checks amount of mustard on a sandwich in the truck
	{
		return allSandwiches[index].getMustard();
	}
};

int main()
{
	Sandwich customer1;
	Sandwich customer2;
	customer2.setMustard(0);//changes customer 2's mustard
	Sandwich customer3(2, 2);//Initializes customer 3's different sandwich
	Sandwich customer4;
	SandwichTruck truck;
	//inserts all 4 sanwiches
	truck.insertSandwich(customer1);
	truck.insertSandwich(customer2);
	truck.insertSandwich(customer3);
	truck.insertSandwich(customer4);
	//checks all sandwiches
	truck.checkBeforeLeaving();
	//checks mustard of customer 2
	cout << truck.checkMustard(1) << " mustard." << endl;
	cin.get();
	return 0;
}