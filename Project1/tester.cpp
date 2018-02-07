#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Weapon
{
	string wepName;
	int strength;
public:
	Weapon(string wepName = "weapon", int strength = 0): wepName(wepName), strength(strength) {};
	string getName()
	{
		return wepName;
	}
};

class Warrior
{
	string name;
	Weapon weapon;
public:
	Warrior(string name, Warrior weapon) {};
};

int main()
{
	string deez = "deez";
	vector<Warrior> AllWarriors;
	Weapon myWeapon(deez, 5);
	cout << myWeapon.getName();
	cin.get();
}