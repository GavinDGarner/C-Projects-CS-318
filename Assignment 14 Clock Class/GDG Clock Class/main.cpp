/*
Gavin Garner CS 318
Clock Class
This program will display military time after adding or subtracting time
*/
#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

ifstream inf;
ofstream outf;

class Clock
{
private:
    int hour, minute;
public:
    Clock()
        {hour = 0; minute = 0;}
    Clock(int h, int m)
        {hour = h; minute = m;}

    void SetHour(int h)
        {hour = h;}
    void SetMinute(int m)
        {minute = m;}

    int GetHour()
        {return hour;}
    int GetMinute()
        {return minute;}

    void AddTime(Clock T)
    {
        hour = hour + T.GetHour();
        minute = minute + T.GetMinute();

        if(minute > 59)
        {
            minute = minute - 60;
            hour = hour + 1;
        }
        if(minute < 0)
        {
            minute = minute + 60;
            hour = hour - 1;
        }

        if(hour > 23)
            hour = hour - 24;
        if(hour < 0)
            hour = hour + 24;

        return;
    }

    void SubTime(Clock T)
    {
        hour = T.GetHour() - hour;
        minute = T.GetMinute() - minute;

        if(minute > 59)
        {
            minute = minute - 60;
            hour = hour + 1;
        }
        if(minute < 0)
        {
            minute = minute + 60;
            hour = hour - 1;
        }

        if(hour > 23)
            hour = hour - 24;
        if(hour < 0)
            hour = hour + 24;

        return;
    }


    void DisplayTime()
    {
        outf << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute;
        cout << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute;

        return;
    }

};


int main()
{
    inf.open("Times.txt");
    outf.open("Result.txt");

    // declaring variables
    int hr, mi; // hours and minutes
    char sign = 't', colon = ':'; // char for the sign

    // Declaring Objects
    Clock C1;
    Clock C2;
    Clock C3;

    cout << setprecision(2) << fixed; // Forcing display of hrs and mins in double digit I.E. 07 minutes
    outf << setprecision(2) << fixed;

    while (inf >> hr) //While there is an hour to be read in (All inputs are in: hh:mm +/- hh:mm   format)
    {
        C1.SetHour(hr);
        inf >> colon; // First char reads in the colon separating hrs and mins
        inf >> mi;
        C1.SetMinute(mi);

        //cout << C1.GetHour() << colon << C1.GetMinute() << " ";

        inf >> sign; // Reads a minus or plus sign
        //cout << "\n" << sign << "\n";
        inf >> hr >> colon >> mi; // import what we will manipulate with
        C2.SetHour(hr);
        C2.SetMinute(mi);

        //cout << sign << " " << C2.GetHour() << colon << C2.GetMinute() << " ";
        if(sign == '+')
        {
            cout << "Current Time: ";
            outf << "Current Time: ";
            C1.DisplayTime();
            cout << " plus " << setfill('0') << setw(2) << hr << "hr. " << setfill('0') << setw(2) << mi << " min. = Future Time ";
            outf << " plus " << setfill('0') << setw(2) << hr << "hr. " << setfill('0') << setw(2) << mi << " min. = Future Time ";
            C2.AddTime(C1); // Passing objects
            C2.DisplayTime();
            cout << endl;
            outf << endl;


        }
        else
        {
            cout << "Future Time: ";
            outf << "Future Time: ";
            C1.DisplayTime();
            cout << " minus " << setfill('0') << setw(2) << hr << "hr. "<< setfill('0') << setw(2) << mi << " min. = Start Time ";
            outf << " minus " << setfill('0') << setw(2) << hr << "hr. "<< setfill('0') << setw(2) << mi << " min. = Start Time ";
            C2.SubTime(C1); // Passing objects
            C2.DisplayTime();
            cout << endl;
            outf << endl;


        }
    }

    outf.close();
    inf.close();
    return 0;
}
