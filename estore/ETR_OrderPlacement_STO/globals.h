#ifndef _GLOBALS_H
#define _GLOBALS_H

//--------------------------------------------------------------------
// Include Files
#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"

//--------------------------------------------------------------------
// Global Variables

//int pmaxValue=0, prandNumber=0;
int SignInFormFlag=0, GuestFlag=0, LoginFlag=0, hpeppFlag=0, eppFlag=0, gsFlag=0, ctoFlag=0, gs_ccFlag=0, orderflag=0, euaFlag=0, CarepackFlag=0,silverFlag=0,goldFlag=0,platinumFlag=0,loyaltyFlag=0,Preorder=0,Subscription=0;
int i,j,k;
int nFound;
char spara[100];
long file;

int pType,oType;

int mj;
// To remove cetain charater from the captured value


char *string_replace(char *input_string,
    char *substring_to_be_replaced,
    char *substitution_string)

 {

// strstr function declaration
 char *strstr(const char *s1, const char *s2); 

// newstring variable the new string to be returned
// increase the buffer size if needed. Default is 200

char newstring[200]=""; 

// str is a temporary pointer to aid in creation of newstring;
// it points at the beginning of each substring that
// needs to be included in the new string.

char *str; 

// ptr is a pointer to hold strstr result.

char *ptr; 

str = input_string;

// search for substring_to_be_replaced and
// replace with substitution_string

 while((ptr = strstr(input_string, substring_to_be_replaced))!=NULL)
 {
 input_string = &ptr[strlen(substring_to_be_replaced)];
 ptr[0] = '\0';
 strcat(newstring, str);
 strcat(newstring, substitution_string);
 str = input_string;
 }

// concatenate the rest of the string

strcat(newstring, input_string);

return newstring;

 }
 #endif
// _GLOBALS_H
