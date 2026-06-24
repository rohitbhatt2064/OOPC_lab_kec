/* consider two classes one representing 1st name and anoatheer representing Last name 
how to use bridge functuon(friend)function to dynamically concatenates the string of two classes 
*/


#include <iostream>
#include<string.h>

class First
{
    private:
    char* first;

    public:
    First()
    {
        first = nullptr;
    }
    First(const char* f)
    {
        int len = strlen(f);
        first = new char[ len +1];

    }

    ~First(){}
};

class Last
{
    private:
    char* last;

    public:
    Last()
    {
        last = nullptr;
    }
    Last(const char* l)
    {
        int len = strlen(l);
        last = new char[ len +1];

    }
    friend  char* fullName();
    
};

char* fullName( First& f , Last& l)
{
    
}