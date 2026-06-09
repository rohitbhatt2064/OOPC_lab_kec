#include <iostream>
using namespace std;

class Student
{
private:
    int roll;

public:
    void setRoll(int r)
    {
        roll = r;
    }

    int getRoll()
    {
        return roll;
    }
};

int main()
{
    Student s;

    s.setRoll(20);

    cout << "Roll Number = " << s.getRoll();

    return 0;
}
