/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

//#include "SHGame.h"
#include "SHPlayer.h"
#include "SHDealer.h"
#include "SHGame.h"
#include <iostream>

using std::cout;
using std::endl;

// only constructor
// Must be given a valid (initialized) game player and dealer
// Menu is constructed internally to provide basic text interface
// We must use an initialization list here.
//void endTurn(Result turnResult);

SHGame::SHGame(SHPlayer& shp, SHDealer& shd)
	: menu(sizeof(menuItems)/sizeof(char*), menuItems), player(shp), dealer(shd)
{
	gameStatus = FIRST_TURN;
	player.setLoan(initCredit);
	dealer.setLoan(initCredit);
}


// one run of the game
// take and process a user action
// show current hands for both players at the end of a run.
bool
SHGame::oneRun()
{
	if(gameStatus == FIRST_TURN)
		restart();
	else{
		menu.print();
		switch(menu.getAnswer()){
			case ONE_MORE:
				if(gameStatus == IN_PROGRESS)
					moreCard();
				else
					cout<<"GAME OVER!"<<endl;
				break;
			case GIVE_UP:
				if(gameStatus == IN_PROGRESS)
					giveUp();
				else
					cout<<"GAME OVER!"<<endl;
				break;
			case RESTART:
				if(gameStatus == IN_PROGRESS)
					cout<<"Game is not over yet. Choose 'give up' to end a game"<<endl;
				else if(gameStatus == ENDED)
					restart();
				else
					cout<<"Sorry. Game over. No loan here."<<endl;
						break;
			case QUIT:
				return false;
		}
	}
	player.showCards();
	dealer.showCards();
	return true;
}


// give the player and dealer one more card
// check if we can do that first.
// and judge who has win the round if the player have 5 cards
void
SHGame::moreCard()
{	
	Card newCard(dealer.giveCardID());
	player.addCard(newCard);
	newCard.setID(dealer.giveCardID());
	dealer.addCard(newCard);
	if(player.getNumCards()==5){
		dealer.openFirstCard();
		endTurn(dealer.judge(player));
	}
}


// give up this round,
// and you'll lose your credit
// the bet is equivalent to the number of card you keep
void
SHGame::giveUp()
{
	dealer.openFirstCard();
	endTurn(DEALER_WIN);
}


// restart the game by giving each player two new cards
// need to check if any one broke (bankrupt).
void
SHGame::restart()
{
	player.start();
	dealer.start();
	for(int i=0;i<2;++i)
		moreCard();
	gameStatus = IN_PROGRESS;
}

void
SHGame::endTurn(Result turnResult)
{
	if(turnResult == DEALER_WIN){
		cout<<"I win. Try again.";
		player.setLoan(player.getLoan()-player.getNumCards()*betCredit);
		dealer.setLoan(dealer.getLoan()+player.getNumCards()*betCredit);
	}
	else if(turnResult == DEALER_LOSE){
		cout<<"You win. Good job.";
		player.setLoan(player.getLoan()+player.getNumCards()*betCredit);
		dealer.setLoan(dealer.getLoan()-player.getNumCards()*betCredit);
	}
	cout<<"(You have "<<player.getLoan()<<" points, I Have "<<dealer.getLoan()<<" points.)"<<endl;
	if(player.getLoan()<1||dealer.getLoan()<1)
		gameStatus = GAME_CALLED;
	else
		gameStatus = ENDED;
}
