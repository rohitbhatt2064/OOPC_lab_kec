/* 
Create a class name employe that represent employ name id age age and salay and bank name
Derive two class
1. account derived of class employ that has slalay acc no and should have a function to simulate sending of salary
 which should display  date of salary send amount and on the account number what
 2. another clss computer that is derived from employee that should have subject they are teaching and should have function anem role 
    that display employe name subject they  are teaching
*/

#include<iostream>

using namespace std;

class Employe
{
    protected:
    string name;
    int id , age , salary ;
    string bankName;

    Employe():id(0),name(""),age(0),salary(0){}
    Employe(int id , string name , int age , int salary , string bankName)
     : id(id) , name(name) , age(age) , salary(salary) , bankName(bankName){}
    ~Employe(){}
};

class Account :  Employe
{
    protected:
    double accountNumber;

    Account(int account ):Employe(id , name , age , salary ,bankName) {}


    ~Account(){}
};



