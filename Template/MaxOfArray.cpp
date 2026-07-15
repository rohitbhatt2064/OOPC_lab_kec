/* 
Create a class template that compares and find the max val of array 
*/

#include <iostream>
#include <climits>

using namespace std;

template < class T , int size = 15 >

class Max
{
    T arr[size] ;
    T maxValue = INT_MIN;

    public:
    Max()
    {
        cout<<"Enter Val: ";
        
        for(int i = 0 ; i< size ; i++) 
        {
            cin >> arr[i] ;
            cout<< "\t" ;
        }
    }

    T get_maxValue()
    {
        for  (int i = 0 ; i < size ; i++)
        {
            if(arr[i]>maxValue)
                maxValue = arr[i];
    
        }
        return maxValue;
    }

};

int main()
{
    Max <int , 5> m;
    cout << m.get_maxValue() <<endl;


}