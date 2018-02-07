#include <iostream>
#include <vector>
#include <string>

using namespace std;

class List
{
private:
	int data;
	List* next;
public:
	List* getNext()
	{
		return next;
	}

	int getData()
	{
		return data;
	}

	void setData(int n)
	{
		data = n;
	}
};

void binary(int num)
{
	if (num < 2)
		cout << num;
	else {
		binary(num / 2);
		cout << num % 2;
	}
}

List* add(const List one, const List two)
{
	List* temp1;
	List* temp2;
	List* result;
	List* temp3 = result;

	while (temp1 != nullptr)
	{
		result->setData(temp1->getData() + temp2->getData());
		temp1 = temp1->getNext();
		temp2 = temp2->getNext();
		result = result->getNext();
	}

	return temp3;

}

int binarySearch(vector<int>& v, int start, int end, int toFind) {
	if (end < start)
		return -1;
	int middle = (start + end) / 2;
	if (v[middle] == toFind)
		return middle;
	if (toFind < v[middle])
		return binarySearch(v, start, middle - 1, toFind);
	else
		return binarySearch(v, middle + 1, end, toFind);
}

	int main()
	{

	}
