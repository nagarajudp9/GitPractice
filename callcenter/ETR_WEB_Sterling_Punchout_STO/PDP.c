PDP()
{
	
	int pdpi,pdpcount;
	
	lr_think_time(30);	
	
	web_reg_save_param("cp_PDPproductId","LB=\"catentryId\":\"","RB=\",","ORD=ALL",LAST);
	web_reg_find("Text=pdp-details","SaveCount=PDP_Products",LAST);
	web_reg_save_param_regexp("ParamName=cp_catEntryIdAddtocart","RegExp=\"catentryId\":\"(.*?)\",(.*?)\"product_type\":\"STO\",","Notfound=warning", "Group=1",LAST);
	web_save_timestamp_param("cp_time", LAST);


	lr_start_transaction(lr_eval_string("{AgentType}CP08_PDP"));
	
	web_url("p_PDP", 
		"URL=https://{p_hostName}/us-en/shop/pdp/{p_pdp}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	pdpcount=atoi(lr_eval_string("{cp_PDPproductId_count}"));	
		if(pdpcount == 0)
		{
			
		lr_end_transaction("CP08_PDP",LR_FAIL);
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
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);
			
	web_url("dealsapi", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp}", 
		"Snapshot=t28.inf", 
		"Mode=HTTP", 
		LAST);
	
	web_url("async",
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/pdp%2F{p_pdp}/async", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp}", 
		"Snapshot=t29.inf", 
		"Mode=HTTP", 
		LAST);
		
	web_reg_find("Text=\"lowStock\": true", "SaveCount=c_OutOfStock", LAST);
	
	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={PDPURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp}", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={PDPURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp}", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);
		
	mFound = atoi(lr_eval_string("{c_OutOfStock}"));
	
	if(atoi(lr_eval_string("{PDP_Products}"))>0)
		
	{
		lr_end_transaction(lr_eval_string("{AgentType}CP08_PDP"),LR_PASS);
		//AddToCartFlag = 1;
		lr_save_string("YES","PDP");
		lr_save_string("_PDP","cartitem");
	}
	
	else
	{
		lr_end_transaction(lr_eval_string("{AgentType}CP08_PDP"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	return 0;
}
