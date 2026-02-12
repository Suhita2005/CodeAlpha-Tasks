# Bank Account Management System

A simple console-based Bank Account Management System built in C for managing bank accounts with deposit, withdrawal, and balance enquiry features.

## Features

✨ **Core Features:**
- **Create Account** - Open new bank accounts with initial deposit
- **Deposit Money** - Add funds to existing accounts
- **Withdraw Money** - Withdraw funds with balance validation
- **Balance Enquiry** - Check account details and current balance
- **View All Accounts** - Display all accounts in a formatted table

## Project Structure

```
task 4/
├── banking.c              # Main program source code
├── bank_accounts.dat      # Binary file for data persistence (auto-created)
└── README.md             # This file
```

## Data Structure

Each account record contains:
- **Account Number** - Unique identifier (integer)
- **Name** - Account holder's full name (max 50 characters)
- **Email** - Contact email address (max 50 characters)
- **Balance** - Current account balance (floating point)

## Compilation & Execution

### On Windows (using MinGW or MSVC):

```bash
gcc banking.c -o banking.exe
banking.exe
```

### On Linux/Mac:

```bash
gcc banking.c -o banking
./banking
```

## Usage Guide

### Main Menu
The program starts with an interactive menu:
```
===== BANK ACCOUNT MANAGEMENT SYSTEM =====

----- MAIN MENU -----
1. Create New Account
2. Deposit Money
3. Withdraw Money
4. Balance Enquiry
5. Display All Accounts
0. Quit Program

Enter your choice:
```

### Creating an Account
1. Select option 1 from the main menu
2. Enter a unique account number
3. Enter the account holder's name
4. Enter an email address
5. Enter initial deposit amount
6. Account is created and saved

### Depositing Money
1. Select option 2 from the main menu
2. Enter the account number
3. Enter the deposit amount
4. System confirms the transaction and shows new balance

### Withdrawing Money
1. Select option 3 from the main menu
2. Enter the account number
3. Enter the withdrawal amount
4. System validates sufficient balance
5. Transaction is processed and new balance is displayed

### Checking Balance
1. Select option 4 from the main menu
2. Enter the account number
3. System displays:
   - Account Number
   - Name
   - Email
   - Current Balance

### Viewing All Accounts
1. Select option 5 from the main menu
2. All accounts are displayed in a formatted table showing:
   - Account Number
   - Name
   - Email
   - Balance
   - Total account count

## Technical Details

### File Storage
- Account records are stored in a binary file: `bank_accounts.dat`
- The file is created automatically in the same directory as the program
- Binary format ensures data integrity and efficient storage

### Maximum Capacity
- The system can handle up to **100 accounts** (configurable via `MAX_ACCOUNTS`)

### Data Validation
- Duplicate account numbers are prevented
- Balance cannot be negative during account creation
- Withdrawal amount cannot exceed available balance
- Positive amounts are required for deposits/withdrawals
- File corruption detection with automatic recovery

## Features & Highlights

🎨 **User-Friendly Interface**
- Clear menu-driven interface
- Easy-to-understand prompts
- Success and error messages with indicators
- Transaction details display

💾 **Data Persistence**
- Binary file format for reliable data storage
- Automatic file creation on first run
- Data validation during file read/write operations
- Corrupt file recovery

⚙️ **Robust Error Handling**
- Graceful handling of missing files
- Detection and recovery from corrupted data
- User-friendly error messages
- Input validation for all operations

## Requirements

- **C Compiler** (GCC, Clang, MSVC, etc.)
- **Standard C Libraries** (stdio.h, string.h, stdlib.h, conio.h)
- **Operating System** - Windows, Linux, or Mac

## Example Workflow

1. **Start Program** → Main menu appears
2. **Create Account** → Add account 1001 with Rs. 5000
3. **Create Another Account** → Add account 1002 with Rs. 10000
4. **Deposit** → Deposit Rs. 2000 to account 1001
5. **Check Balance** → View balance of account 1001 (Rs. 7000)
6. **Withdraw** → Withdraw Rs. 1500 from account 1002
7. **View All** → See all accounts in tabular format
8. **Quit** → Exit program (data saved)

## Transaction Validation

The system validates all transactions:
- ✓ Prevents overdraft (insufficient balance)
- ✓ Requires positive amounts for deposits/withdrawals
- ✓ Prevents duplicate account numbers
- ✓ Ensures file integrity

## Notes

⚠️ **Important:**
- The program uses `fgets()` with `atof()`/`atoi()` for safe input handling
- Data is stored in binary format for security and efficiency
- Account balances are stored as floating-point numbers
- The program uses `conio.h` (Windows-specific for `getch()`)

## Future Enhancements

Possible additions:
- Transaction history
- Account statements
- Interest calculation
- Loan management
- User authentication
- Multi-currency support

## License

This project is educational and free to use.

---

**Version:** 1.0  
**Last Updated:** January 25, 2026
