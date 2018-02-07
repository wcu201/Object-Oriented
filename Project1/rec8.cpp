#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Instrument
{

public:
	virtual void makeSound() = 0;
	virtual void play()const = 0;

};



class Brass: public Instrument
{
private:
	unsigned mouthpiece;
public:
	void makeSound()
	{
		cout << "To make a sound... blow on a mouthpiece of size 9" << endl;
	}
};

class Trumpet: public Brass
{
private:
	unsigned mouthpiece;
public:
	Trumpet(unsigned mouthpiece = 4): mouthpiece(mouthpiece){}

	void getSize()
	{
		cout << "Mouthpiece: " << mouthpiece;
	}

	void play() const
	{
		cout << "Toot" << endl;
	}
};

class Trombone: public Brass
{
private:
	unsigned mouthpiece;
public:
	Trombone(unsigned mouthpiece = 4) : mouthpiece(mouthpiece) {}

	void play() const
	{
		cout << "Blat" << endl;
	}

};

class String: public Instrument
{
private:
	unsigned pitch;
public:
	void makeSound()
	{
		cout << "To make a sound... bow a string with pitch 567" << endl;
	}
};

class Violin: public String
{
private:
	unsigned pitch;
public:
	Violin(unsigned pitch = 0): pitch(pitch){}
	void play() const
	{
		cout << "Screech" << endl;
	}
};

class Cello: public String
{
private:
	unsigned pitch;
public:
	Cello(unsigned pitch = 0): pitch(pitch) {}

	void play() const
	{
		cout << "Squawk" << endl;
	}
};

class Percussion: public Instrument
{
public:
	void makeSound()
	{
		cout << "To make a sound... hit me!" << endl;
	}
};

class Cymbal: public Percussion
{
	void play() const
	{
		cout << "Crash" << endl;
	}
};

class Drum: public Percussion
{
public:
	void play() const
	{
		cout << "Boom" << endl;
	}
};

class Musician {
public:
	Musician() : instr(nullptr) {}
	void acceptInstr(Instrument & i) { instr = &i; }
	Instrument* giveBackInstr() {
		Instrument* tmp(instr);
		instr = nullptr;
		return tmp;
	}
	void testPlay() const {
		if (instr)
			instr->makeSound();
		else
			cerr << "have no instr\n";

	}

	void play()
	{
		if (instr != nullptr)
		instr->play();
	}
private:
	Instrument* instr;
};

class MILL
{
private:
	vector<Instrument*> inventory;
public:
	void receiveInstr(Instrument& newInst)
	{
		newInst.makeSound();
			size_t i;

			for ( i = 0; i < inventory.size(); i++)
			{


				if (inventory[i] == nullptr)
				{
					inventory[i] = &newInst;
					return;

				}

			}

			
				inventory.push_back(&newInst);

		}


	Instrument* loanOut()
	{
		
		for (size_t i = 0; i < inventory.size(); i++)
		{
			if (inventory[i] != nullptr)
			{
				Instrument* temp = inventory[i];
				inventory[i] = nullptr;
				return temp;
			}
		}

	

		return nullptr;

	}

	void dailyTestPlay()
	{
		for (Instrument* inst : inventory)
		{
			if (inst != nullptr)
			inst->makeSound();
		}
	}
};

class Orch
{
private: 
	vector<Musician> allMusicians;
public:
	void addPlayer(Musician& newPlayer)
	{
		allMusicians.push_back(newPlayer);
	}

	void play()
	{
		for (Musician m : allMusicians)
			m.play();
	}

};

int main()
{
	// The initialization phase

	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	MILL mill;
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;



	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(*mill.loanOut());
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(*mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(*mill.loanOut());
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(*mill.loanOut());
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(*mill.loanOut());
	
	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(*mill.loanOut());
	

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	cin.get();
}