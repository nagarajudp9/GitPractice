SearchByCTO()

{
	lr_think_time(100);
	
		web_set_max_html_param_len("999999");
		
		
		if( loyaltyflag == 1)    // CTO for Loyalty user
		
	{
		
		if(strcmp(lr_eval_string("{p_PartNumber1}"),"")==0 || strcmp(lr_eval_string("{p_MRLastParam1}"),"")==0 || strcmp(lr_eval_string("{p_ModelRef1}"),"")==0 || strcmp(lr_eval_string("{LeadSku1}"),"")==0 || strcmp(lr_eval_string("{FinalarrComponent1}"),"")==0 || strcmp(lr_eval_string("{SortedPrimarySku1}"),"")==0 || strcmp(lr_eval_string("{FinalarrPriceSku1}"),"")==0 || strcmp(lr_eval_string("{p_ConfigSKUS1}"),"")==0)
	{
			Logout();
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}
	
web_convert_param("p_MRLastParam1",
	                  "SourceString={p_MRLastParam1}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	
	web_convert_param("p_PartNumber1_URL",
	                  "SourceString={p_PartNumber1}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	
	
	
	//web_reg_find("Text=prodNum\">{p_PartNumber}","savecount=C_PartNumberCount",LAST);
	web_reg_find("Text=data-gtm-id=\"{p_PartNumber}\"","savecount=C_PartNumberCount",LAST);
	web_reg_save_param("productName","LB=var productName = '","RB=';\r\n","Notfound=warning",LAST);
	//web_reg_save_param("cp_CatEntryID","LB=data-a2c='{\"itemId\":\"","RB=\"",LAST);
	web_reg_save_param("cp_PaySessionID","LB=JSESSIONID=0000","RB=:","Notfound=Warning",LAST);
	
	web_reg_save_param("cp_CatEntryID","LB=\"catentryId\":\"","RB=\",","ORD=ALL",LAST);
lr_start_transaction(lr_eval_string("{AgentType}S09_SearchByCTO"));

	web_url("SearchDisplay", 
		//"URL=https://{p_hostName}/us-en/shop/pdp/{cp_pdpURL}",
		"URL=https://{p_hostName}/us-en/shop/SearchDisplay?client=&charset=utf-8&searchTerm={p_PartNumber}&storeId=10151&catalogId=10051&langId=-1&beginIndex=0&pageSize=12",
		"Resource=0",
		"RecContentType=text/html;charset=UTF-8", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

web_reg_find("Text=\"lowStock\": true", "SaveCount=c_OutOfStock", LAST);
	
	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1582254593086&action=cupids&catentryId={cp_CatEntryID}%2C{cp_CatEntryID}&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/?etr_pdp=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
		
	
	if(atoi(lr_eval_string("{C_PartNumberCount}"))>0)
    {
	lr_end_transaction("S09_SearchByCTO",LR_PASS);
    }
    else
    {
	lr_end_transaction("S09_SearchByCTO",LR_FAIL);
	
	Logout();
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
    }
	
	mFound = atoi(lr_eval_string("{c_OutOfStock01}"));
	
	if (mFound > 0)
	{
	
		lr_exit(LR_EXIT_ACTION_AND_CONTINUE,LR_AUTO);
	
	}

	
	 	
	 {
	 
		CTO();
	
	 }
		}
		
		
	else
	{
	
		
		if(strcmp(lr_eval_string("{p_PartNumber}"),"")==0 || strcmp(lr_eval_string("{p_MRLastParam}"),"")==0 || strcmp(lr_eval_string("{p_ModelRef}"),"")==0 || strcmp(lr_eval_string("{LeadSku}"),"")==0 || strcmp(lr_eval_string("{FinalarrComponent}"),"")==0 || strcmp(lr_eval_string("{SortedPrimarySku}"),"")==0 || strcmp(lr_eval_string("{FinalarrPriceSku}"),"")==0 || strcmp(lr_eval_string("{p_ConfigSKUS}"),"")==0)
	{
			Logout();
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
	
	
	
//web_set_option("MaxRedirectionDepth", "10", LAST);

	
	
	
	//web_reg_find("Text=prodNum\">{p_PartNumber}","savecount=C_PartNumberCount",LAST);
	web_reg_find("Text=data-gtm-id=\"{p_PartNumber}\"","savecount=C_PartNumberCount",LAST);
	web_reg_save_param("productName","LB=var productName = '","RB=';\r\n","Notfound=warning",LAST);
	//web_reg_save_param("cp_CatEntryID","LB=data-a2c='{\"itemId\":\"","RB=\"",LAST);
	web_reg_save_param("cp_PaySessionID","LB=JSESSIONID=0000","RB=:","Notfound=Warning",LAST);
	
	web_reg_save_param("cp_CatEntryID","LB=\"catentryId\":\"","RB=\",",LAST);
lr_start_transaction(lr_eval_string("{AgentType}S09_SearchByCTO"));

	web_url("SearchDisplay", 
		//"URL=https://{p_hostName}/us-en/shop/pdp/{cp_pdpURL}",
		"URL=https://{p_hostName}/us-en/shop/SearchDisplay?client=&charset=utf-8&searchTerm={p_PartNumber}&storeId=10151&catalogId=10051&langId=-1&beginIndex=0&pageSize=12",
		"Resource=0",
		"RecContentType=text/html;charset=UTF-8", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

web_reg_find("Text=\"lowStock\": true", "SaveCount=c_OutOfStock", LAST);
	
	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1582254593086&action=cupids&catentryId={cp_CatEntryID}%2C{cp_CatEntryID}&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/?etr_pdp=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	
		
	if(atoi(lr_eval_string("{C_PartNumberCount}")) == 0)
    {
	
		lr_end_transaction("S09_SearchByCTO",LR_FAIL);
	
		Logout();
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		
    }
    else
    {
	
    	lr_end_transaction("S09_SearchByCTO",LR_PASS);
    }
	
	lr_think_time(1);
	
	mFound = atoi(lr_eval_string("{c_OutOfStock}"));
	
	if (mFound > 0)
	{
	
		Logout();
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
		
		//lr_exit(LR_EXIT_ACTION_AND_CONTINUE,LR_AUTO);
	
	}
	 else
	 	
	 {
	 
		CTO();
	
	 }
	
	}
	
	lr_think_time(10);
	
	return 0;
}

