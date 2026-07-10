#include<iostream>
#include<string> // Good practice to include this explicitly

using namespace std;

class Print
{
    private:
    int a;
    float b;
    string c;
    int type; // Track which type was initialized: 1=int, 2=float, 3=string

    public:
    // Constructors handle the Basic-to-Class type conversion automatically
    Print(int x) : a(x), b(0.0f), c(""), type(1) {}
    Print(float x) : a(0), b(x), c(""), type(2) {}
    Print(string x) : a(0), b(0.0f), c(x), type(3) {}

    void show()
    {
        if (type == 1)
            cout << "Integer value: " << a << endl;
        else if (type == 2)
            cout << "Float value: " << b << endl;
        else if (type == 3)
            cout << "String value: " << c << endl;
        else
            cout << "Nothing to show" << endl;
    }

    ~Print(){}
};

int main()
{
    // 1. Implicit conversion (Basic to Class type)
    Print obj1 = 45;          // Converts int to Print object
    Print obj2 = 12.34f;      // Converts float to Print object
    Print obj3 = string("Hello C++"); // Converts string object to Print object

    // 2. Explicit conversion using constructor casting
    Print obj4 = Print(100);

    // Showing the results
    obj1.show();
    obj2.show();
    obj3.show();
    obj4.show();

    return 0;
}