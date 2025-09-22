#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct BankUser
{
    string AccNo;
    string Pin;
    string FullName;
    string Phone;
    double Balance;
    bool Deleted = false;
};

enum eMenuOptions {
    mQuickCash = 1, mWithdraw = 2, mDeposit = 3,
    mBalance = 4, mLogout = 5
};

const string DataFile = "Clients.txt";
BankUser ActiveUser;

void ShowATMMenu();
void StartLogin();
void QuickCashScreen();
void NormalWithdrawScreen();
void DepositScreen();

vector<string> SplitLine(string text, string delim = "#//#")
{
    vector<string> parts;
    short pos;
    string token;
    while ((pos = text.find(delim)) != string::npos) {
        token = text.substr(0, pos);
        if (!token.empty()) parts.push_back(token);
        text.erase(0, pos + delim.size());
    }
    if (!text.empty()) parts.push_back(text);
    return parts;
}

BankUser ParseUserLine(string line)
{
    vector<string> data = SplitLine(line);
    BankUser user;
    user.AccNo = data[0];
    user.Pin = data[1];
    user.FullName = data[2];
    user.Phone = data[3];
    user.Balance = stod(data[4]);
    return user;
}

string ToLine(BankUser u)
{
    return u.AccNo + "#//#" + u.Pin + "#//#" + u.FullName + "#//#" + u.Phone + "#//#" + to_string(u.Balance);
}

vector<BankUser> LoadUsers(string fileName)
{
    fstream file(fileName, ios::in);
    vector<BankUser> users;
    string line;
    while (getline(file, line)) {
        if (!line.empty())
            users.push_back(ParseUserLine(line));
    }
    file.close();
    return users;
}

void SaveUsers(string fileName, vector<BankUser> users)
{
    fstream file(fileName, ios::out);
    for (BankUser& u : users) {
        if (!u.Deleted)
            file << ToLine(u) << endl;
    }
    file.close();
}

bool FindUser(string acc, string pin, BankUser& user)
{
    vector<BankUser> users = LoadUsers(DataFile);
    for (BankUser u : users) {
        if (u.AccNo == acc && u.Pin == pin) {
            user = u;
            return true;
        }
    }
    return false;
}

bool UpdateBalance(string acc, double amount)
{
    vector<BankUser> users = LoadUsers(DataFile);
    for (BankUser& u : users) {
        if (u.AccNo == acc) {
            u.Balance += amount;
            SaveUsers(DataFile, users);
            ActiveUser.Balance = u.Balance;
            return true;
        }
    }
    return false;
}

int QuickCashAmount(short choice)
{
    int amounts[] = { 0,20,50,100,200,400,600,800,1000 };
    return (choice >= 1 && choice <= 8) ? amounts[choice] : 0;
}

void QuickCashOption()
{
    cout << "\n[1] 20  [2] 50\n[3] 100 [4] 200\n[5] 400 [6] 600\n[7] 800 [8] 1000\n[9] Cancel\n";
    cout << "\nYour balance: " << ActiveUser.Balance << "\n";
    cout << "Choose option: ";
    short c; cin >> c;
    if (c == 9) return;

    int amount = QuickCashAmount(c);
    if (amount > ActiveUser.Balance) {
        cout << "\nInsufficient balance.\n";
        system("pause>0");
        return;
    }
    UpdateBalance(ActiveUser.AccNo, -amount);
    cout << "\nWithdraw successful. New Balance = " << ActiveUser.Balance << endl;
}

void NormalWithdrawOption()
{
    int amt;
    cout << "\nEnter amount (multiples of 5): ";
    cin >> amt;
    while (amt % 5 != 0) {
        cout << "Enter valid multiple of 5: ";
        cin >> amt;
    }
    if (amt > ActiveUser.Balance) {
        cout << "\nInsufficient balance.\n";
        return;
    }
    UpdateBalance(ActiveUser.AccNo, -amt);
    cout << "\nTransaction successful. Balance = " << ActiveUser.Balance << endl;
}

void DepositOption()
{
    double amt;
    cout << "\nEnter deposit amount: ";
    cin >> amt;
    while (amt <= 0) {
        cout << "Enter positive value: ";
        cin >> amt;
    }
    UpdateBalance(ActiveUser.AccNo, amt);
    cout << "\nDeposit successful. Balance = " << ActiveUser.Balance << endl;
}

void BalanceScreen()
{
    cout << "\n=================================\n";
    cout << "Your current balance: " << ActiveUser.Balance << endl;
    cout << "=================================\n";
}

void PerformMenu(eMenuOptions op)
{
    switch (op) {
    case mQuickCash:
        system("cls"); QuickCashOption(); break;
    case mWithdraw:
        system("cls"); NormalWithdrawOption(); break;
    case mDeposit:
        system("cls"); DepositOption(); break;
    case mBalance:
        system("cls"); BalanceScreen(); break;
    case mLogout:
        StartLogin(); return;
    }
    cout << "\nPress any key to return to menu...";
    system("pause>0");
    ShowATMMenu();
}

void ShowATMMenu()
{
    system("cls");
    cout << "=========== ATM MENU ===========\n";
    cout << "[1] Quick Cash\n";
    cout << "[2] Withdraw\n";
    cout << "[3] Deposit\n";
    cout << "[4] Balance\n";
    cout << "[5] Logout\n";
    cout << "================================\n";
    cout << "Choose option [1-5]: ";
    short c; cin >> c;
    PerformMenu((eMenuOptions)c);
}

void StartLogin()
{
    string acc, pin;
    bool failed = false;
    do {
        system("cls");
        cout << "--------- Login ---------\n";
        if (failed) cout << "Invalid Account/Pin!\n";
        cout << "Account No: "; cin >> acc;
        cout << "Pin Code : "; cin >> pin;
        failed = !FindUser(acc, pin, ActiveUser);
    } while (failed);

    ShowATMMenu();
}

int main()
{
    StartLogin();
    return 0;
}
