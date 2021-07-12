//Gavin Garner CS 318
//Random Paint
// This program will determine the spread of paint over an unsuspecting class

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>


using namespace std;

ofstream outfile;

// GLOBAL CONST
const int simCount = 1500 + 1; // number of simulations plus 1 for loops
const int numPaint = 85 + 1; // number of paint thrown plus 1 for loops
const int numRows = 8 + 2; // Plus 2 (these will extra rows are unused but keeps data in range
const int numColumns = 7 + 2; // Plus 2 (see above)

const int numRowsADJ = numRows - 1;
const int numColumnsADJ = numColumns - 1; // Adjusted Values Could've set these up in either order
const float percentAray = (numRows - 2)*(numColumns - 2)*(0.45);

// PROTOTYPES
void ThrowPaint(int Aray[][numColumns]);
void Splash(int Aray[][numColumns], int row, int col);
void PrintAray(int Aray[][numColumns]);
float SeatPaintAVG(int Aray[][numColumns], int row, int col);
void PrintSeatAVG(int Aray[][numColumns]);
void ZeroArray(int Aray[][numColumns]);

void PrintOptimalSeats(int Aray[][numColumns]);
int getSmallRow(int Aray[][numColumns]);
int getSmallColumn(int Aray[][numColumns]);
int getBigRow(int Aray[][numColumns]);
int getBigColumn(int Aray[][numColumns]);

void FindNumPaintCups(int Aray[][numColumns]);
int checkCups(int Aray[][numColumns]);
int checkAVGs(int Aray[][numColumns], int cups);
float AVGPaintCups(int paintCups);
int RoundedPaintCups(int paintCups);



int main()
{
    outfile.open("Result.txt");
    outfile.close();   // Clearing our previous sim


    srand(time(NULL)); // Random number seed

    int Class[numRows][numColumns] = {0};// The class is 8 rows and 7 columns but we are getting some extra
    int ClassPhase3[numRows][numColumns] = {0}; // Gonna need a separate array for phase 3

    ThrowPaint(Class);

    PrintSeatAVG(Class);

    PrintOptimalSeats(Class);

    FindNumPaintCups(ClassPhase3);

    return 0;
}

void ThrowPaint(int Aray[][numColumns])
{
    int rand1, rand2;
    for (int x = 1; x < simCount; x++)
    {
        for (int y = 1; y < numPaint; y++)// numPaint cups of paint thrown
        {
            rand1 = rand() % (numRows - 2) + 1;
            rand2 = rand() % (numColumns - 2) + 1;
            Aray[rand1][rand2] = Aray[rand1][rand2] + 2;
            Splash(Aray, rand1 ,rand2);
        }
    }
    return;
}



void Splash(int Aray[][numColumns], int row, int col)
{
    Aray[row - 1][col] = Aray[row - 1][col] + 1;
    Aray[row + 1][col] = Aray[row + 1][col] + 1;
    Aray[row][col - 1] = Aray[row][col - 1] + 1;
    Aray[row][col + 1] = Aray[row][col + 1] + 1;

    return;
}

void PrintAray(int Aray[][numColumns])
{
    outfile.open("Result.txt", ios::out | ios::app);
    for(int r = 1; r < (numRowsADJ); r++)
    {
        for(int c = 1; c < (numColumnsADJ); c++)
            outfile << setw(5) << left <<  Aray[r][c] << " ";
        outfile << "\n";
    }
    outfile << "\n";
    outfile.close();
    return;
}

float SeatPaintAVG(int Aray[][numColumns], int row, int col)
{
    float AVG = 0;

    AVG = static_cast<float>(Aray[row][col]) / (simCount - 1) ; // Number of times Sim has ran

    return AVG;
}

void PrintSeatAVG(int Aray[][numColumns])
{
    outfile.open("Result.txt", ios::out | ios::app);

    outfile << setw(60) << right << "Average Paint Per Seat in cups\n";

    for(int r = 1; r < numRowsADJ; r++)
    {
        for(int c = 1; c < numColumnsADJ; c++)
        {
            outfile << setprecision(3) << fixed;
            outfile << setw(10) << left <<  SeatPaintAVG(Aray, r, c) << " ";
        }
        outfile << "\n";
    }
    outfile << "\n";
    outfile.close();
    return;
}

