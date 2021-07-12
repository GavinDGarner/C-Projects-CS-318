// Gavin Garner CS 318
// Array Workout
// This program manipulates data fed into an array from an input file

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

// PROTOTYPES
void Readin(float xray[], float &HowBig);
void Print(float xray[], float HowBig);
void PrintAVG(float xray[], float HowBig);
void BiggerThanAVG(float xray[], float HowBig, float AVG);
void SmallerThanAVG(float xray[], float HowBig, float AVG);
void PrintOddOrEven(float xray[], float HowBig, int change);
void SwitchArray(float xray[], float HowBig);
void MultipleOf(float xray[], float HowBig, int multiple);
void NEGarray (float xray[], float HowBig);
void Largest(float xray[], float HowBig);
void Smallest(float xray[], float HowBig);
void FindSmaller(float xray[], float HowBig);
void FindLarger(float xray[], float HowBig);
void GreaterThanPOS(float xray[], float HowBig, int place);
void CopyArray(float xray[],float yray[], float HowBig, int change);

float ADDarray(float xray[],float HowBig);
float AVGarray (float xray[], float HowBig);




int main()
{
    //DECLARE VARIABLES
    const int MAX = 50; // maximum size of array is 50
    float Aray[MAX];
    float HowBig = 0; // This will be the total numbers that are in the array
    float Bray[MAX];


    Readin(Aray, HowBig);
    Print(Aray, HowBig);
    PrintAVG(Aray,HowBig);
    BiggerThanAVG(Aray, HowBig, AVGarray(Aray, HowBig));
    SmallerThanAVG(Aray, HowBig, AVGarray(Aray, HowBig));
    PrintOddOrEven(Aray, HowBig, 0);
    PrintOddOrEven(Aray, HowBig, 1);
    NEGarray(Aray, HowBig); // switching positive and negative values if you want to swap back copy paste this code
    PrintAVG(Aray, HowBig);
    SwitchArray(Aray, HowBig);
    MultipleOf(Aray, HowBig, 3);
    MultipleOf(Aray, HowBig, 11);
    Largest(Aray, HowBig);
    Smallest(Aray, HowBig);
    FindSmaller(Aray, HowBig);
    FindLarger(Aray, HowBig);
    GreaterThanPOS(Aray,HowBig, 15);
    CopyArray(Aray, Bray, HowBig, 0);// 0 normal order
    CopyArray(Aray, Bray, HowBig, 1);// 1 reverse order

    return 0;
}



void Readin(float xray[], float &HowBig)
{
    ifstream infile;
    infile.open("arrayV2.txt");

        if (!infile) // test if it read the file
    {
        cout << "INFILE NOT FOUND";
        return;
    }

    while (infile >> xray[static_cast<int>(HowBig)])
        {
        HowBig +=1;
        }

    infile.close();
    return;
}


void Print(float xray[], float HowBig)
{
    for(int i = 0; i < HowBig; i++)
    {
        if ((i)%10==0 && i != 0) // will move the text down 1 line every 10 numbers printed
            cout << endl;

        cout << setw(4) << xray[i] << " ";
    }
    cout << endl;
    return;
}

float ADDarray(float xray[],float HowBig)
{
    float sum = 0;
    for(int r = 0; r < HowBig; r++)
    {
        sum = sum + xray[r];
    }
    return sum;
}

float AVGarray (float xray[],float HowBig)
{
    float AVG = 0, sum = 0;
    sum = ADDarray(xray, HowBig);
    AVG = sum / HowBig;

    return AVG;
}

void PrintAVG(float xray[],float HowBig)
{
    float AVG = AVGarray(xray, HowBig);


    // cout << fixed << setprecision(2); // PLACE THIS IN IF YOU WANT TO ROUND TO A DECIMAL PLACE
    cout << "\nAverage: " << AVG << "\n";

    return;
}

void BiggerThanAVG(float xray[], float HowBig, float AVG)
{
    int counter = 0;

    for (int r = 0; r < HowBig; r+= 1)
    {
        if(xray[r] > AVG)
            counter += 1;

    }
    cout << "\nThere are " << counter << " numbers larger than the average in the data.\n";

    return;
}

void SmallerThanAVG(float xray[], float HowBig, float AVG)
{
    int counter = 0;

    for (int r = 0; r < HowBig; r+= 1)
    {
        if(xray[r] < AVG)
            counter += 1;

    }
    cout << "\nThere are " << counter << " numbers smaller than the average in the data.\n";

    return;
}

