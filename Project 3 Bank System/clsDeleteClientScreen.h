#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsMainScreen.h"


class clsDeleteClientScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card: ";
		cout << "\n_________________";
		cout << "\nFirstName        : " << Client.FirstName;
		cout << "\nLastName         : " << Client.LastName;
		cout << "\nFull Name        : " << Client.FullName();
		cout << "\nEmail            : " << Client.Email;
		cout << "\nPhone            : " << Client.Phone;
		cout << "\nAcc. Number      : " << Client.AccountNumber();
		cout << "\nPassword         : " << Client.PinCode;
		cout << "\nBalance          : " << Client.AccountBalance;
		cout << "\n_________________\n";

	}

public: 

	static void ShowDeleteClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return; // this will exit the function
		}


		_DrawScreenHeader("\tDelete Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\nAre you sure you want to delete this client y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			if (Client1.Delete())
			{
				cout << "\nClient Deleted Successfully :-)\n";
				_PrintClient(Client1);
			}
			else
			{
				cout << "\nError Client Was not Deleted\n";
			}

		}

	}




};

