//      create a class name box that represents its length  and volume 
//    ( it should have consctructor both default and parametrized to initilize obj and
//    it ahould have a static number that keeps track of no of obj created)

#include <iostream>

using namespace std;

class box
{
    private:
    float length , volume ;
    static int count ; //declare staticvar inside class cannot initialize it 
    
    public:
    
    box(float length )
    {
        this ->length = length;
        this -> volume = length * length * length ;
        count++;
    }
    box()
    {
        this->length = 0;
        this->volume = 0;
        count++;
    }
    void show()
    {
        cout<<"length:"<<length<<"   "<<"volume: "<<volume<<endl
                <<"no of obj "<<count<<endl;
    }
    static void showCounter(){cout<<"numberof object"<<count<<endl;}

    ~box(){cout<<"object destroyed"<<endl;}
};

int box :: count = 0 ; //initialize var out of class

int main()
{   
    box b1(10), b2, b3(29);
    b1.show();
    b2.show();
    b3.show();
    box showCounter();
    return 0;
}