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
int SignInFormFlag=0, GuestFlag=0, LoginFlag=0, hpeppFlag=0, eppFlag=0, gsFlag=0, ctoFlag=0, gs_ccFlag=0, CustomerFlag=0, SmbFlag=0, CarepackFlag=0;
int i,j,k,MJ;
int nFound,mFound;

//Customer search
char spara[200];
char parakey[200];


int i,y,cnt,j,k,n,r,o,counter_1,counter_2,counter_3;
//char arrPriceSkus[1024];
//char arrCompon[1024];
char PrimarySku[1024];
char separators[]="\",\"";
char * token;
char skuarr[1024][1024];
char skuarrSort[1024][1024];
char finalSorted[1024][1024];
//char skuarrModification[1024][1024];
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
