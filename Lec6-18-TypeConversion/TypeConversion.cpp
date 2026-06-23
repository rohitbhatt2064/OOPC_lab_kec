/* Write a simple program to convert userdefined data type us doller into
 basic data type float nepali ruppes and vise versa
  */

#include <iostream>

using namespace std ;

class UsDoller
{
    private:
    float dollar;
    
    public:
    UsDoller(){dollar =0 ;}
    UsDoller(int usd )
    {
        dollar = usd;

    }
    UsDoller(float npr) //convertion constructor is made to convert
    {
        //dollar = npr *155.5; 
        ////dollar = (float) npr *155; // Cpp style old casting
        // dollar = float (npr * 155.5);
        dollar = static_cast<float> (npr * 155.5) ; //c++ type casting
    }

    operator float()
    {
        return (this->dollar*155.5);
    }
    
     UsDoller operator = (float npr )//
     {
        this->dollar = npr / 155.5;
     }
   
    
    ~UsDoller(){}
};



int main()
{
    UsDoller D1(100);

    float n = D1;

    



}


