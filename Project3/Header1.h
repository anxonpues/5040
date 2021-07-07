#pragma once
#include "Header.h"

int DyA(vector<int> tira, vector<int> liston)
{
	int di{ 0 };
	int ap{ 0 };
	for (auto i = 0; i < 4; i++)
		for (auto j = 0; j < 4; j++)
		{
			if (tira.at(i) == liston.at(j) && i == j)
				di++;
			if (tira.at(i) == liston.at(j) && i != j)
				ap++;
		}
	return di * 10 + ap;
}

void siembra(vector<vector<int>>& vctr)
{
	vector<int> elem;
	vector<int> digits{ 0,1,2,3,4,5,6,7,8,9 };
	//int cont{ 0 };
	for (unsigned i = 0; i < digits.size(); i++)
		for (unsigned j = 0; j < digits.size(); j++)
			for (unsigned k = 0; k < digits.size(); k++)
				for (unsigned l = 0; l < digits.size(); l++)
					if (i != j && i != k && i != l && j != k && j != l && k != l)
					{
						elem.push_back(digits.at(i));
						elem.push_back(digits.at(j));
						elem.push_back(digits.at(k));
						elem.push_back(digits.at(l));
						vctr.push_back(elem);
						elem.clear();
						//cont++;
						//cout << cont << "  ";
					}
}

bool criba(vector<vector<int>>& ldl, vector<int>& tryit, int da)
{
	bool coh = false;
	int sz_ldl = ldl.size();
	for (int i = sz_ldl - 1; i >= 0; i--)
	{
		int res = DyA(ldl.at(i), tryit);
		if (res != da)
		{
			ldl.erase(i + ldl.begin());
		}
		else
			coh = true;
	}
	return coh;
}

int rndm(int wt, int ht)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(wt, ht);
	//Use dis to transform the random unsigned int generated by gen into an int in [wt, ht]
	return dis(gen);
}

void prnt(vector<int>& elem)
{
	for (auto dig : elem)
		cout << dig;
	cout << "      ";
}

void leave()
{
	cout << "\n s salir  ";
	char c{};
	while (c != 's')
		c = cin.get();
	cout << "\n";
}

int isz(vector<vector<int>>& ldl)
{
	return (int)ldl.size() - 1;
}