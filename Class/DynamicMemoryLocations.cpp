#include<iostream>
#include<string>
#include<memory>

using namespace std;
class Student
{
    private:
    string name;
    int roll;

    public:
    Student()
    {
        this->roll = 0 ;
        this->name = "Not Named";

    }
    Student(int roll ,string name)
    {
         this->roll = roll ;
        this->name = name;
    }
    // Student (Student&);//Copy constructor
    void setData()
    {
        cin>>roll>>name;
        this->roll = roll ;
        this->name = name;
    }

    void showData()
    {
        cout<<"Name  "<<name<<"rol  "<< roll <<endl;

    }

    ~Student()
    {
        cout<<"Calling Deconstructer ...";
    }
    
};

//Copy constructor
// // Student::Student(Student &x);
// {
//     this->roll = x.roll ;
//     this->name = x.name;
// }

int main()
{
    Student *p = new Student[5];
    p->showData();
    

    p = new Student(141,"nak");
    
    p->showData();
    delete p;
    p = nullptr;
    // p = Null;

    unique_ptr<int> a = make_unique<int>(2);
    unique_ptr<Student> a = make_unique<Student>(12,"ram");


    Student *s = new Student[2]; 

    for(int i=0; i<0; i++)
    {
        (s+i)->setData();
    }

    for(int i=0; i<0; i++)
    {
        (s+i)->showData();
    }

    //Another methord
   /*   for(int i=0; i<0; i++)
    {
        s[i].setData();
    }

    for(int i=0; i<0; i++)
    {
        s[i].showData();
    } */

    //Additional methord a feature

       /*   for(int i=0; i<0; i++)
    {
        i[s].setData();
    }

    for(int i=0; i<0; i++)
    {
        i[s].showData();
    } */



    delete[] s; // While Array deletion big braces on delete
    s = nullptr;

//Copy constructor
    Student *p = new Student ;
    Student *p = new Student ;
    // Student p(p1);
   

    return 0;
}