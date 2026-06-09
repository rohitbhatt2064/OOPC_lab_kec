// Analying the error will occur ( default access specifier is private)
#include <iostream>
using namespace std;

class Demo
{
    int x;
};

int main()
{
    Demo d;
    d.x = 10;

    return 0;
}