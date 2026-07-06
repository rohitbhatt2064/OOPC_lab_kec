/* 
define a class publication which has title 
derive two classes from it a class book which has accestion number 
and a class which has volume number with thease two as base derive a class 
journal
define a functiion print in each of thease classes ensure that the derived class function always 
invoke the base class function 
in main create a journal IEEE-OOP with accession no 6081.3 and a volume no 1
invoke the print function for this object
*/

#include<iostream>

using namespace std;

class Publication
{
    protected:
    string title;
    
   Publication():title(""){}
   Publication(string title):title(title){}
    virtual ~Publication(){}

    virtual void display()
    {
        cout << "Title: " << title << endl;
    }

};

class Book : public Publication
{
    protected:
    double accesionNo;

    Book():accesionNo(0){}
    Book(double accesionNo , string title):accesionNo(accesionNo) ,Publication(title){}
    ~Book(){}

    void display()
    {
        cout << "accesionNo: " << accesionNo << endl;
    }

};


class Volume : public Publication
{
    protected:
    int volumeNo;

    Volume():volumeNo(0){}
    Volume(int volumeNo):volumeNo(volumeNo){}
    ~Volume(){}

    void display()
    {
        cout << "Volume No: " << volumeNo << endl;
    }
};

class Journal : public Book , public Volume
{
    public:
    Journal(){}
    Journal(string title , double accesionNo , int volumeNo ) 
        : Book(accesionNo , title), Volume(volumeNo) {}
    void display()
    {
        Publication::display();
        Book::display();
        Volume::display();
    }    
};

int main()
{
    Journal J("IEEEOOP" , 6081.3, 1);
    J.display();

}