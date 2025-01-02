AppStore_SLP()
{
		int SLPi,SLPcount1,SLPcount;
	lr_think_time(10);

	
	web_reg_find("Text=SLPBody","SaveCount=SLP_Products",LAST);
	web_reg_save_param("cp_SLPitemId","LB=\"itemId\":\"","RB=\",","ORD=ALL",LAST);
	
	web_reg_save_param_regexp("ParamName=cp_catEntryIdAddtocart","RegExp=\"itemId\":\"(.*?)\",","Notfound=warning",LAST);
	
	web_save_timestamp_param("cp_time", LAST); 


lr_start_transaction(lr_eval_string("{AgentType}S10_SLP"));

	web_url("p_SLP", 
		"URL=https://{p_hostName}/us-en/shop/slp/{p_SLP}{StoreType}",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
		
SLPcount1=atoi(lr_eval_string("{cp_SLPitemId_count}"));
	if(SLPcount1 == 0)
	{
	
		lr_end_transaction(lr_eval_string(lr_eval_string("{AgentType}S10_SLP")),LR_FAIL);	
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);		
	}	
	else	
		
	{
	lr_save_string(lr_eval_string("{cp_SLPitemId_1}"), "SLPURL");
		for (SLPi=1; SLPi<(lr_paramarr_len("cp_SLPitemId")); SLPi++)
		{
			lr_save_string(lr_paramarr_idx("cp_SLPitemId", SLPi+1), "SLPCatID");
		
			SLPcount=atoi(lr_eval_string("{SLPCatID}"));
						
	if(SLPcount == 0)
	{			
	
	}
	else
	{
	

lr_save_string(lr_eval_string("{SLPURL},{SLPCatID}"), "SLPURL");				
	}
		}		
	}
	
	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cupids&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/slp/{p_SLP}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);


	/*web_url("dealsapi", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151",  
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/slp/{p_SLP}", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);*/
	
	if( eppFlag == 1 || silverFlag == 1 || goldFlag == 1 || platinumFlag == 1 ||  euaFlag == 1 )

	{

  	//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S10_SLP")));
	web_save_timestamp_param("cp_time", LAST);
	web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151{StoreType1}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    
    	
	//lr_end_sub_transaction("S17-1_DealsAPI", LR_AUTO);
	
	}

	else

  	{ 
 
    	//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S10_SLP")));
        web_save_timestamp_param("cp_time", LAST);
    	web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    
    
    	//lr_end_sub_transaction("S17-1_DealsAPI", LR_AUTO);

	}
	
	web_url("HPServices_16", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1641367188353&action=cusipd&catentryId={SLPURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/slp/{p_SLP}", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		LAST);

	if(atoi(lr_eval_string("{SLP_Products}"))>0)
		{
		lr_end_transaction(lr_eval_string("{AgentType}S10_SLP"),LR_PASS);
		AddToCartFlag = 1;
		lr_save_string("_SLP","cartitem");
		}
		else
		{
			lr_end_transaction(lr_eval_string("{AgentType}S10_SLP"),LR_FAIL);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}


	return 0;
}
