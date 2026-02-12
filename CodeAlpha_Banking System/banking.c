#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_ACCOUNTS 100
#define FILENAME "bank_accounts.dat"

typedef struct {
    long accountno;
    char name[50];
    char email[50];
    float balance;
} Account;

void createAccount();
void deposit();
void withdraw();
void balanceEnquiry();
void displayAllAccounts();
void saveToFile(Account acc[], int n);
int loadFromFile(Account acc[]);

int main() {
    int choice;
    
    do {
        system("cls");
        printf("\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====\n");
        printf("\n----- MAIN MENU -----\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Balance Enquiry\n");
        printf("5. Display All Accounts\n");
        printf("0. Quit Program\n");
        printf("\nEnter your choice: ");
        scanf(" %d", &choice);
        
        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                balanceEnquiry();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 0:
                printf("\nThank you for using Bank Management System!\n");
                break;
            default:
                printf("\n[ERROR] Invalid choice! Please try again.\n");
        }
        
        if (choice != 0) {
            printf("\nPress any key to continue...");
            getch();
        }
        
    } while (choice != 0);
    
    return 0;
}

void createAccount() {
    system("cls");
    printf("\n===== CREATE NEW ACCOUNT =====\n");
    
    Account accounts[MAX_ACCOUNTS];
    int count = loadFromFile(accounts);
    
    if (count >= MAX_ACCOUNTS) {
        printf("\n[ERROR] Maximum number of accounts reached!\n");
        return;
    }
    
    Account acc;
    
    printf("\nEnter Account Number: ");
    scanf(" %ld", &acc.accountno);
    
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountno == acc.accountno) {
            printf("\n[ERROR] Account with this number already exists!\n");
            return;
        }
    }
    
    printf("Enter Name: ");
    char temp[20];
    fgets(temp, sizeof(temp), stdin);
    
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = 0;
    
    printf("Enter Email: ");
    fgets(acc.email, sizeof(acc.email), stdin);
    acc.email[strcspn(acc.email, "\n")] = 0;
    
    printf("Enter Initial Deposit: ");
    fgets(temp, sizeof(temp), stdin);
    acc.balance = atof(temp);
    
    if (acc.balance < 0) {
        printf("\n[ERROR] Balance cannot be negative!\n");
        return;
    }
    
    accounts[count] = acc;
    saveToFile(accounts, count + 1);
    
    printf("\n[SUCCESS] Account created successfully!\n");
}

void deposit() {
    system("cls");
    printf("\n===== DEPOSIT MONEY =====\n");
    
    Account accounts[MAX_ACCOUNTS];
    int count = loadFromFile(accounts);
    
    if (count == 0) {
        printf("\n[ERROR] No accounts found!\n");
        return;
    }
    
    long accountno;
    int found = 0;
    printf("\nEnter Account Number: ");
    scanf(" %ld", &accountno);
    getchar();
    
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountno == accountno) {
            float amount;
            char temp[20];
            
            printf("Enter Amount to Deposit: ");
            fgets(temp, sizeof(temp), stdin);
            amount = atof(temp);
            
            if (amount <= 0) {
                printf("\n[ERROR] Deposit amount must be positive!\n");
                return;
            }
            
            accounts[i].balance += amount;
            saveToFile(accounts, count);
            
            printf("\n[SUCCESS] Deposit successful!\n");
            printf("Previous Balance: %.2f\n", accounts[i].balance - amount);
            printf("Deposited Amount: %.2f\n", amount);
            printf("New Balance: %.2f\n", accounts[i].balance);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\n[ERROR] Account with number %d not found!\n", accountno);
    }
}

