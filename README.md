# Banking Management System in C

## Overview

The Banking Management System is a console-based application developed in C that simulates fundamental banking operations. The system provides administrative and customer functionalities, allowing account management, financial transactions, transaction monitoring, and persistent data storage through file handling.

This project demonstrates the application of core programming concepts including structures, arrays, functions, modular programming, authentication, transaction processing, and binary file management.

---

## Features

### Administrative Functions

#### Create Account
Allows the administrator to create a new customer account by entering:

- Card Number
- Account Holder Name
- Personal Identification Number (PIN)
- Initial Balance

#### Delete Account
Removes an existing account from the system.

#### View All Accounts
Displays all registered customer accounts including:

- Card Number
- Account Holder Name
- Current Balance

#### Search Account
Searches for a specific account using the card number.

#### View Total Bank Funds
Calculates and displays the total balance held across all accounts.

#### View Transaction History
Displays all recorded transactions performed within the system.

---

### Customer Functions

#### Login
Authenticates customers using:

- Card Number
- PIN

#### Deposit
Allows customers to add funds to their account.

#### Withdraw
Allows customers to withdraw funds from their account, subject to sufficient balance.

#### Transfer Money
Transfers funds from one customer account to another.

#### Check Balance
Displays the current account information and available balance.

#### Receipt History
Displays all transactions associated with the logged-in customer.

---

## Data Persistence

The application uses binary file handling to store account and transaction data.

### Files Used

| File Name | Description |
|------------|------------|
| accounts.dat | Stores account information |
| transactions.dat | Stores transaction records |

Data remains available after the application is closed and reopened.

---

## System Design

### Account Structure

```c
typedef struct
{
    long long cardNumber;
    char name[100];
    float balance;
    int pin;
} Account;
```

### Transaction Structure

```c
typedef struct
{
    long long sender;
    long long receiver;
    float amount;
    char type[20];
} Transaction;
```

---

## Transaction Types

### Deposit

```text
Sender: 0
Receiver: Customer Card Number
Type: DEPOSIT
```

### Withdrawal

```text
Sender: Customer Card Number
Receiver: 0
Type: WITHDRAW
```

### Transfer

```text
Sender: Customer Card Number
Receiver: Recipient Card Number
Type: TRANSFER
```

---

## Project Structure

```text
banking-management-system/
│
├── main.c
├── README.md
├── .gitignore
│
├── accounts.dat
└── transactions.dat
```

---

## Requirements

### Software Requirements

- GCC Compiler
- Linux, Windows, or macOS
- Terminal or Command Prompt

### Language

- C (C99 Standard or later)

---

## Compilation and Execution

### Linux

```bash
gcc main.c -o banking
./banking
```

### Windows (MinGW)

```bash
gcc main.c -o banking.exe
banking.exe
```

### macOS

```bash
gcc main.c -o banking
./banking
```

---

## Example Usage

### Account Creation

```text
Card Number: 123456789
Name: John Doe
PIN: 1234
Initial Balance: 5000
```

### Customer Login

```text
Card Number: 123456789
PIN: 1234
```

### Deposit

```text
Amount: 1000
```

Result:

```text
Deposit Successful
New Balance: 6000
```

### Withdrawal

```text
Amount: 500
```

Result:

```text
Withdrawal Successful
Remaining Balance: 5500
```

### Transfer

```text
Receiver Card Number: 987654321
Amount: 1000
```

Result:

```text
Transfer Successful
```

---

## Programming Concepts Demonstrated

This project applies the following concepts:

### Data Structures

- Structures
- Arrays of Structures

### Functions

- Function Prototypes
- Modular Programming
- Parameter Passing

### File Handling

- fopen()
- fclose()
- fread()
- fwrite()

### Control Structures

- Conditional Statements
- Loops
- Switch Statements

### Data Validation

- Login Authentication
- Balance Verification
- Input Validation

### Transaction Processing

- Deposit Transactions
- Withdrawal Transactions
- Fund Transfers
- Transaction Recording

---

## Limitations

The current version has the following limitations:

- No administrator authentication
- Fixed maximum number of accounts
- Fixed maximum number of transactions
- No encryption for customer PINs
- Single-user console environment
- No database integration

---

## Future Improvements

Potential enhancements include:

- Administrator Login System
- PIN Encryption and Security Features
- Date and Time Stamps for Transactions
- Interest Calculation Module
- Change PIN Functionality
- Account Locking Mechanism
- Monthly Account Statements
- Database Integration (MySQL or PostgreSQL)
- Graphical User Interface (GUI)
- Online Banking Features
- Multi-user Support

---

## Learning Outcomes

This project was developed to strengthen practical knowledge in:

- Procedural Programming
- Data Structures
- File Management
- Software Design
- Transaction Processing Systems
- Banking System Simulation
- Problem Solving Using C

---

## Author

Developed as an academic and portfolio project to demonstrate proficiency in C programming, file handling, and system design principles.
