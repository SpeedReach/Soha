/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     ConsoleMenu.cc
   PURPOSE
     c++ implementation of console menu
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 12, 1998: Created.
***************************************************************************/

/* $Log: ConsoleMenu.cc,v $
 * */

#include <cstring>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include "ConsoleMenu.h"

using namespace std;


/**
 * Constructor: the only one. These is no default constructor
 */
ConsoleMenu::ConsoleMenu(int numItem, const char * const * menuItems) {

    // make sure that the number of items is greater than or equal to 0
    assert(numItem>=0);
    nItems=numItem;
    // allocate enough memory for hold the item pointers
    items = new char *[nItems];
    // duplicate each menu items
    for(int i=0; i<nItems; i++) {
        items[i]=strdup(menuItems[i]);
    }

}

/**
 * print the menu to the standard output
 */

void 
ConsoleMenu::print() const {

    //cout << endl;
    for(int i=0;i<nItems;i++) {
        cout << i+1 << ". " << items[i] << "   ";
    }

}

/**
 * change the content of a menu item
 */

void 
ConsoleMenu::setMenuItem(int whichItem, const char *menuItem) {

    if ((whichItem<0)||(whichItem>=nItems)) 
        return;
    free(items[whichItem]);
    items[whichItem]=strdup(menuItem);

}

/**
 * query the user for a selection
 * this function only make sure that the selection is within the
 * allowed range but doesn't check the validity of the input data
 * So, any non-integer input may drive it crazy.
 * Not satistied? Implement your own.
 */

int 
ConsoleMenu::getAnswer() const {

    int choice=0;
    string input;

    do {
        cout << "\tChoose one: ";

        getline(cin, input);
        choice = atoi(input.c_str());
        
    } while((choice<=0)||(choice>nItems));
    cout << endl;
    return choice;

}

