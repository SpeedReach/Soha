/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include <iostream>
#include <cstring>
#include <cassert>
#include "AnsiPrint.h"
#include "Card.h"
#include "CardPattern.h"
#include "SHPlayer.h"


using namespace std;

const char* HandTypeName[9] = {
    "Straight flush",
    "Four of a kind",
    "Full house",
    "Flush",
    "Straight",
    "Three of a kind",
    "Two pair",
    "One pair",
    "Other"
};

// constructor
SHPlayer::SHPlayer(const char* playerName)
:n_cards(0), is_open_first(false){
	name = new char[strlen(playerName)+5];	
	strcpy(name, playerName);
	loan = 0;
}

SHPlayer::~SHPlayer(){
	//cout<<"SHPlayer destruct : "<<name[0]<<endl;
	delete [] name;
}

// initialize the number of cards to 0
void
SHPlayer::start()
{
	is_open_first = true;
	n_cards = 0;
}

// add a new card to the current hand
// need to protect the array from overflowing
void SHPlayer::addCard(Card newCard)
{
	//cout<<n_cards;
	if(n_cards!=kMaxCards){
		cards[n_cards] = newCard;
		n_cards+=1;
	}
//	std::cout<<cards[n_cards-1].getID()<<std::endl;
}

// open the first card so it faces up
void
SHPlayer::openFirstCard()
{
	is_open_first = true;
}

void
SHPlayer::coverFirstCard()
{
	is_open_first = false;
}

// print the current hand to the screen graphically
void
SHPlayer::showCards() const
{
	for(int i=0;i<kCardHeight;++i){
		char arr[kCardWidth+1];
		if(i<(int)strlen(name))
			std::cout<<name[i];
		else
			std::cout<<' ';
		for(int j=0;j<n_cards;++j){
			//cout<<cards[j].getPip();
			if(j==0&&is_open_first==false){
				for(int k=0;k<kCardWidth;++k)
					arr[k] = card[13][i][k];
			}
			else{
				for(int k=0;k<kCardWidth;++k){
					arr[k] = card[cards[j].getPip()%13][i][k];
					if(arr[k] == 'x')
						arr[k] = cardAbbrev[cards[j].getSuit()];	
				}
			}
			AnsiPrint(arr, cardColor[cards[j].getSuit()], white);
			std::cout<<' ';
		}
		std::cout<<std::endl;
	}

}

// get the total points of the current hand
int
SHPlayer::totalPips() const
{
	int sum = 0;

	cout << "FIB7: Calculate total points.\n";

	return sum;
}

// judge what kind of hand type you own
// you need to have 5 cards
HandType
SHPlayer::getHandPattern() 
{
	SHPlayer::sortCards();
	if(isStraightFlush())
		return STRAIGHT_FLUSH;
	if(isFourOfAKind())
		return FOUR_OF_A_KIND;
	if(isFullHouse())
		return FULL_HOUSE;
	if(isTwoPair())
		return TWO_PAIR;
	if(isThreeOfAKind())
		return THREE_OF_A_KIND;
	if(isFlush())
		return FLUSH;
	if(isStraight())
		return STRAIGHT;
	if(isOnePair())
		return ONE_PAIR;
	return OTHER;
}

// return the number of cards at hand
int
SHPlayer::getNumCards() const
{
	return n_cards;
}

void
SHPlayer::sortCards() 
{
	bool copied[kMaxCards] = {};
	for(int i=0;i<n_cards;++i){
		int min_val = 10000;
		int min_index = -1;
		for(int j=0;j<n_cards;++j){
	//		std::cout<<copied[j]<<std::endl;
			if(copied[j] == 0){
				if(cards[j].getID()<min_val){
					min_val = cards[j].getID();
					min_index = j;
				}
			}
		}
		sortedCards[i] = cards[min_index];
		copied[min_index] = 1;
	}
}

int
SHPlayer::getLoan() const
{
	return loan;
}

void
SHPlayer::setLoan(int loan)
{
	this->loan = loan;
}

// any five card sequence of same suit
bool 
SHPlayer::isStraightFlush() const
{
	return isStraight()&&isFlush();
}

// four cards of the same pip
bool 
SHPlayer::isFourOfAKind() const
{
    // O O O O X
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[2].getPip() == sortedCards[3].getPip() &&
            sortedCards[0].getPip() == sortedCards[2].getPip() )
        return true;
    // X O O O O
    if( sortedCards[1].getPip() == sortedCards[2].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() &&
            sortedCards[1].getPip() == sortedCards[3].getPip() )
        return true;

    return false;
}

// three of a kind combined with a pair
bool 
SHPlayer::isFullHouse() const
{
    // O O O X X
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[1].getPip() == sortedCards[2].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;
    // X X X O O
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[2].getPip() == sortedCards[3].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;

    return false;
}

// five cards of the same suit
bool
SHPlayer::isFlush() const
{
    for( int i = 0; i < kMaxCards - 1; i++ )
        if( sortedCards[i].getSuit() != sortedCards[i+1].getSuit() )
            return false;

    return true;
}

// five cards in sequence
bool 
SHPlayer::isStraight() const
{
    for( int i = 0; i < kMaxCards - 1; i++ )
        if( sortedCards[i].getPip() + 1 != sortedCards[i+1].getPip() )
            return false;

    return true;
}

// three cards of the same pip
bool 
SHPlayer::isThreeOfAKind() const
{
    for( int i = 0; i < kMaxCards - 2; i++ )
        if( sortedCards[i].getPip() == sortedCards[i+1].getPip() &&
                sortedCards[i].getPip() == sortedCards[i+2].getPip() )
            return true;

    return false;
}

// two cards of one pip, two cards of another pip
bool 
SHPlayer::isTwoPair() const
{
    // O O @ @ X
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[2].getPip() == sortedCards[3].getPip() )
        return true;
    // O O X @ @
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;
    // X O O @ @
    if( sortedCards[1].getPip() == sortedCards[2].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;

    return false;
}

// two cards of one pip
bool 
SHPlayer::isOnePair() const
{
    for( int i = 0; i < kMaxCards - 1; i++ )
        if( sortedCards[i].getPip() == sortedCards[i+1].getPip() )
            return true;

    return false;
}


