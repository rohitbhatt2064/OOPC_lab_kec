// About Working of Default Argument
#include<iostream>

using namespace std;

// Function Prototype declaring default arguments from right to left.
// This allows the original function body below to remain unchanged.
void sum(int a, int b = 0, int c = 0);

int main()
{   
    // Calling with all 3 arguments provided explicitly
    sum(1, 2, 3);
    
    // Calling with 2 arguments; 'c' automatically defaults to 0
    sum(10, 20);
    
    // Calling with 1 argument; 'b' and 'c' both default to 0
    sum(5);

    int a;
    return 0;
}

// Your exact function body remains intact and clean
void sum(int a, int b, int c)
{
    cout << "sum = " << a + b + c << endl;
}