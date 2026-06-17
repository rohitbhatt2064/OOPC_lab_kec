/* Create a class length in meter and cemtermeter write program to overload relational operator 
to overload > operator and use constructor to initialize necissary data 
 */

 #include<iostream>

 using namespace std;

 class Length
 {
    private:
    int m , cm ;

    public:
    Length()
    {
        m=0;
        cm=0;
    }

    Length(int m , int cm)
    {
        this->m= m;
        this->cm=cm;
    }

    bool operator > (Length L)
    {
        if(this->m > L.m && this->cm > L.cm)
        {
        
            
                return 1;
            
        }

        return 0; //if both if not true return 1 will not execute and the control come here

    }

  

    void show ()
    {
       cout<<this->m<<" kg "<<this->cm<<" cm "<<endl;
    }

    void getdata()
    {
        cout<<"Enter Length in Kg and Cm  : "<<endl;
        cin>>this->m;
        cout<<"kg ";
        cin>> this->cm;
        cout<<"cm "<<endl;
    }

    ~Length(){}

 };


 int main()
 {
    Length L1(9,54) , L2 (5,45);
    if(L1 > L2)
    {
        cout << " Is Greater " << endl;

    }
    else
    {
        cout << " Is Not Greater " << endl;
    }

    return 0;
 }


