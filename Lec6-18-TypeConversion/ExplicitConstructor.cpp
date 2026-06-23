
#include<iostream>
using namespace std;
class Distance 
{
    private:
    int meters;

    public:
    explicit Distance(int m )
    {
        meters = m;
    }

    friend void printDistance(Distance);
};

void printDistance(Distance d)
{
    cout<<"Distance: " << d.meters << "meters " <<endl;

}

int main()
{
    //this works because of IMPLICIT CONVERSION
    // The compiler sees an int (q0) but the funcction wants a 'Distance'.
    //It secretely calls Distance(10)
   
   
    Distance d(10);
    printDistance(d);
    return 0;
}