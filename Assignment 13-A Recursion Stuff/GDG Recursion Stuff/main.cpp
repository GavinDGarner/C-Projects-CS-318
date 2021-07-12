/*
Gavin Garner CS 318
Recursion Stuff
Executing particular operations using recursion
*/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ofstream outf;

//PROTOTYPES
void Write(string q);
int CountDigits (int number, int &Digits);
int FirstDigit(int number, int &digit);
int DigitSum(int number, int &sum);
int Multiply(int x, int &y, int &sum);
int SumOfAll(int number, int &sum);
void PrintBackwards(int number, int &digit);

int main()
{
    outf.open("Result.txt");

    int data[3], number1, number2, digit = 0, sum = 0;

    // PART 1 # of digits
    Write("Part 1:");
    Write("Enter a number and we will count the # of digits in it: ");
    for (int x = 0; x < 3; x++)// gonna loop 3 times as per instructions
    {
        cin >> data[x];
        outf << data[x] << endl;

        digit = 0;
        digit = CountDigits(data[x], digit);

        cout << "# of digits in the number: " << digit << endl;
        outf << "# of digits in the number: " << digit << endl;
    }
    Write("\n");

    //PART 2 First number
    Write("Part 2:");
    Write("Using data entered, we will return the first digit: ");
    for (int x = 0; x < 3; x++)// gonna loop 3 times as per instructions
    {
        digit = 0;
        digit = FirstDigit(data[x], digit);

        cout << "First of digit in the number: " << digit << endl;
        outf << "First of digit in the number: " << digit << endl;
    }
    Write("\n");


    //PART 3 Sum of digits
    Write("Part 3:");
    Write("Using data entered, we will return the sum of the digits: ");
    for (int x = 0; x < 3; x++)// gonna loop 3 times as per instructions
    {

    digit = 0;
    digit = DigitSum(data[x], digit);

    cout << "Sum of digits in the number: " << digit << endl;
    outf << "Sum of digits in the number: " << digit << endl;
    }
    Write("\n");


    //PART 4 Ch20 #5
    Write("Part 4-A:");
    Write("Enter two numbers and we will multiply that number recursively: ");

    cin >> number1;
    outf << number1 << endl;
    cin >> number2;
    outf << number2 << endl;

    sum = 0;
    sum = Multiply(number1, number2, sum);

    cout << number1 << "x" << number2 << " = " << sum << endl;
    outf << number1 << "x" << number2 << " = " << sum << endl;

    Write("\n");

    //PART 4 Ch20 #7
    Write("Part 4-B:");
    Write("Using data entered, we will add all integers in that number: ");
    for (int x = 0; x < 2; x++) // running twice as per instructed
    {
    cin >> number1;
    outf << number1 << endl;

    sum = 0;
    sum = SumOfAll(number1, sum);

    cout << "Sum of all integers in number: " << sum << endl;
    outf << "Sum of all integers in number: " << sum << endl;
    }
    Write("\n");


    // PART 5 # Print Backwards
    Write("Part 5:");
    Write("Using data entered, Printing numbers backwards: ");
    for (int x = 0; x < 3; x++)// gonna loop 3 times as per instructions
    {
        PrintBackwards(data[x], digit);

    }
    Write("\n");

    outf.close();
    return 0;
}

void Write(string q)
{
    cout << q << endl;
    outf << q << endl;
    return;
}

int CountDigits (int number, int &digit)
{
    if(number == 0)
        return digit;
    digit++;
    number = number / 10;
    CountDigits(number, digit);
    return digit;
}

int FirstDigit(int number, int &digit)
{
    if (number/10 == 0)
    {
        digit = number;
        return digit;
    }
    number = number / 10; // shave off 1 digit
    FirstDigit(number, digit);
    return digit;

}

int DigitSum(int number, int &sum)
{
    if(number == 0)
        return sum;
    sum = sum + (number%10);
    number = number / 10;
    DigitSum(number, sum);
    return sum;
}

int Multiply(int x, int &y, int &sum)
{
    if (x == 0)
        return sum;
    sum = sum + y;
    x--;
    Multiply(x, y, sum);
    return sum;
}

int SumOfAll(int number, int &sum)
{
    if (number == 0)
        return sum;
    sum = sum + number;
    number--;
    SumOfAll(number, sum);
    return sum;
}

void PrintBackwards(int number, int &digit)
{
    if (number == 0)
    {
        Write("\n"); // moving to a new line at the end of number
        return;
    }
    digit = number %10;
    cout << digit;
    outf << digit;
    number = number/10;
    PrintBackwards(number, digit);
    return;
}
