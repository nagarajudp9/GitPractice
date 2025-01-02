AppStore_PLP()

{
	
	/* Validation Date : 09-04-2022
	   Release         : FY22 - R3
	   Resource        : Nagaraju */

	int PLPi,PLPcount1;
	
	lr_think_time(10);


	web_reg_save_param_regexp("ParamName=cp_catEntryIdAddtocart","RegExp=\"itemId\":\"(.*?)\",(.*?)\"prdClass\":\"STO\",","Notfound=warning", "Group=1",LAST);
	web_save_timestamp_param("cp_time", LAST); //1600153594317 
	web_reg_save_param("cp_PLPcatentryId","lb=\"itemId\":\"","rb=\",","ord=all",LAST);
	web_reg_find("Text=plp-root","SaveCount=PLP_Products",LAST);

lr_start_transaction(lr_eval_string("{AgentType}S11_PLP"));

	web_url("{p_PLP}", 
		"URL=http://{p_hostName}/us-en/shop/plp/{p_PLP}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
		
PLPcount1=atoi(lr_eval_string("{cp_PLPcatentryId_count}"));
	if(PLPcount1 == 0)
	{
	
		lr_end_transaction(lr_eval_string(lr_eval_string("{AgentType}S11_PLP")),LR_FAIL);	
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);		
	}	
	else	
		
	{
	lr_save_string(lr_eval_string("{cp_PLPcatentryId_1}"), "PLPURL");
		for (PLPi=1; PLPi<(lr_paramarr_len("cp_PLPcatentryId")); PLPi++)
		{
			lr_save_string(lr_paramarr_idx("cp_PLPcatentryId", PLPi+1), "PLPCatID");
			lr_save_string(lr_eval_string("{PLPURL},{PLPCatID}"), "PLPURL");
		}
		
	}
		
	web_save_timestamp_param("cp_time", LAST);	
	
	web_url("HPServices",
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cupids&catentryId={PLPURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/plp/{p_PLP}", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_save_timestamp_param("cp_time", LAST);
	//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S11_PLP")));
		
	 web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST); 
	
	//lr_end_sub_transaction("S17-1_DealsAPI", LR_AUTO);
	
	web_save_timestamp_param("cp_time", LAST);
	
	web_reg_find("Text=\"lowStock\": true", "SaveCount=c_OutOfStock", LAST);

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cusipds&catentryId={PLPURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/plp/{p_PLP}", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	if(atoi(lr_eval_string("{PLP_Products}"))>0)
		{
		lr_end_transaction(lr_eval_string("{AgentType}S11_PLP"),LR_PASS);
		AddToCartFlag = 1;
					
		lr_save_string("3074457345619560337","cp_catEntryIdAddtocart");
		lr_save_string("_PLP","cartitem");
		}
		else
		{
			lr_end_transaction(lr_eval_string("{AgentType}S11_PLP"),LR_FAIL);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}


	return 0;
}
