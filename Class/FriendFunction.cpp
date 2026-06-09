/* create a class name distance that represent distance in feet and
 inch now it should have all regular class properties including member function that add two objects */
//fwrite a friend function that adds two object


 #include<iostream>

 using namespace std;

 class Distance
 {
    private:
    float feet , inch ;

    public:
    Distance()
    {
        this->feet=0;
        this->inch=0;

    }
    
    Distance(float feet, float inch)
    {
        this->feet= feet;
        this->inch= inch;
        
    }

     void getData()
    {   
        cin>>feet>>inch;   
        
    }

    void showData()
    {
        cout<<"Feet "<<feet<<"Inch  "<<inch<<endl;
    }

    Distance add(Distance);
    
    friend Distance add(Distance, Distance );
//Or we can use abstraction
    float getFeet(){return feet;}   //some level of abstraction
    float getInch(){return inch;} 


    ~Distance() {};
 };

 //Add Using Getter and setter

 Distance add(Distance d1, Distance d2)
{
    float f,i;
    f=d1.getFeet() + d2.getFeet(); //Using getter methord to get value of private variables
    i=d1.getInch() + d2.getInch(); //This particular function doesnot need to be friend function of class

}

//In reality we use friend function 
//Makeing a function to acess data from multiple class

Distance add(Distance d1, Distance d2)
{
    float f,i;
    f=d1.feet + d2.feet;
    i=d1.inch + d2.inch;

}

Distance Distance::add(Distance d)
{
    float f,i;
    f=this->feet + d.feet;
    i=this->inch + d.inch;
    
    if(i>12)
    {
        f=i/12;

    }

    return Distance(f,i);
}