/* 
PS C:\VScode Rohit\OOPC\Lab3> g++ SimpleBankingSystem.cpp -o SimpleBankingSystem    
PS C:\VScode Rohit\OOPC\Lab3> ./SimpleBankingSystem                                                                        
Basic Banking System                   
============================================
Menu Choices 
1. Createing Account 
2. Depositing Money
3. Withdrawing Amount
4. Take Sapat ( Transfering Amount)
5. Acessing KYC
6. Help
7. List All Bank
8. Total no of Bank
9. Exiting from program
_____________________________________________

===================================
Enter the choice

1

Enter Account Name : 
NIC
Creating Account...
Account created with Id 1

===================================
Enter the choice
2

Deposit Initiated...
Enter Account id : 1
 Amount of money need to be Deposited : 5000

Deposit sucessifully completed
Bank id 1 have now balance 5000

===================================
Enter the choice
3

Withdraw Initiated...
Enter Account id : 1
 Amount of money need to be Withdrawn : 50000

Withdrawing failed...
Either Bank id not Active or Exist OR Insufficient Balance

===================================
Enter the choice
3

Withdraw Initiated...
Enter Account id : 1  
 Amount of money need to be Withdrawn : 500

Withdraw sucessifully completed
Bank id 1 have now balance 4500

===================================
Enter the choice
6

============================================
Menu Choices 
1. Createing Account 
2. Depositing Money
3. Withdrawing Amount
4. Take Sapat ( Transfering Amount)
5. Acessing KYC
6. Help
7. List All Bank
8. Total no of Bank
9. Exiting from program
_____________________________________________

===================================
Enter the choice
1

Enter Account Name : 
NBL
Creating Account...
Account created with Id 2

===================================
Enter the choice
500000

Invalid Command...
============================================
Menu Choices 
1. Createing Account 
2. Depositing Money
3. Withdrawing Amount
4. Take Sapat ( Transfering Amount)
5. Acessing KYC
6. Help
7. List All Bank
8. Total no of Bank
9. Exiting from program
_____________________________________________

===================================
Enter the choice
2

Deposit Initiated...
Enter Account id : 50000
 Amount of money need to be Deposited : 4

Depositing failed...
Bank id not Active or Exist

===================================
Enter the choice
2

Deposit Initiated...
Enter Account id : 2
 Amount of money need to be Deposited : 500000

Deposit sucessifully completed
Bank id 2 have now balance 500000

===================================
Enter the choice
4

Sapat Initiated...
Enter Sender Account ID: 2

Enter Receiver Account ID: 1

Enter Amount to Transfer: 20000

Transfer sucessifully completed
Sender Bank id 2 have now balance 480000
Reciver Bank id 1 have now balance 24500

===================================
Enter the choice
5

Showing KYC Details...
Enter Account id : 1

Account Name: NIC
Balance: 24500
Bank id: 1

===================================
Enter the choice
5

Showing KYC Details...
Enter Account id : 2

Account Name: NBL
Balance: 480000
Bank id: 2

===================================
Enter the choice
1

Enter Account Name : 
EBL
Creating Account...
Account created with Id 3

===================================
Enter the choice
1    

Enter Account Name : 
HBB
Creating Account...
Account created with Id 4

===================================
Enter the choice
2

Deposit Initiated...
Enter Account id : 3
 Amount of money need to be Deposited : 50000

Deposit sucessifully completed
Bank id 3 have now balance 50000

===================================
Enter the choice
2

Deposit Initiated...
Enter Account id : 4
 Amount of money need to be Deposited : 600000

Deposit sucessifully completed
Bank id 4 have now balance 600000

===================================
Enter the choice
6

============================================
Menu Choices 
1. Createing Account 
2. Depositing Money
3. Withdrawing Amount
4. Take Sapat ( Transfering Amount)
5. Acessing KYC
6. Help
7. List All Bank
8. Total no of Bank
9. Exiting from program
_____________________________________________

===================================
Enter the choice
7


Account id       Account Name    Balance
1       NIC     24500
2       NBL     480000
3       EBL     50000
4       HBB     600000

===================================
Enter the choice
8

Total no of Bank Account : 4

===================================
Enter the choice
9

Are you sure you want to Exit 1:yes 0:no
0

===================================
Enter the choice
9

Are you sure you want to Exit 1:yes 0:no
1
PS C:\VScode Rohit\OOPC\Lab3> 

 */