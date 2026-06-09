//create a class weight that represent wt in kg and gram , create friend function that add two object

#include<iostream>
#include<string>
#include<memory>

using namespace std;
class Weight
{
    private:
    
    int kg,g;

    public:
    Weight()
    {
        this->kg = 0 ;
        this->g = 0;

    }
    Weight(int kg ,int g)
    {
         this->kg = kg ;
        this->g = g;
    }

   
    void setData()
    {
        cin>>kg>>g;
        this->kg = kg ;
        this->g = g;
    }

    void showData()
    {   
        cout<<"kg  "<<kg<<"g  "<< g <<endl;

    }

    friend Weight add(Weight& , Weight& );

    ~Weight()
    {
        cout<<"Calling Deconstructer ...";
    }
    
};
Weight add(Weight& x , Weight& y)
{
    int k,g;
    k=x.kg+y.kg;
    g=x.g+y.g;
}

int main()
{
   Weight W1(4,400);
   Weight W2(2,200);
   add(W1,W2);

    return 0;
}