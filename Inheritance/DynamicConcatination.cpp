/* 
 two class first and last use dynamic constructor to dynamically concatinate using dynamic constructor
 */

 #include<iostream>

 using namespace std;
class First;
class Last;

 class First
 {
    char *first;
    
    public:
    First() 
    {
    first = new char[1];
    strcpy(first , "");
    }

    First(const char *firstName) 
    {
        int length = strlen(firstName);
        first = new char[length + 1];
        strcpy(first , firstName);
              
    }
    friend void operator + ( const First & , const Last & );
 };

  class Last
 {
    char *last;
    
    public:
    Last()
    {
    last = new char[1];
    strcpy(last , "");
    }
    
    Last(const char *lastName)
    {
        int length = strlen(lastName);
        last = new char[length + 1];
        strcpy(last , lastName);
              
    }
    friend void operator + ( const First & , const Last &);
    
 };

 void operator + ( const First &F,const Last &L)
 {
     int length = strlen(F.first) + strlen(L.last);
     char *name = new char[length + 2];
    strcpy(name , F.first);
    strcat(name , " ");
    strcat(name , L.last);

    cout<<name<<endl;

 }

 int main()
 {
    First F = ("Ram");
    Last L = ("Shriswastav");

    F+L;

    return 0;
 }
