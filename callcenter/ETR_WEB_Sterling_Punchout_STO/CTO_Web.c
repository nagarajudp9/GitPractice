CTO_Web()
{
	
	web_reg_save_param("cp_PriceSKUSPerformance","LB=\"sequence\":\"1\",\"skuList\":[\"","RB=\"]}};","Notfound=warning",LAST);

//lr_think_time(1);

web_reg_save_param("cp_LeadDays","LB=var _leadDays = \"","RB=\";","Notfound=warning",LAST);//var _leadDays = "14.0";

web_reg_save_param("cp_SecureKey","LB=var shaPwd = \"","RB=\";","Notfound=warning",LAST);

web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");

lr_start_transaction("CP20_CustomizeAndBuy");
	
	web_url("ConfigureView", 
		"URL=https://{p_hostName}/us-en/shop/ConfigureView?catalogId=10051&urlLangId=&langId=-1&storeId=10151&catEntryId={cp_CatEntryID}&quantity=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		LAST);
		
web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1532700181808&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?catalogId=10051&langId=-1&storeId=10151&urlLangId=&catEntryId={cp_CatEntryID}&quantity=1", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	
	splitskuarray("cp_PriceSKUSPerformance");
		
    web_convert_param("cp_ModelRefParam","SourceString={p_ModelRef}","SourceEncoding=HTML","TargetEncoding=URL",LAST);//US_005FStore%2FStore%2FNEW_0020_002D_0020SMB_0020Laptops%2Fx2_005F210_005FG2
	web_reg_save_param("cp_ConfigSKUS","LB=\"skus\":\"","RB=\",\"errors\":\"",LAST);   //"skus":"X5N97AV,X5N90AV,Z6W89AV,X5N91AV,X5N92AV,1EC54AV,X5N93AV,X5P10AV#ABA,X5N96AV,X7P13AV#ABA,M6P78AV,N4U81AV,X5N95AV,X5V65AV#ABA,X5V62AV#ABA,V3A50AV,X8Q05AV,V0W19AV#ABA,X5P11AV#ABA,V4L69AV,Y0Q17AV#ABA,X5N98AV","errors":"","tab
	web_reg_save_param("cp_CompPickArr","LB=type\":\"String\",\"path\":\"","RB/IC=\",\"name\":\"UI: DEFAULT SELECTION\",\"value\":\"yes\"","ORD=All","Convert=HTML_TO_URL",LAST);
	web_reg_save_param("cp_Config","LB=skus\":\"","RB=\",\"errors",LAST);    
	
	                   
	web_url("getconfigurationmodeljson",
		"URL=https://{p_ctohostName}/SterlingConfigRESTfulWebSvcApp/rest/configs/json/getconfigurationmodeljson?webSvcSessionID=&tokenID=&apiTemplateJSONString=&inJSONString=%7B%22include%22%3A%5B%7B%22clazz%22%3A%22Tab%22%7D%2C%7B%22clazz%22%3A%22Property%22%2C%22name%22%3A%22UI%3A+ICON+GRAPHIC%7C%7CUI%3A+DISPLAY+NAME%7C%7CUI%3A+DEFAULT+SELECTION%7C%7C_description%7C%7CUI%3A+PRODUCT+NAME%7C%7CUI%3A+OPTION+CLASS+VIEW%7C%7CUI%3A+LEAD+"
		"TIME%7C%7CHP_SHIP_DATE_CALENDAR_ID%7C%7CHP_Frogger_Message%7C%7CHP_Frogger_PublishedDate%7C%7CHP_UI_Frogger_DisplayMessage%7C%7CUI%3A+CONTROL%7C%7CUI%3A+SUPPRESS+NONE+SELECTION%7C%7CUI%3A+CONSTANT+GUIDING+TEXT%7C%7C_dsku%7C%7CUI%3A+DISPLAY+ADDITIONAL+"
		"INFO%7C%7C_startdate%7C%7C_enddate%7C%7C_sku%7C%7CHP_CROSSSELL_ITEMS%7C%7CHP_MODEL_HAS_CROSS_SELL%7C%7CHP_CLASS_HAS_CROSS_SELL%22%7D%5D%2C%22country%22%3A%22US%22%2C%22language%22%3A%22en%22%2C%22organizationCode%22%3A%22US_Store%22%2C%22path%22%3A%22{cp_ModelRefParam}%22%7D&callback=_jqjsp", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?catalogId=10051&urlLangId=&langId=-1&storeId=10151&catEntryId={cp_CatEntryID}&quantity=1", 
		"Snapshot=t450.inf", 
		LAST);
	
	
	
	web_convert_param("cp_ConfigSKUS",
	                  "SourceString={cp_ConfigSKUS}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	
	
	
	lr_save_string(lr_eval_string("%7B%22item%22%3A%22{cp_CompPickArr_1}%22%2C%22quantity%22%3A%221%22%7D"), "ReqURL");
		
	for (i=1; i<(lr_paramarr_len("cp_CompPickArr")); i++)
		{
			lr_save_string(lr_paramarr_idx("cp_CompPickArr", i+1), "CompItemID");
			lr_save_string(lr_eval_string("{ReqURL}%2C%7B%22item%22%3A%22{CompItemID}%22%2C%22quantity%22%3A%221%22%7D"), "ReqURL");
		}
	
	
	lr_save_string(lr_eval_string("{ReqURL}"),"FinalarrComponent");
	
	
/***********************************************************************************************************/
	memset(&skuarrSort[0], 0, sizeof(skuarrSort));	
	token = (char *)strtok((lr_eval_string("{cp_Config}")), ","); // Get the first token
        y=0;
        counter_2=0;
        while (token != NULL ) 
   {
        lr_output_message ("%s", token );
        snprintf(skuarrSort[y],bufsize - 1,"%s",token);
        lr_output_message ("%s", skuarrSort[y] );
        counter_2++;
        y++;
        token = (char *)strtok(NULL, ","); // Get the next token 
    }
    ///////////  
        memset(&finalSorted[0],0,sizeof(finalSorted));
        for(i=0;i<counter_2;i++)
        {   
        	if (cnt<counter_1)
        	{    
        		lr_save_string(skuarrSort[i],"Array2Val");
        		
        		for(j=0;j<counter_1;j++)
        			{		
        		 lr_save_string(skuarr[j],"Array1Val");
        		 if(strcmp(lr_eval_string("{Array1Val}"),lr_eval_string("{Array2Val}"))==0)
        		 {
        		 	snprintf(finalSorted[cnt],bufsize - 1,"%s",lr_eval_string("{Array2Val}"));
        		 	lr_output_message("%s",finalSorted[cnt]);
        		 	cnt++;
        			break;
        		 }
        		 
        			}
           
        }
        }



/***************************************************************************************************************/


	web_convert_param("cp_SecureKey",
	                  "SourceString={cp_SecureKey}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	web_reg_save_param("cp_PartNumArr","LB=\"","RB=\":{\"inventoryData\":{","ORD=All",LAST);//"Convert=HTML_TO_URL"
	//web_reg_save_param("cp_PriceArr","LB=priceData\":{\"price\":\"","RB=\",\"order","ORD=All",LAST);
	
	//web_reg_save_param("cp_PriceArr","LB=priceData\":{\"gmPoints\":\"0.00\",\"price\":\"","RB=\",\"order","ORD=All",LAST);
	web_reg_save_param("cp_PriceArr","LB=\",\"price\":\"","RB=\",\"order","ORD=All",LAST);
	
	web_custom_request("HPCTOServices", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/HPCTOServices?&partNumbers={cp_ConfigSKUS}&storeId=10151&langId=-1&parentPartNum={p_MRLastParam}&secureKey={cp_SecureKey}",
		"Method=POST", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?catalogId=10051&urlLangId=&langId=-1&storeId=10151&catEntryId={cp_CatEntryID}&quantity=1", 
		"Snapshot=t450.inf", 
		LAST);
	
	
			

memset(&PrimarySku[0], 0, sizeof(PrimarySku));
for (n=0; n<counter_1; n++)
{    
     lr_save_string(finalSorted[n],"Array1Val");
       for(o=1; o<=(lr_paramarr_len("cp_PartNumArr")); o++)
        {
           lr_save_string(lr_paramarr_idx("cp_PartNumArr", o), "PartNum");
               if(strcmp(lr_eval_string("{Array1Val}"),lr_eval_string("{PartNum}"))==0)
                {
                   strcat(PrimarySku,lr_eval_string("{Array1Val}"));  
                   	if(n<counter_1-1)
                   	{
                   		strcat(PrimarySku,",");
                   		  
                   	}
                    	  break;                  
                 }
               
        }
}
            
 lr_save_string(PrimarySku,"SortedPrimarySku");
  
 web_convert_param("SortedPrimarySku", "SourceEncoding=HTML","TargetEncoding=URL", LAST );

 

	//lr_think_time(1);
	//web_reg_find("Text={\"error\":null",LAST);
	
	web_reg_find("Text={\"error\":null","SaveCount=TextCheck1",LAST);
	
	web_custom_request("processconfigurationpicksjson", 
		"URL=https://{p_ctohostName}/SterlingConfigRESTfulWebSvcApp/rest/configs/json/processconfigurationpicksjson?webSvcSessionID=&tokenID=&apiTemplateJSONString=&inJSONString=%7B%22include%22%3A%5B%7B%22clazz%22%3A%22Messages%22%7D%2C%7B%22clazz%22%3A%22Property%22%2C%22name%22%3A%22_isViewable%7C%7C_quantity%7C%7C_rulePick%7C%7CUI%3A+PRE+PICK+GUIDING+TEXT%7C%7CUI%3A+POST+PICK+GUIDING+TEXT%7C%7CUI%3A+SUPPRESS+NONE+SELECTION%7C%7CUI%3A+"
		"REQUIRED%7C%7C_dsku%22%7D%5D%2C%22country%22%3A%22US%22%2C%22currency%22%3A%22USD%22%2C%22language%22%3A%22en%22%2C%22organizationCode%22%3A%22US_Store%22%2C%22path%22%3A%22{cp_ModelRefParam}%22%2C%22picks%22%3A%7B%22pick%22%3A%5B{FinalarrComponent}%5D%7D%2C%22addPick%22%3A%5B%5D%2C%22removePick%22%3A%5B%5D%7D&callback="
		"_jqjsp", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?catalogId=10051&urlLangId=&langId=-1&storeId=10151&catEntryId={cp_CatEntryID}&quantity=1", 
		"Snapshot=t452.inf", 
		LAST);
		

	web_url("PriceStrikeThroughDynamicKitDisplayCmd", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/PriceStrikeThroughDynamicKitDisplayCmd?usertype=&storeId=10151&catentryId={cp_CatEntryID}&skus={SortedPrimarySku}&crossSell=&currentDate={p_CurrentDate}", //Thu26Jan201706 orig part nums - X5N97AV%2CX5N90AV%2CX5N93AV%2CX5P10AV%23ABA%2CX5N96AV%2CX7P13AV%23ABA%2CM6P78AV%2CN4U81AV%2CX5N95AV%2CX5V65AV%23ABA%2CX5P11AV%23ABA%2CY0Q17AV%23ABA%2CX5N98AV
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?catalogId=10051&urlLangId=&langId=-1&storeId=10151&catEntryId={cp_CatEntryID}&quantity=1", 
		"Snapshot=t55.inf", 
		"Mode=HTML", 
		LAST);
	
	
	web_custom_request("getshipdate", 
		"URL=https://{p_ctohostName}/SterlingConfigRESTfulWebSvcApp/rest/configs/json/getshipdate?webSvcSessionID=&apiTemplateJSONString=&storeId=10151&calendarId=CTO-CALENDAR-NB&leadDays={cp_LeadDays}&currentDate={p_CurrentDate}&callback=_jqjsp", //&currentDate=Thu26Jan201708     14.0
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?catalogId=10051&urlLangId=&langId=-1&storeId=10151&catEntryId={cp_CatEntryID}&quantity=1", 
		"Snapshot=t467.inf", 
		LAST);

	
	lr_end_transaction("CP20_CustomizeAndBuy",LR_AUTO);
	
	cnt=0;
	
	lr_think_time(10);
	
	lr_save_string("YES","CTO");
	
	
	if(atoi(lr_eval_string("{TextCheck1}"))<=0)
	{
		//lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		
		lr_exit(LR_EXIT_ACTION_AND_CONTINUE,LR_AUTO);
		return 0;
	}

	
	
	return 0;
}
