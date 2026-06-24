//Basic to class type conversion

#include<iostream>

using namespace std;

class Print
{
    private:
    int a;
    float b;
    string c;

    public:
    Print(int a):a(a){b=0; c = nullptr; }
    Print(float b):b(b){a=0; c = nullptr; }
    Print(string c):c(c){a=b=0;}

    void show()
    {
        if(a != NULL )
            cout<<a<<endl;
        
        else if(b != NULL)
            cout<<b<<endl;
        else if(c != "")
            cout<<c<<endl;
        else
            cout<<"Nothing to show"<<endl;
    }

    ~Print(){}
  };

int main()
{

}