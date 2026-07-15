/* create a template var and a non template var int size function should display intiger or character upto size n */
//generic Programing paradime

#include <iostream>

using namespace std;

template < class T , int X >

void printVar( T var  )
{
    for(int i = 0 ; i < X ; i++ )
        cout << var++ << endl;
    
}

int main()
{
    printVar< char , 5> ('a');
    printVar< float , 5> (2.4);
    printVar< int , 5> (44);
}