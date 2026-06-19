//create a class weight that represent wt in kg and gram , 
//create another class named price that represents price of the given weight 
//create friend function on oth class that it is friend to both class
//determine the price of input weight

#include<iostream>

using namespace std;

class Weight;
class Price;
class Weight
{
    private:
    
    int kg,g;

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


    friend void calculate(Weight& , Price& );

    friend Price;

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
    
    friend void calculate(Weight& w , Price& p);
    
    void calculate(Weight& w)
    {
        this->total = w.kg * this->rate;
    }

    ~Price(){};


};

void calculate(Weight& w , Price& p)
{
    p.total = w.kg * p.rate;
}

int main()
{
   Weight W1(4);
   Price P1(1000);
   calculate(W1,P1);
   P1.showTotal();

    cout<<"___________________________________________"<<endl;
   Weight W2;
   W2.setData();
   Price P2;
   P2.setData();
   P2.calculate(W2);
   P2.showTotal();


    return 0;
}