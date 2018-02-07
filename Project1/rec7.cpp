#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
	PrintedMaterial(unsigned numPages)
		: numOfPages(numPages)
	{}

	virtual
		void displayNumPages() const = 0;
private:
	unsigned numOfPages;
};

void PrintedMaterial::displayNumPages() const {
	cout << numOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
	Magazine(unsigned numPages)
		: PrintedMaterial(numPages)
	{}


	void displayNumPages() const
	{
		cout << "Magazine: " << endl << "Number of Pages: ";
		PrintedMaterial::displayNumPages();
		cout << endl;
	}

protected:
private:
};

class Book : public PrintedMaterial {
public:
	Book(unsigned numPages)
		: PrintedMaterial(numPages)
	{}
protected:
private:
};

class TextBook : public Book {
public:
	TextBook(unsigned numPages, unsigned numIndxPgs)
		: Book(numPages),
		numOfIndexPages(numIndxPgs)
	{}

	void displayNumPages() const
	{
		cout << "Textbook: " << endl << "Number of Pages: ";
		PrintedMaterial::displayNumPages();
		cout << "Index pages: ";
		cout << numOfIndexPages << endl;
	}
protected:
private:
	unsigned numOfIndexPages;
};

class Novel : public Book {
public:
	Novel(unsigned numPages)
		: Book(numPages)
	{}
	void displayNumPages() const
	{
		cout << "Novel: " << endl << "Number of Pages: ";
		PrintedMaterial::displayNumPages();
	}
protected:
private:
};


// tester/modeler code
int main()
{
	TextBook t(5430, 23);
	Novel n(213);
	Magazine m(6);

	// as direct method calls
	cout << "Printing page number of printed objects" << endl << endl;
	t.displayNumPages();
	cout << endl;
	n.displayNumPages();
	cout << endl;
	m.displayNumPages();

	// Storing generic objects in a vector 
	cout << "\n\ncontainer of printed objects\n\n";
	vector< PrintedMaterial* > printedObjects;
	printedObjects.push_back(&t);
	printedObjects.push_back(&n);
	printedObjects.push_back(&m);
	for (size_t ndx = 0; ndx < printedObjects.size(); ++ndx)
	{
		printedObjects[ndx]->displayNumPages();
		cout << endl;
	}

	cin.get();
}

