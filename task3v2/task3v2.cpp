#include <iostream>
using namespace std;

struct node
{
    string data;
    node* nptr;
};
node* fptr = NULL;

int addData();
int displayData();
int findData();
void newLine()
{
    cout
        << endl
        << "<<------------------------------------------------------>>" << endl
        << endl;
}


int main()
{
    int count = 0;
    while (1)
    {
        cout
            << "[-----MAIN MENU-----]" << endl
            << "Choose the following: " << endl
            << "\t1- Add Data" << endl
            << "\t2- Find Data" << endl
            << "\t3- Display All Data" << endl;
        int option;
        cin >> option;
        if (option != 1 && count == 0 )
        {
            cout
                << "No Data has been Entered yet." << endl;
            continue;
        }
        cin.clear();
        cin.ignore();
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
        newLine();
        count++;
    }
    
}

int addData()
{
    node* ptr = new node;
    newLine();
    cout
        << "[-----ADDING NEW DATA-----]" << endl
        << "Enter Data Value: ";
    cin >> ptr->data;
    if (fptr == NULL)
    {
        ptr->nptr = NULL;
        fptr = ptr;
    }
    else
    {
        node* currentPtr = fptr;
        currentPtr = fptr;
        fptr = ptr;
        ptr->nptr = currentPtr;
    }
    return 0;
}

int findData()
{
    newLine();
    cout
        << "[-----FINDING DATA-----]" << endl;
    int dataAtNode = 1, flagForData = 0;
    cout
        << "Enter Data to find: ";
    string dataToFind;
    cin >> dataToFind;
    node* findPtr = fptr;
    while (findPtr != NULL)
    {
        if (findPtr->data == dataToFind)
        {
            cout
                << "Data Found." << endl
                << "Data is at Node [ " << dataAtNode << " ]." << endl
                << "Value of Data is: " << findPtr->data << endl;
            flagForData = 1;
            return 1;
        }
        dataAtNode++;
        findPtr = findPtr->nptr;
    }
    if (flagForData != 1)
    {
        cout
            << "\"Value not Found.\"" << endl;
    }
    return 0;
}

int displayData()
{
    int indexOFNode = 1;
    newLine();
    cout
        << "[-----DISPLAYING ALL DATA-----]"
        << endl;
    node* displayPtr = fptr;
    while (displayPtr != NULL)
    {
        cout
            << "\tData at Node [" << indexOFNode << "]: " << displayPtr->data << endl;
        displayPtr = displayPtr->nptr;
        indexOFNode++;
    }
    return 0;
}