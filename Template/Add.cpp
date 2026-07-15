#include <iostream>

using namespace std;

template < class T1 = int , class T2 = float > // T1 is generic or template datatype after = that is default datatype
T2 add(T1 n1 = 0 , T2 n2 = 0) //num1 and num2 is generic data variables   after - that one is default arguement
{
   return n1+n2 ;

}


int main()
{
    //Remember the return type will be of T2
    cout << "Sum = " << add( 7 , 8 ) << endl; 
    cout << "Sum = " << add( 3.2 , 8 ) << endl; 
    cout << "Sum = " << add( 7 , 8.8 ) << endl; 
    cout << "Sum = " << add( 7 , 'a' ) << endl; //Remember the return type will be of T2
    cout << "Sum = " << add( 'a' , 7 ) << endl;  //Remember the return type will be of T2

   return 0;
}