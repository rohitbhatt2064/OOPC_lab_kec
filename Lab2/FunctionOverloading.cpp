// About Working of FunctionOverloading
#include<iostream>

using namespace std;

// Overload 1: Definition with signature sequence (int, float)
void Area(int a, float b  )
{
  cout<<"Area of Rectriangle = " << a + b <<endl;
}

// Overload 2: Uncommented to implement and demonstrate Function Overloading
void Area(float a, int b  )
{
  cout<<"Area of Rectriangle surface = " << a + b <<endl;
}

int main()
{   
    // In C++, literal decimals like 2.2 and 3.3 are deduced as 'double' by default.
    // To match the specific float overloads exactly and prevent type ambiguity, 
    // the 'f' suffix is explicitly appended (2.2f, 3.3f).
    
    // Call 1: Passes (float, int), which matches Overload 2 perfectly
    Area(2.2f, 3);
    
    // Call 2: Passes (int, float), which matches Overload 1 perfectly
    Area(2, 3.3f);
    
    return 0 ;
}