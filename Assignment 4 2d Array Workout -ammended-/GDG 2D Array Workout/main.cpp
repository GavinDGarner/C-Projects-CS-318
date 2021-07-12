//Gavin Garner CS 318
//2D Array Workout
// This program will work tirelessly with 2d arrays. Will be added to later

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// PROTOTYPES
int ReadRowsAndCol(int alternate);
int AddRow(int Aray[][100], int rownum,int C);
int AddCol(int Aray[][100], int Colnum,int R);
int LargeRow(int Aray[][100], int rownum,int C);
int LargeCol(int Aray[][100], int Colnum,int R);
int SmallRow(int Aray[][100], int rownum,int C);
int SmallCol(int Aray[][100], int Colnum,int R);
int FindCell(int Aray[][100], int rownum, int Colnum);
int AVGarray(int Aray[][100], int rownum, int C);
void SortRow(int Aray[][100], int rownum, int C);
void SortCol(int Aray[][100], int R, int Colnum);



void ReadInArray(int R, int C, int Aray[][100]);
void PrintRow(int Aray[][100], int rownum,int C);
void PrintCol(int Aray[][100], int Colnum,int R);
void PrintTotalsRows(int Aray[][100], int rownum1, int rownum2, int C);
void PrintTotalsCols(int Aray[][100], int Colnum1, int Colnum2, int R);

ifstream infile;


int main()
{
    int Rows = 0, Cols = 0, totalCol = 0, totalRow = 0, totalBiggest = 0, totalSmallest = 0, BigSum = 0;
    int Aray[100][100];



    Rows = ReadRowsAndCol(0);
    Cols = ReadRowsAndCol(1);

    ReadInArray(Rows, Cols, Aray);

    //Step 1
    cout << setw(20) << right << "Data in " << Rows << "x" << Cols << " Grid\n";
    for (int r = 1; r <= Rows; r++)
        PrintRow(Aray, r, Cols);

    //Step 2
    int AVG = AVGarray(Aray, Rows, Cols);
    cout << "\nAverage of All Data: " << AVG;
    cout << "\n\n";

    //Step 3
    PrintTotalsRows(Aray, 1, 10, Cols); // Print totals for first 10 rows

    //Step 4
    PrintTotalsCols(Aray, 4, 8, Rows);


    // STEPS 5 & 6 reversed because there are 25 rows not 25 columns

    //Step 5
    cout << "\nPrinting Columns 1-5\n"; // If directions change, then change 1-5 to a cin statement
    for (int c = 1; c <= 5; c++)
        PrintCol(Aray, c, Rows);

    //Step 6
    cout << "\nPrinting Rows 20-25\n"; // If directions change, then change 20-25 to a cin statement
    for (int r = 20; r <= 25; r++)
        PrintRow(Aray, r, Cols);

    cout << "\n";


    //Step 7
    for (int r = 1; r <= Rows; r+=2) // printing odd num rows
        cout << "Largest number in Row " << r << ": " << LargeRow(Aray, r, Cols) << "\n";
    cout << "\n";


    //Step 8
    for (int c = 2; c <= Cols; c+=2) // printing even num columns
        cout << "Smallest number in Column " << c << ": " << SmallCol(Aray, c, Rows) << "\n";
    cout << "\n";

    //Step 9
    for (int c = 3; c <= 6; c++) // Print total of columns 3-6
        totalCol = totalCol + AddCol(Aray, c, Rows);
    cout << "Sum of Values in Columns 3-6: " << totalCol << "\n\n";

    //Step 10
    for (int r = 10; r <= 25; r++) // Print total of columns 3-6
        totalRow = totalRow + AddRow(Aray, r, Cols);
    cout << "Sum of Values in Rows 10-25: " << totalRow << "\n\n";

    //Step 11
    for (int c = 2; c < Cols; c+=2)
        totalBiggest = totalBiggest + LargeCol(Aray, c, Rows);
    cout << "Sum of largest values in even numbered Columns: " << totalBiggest << "\n\n";

    //Step 12
    for (int r = 1; r < Rows; r++)
        totalSmallest = totalSmallest + SmallRow(Aray, r, Cols);
    cout << "Sum of smallest values in rows 1-25: " << totalSmallest << "\n\n";

    //Step 13
    BigSum = FindCell(Aray, 21, 4) + FindCell(Aray, 20, 4) + FindCell(Aray, 21, 3) + FindCell(Aray, 22, 5);
    cout << "Largest sum of adjacent Values is: " << BigSum << "\n";

    //Step 14
    for (int r = 0; r < Rows; r++)
        SortRow(Aray, r, Cols);

    cout << setw(20) << right << "\nData sorted by least to greatest by Row\n";

    for (int r = 1; r <= Rows; r++)
        PrintRow(Aray, r, Cols);

    ReadInArray(Rows, Cols, Aray); // Reseting for additional manipulation

    //Step 15
    for (int c = 0; c < Cols; c++)
        SortCol(Aray, Rows, c);

    cout << setw(20) << right << "\nData sorted by least to greatest by Column\n";

    for (int r = 1; r <= Rows; r++)
        PrintRow(Aray, r, Cols);

    ReadInArray(Rows, Cols, Aray); // Reseting for further manipulation

return 0;
}




