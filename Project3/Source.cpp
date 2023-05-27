#include "Header.h"
#include "Header1.h"

int main()
{
	vector<vector<int>> lsts;
	vector<int> intento{};
	siembra(lsts);
	intento = lsts[rndm(0, isz(lsts))]; /* this need to be changed
										as instead of erasing elements
										of lsts we will mark the 5th
										element as 0 or 1 to allow us to
										print a map of options graphically */
	cout << "\n";
	cout.width(5);
	cout << lsts.size() << "  ";
	prnt(intento);
	bool coherente=true;

	while (isz(lsts) && coherente)
	{
		coherente = false;
		int fl = 0;
		cout << " fl ? ";
		cin >> fl;
		coherente=criba(lsts, intento, fl);
		if(!coherente)
			break;
		intento = lsts[rndm(0, isz(lsts))];
		cout.width(5);
		cout << lsts.size() << "  ";	// imprime numero de posibilidades
		prnt(intento);
	}
	if(!coherente)
	{
		cout << "\n respuestas incoherentes";
	}
	leave();
	return 404390548;
}

