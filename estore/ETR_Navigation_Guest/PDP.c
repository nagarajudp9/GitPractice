PDP()
{
		/* Validation Date : 09-04-2022
	   Release         : FY22 - R3
	   Resource        : Nagaraju */
	
	int pdpi,pdpcount;
	
	lr_think_time(30);	
	
	web_reg_save_param("cp_PDPproductId","LB=\"catentryId\":\"","RB=\",","ORD=ALL",LAST);
	web_reg_find("Text=pdp-details","SaveCount=PDP_Products",LAST);
	web_reg_save_param_regexp("ParamName=cp_catEntryIdAddtocart","RegExp=\"catentryId\":\"(.*?)\",(.*?)\"product_type\":\"STO\",","Notfound=warning", "Group=1",LAST);
	web_save_timestamp_param("cp_time", LAST);


	lr_start_transaction(lr_eval_string("{AgentType}S08_PDP"));
	
	//web_set_max_retries ("5");
	
	web_url("p_PDP", 
		"URL=https://{p_hostName}/us-en/shop/pdp/{p_PDP}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	pdpcount=atoi(lr_eval_string("{cp_PDPproductId_count}"));	
		if(pdpcount == 0)
		{
			
		lr_end_transaction("S08_PDP",LR_FAIL);
    	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	
		}	
		else
		{
			lr_save_string(lr_eval_string("{cp_PDPproductId_1}"), "PDPURL");
			for (pdpi=1; pdpi<(lr_paramarr_len("cp_PDPproductId")); pdpi++)
			{
				lr_save_string(lr_paramarr_idx("cp_PDPproductId", pdpi+1), "PDPCatID");
				lr_save_string(lr_eval_string("{PDPURL},{PDPCatID}"), "PDPURL");
			}
		}

	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cupids&catentryId={PDPURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDP}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);
	
		
	web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/pdp%2F{p_PDP}/async", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDP}", 
		"Snapshot=t29.inf", 
		"Mode=HTTP", 
		LAST);
		
		
		web_save_timestamp_param("cp_time", LAST);
	//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S08_PDP")));
		
	 web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST); 
	
	//lr_end_sub_transaction("S17-1_DealsAPI", LR_AUTO);
		
web_reg_find("Text=\"lowStock\": true", "SaveCount=c_OutOfStock", LAST);
	
	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={PDPURL}&modelId=&langId=-1&storeId=10151&catalogId=10051",		
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDP}", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);

		
	mFound = atoi(lr_eval_string("{c_OutOfStock}"));
	
	if(atoi(lr_eval_string("{PDP_Products}"))>0 && mFound == 0)
		
	{
		lr_end_transaction(lr_eval_string("{AgentType}S08_PDP"),LR_PASS);
		//AddToCartFlag = 1;
		lr_save_string("PDP","cartitem");
	}
	
	else
	{
		lr_end_transaction(lr_eval_string("{AgentType}S08_PDP"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	return 0;
}
