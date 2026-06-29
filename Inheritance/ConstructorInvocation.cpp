/* 
create a class name personal info that stores name and age of a person and
create another class name id that stores nid and citizenship idof a person
(double int  ) now derive a class location deerived from classes defined abv
1. only define datamember in member function private if required
2. All the base class and derived class should have display function
and you are only allowed to use the display of derived class to display the 
function of base class
3. also create all the required member function like geter methord seter methor
and constructior and destructor and show that base class constructor are always
called before derived class and vice versa in case of destructor 
*/


#include<iostream>

using namespace std;

class Personal
{
    protected:
    string name;
    int age;

    Personal(string name , int age):name(name),age(age){};
    Personal():name(""),age(age){};
    ~Personal(){ cout<< "calling destructor of Personal"<<endl;}

    void show(){ cout<<endl<<"Name: "<<name<<"   Age: "<< age<<endl; }
    void set()
    {
        cout<<"Enter name and age";
        cin>>name>>age;
        cout<<endl;
    }
};

class Id
{
    protected:
    long int cid , nid;

    Id(long int cid , long int nid):cid(cid),nid(nid){}
    Id():cid(0),nid(0){}
    ~Id(){cout<<"calling destructor of Id"<<endl;}

    void show(){ cout<<endl<<"CID: "<< cid <<"   NID: "<< nid <<endl; }
    void set()
    {
        cout<<"Enter cid and nid";
        cin>>cid>>nid;
        cout<<endl;
    }
};

class Location: private Id , private Personal 
{
    private:
    double latitute , longitute ;

    public:
    Location( string name , int age , long int cid , long int nid , double latitute , double longitute)
        : Personal(name , age ) , Id(cid , nid) , latitute( latitute ) , longitute( longitute ) {}
    Location():Personal() , Id(),latitute(0.0),longitute(0.0){}
    ~Location(){cout<<"calling destructor of Location"<<endl;}

    void show()
    {
        Personal::show();
        Id::show();
        cout<<endl<<"latitute: "<< latitute <<"   NID: "<< longitute <<endl;
    }

        void set()
    {
        Personal::set();
        Id::set();

        cout<<"Enter latitute and longitute";
        cin>>latitute>>longitute;
        cout<<endl;
    }

};

int main()
{
    Location x ("Rohit" , 18 , 2089372 , 23213432 , 65.34567 ,33.223232);
    x.show();
    cout<<"============================================="<<endl;

    Location j;
    x.set();
    x.show();

    return 0 ;
}