PDP()
{
	
//	int pdpcpi,pdpcpcount;
//	int pdpi,pdpcount;
	
	lr_think_time(100);	
	
//	productId":"3074457345619275820",
	
web_reg_save_param("cp_PDPcatentryId","LB=catentryId\":\"","RB=\"",LAST);
//web_reg_save_param_regexp("ParamName=cp_catEntryIdAddtocart","RegExp=\"catentryId\":\"(.*?)\",(.*?)\"product_type\":\"STO\",", "Group=1",LAST);
web_reg_find("Text=pdp-details","SaveCount=c_PDP",LAST);
web_save_timestamp_param("cp_time", LAST); //1626179257488 
	
	
	lr_start_transaction("S08_PDP");
	
	web_url("p_PDP", 
		"URL=https://{p_hostName}/us-en/shop/pdp/{p_pdp}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cu&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	
	web_save_timestamp_param("cp_time", LAST);
	
	web_url("dealsapi",
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151{StoreType1}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    
	
	

	web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/pdp%2F/async", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp}", 
		"Snapshot=t29.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=ipd&catentryId={cp_PDPcatentryId}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp}", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_find("Text=\"lowStock\": true", "SaveCount=c_OutOfStock", LAST);

	if(atoi(lr_eval_string("{c_PDP}"))>0)
	
	{
		lr_end_transaction("S08_PDP",LR_PASS);
	}
	
	else
	{
		lr_end_transaction("S08_PDP",LR_FAIL);
		
		Logout();
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	//lr_save_string(lr_eval_string("{cp_PDPcatentryId}"),"cp_PDPcatentryId");
	
	lr_save_string("YES","PDP");
	

	nFound = atoi(lr_eval_string("{c_OutOfStock}"));
	
	return 0;
}
