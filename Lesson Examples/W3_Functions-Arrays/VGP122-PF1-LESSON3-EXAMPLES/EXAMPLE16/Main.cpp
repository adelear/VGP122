#include <iostream>

int main()
{
	int randomCard;

	enum Cards { ONE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10, ACE = 11};

	srand(time(0));

	randomCard = (1 + rand() % 11);

	if (randomCard == Cards::ACE)
		std::cout << "You Win!" << std::endl;
	else
		std::cout << "You Lose." << std::endl;

	return 0;
}