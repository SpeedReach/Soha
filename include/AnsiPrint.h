/* Copyright (c) 1996 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     AnsiPrint.h
   PURPOSE
     Print Text with color in Ansi-enabled terminal
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Sep 25, 1996: Created.
***************************************************************************/

/* $Log: AnsiPrint.h,v $
 * Revision 1.1  1996/10/09 10:34:59  li
 * Initial revision
 * */

#ifndef _ANSIPRINT_H
#define _ANSIPRINT_H

enum color {black=0, red, green, yellow, blue, pink, cyan, white, nochange};

// format and print a string with the given ansi coloring options
void AnsiPrint(const char *str, color fg, color bg = nochange, 
	           bool hi = false, bool blinking = false);
void AnsiPrint(const char *str, bool hi = false, bool blinking = false);

#endif
