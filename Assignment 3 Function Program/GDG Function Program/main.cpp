//Gavin Garner CS 318
//Function Program
// This program will use alot of functions to manipulate variables

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;



// PROTOTYPES
float Readin();
float AddFloat (float num1, float num2);
float SubFloat (float num1, float num2);
float ExpoFloat (float num1, float num2);
float IsBigger (float num1, float num2);
float IsSmaller (float num1, float num2);

void PrintFloat (float num, ofstream &outfile);
void PrintSum (float num, ofstream &outfile);
void PrintAVG (float num, ofstream &outfile);
void PrintSub (float num1, float num2, float result, ofstream &outfile);
void PrintExpo (float num1, float num2, float result, ofstream &outfile);
void PrintBigger (float num, ofstream &outfile);
void PrintSmaller (float num, ofstream &outfile);
void PrintLargeAVG (float num, ofstream &outfile);
void PrintSmallAVG (float num, ofstream &outfile);
void PrintRunningSum(float num, ofstream &outfile);


int main()
{
    ofstream outfile;
    outfile.open("Result.out");
    float num1, num2, num3, num4, num5, num6;

    //Step 1
    num1 = Readin();
    num2 = Readin();
    num3 = Readin();
    num4 = Readin();
    num5 = Readin();
    num6 = Readin();

    //Step 2
    cout << "\n" << setw(15) << right <<  "Data Set:\n";
    outfile <<  setw(15) << right << "Data Set:\n";
    PrintFloat(num1, outfile);
    PrintFloat(num2, outfile);
    PrintFloat(num3, outfile);
    PrintFloat(num4, outfile);
    PrintFloat(num5, outfile);
    PrintFloat(num6, outfile);
    cout << "\n";
    outfile << "\n";

    //Step 3
    PrintSum(AddFloat(num1,AddFloat(num2,AddFloat(num3,AddFloat(num4,AddFloat(num5, num6))))), outfile);

    //Step 4
    PrintAVG(AddFloat(num1,AddFloat(num2,AddFloat(num3,AddFloat(num4,AddFloat(num5, num6)))))/6, outfile);

    //Step 5
    PrintSub(num1, num6, SubFloat(num1, num6), outfile);

    //Step 6
    PrintSub(num2, num5, SubFloat(num2, num5), outfile);

    //Step 7
    PrintExpo(num1, num3, ExpoFloat(num1, num3), outfile);

    //Step 8
    PrintExpo(num5, num2, ExpoFloat(num5, num2), outfile);

    //Step 9
    PrintBigger(IsBigger(num1,IsBigger(num2,IsBigger(num3,IsBigger(num4,IsBigger(num5, num6))))), outfile);

    //Step 10
    PrintSmaller(IsSmaller(num1,IsSmaller(num2,IsSmaller(num3,IsSmaller(num4,IsSmaller(num5, num6))))), outfile);

    //Step 11
    PrintLargeAVG((AddFloat(num1,AddFloat(num2,AddFloat(num3,AddFloat(num4,AddFloat(num5, num6))))) - IsSmaller(num1,IsSmaller(num2,IsSmaller(num3,IsSmaller(num4,IsSmaller(num5, num6))))))/5, outfile);

    //Step 12
    PrintSmallAVG((AddFloat(num1,AddFloat(num2,AddFloat(num3,AddFloat(num4,AddFloat(num5, num6))))) - IsBigger(num1,IsSmaller(num2,IsBigger(num3,IsBigger(num4,IsBigger(num5, num6))))))/5, outfile);

    //Step 13
    cout << "\n" << setw(15) << right << "Running Total:\n";
    outfile << "\n" << setw(15) << right << "Running Total:\n";
    PrintRunningSum(num1, outfile);
    PrintRunningSum(AddFloat(num1, num2), outfile);
    PrintRunningSum(AddFloat(num2, num3), outfile);
    PrintRunningSum(AddFloat(num3, num4), outfile);
    PrintRunningSum(AddFloat(num4, num5), outfile);
    PrintRunningSum(AddFloat(num5, num6), outfile);

    outfile.close();
    return 0;
}

float Readin()
{

    float num;
    cout << "Enter 1 of 6 float numbers: ";
    cin >> num;


    return num;
}

float AddFloat (float num1, float num2)
{
    float sum;
    sum = num1 + num2;

    return sum;
}

float SubFloat (float num1, float num2)
{
    float sub;
    sub = num1 - num2;

    return sub;
}

float ExpoFloat (float num1, float num2)
{
    float expo;
    expo = pow(num1,num2);

    return expo;
}

float IsBigger (float num1, float num2)
{
    float bigger;

    bigger = num1;

    if (num1 < num2)
        bigger = num2;

    return bigger;
}

float IsSmaller (float num1, float num2)
{
    float Smaller;

    Smaller = num1;

    if (num1 > num2)
        Smaller = num2;

    return Smaller;
}

void PrintFloat (float num, ofstream &outfile)
{
    cout << setw(4) << num << " ";
    outfile << setw(4) << num << " ";

    return;
}

void PrintSum (float num, ofstream &outfile)
{
    cout << "\nSum of Numbers: " <<  setw(4) << num << "\n";
    outfile << "\nSum of Numbers: " <<  setw(4) << num << "\n";

    return;
}

void PrintAVG (float num, ofstream &outfile)
{
    cout << "\nAverage of Numbers: " <<  setw(4) << num << "\n";
    outfile << "\nAverage of Numbers: " <<  setw(4) << num << "\n";

    return;
}

void PrintSub (float num1, float num2, float result, ofstream &outfile)
{
    cout << "\nDifference of " << num1 << " and " << num2 << ": " <<  setw(4) << result << "\n";
    outfile << "\nDifference of " << num1 << " and " << num2 << ": " <<  setw(4) << result << "\n";

    return;
}

void PrintExpo (float num1, float num2, float result, ofstream &outfile)
{
    cout << "\n" << num1 << " raised to the " << num2 << " power: " <<  setw(4) << result << "\n";
    outfile << "\n" << num1 << " raised to the " << num2 << " power: " <<  setw(4) << result << "\n";

    return;
}

void PrintBigger (float num, ofstream &outfile)
{
    cout << "\nLargest of the Numbers: " <<  setw(4) << num << "\n";
    outfile << "\nLargest of the Numbers: " <<  setw(4) << num << "\n";

    return;
}

void PrintSmaller (float num, ofstream &outfile)
{
    cout << "\nSmallest of the Numbers: " <<  setw(4) << num << "\n";
    outfile << "\nSmallest of the Numbers: " <<  setw(4) << num << "\n";

    return;
}

void PrintLargeAVG (float num, ofstream &outfile)
{
    cout << "\nAverage of 5 Largest Numbers: " <<  setw(4) << num << "\n";
    outfile << "\nAverage of 5 Largest Numbers: " <<  setw(4) << num << "\n";

    return;
}

void PrintSmallAVG (float num, ofstream &outfile)
{
    cout << "\nAverage of 5 Smallest Numbers: " <<  setw(4) << num << "\n";
    outfile << "\nAverage of 5 Smallest Numbers: " <<  setw(4) << num << "\n";

    return;
}

void PrintRunningSum(float num, ofstream &outfile)
{
    cout << setw(4) << num << " ";
    outfile << setw(4) << num << " ";

    return;
}
