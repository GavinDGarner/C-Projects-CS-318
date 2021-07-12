// Gavin Garner cs318
// StringsBookv3
// This program manipulates strings to accomplish six goals listed in the associated  Word doc.
#include <iostream>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

ifstream inf; // for input from a file.
ofstream outf; // for outputting to a file

// PROTOTYPES
void Write(string text); // puts text to console and file
void Divide(); // Divides Problem sections
void ClearOutput(); // Clears the output file
void ReadinCharArray(char *Arraystart);// Reads input line form file into a char array of size 100
void PrintCharBackwards(char *Arraystart); // Prints a char array backwards
void CheckPassword(char *Arraystart); //Checks passwords to meet conditions
void PrintCharArray(char *Arraystart); //Print the string
void SeparateSentence(char *Arraystart); //Separates the sentence into a readable sentence

int StrLength(char *Arraystart); // returns the number of chars in a string

char* FindAndReplace(char *str1, char *substring, char *replacestr);  // Finds a word in a string and replaces it

//Constants
const int SIZE = 200;
const int PASNUM = 9;



int main()
{
    inf.open("Input.txt");
    if(!inf) // if file is not found then stop here
    {
        Write("Failed to find File: This program will terminate");
        return 0;
    }
    ClearOutput(); // clear output file
    outf.open("Results.txt"); // reopen for output

    // Now we can begin
    char Aray[SIZE];
    char *Arraystart; // pointer for array manipulation
    Arraystart = Aray;// points to start of Array
    string sentence;


    ReadinCharArray(Arraystart);// Reads input line form file into a char array of size SIZE

    int strLength = 0;
    strLength = StrLength(Arraystart);

    Write("Problem #1: String Length");
    // lets start by printing the string itself
    while (*Arraystart != NULL) // print the char array
    {
        cout << *Arraystart;
        outf << *Arraystart;
        Arraystart++; // increment to move through array
    }
    cout << endl;
    outf << endl;
    Arraystart = Aray; // reset position of ptr

    cout << "Number of characters in this line: " << strLength;
    outf << "Number of characters in this line: " << strLength;

    Divide(); // Separate the Problems
    Write("Problem #2: Prt String Backwards");

    ReadinCharArray(Arraystart);

    PrintCharBackwards(Arraystart);

    Divide(); // Separate
    Write("Problem #3: Password Verifier");

    for(int i=0; i < PASNUM; i++)// there are 9 passwords to test in the file, change PASNUM to the num of passwords to check
    {
        ReadinCharArray(Arraystart);
        CheckPassword(Arraystart);
        // Arraystart = Aray;
    }

    Divide(); // Separate
    Write("Problem #4: Word Separator");

    ReadinCharArray(Arraystart);

    SeparateSentence(Arraystart);

    Divide();// Gotta keep'em separated
    Write("Problem #5: replaceSubstring");

    char str1[SIZE], str2[SIZE], str3[SIZE];

    ReadinCharArray(str1);
    ReadinCharArray(str2); // Replace this
    ReadinCharArray(str3); // With this

    char* fs = NULL;

    fs = FindAndReplace(str1, str2, str3);

    while (*fs != NULL)
    {
        cout << *fs;
        outf << *fs;
        fs++;
    }

    // Now we just do all that again
    Divide();
    ReadinCharArray(str1);
    ReadinCharArray(str2); // Replace this
    ReadinCharArray(str3); // With this

    *fs = NULL;

    fs = FindAndReplace(str1, str2, str3);

    while (*fs != NULL)
    {
        cout << *fs;
        outf << *fs;
        fs++;
    }

    Divide();
    Write("Problem #6:Word Replacement Pgm...");
    Write("No input file was found on BlackBoard. If one is uploaded,");
    Write("Then I will write the code. Have a Nice Day :)");

    outf.close();
    inf.close();
    return 0;
}

//FUNCTIONS

void Write(string text) // Writes to both console and file
{
    cout << text << endl;
    outf << text << endl;

    return;
}

