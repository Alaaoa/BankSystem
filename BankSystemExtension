
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

const string FileNameClients = "Clients.txt";
const string UsersFileName = "Users.txt";

// Structures
struct ClientData
{
    string AccNum;
    string Pin;
    string FullName;
    string Mobile;
    double Balance;
    bool ToDelete = false;
};

struct stUser
{
    string UserName;
    string Password;
    int Permissions;
    bool MarkForDelete = false;
};

stUser CurrentUser;

enum enMainMenuPermissions
{
    eAllPermissions = -1, // full access to everything

    pListClients = 1,     // 0000001
    pAddClient = 2,       // 0000010
    pDeleteClient = 4,    // 0000100
    pUpdateClients = 8,   // 0001000
    pFindClient = 16,     // 0010000
    pDoTransactions = 32, // 0100000
    pManageUsers = 64     // 1000000
};

// Function Prototypes
void ShowMainMenu();
void SaveUsersToFile(string FileName, vector<stUser> vUsers);
void ShowTransactionMenu();
vector<string> SplitText(string text, string delimiter);
ClientData LineToClient(string line, string delimiter = "#//#");
string ClientToLine(ClientData client);
bool AccountExists(string accNum, string fileName);
ClientData GetNewClient();
vector<ClientData> LoadClientsFromFile(string fileName);
void DisplayClientRow(ClientData client);
void DisplayClientBalanceRow(ClientData client);
void DisplayClientCard(ClientData client);
bool FindClientByAcc(string accNum, vector<ClientData> clients, ClientData& client);
ClientData UpdateClientRecord(string accNum);
bool MarkClientForDeletion(string accNum, vector<ClientData>& clients);
vector<ClientData> SaveClientsToFile(string fileName, vector<ClientData> clients);
void AppendDataToFile(string fileName, string clientLine);
void AddClient();
void AddMultipleClients();
int ReadPermissions();
bool DeleteClient(string accNum, vector<ClientData>& clients);
bool UpdateClient(string accNum, vector<ClientData>& clients);
bool DepositToClient(string accNum, double amount, vector<ClientData>& clients);
string AskClientAcc();
void ShowAllClients();
void ShowAllBalances();
bool FindUserByUserName(string UserName, vector<stUser> users, stUser& UserToUpdate);
void ShowDepositScreen();
void ShowWithdrawScreen();
void ShowDeleteClientScreen();
void ShowUpdateClientScreen();
void ShowAddClientScreen();
void ShowFindClientScreen();
void ShowEndScreen();
void GoBackToMainMenu();
void GoBackToTransactionMenu();
short ReadMainMenuOption();
short ReadTransactionMenuOption();
void ExecuteMainMenuOption(short option);
void ExecuteTransactionMenuOption(short option);
vector<stUser> LoadUsersFromFile(string FileName);

void DeniedMessage()
{
    cout << "\n------------------------------------\n";
    cout << "Access Denied, \nYou dont Have Permission .";
    cout << "\n------------------------------------\n";
}

bool HasPermission(int UserPermissions, enMainMenuPermissions RequiredPermission)
{
    if (UserPermissions == eAllPermissions)
        return true;

    return (UserPermissions & RequiredPermission) == RequiredPermission;
}

int GetUserPermissionsFromFile(string FileName, string UserName)
{
    fstream MyFile(FileName, ios::in);
    if (!MyFile.is_open())
    {
        cerr << "\n❌ Error: Could not open users file.\n";
        return 0; // No permissions
    }

    string Line;
    while (getline(MyFile, Line))
    {
        vector<string> vData = SplitText(Line, "#//#");
        // Assuming format: Username#//#Password#//#Permissions

        if (vData.size() >= 3 && vData[0] == UserName)
        {
            MyFile.close();
            return stoi(vData[2]); // Permission number
        }
    }

    MyFile.close();
    return 0; // User not found → No permissions
}

bool DeleteUserByUsername(string UserName, vector<stUser>& vUsers)
{
    for (stUser& U : vUsers)
    {
        if (U.UserName == UserName)
        {
            char Confirm = 'n';
            cout << "\nAre you sure you want to delete this user ["
                << U.UserName << "] ? (y/n): ";
            cin >> Confirm;

            if (Confirm == 'y' || Confirm == 'Y')
            {
                U.MarkForDelete = true;
                SaveUsersToFile(UsersFileName, vUsers);
                cout << "\n✅ User [" << U.UserName << "] deleted successfully.\n";
                vUsers = LoadUsersFromFile(UsersFileName);
                return true;
            }
            else
            {
                cout << "\n❌ Delete operation cancelled.\n";
                return false;
            }
        }
    }

    cout << "\n⚠️ User not found.\n";
    return false;
}

