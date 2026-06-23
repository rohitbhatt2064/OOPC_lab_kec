/* create a class name rect that represents cartition coordinate create another class polar that represent 
polar coordinate in term of r and theta 
convert the data type from cation to polar using destinationtype convertion
without using friend function
 */

 #include <iostream>
#include <math.h>

 using namespace std ;

 class Rect
 {
    private:
    float x , y;

    public :
    Rect(){x=y=0;}
    Rect(float x , float y)
    {   this->x = x;
        this->y = y;

    }

    float getX(){ return x;}
    float getY(){ return y;}    //used getter methord to acess the indivisual variable
    void show(){cout<<x<<"x "<<y <<" y"<<endl;}

    operator Polar();

    //Source class convertion
    ~Rect(){}
 };

 class Polar
 {
    private:
    float r , t;
    

    public :
    Polar(){r=t=0; }
    Polar(float r , float t)
    {   this->r = r;
        this->t = t;
    }

    //Convertion constructor methord
     Polar( Rect& R)
    {
        
        this->r =  sqrt(R.getX()*R.getX() + R.getY()*R.getY());
        this->t =  atan2(R.getY(),R.getX());
    }
    void show(){cout<<r<<"r "<<t<<" Theta"<<endl;}
    ~Polar(){}
 };

 int main()
 {
    Rect R(25 , 25);
    Polar P(R);
    P.show();

 }