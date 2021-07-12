// Gavin Garner CS 318
// Extra Message
// This program will pick out the hidden message in the input file (at least our message)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>

using namespace std;

//PROTOTYPES
void ReadFile();
bool Findit(string para);

ifstream inf;
ofstream outf;


int main()
{
    inf.open("Messages.txt");
    outf.open("Results.txt");

    while(inf.peek() != EOF)
    {
        ReadFile();
    }

    outf.close();
    inf.close();
    return 0;
}

void ReadFile()
{

    int nbr; // number of characters after $Y
    string para, temp1, temp2, temp3;

    getline(inf, para, '\n');

    while(Findit(para))
        {
            temp2 = para.substr(para.find("$Y"),4); // after finding first occurance, we get the 4 characters we need
            temp1 = temp2.substr(2,2); // cut $Y from number
            nbr = stoi(temp1); // length of string to print


            if (nbr < 10)
            {
                temp3 = temp1.substr(1,1);
                temp1 = temp1.substr(0,1);
                if(temp1 != "0") // Check if it is a double digit number
                {
                    outf << "NOT A DOUBLE DIGIT NUMEBER AFTER HEADER!" << endl;
                    para.replace(para.find("$Y"),2,"  "); // stops the loop from happening infinitely
                }
                else
                {
                    temp2 = para.substr(para.find("$Y"), nbr + 4); // the 4 characters again plus the string to print
                    temp1 = temp2.substr(4,nbr); // sets temp1 to be our message
                    para.replace(para.find("$Y"),4,"    "); // stops the loop from happening infinitely
                    outf << temp1 << endl;
                }
            }
            else
            {
                temp2 = para.substr(para.find("$Y"), nbr + 4); // the 4 characters again plus the string to print
                temp1 = temp2.substr(4,nbr); // sets temp1 to be our message
                para.replace(para.find("$Y"),4,"    "); // stops the loop from happening infinitely
                outf << temp1 << endl;
            }
        }

    return;
}

bool Findit(string para)
{
    if(para.find("$Y") != string::npos)
        return true;

    return false;
}
