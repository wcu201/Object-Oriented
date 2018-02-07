#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sequence
{
private:
	int data;
	Sequence* theNext;
	int mark = 0;
public:

	Sequence(int data = -1, Sequence* theNext = NULL): data(data), theNext(theNext) {}

	Sequence* findEnd()
	{
		if (theNext == NULL)
			return this;
		Sequence* end = theNext;
		while (end->theNext != NULL)
		{
			end = end->theNext;
		}

		return end;
	}

	void reset()
	{
		mark = 0;
	}

	void add(int i)
	{
		if (mark == 0)
		{
			if (data == -1)
			{
				data = i;
			}

			else
			{
				Sequence* p = new Sequence();

				p->data = i;

				findEnd()->theNext = p;
			}
		}
		else
		{
			if (data == -1)
			{
				data = i;
			}

			else
			{
				Sequence* p = new Sequence();

				p->data = i;

				Sequence* o = this;

				for (int i = 0; i < mark - 1; i++)
				{
					o = o->theNext;
				}

				p->theNext = o->theNext;
				o->theNext = p;
			}
		}
	}

	void remove()
	{
		if (mark == 0)
		{

			
			this->data = -1;

			
			
		}
		else
		{
	

		
				Sequence* p = new Sequence();

				p->data = i;

				Sequence* o = this;

				for (int i = 0; i < mark - 1; i++)
				{
					o = o->theNext;
				}

				p->theNext = o->theNext;
				o->theNext = p;
			
		}
	

	void next()
	{
		mark++;
	}

	bool valid()
	{}

	void clear()
	{}

	void display()
	{

		Sequence* list = this;
		while (list != NULL)
		{
			cout << list->data << " ";
			list = list->theNext;
		}

		cout << endl;
	}
};

int main()
{
	Sequence s;
	s.add(5);
	s.add(4);
	s.add(3);
	s.next();
	s.add(6);

	s.display();
	cin.get();
}