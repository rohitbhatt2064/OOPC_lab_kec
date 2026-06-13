//Create a class name acc holder ( name , acc no , balance) , have constructor(default , paramatrized) destructor 
//Display   deposit , withdraw , sapat 


#include<iostream>
#include<string>

using namespace std;

//Status Type
int NonExisting=0 , Active = 1 ;
const int Max_Bank = 25;
int NoOfBank = 0;

class Account{
    private:
    
    //Account Attributes
    int id ;
    int balance = 0 ;
    int status  ;  
    string accountName;

    public:
    Account()
    { 
     this->accountName ="";
     this->status = NonExisting;
     this->balance = 0 ;
     this->id = NoOfBank;

    }
     void createAccount(string name )
    { 
     this->accountName = name;
     this->status = Active;
     this->balance = 0 ;
     this->id =NoOfBank;

     cout<<"Creating Account..."<<endl;
     cout<<"Account created with Id "<<this->id<<endl;

    }                       
     
     bool isActive()
    { 
    if(this->status==1)
    return true;
    else
    return false;
    }
    
    void deposit(int depositAmount )
    {
        if(isActive())
        {
            this->balance += depositAmount;
            
            cout<<"Deposit sucessifully completed"<<endl;
            cout<<"Bank id "<< this->id<< " have now balance " <<this->balance<<endl;

        }
        
        else
        {
            cout<<"Depositing failed..."<<endl;
            cout<<"Bank id not Active or Exist"<<endl;
        }
    }

    void withdraw(int withdrawAmount )
    {
        if(isActive() && this->balance>=withdrawAmount)
        {
            
            this->balance = this->balance - withdrawAmount;
            
            cout<<"Withdraw sucessifully completed"<<endl;
            cout<<"Bank id "<< this->id<< " have now balance " <<this->balance<<endl;

        }
        
        else
        {
            cout<<"Withdrawing failed..."<<endl;
            cout<<"Either Bank id not Active or Exist OR Insufficient Balance"<<endl;
        }
    }
     void sapat(Account &reciverAccount , int Amount)
    {
        if(this->isActive() && reciverAccount.isActive() )
        {
            if(this->balance>= Amount)
            {
                reciverAccount.balance += Amount;
                this->balance -= Amount;

                cout<<"Transfer sucessifully completed"<<endl;
                cout<<"Sender Bank id "<< this->id<< " have now balance " <<this->balance<<endl;
                cout<<"Reciver Bank id "<< reciverAccount.id<< " have now balance " <<reciverAccount.balance<<endl;
            }
            else
            {
                cout<<"Insufficient Balance..."<<endl; 
            }  
        }
        else
        {
            cout<<"Transfer failed..."<<endl;
            cout<<"one or both Bank id not Active or Exist";
            cout<<"Or insufficient balance in sender Bank account"<<endl;
        }
    }

    void checkKYC()
    {
        if(isActive())
        {
            cout<<"Account Name: "<< this->accountName << endl;
            cout<<"Balance: "<< this->balance<< endl;
            cout<<"Bank id: "<< this->id << endl;
        }
        else
        {
            cout << " Bank id is not Active"<<endl;
        }
    }


    friend void listAll(Account account[] );


    ~Account(){}//Destructor

};

void listAll(Account account[] ) //Size of araay passed as global var = NoOfBank
{     
    cout<<endl<<"Account id  \t Account Name \t Balance"<<endl;
    
    for(int i=1; i<= NoOfBank ; i++)
    {
        cout<<account[i].id<<"\t\t\t"<<account[i].accountName<<"\t\t"<<account[i].balance<<"\t"<<endl;
    }
    
}
void help()
{
    cout<<"============================================"<<endl;
    cout<<"Menu Choices "<<endl;
    cout<<"1. Createing Account "<<endl;
    cout<<"2. Depositing Money"<<endl;
    cout<<"3. Withdrawing Amount"<<endl;
    cout<<"4. Take Sapat ( Transfering Amount)"<<endl;
    cout<<"5. Acessing KYC"<<endl;
    cout<<"6. Help"<<endl;
    cout<<"7. List All Bank"<<endl;
    cout<<"8. Total no of Bank"<<endl;
    cout<<"9. Exiting from program"<<endl;
    cout<<"_____________________________________________"<<endl;
}

int main()
{  string accountName;
    Account account[Max_Bank+1];//ignoring 0 position of 1
      int   choice = 0;
    
      //Menu Interface
      cout<<"Basic Banking System"<<endl;
      help();

    while(1)
    {
        cout<<endl<<"==================================="<<endl;
        cout<<"Enter the choice"<<endl;
        cin>>choice;
        cout<<endl;

        switch (choice)
        {
            case 1://Creating Account
            {    cout<<"Enter Account Name : "<<endl;
                cin>>accountName;

                account[++NoOfBank].createAccount(accountName);

                break;
            }
            case 2://Depositing Money
            {    int depositAmount = 0 ;
                int accountId = 0;

                cout<<"Deposit Initiated..."<<endl;
                cout<<"Enter Account id : ";
                cin>>accountId;
                cout<<" Amount of money need to be Deposited : ";
                cin>>depositAmount;
                cout<<endl;

                account[accountId].deposit(depositAmount);
                
                break;
            }   
            case 3://Withdrawing Amount
            {    int withdrawAmount = 0 ;
                int accountId = 0 ;

                cout<<"Withdraw Initiated..."<<endl;
                cout<<"Enter Account id : ";
                cin>>accountId;
                cout<<" Amount of money need to be Withdrawn : ";
                cin>>withdrawAmount;
                cout<<endl;

                account[accountId].withdraw(withdrawAmount);
                
                break;
            }
            case 4://Sapat
            {   int transferAmount = 0, senderId = 0, receiverId = 0;
                
                cout<<"Sapat Initiated..."<<endl;
                cout << "Enter Sender Account ID: ";
                cin >> senderId;
                cout <<endl<< "Enter Receiver Account ID: ";
                cin >> receiverId;
                cout <<endl<< "Enter Amount to Transfer: ";
                cin >> transferAmount;
                cout<<endl;

                account[senderId].sapat(account[receiverId] ,transferAmount );
                
                break;

            }
            case 5://Acessing KYC 
            {
                int accountId = 0;

                cout<<"Showing KYC Details..."<<endl;
                cout<<"Enter Account id : ";
                cin>>accountId;
                cout<<endl;

                account[accountId].checkKYC();
                
                break;
            }
            case 6: //help initiation feature
            {
                help();

                break;
            }
            
            case 7://Listing all Bank Account
            {
                listAll(account);

                break;
            }

            case 8:
            {
                cout<<"Total no of Bank Account : "<<NoOfBank<<endl;
            
            break;
            }
            case 9://Exit Feature
            {
                cout<<"Are you sure you want to Exit 1:yes 0:no"<<endl;
                cin>>choice;

                if(choice)
                    return 0;//Exiting the program

                break;
            }

            default:
            {
                cout<<"Invalid Command..."<<endl;
                help();

                break;
            }
        }
    }
    return 0;
}