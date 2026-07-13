#include <iostream>

using namespace std;

class Time
{
    private:
    int sec;

    public:
    Time():sec(0){};
    
    // Note: Kept your original logic here, but remember if you want to use this 
    // to convert basic-to-class, you'd change it to :sec(s)
    Time(int s):sec(0){}; 
    
    Time(int h , int m , int s)
    {
        sec = h * 3600 + m * 60 + s;
    }

    // --- CLASS TO BASIC CONVERSION OPERATOR ---
    // This allows a Time object to be implicitly or explicitly treated as an int
    operator int() 
    {
        return sec; 
    }
};

int main()
{
    // Create a Time object (2 hours, 30 minutes, 15 seconds)
    Time t1(2, 30, 15); 
    
    // Convert Class type (Time) to Basic type (int)
    int totalSeconds = t1; // Invokes the operator int() conversion function
    
    cout << "The basic int value (total seconds) is: " << totalSeconds << endl;

    return 0;
}