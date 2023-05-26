#pragma once

class Card
{
public:
	char face;
	char suit;

	static const char SUITS[];
	static const char FACES[];
};

const char Card::SUITS[] = "HCSD";
const char Card::FACES[] = "23456789TJQKA";