//FUNCTIONS

int ReadRowsAndCol(int alternate)
{
    int R=0,C=0;

    infile.open("TwoDim.txt");
    infile >> R;
    infile >> C;
    infile.close();

    if(alternate == 0)
    {
        return R;
    }
    else
        return C;

}

void ReadInArray(int R, int C, int Aray[][100])
{
    int Empty1, Empty2;

    infile.open("TwoDim.txt");
    infile >> Empty1;
    infile >> Empty2;

    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
            infile >> Aray [r][c];
    }

    infile.close();

    return;
}

int AddRow(int Aray[][100], int rownum,int C)
{
    int sum = 0;

    for (int c = 0; c < C; c++)
    {
        sum = sum + Aray[rownum-1][c]; // minus 1 makes the adjustment to the correct row
    }

    return sum;
}

int AddCol(int Aray[][100], int Colnum,int R)
{
    int sum = 0;

    for (int r = 0; r < R; r++)
    {
        sum = sum + Aray[r][Colnum-1]; // minus 1 makes the adjustment to the correct column
    }

    return sum;
}

int LargeRow(int Aray[][100], int rownum,int C)
{
    int large = Aray[rownum-1][0];

    for (int c = 0; c < C; c++)
    {
        if(Aray[rownum-1][c] > large)// minus 1 makes the adjustment to the correct row
            large = Aray[rownum-1][c];
    }

    return large;
}

int LargeCol(int Aray[][100], int Colnum,int R)
{
    int large = Aray[0][Colnum];

    for (int r = 0; r < R; r++)
    {
        if(Aray[r][Colnum-1] > large)// minus 1 makes the adjustment to the correct Column
            large = Aray[r][Colnum-1];
    }

    return large;
}

int SmallRow(int Aray[][100], int rownum,int C)
{
    int small = Aray[rownum-1][0];

    for (int c = 0; c < C; c++)
    {
        if(Aray[rownum-1][c] < small)// minus 1 makes the adjustment to the correct row
            small = Aray[rownum-1][c];
    }

    return small;
}

int SmallCol(int Aray[][100], int Colnum,int R)
{
    int small = Aray[0][Colnum];

    for (int r = 0; r < R; r++)
    {
        if(Aray[r][Colnum-1] < small)// minus 1 makes the adjustment to the correct Column
            small = Aray[r][Colnum-1];
    }

    return small;
}
void PrintRow(int Aray[][100], int rownum,int C)
{
    for (int c = 0; c < C; c++)
        cout << setw(4) << Aray[rownum-1][c] << " "; //minus 1 makes the adjustment to the correct row

    cout << "\n";
    return;
}

void PrintCol(int Aray[][100], int Colnum,int R)
{
    for (int r = 0; r < R; r++)
        cout << setw(3) << Aray[r][Colnum-1] << " "; // minus 1 makes the adjustment to the correct Column

    cout << "\n";
    return;
}

int FindCell(int Aray[][100], int rownum, int Colnum)
{
    int cell = Aray[rownum-1][Colnum-1]; // minus 1 for the correct adjustments

    return cell;
}






// OPTIONAL FUNCTIONS


int AVGarray(int Aray[][100], int rownum, int C)
{
    int AVG = 0;
    for (int r = 0; r < rownum; r++)
        AVG = AVG + AddRow(Aray, rownum, C);

    AVG = AVG / (rownum*C);
    return AVG;
}


void PrintTotalsRows(int Aray[][100],int rownum1, int rownum2, int C)
{
     for (int r = rownum1; r <= rownum2; r++)
        cout << "The Total for Row" <<setw(3) <<  r << ": " << AddRow(Aray, r, C) << "\n";

    cout << "\n";

    return;
}

void PrintTotalsCols(int Aray[][100],int Colnum1, int Colnum2, int R)
{
     for (int c = Colnum1; c <= Colnum2; c++)
        cout << "The Total for Column" <<setw(3) <<  c << ": " << AddRow(Aray, R, c) << "\n";

    cout << "\n";

    return;
}

void SortRow(int Aray[][100], int rownum, int C)
{
    int original;
    rownum = rownum -1;

    for (int i = 0; i < C-1; i++)
    {

        for (int c = 0;c < C - i - 1; c++)
        {
            if (Aray[rownum][c] > Aray[rownum][c+1])
            {
                original = Aray[rownum][c+1];
                Aray[rownum][c+1] = Aray[rownum][c];
                Aray[rownum][c] = original;
            }
        }
    }
    return;
}

void SortCol(int Aray[][100], int R, int Colnum)
{
    int original;
    Colnum = Colnum -1;

    for (int i = 0; i < R-1; i++)
    {

        for (int r = 0;r < R - i - 1; r++)
        {
            if (Aray[r][Colnum] > Aray[r+1][Colnum])
            {
                original = Aray[r+1][Colnum];
                Aray[r+1][Colnum] = Aray[r][Colnum];
                Aray[r][Colnum] = original;
            }
        }
    }
    return;
}

