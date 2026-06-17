/* write a program to find the sum of 2 complex number using binary operator
 */

 #include<iostream>

 using namespace std;

 class Complex 
 {
    private:
    float r , c ;

    public:
    Complex()
    {
        r=0;
        c=0;
    }

    Complex(float real , float comp)
    {
        this->r=real;
        this->c=comp;
    }

    Complex operator + (Complex num)
    {
        Complex temp;
        temp.r = this->r  + num.r ;
        temp.c = this->c  + num.c ;
        return temp;
    }

    friend Complex operator - (Complex , Complex) ;

    void show ()
    {
       cout<<this->r<<" + "<<this->c<<"i "<<endl;
    }

    void getdata()
    {
        cout<<"Enter complex number : "<<endl;
        cin>>this->r;
        cout<<" + ";
        cin>> this->c;
        cout<<" i "<<endl;
    }
    ~Complex(){}
 };

    Complex  operator - (Complex C1 , Complex C2) 
    {
        
        int r = C1.r  - C2.r ;
        int c = C1.c  - C2.c ;
        return Complex(r,c);
    }

 int main()
 {
    Complex C1(5,7) ,C2(6,10) ,C ;
    C = C1 + C2;
    C.show();
    return 0;

    
    C1.getdata();
    C2.getdata();
    C=C1-C2;
    C.show();

    return 0;
 }


