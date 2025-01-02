SearchBySTO()
{
	
	/* Validation Date : 09-04-2022
	   Release         : FY22 - R3
	   Resource        : Nagaraju */
	lr_think_time(60);
	
		
	
	
	lr_start_transaction(lr_eval_string("{AgentType}S09_SearchBySTO"));
	
	//Add to cart
	
		
	web_reg_save_param("cp_pdpurl","LB=com/us-en/shop/pdp/","RB=\"","Notfound=warning",LAST);


	web_custom_request("autocomplete_2", 
		"URL=https://searchapi-test.hawksearch.net/api/autocomplete", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr\",\"ClientData\":{\"Custom\":{},\"UserAgent\":\"Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36\",\"VisitorId\":\"1f8a791c-c3b3-4dfa-8a06-fe1e6b13dee8\",\"VisitId\":\"5d9be6d3-a7d9-44f6-901f-e4012b169093\"},\"DisplayFullResponse\":true,\"Keyword\":\"{p_STOPartNumber}\"}", 
		LAST);
																																																																																	
	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_reg_save_param("cp_catentryid","lb=\"catentryId\":\"","rb=\",",LAST);
	
	web_reg_find("Text=Add to cart","savecount=C_PartNumberCount",LAST);
	
	web_url("sync", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/pdp%2F{cp_pdpurl}/sync", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{cp_pdpurl}", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/pdp%2F{cp_pdpurl}/async", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{cp_pdpurl}", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1662046653068&action=pid&catentryId={cp_catentryid}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{cp_pdpurl}", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);


	 if(strcmp(lr_eval_string("{cp_catentryid}"),"")==0)
	{
		lr_end_transaction(lr_eval_string("S09_SearchBySTO"),LR_FAIL);
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	 else 
	 	
	
    {
		lr_end_transaction(lr_eval_string("{AgentType}S09_SearchBySTO"),LR_PASS);
    }
    
	
	return 0;
}
