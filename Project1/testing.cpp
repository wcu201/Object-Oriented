#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Base
{
public: 
	virtual void display()
	{
		cout << "Base" << endl;
	}
};

class Derived : public Base
{
public:
	virtual	void display()
	{
		cout << "der" << endl;
	}
};

class ThingHolder
{
public:
	void display()
	{
		cout << "ThingHolder\n";
	}
};

string rev(string original)
{
	string reverse = "";
    
	for (int i = original.size() - 1;i>=0; i--)
	{
		reverse += original[i];
	}

	return reverse;
}

int main()
{
	Base base;
	Derived der;
	Base* bp = &der;

	base = der;
	der.display();
	base.display();

	cin.get();
	return 0;
	
}