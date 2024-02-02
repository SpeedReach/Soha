/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include "SHPlayer.h"
#include "SHDealer.h"
#include <random>
#include <iostream>

// constructor
SHDealer::SHDealer()
	:SHPlayer("Dealer")
{//change:call the constructor of SHPlayer
	start();
}

// distribute a card to the player
int
SHDealer::giveCardID()
{
	if(cardDrew>51)
		return -1;
	while(deck[cardDrew]/4>0&&deck[cardDrew]/4<8){
		cardDrew++;
		if(cardDrew>51)
			return -1;
	}
	cardDrew++;
	return deck[cardDrew-1];
}


// give the dealer a card
/*void
SHDealer::addCard(Card newCard)
{
	dealer.addCard(newCard);
}*/
//change:call the member function directly


// determind who has win the game.
// if both of them have the same pattern,
// the one has more total pips wins the game.
Result
SHDealer::judge(SHPlayer& player)
{
	if(static_cast<int>(player.getHandPattern())==static_cast<int>(getHandPattern())){
	//change:call the member function directly
		if(player.totalPips()==totalPips())
	//change:call the member function directly
			return TIE;
		else if(player.totalPips()>totalPips())
	//change:call the member function directly
			return DEALER_LOSE;
		return DEALER_WIN;
	}
	else if(static_cast<int>(player.getHandPattern())<static_cast<int>(getHandPattern()))
	//change:call the member function directly
		return DEALER_LOSE;
	return DEALER_WIN;
}


// start a new game(round)
// before starting a new game(round), you should have
// a new deck, and then shuffle it.
// The deck only has pips A, 8, 9, 10, J, Q, K.
void
SHDealer::start()
{
	SHPlayer::start();
	//change:call the member function directly
	coverFirstCard();
	//change:call the member function directly
	cardDrew = 0;
	shuffle();
}


// shuffle the deck of cards
void
SHDealer::shuffle()
{
	for(int i=0;i<52;++i)
		deck[i] = i;
	std::cout << "FIB6: Suffle Card Logic\n";
	/* FIB6: Dealer洗牌*/
}

