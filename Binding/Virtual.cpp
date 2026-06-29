/* 
Create a class name shape and create a function which displays simplly
 draw from that class derive 4 class name circle rectriange triangle
  swuare each should have function show which should display circle drawn
  rect drwn ad so on
  now implement the concept of virtual functions to call the 
  function of derived class using base class pointer
  and implement the concept of virtual destructor
*/

#include<iostream>

using namespace std;
class Animal
{
    public:
    virtual void show()
    {
        cout<<"animal sound: " << endl;
    }
    
    //using destructor normally will now call destructor of other 
    /* ~Animal()
    {
        cout<<"Base class(Animal) destructor"<<endl;
    } */
    //virtual destructor
    /* 
    calling destructor of all using virtual can be done but its slow compared to the speed of the cpp
    */
   /* When a class has a virtual destructor, the compiler creates a vtable (virtual table) containing
    pointers to virtual functions, including the destructor.  Each object holds a hidden vptr 
    (virtual pointer) that points to its class's vtable.
     */
   virtual ~Animal()
    {
        cout<<"Base class(Animal) destructor"<<endl;
    }
};

class Dog : public Animal
{
 public: 
    void show()
    {
        cout<<"bark" <<endl;
    }
    ~Dog()
    {
        cout<<"Dog destructor"<<endl;
    }   
};

class Cow : public Animal
{
    public: 
    void show()
    {
        cout<<"MOOOOOOOOOOOh" <<endl;
    }   

    ~Cow()
    {
        cout<<"Cow destructor"<<endl;
    }
};

int main()
{
    Animal *a = new Animal;
    a->show();

    delete a;
    
    a= new Dog;
    a->show();

    delete a;

    a= new Cow;
    a->show();

    delete a;
    a = nullptr;

    return 0;
}
