/* 
Create a class name cricketer with member var  name age and no of matches played
from this derive two classes bowler and batsman
bowler has no of wickets as member var 
and batter have no of run and centuries as member variables 
use appropriate member function in respective classes to read and display the data
 */

 
 #include<iostream>

 using namespace std;

 class Cricketer
 {
    protected:
    string name;
    int age , machesPlayed;
    
    Cricketer():name(" null "),age(0),machesPlayed(0){}
    Cricketer(string name , int age , int machesPlayed):name(name),age(age),machesPlayed(machesPlayed){} 
    virtual ~ Cricketer(){}

   public: virtual void show () = 0 ;//makeing pure virtual function now the pure virtual function make the class will be abstract
   virtual void getData() = 0;
 
 };

 
  class Batter : public Cricketer
 {
    int run , centuries ;

    public:
    Batter():run(0),centuries(0){}  // here keeping default constructor is note necessary
    Batter(string name , int age , int machesPlayed , int run , int centuries):Cricketer( name , age , machesPlayed), run(run) , centuries(centuries){}
    ~Batter(){}

    void show  ()
    {
        cout<<name<<"\t"<<age<<"\t"<<machesPlayed<<"\t"<<run<<"\t"<<centuries<<endl;
    }
    void getData()
    {
        cout<<"Enter Name: ";
        cin>>name;
        cout<<endl;

        cout<<"Enter Age: ";
        cin>>age;
        cout<<endl;

        cout<<"Enter Maches Played: ";
        cin>>machesPlayed;
        cout<<endl;

        cout<<"Enter Centuries: ";
        cin>>centuries;
        cout<<endl;

    }

 };

 class Bowler : public Cricketer
 {
    int wickets ;

    public:
    Bowler():wickets(0){}  // here keeping default constructor is note necessary
    Bowler(string name , int age , int machesPlayed , int wickets):Cricketer( name , age , machesPlayed),wickets(wickets){}
    ~Bowler(){}

    void show  ()
    {
        cout<<"\t"<<name<<"\t"<<age<<"\t"<<machesPlayed<<"\t"<<wickets<<endl;
    }

    void getData()
    {
        cout<<"Enter Name: ";
        cin>>name;
        cout<<endl;

        cout<<"Enter Age: ";
        cin>>age;
        cout<<endl;

        cout<<"Enter Wickts: ";
        cin>>wickets;
        cout<<endl;


    }


 };

int main()
{
//    Cricketer c;  not allowed because abstract class
    Cricketer *c = new Batter("Bhim sarki" ,1 , 12 , 1000 , 9);
    c->show();


}