#include <iostream>
#include <typeinfo>

using namespace std;



float divide(float x , float y)
{

    // if (typeid(y) == typeid(char))
    // throw ( y );
    if(y==0)
    {
        throw ( y );
    }
    cout << "Result: " << x/y <<endl;

}

int main ()
{

    float x  , y;

    cout<<"enter numbers ";

    try
    {
    cin >> x;
    cin >> y;

    divide(x , y);
        
    }
    catch( float y )
    {
        cout << " Err 102->float  divisor = 0 : Cannot divide by 0" << endl;
    }
    catch( ... )
    {
        cout << " Err 101 : Cannot divide" << endl;
    }

    // catch( char y)
    // {
    //     cout << "Cannot enter character" << endl;
    // }

}