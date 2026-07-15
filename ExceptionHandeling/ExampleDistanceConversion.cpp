 /* 
 Create a class name diistance that rempresent distance in feet and inch
 this class should be completely free from error and should be able to handel exception saying that
 - val of inch cant be greater than 11
 error
 - val of int cant be > 11
 - val you entered is x
 - take input
 
 and display the value provided by user
 */


 #include<iostream>

using namespace std;

class Distance
{
  int feet , inch ;
  
  public:
  Distance( int feet , int inch):feet(feet),inch(inch)
  {
    try
    {
        if (inch > 11)  throw Error("inch greater then 11", inch);
    }
    catch( Error )
    {

    }
    
    
  }
/* void InchNormalige(int feet , int inch)
    {
        if(inch > 12)
        {
            feet++;
            inch -= 12;

            setDistance(feet, inch);

        }
    } */
  void setDistance( int f , int i )
  {
    feet = f;
    inch = i;
  }



  class Error
  { 
    string errMsg;
    int errVal;
    
    public:
    Error(string errMsg, int errVal):errMsg(errMsg),errVal(errVal)
    {
        cout<<"Error: The value of inch cant be greater then 11"<<endl
            <<"The value you entered is " << errVal << endl;
    }

   
  };


};