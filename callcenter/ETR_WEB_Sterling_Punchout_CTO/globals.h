#ifndef _GLOBALS_H 
#define _GLOBALS_H

//--------------------------------------------------------------------
// Include Files
#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"

//--------------------------------------------------------------------
// Global Variables

int pmaxValue=0, prandNumber=0;
int SignInFormFlag=0, GuestFlag=0, CarepackFlag=0,LoginFlag=0, hpeppFlag=0, eppFlag=0, gsFlag=0, ctoFlag=0,gs_ccFlag=0,CustomerFlag, SmbFlag=0,mFound=0,CrossSellNonCross=1;
int i,j,k,MJ;
int nFound,mFound;
//int i,mj;


char *string_replace(char *input_string,
    char *substring_to_be_replaced,
    char *substitution_string)

 {

// strstr function declaration
 char *strstr(const char *s1, const char *s2); 

// newstring variable the new string to be returned
// increase the buffer size if needed. Default is 200

char newstring[1024]=""; 

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
 
 
//Customer search
char spara[200];
char parakey[200];

int i,y,cnt,j,k,n,r,o,counter_1,counter_2,counter_3;
char arrPriceSkus[1024];
char arrCompon[1024];
char PrimarySku[1024];
char separators[]="\",\"";
char * token;
char skuarr[1024][1024];
char skuarrSort[1024][1024];
char finalSorted[1024][1024];
char skuarrModification[1024][1024];
//char bufsize =1024;
enum { bufsize =1024 };

void splitskuarray(const char* paramName){
	
	
	char* srcq=0;
    char enclosedParamName[1024];
	sprintf(enclosedParamName, "{%s}", paramName);
    srcq=lr_eval_string(enclosedParamName);
    token = (char *)strtok(srcq, separators); // Get the first token
       
        counter_1=0;
    memset(&skuarr[0],0,sizeof(skuarr));     
        while (token != NULL ) 
   {
        lr_output_message ("%s", token );
        snprintf(skuarr[counter_1],bufsize - 1,"%s",token);
        counter_1++;
        token = (char *)strtok(NULL, separators); // Get the next token 
       
   }
}
      


void removeQuotes(const char* paramName)
{
    
    char* psrc=0;
    char* dst = 0;
    char* pdst = 0;
    int srclen=0;
    char c;
    char buf[5];
	char* src=0;
    char enclosedParamName[1024];

    sprintf(enclosedParamName, "{%s}", paramName);
    src=lr_eval_string(enclosedParamName);

    srclen = strlen(src)+1;

    dst = (char*)malloc(srclen);
    memset(dst, 0, srclen);

    for(psrc=src, pdst = dst; *psrc != '\0'; pdst++)
    {
         if(*psrc== '"')
        {
           *pdst  = *(psrc + 1) ;
            psrc += 2;
       }
        else
        {
            *pdst = *psrc;
            ++psrc;
        }    
    }
    *(pdst) = '\0';

    lr_save_string(dst,paramName);
   
    free(dst);
}

void removecomma(const char* paramName)
{
    char* src=0;
    char* psrc=0;
    char* dst = 0;
    char* pdst = 0;
    int srclen=0;
    char c;
    char buf[5];

    char enclosedParamName[1024];

    sprintf(enclosedParamName, "{%s}", paramName);
    src=lr_eval_string(enclosedParamName);

    srclen = strlen(src)+1;

    dst = (char*)malloc(srclen);
    memset(dst, 0, srclen);

    for(psrc=src, pdst = dst; *psrc != '\0'; pdst++)
    {
    	if(*psrc==',')
        {
           *pdst  = *(psrc + 1) ;
            psrc += 2;
       }
        else
        {
            *pdst = *psrc;
            ++psrc;
        }    
    }
    *(pdst) = '\0';

    lr_save_string(dst,paramName);
   
    free(dst);
}

//#endif // _GLOBALS_H
