#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 100

typedef struct
{
    long long cardNumber;
    char name[100];
    float balance;
    int pin;

}Account;

typedef struct 
{
    long long sender;
    long long receiver;
    float amount;
    char type[20];
}Transaction;

Account accounts[MAX_ACCOUNTS];
Transaction transactions[MAX_TRANSACTIONS];

int accountCount = 0;
int transactionCount =0;
int currentUserIndex = -1;

//admin func
void createAccount();
void deleteAccount();
void viewAccounts();
void searchAccount();
void totalBankFunds();
void viewTransactions();
void addTransaction(long long sender,long long receiver, float amount, char type[]);

//customer func
int login();
void deposit();
void withdraw();
void transferMoney();
void checkBalance();
void receiptHistory();

//for file handling:
void saveAccounts();
void loadAccounts();
void saveTransactions();
void loadTransactions();


int main()
{
    loadAccounts();
    loadTransactions();

    int roleChoice;
    int customerChoice;
    int adminChoice;

    do
    {
        printf("\n=============================\n");
        printf("      BANKING SYSTEM\n");
        printf("=============================\n");
        printf("1. Admin\n");
        printf("2. Customer\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &roleChoice);

        switch (roleChoice)
        {
        case 1:
            do
            {
                printf("\n===== ADMIN MENU =====\n");
                printf("1. Create Account\n");
                printf("2. Delete Account\n");
                printf("3. View All Accounts\n");
                printf("4. Search Account\n");
                printf("5. View Total Bank Funds\n");
                printf("6. View Transactions\n");
                printf("7. Back\n");
                printf("Choice: ");
                scanf("%d", &adminChoice);

                switch(adminChoice)
                {
                    case 1:
                        createAccount();
                        break;
                    case 2:
                        deleteAccount();
                        break;
                    case 3: 
                        viewAccounts();
                        break;
                    case 4:
                        searchAccount();
                        break;
                    case 5: 
                        totalBankFunds();
                        break;
                    case 6:
                        viewTransactions();
                        break;
                    case 7:
                        printf("Returning...\n");
                        break;
                    default:
                        printf("Invalid Choice!\n");
                }
            }while(adminChoice != 7);
            break;

        case 2:
            if(login())
            {
            do
            {
                printf("\n===== CUSTOMER MENU =====\n");
                printf("1. Deposit\n");
                printf("2. Withdraw\n");
                printf("3. Transfer Money\n");
                printf("4. Check Balance\n");
                printf("5. Receipt History\n");
                printf("6. Back\n");
                printf("Choice: ");
                scanf("%d", &customerChoice);

                switch(customerChoice)
                {
                    case 1:
                        deposit();
                        break;
                    case 2:
                        withdraw();
                        break;
                    case 3:
                        transferMoney();
                        break;
                    case 4:
                        checkBalance();
                        break;
                    case 5: 
                        receiptHistory();
                        break;
                    case 6:
                        currentUserIndex = -1;
                        printf("Logged out successfully\n");
                        break;
                }
            }while(customerChoice != 6);
            }
            else{
                printf("Login Failed\n");
            }
            break;
            

        case 3:
            saveAccounts();
            saveTransactions();
            printf("Thank you for using the Banking System\n");
            break;
        
        default:
            printf("Invalid Choice\n");
            break;
        }
    }while(roleChoice != 3);

    return 0;
}

void createAccount()
{
    if(accountCount >= MAX_ACCOUNTS)
    {
        printf("Bank is full\n");
        return;
    }

    printf("Enter card Number: ");
    scanf("%lld", &accounts[accountCount].cardNumber);

    printf("Enter Name: ");
    scanf(" %[^\n]", accounts[accountCount].name);

    printf("Enter PIN: ");
    scanf("%d", &accounts[accountCount].pin);

    printf("Enter Initial Balance: ");
    scanf("%f", &accounts[accountCount].balance);

    printf("Account created successfully\n");

    accountCount++;
    saveAccounts();
}
void deleteAccount()
{
    long long searchCard;
    printf("Enter Card Number to delete: ");
    scanf("%lld", &searchCard);

    for(int i = 0; i < accountCount; i++)
    {
        if(accounts[i].cardNumber == searchCard)
        {
            for(int j = i; j < accountCount - 1; j++)
            {
                accounts[j] = accounts[j + 1];
            }
            accountCount--;
            printf("Account deleted successfully!\n");
            return;
        }
    }
    printf("Account not found!\n");
    accountCount--;
    saveAccounts();
}
void viewAccounts()
{
    if(accountCount ==0)
    {
        printf("No Accounts found\n");
        return;
    }
    printf("\n====== ACCOUNT LIST =====\n");
    printf("%-15s %-15s %-10s\n", "Card", "Name", "Bal");
    for(int i = 0 ; i < accountCount ; i++)
    {
      printf("%-10lld %-15s %-10.2f\n", 
        accounts[i].cardNumber,
        accounts[i].name,
        accounts[i].balance);
    }
}
void searchAccount()
{
    long long searchCard;
    int found = 0;
    printf("Enter Card Number to search: \n");
    scanf("%lld", &searchCard);

    for(int i = 0 ; i < accountCount ; i++)
    {
        if(accounts[i].cardNumber == searchCard)
        {
            printf("Account found!\n");
            printf("Card Number: %lld | Name: %s | Balance: %.2f\n", 
                    accounts[i].cardNumber, accounts[i].name,accounts[i].balance);
            found = 1;
        }
    }
    if(found == 0)
    {
        printf("Accound not found\n");
        return;
    }
}
void totalBankFunds()
{
    float total = 0;

    if(accountCount == 0)
    {
        printf("No accounts available\n");
        return;
    }

    for(int i = 0 ;i < accountCount ; i++)
    {
        total += accounts[i].balance;//sum 
    }

    printf("\n======= TOTAL BANK FUNDS =======\n");
    printf("Total Money: PHP %.2f\n", total);
}
void viewTransactions()
{
    if(transactionCount == 0)
    {
        printf("No transactions available\n");
        return;
    }

    printf("\n======= TRANSACTION HISTORY =======\n");

    for(int i = 0 ; i < transactionCount ; i++)
    {
        printf("\nTransaction no.%d\n", i + 1);

        printf("Type: %s\n", transactions[i].type);
        printf("Sender: %lld\n", transactions[i].sender);
        printf("Receiver: %lld\n", transactions[i].receiver);
        printf("Amount: PHP%.2f\n", transactions[i].amount);
    }
}
void addTransaction(long long sender,long long receiver, float amount, char type[])
{
    if(transactionCount >= MAX_TRANSACTIONS)
    {
        printf("Transaction history full\n");
        return;
    }

    transactions[transactionCount].sender = sender;
    transactions[transactionCount].receiver = receiver;
    transactions[transactionCount].amount = amount;
    strcpy(transactions[transactionCount].type, type);
    transactionCount++;
    printf("Transaction recorded successfully\n");
}
//customer func
int login()
{
    long long cardNumber;
    int pin;

    printf("\n===== CUSTOMER LOGIN =====\n");
    printf("Enter Card Number: ");
    scanf("%lld",&cardNumber);

    printf("Enter PIN: ");
    scanf("%d", &pin);

    for(int i = 0 ; i < accountCount; i++)
    {
        if(accounts[i].cardNumber == cardNumber && accounts[i].pin == pin)
        {
            currentUserIndex = i;
            printf("\nLOGIN SUCCESSFUL\n");
            printf("Welcome, %s\n", accounts[i].name);
            return 1;
        }
    }

    printf("\nInvalid Card Number or PIN\n");
    return 0;
}
void deposit()
{
    float amount;
    if(currentUserIndex == -1)
    {
        printf("Please login first\n");
        return;
    }

    printf("Enter amount you want to deposit: ");
    scanf("%f", &amount);

    if(amount <= 0)
    {
        printf("Invalid amount!\n");
        return;
    }

    accounts[currentUserIndex].balance += amount;
    saveAccounts();
    saveTransactions();
    addTransaction(
        0,
        accounts[currentUserIndex].cardNumber,
        amount,
        "DEPOSIT"
    );
    printf("\nDeposit Successful!\n");
    printf("Deposited: %.2f\n", amount);
    printf("New Balance: %.2f\n", accounts[currentUserIndex].balance);

}
void withdraw()
{
    float amount;

    if(currentUserIndex == -1)
    {
        printf("Please login first\n");
        return;
    }

    printf("Enter amount: ");
    scanf("%f", &amount);

    if(amount <= 0)
    {
        printf("Invalid amount!\n");
        return;
    }

    if(amount > accounts[currentUserIndex].balance)
    {
        printf("Insufficient funds\n");
        return;
    }

    accounts[currentUserIndex].balance -= amount;
    saveAccounts();
    saveTransactions();
    addTransaction(
        accounts[currentUserIndex].cardNumber,
        0,
        amount,
        "WITHDRAW"
    );
    printf("\nWithdrawal Successful!\n");
    printf("Withdrawn: %.2f\n", amount);
    printf("Remaining Balance: %.2f\n", accounts[currentUserIndex].balance);
}
void transferMoney()
{

    long long receiverCard;
    float amount;
    int receiverIndex = -1;

    if(currentUserIndex == -1)
    {
        printf("Please login first\n");
        return;
    }

    printf("Enter receiver card number: ");
    scanf("%lld", &receiverCard);

    for(int i = 0 ; i < accountCount ; i++){
        if(accounts[i].cardNumber == receiverCard)
        {
            receiverIndex = i;
            break;
        }
    }

    printf("Enter amount to transfer: ");
    scanf("%f", &amount);

    if(receiverIndex == -1)
    {
        printf("Receiver account not found\n");
        return;
    }

    if(amount <= 0)
    {
        printf("Invalid amount\n");
        return;
    }

    if(amount > accounts[currentUserIndex].balance)
    {
        printf("Insufficient funds\n");
        return;
    }

    accounts[currentUserIndex].balance -= amount;
    accounts[receiverIndex].balance += amount;
    saveAccounts();
    saveTransactions();

    addTransaction(
        accounts[currentUserIndex].cardNumber,
        accounts[receiverIndex].cardNumber,
        amount,
        "TRANSFER"
    );
    printf("\n===== TRANSFER RECEIPT =====\n");
    printf("Sender: %s\n", accounts[currentUserIndex].name);
    printf("Receiver: %s\n", accounts[receiverIndex].name);
    printf("Amount: %.2f\n", amount);
    printf("Remaining Balance: %.2f\n", accounts[currentUserIndex].balance);

}
void checkBalance()
{
    if(currentUserIndex == -1)
    {
        printf("Please login first!\n");
        return;
    }

    printf("\n===== ACCOUNT BALANCE =====\n");

    printf("Name: %s\n",accounts[currentUserIndex].name);

    printf("Card Number: %lld\n",accounts[currentUserIndex].cardNumber);

    printf("Current Balance: PHP %.2f\n",accounts[currentUserIndex].balance);
}

void receiptHistory()
{
    if(currentUserIndex == -1)
    {
        printf("Please login first\n");
        return;
    }

    long long userCard = accounts[currentUserIndex].cardNumber;
    int found = 0;

    printf("\n===== RECEIPT HISTORY =====\n");

    for(int i = 0 ; i < transactionCount ; i++)
    {
        if(transactions[i].sender == userCard || transactions[i].receiver == userCard)
        {
            found = 1;
            printf("\nTRANSACTION no.%d\n", i + 1);
            printf("Type: %s\n", transactions[i].type);
            printf("Sender: %lld\n", transactions[i].sender);
            printf("Receiver: %lld\n", transactions[i].receiver);
            printf("Amount: PHP %.2f\n", transactions[i].amount);
            printf("------------------------------------------\n");
        }
    }
    if(found == 0)
    {
        printf("No transactions history found\n");
    }
}

void saveAccounts()
{
    FILE *fp = fopen("accounts.dat", "wb");

    if(fp == NULL)
    {
        printf("Error saving accounts!\n");
        return;
    }

    fwrite(&accountCount, sizeof(int), 1, fp);
    fwrite(accounts, sizeof(Account), accountCount, fp);

    fclose(fp);
}

void loadAccounts()
{
    FILE *fp = fopen("accounts.dat", "rb");

    if(fp == NULL)
    {
        return;
    }

    fread(&accountCount, sizeof(int), 1, fp);
    fread(accounts, sizeof(Account), accountCount, fp);

    fclose(fp);
}

void saveTransactions()
{
    FILE *fp = fopen("transactions.dat", "wb");

    if(fp == NULL)
    {
        printf("Error saving transactions!\n");
        return;
    }

    fwrite(&transactionCount, sizeof(int), 1, fp);
    fwrite(transactions, sizeof(Transaction), transactionCount, fp);

    fclose(fp);
}

void loadTransactions()
{
    FILE *fp = fopen("transactions.dat", "rb");

    if(fp == NULL)
    {
        return;
    }

    fread(&transactionCount, sizeof(int), 1, fp);
    fread(transactions, sizeof(Transaction), transactionCount, fp);

    fclose(fp);
}