/* 
Create 2 class of one representing american doller and another representing nepali 
rupee convert dnepali rupee into doller using source and destination class conversion
 */

 /* Write a simple program to convert userdefined data type us doller into
 basic data type float nepali ruppes and vise versa
  */


  /* class to other datatype ma convert garna operator
  other data to class ko data then use constructor
  */

#include <iostream>

using namespace std ;

class NPR;
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
   

    operator NPR();

    float getDoller()
    {
        return dollar;
    }
    
    void show()
    {
        cout<<"Usd: "<<dollar<<endl;

    }






    friend NPR;
    
    ~UsDoller(){}
};

class NPR
{
    private:
    float rupee;
    
    public:
    NPR(){rupee =0 ;}
    NPR(int n )
    {
        rupee = n;

    }
    
    NPR(UsDoller& );
    float getRupee()
    {
        return rupee;
    }
    
    friend UsDoller;
    operator UsDoller();

    ~NPR(){}
};
NPR::operator UsDoller()
{
    return rupee / 150.0;
}

UsDoller::operator NPR()
{
    return dollar * 150.0;
}


NPR::NPR(UsDoller& d)
{
    rupee = static_cast<float>(d.dollar);
}
int main()
{
     NPR N1(1300);
     UsDoller U1 = N1;
     U1.show();

    return 0;

}


