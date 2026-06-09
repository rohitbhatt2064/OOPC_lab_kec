#include <iostream>
using namespace std;

struct Student
{
    int roll;
};

int main()
{
    Student s;

    s.roll = 5;

    cout << "Roll Number = " << s.roll;

    return 0;
}
