// Gavin Garner CS 318
// Stats with pointers
// does stat things with a frustrating twist

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>



using namespace std;

// GLOBAL CONSTATNTS
const char* OUT_FILE = "results.txt";
const int MAX_SIZE = 100;
ifstream inf;
ofstream outf;

// PROTOTYPES
string getFilename();

float getMean(int *Aray, int size);
float getMedian(int *Aray, int size);

int getMode(int *Aray, int size);
int readFile(string file, int *Aray);


void sort(int *Aray, int size);
void reverse(int *Aray, int size);
void printBulk(int size, float mean, float median, int mode);
void printArray(int *Aray, int size);
void write(string text);

int main()
{
	string inFile;
	float mean;
	float median;
	int size;
	int mode;
	int *Aray;
	Aray = new int [MAX_SIZE];

	outf.open(OUT_FILE, ios::out | ios::trunc);
	outf << "Gavin Garner" << endl;
	outf.close();

	inFile=" ";
	while(inFile!="END" && inFile!="end")
	{
		inFile=getFilename();
		size=readFile(inFile, Aray);
		if(size!=0)
		{
            sort(Aray,size);

            write("Array:");
			printArray(Aray, size);


			mean=getMean(Aray,size);
			median=getMedian(Aray,size);
			mode=getMode(Aray, size);

			printBulk(size, mean, median, mode);

			write("Reverse 32:");
			reverse(Aray, size);
			printArray(Aray, min(size,32));
		}
	}

	if(outf.is_open())
	{
		write("WARNING: File closed on Exit");
		outf.close();
	}
	return 0;
}

string getFilename()
{
	string file;
	cout << "Enter the file, or type END to end: ";
	cin >> file;
	return file;
}


int readFile(string file, int *Aray)
{
	int *intPtr = Aray;
	int counter=0;
	inf.open(file);
	if(inf.is_open())
	{
		for(int i=0; i<MAX_SIZE && inf.peek()!=EOF;i++)
		{
			inf >> *intPtr;
			intPtr++;
			counter++;
		}
		inf.close();
	}
	else
		cout << "ERROR: file could not be opened." << endl;
	return counter;
}


void sort(int *Aray, int size)
{
	int temp;
	int *ptrX;
	int *ptrY;
	ptrX = Aray;
	ptrY=ptrX+1;
	for(int i=0; i<size; i++)
	{
		for(int j=i+1; j<size; j++)
		{
			if(*ptrX > *ptrY)
			{
				temp  = *ptrX;
				*ptrX = *ptrY;
				*ptrY = temp;
			}
			ptrY++;
		}
		ptrX++;
		ptrY=ptrX+1;
	}

	return;
}


float getMean(int *Aray, int size)
{
	int *intPtr = Aray;
	float mean=0;

	for(int i=0; i<size; i++)
	{
		mean+=*intPtr;
		intPtr++;
	}
	mean/=size;
	return mean;
}


float getMedian(int *Aray, int size)
{
	int *tempPtr=Aray;
	float median;

	tempPtr += static_cast <int>((size/2.0)+0.5);

	median = static_cast <float>(*tempPtr);

	if(size%2==0)
	{
		median+= *(tempPtr+1);
		median/=2;
	}

	return median;
}


int getMode(int *Aray, int size)
{
	int *intPtr = Aray+1;
	int number = *Aray;
	int mode = number;
	int count = 1;
	int countMode = 1;
	for (int i=1; i<size; i++)
	{
		if (*intPtr == number)
	    {
			count++;
	    }
	    else
	    {
			if (count > countMode)
			{
				countMode = count;
				mode = number;
			}
			count = 1;
			number = *intPtr;
		}
		intPtr++;
	}

	return mode;
}


void reverse(int *Aray, int size)
{
	int looper =(size/2);
	int temp;
	int *ptrX;
	int *ptrY;
	ptrX=Aray;
	ptrY=Aray+size-1;
	for(int i=0; i<looper; i++)
	{
		temp=*ptrX;
		*ptrX = *ptrY;
		*ptrY = temp;
		ptrX++;
		ptrY--;
	}

	return;
}

void printBulk(int size, float mean, float median, int mode)
{
	string tempString;
	stringstream sstm;

	sstm << endl;
	sstm << "Number of elements: " << size << endl;
	sstm << "Mean: " << fixed << setprecision(1) << mean << endl;
	sstm << "Median: " << fixed << setprecision(1) << median << endl;
	sstm << "Mode: "<< mode << endl;

	tempString = sstm.str();
	write(tempString);

	return;
}


void printArray(int *Aray, int size)
{
	int *intPtr = Aray;
	string tempString;
	stringstream sstm;

	for(int i=0; i<size; i++)
	{
		if(i%8==0)
			sstm << endl;
		sstm << setw(5) << *intPtr << ' ';
		intPtr++;
	}
	sstm <<endl;
	tempString = sstm.str();
	sstm=stringstream();
	write(tempString);

	return;
}


void write(string text)
{
	outf.open(OUT_FILE, ios::out | ios::app);
	outf << text;
	cout << text << endl;
	outf.close();
	return;
}
