//program to take year and convert it  into its components

#include <iostream>

using namespace std;

class Year
{
    private:
    int year , month  ;
    
    public:
        Year():year(0),month(0){};
        Year(int y , int m):year(y),month(m){};
    Year(float y)
    {
        year = y ;
        y -= year ;
        month = y * 12;        
    }
    void show()
    {
        cout<<"Year: "<< year<<"  Months: "<<month<<endl;
    }
    ~Year(){}

};

int main()
{
    Year Y = 1.5;
    Y.show();
    return 0;
}