#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct node
{
	int roll_no;
	string name, city, phone_no;
	float marks_subject[3];
	char grade_subject[3];
	node* nptr;
};

node* fptr = NULL;								//Global variables
node* currentptr;
int count = 0;

void display_menu();							//Function Prototypes
int check_rollno(int rollno);
void new_entry();
char calculate_grade(int marks);
void display_student();
void display_allstudents();
void search_student();
void duplicate_student();
void display_grade();
void print_line()
{
	cout << endl << "--------------------------------------------------------- >> " << endl;
}


int main()
{
	int option;
	cout << endl << "<<---Student Data storage for Sir Irtaza--->>";
	for (;;)
	{
		print_line();
		display_menu();
		cout << "Option No : ";
		cin >> option;
		if (fptr == NULL && option != 1)
		{
			if (option != 6)
			{
				cout << "Linked List has not yet been formed ! " << endl;
				continue;
			}
		}
		print_line();
		switch (option)
		{
		case 1:
			new_entry();
			break;
		case 2:
			display_allstudents();
			break;
		case 3:
			search_student();
			break;
		case 4:
			duplicate_student();
			break;
		case 5:
			display_grade();
			break;
		case 6:
			exit(0);
		default:
			cout << "Invalid Input, please try again ! " << endl;
		}
	}
	return 0;
}

// Functions defined below

void display_menu()
{
	cout << endl << endl << "Total Students added : " << ::count << endl << endl
		<< " - Press 1 to enter new student data" << endl
		<< " - Press 2 to view all students data" << endl
		<< " - Press 3 to search a student by roll no and display its information" << endl
		<< " - Press 4 to make a duplicate of student data by roll no and enter new roll no for the duplicate entry" << endl
		<< " - Press 5 to display Student name and grade only" << endl
		<< " - Press 6 to EXIT" << endl << endl;
}

int check_rollno(int rollno)
{
	currentptr = fptr;
	while (currentptr != NULL)
	{
		if (currentptr->roll_no == rollno)
		{
			return 1;
		}
		currentptr = currentptr->nptr;
	}
	return 0;
}

