/* 
 */

 #include<iostream>

 using namespace std ;

class Test
{
    private: int x;
    private: float a;
    protected: string name;

};

class Sample : private Test //private make all the data member private except public one
                            //public keep them as it is
{
    public: string add;

};