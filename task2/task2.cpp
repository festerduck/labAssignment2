#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//nodeStructure
struct node
{
	string
		stdName,
		stdRoll,
		stdCity,
		stdPhone;
	int
		stdMarks[3];
	node* nptr;
};


//functionPrototypes
void newLine();
int newNode();
int checkRollNo(string rollNo);
int displayData();
int addData(node* ptr);
node* fptr = NULL;
node* currentPtr;

//globalVaribles
int indexOfStudent = 0;


//mainFuntion
int main()
{

	while (1)
	{
		cout 
			<< endl << ">>----------------- STUDENT DATABASE -----------------<<" << endl << endl
			<< " >>------- [Students in the Database: " << indexOfStudent << " ]  -------<<" << endl
			<< endl;
		cout 
			<< "  Press 1 to Enter New Data" << endl
			<< "  Press 2 to View all student data" << endl
			<< "  Press 3 to search a student by his Roll No and display his information" << endl
			<< "  Press 4 to make duplicate student data by roll and enter new Roll No for duplicate entry" << endl
			<< "  Press 5 to exit" 
			<< endl;
		int option;
		cin >> option;
		cin.clear();
		cin.ignore(500, '\n');
		switch (option)
		{
		case 1:
		{
			newNode();
			break;
		}
		case 2:
		{
			displayData();
			break;
		}
		case 5:
		{
			exit(0);
			break;
		}
		default:
			cout 
				<< "Invalid Value." 
				<< endl;
			break;
		}
	}

}

void newLine()
{
	cout 
		<< "<<<<---------------------------------------------->>>>" 
		<< endl;
	
}

int newNode()
{
	node* ptr;
	ptr = new node;
	ptr->nptr = NULL;

	addData(ptr);

	if (fptr == NULL)
	{
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
		currentptr->nptr = ptr;
	}
	return 0;
}
int addData(node* ptr)
{
	string givenRollNo;
	node* addPtr = ptr;
	newLine();
	cout 
		<< "ENTERING NEW DATA" 
		<< endl;
	while (1)
	{
		cout 
			<< "Enter Roll No. of the Student: ";
		getline(cin, givenRollNo, '\n');
		if (checkRollNo(givenRollNo) != 1)
		{
			cout 
				<< "Roll No.Already Exists." 
				<< endl;
			continue;
		}
		break;
	}
	addPtr->stdRoll = givenRollNo;
	cout 
		<< "Enter Student Name: ";
	getline(cin, addPtr->stdName, '\n');
	cout 
		<< "Enter City Name: ";
	getline(cin, addPtr->stdCity, '\n');
	cout 
		<< "Enter Phone No.: ";
	getline(cin, addPtr->stdPhone, '\n');
	for (int i = 0; i < 3; i++)
	{
			cout 
				<< "Enter Marks of Subject [" << i + 1 << "]: " << endl;
			cin >> addPtr->stdMarks[i];
			cin.clear();
			cin.ignore(100, '\n');
	}

	indexOfStudent++;
	return 0;
}
int checkRollNo(string rollNo)
{
	node* checkPtr = fptr;
	while (checkPtr != NULL)
	{
		if (checkPtr->stdRoll == rollNo)
			return 0;
		checkPtr = checkPtr->nptr;
	}
	return 1;
}

int displayData()
{
	node* displayPtr = fptr;
	int displayIndex = 1;
	newLine();
	cout 
		<< "DISPLAYING ALL DATA" 
		<< endl;
	while (displayPtr != NULL)
	{
		cout
			<< "\tData of Student # [ " << indexOfStudent << " ]" << endl
			<< "\tRoll No. : " << displayPtr->stdRoll << endl
			<< "\tStudent Name : " << displayPtr->stdName << endl
			<< "\tCity Name: " << displayPtr->stdCity << endl
			<< "\tPhone No.: " << displayPtr->stdPhone 
			<< endl;
		for (int i = 0; i < 3; i++)
		{
			cout 
				<< "\tMarks of Subject [" << i + 1 << "]: " 
				<< displayPtr->stdMarks[i] 
				<< endl;

		}
		cout 
			<< "<<-------------------------->>" 
			<< endl;
		displayPtr = displayPtr->nptr;
		displayIndex++;
	} //while
	return 0;
}