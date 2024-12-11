#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsListCurrenciesScreen : protected clsScreen
{
private:
	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left <<
			Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(30) << left << Currency.CurrencyName();
		cout << "| " << setw(8) << left << Currency.Rate();

	}


public: 
	
	static void ShowListCurrenciesScreen()
	{
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList(); // clsCurrency::GetAllUSDRates();
		string Title = "\t Currencies List Screen";
		string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t_________________________________________________________________________________________________________\n";
		cout << endl<< setw(8) << left << "" << "| " << setw(30) << left << "Country";
		cout << "| " << setw(8) << left << "Code";
		cout << "| " << setw(30) << left << "Name";
		cout << "| " << setw(10) << left << "Rate/(1$)";

		cout << "\n\t_________________________________________________________________________________________________________\n";
		cout << endl;
		if (vCurrencies.size() == 0)
		{
			cout << "\n\t\tNo Currencies Available on the System!\n";
		}
		else
		{
			for (const clsCurrency& Currency : vCurrencies)
			{
				_PrintCurrencyRecordLine(Currency);
				cout << endl;
			}
		}

		cout << "\n\t_________________________________________________________________________________________________________\n";


	}

	

};

