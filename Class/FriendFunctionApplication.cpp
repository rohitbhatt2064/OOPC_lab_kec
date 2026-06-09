/* create a class wt representing wt in kg and g 
create another class named price that represent price of weight 
create a friend function that is friend to both class and determine price of input weight
class weight and class price */

#include<iostream>
#include<string>

using namespace std;

class Weight;
class Price;

class Weight
{
    private:
    int kg , g;

    public:
    Weight()
    {
        kg=g=0;
    }

    Weight( int kg , int g)
    {   
        this->kg= kg;
        this->g= g;
        
    }

    void show()
    {
        cout<<"kg "<<kg<<" g  "<<g<<endl;
    }
    friend Price convert(Weight& , Price&);
    ~Weight(){};
};

class Price
{   
    const float rate;//price per kg
    int total;
    
   
    public:


     Price(float r , int total):rate(r){this->total=total;}


    void show() const{
        cout<<"price:"<<rate<<" Total  "<<total<<endl;
    }
    
        

    

    friend Price convert(Weight& , Price&);
};

Price convert(Weight& w , Price& p)
{
    float rate;
    float total = 0 ;
    float totalWeight = w.kg + float(w.g/1000);
    total = totalWeight * rate ;

    return Price(rate , total);

}

int main()
{
    Weight w(1,400);
    Price(1000 , 0);
    


    return 0;
}