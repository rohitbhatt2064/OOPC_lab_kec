/* create a class name time that represent time in sec min and hour overload 
post fix uniary operator to increment the object  
*/

#include <iostream>

using namespace std;

class Time
{
    private:
    int sec , min , hour ;

    public:
    Time()
    {
        this->sec = 0;
        this->min = 0;
        this->hour = 0;

    }

    Time( int hour , int min , int sec)
    {
        this->sec = sec;
        this->min = min;
        this->hour = hour; 

        convertionLogic();
    }

    //use of inline
    inline void convertionLogic()
    {
        //conversion logic dosnt use 
        while( this->sec >= 60)
        {
            this->sec = this ->sec - 60;
            this->min = this ->min + 1;

        }
        while (this->min >= 60)
        {
            this->min = this ->min - 60;
            this->hour = this ->hour + 1;
        }
    }
    void show()
    {
        cout<<"hour  "<<this->hour<<"  minute "<<this->min<<"  second "<<this->sec<<endl;
    }



    //postfix operator overloading
    //operator is a key word
    //use ++(int) for postfix and just ++ without anything to prefix
    void operator ++(int) 
    {
        this->sec++;
        this->min++;
        this->hour++;

        convertionLogic();
        
    }

    Time operator++() ;


    ~Time(){}

};

//prefix operator overloading
inline Time Time::operator++()
    {
        ++sec;
        ++min;
        ++hour;

        convertionLogic();
        
        return *this;

    }

int main ()
{
    Time T1(5,6,2);
    T1.show();

    Time T2(6,100,120);
    T2.show();
    T2++;
    T2.show();

    Time T3(6,100,120);
    T3.show();
    ++T3;
    T3.show();

}