bool UpdateUserByUserName(string UserName, vector<stUser>& vUsers)
{
    for (stUser& U : vUsers)
    {
        if (U.UserName == UserName)
        {
            char Confirm = 'n';
            cout << "\nAre you sure you want to delete this user ["
                << U.UserName << "] ? (y/n): ";
            cin >> Confirm;

            if (Confirm == 'y' || Confirm == 'Y')
            {
                cout << "Enter Password: ";
                cin >> U.Password;
                cout << "Enter Password: ";
                cin >> U.Password;

                U.Permissions = ReadPermissions();

                SaveUsersToFile(UsersFileName, vUsers);
                cout << "\n✅ User [" << U.UserName << "] updated successfully.\n";
                vUsers = LoadUsersFromFile(UsersFileName);
                return true;
            }
            else
            {
                cout << "\n❌ Delete operation cancelled.\n";
                return false;
            }
        }
    }
}

void ShowUpdateUserScreen()
{
    system("cls");

    cout << "===========================================\n";
    cout << "\t     Update User Screen\n";
    cout << "===========================================\n";

    vector<stUser> vUsers = LoadUsersFromFile(UsersFileName);

    string UserName;
    stUser updatedUser;
    cout << "\nEnter Username to update: ";
    cin >> UserName;
    while (!FindUserByUserName(UserName, vUsers, updatedUser))
    {
        cout << "\n User with [" << UserName << "] does not exist.\n";
        cout << "\nEnter Username to delete: ";
        cin >> UserName;
    }

    UpdateUserByUserName(UserName, vUsers);
}

void ShowDeleteUserScreen()
{
    system("cls");

    cout << "===========================================\n";
    cout << "\t     Delete User Screen\n";
    cout << "===========================================\n";

    vector<stUser> vUsers = LoadUsersFromFile(UsersFileName);

    string UserName;
    cout << "\nEnter Username to delete: ";
    cin >> UserName;

    DeleteUserByUsername(UserName, vUsers);
}

void PerfromManageUsersMenueOption(int Number);

// Function Definitions

int ReadPermissions()
{
    int Permissions = 0;
    char Answer = 'n';

    cout << "\nSet user permissions:\n";

    cout << "Grant full access? (y/n): ";
    cin >> Answer;

    if (tolower(Answer) == 'y')
        return enMainMenuPermissions::eAllPermissions;

    cout << "Allow List Clients? (y/n): ";
    cin >> Answer;
    if (tolower(Answer) == 'y')
        Permissions |= enMainMenuPermissions::pListClients;

    cout << "Allow Add Client? (y/n): ";
    cin >> Answer;
    if (tolower(Answer) == 'y')
        Permissions |= enMainMenuPermissions::pAddClient;

    cout << "Allow Delete Client? (y/n): ";
    cin >> Answer;
    if (tolower(Answer) == 'y')
        Permissions |= enMainMenuPermissions::pDeleteClient;

    cout << "Allow Update Clients? (y/n): ";
    cin >> Answer;
    if (tolower(Answer) == 'y')
        Permissions |= enMainMenuPermissions::pUpdateClients;

    cout << "Allow Find Client? (y/n): ";
    cin >> Answer;
    if (tolower(Answer) == 'y')
        Permissions |= enMainMenuPermissions::pFindClient;

    cout << "Allow Transactions? (y/n): ";
    cin >> Answer;
    if (tolower(Answer) == 'y')
        Permissions |= enMainMenuPermissions::pDoTransactions;

    cout << "Allow Manage Users? (y/n): ";
    cin >> Answer;
    if (tolower(Answer) == 'y')
        Permissions |= enMainMenuPermissions::pManageUsers;

    return Permissions;
}

string BuildUserRecord(stUser User, string Sep = "#//#")
{
    string Record = "";
    Record += User.UserName + Sep;
    Record += User.Password + Sep;
    Record += to_string(User.Permissions);
    return Record;
}

