#include <iostream>
#include <vector>
using namespace std;

struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;

	Node* findEnd(Node* start)
	{
		Node* end = nullptr;

		Node* check = start;
		
		while (end == nullptr)
		{
			if (check->next == nullptr)
				end = check;
			else
				check = check->next;
		}

		return end;
	}

	int findSize(Node start)
	{
		int count = 1;

		Node* end = nullptr;

		Node* check = &start;

		while (end == nullptr)
		{
			if (check->next == nullptr)
				end = check;
			else
			{
				check = check->next;
				count++;
			}
		}

		return count;

	}

	void splice(Node* insertion)
	{
		
		this->findEnd(this)->next = insertion->next;

		insertion->next = this;
	}


};

void listDisplay(Node* headPtr) {
	Node* p = headPtr;
	//    while(p->next != nullptr) {
	while (p != nullptr) {  // I have a node
		cout << p->data << ' ';
		p = p->next;  // Bump the pointer
	}
	cout << endl;
}

void converter(vector<int>& vec, Node* node)
{
	Node* start = node;
	while (start != nullptr)
	{
		vec.push_back(start->data);
	}
}

/*void findVec(const vector<int> vec1, const vector<int> vec2)
{
	for (size_t i = 0; i < vec1.size(); i++)
	{
		if (vec1[i]==vec2[0])
			if((vec1.size()-i)>=vec2.size())
				for(size_t p = i)
	}
}*/


Node* search(Node& list, Node& sublist)
{
	cout << "Attempt match: ";
	listDisplay(&sublist);
	Node* result = NULL;
	Node* check = &list;
	bool match = false;
	
	Node* list_check = &list;
	Node* sublist_check = &sublist;

	while (check != nullptr)
	{
		if (check->data == sublist.data)
		if(check->findSize(*check)>=sublist.findSize(sublist))
		{ 
			list_check = check;
			sublist_check = &sublist;
			for (int i = 0; i < sublist.findSize(sublist); i++)
			{

				match = true;
				if (list_check->data != sublist_check->data)
				{
					match = false;
					i = sublist.findSize(sublist);
				}
				else
				{
					list_check = list_check->next;
					sublist_check = sublist_check->next;
				}


			}

		

			}
		
		if (match == true)
		{
			result = check;
			check = nullptr;
		}
		else
		check = check->next;
	}


	return result;
}

Node* search2(Node list, Node sublist)
{
	
	Node* result = NULL;
	Node* check = &list;
	bool match = false;

	Node* list_check = &list;
	Node* sublist_check = &sublist;

	while (check != nullptr)
	{
		if (check->data == sublist.data)
			if (check->findSize(*check) >= sublist.findSize(sublist))
			{
				list_check = check;
				sublist_check = &sublist;
				for (int i = 0; i < sublist.findSize(sublist); i++)
				{

					match = true;
					if (list_check->data != sublist_check->data)
					{
						match = false;
						i = sublist.findSize(sublist);
					}
					else
					{
						list_check = list_check->next;
						sublist_check = sublist_check->next;
					}


				}



			}

		if (match == true)
		{
			result = check;
			check = nullptr;
		}
		else
			check = check->next;
	}


	return result;
}

int main()
{
	Node end(6, nullptr);
	Node eighth(5, &end);
	Node seventh(4, &eighth);
	Node sixth(2, &seventh);
	Node fifth(3, &sixth);
	Node fourth(2, &fifth);
	Node third(3, &fourth);
	Node second(2, &third);
	Node first(1, &second);

	listDisplay(&first);

	cout << endl;

	Node end2(4, nullptr);
	Node mid(2, &end2);
	Node next(3, &mid);
	Node start(2, &next);

	Node one(1, nullptr);

	Node twoend(3, nullptr);
	Node two(2, &twoend);

	Node two2end(9, nullptr);
	Node two2(3, &two2end);

	Node end1(6, nullptr);
	Node mid1(5, &end1);
	Node next1(4, &mid1);
	Node start1(2, &next1);

	Node three3(7, nullptr);
	Node three2(6, &three3);
	Node three(5, &three2);


	Node end3(6, nullptr);
	Node mid3(5, &end3);
	Node start3(4, &mid3);

	start.splice(&start3);

	listDisplay(&start3);

	cout << "Part two:" << endl;

	cout << "Target: ";
	listDisplay(&first);

	if (search2(first, one) == NULL)
	{
		cout << "Attempt match: ";
		listDisplay(&one);
		cout << endl << "Failed to match" << endl;
	}
	else
		listDisplay(search(first, one));

	if (search2(first, two2) == NULL)
	{
		cout << "Attempt match: ";
		listDisplay(&two2);
		cout << endl << "Failed to match" << endl;
	}
	else
		listDisplay(search(first, two2));

	if (search2(first, two) == NULL)
	{
		cout << "Attempt match: ";
		listDisplay(&two);
		cout << endl << "Failed to match" << endl;
	}
	else
		listDisplay(search(first, two));

	if (search2(first, start1) == NULL)
	{
		cout << "Attempt match: ";
		listDisplay(&start1);
		cout << endl << "Failed to match" << endl;
	}
	else
		listDisplay(search(first, start1));
	
	if (search2(first, start) == NULL)
	{
		cout << "Attempt match: ";
		listDisplay(&start);
		cout << endl << "Failed to match" << endl;
	}
	else
	listDisplay(search(first, three));

	if (search2(first, three) == NULL)
	{
		cout << "Attempt match: ";
		listDisplay(&start);
		cout << endl << "Failed to match" << endl;
	}
	else
		listDisplay(search(first, three));

	cin.get();
}
