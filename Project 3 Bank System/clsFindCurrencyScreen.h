#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrency.h"
#include <string>
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{

private:
	
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card: \n";
		cout << "_______________________________________\n";
		cout << "\nCountry     : " << Currency.Country();
		cout << "\nCode        : " << Currency.CurrencyCode();
		cout << "\nName        : " << Currency.CurrencyName();
		cout << "\nRate(1$)    : " << Currency.Rate();

		cout << "\n_______________________________________\n";


	}

	enum enFindCurrencyOptions {
		eByCode = 1, eByCountry = 2 };

	

	static void _PerformFindCurrencyOption(enFindCurrencyOptions
		CurrencyOption)
	{
		switch (CurrencyOption)
		{
		case enFindCurrencyOptions::eByCode:
		{
			cout << "\nPlease Enter Country Code: ";
			string sCode = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCode(sCode);
			if (Currency.IsEmpty())
			{
				cout << "\nCurrency Not Found :-(\n";
			}
			else
			{
				_PrintCurrencyCard(Currency);
			}

			break;
		}
		case enFindCurrencyOptions::eByCountry:
		{
			cout << "\nPlease Enter Country Name: ";
			string sName = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(sName);
			if (Currency.IsEmpty())
			{
				cout << "\nCurrency Not Found :-(\n";
			}
			else
			{
				_PrintCurrencyCard(Currency);
			}

			break;



			break;
		}



		}

	}

public: 
	
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country ? ";

		_PerformFindCurrencyOption((enFindCurrencyOptions)
			clsInputValidate::
			ReadShortNumberBetween(1, 2, "Enter number between [1 to 2] ?"));


	}



};

