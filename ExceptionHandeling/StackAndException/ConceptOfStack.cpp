/* 
    Basic concept of stack and stack implementation basic 

- Stack empty error
- Stack Overflow error
 */

 #include <iostream>

 using namespace std;

 class Stack
 {
    int arr[5];
    int top;

    public:
    Stack()
    {
        top = -1 ;
    }
    ~Stack(){}
    void push (int a)
    {
        if ( top >= 4 ) throw Error();
        arr[++top] = a;
    }
    int pop()
    {   
        if ( top = -1 ) throw Error();
        return arr[top--];
    }

    class Error
    {
        public:
        class Empty{};
        class Full{};
    };
 };

//some error
/*  int take_input()
(
    int a ;
    cin >>a;
    return a;
)  */
 int main()
 {
    Stack S1;

    try
    {
    
    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);
    S1.push(50);

    //S1.push(60);   // here the stack over flow exception occurs
    
    cout<<S1.pop()<<endl;
    cout<<S1.pop()<<endl;
    cout<<S1.pop()<<endl;
    cout<<S1.pop()<<endl;
    cout<<S1.pop()<<endl;

    //cout<<S1.pop()<<endl;   //here the stack empty exceptio occurs
    }

    catch( Stack::Error::Empty e)
    {
        cout << " Unexpected error " << endl;

    }

    catch( Stack::Error::Full e)
    {
        cout << " Unexpected error " << endl;

    }

    catch( Stack::Error error)
    {
        cout << " Unexpected error " << endl;

    }


 }