void new_entry()
{
	int temp;
	node* ptr;
	ptr = new node;
	ptr->nptr = NULL;

	::count++;
	cout << endl << " - Enter data for student - " << ::count << " : " << endl
		<< "Roll No : ";
	cin >> temp;

	while (check_rollno(temp) != 0)
	{
		cout << "This roll no already exists in database, try again !" << endl
			<< "Roll No : ";
		cin >> temp;
	}

	ptr->roll_no = temp;
	cout << "Name : ";
	cin.ignore();
	getline(cin, ptr->name);
	cout << "City : ";
	cin.ignore();
	getline(cin, ptr->city);
	cout << "Phone No : ";
	cin >> ptr->phone_no;
	cout << "Marks in ENGLISH : ";
	cin >> ptr->marks_subject[0];
	ptr->grade_subject[0] = calculate_grade((int)ptr->marks_subject[0]);

	cout << "Marks in URDU : ";
	cin >> ptr->marks_subject[1];
	ptr->grade_subject[1] = calculate_grade((int)ptr->marks_subject[1]);

	cout << "Marks in MATHS : ";
	cin >> ptr->marks_subject[2];
	ptr->grade_subject[2] = calculate_grade((int)ptr->marks_subject[2]);

	if (fptr == NULL)
	{
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
	cout << endl << " -- Student Data has been added ! -- " << endl;
}

char calculate_grade(int marks)
{
	if (marks >= 80)
		return 'A';
	if (marks >= 70)
		return 'B';
	if (marks >= 60)
		return 'C';
	if (marks >= 50)
		return 'D';
	else
		return 'F';
}

void display_student()
{
	cout << endl << "Roll No : " << currentptr->roll_no << endl
		<< "Name : " << currentptr->name << endl
		<< "City : " << currentptr->city << endl
		<< "Phone No : " << currentptr->phone_no << endl << endl
		<< "Marks in ENGLISH : " << currentptr->marks_subject[0] << endl
		<< "Marks in URDU : " << currentptr->marks_subject[1] << endl
		<< "Marks in MATHS : " << currentptr->marks_subject[2] << endl << endl
		<< "Grade in ENGLISH : " << currentptr->grade_subject[0] << endl
		<< "Grade in URDU : " << currentptr->grade_subject[1] << endl
		<< "Grade in MATHS : " << currentptr->grade_subject[2] << endl;
}

void display_allstudents()
{
	currentptr = fptr;
	cout << endl << " -- Data of all students added -- " << endl << endl;
	for (int i = 1; currentptr != NULL; i++)
	{
		cout << endl << "--- Student - " << i << " ---" << endl;
		display_student();
		currentptr = currentptr->nptr;
	}
}

void search_student()
{
	int input;
	currentptr = fptr;
	cout << "Enter Roll No of student to be searched : ";
	cin >> input;

	while (currentptr != NULL)
	{
		if (currentptr->roll_no == input)
		{
			display_student();
			break;
		}
		else
		{
			currentptr = currentptr->nptr;
		}
	}
	if (currentptr == NULL)
	{
		cout << "Sorry, no student found with roll no ' " << input << " ' in database" << endl;
	}
}

void duplicate_student()
{
	int input, temp, index, local_count = 1;
	node* ptr;
	ptr = new node;

	currentptr = fptr;
	cout << "Enter Roll No of student to be duplicated : ";
	cin >> input;

	while (currentptr != NULL)
	{
		if (currentptr->roll_no == input)
		{
			ptr->name = currentptr->name;
			ptr->city = currentptr->city;
			ptr->phone_no = currentptr->phone_no;
			ptr->marks_subject[0] = currentptr->marks_subject[0];
			ptr->marks_subject[1] = currentptr->marks_subject[1];
			ptr->marks_subject[2] = currentptr->marks_subject[2];
			ptr->grade_subject[0] = currentptr->grade_subject[0];
			ptr->grade_subject[1] = currentptr->grade_subject[1];
			ptr->grade_subject[2] = currentptr->grade_subject[2];

			cout << "Enter New Roll Number : ";
			cin >> temp;
			while (check_rollno(temp) != 0)
			{
				cout << "This roll no already exists in database, try again !" << endl
					<< "Enter New Roll Number : ";
				cin >> temp;
			}
			ptr->roll_no = temp;

			cout << "Enter Index ( starting from 1 ) at which the duplicated student is to be placed : ";
			cin >> index;

			if (index == 1)
			{
				ptr->nptr = fptr;
				fptr = ptr;
			}
			else
			{
				if (index > ::count + 1)
				{
					index = ::count + 1;
				}
				currentptr = fptr;
				while (local_count != (index - 1))
				{
					currentptr = currentptr->nptr;
					local_count++;
				}
				ptr->nptr = currentptr->nptr;
				currentptr->nptr = ptr;
			}
			cout << endl << "Data has been Duplicated ! " << endl;
			break;
		}
		else
		{
			currentptr = currentptr->nptr;
		}
	}
	if (currentptr == NULL)
	{
		cout << "Sorry, no student found with roll no ' " << input << " ' in database" << endl;
	}
}

void display_grade()
{
	int input;
	currentptr = fptr;
	cout << "Enter Roll No of student to be displayed : ";
	cin >> input;

	while (currentptr != NULL)
	{
		if (currentptr->roll_no == input)
		{
			cout << endl << "Name : " << currentptr->name << endl
				<< "City : " << currentptr->city << endl
				<< "Phone No : " << currentptr->phone_no << endl << endl
				<< "Grade in ENGLISH : " << currentptr->grade_subject[0] << endl
				<< "Grade in URDU : " << currentptr->grade_subject[1] << endl
				<< "Grade in MATHS : " << currentptr->grade_subject[2] << endl;
			break;
		}
		else
		{
			currentptr = currentptr->nptr;
		}
	}
	if (currentptr == NULL)
	{
		cout << "Sorry, no student found with roll no ' " << input << " ' in database" << endl;
	}
}