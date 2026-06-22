/* create a class weight that represent wt in kg and gram , 
   create another class named price that represents price of the given weight 
   create friend function on both class that it is friend to both class
   determine the price of input weight
   make a  friend function to both other class for this
*/

#include<iostream>

using namespace std;


class Weight;
class Price;


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
    friend void calculate(Weight& , Price&);
    
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

    
    friend void calculate(Weight& , Price&);
  

    ~Price(){};


};

void calculate(Weight& w , Price & p)
{
    p.total = w.kg * p.rate;    
}

int main()
{
   Weight W1;
   Price P1;
   W1.setData();
   P1.setData();
   calculate(W1,P1);
   P1.showTotal();

    return 0;
}