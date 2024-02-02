/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#ifndef _CARD_H_
#define _CARD_H_

class Card {

public:
    // a few card related constants
    static const int kNPip = 13;
    static const int kNSuit = 4;
    // total number of cards for a standard deck of poker cards
    static const int kNCards = 52;
    // suit types
    enum Suit {spade, heart, diamond, club};

    // Constructor
    Card(int myId = 0);

    // accessors
    int getID() const;
    int getPip() const;
    int getSuit() const;

    // modifiers
    void setID(int newId);

private:

    // your private or internal stuff goes here
	int id;
	int pip;
	int suit;

};

#endif // _CARD_H_
