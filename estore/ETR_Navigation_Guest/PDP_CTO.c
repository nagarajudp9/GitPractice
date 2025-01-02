PDP_CTO()
{
	lr_think_time(30);
	
		web_set_max_html_param_len("9999");
	
		
		if(strcmp(lr_eval_string("{p_PartNumber}"),"")==0 || strcmp(lr_eval_string("{p_MRLastParam}"),"")==0 || strcmp(lr_eval_string("{p_ModelRef}"),"")==0 || strcmp(lr_eval_string("{LeadSku}"),"")==0 || strcmp(lr_eval_string("{FinalarrComponent}"),"")==0 || strcmp(lr_eval_string("{SortedPrimarySku}"),"")==0 || strcmp(lr_eval_string("{FinalarrPriceSku}"),"")==0 || strcmp(lr_eval_string("{p_ConfigSKUS}"),"")==0)
	{
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}
	
	web_convert_param("p_MRLastParam",
	                  "SourceString={p_MRLastParam}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	
	web_convert_param("p_PartNumber_URL",
	                  "SourceString={p_PartNumber}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	
	
	web_reg_find("Text={p_PartNumber}","savecount=C_PartNumberCount",LAST);
	web_save_timestamp_param("cp_time", LAST);
	
	web_convert_param("cp_ModelRefParam","SourceString={p_ModelRef}","SourceEncoding=HTML","TargetEncoding=URL",LAST);
	
	web_reg_save_param("productName","LB=var productName = '","RB=';\r\n","Notfound=warning",LAST);
	web_reg_save_param("cp_CatEntryID","LB=\"catentryId\":\"","RB=\",",LAST);
	web_reg_save_param("cp_PaySessionID","LB=JSESSIONID=0000","RB=:","Notfound=Warning",LAST);
	lr_start_transaction("S08_PDP_CTO");
	
	
	
	web_url("cp_pdpURL", 
		"URL=https://{p_hostName}/us-en/shop/pdp/{cp_pdpURL}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1627102062941&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{cp_pdpURL}", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	
	web_save_timestamp_param("cp_time", LAST);
	//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S08_PDP_CTO")));
		
	 web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST); 
	
	//lr_end_sub_transaction("S17-1_DealsAPI", LR_AUTO);
	
  
	web_url("async_2", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/pdp%2F{cp_pdpURL}/async", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{cp_pdpURL}", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);
	
web_reg_find("Text=\"lowStock\": true", "SaveCount=c_OutOfStock", LAST);

	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={cp_CatEntryID}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{cp_pdpURL}", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);


	
		
	if(atoi(lr_eval_string("{C_PartNumberCount}"))>0)
    {
	lr_end_transaction("S08_PDP_CTO",LR_PASS);
    }
    else
    {
	lr_end_transaction("S08_PDP_CTO",LR_FAIL);
	
    lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
    }
	
	
	
	mFound = atoi(lr_eval_string("{c_OutOfStock}"));
	
	if (mFound > 0)
	{
	
		//lr_exit(LR_EXIT_ACTION_AND_CONTINUE,LR_AUTO);
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
	
	}
	 else
	 	
	 {
	 
		CTO();
	
	 }
	
	
		
	return 0;
}
