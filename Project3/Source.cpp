#include "Header.h"
#include "Header1.h"

int main()
{
	vector<vector<int>> lsts;
	vector<int> intento{};
	siembra(lsts);
	intento = lsts[rndm(0, isz(lsts))];
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

