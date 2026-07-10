/* 
Explain the case of ambiguity in multiple inheritance and how you resolve it using scope operator.
How does Inheritance support code reusibility?
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
        cout << "\n[Class A] Enter an integer: ";
        cin >> t;
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
        cout << "\n[Class B] Enter an integer: ";
        cin >> t;
    }
    ~B(){}
};

// Class C inherits from both A and B (Multiple Inheritance)
class C : public A , public B
{
private:
    int t;
public:
    C(int n):t(n){}
    C():t(0){}

    // This method overrides A::input() and B::input()
    void input()
    {
        cout << "\n[Class C] Enter an integer: ";
        cin >> t;
    }

    ~C(){}
};

int main()
{
    // 1. Normal standalone objects
    A objA;
    B objB;
    
    objA.input(); // Calls A's input
    objB.input(); // Calls B's input

    cout << "\n--- Working with Multiple Inheritance Object ---" << endl;

    // 2. Object of derived class C
    C objC;
    
    // This calls C's own input() because of Function Overriding
    objC.input(); 

   
    objC.A::input(); // Explicitly calls the inherited input() from Class A
    objC.B::input(); // Explicitly calls the inherited input() from Class B

    return 0;
}