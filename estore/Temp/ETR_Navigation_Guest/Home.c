Home()
{
	/* Validation Date : 09-04-2022
	   Release         : FY22 - R3
	   Resource        : Nagaraju */
	
	int Homei,Homecount;
	
	lr_think_time(60);
	
	web_reg_find("Text=<div class=\"home\">","SaveCount=Home_count",LAST);
	web_save_timestamp_param("cp_time", LAST);  
	
	lr_start_transaction(lr_eval_string("{AgentType}S00_Homepage"));
		
	lr_start_sub_transaction("S00-1_Homepage",(lr_eval_string("{AgentType}S00_Homepage")));
		
	web_url("HomePage", 
		"URL=https://{p_hostName}/us-en/shop", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_sub_transaction("S00-1_Homepage", LR_AUTO);
	

	
	web_reg_save_param("cp_ClientID","LB=client_id=","RB=&amp","ORD=1","Notfound=Warning",LAST);
	
	web_url("HPServices_1",
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
	
	web_save_timestamp_param("cp_time", LAST); 
	
	//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S00_Homepage")));
		
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

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
		
	web_reg_save_param("cp_catentryID","LB=\",\"catentryId\":\"","RB=\",\"","ORD=ALL","Notfound=Warning",LAST);
	
	web_url("async",
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/%2F/async", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
		
	web_url("product", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/product?itemId={p_ItemId}&limit=12&select=itemId,sku,name,attributes", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

web_save_timestamp_param("cp_time", LAST); 	
		
	lr_start_sub_transaction("S00-2_HPServices",(lr_eval_string("{AgentType}S00_Homepage")));	
	
	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={p_HomeUrl}&modelId=&langId=-1&storeId=10151&catalogId=10051",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_sub_transaction("S00-2_HPServices", LR_AUTO);
	
	
	
	

		if(atoi(lr_eval_string("{Home_count}"))>0)
		{
			lr_end_transaction(lr_eval_string("{AgentType}S00_Homepage"),LR_PASS);
		}
		else
		{
			lr_end_transaction(lr_eval_string("{AgentType}S00_Homepage"),LR_FAIL);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);							
		}
	
	
	return 0;
}
