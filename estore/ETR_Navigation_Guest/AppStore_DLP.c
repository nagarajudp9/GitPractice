AppStore_DLP()
{
	/* Validation Date : 09-04-2022
	   Release         : FY22 - R3
	   Resource        : Nagaraju */
	
	int DLPi,DLPcount1;
	
	lr_think_time(10);
	
	web_reg_find("Search=All","SaveCount=c_DLP1","Text=dlp-product-list",LAST);
	web_reg_save_param("cp_ModelName","LB=tags\":[\"","RB=\"],","ORD=ALL",LAST);
	web_reg_save_param("cp_DLPcatentryId","lb=\"itemId\":\"","rb=\",","ord=all",LAST);
	
	
lr_start_transaction(lr_eval_string("{AgentType}S10_DLP"));

	web_url("{p_DLP}", 
		"URL=https://{p_hostName}/us-en/shop/dlp/{p_DLP}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
		
DLPcount1=atoi(lr_eval_string("{cp_DLPcatentryId_count}"));
	if(DLPcount1 == 0)
	{
	
		lr_end_transaction(lr_eval_string(lr_eval_string("{AgentType}S10_DLP")),LR_FAIL);	
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);		
	}	
	else	
		
	{
	lr_save_string(lr_eval_string("{cp_DLPcatentryId_1}"), "DLPURL");
		for (DLPi=1; DLPi<(lr_paramarr_len("cp_DLPcatentryId")); DLPi++)
		{
			lr_save_string(lr_paramarr_idx("cp_DLPcatentryId", DLPi+1), "DLPCatID");
			lr_save_string(lr_eval_string("{DLPURL},{DLPCatID}"), "DLPURL");
		}
		
	}

web_save_timestamp_param("cp_time", LAST); 


	web_url("HPServices_1",
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cupids&catentryId={DLPURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/dlp/{p_DLP}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
web_save_timestamp_param("cp_time", LAST); 
	
	web_reg_find("Text=\"lowStock\": true", "SaveCount=c_OutOfStock", LAST);
	
	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cupids&catentryId={DLPURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/dlp/{p_DLP}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
		
	web_save_timestamp_param("cp_time", LAST);
	//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S10_DLP")));
		
	 web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST); 
	
	//lr_end_sub_transaction("S17-1_DealsAPI", LR_AUTO);
	
	
	if(atoi(lr_eval_string("{c_DLP1}"))>0)
		{
		lr_end_transaction(lr_eval_string("{AgentType}S10_DLP"),LR_PASS);
		//AddToCartFlag = 1;
		//lr_save_string("","cartitem");
		}
		else
		{
			lr_end_transaction(lr_eval_string("{AgentType}S10_DLP"),LR_FAIL);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}


	return 0;
}
