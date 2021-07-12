/*
Gavin Garner CS 318
Ch13#7 Test Scores
Using classes to
*/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ofstream outf;

class TestScores
{
private:
    int score1, score2, score3, score4, score5, small;
    float sum, avg;


public:
    TestScores()
    {score1 = 0; score2 = 0; score3 = 0; score4 = 0; score5 = 0; small = 0; avg = 0; sum = 0;}

    void setScore1(int val)
    {score1 = val;}
    void setScore2(int val)
    {score2 = val;}
    void setScore3(int val)
    {score3 = val;}
    void setScore4(int val)
    {score4 = val;}
    void setScore5(int val)
    {score5 = val;}

    int getScore1()
    {return score1;}
    int getScore2()
    {return score2;}
    int getScore3()
    {return score3;}
    int getScore4()
    {return score4;}
    int getScore5()
    {return score5;}

    float Average()
    {
        sum = score1 + score2 + score3 + score4 + score5;
        avg = sum / 5;
        return avg;
    }

    float DropAvg()
    {
        int scores[5] = {score1, score2, score3, score4, score5};

        small = scores[1];
        for (int x = 0; x < 5; x++)
        {
            if (scores[x] < small)
                small = scores[x];
        }

        sum = score1 + score2 + score3 + score4 + score5 - small;

        avg = sum / 4;
        return avg;
    }

};

void Write(string q)
{
    cout << q;
    outf << q;
    return;
}


int main()
{
    outf.open("Result.txt");

    TestScores T;
    int v;

    Write("Enter test score 1 of 5: ");
    cin >> v;
    outf << v;
    Write("\n");
    T.setScore1(v);

    Write("Enter test score 2 of 5: ");
    cin >> v;
    outf << v;
    Write("\n");
    T.setScore2(v);

    Write("Enter test score 3 of 5: ");
    cin >> v;
    outf << v;
    Write("\n");
    T.setScore3(v);

    Write("Enter test score 4 of 5: ");
    cin >> v;
    outf << v;
    Write("\n");
    T.setScore4(v);

    Write("Enter test score 5 of 5: ");
    cin >> v;
    outf << v;
    Write("\n");
    T.setScore5(v);

    Write("The average of the 5 scores is: ");
    outf << T.Average();
    cout << T.Average();
    Write("\n");

    Write("The average after dropping the lowest grade: ");
    outf << T.DropAvg();
    cout << T.DropAvg();
    Write("\n");

    outf.close();
    return 0;
}
