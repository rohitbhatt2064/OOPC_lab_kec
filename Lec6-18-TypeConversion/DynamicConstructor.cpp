// Dynamic Constructor 
//create a class name that will store username and its uuid
// use dynamic cionstructor to intililige the object


/* 
Consider two classess  ine representing fist name another representing last name use a bridge function 
that dynamically concatinates and make full name
*/
#include<iostream>

using namespace std ;
 

class User
{   private:
    char *name;
    int uuid;
    static int UserNo ;
    public:
    User(){name = nullptr; }
    User(char*s)
    {
        int length = strlen(s);
        name = new char[length+1];
        strcpy(name,s);
    }
    void AssignUid()
    {
        
    }
    ~User()
    {
        delete name;
        name = NULL;
    }
};

