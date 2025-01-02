AppStore_DLP()
{
	int DLPi,DLPcount1;
	
lr_think_time(10);
	
web_reg_find("Search=All","SaveCount=c_DLP1","Text=dlp-product-list",LAST);
	web_reg_save_param("cp_ModelName","LB=tags\":[\"","RB=\"],","ORD=ALL",LAST);
	
web_reg_save_param("cp_DLPcatentryId","lb=\"itemId\":\"","rb=\",","ord=all",LAST);
lr_start_transaction(lr_eval_string("{AgentType}S10_DLP"));

	web_url("{p_DLP}", 
		"URL=https://{p_hostName}/us-en/shop/dlp/{p_DLP}{StoreType}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
		
DLPcount1=atoi(lr_eval_string("{cp_DLPcatentryId_count}"));
	if(DLPcount1 == 0)
	{
	
		lr_end_transaction(lr_eval_string(lr_eval_string("{AgentType}S10_DLP")),LR_FAIL);	
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);		
	}	
	else	
		
	{
	lr_save_string(lr_eval_string("{cp_DLPcatentryId_1}"), "DLPURL");
		for (DLPi=1; DLPi<(lr_paramarr_len("cp_DLPcatentryId")); DLPi++)
		{
			lr_save_string(lr_paramarr_idx("cp_DLPcatentryId", DLPi+1), "DLPCatID");
			lr_save_string(lr_eval_string("{DLPURL},{DLPCatID}"), "DLPURL");
		}
		
	}

	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1638773315891&action=cupids&catentryId={DLPURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/dlp/{p_DLP}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	

	/*web_url("dealsapi_3", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/dlp/{p_DLP}", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);*/

	if( eppFlag == 1 || silverFlag == 1 || goldFlag == 1 || platinumFlag == 1 ||  euaFlag == 1 )

	{

  	//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S10_DLP")));
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
 
    	//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S10_DLP")));
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
	
	web_custom_request("search", 
		"URL=https://{p_hostName}/us-en/shop/app/api/es/page/search", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/dlp/{p_DLP}", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"filters\":{\"templateKey\":\"dlp\",\"hosted\":\"true\",\"key\":{\"value\":\"laptop-docking-station\",\"boolType\":\"must_not\",\"type\":\"match_phrase\"}},\"post_filters\":null,\"aggregates\":{},\"aggregateFilters\":[],\"sort\":{\"viewCount\":\"desc\"},\"size\":20,\"from\":0,\"bucketSize\":10,\"_source\":[\"title\",\"vanityUrl\"]}", 
		LAST);
	
	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1638773315891&action=cusipd&catentryId={DLPURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/dlp/{p_DLP}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
		
		web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1638773315891&action=ipd&catentryId={DLPURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/dlp/{p_DLP}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
	if(atoi(lr_eval_string("{c_DLP1}"))>0)
		{
		lr_end_transaction(lr_eval_string("{AgentType}S10_DLP"),LR_PASS);
		AddToCartFlag = 1;
		lr_save_string("_DLP","cartitem");
		}
		else
		{
			lr_end_transaction(lr_eval_string("{AgentType}S10_DLP"),LR_FAIL);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}

	return 0;
}