void PrintOddOrEven(float xray[], float HowBig, int change)
{
    if(change == 0)
    {
        int counter = 0;

        cout << "\nEvery other number in the Array\n";

        for(int r = 1; r<HowBig; r +=2)
        {
        counter +=1;

        if ((counter-1)%10==0 && counter != 0) // will move the text down 1 line every 10 numbers printed
            cout << endl;

        cout << setw(4) << xray[r] << " ";
        }
        cout << "\n";
    }
    if (change ==1)
    {
        int counter = 0;

        for(int r = 0; r < HowBig; r += 1)
        {
            if((static_cast<int>(xray[r]) % 2) == 0)
                counter += 1;
        }

        cout << "\nThe number of even values is: " << counter << "\n";
    }

    return;
}

void NEGarray (float xray[], float HowBig)
{
    for(int r = 0; r < HowBig; r += 1)
    {
        xray[r] = xray[r] * -1;
    }
    return;
}

void SwitchArray(float xray[], float HowBig)
{
    cout << endl;
    float temp = 0;

    xray[0] = temp;
    xray[0] = xray[static_cast<int>(HowBig-1)];
    xray[static_cast<int>(HowBig)] = temp;

    for(int r =0; r < HowBig; r += 1)
    {
        if ((r)%10==0 && r != 0) // will move the text down 1 line every 10 numbers printed
            cout << endl;

        cout << setw(4) << xray[r] << " ";
    }
    cout << endl;
    return;
}

void MultipleOf(float xray[], float HowBig, int multiple)
{
    int counter =0;
        for(int r=0; r<HowBig; r++)
        {
            if(static_cast<int>(xray[r]) % multiple == 0)
                counter += 1;
        }
        cout << "\nMultiples of " << multiple << " : " << counter << "\n";
        return;
}

void Largest(float xray[], float HowBig)
{
    float large = xray[0];
    int largePOS = 0;

    for(int r = 0; r < HowBig; r+=1)
    {
        if (xray[r] > large)
        {
            large = xray[r];
            largePOS = r+1;
        }
    }
    cout << "\n The largest number is " << large << " and it is in position " << largePOS << "\n";
    return;
}

void Smallest(float xray[], float HowBig)
{
    float small = xray[0];
    int smallPOS = 0;

    for(int r = 0; r < HowBig; r+=1)
    {
        if (xray[r] < small)
        {
            small = xray[r];
            smallPOS = r+1;
        }
    }
    cout << "\n The smallest number is " << small << " and it is in position " << smallPOS << "\n";
    return;
}

void FindSmaller(float xray[], float HowBig)
{
    int TestValue = 0, counter = 0;

    cout << "\nEnter a number, then program will determine how many numbers are less than it: ";
    cin >> TestValue;

    for(int r = 0; r < HowBig; r+=1)
    {
        if(xray[r] < TestValue)
            counter += 1;
    }

    cout << "There are " << counter << " numbers smaller than " << TestValue << "\n";
    return;
}

void FindLarger(float xray[], float HowBig)
{
    int TestValue = 0, counter = 0;

    cout << "\nEnter a number, then program will determine how many numbers are greater than it: ";
    cin >> TestValue;

    for(int r = 0; r < HowBig; r+=1)
    {
        if(xray[r] > TestValue)
            counter += 1;
    }

    cout << "There are " << counter << " numbers larger than " << TestValue << "\n";
    return;
}

void GreaterThanPOS(float xray[], float HowBig, int place)
{
    int counter = 0;

    for(int r = 0; r < HowBig; r+=1)
    {
        if(xray[r] > xray[place-1])
            counter += 1;
    }

    cout << "\nThere are " << counter << " numbers greater than number in position " << place << "\n";
    return;
}

void CopyArray(float xray[],float yray[], float HowBig, int change)// int change controls whether the function prints in normal or reverse order
{
    int Big = HowBig;
    cout << endl;
    if(change == 0)
    {
        cout << "\n Normal Order\n";
        for(int r =0;r<HowBig;r+=1)
        {
            yray[r] = xray[r];
        }
    Print(yray, HowBig);
    }
    if(change == 1)
    {
        cout << "\n Reverse Order\n";
        for (int r = 0; r<HowBig; r++)
        {
            yray[(Big-1) - r] = xray[r];
        }

    Print(yray, HowBig);
    }
}
