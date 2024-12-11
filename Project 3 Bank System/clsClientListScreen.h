#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <string>


class clsClientListScreen : protected clsScreen
{
private: 

	static void PrintClientRecordLine(clsBankClient Client)
	{

		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}


public:

	static void ShowClientsList()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return; // this will exit the function and it will not continue
		}


		vector<clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "\t Client List Screen";
		string SubTitle = "\t   (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout <<setw(8) << left <<  "\n\t________________________________________________________";
		cout << "___________________________________________\n" << endl;

		cout  << setw(8) << left  << "" << "| " << setw(15) << left << "Account Number";
		cout << "| " << setw(20) << left << "Client Name";
		cout << "| " << setw(12) << left << "Phone";
		cout << "| " << setw(20) << left << "Email";
		cout << "| " << setw(10) << left << "Pin Code";
		cout << "| " << setw(12) << left << "Balance" << endl;
		cout <<setw(8) << left << "" << "________________________________________________________";
		cout << "___________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else
			for (clsBankClient Client : vClients)
			{

				PrintClientRecordLine(Client);
				cout << endl;
			}

		cout << endl<< setw(8)<< left  << "" << "________________________________________________________";
		cout << "___________________________________________\n" << endl;


	}

};

