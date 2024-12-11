#include <iostream>
#include "clsLoginScreen.h"
#include "clsCurrency.h"

using namespace std;

static void _PrintCurrency(clsCurrency Currency)
{
	cout << "\nCurrency Card:\n";
	cout << "______________________________\n";
	cout << "\nCountry        : " << Currency.Country();
	cout << "\nCode           : " << Currency.CurrencyCode();
	cout << "\nName           : " << Currency.CurrencyName();
	cout << "\nRate(1$) =     : " << Currency.Rate();

	cout << "\n______________________________\n";


}



int main()
{
	/*while (true)
	{
		
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}
	*/

	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}

	}
	

	system("pause>0");
	return 0;

}








