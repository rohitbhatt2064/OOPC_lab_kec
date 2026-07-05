#include <iostream>
#include <typeinfo>

using namespace std;

class Employee 
{
    string name;

    public:
    Employee():name(""){}
    Employee(string name):name(name){}
    virtual ~Employee(){}

    virtual void show() = 0 ; //pure virtual function ,  pure polymorfic class 
    //  ( empty can also be kept but this look more beutifull)
    // not the class is abstract clASS i.e cant create any object from the class
};

class Developer: public Employee
{
private:
    int id;
public:
    Developer( ):id(0){}
    Developer(int id , string name):id(id), Employee(name){}
    ~Developer(){}

    void show() { cout<<id<<endl; }
};

class Manager: public Employee
{
private:
    int id;
public:
    Manager( ):id(0){}
    Manager(int id , string name):id(id), Employee(name){}
    ~Manager(){}

    void show() { cout<<id<<endl; }
};

int main()
{
   /*  Employee *e1 = new Employee ("Ram");
    e1->show();
    delete e1; */
    //cant do it because the class is abstract class
    Employee *e1;
    e1 = new Manager (  39 , "Shyam" );
    e1->show();
    delete e1;


    e1 = new Developer (  39 , "Ravindra" );
    e1->show();
    delete e1;

    e1 = nullptr;

    Employee *E1 = new Manager( 1 , "Ramdhwaj ");
    Employee *E2 = new Developer(100 , "Hari");

    Manager *m = dynamic_cast<Manager*>(E1);
    if(m != nullptr)
    {
        cout<<"Casting Sucessfull"<<endl;
    }
    else
    {
        cout<<"casting unsucessfull"<<endl;
    }
    Developer *D = dynamic_cast<Developer*>(E1);
    if(D!= nullptr)
        {
        cout<<"Casting Sucessfull"<<endl;
    }
    else
    {
        cout<<"casting unsucessfull"<<endl;
    }



    //typeif extract info about a pointer in runtime
    //must include typeinfo in headder
    cout<<typeid(E1).name()<<endl;
    cout<<typeid(D).name();

    return 0;
}