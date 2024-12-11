#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrency.h"
#include "clsInputValidate.h"


class clsUpdateCurrencyRate : protected clsScreen
{
private: 

	static float _ReadRate()
	{
		cout << "\nEnter New Rate: ";
		float NewRate = 0;

		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	}

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

	
public: 

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\t Update Currency Screen");

		cout << "\nPlease Enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}


		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrencyCard(Currency);

		char Answer = 'n';
		cout << "Are you sure want to update the rate of this Currency y/n? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			cout << "\nUpdate Currency Rate:\n";
			cout << "_________________________\n";
			
			Currency.UpdateRate(_ReadRate());
				
			cout << "\nCurrency Rate Updated Successfully :-)\n";
			_PrintCurrencyCard(Currency);

		}
		else
		{
			cout << "\nUpdate was cancelled\n";
		}

	}


	
	


};