void PrintUserRecordLine(stUser User)
{

    cout << "\nThe details of the requested user is :\n";
    cout << "-----------------------------------";
    cout << "\nUsername    : " << User.UserName;
    cout << "\nPassword    : " << User.Password;
    cout << "\nPermissions : " << User.Permissions;
    cout << "\n-----------------------------------\n";
}

void ShowListUsersScreen()
{

    // HasPermission()

    vector<stUser> vUsers = LoadUsersFromFile(UsersFileName);

    cout << "\n\t\t\t\t\tUser List Screen (" << vUsers.size() << ") User(s).\n";
    cout << "________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(25) << "Username";
    cout << "| " << left << setw(25) << "Password";
    cout << "| " << left << setw(12) << "Permissions";
    cout << "\n________________________________________________________________________________________________\n\n";

    if (vUsers.empty())
    {
        cout << "\t\t\t\tNo Users Available In the System!\n";
    }
    else
    {
        for (stUser& User : vUsers)
        {
            cout << "| " << left << setw(25) << User.UserName;
            cout << "| " << left << setw(25) << User.Password;
            cout << "| " << left << setw(12) << User.Permissions;
            cout << endl;
        }
    }

    cout << "________________________________________________________________________________________________\n";
}

stUser ReadNewUserFromInput()
{
    stUser User;

    cout << "Enter Username: ";
    cin >> User.UserName;

    cout << "Enter Password: ";
    cin >> User.Password;

    User.Permissions = ReadPermissions();

    return User;
}

void ShowManageUsersMenue()
{
    if (!HasPermission(GetUserPermissionsFromFile(UsersFileName, CurrentUser.UserName), enMainMenuPermissions::pManageUsers))
    {
        DeniedMessage();
        return;
    }
    system("cls");

    cout << "===========================================\n";
    cout << "\t   Manage Users Menu\n";
    cout << "===========================================\n";
    cout << "[1] List Users\n";
    cout << "[2] Add New User\n";
    cout << "[3] Delete User\n";
    cout << "[4] Update User\n";
    cout << "[5] Find User\n";
    cout << "[6] Back To Main Menu\n";
    cout << "===========================================\n";

    cout << "Choose an option [1 to 6]: ";
    short Choice = 0;
    cin >> Choice;

    // validate input
    while (Choice < 1 || Choice > 6)
    {
        cout << "Invalid choice, please enter a number between 1 and 6: ";
        cin >> Choice;
    }

    PerfromManageUsersMenueOption(Choice);
}

void GoBackUsersMenue()
{
    cout << "Press any key to go back to ManageUser Menu...";
    system("pause>0");
    ShowManageUsersMenue();
}

void ShowAddNewUserScreen()
{
    system("cls");

    cout << "===========================================\n";
    cout << "\t     Add New User Screen\n";
    cout << "===========================================\n";

    stUser NewUser = ReadNewUserFromInput();
    AppendDataToFile(UsersFileName, BuildUserRecord(NewUser));

    // save

    cout << "\n✅ User [" << NewUser.UserName << "] added successfully with permissions: "
        << NewUser.Permissions << endl;
}

void ShowFindUserScreen()
{
    system("cls");

    cout << "===========================================\n";
    cout << "\t     Find User Screen\n";
    cout << "===========================================\n";

    vector<stUser> vUsers = LoadUsersFromFile(UsersFileName);

    string UserName;
    cout << "\nEnter Username to Show: ";
    cin >> UserName;

    stUser UserTofind;

    while (!FindUserByUserName(UserName, vUsers, UserTofind))
    {
        cout << "\n User with [" << UserName << "] does not exist.\n";
        cout << "\nEnter Username to find: ";
        cin >> UserName;
    }
    PrintUserRecordLine(UserTofind);
}

void PerfromManageUsersMenueOption(int Number)
{
    switch (Number)
    {
    case 1:
    {
        system("cls");
        ShowListUsersScreen();
        GoBackUsersMenue();
        system("pause>0");
        break;
    }

    case 2:
    {
        system("cls");
        ShowAddNewUserScreen();
        GoBackUsersMenue();
        break;
    }

    case 3:
    {
        system("cls");
        ShowDeleteUserScreen();
        GoBackUsersMenue();
        break;
    }

    case 4:
    {
        system("cls");
        ShowUpdateUserScreen();
        GoBackUsersMenue();
        break;
    }

    case 5:
    {
        system("cls");
        ShowFindUserScreen();
        GoBackUsersMenue();
        break;
    }

    case 6:
    {
        ShowMainMenu();
        break;
    }
    }
}

