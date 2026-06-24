#include<iostream>

using namespace std;

class Radian
{
private:
   float r;
public:
    Radian(float r):r(r){}
    Radian():r(0){}
    Radian(int g):r(3.15/200.0 * g){};

    void show()
    {
        cout<<r<<endl;
    }
    ~Radian(){}

};

int main()
{
    Radian R(1001);
    R.show();
    return 0;
}