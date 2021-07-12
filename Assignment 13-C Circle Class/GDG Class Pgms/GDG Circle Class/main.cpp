/*
Gavin Garner CS 318
Ch13#8 Circle Class
Using classes to generate details of a circle
*/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ofstream outf;

class Circle
{
private:
    float radius;
    const float PI = 3.14159;
public:
    Circle()
    {radius = 0.0;}

    void setRadius(float v)
    {radius = v;}
    float getRadius()
    {return radius;}

    float getArea()
    {return (radius * radius * PI);}

    float getDiameter()
    {return (radius * 2);}

    float getCircumference()
    {return (2 * PI * radius);}
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
    float v;
    Circle C;

    Write("Enter the radius of the first circle: ");
    cin >> v;
    outf << v;
    C.setRadius(v);
    Write("\n");

    Write("The Area of the circle is: ");
    v = C.getArea();
    cout << setprecision(3) << fixed << v;
    outf << setprecision(3) << fixed << v;
    Write("\n");

    Write("The Diameter of the circle is: ");
    v = C.getDiameter();
    cout << setprecision(3) << fixed << v;
    outf << setprecision(3) << fixed << v;
    Write("\n");

    Write("The Circumference of the circle is: ");
    v = C.getCircumference();
    cout << setprecision(3) << fixed << v;
    outf << setprecision(3) << fixed << v;
    Write("\n");

    Write("\nEnter the radius of the second circle: ");
    cin >> v;
    outf << v;
    C.setRadius(v);
    Write("\n");

    Write("The Area of the circle is: ");
    v = C.getArea();
    cout << setprecision(3) << fixed << v;
    outf << setprecision(3) << fixed << v;
    Write("\n");

    Write("The Diameter of the circle is: ");
    v = C.getDiameter();
    cout << setprecision(3) << fixed << v;
    outf << setprecision(3) << fixed << v;
    Write("\n");

    Write("The Circumference of the circle is: ");
    v = C.getCircumference();
    cout << setprecision(3) << fixed << v;
    outf << setprecision(3) << fixed << v;
    Write("\n");

    outf.close();
    return 0;
}