void withdraw() {
    system("cls");
    printf("\n===== WITHDRAW MONEY =====\n");
    
    Account accounts[MAX_ACCOUNTS];
    int count = loadFromFile(accounts);
    
    if (count == 0) {
        printf("\n[ERROR] No accounts found!\n");
        return;
    }
    
    long accountno;
    int found = 0;
    printf("\nEnter Account Number: ");
    scanf(" %ld", &accountno);
    getchar();
    
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountno == accountno) {
            float amount;
            char temp[20];
            
            printf("Enter Amount to Withdraw: ");
            fgets(temp, sizeof(temp), stdin);
            amount = atof(temp);
            
            if (amount <= 0) {
                printf("\n[ERROR] Withdrawal amount must be positive!\n");
                return;
            }
            
            if (amount > accounts[i].balance) {
                printf("\n[ERROR] Insufficient balance!\n");
                printf("Current Balance: %.2f\n", accounts[i].balance);
                return;
            }
            
            accounts[i].balance -= amount;
            saveToFile(accounts, count);
            
            printf("\n[SUCCESS] Withdrawal successful!\n");
            printf("Previous Balance: %.2f\n", accounts[i].balance + amount);
            printf("Withdrawn Amount: %.2f\n", amount);
            printf("New Balance: %.2f\n", accounts[i].balance);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\n[ERROR] Account with number %ld not found!\n", accountno);
    }
}

void balanceEnquiry() {
    system("cls");
    printf("\n===== BALANCE ENQUIRY =====\n");
    
    Account accounts[MAX_ACCOUNTS];
    int count = loadFromFile(accounts);
    
    if (count == 0) {
        printf("\n[ERROR] No accounts found!\n");
        return;
    }
    
    long accountno;
    int found = 0;
    printf("\nEnter Account Number: ");
    scanf(" %ld", &accountno);
    getchar();
    
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountno == accountno) {
            printf("\n===== ACCOUNT DETAILS =====\n");
            printf("Account Number : %ld\n", accounts[i].accountno);
            printf("Name            : %s\n", accounts[i].name);
            printf("Email           : %s\n", accounts[i].email);
            printf("Current Balance : Rs. %.2f\n", accounts[i].balance);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\n[ERROR] Account with number %ld not found!\n", accountno);
    }
}

void displayAllAccounts() {
    system("cls");
    printf("\n===== ALL BANK ACCOUNTS =====\n\n");
    
    Account accounts[MAX_ACCOUNTS];
    int count = loadFromFile(accounts);
    
    if (count == 0) {
        printf("No accounts in the system yet.\n");
        printf("Create an account to get started.\n");
        return;
    }
    
    printf("%-12s %-20s %-25s %-15s\n", "Account No", "Name", "Email", "Balance");
    printf("================================================================================\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-12ld %-20s %-25s Rs. %-15.2f\n", 
               accounts[i].accountno, 
               accounts[i].name, 
               accounts[i].email, 
               accounts[i].balance);
    }
    
    printf("================================================================================\n");
    printf("\nTotal Accounts: %d\n", count);
}

void saveToFile(Account accounts[], int count) {
    FILE *file = fopen(FILENAME, "wb");
    
    if (file == NULL) {
        printf("\n[ERROR] Couldn't save the data!\n");
        printf("Please check if you have write permissions in this directory.\n");
        return;
    }
    
    if (fwrite(&count, sizeof(int), 1, file) != 1) {
        printf("\n[WARNING] Error writing account count to file!\n");
    }
    
    if (fwrite(accounts, sizeof(Account), count, file) != count) {
        printf("\n[WARNING] Not all accounts were saved correctly!\n");
    }
    
    fclose(file);
}

int loadFromFile(Account accounts[]) {
    FILE *file = fopen(FILENAME, "rb");
    
    if (file == NULL) {
        return 0;
    }
    
    int count = 0;
    
    if (fread(&count, sizeof(int), 1, file) != 1) {
        printf("\n[WARNING] Corrupted data file. Starting with empty database.\n");
        fclose(file);
        return 0;
    }
    
    if (count < 0 || count > MAX_ACCOUNTS) {
        printf("\n[WARNING] Invalid account count in file. Starting fresh.\n");
        fclose(file);
        return 0;
    }
    
    size_t read = fread(accounts, sizeof(Account), count, file);
    if (read != count) {
        printf("\n[WARNING] Some account records may be corrupted.\n");
        count = read;
    }
    
    fclose(file);
    return count;
}
