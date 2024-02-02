/* Copyright (c) 1996 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     AnsiPrint.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Sep 25, 1996: Created.
***************************************************************************/

/* $Log: AnsiPrint.cc,v $
 * Revision 1.1  1996/10/09 10:34:59  li
 * Initial revision
 * */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include "AnsiPrint.h"

using namespace std;

// a few constant ansi formatting string
const char *init="\x1b[";
const char *endc="m";
const char *hilit="1;";
const char *blink="5;";
const char *recover="\x1b[0m";
const char *fgBase="30;";
const char *bgBase="40;";
const int kFormatStrSize=20;


char *strdup(const char *src) {
    char *dst = (char*) malloc(strlen (src) + 1);  // Space for length plus nul
    if (dst == NULL) return NULL;          // No memory
    strcpy(dst, src);                      // Copy the characters
    return dst;                            // Return the new string
}

/** 
 * This function takes a string and ansi formatting option such as 
 * foreground and background colors, hilighting for foreground color,
 * and blinking option and then send the appropriate string to the
 * standard output. 
 * The options except for the foreground color are optional. 
 */

void 
AnsiPrint(const char *str, color fg, color bg, bool hi, bool blinking) {

    // kick out exceptional case
    if ((str==NULL)||(strlen(str)==0))
        return;
    // creating foreground and background options
    char *foreground=strdup(fgBase);
    foreground[1]+=fg;
    char *background=strdup(bgBase);
    background[1]+=bg;
    // initialize the formatting string
    char formatStr[kFormatStrSize]="";
    strcat(formatStr, init);
    // according to the options, append appropriate string
    if (hi) {
        strcat(formatStr, hilit);
    }
    if (blinking) {
        strcat(formatStr, blink);
    }
    if (fg!=nochange) {
        strcat(formatStr, foreground);
    }
    if (bg!=nochange) {
        strcat(formatStr, background);
    }
    // terminate the options
    if (formatStr[strlen(formatStr)-1]==';')
        formatStr[strlen(formatStr)-1]= '\0';
    strcat(formatStr,endc);
    // print to the standard output
    cout << formatStr << str << recover;
    // delete allocated buffer
    free(background);
    free(foreground);
    return;

}

/** 
 * This function takes a string and ansi formatting option such as 
 * hilighting for foreground color,  and blinking option and 
 * then send the appropriate string to the standard output. 
 * The two options are optional. So, when no options are given,
 * it prints the string as normal string.
 */

void 
AnsiPrint(const char *str, bool hi, bool blinking) {

    // kick out exceptional case
    if ((str==NULL)||(strlen(str)==0))
        return;

    char formatStr[kFormatStrSize]="";
    if (hi||blinking) {
        // initialize the formatting string
        strcat(formatStr, init);
        // according to the options, append appropriate string
        if (hi) {
            strcat(formatStr, hilit);
        }
        if (blinking) {
            strcat(formatStr, blink);
        }
        if (formatStr[strlen(formatStr)-1]==';')
            formatStr[strlen(formatStr)-1]= '\0';
        strcat(formatStr,endc);
    }
    // print to the standard output
    cout << formatStr << str << recover;
    return;

}

