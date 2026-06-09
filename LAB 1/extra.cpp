#include <iostream>
using namespace std;

class Student
{
private:
    int age;
    int marks;

public:
    void setData(int a, int m)
    {
        age = a;
        marks = m;
    }

    void display()
    {
        cout << "Age = " << age << endl;
        cout << "Marks = " << marks;
    }
};

int main()
{
    Student s;

    s.setData(18, 90);

    s.display();

    return 0;
}
