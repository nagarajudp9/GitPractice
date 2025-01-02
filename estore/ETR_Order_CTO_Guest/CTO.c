CTO()
{
	//web_set_max_html_param_len("999999");
	int pdpi,pdpcount1;
	
	
	if(strcmp(lr_eval_string("{cp_CatEntryID}"),"")==0 )
		
	{
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}
	
lr_start_transaction("S20_CustomizeAndBuy");
	
	
	
		
		
	web_set_max_retries ("5");	
	
//web_url("ConfigureView", 
//		"URL=https://{p_hostName}/us-en/shop/ConfigureView?langId=-1&storeId=10151&catalogId=10051&catEntryId={cp_CatEntryID}&urlLangId=&quantity=1", 
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=https://{p_hostName}/us-en/shop/pdp/{cp_pdpURL}", 
//		"Snapshot=t12.inf", 
//		"Mode=HTML", 
//		LAST);
//web_reg_save_param("cp_CatEntryID","LB=\"catentryId\":\"","RB=\",",LAST);

//web_reg_save_param("cp_MultiPDKSKUList","LB=.png\",\"skuList\":[","RB=]}","Ordinal=All","Notfound=warning",LAST);

web_reg_find("Search=All","SaveCount=cp_MultiPDKSKUList","Text=\"hasMultiplePDK\":true,",LAST);
web_reg_find("Search=All","SaveCount=c_CTOWeb","Text=ConfigureView",LAST);


web_url("sync",
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/ConfigureView%3FlangId%3D-1%26storeId%3D10151%26catalogId%3D10051%26catEntryId%3D{cp_CatEntryID}%26urlLangId%3D%26quantity%3D1/sync", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?langId=-1&storeId=10151&catalogId=10051&catEntryId={cp_CatEntryID}&urlLangId=&quantity=1", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
		
	
//	web_url("HPServices_4", 
//		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1627102127360&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?langId=-1&storeId=10151&catalogId=10051&catEntryId={cp_CatEntryID}&urlLangId=&quantity=1", 
//		"Snapshot=t13.inf", 
//		"Mode=HTML", 
//		LAST);


if(strcmp(lr_eval_string("{cp_SecureKey}"),"")==0 || strcmp(lr_eval_string("{cp_LeadDays}"),"")==0 || strcmp(lr_eval_string("{c_CTOWeb1}"),"0")==0 ||strcmp(lr_eval_string("{c_CTOWeb2}"),"0")==0)
	{
		lr_end_transaction(lr_eval_string("S20_CustomizeAndBuy"),LR_FAIL);
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	web_convert_param("cp_pdpname",
	                  "SourceString={productName}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	
	
web_convert_param("cp_ConfigSKUS",
	                  "SourceString={p_ConfigSKUS}",
	                  "SourceEncoding=URL",
	                  "TargetEncoding=HTML",
	                  LAST);
	                  
 web_convert_param("SortedPrimarySku",
	                  "SourceString={SortedPrimarySku}",
	                  "SourceEncoding=URL",
	                  "TargetEncoding=PLAIN",
	                  LAST);
	  
	  lr_save_string(string_replace(lr_eval_string("{SortedPrimarySku}"),"#","%23"),"SortedPrimarySku");

 web_reg_save_param("parentPartNum","LB=item\":\"","RB=\"}",LAST);
	 
	 lr_start_sub_transaction(lr_eval_string("S20-1_CustomizeAndBuy_SinglePDK"),"S20_CustomizeAndBuy");
	 
	 web_custom_request("processconfigurationpicksjson", 
		"URL=https://{p_ctohostName}/SterlingConfigRESTfulWebSvcApp/rest/configs/json/processconfigurationpicksjson?webSvcSessionID=&tokenID=&apiTemplateJSONString=&inJSONString=%7B%22include%22%3A%5B%7B%22clazz%22%3A%22Messages%22%7D%2C%7B%22clazz%22%3A%22Property%22%2C%22name%22%3A%22_isViewable%7C%7C_quantity%7C%7C_rulePick%7C%7CUI%3A+PRE+PICK+GUIDING+TEXT%7C%7CUI%3A+POST+PICK+GUIDING+TEXT%7C%7CUI%3A+SUPPRESS+NONE+SELECTION%7C%7CUI%3A+"
		"REQUIRED%7C%7C_dsku%22%7D%5D%2C%22country%22%3A%22US%22%2C%22currency%22%3A%22USD%22%2C%22language%22%3A%22en%22%2C%22organizationCode%22%3A%22US_Store%22%2C%22path%22%3A%22{cp_ModelRefParam}%22%2C%22picks%22%3A%7B%22pick%22%3A%5B{FinalarrComponent}%5D%7D%2C%22addPick%22%3A%5B%5D%2C%22removePick%22%3A%5B%5D%7D&callback="
		"_jqjsp", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?catalogId=10051&urlLangId=&langId=-1&storeId=10151&catEntryId={cp_CatEntryID}&quantity=1", 
		"Snapshot=t452.inf", 
		LAST);

	  if(strcmp(lr_eval_string("{parentPartNum}"),"")==0)
	{
		lr_end_transaction(lr_eval_string("S20_CustomizeAndBuy"),LR_FAIL);
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	
		web_url("HPCTOLeadTimeService", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/HPCTOLeadTimeService?&parentSku={p_PartNumber}&skus={SortedPrimarySku}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?urlLangId=&catalogId=10051&langId=-1&storeId=10151&catEntryId={cp_CatEntryID}&quantity=1", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
	
	  
	web_reg_save_param("ShipDate","LB=shipDate\": \"","RB=\"}",LAST);
	
	web_url("getshipdate", 
		"URL=https://{p_ctohostName}/SterlingConfigRESTfulWebSvcApp/rest/configs/json/getshipdate?storeId=10151&webSvcSessionID=&apiTemplateJSONString=&calendarId=CTO-CALENDAR-NB&leadDays=20.0&currentDate={p_CurrentDate}&callback=_ship_id", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	      lr_end_sub_transaction(lr_eval_string("S20-1_CustomizeAndBuy_SinglePDK"),LR_AUTO);
	   
	  if(strcmp(lr_eval_string("{ShipDate}"),"")==0)
	{
		lr_end_transaction(lr_eval_string("S20_CustomizeAndBuy"),LR_FAIL);
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	  
	 	
	  	  
	//  web_reg_save_param("cp_krypto","LB=&krypto=","RB=&ddkey", LAST);
	  
	  
	  
	web_url("PriceStrikeThroughDynamicKitDisplayCmd", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/PriceStrikeThroughDynamicKitDisplayCmd?storeId=10151&usertype=&catentryId={cp_CatEntryID}&skus={SortedPrimarySku}&crossSell=&pStoreId=&currentDate={p_CurrentDate}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?langId=-1&storeId=10151&catalogId=10051&catEntryId={cp_CatEntryID}&urlLangId=&quantity=1", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

		 
	 if(atoi(lr_eval_string("{c_CTOWeb}"))>0)
    {
	lr_end_transaction("S20_CustomizeAndBuy",LR_PASS);
    }
    else
    {
	lr_end_transaction("S20_CustomizeAndBuy",LR_FAIL);
	
    lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
    }
 
	 lr_think_time(10);
	 
 if(atoi(lr_eval_string("{cp_MultiPDKSKUList}"))>0)	 
	
	{
		
	  //	lr_save_string(string_replace(lr_eval_string("{cp_MultiPDKSKUList_2}"),"\"",""),"SortedPrimarySku");
	  	
	  	
	  	
	  	lr_start_transaction("S20-1_CustomizeAndBuy_MultiPDK");
	  	
	  	 web_reg_save_param("parentPartNum","LB=item\":\"","RB=\"}",LAST);	 
	
	 web_custom_request("processconfigurationpicksjson", 
		"URL=https://{p_ctohostName}/SterlingConfigRESTfulWebSvcApp/rest/configs/json/processconfigurationpicksjson?webSvcSessionID=&tokenID=&apiTemplateJSONString=&inJSONString=%7B%22include%22%3A%5B%7B%22clazz%22%3A%22Messages%22%7D%2C%7B%22clazz%22%3A%22Property%22%2C%22name%22%3A%22_isViewable%7C%7C_quantity%7C%7C_rulePick%7C%7CUI%3A+PRE+PICK+GUIDING+TEXT%7C%7CUI%3A+POST+PICK+GUIDING+TEXT%7C%7CUI%3A+SUPPRESS+NONE+SELECTION%7C%7CUI%3A+"
		"REQUIRED%7C%7C_dsku%22%7D%5D%2C%22country%22%3A%22US%22%2C%22currency%22%3A%22USD%22%2C%22language%22%3A%22en%22%2C%22organizationCode%22%3A%22US_Store%22%2C%22path%22%3A%22{cp_ModelRefParam}%22%2C%22picks%22%3A%7B%22pick%22%3A%5B{FinalarrComponent}%5D%7D%2C%22addPick%22%3A%5B%5D%2C%22removePick%22%3A%5B%5D%7D&callback="
		"_jqjsp", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?catalogId=10051&urlLangId=&langId=-1&storeId=10151&catEntryId={cp_CatEntryID}&quantity=1", 
		"Snapshot=t452.inf", 
		LAST);

	  	// web_reg_save_param("cp_PromPrice","LB=\"PromPrice\": ","RB=,",LAST);	
	  	 
	  	// web_reg_find("Search=All","SaveCount=c_PriceSKU","Text=\"viewTaskName\": \"PSTDisplayCmdResponseView\"",LAST);
 //"PromPrice": 1659.99, "
	  
	  web_url("PriceStrikeThroughDynamicKitDisplayCmd",
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/PriceStrikeThroughDynamicKitDisplayCmd?usertype=&storeId=10151&catentryId={cp_CatEntryID}&skus={SortedPrimarySku}&crossSell=&currentDate={p_CurrentDate}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?catalogId=10051&urlLangId=&langId=-1&storeId=10151&catEntryId={cp_CatEntryID}&quantity=1", 
		"Snapshot=t55.inf", 
		"Mode=HTML", 
		LAST);
 
	  	web_url("HPCTOLeadTimeService", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/HPCTOLeadTimeService?&parentSku={p_PartNumber}&skus={SortedPrimarySku}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?urlLangId=&catalogId=10051&langId=-1&storeId=10151&catEntryId={cp_CatEntryID}&quantity=1", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
	
	  	//  web_reg_save_param("ShipDate","LB=shipDate\": \"","RB=\"}",LAST);
	  
	  
		web_url("getshipdate", 
		"URL=https://{p_ctohostName}/SterlingConfigRESTfulWebSvcApp/rest/configs/json/getshipdate?webSvcSessionID=&apiTemplateJSONString=&storeId=10151&calendarId=CTO-CALENDAR-NB&leadDays=20&currentDate={p_CurrentDate}&callback=_jqjsp", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?catalogId=10051&langId=-1&storeId=10151&urlLangId=&catEntryId={cp_CatEntryID}&quantity=1", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
	
	 
	  	 
	  	lr_end_transaction(lr_eval_string("S20-1_CustomizeAndBuy_MultiPDK"),LR_AUTO);
		
	  }
	 	web_set_max_html_param_len("1024");
	
	return 0;
}
