PDP()
{
	

	
	lr_think_time(100);	
	

web_reg_save_param("cp_PDPcatentryId","LB=catentryId\":\"","RB=\"",LAST);
web_reg_save_param_regexp("ParamName=cp_catEntryIdAddtocart","RegExp=\"catentryId\":\"(.*?)\",(.*?)\"product_type\":\"STO\",","Notfound=warning", "Group=1",LAST);
web_reg_find("Text=pdp-details","SaveCount=c_PDP",LAST);
web_save_timestamp_param("cp_time", LAST); //1626179257488 
web_reg_save_param("cp_catentry_id","LB=catentryId\":\"","RB=\"","RelFrameID=1","ORD=1",LAST);	
	
	if(atoi(lr_eval_string("{p_randomNo}")) == 1)
	{
lr_start_transaction("S08_PDP_CP");


	
web_url("{p_pdp_cp_new}",
		"URL=https://{p_hostName}/us-en/shop/pdp/{p_pdp_cp_new}{StoreType}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp_cp_new}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

if( eppFlag == 1 || silverFlag == 1 || goldFlag == 1 || platinumFlag == 1 ||  euaFlag == 1 )

	
{
	web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151{StoreType1}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    
    	
}

	else

{ 
        web_save_timestamp_param("cp_time", LAST);
    	web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    
}	
	
	

	web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/pdp%2F/async", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp_cp_new}", 
		"Snapshot=t29.inf", 
		"Mode=HTTP", 
		LAST);


web_reg_find("Text=\"lowStock\": true", "SaveCount=c_OutOfStock", LAST);

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={cp_PDPcatentryId}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_pdp_cp_new}", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);
		
	

	
	if((atoi(lr_eval_string("{c_PDP}"))>0) && (atoi(lr_eval_string("{c_Home}"))==0))
	{
		lr_end_transaction("S08_PDP_CP",LR_PASS);
	}
	
	else
	{
		lr_end_transaction("S08_PDP_CP",LR_FAIL);
		
		Logout();
	
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	lr_save_string(lr_eval_string("{cp_PDPcatentryId}"),"cp_PDPcatentryId");
	
	lr_save_string("YES","PDP");
	
	CarepackFlag=1;
	}
	
	else if(atoi(lr_eval_string("{p_randomNo}"))>1 && atoi(lr_eval_string("{p_randomNo}"))<3)
		
	{
	web_set_max_html_param_len("99999");
	lr_start_transaction("S08_PDP_PreOrder");
	
	web_reg_save_param("cp_PDPcatentryId","LB=catentryId\":\"","RB=\"",LAST);
	
	web_url("p_PDPpre", 
		"URL=https://{p_hostName}/us-en/shop/pdp/{p_PDPpre}{StoreType}", 
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
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDPpre}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	
	if( eppFlag == 1 || silverFlag == 1 || goldFlag == 1 || platinumFlag == 1 ||  euaFlag == 1 )

	
{
	web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151{StoreType1}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    
    	
}

	else

{ 
        web_save_timestamp_param("cp_time", LAST);
    	web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    
}

	web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/pdp%2F/async", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDPpre}", 
		"Snapshot=t29.inf", 
		"Mode=HTTP", 
		LAST);

	web_reg_find("Text=\"lowStock\": true", "SaveCount=c_OutOfStock", LAST);
	
	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={cp_PDPcatentryId}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDPpre}", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);
	

web_reg_find("Text=\"lowStock\": true", "SaveCount=c_OutOfStock", LAST);
	
	if((atoi(lr_eval_string("{c_PDP}"))>0))
	{
		lr_end_transaction("S08_PDP_PreOrder",LR_PASS);
	}
	
	else
	{
		lr_end_transaction("S08_PDP_PreOrder",LR_FAIL);
		
		Logout();
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
 lr_save_string(lr_eval_string("{cp_PDPcatentryId}"),"cp_PDPcatentryId");
	
	lr_save_string("YES","PDP");
	lr_save_string("_PreOrder","cartitem");
	Preorder=1;
	
	nFound = atoi(lr_eval_string("{c_OutOfStock}"));
	

	}
	
	else
	{		
	web_set_max_html_param_len("99999");
	
	lr_start_transaction("S08_PDP");
	
	web_reg_save_param("cp_PDPcatentryId","LB=catentryId\":\"","RB=\"",LAST);
	
	web_url("p_PDP", 
		"URL=https://{p_hostName}/us-en/shop/pdp/{p_PDP}{StoreType}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDP}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	

	web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/pdp%2F/async", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDP}", 
		"Snapshot=t29.inf", 
		"Mode=HTTP", 
		LAST);

	
	if( eppFlag == 1 || silverFlag == 1 || goldFlag == 1 || platinumFlag == 1 ||  euaFlag == 1 )

	
{
	web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151{StoreType1}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    
    	
}

	else

{ 
        web_save_timestamp_param("cp_time", LAST);
    	web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    
}
	web_reg_find("Text=\"lowStock\": true", "SaveCount=c_OutOfStock", LAST);
	
	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={cp_PDPcatentryId}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDP}", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);

	
	
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
	
	lr_save_string(lr_eval_string("{cp_PDPcatentryId}"),"cp_PDPcatentryId");
	
	lr_save_string("YES","PDP");
	}
	
	nFound = atoi(lr_eval_string("{c_OutOfStock}"));
	
	return 0;
}
