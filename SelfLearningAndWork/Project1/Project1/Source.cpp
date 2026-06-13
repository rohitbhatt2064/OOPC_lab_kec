//Create a class name acc holder ( name , acc no , balance) , have constructor(default , paramatrized) destructor 
//Display   deposit , withdraw , sapat 

#include<iostream>
#include<string>
#include "Header.h"

using namespace std;

int main()
{
    string accountName;
    Account account[Max_Bank + 1];//ignoring 0 position of 1
    int   choice = 0;

    //Menu Interface
    cout << "Basic Banking System" << endl;
    help();

    while (1)
    {
        cout << endl << "===================================" << endl;
        cout << "Enter the choice" << endl;
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1://Creating Account
        {
            cout << "Enter Account Name : " << endl;
            cin >> accountName;

            account[++NoOfBank].createAccount(accountName);

            break;
        }
        case 2://Depositing Money
        {
            int depositAmount = 0;
            int accountId = 0;

            cout << "Deposit Initiated..." << endl;
            cout << "Enter Account id : ";
            cin >> accountId;
            cout << " Amount of money need to be Deposited : ";
            cin >> depositAmount;
            cout << endl;

            account[accountId].deposit(depositAmount);

            break;
        }
        case 3://Withdrawing Amount
        {
            int withdrawAmount = 0;
            int accountId = 0;

            cout << "Withdraw Initiated..." << endl;
            cout << "Enter Account id : ";
            cin >> accountId;
            cout << " Amount of money need to be Withdrawn : ";
            cin >> withdrawAmount;
            cout << endl;

            account[accountId].withdraw(withdrawAmount);

            break;
        }
        case 4://Sapat
        {
            int transferAmount = 0, senderId = 0, receiverId = 0;

            cout << "Sapat Initiated..." << endl;
            cout << "Enter Sender Account ID: ";
            cin >> senderId;
            cout << endl << "Enter Receiver Account ID: ";
            cin >> receiverId;
            cout << endl << "Enter Amount to Transfer: ";
            cin >> transferAmount;
            cout << endl;

            account[senderId].sapat(account[receiverId], transferAmount);

            break;

        }
        case 5://Acessing KYC
        {
            int accountId = 0;

            cout << "Showing KYC Details..." << endl;
            cout << "Enter Account id : ";
            cin >> accountId;
            cout << endl;

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
            cout << "Total no of Bank Account : " << NoOfBank << endl;

            break;
        }
        case 9://Exit Feature
        {
            cout << "Are you sure you want to Exit 1:yes 0:no" << endl;
            cin >> choice;

            if (choice)
                return 0;//Exiting the program

            break;
        }

        default:
        {
            cout << "Invalid Command..." << endl;
            help();

            break;
        }
        }
    }
    return 0;
}