string ConvertUserToLine(stUser User, string Seperator = "#//#")
{
    string Record = "";
    Record += User.UserName + Seperator;
    Record += User.Password + Seperator;
    Record += to_string(User.Permissions);
    return Record;
}

stUser ParseUserRecord(string Line, string Sep = "#//#")
{
    stUser User;
    vector<string> Data = SplitText(Line, Sep);

    User.UserName = Data[0];
    User.Password = Data[1];
    User.Permissions = stoi(Data[2]);

    return User;
}

vector<string> SplitText(string text, string delimiter)
{
    vector<string> result;
    short pos;
    string token;
    while ((pos = text.find(delimiter)) != string::npos)
    {
        token = text.substr(0, pos);
        if (!token.empty())
            result.push_back(token);
        text.erase(0, pos + delimiter.length());
    }
    if (!text.empty())
        result.push_back(text);
    return result;
}

vector<stUser> LoadUsersFromFile(string FileName)
{
    vector<stUser> vUsers;
    fstream File(FileName, ios::in);
    string Line;

    while (getline(File, Line))
    {
        if (Line != "")
            vUsers.push_back(ParseUserRecord(Line));
    }

    File.close();
    return vUsers;
}

void SaveUsersToFile(string FileName, vector<stUser> vUsers)
{
    fstream File(FileName, ios::out);
    for (stUser User : vUsers)
    {
        if (!User.MarkForDelete)
            File << BuildUserRecord(User) << endl;
    }
    File.close();
}

void PrintUser(stUser User)
{
    cout << "\nUser Info:\n";
    cout << "Username: " << User.UserName << endl;
    cout << "Password: " << User.Password << endl;
    cout << "Permissions: " << User.Permissions << endl;
    cout << "--------------------------------------\n";
}

ClientData LineToClient(string line, string delimiter)
{
    vector<string> data = SplitText(line, delimiter);
    ClientData c;
    c.AccNum = data[0];
    c.Pin = data[1];
    c.FullName = data[2];
    c.Mobile = data[3];
    c.Balance = stod(data[4]);
    return c;
}

string ClientToLine(ClientData c)
{
    string line = "";
    string delimiter = "#//#";
    line += c.AccNum + delimiter;
    line += c.Pin + delimiter;
    line += c.FullName + delimiter;
    line += c.Mobile + delimiter;
    line += to_string(c.Balance);
    return line;
}

bool CheckUserCredentials(string Username, string Password, stUser& User)
{
    vector<stUser> vUsers = LoadUsersFromFile(UsersFileName);

    for (stUser u : vUsers)
    {
        if (u.UserName == Username && u.Password == Password)
        {
            User = u;
            return true;
        }
    }
    return false;
}

bool Login()
{
    string Username, Password;
    bool Success = false;

    cout << "\n=========== Login Screen ===========\n";

    for (int i = 0; i < 3; i++) // allow up to 3 tries
    {
        cout << "Enter Username: ";
        cin >> Username;
        cout << "Enter Password: ";
        cin >> Password;

        if (CheckUserCredentials(Username, Password, CurrentUser))
        {
            Success = true;

            ShowMainMenu();
            break;
        }
        else
        {
            cout << "Invalid login, please try again.\n";
        }
    }

    return Success;
}

