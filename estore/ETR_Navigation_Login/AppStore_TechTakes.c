AppStore_TechTakes()
{
	//web_set_sockets_option("SSL_VERSION", "2&3");
	web_reg_find("Text=hp-tech-takes-title","SaveCount=TechTakes_Products",LAST);

	lr_think_time(10);
	
	lr_start_transaction("S12_TechTakes");

	web_url("{p_TechTakes}", 
		"URL=https://{p_hostName}/us-en/shop/tech-takes/{p_TechTakes}{StoreType}", 
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

	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1638773381102&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/tech-takes/{p_TechTakes}", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);
	
	if( eppFlag == 1 || silverFlag == 1 || goldFlag == 1 || platinumFlag == 1 ||  euaFlag == 1 )

	{

  	//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S12_TechTakes")));
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
 
    	//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S12_TechTakes")));
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

	/*web_url("dealsapi_5", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/tech-takes/{p_TechTakes}", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);*/
	
	if(atoi(lr_eval_string("{TechTakes_Products}"))>0)
		{
			lr_end_transaction("S12_TechTakes",LR_PASS);
			
		}
		else
		{
			lr_end_transaction("S12_TechTakes",LR_FAIL);
			
		}

	return 0;
}
