Supplies()
{
	
	int PDP_Suppliesi,PDP_Suppliescount;
	lr_think_time(30);
	
	web_reg_find("Search=All","SaveCount=c_Category1","Text=INK, TONER & PAPER",LAST);
	web_reg_find("Search=All","SaveCount=c_Category2","Text=pdpSimilarSupplies",LAST);
	web_reg_find("Search=All","SaveCount=c_Home","Text=HomePage.jsp",LAST);
	
	web_set_option("MaxRedirectionDepth", "0", LAST);
	
	
	web_reg_save_param("C_PDP_SuppliescategoryId","LB=\"catentryId\":\"","RB=\",","ORD=ALL",LAST);
lr_start_transaction(lr_eval_string("{AgentType}CP08_PDP_Supplies"));
	
	web_url("{p_PDP_Supplies}", 
		"URL=https://{p_hostName}/us-en/shop/pdp/{p_PDP_Supplies}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	web_set_option("MaxRedirectionDepth", "10", LAST);

	
	//web_reg_find("Search=All","SaveCount=c_Category2","Text=productType\": \"SUPPLIES\"",LAST);
	web_reg_find("Search=All","SaveCount=c_Category3","Text=productType\": \"STO\"",LAST);
	
	 PDP_Suppliescount=atoi(lr_eval_string("{C_PDP_SuppliescategoryId_count}"));	
		if(PDP_Suppliescount == 0)
		{
			
			lr_end_transaction(lr_eval_string("{AgentType}CP08_PDP_Supplies"),LR_FAIL);			
		    lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
			
		}	
		else
		{
			lr_save_string(lr_eval_string("{C_PDP_SuppliescategoryId_1}"), "PDP_SuppliesURL");
			for (PDP_Suppliesi=1; PDP_Suppliesi<(lr_paramarr_len("C_PDP_SuppliescategoryId")); PDP_Suppliesi++)
			{
				lr_save_string(lr_paramarr_idx("C_PDP_SuppliescategoryId", PDP_Suppliesi+1), "PDP_SuppliesCatID");
				lr_save_string(lr_eval_string("{PDP_SuppliesURL}%2c{PDP_SuppliesCatID}"), "PDP_SuppliesURL");
			}
		}
    web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDP_Supplies}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);
    
		web_url("dealsapi", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDP_Supplies}", 
		"Snapshot=t28.inf", 
		"Mode=HTTP", 
		LAST);
    
		web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/pdp%2F{p_PDP_Supplies}/async", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDP_Supplies}", 
		"Snapshot=t29.inf", 
		"Mode=HTTP", 
		LAST);
		
		web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cupids&catentryId={PDP_SuppliesURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDP_Supplies}", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);
		
	web_url("HPServices",
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1645107200244&action=pid&catentryId={PDP_SuppliesURL}&modelId=&langId=-1&storeId=10151&catalogId=10051",		        
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDP_Supplies}", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	if(((atoi(lr_eval_string("{c_Category1}"))>0) || (atoi(lr_eval_string("{c_Category2}"))>0) || (atoi(lr_eval_string("{c_Category3}"))>0)) && (atoi(lr_eval_string("{c_Home}"))==0))
	{
		lr_end_transaction(lr_eval_string("{AgentType}CP08_PDP_Supplies"),LR_PASS);
//		AddToCartFlag = 1;
		lr_save_string("_Supplies","cartitem");
	}
	
	else
	{
		lr_end_transaction(lr_eval_string("{AgentType}CP08_PDP_Supplies"),LR_FAIL);
	}
	return 0;
	
}