bool AccountExists(string accNum, string fileName)
{
    fstream file(fileName, ios::in);
    if (!file.is_open())
        return false;

    string line;
    ClientData c;
    while (getline(file, line))
    {
        c = LineToClient(line);
        if (c.AccNum == accNum)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

ClientData GetNewClient()
{
    ClientData c;
    cout << "Enter Account Number? ";
    getline(cin >> ws, c.AccNum);
    while (AccountExists(c.AccNum, FileNameClients))
    {
        cout << "\nClient with [" << c.AccNum << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, c.AccNum);
    }
    cout << "Enter PinCode? ";
    getline(cin, c.Pin);
    cout << "Enter Name? ";
    getline(cin, c.FullName);
    cout << "Enter Phone? ";
    getline(cin, c.Mobile);
    cout << "Enter Balance? ";
    cin >> c.Balance;
    return c;
}

vector<ClientData> LoadClientsFromFile(string fileName)
{
    vector<ClientData> clients;
    fstream file(fileName, ios::in);
    if (file.is_open())
    {
        string line;
        ClientData c;
        while (getline(file, line))
        {
            c = LineToClient(line);
            clients.push_back(c);
        }
        file.close();
    }
    return clients;
}

void DisplayClientRow(ClientData c)
{
    cout << "| " << setw(15) << left << c.AccNum;
    cout << "| " << setw(10) << left << c.Pin;
    cout << "| " << setw(40) << left << c.FullName;
    cout << "| " << setw(12) << left << c.Mobile;
    cout << "| " << setw(12) << left << c.Balance;
}

void DisplayClientBalanceRow(ClientData c)
{
    cout << "| " << setw(15) << left << c.AccNum;
    cout << "| " << setw(40) << left << c.FullName;
    cout << "| " << setw(12) << left << c.Balance;
}

void DisplayClientCard(ClientData c)
{
    cout << "\nClient Details:\n";
    cout << "-----------------------------------";
    cout << "\nAccount Number: " << c.AccNum;
    cout << "\nPin Code      : " << c.Pin;
    cout << "\nName          : " << c.FullName;
    cout << "\nPhone         : " << c.Mobile;
    cout << "\nBalance       : " << c.Balance;
    cout << "\n-----------------------------------\n";
}

bool FindClientByAcc(string accNum, vector<ClientData> clients, ClientData& c)
{
    for (ClientData cl : clients)
    {
        if (cl.AccNum == accNum)
        {
            c = cl;
            return true;
        }
    }
    return false;
}

bool FindUserByUserName(string UserName, vector<stUser> users, stUser& UserToUpdate)
{
    for (stUser c : users)
    {
        if (c.UserName == UserName)
        {
            UserToUpdate = c;
            return true;
        }
    }
    return false;
}

ClientData UpdateClientRecord(string accNum)
{
    ClientData c;
    c.AccNum = accNum;
    cout << "\nEnter PinCode? ";
    getline(cin >> ws, c.Pin);
    cout << "Enter Name? ";
    getline(cin, c.FullName);
    cout << "Enter Phone? ";
    getline(cin, c.Mobile);
    cout << "Enter Balance? ";
    cin >> c.Balance;
    return c;
}

bool MarkClientForDeletion(string accNum, vector<ClientData>& clients)
{
    for (ClientData& c : clients)
    {
        if (c.AccNum == accNum)
        {
            c.ToDelete = true;
            return true;
        }
    }
    return false;
}

vector<ClientData> SaveClientsToFile(string fileName, vector<ClientData> clients)
{
    fstream file(fileName, ios::out);
    if (file.is_open())
    {
        string line;
        for (ClientData c : clients)
        {
            if (!c.ToDelete)
            {
                line = ClientToLine(c);
                file << line << endl;
            }
        }
        file.close();
    }
    return clients;
}

void AppendDataToFile(string fileName, string clientLine)
{
    fstream file(fileName, ios::out | ios::app);
    if (file.is_open())
    {
        file << clientLine << endl;
        file.close();
    }
}

void AddClient()
{
    ClientData c = GetNewClient();
    AppendDataToFile(FileNameClients, ClientToLine(c));
}

void AddMultipleClients()
{
    char choice = 'Y';
    do
    {
        cout << "Adding New Client:\n";
        AddClient();
        cout << "\nClient Added Successfully, add more? (Y/N): ";
        cin >> choice;
    } while (toupper(choice) == 'Y');
}

bool DeleteClient(string accNum, vector<ClientData>& clients)
{
    ClientData c;
    char choice = 'n';
    if (FindClientByAcc(accNum, clients, c))
    {
        DisplayClientCard(c);
        cout << "Are you sure you want to delete this client? (y/n): ";
        cin >> choice;
        if (tolower(choice) == 'y')
        {
            MarkClientForDeletion(accNum, clients);
            SaveClientsToFile(FileNameClients, clients);
            clients = LoadClientsFromFile(FileNameClients);
            cout << "\nClient deleted successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "\nClient not found!\n";
        return false;
    }
    return true;
}

bool UpdateClient(string accNum, vector<ClientData>& clients)
{
    ClientData c;
    char choice = 'n';
    if (FindClientByAcc(accNum, clients, c))
    {
        DisplayClientCard(c);
        cout << "\nUpdate this client? (y/n): ";
        cin >> choice;
        if (tolower(choice) == 'y')
        {
            for (ClientData& cl : clients)
            {
                if (cl.AccNum == accNum)
                {
                    cl = UpdateClientRecord(accNum);
                    break;
                }
            }
            SaveClientsToFile(FileNameClients, clients);
            cout << "\nClient updated successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "\nClient not found!\n";
        return false;
    }
    return true;
}

bool DepositToClient(string accNum, double amount, vector<ClientData>& clients)
{
    char choice = 'n';
    cout << "\nAre you sure to perform this transaction? (y/n): ";
    cin >> choice;
    if (tolower(choice) == 'y')
    {
        for (ClientData& c : clients)
        {
            if (c.AccNum == accNum)
            {
                c.Balance += amount;
                SaveClientsToFile(FileNameClients, clients);
                cout << "\nTransaction completed. New Balance: " << c.Balance << endl;
                return true;
            }
        }
        return false;
    }
    return true;
}

string AskClientAcc()
{
    string acc;
    cout << "\nEnter Account Number? ";
    cin >> acc;
    return acc;
}

void ShowAllClients()

{

    if (!HasPermission(GetUserPermissionsFromFile(UsersFileName, CurrentUser.UserName), enMainMenuPermissions::eAllPermissions))
    {
        DeniedMessage();
        return;
    }

    vector<ClientData> clients = LoadClientsFromFile(FileNameClients);
    cout << "\nClient List (" << clients.size() << " clients)\n";
    cout << "---------------------------------------------------------------\n";
    cout << "| " << left << setw(15) << "Account No";
    cout << "| " << left << setw(10) << "Pin";
    cout << "| " << left << setw(40) << "Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance\n";
    cout << "---------------------------------------------------------------\n";
    for (ClientData c : clients)
    {
        DisplayClientRow(c);
        cout << endl;
    }
    cout << "---------------------------------------------------------------\n";
}

void ShowAllBalances()
{
    vector<ClientData> clients = LoadClientsFromFile(FileNameClients);
    double total = 0;
    cout << "\nBalance List (" << clients.size() << " clients)\n";
    cout << "---------------------------------------------------------------\n";
    cout << "| " << left << setw(15) << "Account No";
    cout << "| " << left << setw(40) << "Name";
    cout << "| " << left << setw(12) << "Balance\n";
    cout << "---------------------------------------------------------------\n";
    for (ClientData c : clients)
    {
        DisplayClientBalanceRow(c);
        total += c.Balance;
        cout << endl;
    }
    cout << "---------------------------------------------------------------\n";
    cout << "Total Balance = " << total << endl;
}

// Transaction Screens
void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen\n";
    cout << "-----------------------------------\n";

    vector<ClientData> clients = LoadClientsFromFile(FileNameClients);
    ClientData client;
    string accNum = AskClientAcc();

    while (!FindClientByAcc(accNum, clients, client))
    {
        cout << "\nClient with [" << accNum << "] does not exist.\n";
        accNum = AskClientAcc();
    }

    DisplayClientCard(client);

    double amount = 0;
    cout << "\nEnter deposit amount? ";
    cin >> amount;

    DepositToClient(accNum, amount, clients);
}

void ShowWithdrawScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen\n";
    cout << "-----------------------------------\n";

    vector<ClientData> clients = LoadClientsFromFile(FileNameClients);
    ClientData client;
    string accNum = AskClientAcc();

    while (!FindClientByAcc(accNum, clients, client))
    {
        cout << "\nClient with [" << accNum << "] does not exist.\n";
        accNum = AskClientAcc();
    }

    DisplayClientCard(client);

    double amount = 0;
    cout << "\nEnter withdraw amount? ";
    cin >> amount;

    while (amount > client.Balance)
    {
        cout << "\nAmount exceeds balance (" << client.Balance << "). Enter another amount: ";
        cin >> amount;
    }

    DepositToClient(accNum, -amount, clients);
}

// Menu Navigation
void GoBackToMainMenu()
{
    cout << "\nPress any key to return to Main Menu...";
    system("pause>0");
    ShowMainMenu();
}

void GoBackToTransactionMenu()
{
    cout << "\nPress any key to return to Transaction Menu...";
    system("pause>0");
    ShowTransactionMenu();
}

// Menu Options Reading
short ReadMainMenuOption()
{
    cout << "Choose an option [1-7]: ";
    short choice;
    cin >> choice;
    return choice;
}

short ReadTransactionMenuOption()
{
    cout << "Choose an option [1-4]: ";
    short choice;
    cin >> choice;
    return choice;
}

// Execute Menu Options
void ExecuteMainMenuOption(short option)
{
    switch (option)
    {
    case 1:
        system("cls");
        ShowAllClients();
        GoBackToMainMenu();
        break;
    case 2:
        system("cls");
        ShowAddClientScreen();
        GoBackToMainMenu();
        break;
    case 3:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenu();
        break;
    case 4:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenu();
        break;
    case 5:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenu();
        break;
    case 6:
        system("cls");
        ShowTransactionMenu();
        GoBackToMainMenu();
        break;
    case 7:
        system("cls");
        ShowManageUsersMenue();
        GoBackToMainMenu();
        break;
    case 8:
        system("cls");
        ShowEndScreen();
        Login();

        break;
    }
}

void ExecuteTransactionMenuOption(short option)
{
    switch (option)
    {
    case 1:
        system("cls");
        ShowDepositScreen();
        GoBackToTransactionMenu();
        break;
    case 2:
        system("cls");
        ShowWithdrawScreen();
        GoBackToTransactionMenu();
        break;
    case 3:
        system("cls");
        ShowAllBalances();
        GoBackToTransactionMenu();
        break;
    case 4:
        ShowMainMenu();
        break;
    }
}

// Screens
void ShowMainMenu()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menu\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List\n";
    cout << "\t[2] Add New Client\n";
    cout << "\t[3] Delete Client\n";
    cout << "\t[4] Update Client Info\n";
    cout << "\t[5] Find Client\n";
    cout << "\t[6] Transactions\n";
    cout << "\t[7] ManageUser\n";
    cout << "\t[8] Logout\n";
    cout << "===========================================\n";

    ExecuteMainMenuOption(ReadMainMenuOption());
}

