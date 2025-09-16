//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <iomanip>
//using namespace std;
//const string ClientsFileName = "NEWFILE.txt";
//void ShowMainMenue();
//void ShowTransactionsMenue();
//struct sClient
//{
//	string AccountNumber;
//	string PinCode;
//	string Name;
//	string Phone;
//	double AccountBalance;
//	bool MarkForDelete = false;
//};
//
//vector<string> SplitString(string S1, string Delim)
//{
//	vector<string> vString;
//	short pos = 0;
//	string sWord;
//	while ((pos = S1.find(Delim)) != std::string::npos)
//	{
//		sWord = S1.substr(0, pos);
//		if (sWord != "")
//		{
//			vString.push_back(sWord);
//		}
//		S1.erase(0, pos + Delim.length());
//	}
//	if (S1 != "")
//	{
//		vString.push_back(S1);
//	}
//	return vString;
//}
//
//sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
//{
//	sClient Client;
//	vector<string> vClientData;
//	vClientData = SplitString(Line, Seperator);
//	Client.AccountNumber = vClientData[0];
//	Client.PinCode = vClientData[1];
//	Client.Name = vClientData[2];
//	Client.Phone = vClientData[3];
//	Client.AccountBalance = stod(vClientData[4]);
//	return Client;
//}
//string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
//{
//	string stClientRecord = "";
//	stClientRecord += Client.AccountNumber + Seperator;
//	stClientRecord += Client.PinCode + Seperator;
//	stClientRecord += Client.Name + Seperator;
//	stClientRecord += Client.Phone + Seperator;
//	stClientRecord += to_string(Client.AccountBalance);
//	return stClientRecord;
//}
//
//bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
//{
//	vector<sClient> vClients;
//	fstream MyFile;
//	MyFile.open(FileName, ios::in);
//	if (MyFile.is_open())
//	{
//		string Line;
//		sClient Client;
//		while (getline(MyFile, Line))
//		{
//			Client = ConvertLinetoRecord(Line);
//			if (Client.AccountNumber == AccountNumber)
//			{
//				MyFile.close();
//				return true;
//			}
//			vClients.push_back(Client);
//		}
//		MyFile.close();
//	}
//	return false;
//}
//
//sClient ReadNewClient()
//{
//	sClient Client;
//	cout << "Enter Account Number? ";
//	getline(cin >> ws, Client.AccountNumber);
//	while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
//	{
//		cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
//		getline(cin >> ws, Client.AccountNumber);
//	}
//	cout << "Enter PinCode? ";
//	getline(cin, Client.PinCode);
//	cout << "Enter Name? ";
//	getline(cin, Client.Name);
//	cout << "Enter Phone? ";
//	getline(cin, Client.Phone);
//	cout << "Enter AccountBalance? ";
//	cin >> Client.AccountBalance;
//	return Client;
//}
//
//vector<sClient> LoadCleintsDataFromFile(string FileName)
//{
//	vector<sClient> vClients;
//	fstream MyFile;
//	MyFile.open(FileName, ios::in);
//	if (MyFile.is_open())
//	{
//		string Line;
//		sClient Client;
//		while (getline(MyFile, Line))
//		{
//			Client = ConvertLinetoRecord(Line);
//			vClients.push_back(Client);
//		}
//		MyFile.close();
//	}
//	return vClients;
//}
//void PrintClientRecordLine(sClient Client)
//{
//	cout << "| " << setw(15) << left << Client.AccountNumber;
//	cout << "| " << setw(10) << left << Client.PinCode;
//	cout << "| " << setw(40) << left << Client.Name;
//	cout << "| " << setw(12) << left << Client.Phone;
//	cout << "| " << setw(12) << left << Client.AccountBalance;
//}
//
//// DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<sClient> &vClients)
//// {
//// 	char Answer = 'n';
//// 	cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
//// 	cin >> Answer;
//// 	if (Answer == 'y' || Answer == 'Y')
//// 	{
//// 		for (sClient &C : vClients)
//// 		{
//// 			if (C.AccountNumber == AccountNumber)
//// 			{
//// 				C.AccountBalance += Amount;
//// 				SaveCleintsDataToFile(ClientsFileName, vClients);
//// 				cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;
//// 				returntrue;
//// 			}
//// 		}
//// 		return false;
//// 	}
//// }
//// string ReadClientAccountNumber()
//// {
//// 	string AccountNumber = "";
//// 	cout << "\nPlease enter AccountNumber? ";
//// 	cin >> AccountNumber;
//// 	return AccountNumber;
//// }
//
//void PrintClientRecordBalanceLine(sClient Client)
//{
//	cout << "| " << setw(15) << left << Client.AccountNumber;
//	cout << "| " << setw(40) << left << Client.Name;
//	cout << "| " << setw(12) << left << Client.AccountBalance;
//}
//void ShowAllClientsScreen()
//{
//	vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n"
//		<< endl;
//	cout << "| " << left << setw(15) << "Accout Number";
//	cout << "| " << left << setw(10) << "Pin Code";
//	cout << "| " << left << setw(40) << "Client Name";
//	cout << "| " << left << setw(12) << "Phone";
//	cout << "| " << left << setw(12) << "Balance";
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n"
//		<< endl;
//	if (vClients.size() == 0)
//		cout << "\t\t\t\tNo Clients Available In the System!";
//	else
//		for (sClient Client : vClients)
//		{
//			PrintClientRecordLine(Client);
//			cout << endl;
//		}
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n"
//		<< endl;
//}
//
//void ShowTotalBalances()
//{
//	vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//	cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n"
//		<< endl;
//	cout << "| " << left << setw(15) << "Accout Number";
//	cout << "| " << left << setw(40) << "Client Name";
//	cout << "| " << left << setw(12) << "Balance";
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n"
//		<< endl;
//	double TotalBalances = 0;
//	if (vClients.size() == 0)
//		cout << "\t\t\t\tNo Clients Available In the System!";
//	else
//		for (sClient Client : vClients)
//		{
//			PrintClientRecordBalanceLine(Client);
//			TotalBalances += Client.AccountBalance;
//			cout << endl;
//		}
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n"
//		<< endl;
//	cout << "\t\t\t\t\t   Total Balances = " << TotalBalances;
//}
//
//void PrintClientCard(sClient Client)
//{
//	cout << "\nThe following are the client details:\n";
//	cout << "-----------------------------------";
//	cout << "\nAccout Number: " << Client.AccountNumber;
//	cout << "\nPin Code     : " << Client.PinCode;
//	cout << "\nName         : " << Client.Name;
//	cout << "\nPhone        : " << Client.Phone;
//	cout << "\nAccount Balance: " << Client.AccountBalance;
//	cout << "\n-----------------------------------\n";
//}
//bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client)
//{
//	for (sClient C : vClients)
//	{
//		if (C.AccountNumber == AccountNumber)
//		{
//			Client = C;
//			return true;
//		}
//	}
//	return false;
//}
//
//sClient ChangeClientRecord(string AccountNumber)
//{
//	sClient Client;
//	Client.AccountNumber = AccountNumber;
//	cout << "\n\nEnter PinCode? ";
//	getline(cin >> ws, Client.PinCode);
//	cout << "Enter Name? ";
//	getline(cin, Client.Name);
//	cout << "Enter Phone? ";
//	getline(cin, Client.Phone);
//	cout << "Enter AccountBalance? ";
//	cin >> Client.AccountBalance;
//	return Client;
//}
//bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients)
//{
//	for (sClient& C : vClients)
//	{
//		if (C.AccountNumber == AccountNumber)
//		{
//			C.MarkForDelete = true;
//			return true;
//		}
//	}
//	return false;
//}
//
//vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients)
//{
//	fstream MyFile;
//	MyFile.open(FileName, ios::out);
//	string DataLine;
//	if (MyFile.is_open())
//	{
//		for (sClient C : vClients)
//		{
//			if (C.MarkForDelete == false)
//			{ // we only write records that are not marked for delete.
//				DataLine = ConvertRecordToLine(C);
//				MyFile << DataLine << endl;
//			}
//		}
//		MyFile.close();
//	}
//	return vClients;
//}
//
//void AddDataLineToFile(string FileName, string stDataLine)
//{
//	fstream MyFile;
//	MyFile.open(FileName, ios::out | ios::app);
//	if (MyFile.is_open())
//	{
//		MyFile << stDataLine << endl;
//		MyFile.close();
//	}
//}
//void AddNewClient()
//{
//	sClient Client;
//	Client = ReadNewClient();
//	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
//}
//void AddNewClients()
//{
//	char AddMore = 'Y';
//	do
//	{ // system("cls");
//		cout << "Adding New Client:\n\n";
//		AddNewClient();
//		cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
//		cin >> AddMore;
//	} while (toupper(AddMore) == 'Y');
//}
//
//bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
//{
//	sClient Client;
//	char Answer = 'n';
//	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
//	{
//		PrintClientCard(Client);
//		cout << "\n\nAre you sure you want delete this client? y/n ? ";
//		cin >> Answer;
//		if (Answer == 'y' || Answer == 'Y')
//		{
//			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
//			SaveCleintsDataToFile(ClientsFileName, vClients); // Refresh
//			vClients = LoadCleintsDataFromFile(ClientsFileName);
//			cout << "\n\nClient Deleted Successfully.";
//			return true;
//		}
//	}
//	else
//	{
//		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
//		return false;
//	}
//	return true;
//}
//bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
//{
//	sClient Client;
//	char Answer = 'n';
//	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
//	{
//		PrintClientCard(Client);
//		cout << "\n\nAre you sure you want update this client? y/n ? ";
//		cin >> Answer;
//		if (Answer == 'y' || Answer == 'Y')
//		{
//			for (sClient& C : vClients)
//			{
//				if (C.AccountNumber == AccountNumber)
//				{
//					C = ChangeClientRecord(AccountNumber);
//					break;
//				}
//			}
//			SaveCleintsDataToFile(ClientsFileName, vClients);
//			cout << "\n\nClient Updated Successfully.";
//			return true;
//		}
//	}
//	else
//	{
//		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
//		return false;
//	}
//	return true;
//}
//bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<sClient>& vClients)
//{
//	char Answer = 'n';
//	cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
//	cin >> Answer;
//	if (Answer == 'y' || Answer == 'Y')
//	{
//		for (sClient& C : vClients)
//		{
//			if (C.AccountNumber == AccountNumber)
//			{
//				C.AccountBalance += Amount;
//				SaveCleintsDataToFile(ClientsFileName, vClients);
//				cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;
//				return true;
//			}
//		}
//		return false;
//	}
//	return true;
//}
//string ReadClientAccountNumber()
//{
//	string AccountNumber = "";
//	cout << "\nPlease enter AccountNumber? ";
//	cin >> AccountNumber;
//	return AccountNumber;
//}
//void ShowDeleteClientScreen()
//{
//	cout << "\n-----------------------------------\n";
//	cout << "\tDelete Client Screen";
//	cout << "\n-----------------------------------\n";
//	vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//	string AccountNumber = ReadClientAccountNumber();
//	DeleteClientByAccountNumber(AccountNumber, vClients);
//}
//void ShowUpdateClientScreen()
//{
//	cout << "\n-----------------------------------\n";
//	cout << "\tUpdate Client Info Screen";
//	cout << "\n-----------------------------------\n";
//	vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//	string AccountNumber = ReadClientAccountNumber();
//	UpdateClientByAccountNumber(AccountNumber, vClients);
//}
//void ShowAddNewClientsScreen()
//{
//	cout << "\n-----------------------------------\n";
//	cout << "\tAdd New Clients Screen";
//	cout << "\n-----------------------------------\n";
//	AddNewClients();
//}
//void ShowFindClientScreen()
//{
//	cout << "\n-----------------------------------\n";
//	cout << "\tFind Client Screen";
//	cout << "\n-----------------------------------\n";
//	vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//	sClient Client;
//	string AccountNumber = ReadClientAccountNumber();
//	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
//		PrintClientCard(Client);
//	else
//		cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
//}
//void ShowEndScreen()
//{
//	cout << "\n-----------------------------------\n";
//	cout << "\tProgram Ends :-)";
//	cout << "\n-----------------------------------\n";
//}
//
//void ShowDepositScreen()
//{
//	cout << "\n-----------------------------------\n";
//	cout << "\tDeposit Screen";
//	cout << "\n-----------------------------------\n";
//	sClient Client;
//	vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//	string AccountNumber = ReadClientAccountNumber();
//	while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
//	{
//		cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
//		AccountNumber = ReadClientAccountNumber();
//	}
//	PrintClientCard(Client);
//	double Amount = 0;
//	cout << "\nPlease enter deposit amount? ";
//	cin >> Amount;
//	DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);
//}
//
//void ShowWithDrawScreen()
//{
//	cout << "\n-----------------------------------\n";
//	cout << "\tWithdraw Screen";
//	cout << "\n-----------------------------------\n";
//	sClient Client;
//	vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//	string AccountNumber = ReadClientAccountNumber();
//	while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
//	{
//		cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
//		AccountNumber = ReadClientAccountNumber();
//	}
//	PrintClientCard(Client);
//	double Amount = 0;
//	cout << "\nPlease enter withdraw amount? ";
//	cin >> Amount; // Validate that the amount does not exceeds the balance
//	while (Amount > Client.AccountBalance)
//	{
//		cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
//		cout << "Please enter another amount? ";
//		cin >> Amount;
//	}
//
//	DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients);
//}
//
//void ShowTotalBalancesScreen() { ShowTotalBalances(); }
//enum enTransactionsMenueOptions
//{
//	eDeposit = 1,
//	eWithdraw = 2,
//	eShowTotalBalance = 3,
//	eShowMainMenue = 4
//};
//enum enMainMenueOptions
//{
//	eListClients = 1,
//	eAddNewClient = 2,
//	eDeleteClient = 3,
//	eUpdateClient = 4,
//	eFindClient = 5,
//	eShowTransactionsMenue = 6,
//	eExit = 7
//};
//void GoBackToMainMenue()
//{
//	cout << "\n\nPress any key to go back to Main Menue...";
//	system("pause>0");
//	ShowMainMenue();
//}
//void GoBackToTransactionsMenue()
//{
//	cout << "\n\nPress any key to go back to Transactions Menue...";
//	system("pause>0");
//	ShowTransactionsMenue();
//}
//short ReadTransactionsMenueOption()
//{
//	cout << "Choose what do you want to do? [1 to 4]? ";
//	short Choice = 0;
//	cin >> Choice;
//	return Choice;
//}
//void PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
//{
//	switch (TransactionMenueOption)
//	{
//	case enTransactionsMenueOptions::eDeposit:
//	{
//		system("cls");
//		ShowDepositScreen();
//		GoBackToTransactionsMenue();
//		break;
//	}
//	case enTransactionsMenueOptions::eWithdraw:
//	{
//		system("cls");
//		ShowWithDrawScreen();
//		GoBackToTransactionsMenue();
//		break;
//	}
//	case enTransactionsMenueOptions::eShowTotalBalance:
//	{
//		system("cls");
//		ShowTotalBalancesScreen();
//		GoBackToTransactionsMenue();
//		break;
//	}
//	case enTransactionsMenueOptions::eShowMainMenue: { ShowMainMenue(); }
//	}
//}
//void ShowTransactionsMenue()
//{
//	system("cls");
//	cout << "===========================================\n";
//	cout << "\t\tTransactions Menue Screen\n";
//	cout << "===========================================\n";
//	cout << "\t[1] Deposit.\n";
//	cout << "\t[2] Withdraw.\n";
//	cout << "\t[3] Total Balances.\n";
//	cout << "\t[4] Main Menue.\n";
//	cout << "===========================================\n";
//	PerfromTranactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
//}
//short ReadMainMenueOption()
//{
//	cout << "Choose what do you want to do? [1 to 7]? ";
//	short Choice = 0;
//	cin >> Choice;
//	return Choice;
//}
//void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
//{
//	switch (MainMenueOption)
//	{
//	case enMainMenueOptions::eListClients:
//	{
//		system("cls");
//		ShowAllClientsScreen();
//		GoBackToMainMenue();
//		break;
//	}
//	case enMainMenueOptions::eAddNewClient: system("cls");
//		ShowAddNewClientsScreen();
//		GoBackToMainMenue();
//		break;
//	case enMainMenueOptions::eDeleteClient: system("cls");
//		ShowDeleteClientScreen();
//		GoBackToMainMenue();
//		break;
//	case enMainMenueOptions::eUpdateClient: system("cls");
//		ShowUpdateClientScreen();
//		GoBackToMainMenue();
//		break;
//	case enMainMenueOptions::eFindClient: system("cls");
//		ShowFindClientScreen();
//		GoBackToMainMenue();
//		break;
//	case enMainMenueOptions::eShowTransactionsMenue: system("cls");
//		ShowTransactionsMenue();
//		break;
//	case enMainMenueOptions::eExit: system("cls");
//		ShowEndScreen();
//		break;
//	}
//}
//void ShowMainMenue()
//{
//	system("cls");
//	cout << "===========================================\n";
//	cout << "\t\tMain Menue Screen\n";
//	cout << "===========================================\n";
//	cout << "\t[1] Show Client List.\n";
//	cout << "\t[2] Add New Client.\n";
//	cout << "\t[3] Delete Client.\n";
//	cout << "\t[4] Update Client Info.\n";
//	cout << "\t[5] Find Client.\n";
//	cout << "\t[6] Transactions.\n";
//	cout << "\t[7] Exit.\n";
//	cout << "===========================================\n";
//	PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
//}
//int main()
//{
//	ShowMainMenue();
//	system("pause>0");
//	return 0;
//}



































