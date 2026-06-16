//Wap to create a class called Time having data member having data members day hr min and see
//Wap to add two numbers /objects of class time also make the use of constructor to initilize the data members

#include<iostream>

using namespace std;
class Time
{
    private:
    int hour , min , sec ;

    public:
    Time(int hour, int min, int sec)
    {
        this->hour = hour ;
        this->min = min ;
        this->sec = sec ;

    }
    Time()
    {
         this->hour = 0 ;
        this->min = 0 ;
        this->sec = 0 ;

        
    }
    void setValue(int h, int m, int s)
    {
        Time(h,m,s);
    }
    
    Time add(Time);

    void showData( Time )
    {
        cout<<"hour  "<<this->hour<<"Minute  "<<this->min<<"second  "<<this->sec;
    }

    

    ~Time()
    {
        cout<<"Destructor Loading..."<<endl;
    }
    
};


Time Time::add(Time T)
{
    Time Temp;
    Temp.sec = T.sec + this->sec;
    Temp.min = T.min + this->min;
    Temp.hour = T.hour + this->hour;
    
    return Temp;
}
    

int main()
{
    int h , m , s ;
    cout<<"enter the time ";
    cin>>h>>m>>s;
    Time T1(h,m,s);
    Time T2(3,25,6);
    Time T3;
    T3 = T2.add(T1);
    T3.showData( T3 );
    
    
    return 0;
}