void PrintCharArray(char *Arraystart)
{
    while(*Arraystart != NULL)// Print Password
        {
            cout << *Arraystart;
            outf << *Arraystart;
            Arraystart++;
        }
    cout << endl;
    outf << endl;
    return;
}

void Divide() // Divides Problem sections
{
    cout << "\n\n";
    outf << "\n\n";

    return;
}

void ClearOutput() // Clears contents of outfile
{
    outf.open("Results.txt", ios::out | ios::trunc);
    outf.close();
    return;
}

void ReadinCharArray(char *Arraystart) // easiest way of reading data into a char array
{
    inf.getline(Arraystart, SIZE);
    return;
}

void PrintCharBackwards(char *Arraystart) // Prints a char array backwards
{
    int strLength = StrLength(Arraystart);

    while(*Arraystart != NULL) // puts pointer at end of array
    {
        Arraystart++;
    }

    for (int i = strLength; i > 0; i--) // Prints in reverse by taking the pointer and walking it backwards
    {
        Arraystart--;
        cout << *Arraystart;
        outf << *Arraystart;
    }
       return;
}

void CheckPassword(char *Arraystart) //Checks passwords to meet conditions
{
    int capcounter = 0, lowcounter = 0, digcounter = 0;
    int strLength = StrLength(Arraystart);

    PrintCharArray(Arraystart);

    if(strLength < 7) // if Paswrd is less than 7 characters FAIL
    {

        Write("Password is too short: At least 7 characters required.");
        return;
    }

    while(*Arraystart != NULL)// Test if one uppercase and 1 lowercase exist and if it has one digit
        {
            if(isalpha(*Arraystart))
            {
                if(isupper(*Arraystart))// test if there is one or more uppercase letters
                    capcounter++;
                if(islower(*Arraystart))// test if there is one or more lowercase letters
                    lowcounter++;
            }
            if(isdigit(*Arraystart))
                digcounter++;
            Arraystart++;
        }

        if(capcounter == 0 || lowcounter == 0) //check to see if it had lower and upper
            {
                Write("Password must contain at least one uppercase and one lowercase letter.");
                return;
            }
        if(digcounter == 0) // check if we got a digit
            {
                Write("Password must contain at least one digit");
                return;
            }

    Write("Password Accepted"); // If it clears all checks then accepted
    return;
}

void SeparateSentence(char *Arraystart)
{
    int i = 0; // for tracking where we are in the loop

    while(*Arraystart != NULL)// Gonna run through and put spaces right before capital letters then convert them to lowercase
    {
        if(isupper(*Arraystart) && i != 0) // If its uppercase and not the first letter in the line
        {
            cout << " "; // put a space before we print it
            outf << " ";
            *Arraystart = *Arraystart + 32; // Swap the letter to its lowercase equivalent
        }

        cout << *Arraystart;
        outf << *Arraystart;
        Arraystart++;
        i++;
    }

    return;
}

char* FindAndReplace(char *str1, char *substring, char *replacestr)
{

    // Lets make some pointers and other stuff
    char *fs; // stringptr
    int g, cnt = 0;
    int sublength = StrLength(substring);
    int replacestrlength = StrLength(replacestr);

    // lets count how many times the substring occurs within the original string
    for (g = 0; str1[g] != '\0'; g++)
    {
        if (strstr(&str1[g], substring) == &str1[g])
        {
            cnt++;

            // Jumping to index after the substring.
            g += sublength - 1;
        }

    }
     // Making new string of enough length to contain the new string
    fs = (char*)malloc(g + cnt * (replacestrlength - sublength) + 1);

    g = 0;
    while (*str1) {
        // compare the substring with the result
        if (strstr(str1, substring) == str1) {
            strcpy(&fs[g], replacestr);
            g += replacestrlength;
            str1 += sublength;
        }
        else
            fs[g++] = *str1++;
    }

    fs[g] = '\0';
    return fs;
}

int StrLength(char *ArrayStart) // returns the number of chars in a string
{
    int i = 0;
    while(*ArrayStart !=NULL) // running through and keeping loop number stored in i
    {
        ArrayStart++;
        i++;
    }
    return i;
}
