#include "CARDS.h"


void CARDS::Draw(map<int,string>& Bolfa)
{
	char result_string=' ';
	int result_int;
	int index = 1;
	int sign=1;
	while (!Get_card_with_probability(index, 0.077, result_int))
	{
		index++;
		if (index >= 13)
			index = 1;
	}
	while (!Get_simbol_with_probability(Sign[sign], 0.33, result_string) && result_string==' ') {
		sign++;
		if (sign > 4)
			sign = 1;
	}
	//cout <<"("<< result_int << ") (" << Sign[sign] <<")" << endl;

	string simbol;
	simbol.push_back(Sign[sign]);
	if (result_int == 1) {
		cout << "Cum Alegeti As-ul?[1/11]:"; cin >> result_int;
	}
	Bolfa.insert(make_pair(result_int, simbol));
	//DECK.erase(result_int);
}


