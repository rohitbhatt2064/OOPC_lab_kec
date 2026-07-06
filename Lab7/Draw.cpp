/* 
Create a class name shape and create a function which displays simplly
 draw from that class derive 4 class name circle rectriange triangle
  swuare each should have function show which should display circle drawn
  rect drwn ad so on
  now implement the concept of virtual functions to call the 
  function of derived class using base class pointer
  and implement the concept of virtual destructor
*/

#include <iostream>

using namespace std;

class Draw
{
    public:
    virtual void show()
    {
        cout<<"Draw :"<< endl;
    }

    virtual ~Draw(){ cout <<"Calling destructor of Draw"<<endl<<endl;}
};

class Circle : public Draw
{
    public:
    void show()
    {
        cout<<"Circle"<< endl;
    }

     ~Circle(){ cout <<"Calling destructor of Circle"<<endl<<endl;}
};

class Rectriange : public Draw
{
    public:
     void show()
    {
        cout<<"Rectriangle"<< endl;
    }

     ~Rectriange(){ cout <<"Calling destructor of Rectriangle"<<endl<<endl;}
};

class Triangle : public Draw
{
    public:
     void show()
    {
        cout<<"Triangle"<< endl;
    }

     ~Triangle(){ cout <<"Calling destructor of Triangle"<<endl<<endl;}
};

class Square : public Draw
{
    public:
     void show()
    {
        cout<<"Square"<< endl;
    }

     ~Square(){ cout <<"Calling destructor of Square"<<endl<<endl;}
};

int main()
{
/*     Draw *D = new Draw ;
    D->show();
    delete D;

    D = new Circle;
    D->show();
    delete D;

    D = new Rectriange;
    D->show();
    delete D;

    D = new Triangle;
    D->show();
    delete D;
    
    D = new Square;
    D->show();
    delete D;
    D = nullptr; */

    Draw *D[3];

    

    for(int i = 0 ; i < 3 ; i++)
    {
      switch(i)
      {
        case 0:
        D[0] = new Circle();
        D[0]->show();
      

        case 1:
        D[1] =  new Rectriange();
        D[1]->show();

        case 2:
        D[2] = new Triangle();
        D[2]->show();

      }  

      delete [] *D;
      *D = nullptr;

    return 0;

    }



    return 0;
}