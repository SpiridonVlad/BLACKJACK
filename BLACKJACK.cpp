#include "BLACKJACK.h"

BLACKJACK::BLACKJACK()
{
	Sign.resize(1);
	Symbol_Set(Sign);
	for (int i = 1; i <= 10; i++)
		DECK.insert(make_pair(i, Sign));
	DECK.insert(make_pair(16, ":)"));
}

BLACKJACK::~BLACKJACK()
{
	Sign.clear();
	DECK.clear();
	House.clear();
	Player.clear();
}

void BLACKJACK::Game()
{
	Draw(House);
	Draw(Player);
	Draw(House);
	Draw(Player);
	Table(false);
	Check(true);
	Table(true);
	Check(false);
	WIN();
	while (Again()) {
		Draw(House);
		Draw(Player);
		Draw(House);
		Draw(Player);
		Table(false);
		Check(true);
		Table(true);
		Check(false);
		WIN();
	}
}

void BLACKJACK::Check(bool jucator)
{
	bool ok;
	int sum = 0;
	sum_house = 0;
	sum_player = 0;
	for (auto i : House)
		if (i.first < 10)
			sum_house += i.first;
		else
			if (i.first == 11)
				sum_house += 11;
			else
				sum_house += 10;

	for (auto i : Player)
		if (i.first < 10)
			sum_player += i.first;
		else
			if (i.first == 11)
				sum_player += 11;
			else
				sum_player += 10;

	if (jucator == true) {
		cout << "(Jucator) Trageti carte [0/1] :"; cin >> ok;
		if (ok == 1) {
			Draw(Player);
			/*cout << "PLAYER:" << endl;
			Print(Player);*/
			sum_player = 0;
			for (auto i : Player)
				if (i.first < 10)
					sum_player += i.first;
				else
					sum_player += 10;
			if (sum_player < 21) {
				Table(false);
				Check(jucator);
			}
		}
	}
	else if (sum_house <= 16 && sum_house < sum_player)
	{
		cout << "(House) Trageti carte [0/1] :"; cin >> ok;
		if (ok == 1) {
			Draw(House);
			/*cout << "HOUSE:" << endl;
			Print(House);*/
			sum_house = 0;
			for (auto i : House)
				if (i.first < 10)
					sum_house += i.first;
				else
					sum_house += 10;
			if (sum_house < 21)
			{
				Table(true);
				Check(jucator);
			}
		}
	}
	system("cls");
}

void BLACKJACK::Print(map<int, string>& DECK, bool jucator)
{
	bool ok = 0;
	char j;
	if (jucator == false) {
		std::cout << " _    _    ____      _    _    _____    _____ \n";
		std::cout << "| |  | |  / __ \    | |  | |  / ____|  |  ____|\n";
		std::cout << "| |__| | | |  | |  | |  | | | (___    | |__   \n";
		std::cout << "|  __  | | |  | |  | |  | |  <___>    |  __|   \n";
		std::cout << "| |  | | | |__| |  | |__| |  ____)|   | |____  \n";
		std::cout << "|_|  |_|  <____/     \____/  |_____/   |______| \n";
	}
	else
	{
		std::cout << "  ____      _             _    __     __   _____      ____       \n";
		std::cout << " |  _ \\    | |           / \\   \\ \\   / /  |  ____|   |  _ \\      \n";
		std::cout << " | |_) |   | |          / _ \\   \\ \\_/ /   | |__      | |_) |    \n";
		std::cout << " |  _ <    | |         / ___ \\   \\   /    |  __|     |  _ <    \n";
		std::cout << " | |       | |____    / /  \\ \\    | |     | |____    | | < |   \n";
		std::cout << " |_|       |______|  /_/    \\_\\   |_|     |______|   |_|  <_|   \n";
	}
	if (House.size() == 2 && jucator == false)
	{
		ok = 1;
	}
	for (auto it : DECK) {
		if (it.first < 11 && it.first>1 && ok == 0) {
			cout << "$----------------------------------------$" << endl;
			std::cout << "                        " << std::endl;
			std::cout << "               ----------- " << std::endl;
			if (it.first > 9)
				std::cout << "              |" << it.first << "         | " << std::endl;
			else
				std::cout << "              |" << it.first << "          | " << std::endl;
			std::cout << "              | --------- |" << std::endl;
			std::cout << "              | |       | |" << std::endl;
			std::cout << "              | |   $   | |  " << std::endl;
			std::cout << "              | |       | |" << std::endl;
			std::cout << "              | --------- |" << std::endl;
			if (it.first > 9)
				std::cout << "              |         " << it.first << "| " << std::endl;
			else
				std::cout << "              |          " << it.first << "| " << std::endl;
			std::cout << "               ----------- " << std::endl;
			std::cout << "                    " << std::endl;
			cout << "$----------------------------------------$" << endl;
			ok = 0;
		}
		else
		{
			if (ok == 0) {
				if (it.first == 11 || it.first == 1)
					j = 'A';
				if (it.first == 12)
					j = 'J';
				if (it.first == 13)
					j = 'Q';
				if (it.first == 14)
					j = 'K';
				cout << "$----------------------------------------$" << endl;
				std::cout << "                        " << std::endl;
				std::cout << "               ----------- " << std::endl;
				std::cout << "              |" << j << "          | " << std::endl;
				std::cout << "              | --------- |" << std::endl;
				std::cout << "              | |       | |" << std::endl;
				std::cout << "              | |   $   | |  " << std::endl;
				std::cout << "              | |       | |" << std::endl;
				std::cout << "              | --------- |" << std::endl;
				std::cout << "              |          " << j << "|" << std::endl;
				std::cout << "               ----------- " << std::endl;
				std::cout << "                    " << std::endl;
				cout << "$----------------------------------------$" << endl;
				ok = 0;
			}
		}
		ok = 0;
	}
}

