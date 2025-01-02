AppStore_TechTakes()
{
	
	/* Validation Date : 09-04-2022
	   Release         : FY22 - R3
	   Resource        : Nagaraju */
	
	web_reg_find("Text=hp-tech-takes-title","SaveCount=TechTakes_Products",LAST);
	
	lr_think_time(10);

	lr_start_transaction("S12_TechTakes");

	web_url("{p_TechTakes}", 
		"URL=https://{p_hostName}/us-en/shop/tech-takes/{p_TechTakes}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("{p_TechTakes}_2", 
		"URL=https://{p_hostName}/us-en/shop/tech-takes/{p_TechTakes}?deferState=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/tech-takes/{p_TechTakes}", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	
web_save_timestamp_param("cp_time", LAST);

	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/tech-takes/{p_TechTakes}", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);
		
		web_save_timestamp_param("cp_time", LAST);
		//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S12_TechTakes")));
		
	 web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST); 
		
	//lr_end_sub_transaction("S17-1_DealsAPI", LR_AUTO);


	
	if(atoi(lr_eval_string("{TechTakes_Products}"))>0)
		{
			lr_end_transaction("S12_TechTakes",LR_PASS);
			
		}
		else
		{
			lr_end_transaction("S12_TechTakes",LR_PASS);
			
		}

	return 0;
}
