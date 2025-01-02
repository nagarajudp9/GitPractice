PDP()
{
	lr_think_time(100);	
	
	web_set_max_retries ("5") ;
	
	if(atoi(lr_eval_string("{p_randomNo}"))< 3)
	{
	
		
web_reg_save_param("cp_CatEntryID","LB=catentryId\":\"","RB=\"",LAST);

web_reg_find("Text=pdp-details","SaveCount=c_PDP1",LAST);
web_save_timestamp_param("cp_time", LAST); //1626179257488 

	web_reg_save_param("cp_prod_id","LB=, \"prodId\":\"","RB=\"","RelFrameID=1","ORD=1","Notfound=warning",LAST);	
	
	web_reg_save_param("cp_sku","LB=<span itemprop=\"sku\" style=\"display:none;\" >","RB=</span>","Convert=HTML_TO_URL","Notfound=warning",LAST);	
	
	web_reg_save_param("cp_price","LB=<span style=\"display:none;\" itemprop=\"price\">","RB=</span>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_pdpname","LB=<span itemprop=\"name\">","RB=</span>","Convert=HTML_TO_URL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_restResourceContext","LB=var restResourceContext = '","RB=';","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_clientip","LB=clientip:\"","RB=\",","Notfound=warning",LAST);
	
	lr_start_transaction("CP08_PDP_CP");
	
	web_url("PDP",
		"URL=https://{p_hostName}/us-en/shop/pdp/{p_pdp_cp_new}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t107.inf", 
		"Mode=HTML", 
		LAST);
	
	web_convert_param("cp_restResourceContextURL",
				"SourceString={cp_restResourceContext}",
				"SourceEncoding=HTML",
				"TargetEncoding=URL",
				LAST);
	
	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cu&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp_cp_new}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	
	web_url("dealsapi", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/product-group/dealsapi?_={cp_time}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp_cp_new}", 
		"Snapshot=t28.inf", 
		"Mode=HTTP", 
		LAST);

	

	web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/pdp%2F/async", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp_cp_new}", 
		"Snapshot=t29.inf", 
		"Mode=HTTP", 
		LAST);

	
web_reg_find("Text=\"lowStock\": true", "SaveCount=c_OutOfStock", LAST);

	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={cp_CatEntryID}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp_cp_new}", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);
		
	web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151{StoreType1}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    

	
	
	if(((atoi(lr_eval_string("{c_PDP1}"))>0) || (atoi(lr_eval_string("{c_PDP2}"))==0)))
	{
		lr_end_transaction("CP08_PDP_CP",LR_PASS);
	}
	
	else
	{
		lr_end_transaction("CP08_PDP_CP",LR_FAIL);
		
		CC_Logout();    		
       	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	lr_save_string(lr_eval_string("{cp_CatEntryID}"),"cp_CatEntryID");
	
	lr_save_string("YES","PDP");
	
	CarepackFlag=1;
	}
	else
	{		
	web_reg_save_param("cp_CatEntryID","LB=catentryId\":\"","RB=\"",LAST);

web_reg_find("Text=pdp-details","SaveCount=c_PDP1",LAST);
web_save_timestamp_param("cp_time", LAST); //1626179257488 

	web_reg_save_param("cp_prod_id","LB=, \"prodId\":\"","RB=\"","RelFrameID=1","ORD=1","Notfound=warning",LAST);	
	
	web_reg_save_param("cp_sku","LB=<span itemprop=\"sku\" style=\"display:none;\" >","RB=</span>","Convert=HTML_TO_URL","Notfound=warning",LAST);	
	
	web_reg_save_param("cp_price","LB=<span style=\"display:none;\" itemprop=\"price\">","RB=</span>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_pdpname","LB=<span itemprop=\"name\">","RB=</span>","Convert=HTML_TO_URL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_restResourceContext","LB=var restResourceContext = '","RB=';","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_clientip","LB=clientip:\"","RB=\",","Notfound=warning",LAST);
	

	lr_start_transaction("CP08_PDP");
	
	web_url("PDP",
		"URL=https://{p_hostName}/us-en/shop/pdp/{p_pdp}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t107.inf", 
		"Mode=HTML", 
		LAST);
	
	web_convert_param("cp_restResourceContextURL",
				"SourceString={cp_restResourceContext}",
				"SourceEncoding=HTML",
				"TargetEncoding=URL",
				LAST);
	
	
	
	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cu&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	

	web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/pdp%2F/async", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp}", 
		"Snapshot=t29.inf", 
		"Mode=HTTP", 
		LAST);

	
web_reg_find("Text=\"lowStock\": true", "SaveCount=c_OutOfStock", LAST);

	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={cp_CatEntryID}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp}", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);
		
	web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151{StoreType1}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    

	
	
	if(((atoi(lr_eval_string("{c_PDP1}"))>0) || (atoi(lr_eval_string("{c_PDP2}"))==0))  && (atoi(lr_eval_string("{c_Home}"))==0))
	{
		lr_end_transaction("CP08_PDP",LR_PASS);
	}
	
	else
	{
	lr_end_transaction("CP08_PDP",LR_FAIL);
		
		CC_Logout();    		
       	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	lr_save_string(lr_eval_string("{cp_CatEntryID}"),"cp_CatEntryID");
	
	lr_save_string("YES","PDP");
	}
	
	nFound = atoi(lr_eval_string("{c_OutOfStock}"));
	
	return 0;
}
