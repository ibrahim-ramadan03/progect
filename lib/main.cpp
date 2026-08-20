#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

//==================================================
// Account
//==================================================

class Account
{
private:

    int accountNumber;
    string ownerName;
    int pin;
    double balance;

public:

    // Constructor افتراضي
    Account()
    {
        accountNumber = 0;
        ownerName = "";
        pin = 0;
        balance = 0;
    }


    // Constructor كامل
    Account(int number, string name, int pin, double balance)
    {
        this->accountNumber = number;
        this->ownerName = name;
        this->pin = pin;
        this->balance = balance;
    }


    // إدخال بيانات الحساب
    void input()
    {
        cout << "Enter account number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter owner name: ";
        getline(cin, ownerName);

        cout << "Enter PIN: ";
        cin >> pin;

        cout << "Enter initial balance: ";
        cin >> balance;

        while (balance < 0)
        {
            cout << "Balance cannot be negative.\n";
            cout << "Enter initial balance: ";
            cin >> balance;
        }
    }


    // عرض بيانات الحساب
    void display()
    {
        cout << "-------------------------\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Owner Name     : " << ownerName << endl;
        cout << "Balance        : "
             << fixed << setprecision(2)
             << balance << endl;
        cout << "-------------------------\n";
    }


    // إرجاع رقم الحساب
    int getAccountNumber()
    {
        return accountNumber;
    }


    // إرجاع اسم صاحب الحساب
    string getOwnerName()
    {
        return ownerName;
    }


    // إرجاع الرصيد
    double getBalance()
    {
        return balance;
    }


    // التحقق من PIN
    bool checkPin(int enteredPin)
    {
        return pin == enteredPin;
    }


    // إيداع مبلغ
    bool deposit(double amount)
    {
        if (amount <= 0)
        {
            return false;
        }

        balance += amount;

        return true;
    }


    // سحب مبلغ
    bool withdraw(double amount)
    {
        if (amount <= 0)
        {
            return false;
        }

        if (amount > balance)
        {
            return false;
        }

        balance -= amount;

        return true;
    }
};


//==================================================
// ATM
//==================================================

class ATM
{
private:

    vector<Account> accounts;


    // البحث عن حساب وإرجاع مؤشر إليه
    Account* findAccount(int accountNumber)
    {
        for (auto &account : accounts)
        {
            if (account.getAccountNumber() == accountNumber)
            {
                return &account;
            }
        }

        return nullptr;
    }


public:

    // إضافة حساب جديد
    void addAccount()
    {
        Account account;

        account.input();

        // التأكد أن رقم الحساب غير مستخدم
        if (findAccount(account.getAccountNumber()) != nullptr)
        {
            cout << "\nAccount number already exists!\n";
            return;
        }

        accounts.push_back(account);

        cout << "\nAccount created successfully.\n";
    }


    // عرض جميع الحسابات
    void displayAccounts()
    {
        if (accounts.empty())
        {
            cout << "\nNo accounts available.\n";
            return;
        }

        for (auto &account : accounts)
        {
            account.display();
        }
    }


    // تسجيل الدخول
    Account* login()
    {
        int accountNumber;
        int enteredPin;

        cout << "\nEnter account number: ";
        cin >> accountNumber;

        Account* account = findAccount(accountNumber);

        if (account == nullptr)
        {
            cout << "Account not found.\n";
            return nullptr;
        }

        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (!account->checkPin(enteredPin))
        {
            cout << "Incorrect PIN.\n";
            return nullptr;
        }

        cout << "\nLogin successful.\n";
        cout << "Welcome, " << account->getOwnerName() << "!\n";

        return account;
    }


    // عرض الرصيد
    void checkBalance(Account* account)
    {
        cout << "\nCurrent balance: "
             << fixed << setprecision(2)
             << account->getBalance()
             << endl;
    }


    // إيداع
    void depositMoney(Account* account)
    {
        double amount;

        cout << "\nEnter amount to deposit: ";
        cin >> amount;

        if (account->deposit(amount))
        {
            cout << "Deposit successful.\n";

            cout << "New balance: "
                 << fixed << setprecision(2)
                 << account->getBalance()
                 << endl;
        }
        else
        {
            cout << "Invalid amount.\n";
        }
    }


    // سحب
    void withdrawMoney(Account* account)
    {
        double amount;

        cout << "\nEnter amount to withdraw: ";
        cin >> amount;

        if (account->withdraw(amount))
        {
            cout << "Withdrawal successful.\n";

            cout << "Remaining balance: "
                 << fixed << setprecision(2)
                 << account->getBalance()
                 << endl;
        }
        else
        {
            cout << "Withdrawal failed.\n";
            cout << "Check the amount or your balance.\n";
        }
    }


    // قائمة عمليات الحساب بعد تسجيل الدخول
    void accountMenu(Account* account)
    {
        int choice;

        do
        {
            cout << "\n================================\n";
            cout << "        ACCOUNT MENU\n";
            cout << "================================\n";

            cout << "1. Check Balance\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "0. Logout\n";

            cout << "Choose: ";
            cin >> choice;


            switch (choice)
            {
            case 1:

                checkBalance(account);

                break;


            case 2:

                depositMoney(account);

                break;


            case 3:

                withdrawMoney(account);

                break;


            case 0:

                cout << "Logged out.\n";

                break;


            default:

                cout << "Invalid choice.\n";
            }

        } while (choice != 0);
    }


    // القائمة الرئيسية
    void menu()
    {
        int choice;

        do
        {
            cout << "\n================================\n";
            cout << "          ATM SYSTEM\n";
            cout << "================================\n";

            cout << "1. Create Account\n";
            cout << "2. Display Accounts\n";
            cout << "3. Login\n";
            cout << "0. Exit\n";

            cout << "Choose: ";
            cin >> choice;


            switch (choice)
            {
            case 1:

                addAccount();

                break;


            case 2:

                displayAccounts();

                break;


            case 3:
            {
                Account* account = login();

                if (account != nullptr)
                {
                    accountMenu(account);
                }

                break;
            }


            case 0:

                cout << "Goodbye!\n";

                break;


            default:

                cout << "Invalid choice.\n";
            }

        } while (choice != 0);
    }
};


//==================================================
// Main
//==================================================

int main()
{
    ATM atm;

    atm.menu();

    return 0;
}