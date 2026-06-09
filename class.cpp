#include <iostream>
#include <string>

using namespace std;

class stud{
     
    string name;
    int age;
    string address;

    public:
    void setValue()
    {   cout<<"Enter your name: ";
        cin>>name;
        cout<<"Enter your age: ";
        cin>>age; 
        cout<<"Enter your address: ";
        cin>>address;
    }
    void showValue()
    {
        cout << "================== \n";
        cout << "name \n";
        cout<< name<<endl;
        cout << "================== \n";
        cout << "age " <<age;
        cout << "\n================== \n";
        cout<<"\n address "<<address<<endl;
    }
};

int main()
{
    stud s;
    s.setValue();
    s.showValue();

   return 0;

    
}