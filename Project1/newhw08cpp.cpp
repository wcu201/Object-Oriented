#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Node
{
private:
	int data;
	Node* next;

public:
	Node(int data, Node* next = nullptr): data(data), next(next){}
	void setData(int num)
	{
		data = num;
	}

	int getData()
	{
		return data;
	}

	Node*& getNext()
	{
		return next;;
	}

	void setNext(Node* theNext)
	{
		next = theNext;
	}
};

class Polynomial
{
private:
	int degree;
	Node* coefficient;

public:
	void createList(const vector<int> &coff)
	{
		int size = coff.size();
		

		coefficient = new Node(coff[0]);

		Node* temp = coefficient;


		for (int i = 1; i < size; i++)
		{
			 
			temp->setNext(new Node(coff[i], NULL));
			temp = temp->getNext();
		}
	}


	Polynomial(vector<int> coeff )
	{
		coefficient = NULL;

		createList(coeff);

		degree = coeff.size() - 1;
	}



	Polynomial(const Polynomial& rhs)
	{
		coefficient = new Node(rhs.coefficient->getData());
		Node* temp = rhs.coefficient;
		
		Node* temp2 = coefficient;

		for (int i = rhs.degree; i > 0;i--)
		{
			temp2->setNext(new Node(temp->getData()));
			temp2 = temp2->getNext();
			temp = temp->getNext();
		}
		degree = rhs.degree;

		
	}

	Polynomial& operator=(const Polynomial rhs)
	{
		if (&rhs != this)
		{
			{
				
				Node* dstry = coefficient;
				Node* store = coefficient->getNext();

				while (store->getNext() != NULL) {
					delete dstry;
					dstry = store;
					store = store->getNext();
				}
				delete dstry;
			}
			coefficient = new Node(rhs.coefficient->getData());
			Node* temp = rhs.coefficient;

			Node* temp2 = coefficient;

			for (int i = rhs.degree; i > 0; i--)
			{
				temp2->setNext(new Node(temp->getData()));
				temp2 = temp2->getNext();
				temp = temp->getNext();
			}
			degree = rhs.degree;
		}
		return *this;
	}



	int count = 0;//used in printBackwards 

	void printBackwards(Node* coff, ostream &os)
	{
		
		if (coff != nullptr)
		{
			if (count == 0)
			{
				count++;

				printBackwards(coff->getNext(), os);

				os << coff->getData() << " ";
			}

			else
			{
				int temp = int(count);
				count++;
				printBackwards(coff->getNext(), os);

				os << coff->getData() << "x" << "^" << temp << " ";
			}
		}
	}

	void display(ostream &os)
	{
		printBackwards(coefficient, os);
		count = 0;
	}



	void operator+=(const Polynomial rhs)
	{
		int start;
		vector<int> add;

		if (degree > rhs.degree)
		{
			start = rhs.degree;

			Node* temp = coefficient;
			Node* temp2 = rhs.coefficient;

			for (int i = start; i >= 0; i--)
			{
				add.push_back(temp->getData() + temp2->getData());
				
				temp = temp->getNext();
				temp2 = temp2->getNext();
			}

			for (int i = degree; i > start; i--)
			{
				add.push_back(temp->getData());

				temp = temp->getNext();
			}
		}
		else
		{
			start = degree;

			Node* temp = coefficient;
			Node* temp2 = rhs.coefficient;

			for (int i = start; i >= 0; i--)
			{
				add.push_back(temp->getData() + temp2->getData());

				temp = temp->getNext();
				temp2 = temp2->getNext();
			}

			for (int i = rhs.degree; i > start; i--)
			{
				add.push_back(temp->getData());

				temp = temp->getNext();
			}
		}



		*this = Polynomial(add);

	}

	Polynomial operator+(const Polynomial rhs)
	{
		Polynomial result = *this;
		result += rhs;

		return result;
	}

	bool operator!=(const Polynomial rhs)
	{
		bool result = false;

		if (degree != rhs.degree)
			result = true;
		else
		{
			Node* temp = coefficient;
			Node* temp2 = rhs.coefficient;
			for (int i = degree; i <= 0; i--)
			{
				if (temp->getData() != temp2->getData())
					result = true;
				temp = temp->getNext();
				temp2 = temp2->getNext();
			}
		}
		return result;
	}
	bool operator==(const Polynomial rhs)
	{
		return !(*this != rhs);
	}


};

ostream &operator<<(ostream &os, Polynomial &rhs)
{
	rhs.display(os);
	return os;
}

int main()
{
	Polynomial test({ 3, 2, 1 });

	cout << test << endl;

	Polynomial test2({ 4, 2 });

	cout << test2 << endl;

	cout << test + test2;

	cin.get();
}