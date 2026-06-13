#include<iostream>
#include<string>

using namespace std;

//Status Type
inline int NonExisting = 0, Active = 1;
inline const int Max_Bank = 25;
inline int NoOfBank = 0;

class Account {
private:

    //Account Attributes
    int id;
    int balance = 0;
    int status;
    string accountName;

public:
    Account()
    {
        this->accountName = "";
        this->status = NonExisting;
        this->balance = 0;
        this->id = NoOfBank;

    }
    void createAccount(string name)
    {
        this->accountName = name;
        this->status = Active;
        this->balance = 0;
        this->id = NoOfBank;

        cout << "Creating Account..." << endl;
        cout << "Account created with Id " << this->id << endl;

    }

    bool isActive()
    {
        if (this->status == 1)
            return true;
        else
            return false;
    }

    void deposit(int depositAmount)
    {
        if (isActive())
        {
            this->balance += depositAmount;

            cout << "Deposit sucessifully completed" << endl;
            cout << "Bank id " << this->id << " have now balance " << this->balance << endl;

        }

        else
        {
            cout << "Depositing failed..." << endl;
            cout << "Bank id not Active or Exist" << endl;
        }
    }

    void withdraw(int withdrawAmount)
    {
        if (isActive() && this->balance >= withdrawAmount)
        {

            this->balance = this->balance - withdrawAmount;

            cout << "Withdraw sucessifully completed" << endl;
            cout << "Bank id " << this->id << " have now balance " << this->balance << endl;

        }

        else
        {
            cout << "Withdrawing failed..." << endl;
            cout << "Either Bank id not Active or Exist OR Insufficient Balance" << endl;
        }
    }
    void sapat(Account& reciverAccount, int Amount)
    {
        if (this->isActive() && reciverAccount.isActive())
        {
            if (this->balance >= Amount)
            {
                reciverAccount.balance += Amount;
                this->balance -= Amount;

                cout << "Transfer sucessifully completed" << endl;
                cout << "Sender Bank id " << this->id << " have now balance " << this->balance << endl;
                cout << "Reciver Bank id " << reciverAccount.id << " have now balance " << reciverAccount.balance << endl;
            }
            else
            {
                cout << "Insufficient Balance..." << endl;
            }
        }
        else
        {
            cout << "Transfer failed..." << endl;
            cout << "one or both Bank id not Active or Exist";
            cout << "Or insufficient balance in sender Bank account" << endl;
        }
    }

    void checkKYC()
    {
        if (isActive())
        {
            cout << "Account Name: " << this->accountName << endl;
            cout << "Balance: " << this->balance << endl;
            cout << "Bank id: " << this->id << endl;
        }
        else
        {
            cout << " Bank id is not Active" << endl;
        }
    }


    friend void listAll(Account account[]);


    ~Account() {}//Destructor

};

inline void listAll(Account account[]) //Size of araay passed as global var = NoOfBank
{
    cout << endl << "Account id  \t Account Name \t Balance" << endl;

    for (int i = 1; i <= NoOfBank; i++)
    {
        cout << account[i].id << "\t\t\t" << account[i].accountName << "\t\t" << account[i].balance << "\t" << endl;
    }

}
inline void help()
{
    cout << "============================================" << endl;
    cout << "Menu Choices " << endl;
    cout << "1. Createing Account " << endl;
    cout << "2. Depositing Money" << endl;
    cout << "3. Withdrawing Amount" << endl;
    cout << "4. Take Sapat ( Transfering Amount)" << endl;
    cout << "5. Acessing KYC" << endl;
    cout << "6. Help" << endl;
    cout << "7. List All Bank" << endl;
    cout << "8. Total no of Bank" << endl;
    cout << "9. Exiting from program" << endl;
    cout << "_____________________________________________" << endl;
}