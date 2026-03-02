#include <iostream>
#include <string>
using namespace std;

int accountNumber;
int pin;
float balance = 0;

string transactions[5];
int transactionCount = 0;

void addTransaction(string message) {
    if (transactionCount < 5) {
        transactions[transactionCount++] = message;
    } else {
        // Shift transactions left
        for (int i = 0; i < 4; i++) {
            transactions[i] = transactions[i + 1];
        }
        transactions[4] = message;
    }
}

void createAccount() {
    cout << "\nEnter Account Number: ";
    cin >> accountNumber;

    cout << "Set 4-digit PIN: ";
    cin >> pin;

    balance = 0;
    addTransaction("Account created");

    cout << "Account created successfully!\n";
}

bool verifyPin() {
    int enteredPin;
    cout << "Enter PIN: ";
    cin >> enteredPin;

    if (enteredPin == pin)
        return true;
    else {
        cout << "Incorrect PIN!\n";
        return false;
    }
}

void depositMoney() {
    if (!verifyPin()) return;

    float amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    balance += amount;
    addTransaction("Deposited: " + to_string(amount));

    cout << "Amount deposited successfully!\n";
}

void withdrawMoney() {
    if (!verifyPin()) return;

    float amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount <= balance) {
        balance -= amount;
        addTransaction("Withdrawn: " + to_string(amount));
        cout << "Please collect your cash.\n";
    } else {
        cout << "Insufficient balance!\n";
    }
}

void checkBalance() {
    if (!verifyPin()) return;

    cout << "\nAccount Number: " << accountNumber;
    cout << "\nCurrent Balance: " << balance << endl;
}

void showTransactions() {
    if (!verifyPin()) return;

    cout << "\n--- Transaction History ---\n";
    if (transactionCount == 0) {
        cout << "No transactions available.\n";
    } else {
        for (int i = 0; i < transactionCount; i++) {
            cout << i + 1 << ". " << transactions[i] << endl;
        }
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Check Balance";
        cout << "\n5. Transaction History";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                showTransactions();
                break;
            case 6:
                cout << "\nThank you for using the Bank Management System!\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}