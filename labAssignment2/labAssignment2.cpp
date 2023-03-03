#include <iostream>
#include <string>
using namespace std;

void addData();
void newNode(string dataEntered);
void displayData();
void findData();

struct node
{
	string data;
	node* nptr;
};

node* fptr = NULL;
int index = 0;

int main()
{
	int option;
	while (1)
	{
		cout << "Choose the following options: " << endl;
		cout << "\t1. Add data" << endl;
		cout << "\t2. Find Data" << endl;
		cout << "\t3. Display All Data" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
		{
			addData();
			break;
		}
		case 2:
		{
			findData();
			break;
		}
		case 3:
		{
			displayData();
			break;
		}
		default:
			break;
		}
		cout << endl;
	}
	
	return 0;
}
void addData()
{
	string userData;
	cout << "Enter Data: " << endl;
	cin.ignore();
	getline(cin, userData, '\n');
	newNode(userData);
}
void newNode(string dataEntered)
{
	node* ptr;
	ptr = new node;

	if (fptr == NULL)
	{
		ptr->data = dataEntered;
		ptr->nptr = NULL;
		fptr = ptr;
	}
	else
	{
		node* currentptr = fptr;
		while (currentptr->nptr != NULL)
		{
			currentptr = currentptr->nptr;
		}

		ptr->data = dataEntered;
		currentptr->nptr = ptr;
		ptr->nptr = NULL;
	}
}
void displayData()
{
	int displayIndex = 1;
	node* displayPtr = fptr;
	while (displayPtr != NULL)
	{
		cout << "\tData at Node [ " << displayIndex << " ] = " << displayPtr->data << endl;
		displayPtr = displayPtr->nptr;
		displayIndex++;
	}
}
void findData()
{
	string dataToFind;
	cout << "Enter the Data You want to find: ";
	cin.ignore();
	getline(cin, dataToFind, '\n');
	cout << endl;

	int flag = 0;

	node* findPtr = fptr;
	while (findPtr != NULL)
	{
		index++;
		if (findPtr->data == dataToFind)
		{
			cout << "\tData has been found in the list." << endl;
			cout << "\tData at Node [ " << index << " ] : " << findPtr->data << endl;
			flag = 1;
			break;
		}
		findPtr = findPtr->nptr;
	}
	index = 0;
	if (flag == 0)
	{
		cout << "\tData has NOT been found in the list." << endl;
	}
}
