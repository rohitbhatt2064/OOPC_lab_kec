/* /* Ecplain the case of ambiguity in multiple inheritance and how to you resolve it using scope operator
( this is called function overriding) 

How does Inheritance support code reusibility?

Function Overriding / Ambiguity
 */

#include <iostream>

using namespace std;

class A
{
private:
    int t;
public:
   
    A(int n):t(n){}
    A():t(0){}

    void input()
    {
        cout<<endl<<"enter";
        cin>>t;

    }
    ~A(){}
};

class B
{
private:
    int t;
public:
   
    B(int n):t(n){}
    B():t(0){}

    void input()
    {
        cout<<endl<<"enter";
        cin>>t;

    }
    ~B(){}
};

class C : public A , public B
{
private:
    int t;
public:
   
    C(int n):t(n){}
    C():t(0){}

    void input()
    {
        cout<<endl<<"enter";
        cin>>t;

    }

    ~C(){}
};

int main()
{
    A a;
    A::a.input();

    B a;
    B::a.input();
    C a;
    a.input();
} */