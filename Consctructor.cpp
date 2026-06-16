//How do constructor work
#include <iostream>
#include <string>

using namespace std;

class student{
     
    string name;
    int age;


    public:
    student(string name , int age) //Parimatrized constructor
    { this->age = age;
        this->name = name;
        cout<<"name "<<name<<endl;
    }
    student() // Default Constructor
    {
        this->age = 0;
        this->name = "";
        cout<<"name "<<name<<endl;
    }
   
     ~student() //desctructor starts with   , has no return type, same as class name , no arguement as well automatically
                //clear the memory
     {
        cout<<"destructor called"<<endl;
     }  
    
};

int main()
{
    student s = student("Rohit",1);
{
    student s4;
    cout<<"test"<<endl;
}

   return 0;

    
}