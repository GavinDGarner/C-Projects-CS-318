//Gavin Garner CS 318
// Monthly Accounting Structures
// This program will provide and organize accounting information for clients


#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

// PROTOTYPES
int getLineNumber(string filename);

void Readit(struct Info Customer[]);
void NAME(string filename);

// CONSTANTS
const string CustomerInfo = "Customer.txt"; //name of customer data file

//Structures
struct Info
    {
        int ID;
        string name;
        string address;
        float balance;

    };


ifstream infile;
ofstream outfile;

int main()
{
    outfile.open("Result.txt");
    outfile.close();

    const int maxsize = getLineNumber(CustomerInfo);

    Info Customer[maxsize];
    Readit(Customer);

    NAME(CustomerInfo);


    infile.close();
    return 0;
}



// Functions
int getLineNumber(string filename)
{
    infile.open(filename);
    string line;
    int number_of_lines = 0;

    while(infile.peek() != EOF)
        {
            getline(infile,line);
            number_of_lines++;
        }
    infile.close();
    return number_of_lines;
}

void Readit(struct Info Customer[])
{
    infile.open(CustomerInfo);
    int index = 0;

    while(infile.peek() != EOF)
    {
        infile >> Customer[index].ID;
        infile >> Customer[index].name;
        infile >> Customer[index].address;
        infile >> Customer[index].balance;

        index++;
    }


    infile.close();
    return;
}

void NAME(string filename)
{
        infile.open(filename);
        outfile.open("Result.txt", ios::out | ios::app);
    string line;
    char arr[100];


    while(infile.peek() != EOF)
        {
            infile.getline(arr,100);
            for(int r = 0; r < 100;r++)
                outfile << arr[r];

            outfile << "\n";
        }
    infile.close();

    return;
}
