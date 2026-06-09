// InlineFunctions
#include<iostream>
#include <iomanip>

using namespace std;

// Inline function definition
// Requesting the compiler to replace the function call directly with its body code
inline int compare(int a, int b  )
{
  return (a>b)?a:b;
}

int main()
{   
    // Utilizing stream manipulators:
    // \t inserts a tab space
    // setw(40) sets the character field width for the next item to 40
    // setfill('-') fills the empty padding space with hyphens
    // compare(14,8) evaluates inline and passes the result (14) to the stream
    cout <<"the greater is\t"<<setw(40)<<setfill('-')<<compare(14,8)<<endl;
    
    return 0 ;
}