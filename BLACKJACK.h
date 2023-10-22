#pragma once
#include "CARDS.h"
class BLACKJACK : public CARDS
{
public:
	BLACKJACK();
	~BLACKJACK();
	// Inherited via CARDS
	virtual void Game() override;
	virtual void Check(bool jucator) override;
	virtual void Print(map<int, string>& DECK, bool jucator) override;
	virtual void Table(bool jucator) override;
	virtual bool WIN() override;
	virtual bool Again() override;
};

