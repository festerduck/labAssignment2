#include <iostream>
using namespace std;

struct node
{
	string data;
	node* nptr;
};
node* fptr = NULL;

int addData();

int main()
{
	cout
		<< "Choose from the following options: " << endl
		<< "1- Add Value" << endl
		<< "2- Find Data" << endl
		<< "3- Display All Data" << endl;
	int option;
	cin >> option;
	cin.clear();
	cin.ignore();
	switch (option)
	{
	case 1: 
	{
		addData();
		break;
	}
	default:
		break;
	}
	
}
int addData()
{
	node* ptr;
	ptr = new node;
	string userData;
	cin >> userData;

	if (fptr == NULL)
	{
		ptr->data = userData;
		ptr->nptr = NULL;
		fptr = ptr;
	}
	else
	{
		node* currentPtr = fptr;

	}
}