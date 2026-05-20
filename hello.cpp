#include <iostream>
#include <string>

using namespace std;
struct student{
    string name;
    int age;
    string address;

};
int main()
{
    student s;
    s.name = "ram";
    cout<<"Enter your age";
    cin>>s.age; 
    s.address = "dhapakhel";
    cout << "name "<< s.name << ", \n age " <<s.age<<", \n address "<<s.address<<endl;
    return 0;

    
}