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
		/* 注意: 這邊皆需要檢查當前gameStatus能否執行該動作，
		ex: 遊戲中不能直接restart，需要先結束遊戲or放棄 */
		switch(menu.getAnswer()){
			case ONE_MORE:
				if (gameStatus == IN_PROGRESS)
					moreCard();
				else
					cout<<"GAME OVER!"<<endl;
				break;
			case GIVE_UP:
				/*	FIB2: 在遊戲中，玩家選擇放棄	*/;
				cout << "FIB2: When in game, Player choose to giveup\n";
				break;
			case RESTART:
				/*	FIB3: 在遊戲結束後，玩家選擇重新一局	*/;
				cout << "FIB3: After the game ends, Player chooses to restart a new game. \n";
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
	/* FIB1: 各發一張牌*/
	Card newCard1(dealer.giveCardID());
	Card newCard2(dealer.giveCardID());
	cout << "FIB1: Give both the player and dealer a card\n";
	
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


// 重新開始遊戲，並每人發兩張牌
// 需先檢查Dealer與Player是否還有足夠的錢
void
SHGame::restart()
{
	/* 填空四: 檢查是否有足夠的錢 */
	cout << "FIB4: Check if both players have enough money to keep playing.\n";

	player.start();
	dealer.start();
	
	//發兩張牌
	moreCard();
	moreCard();
		
	gameStatus = IN_PROGRESS;
}

void
SHGame::endTurn(Result turnResult)
{
	if(turnResult == DEALER_WIN){
		/* 填空五 宣布誰獲勝 */
		cout << "FIB5: Declare who wins.\n";
		player.setLoan(player.getLoan()-player.getNumCards()*betCredit);
		dealer.setLoan(dealer.getLoan()+player.getNumCards()*betCredit);
	}
	else if(turnResult == DEALER_LOSE){
		/* 填空五 宣布誰獲勝 */
		cout << "FIB5: Declare who wins.\n";
		player.setLoan(player.getLoan()+player.getNumCards()*betCredit);
		dealer.setLoan(dealer.getLoan()-player.getNumCards()*betCredit);
	}
	cout<<"(You have "<<player.getLoan()<<" points, I Have "<<dealer.getLoan()<<" points.)"<<endl;
	if(player.getLoan()<1||dealer.getLoan()<1)
		gameStatus = GAME_CALLED;
	else
		gameStatus = ENDED;
}