void ShowTransactionMenu()
{

    if (!HasPermission(GetUserPermissionsFromFile(UsersFileName, CurrentUser.UserName), enMainMenuPermissions::pDoTransactions))
    {
        DeniedMessage();
        return;
    }

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tTransaction Menu\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit\n";
    cout << "\t[2] Withdraw\n";
    cout << "\t[3] Show Total Balances\n";
    cout << "\t[4] Main Menu\n";
    cout << "===========================================\n";

    ExecuteTransactionMenuOption(ReadTransactionMenuOption());
}

// Other Screens
void ShowAddClientScreen()
{
    if (!HasPermission(GetUserPermissionsFromFile(UsersFileName, CurrentUser.UserName), enMainMenuPermissions::pAddClient))
    {
        DeniedMessage();
        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Client\n";
    cout << "-----------------------------------\n";
    AddMultipleClients();
}

void ShowDeleteClientScreen()
{
    if (!HasPermission(GetUserPermissionsFromFile(UsersFileName, CurrentUser.UserName), enMainMenuPermissions::pDeleteClient))
    {
        DeniedMessage();
        return;
    }
    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client\n";
    cout << "-----------------------------------\n";

    vector<ClientData> clients = LoadClientsFromFile(FileNameClients);
    string accNum = AskClientAcc();
    DeleteClient(accNum, clients);
}

void ShowUpdateClientScreen()
{
    if (!HasPermission(GetUserPermissionsFromFile(UsersFileName, CurrentUser.UserName), enMainMenuPermissions::pUpdateClients))
    {
        DeniedMessage();
        return;
    }
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info\n";
    cout << "-----------------------------------\n";

    vector<ClientData> clients = LoadClientsFromFile(FileNameClients);
    string accNum = AskClientAcc();
    UpdateClient(accNum, clients);
}

void ShowFindClientScreen()
{
    if (!HasPermission(GetUserPermissionsFromFile(UsersFileName, CurrentUser.UserName), enMainMenuPermissions::pFindClient))
    {
        DeniedMessage();
        return;
    }
    cout << "\n-----------------------------------\n";
    cout << "\tFind Client\n";
    cout << "-----------------------------------\n";

    vector<ClientData> clients = LoadClientsFromFile(FileNameClients);
    string accNum = AskClientAcc();
    ClientData client;

    if (FindClientByAcc(accNum, clients, client))
        DisplayClientCard(client);
    else
        cout << "\nClient with Account Number [" << accNum << "] not found!\n";
}

void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tLogout :-)\n";
    cout << "-----------------------------------\n";
}

// Main
int main()
{
    Login();
    // ShowMainMenu();

    system("pause>0");
    return 0;
}