void BLACKJACK::Table(bool jucator)
{
	system("cls");
	sum_house = 0;
	sum_player = 0;
	for (auto i : House)
		if (i.first < 10)
			sum_house += i.first;
		else
			if (i.first == 11)
				sum_house += 11;
			else
				sum_house += 10;

	for (auto i : Player)
		if (i.first < 10)
			sum_player += i.first;
		else
			if (i.first == 11)
				sum_player += 11;
			else
				sum_player += 10;

	if (jucator == false) {
		Print(House, false);
		if (House.size() == 2) {
			cout << endl;
			cout << "               HOUSE(?)" << endl;
		}
		else
			cout << "               HOUSE (" << sum_house << ")" << endl;
		Print(Player, true);
		cout << "               PLAYER (" << sum_player << ")" << endl;
	}
	else {
		Print(Player, true);
		cout << endl;
		cout << "               PLAYER (" << sum_player << ")" << endl;
		Print(House, false);
		if (House.size() == 2) {
			cout << "               HOUSE(?)" << endl;
		}
		else
			cout << "               HOUSE (" << sum_house << ")" << endl;
	}
}

bool BLACKJACK::WIN()
{
	system("cls");
	cout << endl;
	cout << "                 HOUSE (" << sum_house << ")" << endl;
	Print(House, false);
	cout << endl;
	cout << "                PLAYER (" << sum_player << ")" << endl;
	Print(Player, true);
	if (sum_player > 21) {
		cout << "                 HOUSE (" << sum_house << ")" << endl;
		cout << "                PLAYER (" << sum_player << ")" << endl;
		cout << "              The House Won" << endl;
		return true;
	}
	if (sum_house > 21) {
		cout << "                 HOUSE (" << sum_house << ")" << endl;
		cout << "                PLAYER (" << sum_player << ")" << endl;
		cout << "              The Player Won" << endl;
		return true;
	}
	if (sum_player > sum_house) {
		cout << "                 HOUSE (" << sum_house << ")" << endl;
		cout << "                PLAYER (" << sum_player << ")" << endl;
		cout << "              The Player Won" << endl;
		return true;
	}
	else
	{
		if (sum_player < sum_house) {
			cout << "                 HOUSE (" << sum_house << ")" << endl;
			cout << "                PLAYER (" << sum_player << ")" << endl;
			cout << "              The House Won" << endl;
		}
		return true;
	}
	return false;
}

bool BLACKJACK::Again()
{
	bool ok = false;
	Sleep(7000);
	system("cls");
	cout << "Vreti sa jucati din nou? [0/1]:"; cin >> ok;
	if (ok == true) {
		Player.clear();
		House.clear();
		sum_house = 0;
		sum_player = 0;
	}
	else
	{
		cout << "Multumim ca ati jucat!" << endl;
	}
	return ok;
}
