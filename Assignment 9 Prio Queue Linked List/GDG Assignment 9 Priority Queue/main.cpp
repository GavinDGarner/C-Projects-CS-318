// Gavin Garner CS 318
// LL Priority Queue
// This program aims to keep track of user priority levels

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


//GLOBAL & STRUCTS
struct LLNodes
{
    int value; // Priority Level
    int CusNum; // Customer ID
    LLNodes *link; // Linker
};
    LLNodes *header; //beginning of list

    ofstream outf;
    ifstream inf;


//PROTOTYPES
void Write(string message);
void Create(LLNodes *ptr1,int CusID, int NewVal);
void FlushFile();
void PrintList(LLNodes *ptr1);
void SearchAndRemove(LLNodes *ptr1, int CusID);

LLNodes* NewNode();

int main()
{
    FlushFile(); // Clear the output file
    inf.open("Priority queue.txt");
    outf.open("Results.txt");


    char responce;
    int CusID, Priority;

    while (inf.peek() != EOF)
    {
        inf >> CusID >> Priority;
        Create(header, CusID, Priority);
    }

    Write(" List");
    Write(" ID      Priority");

    PrintList(header);

    Write("Do you want to increase your priority?(Y/N): ");
    cin >> responce;
    outf << responce << endl;





    if (responce == 'Y' || responce == 'y') // we skip all this if not yes
    {
        Write("What is your Customer ID?: ");
        cin >> CusID;
        outf << CusID << endl;

        Write("What is your new Priority Level?: ");
        cin >> Priority;
        outf << Priority << endl;

        SearchAndRemove(header, CusID);
        Create(header, CusID, Priority);
        Write(" Updated List");
        Write(" ID      Priority");
        PrintList(header);
    }

    outf.close();
    inf.close();
    return 0;
}

//FUNCTIONS BEGIN HERE


void Write(string message) // Generic so i type less for Prints
{
    cout << message << endl;
    outf << message << endl;

    return;
}

void FlushFile() // Clearing output file
{
    outf.open("Results.txt", ios::out | ios::trunc);
    outf.close(); //clearing the file at the start of the program or when needed
    return;
}

void PrintList(LLNodes *ptr1) // Print Queue list
{
    ptr1 = header;

    while (ptr1 != NULL)
    {
        outf << " " << setw(6) << left << (*ptr1).CusNum << "   " << (*ptr1).value << endl;
        cout << " " << setw(4) << right << (*ptr1).CusNum << "   " << (*ptr1).value << endl;
        ptr1 = (*ptr1).link;
    }
    return;
}

LLNodes* NewNode() // Making a New Node for the list
{
    LLNodes *temp;
    temp = new LLNodes;
    (*temp).value = 0;
    (*temp).link = NULL;

    return temp;
}

void SearchAndRemove(LLNodes *ptr1, int CusID) // Find a node in the list and remove it safely
{
    ptr1 = header;
    LLNodes *prev;
    while (ptr1 != NULL && (*ptr1).CusNum != CusID)
    {
        prev = ptr1;
        ptr1 = (*ptr1).link;
    }

    if (ptr1 == NULL) // check out if it failed to find ID
        {
            Write("Search Failed");
            return;
        }
    // If we found it, I want ot move on to the next entry to copy and replace the target entry

    prev = (*ptr1).link;
    (*ptr1).value = (*prev).value;
    (*ptr1).CusNum = (*prev).CusNum;
    (*ptr1).link = (*prev).link;
    delete(prev);

    return;
}

void Create(LLNodes *ptr1,int CusID, int NewVal)// Creating entries in the list
{
    ptr1 = header;
    LLNodes *temp, *prev; // a temp for additional nodes and prev to track the previous node
    prev = NULL;

    while (ptr1 != NULL && (*ptr1).value > NewVal)
    {
        prev = ptr1;
        ptr1 = (*ptr1).link; // cycles through the nodes in the list
    }

    temp = NewNode(); // creates an empty node
    (*temp).value = NewVal;
    (*temp).CusNum = CusID;
    (*temp).link = ptr1; //assigns all the information needed into the new node and links it in

    if(prev != NULL) // links prev to the new node
    {
        (*prev).link = temp;
    }
    else
        header = temp; // sets temp as the first entry
    return;
}
