/* 
Create a fn name divide thate take input and prints the result
write a proper exception handeling cpde for
- divide by 0 
- if wrong input type is entered
 */

#include<iostream>
#include<typeinfo>

using namespace std;

float divide(float a , float b)
{
    if ( b == 0 )
    throw (b);

    cout<< "Divide Result = " << a/b << endl; 

    return  a/b ;
}

int main()
{
    float a , b ;

    

    try //performing exception handelingw
    {

       // 1. Check Variable A
        cout << "Enter first number (a): ";
        cin >> a;
        if (cin.fail())
        {
            cin.clear();
            string junk;
            cin >> junk; // Clear out the bad text
            throw string(" Divident "); // Throwing a string object
        }

        // 2. Check Variable B
        cout << "Enter second number (b): ";
        cin >> b;
        if (cin.fail())
        {
            cin.clear();
            string junk;
            cin >> junk; // Clear out the bad text (i.e clear input buffer)
            throw string(" Divisor "); // Throwing a string object
        }
        divide( a , b);
    }
    catch(float f)
    {
        cout << " Error 1 :Trying to divide with 0, \n cannot divide a number by zero" << endl;
    }
    catch(string fail_text)
    {
        cout << "Error 2 : Wrong input type trying to assigne in a float variable , error at " << fail_text << endl;
    }

    catch(...)
    {
        cout << "Unexpected error occured " << endl;
    }
}