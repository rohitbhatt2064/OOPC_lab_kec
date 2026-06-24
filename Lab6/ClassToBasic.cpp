#include<iostream>

using namespace std;

class Time
{
    private:
    int sec;

    public:
    Time():sec(0){};
    Time(int s):sec(0){};
    Time(int h , int m , int s)
    {
        sec = h * 3600 + m * 60 + s;
    }
};