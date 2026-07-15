#include <iostream>

using namespace std;

template < class T1 = int , class T2 = float > // T1 is generic or template datatype after = that is default datatype
void swap(T1 n1 = 0 , T2 n2 = 0) //num1 and num2 is generic data variables   after - that one is default arguement
{
   T1 temp = n1;
    n1 = n2; // Implicit conversion/type-casting happens here
    n2 = temp;

    cout << "n1 =" << n1 << "\t n2 = " << n2 << endl;    

}


int main()
{
   
    swap(68 , 4.7);  // implicit casting on swaping
    swap(3, 45);
    swap(32.1 , 26.7);
    swap(98 , 'a');   // after swaping a ascii value  and 98 acci convertion is happening
}