void PrintOptimalSeats(int Aray[][numColumns])
{
    outfile.open("Result.txt", ios::out | ios::app);

    outfile << "\nI would choose the seat in Row " << getSmallRow(Aray) << " Column " << getSmallColumn(Aray) << "\n";
    outfile << "\nThe instructor should take a seat at Row " << getBigRow(Aray) << " Column " << getBigColumn(Aray) << "\n";

    outfile.close();
    return;
}

int getSmallRow(int Aray[][numColumns])
{
    float small = SeatPaintAVG(Aray, 1, 1);
    int myrow = 1;
    for (int r = 1; r < numRowsADJ; r++)
    {
        for (int c = 1; c < numColumnsADJ; c++)
        {
            if (SeatPaintAVG(Aray, r, c) < small)
                {
                    small = SeatPaintAVG(Aray, r, c);
                    myrow = r;

                }
        }
    }
    return myrow;
}

int getSmallColumn(int Aray[][numColumns])
{
    float small = SeatPaintAVG(Aray, 1, 1);
    int mycol = 1;
    for (int r = 1; r < numRowsADJ; r++)
    {
        for (int c = 1; c < numColumnsADJ; c++)
        {
            if (SeatPaintAVG(Aray, r, c) < small)
                {
                    small = SeatPaintAVG(Aray, r, c);
                    mycol = c;

                }
        }
    }
    return mycol;
}

int getBigRow(int Aray[][numColumns])
{
    float large = SeatPaintAVG(Aray, 1, 1);
    int row = 1;
    for (int r = 1; r < numRowsADJ; r++)
    {
        for (int c = 1; c < numColumnsADJ; c++)
        {
            if (SeatPaintAVG(Aray, r, c) > large)
                {
                    large = SeatPaintAVG(Aray, r, c);
                    row = r;

                }
        }
    }
    return row;
}

int getBigColumn(int Aray[][numColumns])
{
    float large = SeatPaintAVG(Aray, 1, 1);
    int col = 1;
    for (int r = 1; r < numRowsADJ; r++)
    {
        for (int c = 1; c < numColumnsADJ; c++)
        {
            if (SeatPaintAVG(Aray, r, c) > large)
                {
                    large = SeatPaintAVG(Aray, r, c);
                    col = c;

                }
        }
    }
    return col;
}

void FindNumPaintCups(int Aray[][numColumns]) // constraints 45% of people get 3 cups OR any row or column gets avg of 5 cups
{
    outfile.open("Result.txt", ios::out | ios::app);

    int rand1, rand2, check1, check2, paintCups = 0;
    for (int x = 1; x < simCount; x++)
    {
        check1 = 0;
        check2 = 0;
        ZeroArray(Aray);
        while (check1 == 0 && check2 == 0)
        {
            paintCups = paintCups + 1;

            rand1 = rand() % (numRows - 2) + 1;
            rand2 = rand() % (numColumns - 2) + 1;
            Aray[rand1][rand2] = Aray[rand1][rand2] + 2;
            Splash(Aray, rand1 ,rand2);

            check1 = checkCups(Aray);
            check2 = checkAVGs(Aray, paintCups);
        }

    }
    outfile << "\nWe are gonna need " << RoundedPaintCups(paintCups) << " cups of paint for a successful disturbance.";
    outfile.close();
    return;
}

int checkCups(int Aray[][numColumns])
{
    int check = 0;
    float counter = 0.0;
    for (int r = 1; r < numRowsADJ; r++)
    {
        for (int c =1; c < numColumnsADJ; c++)
        {
            if (Aray[r][c] > 3.0)
                counter += 1.0;
        }
    }
    if (counter > percentAray)
    {
        check = 1;
    }
    return check;
}

int checkAVGs(int Aray[][numColumns], int cups)
{
    int counter = 0, check = 0;
    for (int r = 1; r < numRowsADJ; r++)
    {
        for (int c =1; c < numColumnsADJ; c++)
        {
            if (static_cast<float>((Aray[r][c]/cups)) > 5.0)
                {
                    counter += 1;
                }
        }
    }
    if (counter > 0)
        check = 1;

    return check;
}

float AVGPaintCups(int paintCups)
{
    float AVG = paintCups / static_cast<float>((simCount - 1));

    return AVG;
}

void ZeroArray(int Aray[][numColumns])
{
    for (int r = 0; r < numRows; r++)
        for(int c = 0; c < numColumns; c++)
            Aray[r][c] = 0;
    return;
}

int RoundedPaintCups(int paintCups)
{
    int rounded = AVGPaintCups(paintCups);

    if (AVGPaintCups(paintCups) > rounded)
        rounded += 1;

    return rounded;
}
