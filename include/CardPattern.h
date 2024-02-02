/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     CardPat.h
   PURPOSE
     Bitmaps for the poker cards
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 5, 1998: Created.
***************************************************************************/

#include "AnsiPrint.h"

// number of characters in width for displaying a card
const int kCardWidth = 11;
// number of characters in height for displaying a card
const int kCardHeight = 11;
// data for use with the card printing
const char cardAbbrev[] = "SHDC";
// data for use with the card printing
const color cardColor[] = {black, red, red, black};
// // maximal number of cards to be print in a row before wrapping
const int kNCardPerRow = 5;

/* 'x's are special characters that will be replaced in printing */
const char card[14][kCardHeight][kCardWidth+1] = {{
  "***********",
  "*1x       *",
  "*         *",
  "*         *",
  "*         *",
  "*    x    *",
  "*         *",
  "*         *",
  "*         *",
  "*        1*",
  "***********"
}, {
  "***********",
  "*2x       *",
  "*         *",
  "*    x    *",
  "*         *",
  "*         *",
  "*         *",
  "*    x    *",
  "*         *",
  "*        2*",
  "***********"
}, {
  "***********",
  "*3x       *",
  "*         *",
  "*    x    *",
  "*         *",
  "*    x    *",
  "*         *",
  "*    x    *",
  "*         *",
  "*        3*",
  "***********"
}, {
  "***********",
  "*4x       *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*         *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*        4*",
  "***********"
}, {
  "***********",
  "*5x       *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*    x    *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*        5*",
  "***********"
}, {
  "***********",
  "*6x       *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*        6*",
  "***********"
}, {
  "***********",
  "*7x       *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*  x x x  *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*        7*",
  "***********"
}, {
  "***********",
  "*8x       *",
  "*         *",
  "*  x   x  *",
  "*    x    *",
  "*  x   x  *",
  "*    x    *",
  "*  x   x  *",
  "*         *",
  "*        8*",
  "***********"
}, {
  "***********",
  "*9x       *",
  "*  x   x  *",
  "*         *",
  "*  x   x  *",
  "*    x    *",
  "*  x   x  *",
  "*         *",
  "*  x   x  *",
  "*        9*",
  "***********"
}, {
  "***********",
  "*10x      *",
  "*  x   x  *",
  "*    x    *",
  "*  x   x  *",
  "*         *",
  "*  x   x  *",
  "*    x    *",
  "*  x   x  *",
  "*       10*",
  "***********"
}, {
  "***********",
  "*Jx       *",
  "*  xxxxx  *",
  "*     x   *",
  "*     x   *",
  "*     x   *",
  "*     x   *",
  "*  x  x   *",
  "*   xxx   *",
  "*        J*",
  "***********"
}, {
  "***********",
  "*Qx       *",
  "*   xxx   *",
  "*  x   x  *",
  "*  x   x  *",
  "*  x   x  *",
  "*  x  xx  *",
  "*   xxxx  *",
  "*       x *",
  "*        Q*",
  "***********"
}, {
  "***********",
  "*Kx       *",
  "*  x   xx *",
  "*  x  x   *",
  "*  x x    *",
  "*  xx     *",
  "*  x x    *",
  "*  x  x   *",
  "*  x   xx *",
  "*        K*",
  "***********"
}, {
  "           ",
  "           ",
  "           ",
  "           ",
  "           ",
  "           ",
  "           ",
  "           ",
  "           ",
  "           ",
  "           "
}};

