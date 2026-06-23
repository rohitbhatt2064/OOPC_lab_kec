/* private data members don't get inherited
Note: Cant access the private of base class  in derived class  but 
All data member go to the memory location  of the derived class not only private and public
that's why the size will be combined of those 
but the compiler keep it as restricted 
 */

#include<iostream>
using namespace std;

class animal
{
    protected:void sound()
    {
        cout<<"animal sound" <<endl;
    }
};

class dog:private animal
{
    public:
     void sound()
    {
        animal::sound(); //sound is protected so can be acessed only in the derived class of animal
        cout << " Dog Bark" << endl;
    } 
   //If  there is the function in the class we call it
   // get executed else it search in base class then in header file (specific namespace we mentiond)
   
   //member function overloadinng 
    /* if we have a base class and derived class
    there we have member function of same name then prirority to the derived class if none of the name then only to the base class
      */
};

int main()
{
    dog d;
    /* animal::sound(); // this call function from the animal class which is protected cant acess
    It can not be accessed from outside the class as it is protected
    Protected allow us to use it on inherited class only
     */

    d.sound();//this is public
}