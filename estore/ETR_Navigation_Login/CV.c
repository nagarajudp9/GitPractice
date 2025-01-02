CV()
{
	
	lr_think_time(30);
	
	web_reg_find("Search=All","SaveCount=c_ContentView","Text=ContentRecommendation_UI.jsp",LAST);
	web_save_timestamp_param("cp_time", LAST); //1600153594317
	
	lr_start_transaction(lr_eval_string("{AgentType}S03_ContentView"));
	
	web_url("{p_ContentView}", 
		"URL=https://{p_hostName}/us-en/shop/cv/{p_contentview}{StoreType}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_={cp_time}&action=cupids&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cv/{p_contentview}{StoreType}", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
	
	
	if((atoi(lr_eval_string("{c_ContentView}"))>0))
	{
		lr_end_transaction(lr_eval_string("{AgentType}S03_ContentView"),LR_PASS);
	}
	
	else
	{
		lr_end_transaction(lr_eval_string("{AgentType}S03_ContentView"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	return 0;
}
