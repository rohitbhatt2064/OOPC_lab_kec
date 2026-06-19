/* create a class weight that represent wt in kg and gram , 
   create another class named price that represents price of the given weight 
   create friend function on both class that it is friend to both class
   determine the price of input weight
   make a class friend to another class and a function in that class
*/


/* =====================================================================================
   THE CORE PROBLEM
   =====================================================================================
   
   We want Weight at top and Price at bottom.
   Inside Weight we want to declare:
       friend void Price::calculate(Weight& w);
   
   But C++ reads TOP TO BOTTOM strictly.
   So when compiler reaches that line inside Weight it asks:
       "Does Price have a function called calculate?"
       "I dont know yet, I havent seen Price fully"
       ERROR.
   
   A simple forward declaration  →  class Price;
   only tells compiler "Price EXISTS as a type"
   does NOT tell it what functions are inside Price
   So friend void Price::calculate() still fails.

   To fix this we have multiple approaches:
   =====================================================================================
*/


/* =====================================================================================
   APPROACH 1 : WRITING PRICE FIRST (Simplest Fix)
   =====================================================================================
   
   Just put the entire Price class above Weight.
   Compiler sees Price fully, then sees Weight, no confusion.
   
   * Pros : Simple. Clean. No extra tricks needed.
   * Cons : Price is now DEPENDENT on staying above Weight always.
             If you add more classes later, ordering becomes a headache.
             Does not scale well with multiple interdependent classes.
   
   * Industry Status : MEDIUM (Fine for small programs, avoided in large codebases)
   =====================================================================================
*/


/* =====================================================================================
   APPROACH 2 : CLASS LEVEL FRIENDSHIP
   =====================================================================================
   
   Inside Weight declare:
       friend class Price;
   This gives the ENTIRE Price class access to Weight's private members.
   
   * Pros : Easiest to write.
             No ordering issues, simple forward declaration is enough.
             Very readable.
   * Cons : ZERO isolation. Every single function inside Price can now
             read and modify Weight's private variables.
             Breaks encapsulation principle of OOP.
   
   * Industry Status : LOW (Discouraged unless classes are very tightly coupled)
   =====================================================================================
*/


/* =====================================================================================
   APPROACH 3 : STATIC MEMBER BRIDGE  
   (Also called Access Bridge or Mediator Pattern)
   =====================================================================================
   
   Create a tiny neutral helper class at the very top of the file.
   This helper class contains static functions that act as a relay/conduit.
   
   Instead of making Price::calculate a friend directly:
       Weight makes the Bridge function its friend.
       Price calls that bridge function internally.
   
   This lets Weight stay at top and Price stay at bottom.
   Only the bridge function has access, everything else is isolated.
   
   * Pros : Weight stays at top, Price stays at bottom.
             Scales well with multiple classes.
             Only ONE specific bridge function gets access to Weight internals.
   * Cons : Requires writing an extra helper class.
             static means the function belongs to class not to object instance.
             Have to pass instance variables manually as references.
             Adds boilerplate code.
   
   * Industry Status : MEDIUM (Used in large scale enterprise and game engines)
   =====================================================================================
*/


/* =====================================================================================
   APPROACH 4 : METHOD FORWARD DECLARATION WITH SPLIT BODY  ← RECOMMENDED
   =====================================================================================
   
   KEY RULE TO REMEMBER:
       class Price;                          → forward declaration
                                               only says "Price exists as a type"
                                               compiler still does not know its functions
                                               friend void Price::calculate() FAILS here
       
       class Price { void calculate(...); }; → stub / full declaration
                                               now compiler knows calculate exists inside Price
                                               friend void Price::calculate() WORKS now
   
   HOW IT WORKS:
   
   Step 1: Write complete Price class at top with ALL members declared
           (private variables, constructors, all function SIGNATURES)
           But write ONLY the declaration of calculate, NOT its body
           because Weight is not fully known yet at this point.
   
   Step 2: Write Weight class below Price.
           Now compiler already knows Price::calculate exists from Step 1.
           So friend void Price::calculate(Weight& w); works perfectly.
   
   Step 3: Write the BODY of calculate at the very bottom using scope resolution.
           void Price::calculate(Weight& w) { ... }
           By this point both classes are fully known so body can access
           both w.kg and this->rate freely.
   
   IMPORTANT:
       class Price { } is opened ONLY ONCE.
       It is NEVER reopened below.
       All bodies are written outside using Price:: not inside a second class wrapper.
   
   * Pros : Strict isolation, only that one function gets access.
             Completely instance based, this-> works naturally.
             Clean and readable structure.
   * Cons : Price structure must still appear above Weight in the file.
             If Weight also needs to call a function inside Price it creates
             a circular dependency and this method breaks down.
   
   * Industry Status : HIGH (The standard for clean modern C++ in single files)
   =====================================================================================
*/


/* =====================================================================================
   APPROACH 5 : GLOBAL BRIDGING FUNCTION
   =====================================================================================
   
   Write a standalone global function outside both classes:
       void calculate(Weight& w, Price& p)
   Declare it as friend in BOTH classes.
   Call it directly in main as:
       calculate(W1, P1);
   
   * Pros : Simple to write.
             Matches a direct main() call flow naturally.
             No class ordering dependency.
   * Cons : Pollutes the global namespace.
             Logic lives outside OOP structure entirely.
             Not a member function so cannot use this->
   
   * Industry Status : LOW 
     (Used mainly for operator overloading like << and >> or legacy C compatibility)
   =====================================================================================
*/


#include<iostream>

using namespace std;


class Weight;
class Price;

class BridgeWeightPrice
{
    public:
    static int weight(Weight& w);
   



};
class Weight
{
    private:
    
    int kg;

    public:

    Weight()
    {
        this->kg = 0 ;
    }

    Weight(int kg)
    {
         this->kg = kg ;
        
    }
   
    void setData()
    {
        cout<<"Enter Weight"<<endl;
        cin>>kg;
        cout<<endl;
        this->kg = kg ;
        
    }
//Remember just declaring Price avobe is not enough if calculate exist till this line doesnot not know 
//Read comments of above for knowing more 
    friend int BridgeWeightPrice::weight(Weight& w);
    
    ~Weight(){};
    
};

class Price
{
    private:
    int rate ,total ;

    public:
    Price()
    {
        this->rate = 0;
        this->total = 0;

    }

    Price(int rate )
    {
        this->rate = rate;
        this ->total = 0;
    }

    void showTotal()
    {
        cout<<"Total ="<<this->total<<endl;
    }

    void setData()
    {   
        cout<<"Enter Rate: ";
        cin>>this->rate;
        cout<<endl;
        this->total=0;
        
    }

    
    void calculate(Weight& w)
    {   
        this->total = BridgeWeightPrice::weight(w) * this->rate;
    } 
  

    ~Price(){};


};

int BridgeWeightPrice::weight(Weight& w)
{
    return w.kg;
}

int main()
{
   Weight W1;
   Price P1;
   W1.setData();
   P1.setData();
   P1.calculate(W1);
   P1.showTotal();

    return 0;
}