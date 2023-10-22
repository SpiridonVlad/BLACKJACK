#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<chrono>
#include<random>
#include<map>
#include<windows.h>

using namespace std;
class CARDS
{
protected:
	string Sign;
	int sum_house = 0;
	int sum_player = 0;
	map<int,string>DECK;
	map<int, string> House;
	map<int, string> Player;
public:

	static void Symbol_Set(string& Sign) {
		for (int i = 3; i < 7; i++)
			Sign.push_back(i);
		/*cout << Sign;*/
		/*for (int i = 0; i < 6; i++)
			cout << Simbol[i];*/
	}

	static void Random_Set(string& Number1, string& Number2, string& Number3, string& Sign1, string& Sign2, string& Sign3, string Simbol) {
		srand(time(0));
		Number1.clear();
		Number2.clear();
		Number3.clear();
		Sign1.clear();
		Sign2.clear();
		Sign3.clear();

		int random_sign;
		int random_num1, random_num2, random_num3;
		do {
			random_num1 = rand() % 4;
			random_num2 = rand() % 4;
			random_num3 = rand() % 4;
		} while (random_num1 == random_num2 || random_num1 == random_num3 || random_num2 == random_num3);

		Number1 = Simbol[random_num1];
		Number2 = Simbol[random_num2];
		Number3 = Simbol[random_num3];

		random_sign = rand() % 4;
		Sign1 = Simbol[random_sign];
		random_sign = rand() % 4;
		Sign2 = Simbol[random_sign];
		random_sign = rand() % 4;
		Sign3 = Simbol[random_sign];
	}

	static bool Get_simbol_with_probability(char Simbol, double probability, char& result) {
		srand(time(nullptr));
		unsigned const seed = std::chrono::system_clock::now().time_since_epoch().count();
		default_random_engine generator(seed); // generam numere aleatoare folosind distributia uniforma
		uniform_real_distribution<double> distribution(0.00, 1.00); // distributia uniforma pe intervalul [0,1]
		double const rand_num = distribution(generator); // generam un numar aleatoriu intre 0 si 1
		//cout << rand_num<<" ";
		if (rand_num <= probability) { // daca numaru aleatoriu e mai mic decat probabilitatea, adaugam valoarea in vectorul de rezultate
			//result.clear();
			result = Simbol;
			return true;
		}
		return false;
	}

	static bool Get_card_with_probability(int value,double probability,int& result) {
		result = 0;
		srand(time(0));
		unsigned const seed = std::chrono::system_clock::now().time_since_epoch().count();
		default_random_engine generator(seed); 
		uniform_real_distribution<double> distribution(0.00, 10.00); 
		double const rand_num = distribution(generator); 
		//cout << rand_num<<" ";
		if (rand_num <= probability) { // daca numaru aleatoriu e mai mic decat probabilitatea, adaugam valoarea in vectorul de rezultate
			result = value;
			return true;
		}
		return false;
	}

	void Draw(map<int,string> &);

	virtual void Game()=0;

	virtual void Check(bool jucator)=0;
	//function that prints a map
	virtual void Print(map<int, string>& DECK, bool jucator) = 0; 

	virtual void Table(bool jucator)=0;

	virtual bool WIN()=0;

	virtual bool Again()=0;
};

