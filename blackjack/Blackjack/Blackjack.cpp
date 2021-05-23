#include <iostream>
#include <array>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

const int numCards{ 52 };
int cardsDealt{};

enum cardRank
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,

	MAX_RANK
};

enum cardSuit
{
	SUIT_CLUB,
	SUIT_DIAMOND,
	SUIT_HEART,
	SUIT_SPADE,

	MAX_SUIT
};

struct card
{
	cardRank rank;
	cardSuit suit;
};

void createDeck(std::array<card, numCards> &deck)
{
	int suitCount{};
	int rankCount{};
	int totalCount{};
	for (;totalCount < numCards; suitCount++)
	{
		for (; rankCount < MAX_RANK; rankCount++)
		{
			deck[totalCount].suit = cardSuit(suitCount);
			deck[totalCount].rank = cardRank(rankCount);
			totalCount++;
		}
		rankCount = 0;
	}
}

void printDeck(std::array<card, numCards>& deck)
{
	std::array <char, static_cast<int>(MAX_RANK)> ranks{ '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };
	std::array<char, static_cast<int>(MAX_SUIT)> suits{ 'C', 'D', 'H', 'S' };
	int count{};
	for (;count < numCards;count++)
		std::cout << ranks[deck[count].rank] << suits[deck[count].suit] << " ";
}

void shuffleDeck(std::array<card, numCards>& deck)
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(deck.begin(), deck.end(),g);
}

int getCardValue(card inputCard)
{
	std::array<int,MAX_RANK>rankValue{ 2,3,4,5,6,7,8,9,10,10,10,10,11 };
	int cardValue{ rankValue[inputCard.rank] };
	return cardValue;
}

int deal (std::array<card, numCards>& deck)
{
	cardsDealt++;
	return getCardValue(deck[cardsDealt - 1]);
}

void printScore(int score, bool isPlayer)
{
	std::string player{ "Player" };
	std::string dealer{ "Dealer" };
	std::string who;
	if (isPlayer == true)
		who = player;
	else
		who = dealer;
	std::cout << who << " score: " << score << '\n';
}

bool ifStand()
{
	std::string input;
	std::cout << "Stand or hit? ";
	std::cin >> input;
	if (input == "stand")
		return true;
	else if (input == "hit")
		return false;
	else
		std::cin.clear(std::size(input));
	std::cout << "Error: unknown input\n";
		ifStand();
}

bool play(std::array<card, numCards>& deck)
{
	shuffleDeck(deck);
	int dealer{ deal(deck) };
	int player{ deal(deck) };
	player += deal(deck);
	printScore(player, true);
	while (ifStand() == false)
	{
		player += deal(deck);
		printScore(player, true);
		if (player > 21)
			return false;
	}
	while (dealer <= 17)
		dealer += deal(deck);
	if (dealer > 21 || player > dealer)
	{
		printScore(dealer, false);
		return true;
	}
	printScore(dealer, false);
	return false;
}

bool continuePlayingCheck()
{
	std::cout << "Continue playing (y/n)? ";
	char input;
	std::cin >> input;
	if (input == 'y')
		return true;
	else if (input == 'n')
		return false;
	else
	{
		std::cin.clear(32767, '\n');
		continuePlayingCheck();
	}
}

int main()
{
	std::array<card, numCards>deck{};
	createDeck(deck);
	bool continuePlaying{ true };
	int wins{};
	int loses{};
	while (continuePlaying == true)
	{
		if (play(deck) == false)
		{
			std::cout << "You have lost.\n";
			loses += 1;
		}
		else
		{
			std::cout << "You have won.\n";
			wins += 1;
		}
		continuePlaying = continuePlayingCheck();
	}
	std::cout << "You have finished playing with " << wins << " wins and " << loses << " loses\nWin-to-loss ratio: " << float (wins / loses);
	return 0;
}

/*
int testMain()
{
	const card disCard{ RANK_2, SUIT_CLUB };
	std::array<card, numCards>deck{};
	createDeck(deck);
	printDeck(deck);
	shuffleDeck(deck);
	std::cout << "\n";
	printDeck(deck);
	std::cout << "\n";
	std::cout << getCardValue(disCard);
}*/