#include <iostream>
#include <string>
using namespace std;

void addData();
void newNode(string dataEntered);
int displayData();
int findData();

struct node
{
	string data;
	node* nptr;
};

node* fptr = NULL;
int index = 0, counter = 0;

int main()
{
	char option;
	while (1)
	{
		cout << "Choose the following options: " << endl
		<< "\t1. Add data" << endl
		<< "\t2. Find Data" << endl
		<< "\t3. Display All Data" << endl;
		cin >> option;
		switch (option)
		{
		case '1':
		{
			addData();
			break;
		}
		case '2':
		{
			findData();
			break;
		}
		case '3':
		{
			displayData();
			break;
		}
		default:
			cout << "Please Select from the given options." << endl;
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
	counter++;
}
int displayData()
{
	if (counter == 0)
	{
		cout << "No Data has been entered yet." << endl;
		return 0;
	}//if
	int displayIndex = 1;
	node* displayPtr = fptr;
	while (displayPtr != NULL)
	{
		cout << "\tData at Node [ " << displayIndex << " ] = " << displayPtr->data << endl;
		displayPtr = displayPtr->nptr;
		displayIndex++;
	} //while
	return 1;
}
int findData()
{
	if (counter == 0)
	{
		cout << "No Data has been entered yet." << endl;
		return 0;
	}//if
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
	} //while
	index = 0;
	if (flag == 0)
	{
		cout << "\tValue not found." << endl;
	}
	return 1;
}
