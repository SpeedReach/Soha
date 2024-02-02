/* Copyright (c) 1997 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     ConsoleMenu.h
   PURPOSE
     menu management
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 12, 1998: Created.
***************************************************************************/

/* $Log: ConsoleMenu.h,v $
 * */

#ifndef _CONSOLE_MENU_H
#define _CONSOLE_MENU_H

class ConsoleMenu {
  
public:
  // constructor: must give the number of items and the menu item strings
  ConsoleMenu(int numItem, const char * const * menuItems);

  // print the menu to the stdout
  void print() const;

  // change the content of the 'whichItem' menu item
  void setMenuItem(int whichItem, const char *menuItem);

  // get and return the user selection
  // it onlys checks for valid number input 
  // and will go crasy if a letter is entered.
  int getAnswer() const;
  
private:
  int nItems; // number of menu items
  char **items; // the content of these menu items
  
};

#endif
