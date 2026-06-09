#include <iostream>
#include <string>

using namespace std;
struct student{
    string name;
    int age;
    string address;
};

void setvalue(student &s)
{
    
    s.name = "ram";
    cout<<"Enter your age";
    cin>>s.age; 
    s.address = "dhapakhel";
    cout << "name "<< s.name << ", \n age " <<s.age<<", \n address "<<s.address<<endl;
}
int main()
{student s;
    setvalue(s);

   

    
}