#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

const string FileNameClients = "NEWFILE.txt";

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

// Function Prototypes
void ShowMainMenu();
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
void AppendClientToFile(string fileName, string clientLine);
void AddClient();
void AddMultipleClients();
bool DeleteClient(string accNum, vector<ClientData>& clients);
bool UpdateClient(string accNum, vector<ClientData>& clients);
bool DepositToClient(string accNum, double amount, vector<ClientData>& clients);
string AskClientAcc();
void ShowAllClients();
void ShowAllBalances();
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

// Function Definitions
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

void AppendClientToFile(string fileName, string clientLine)
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
    AppendClientToFile(FileNameClients, ClientToLine(c));
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

// You can rename the remaining functions (transaction screens, menus) similarly...
// Due to length, the pattern is identical: rename all functions and variables, logic remains.


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
        break;
    case 7:
        system("cls");
        ShowEndScreen();
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
    cout << "\t[7] Exit\n";
    cout << "===========================================\n";

    ExecuteMainMenuOption(ReadMainMenuOption());
}

void ShowTransactionMenu()
{
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
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Client\n";
    cout << "-----------------------------------\n";
    AddMultipleClients();
}

void ShowDeleteClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client\n";
    cout << "-----------------------------------\n";

    vector<ClientData> clients = LoadClientsFromFile(FileNameClients);
    string accNum = AskClientAcc();
    DeleteClient(accNum, clients);
}

void ShowUpdateClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info\n";
    cout << "-----------------------------------\n";

    vector<ClientData> clients = LoadClientsFromFile(FileNameClients);
    string accNum = AskClientAcc();
    UpdateClient(accNum, clients);
}

void ShowFindClientScreen()
{
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
    cout << "\tProgram Ends :-)\n";
    cout << "-----------------------------------\n";
}

// Main
int main()
{
    ShowMainMenu();
    system("pause>0");
    return 0;
}

