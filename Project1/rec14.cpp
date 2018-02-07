#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct List
{
	int data;
	List* next;

	List(int data = 0): data(data){}
};

bool isPalindrome(const string& word) {
	if (word.size() < 2) return true;
	if (word[0] == word[word.size() - 1]) {
		return isPalindrome(word.substr(1, word.size() - 2));
	}
	else return false;
}

void printBin(int n) {
	if (n < 2) {
		cout << n;
	}
	else {
		printBin(n / 2);
		cout << n % 2;
	}
}

List* mixLists(List* first, List* second)
{
	List* mixed = new List;
	
	mixed->data = 0;
	while (first != nullptr)
	{
		
		mixed->data = first->data + second->data;
		mixLists(first->next, second->next, );
	}

	return mixed;
}

void listDisplay(List* headPtr) {
	List* p = headPtr;
	//    while(p->next != nullptr) {
	while (p != nullptr) {  // I have a node
		cout << p->data << ' ';
		p = p->next;  // Bump the pointer
	}
	cout << endl;
}

int main()
{
	List one(1);
	List two(2);
	List three(3);

	one.next = &two;
	two.next = &three;

	List four(4);
	List five(5);
	List six(6);

	four.next = &five;
	five.next = &six;

	List mix(2);

	mixLists(&one, &four, &mix);

	listDisplay(&mix);

	cin.get();
}