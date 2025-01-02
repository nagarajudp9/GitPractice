Search()
{
	int sbti,sbtcount;
	char fspara[200];	
	int si,catcount,fcount;	
	int pmaxValue=0, prandNumber=0;
		
	
	lr_think_time(50);
	
	web_reg_find("Search=All","SaveCount=c_Search","Text=SEARCH RESULTS",LAST);
	
	web_reg_find("Search=All","SaveCount=c_Home","Text=HomePage.jsp",LAST);
	
	web_add_auto_header("accept-language",
		"en-US,en;q=0.9");
	
	//"dte_facet_category":["Printers"]
		
	//PRODUCT AVAILABILITY
	
	
	
	lr_start_transaction(lr_eval_string("{AgentType}CP09_Search"));
	
	web_url("sitesearch",
		"URL=https://{p_hostName}/us-en/shop/sitesearch?keyword={p_search}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("accept-language");

	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1645182318063&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/sitesearch?keyword={p_search}", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("accept-language", 
		"en-US,en;q=0.9");
	
	web_url("DealsAPI", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/sitesearch?keyword={p_search}", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("accept-language");

	web_reg_save_param("sbtcatentryid","lb=\"catentry_id\":[\"","rb=\"],","ord=all",LAST);

	web_reg_save_param("cp_category","LB=dte_facet_category\":[\"","RB=\"]","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_facet","LB=facet_prodtype\":[\"","RB=\"],","ORD=ALL","Notfound=warning",LAST);
	
	web_custom_request("search", 
		"URL=https://searchapi-test.hawksearch.net/api/v2/search", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"ClientData\":{\"Custom\":{},\"UserAgent\":\"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.82 Safari/537.36\",\"VisitorId\":\"edef760b-b23a-4ef1-8d9c-e73d602b070b\",\"VisitId\":\"63e06a8f-e256-45f1-8758-d1e8fee882f8\"},\"Keyword\":\"{p_search}\\t\",\"FacetSelections\":{},\"query\":\"type:product\",\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr\"}", 
		LAST);
	
	sbtcount=atoi(lr_eval_string("{sbtcatentryid_count}"));
	
	if(sbtcount == 0)
	{
		lr_end_transaction(lr_eval_string("{AgentType}CP09_Search"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}	
	else
	{
		lr_save_string(lr_eval_string("{sbtcatentryid_1}"), "sbtURL");
		for (sbti=1; sbti<(lr_paramarr_len("sbtcatentryid")); sbti++)
		{
			lr_save_string(lr_paramarr_idx("sbtcatentryid", sbti+1), "sbtCatID");
			lr_save_string(lr_eval_string("{sbtURL}%2C{sbtCatID}"), "sbtURL");
		}
	}
	

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1645182319333&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/sitesearch?keyword={p_search}", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1645182321770&action=pid&catentryId={sbtURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/sitesearch?keyword={p_search}", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	

	if((atoi(lr_eval_string("{c_Search}"))>0) && (atoi(lr_eval_string("{c_Home}"))==0))
	{
		lr_end_transaction(lr_eval_string("{AgentType}CP09_Search"),LR_PASS);
	}
	
	else
	{
		lr_end_transaction(lr_eval_string("{AgentType}CP09_Search"),LR_FAIL);		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
		
	
	lr_think_time(60);
	
	catcount=atoi(lr_eval_string("{cp_category_count}"));
	
	if(catcount == 0)
	{
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	else
	{
	
	if(atoi(lr_eval_string("{cp_category_count}"))>=2)
	{
		
		if(atoi(lr_eval_string("{p_iterationNo}"))%2==1)
		{
				
			pmaxValue = atoi(lr_eval_string("{cp_category_count}"));			
			prandNumber =(rand() % (pmaxValue))+1;			
			sprintf(fspara, "{cp_category_%d}",prandNumber);			
			lr_save_string(	lr_eval_string(fspara), "cp_category");
			
			
	lr_start_transaction(lr_eval_string("{AgentType}CP13_ProductCategory"));
	
	//"Value":"priceasc",
	
	
	
	
	web_reg_save_param("cp_SortValue","LB=Value\":\"","RB=\",",LAST);
	
	//facet_prodtype":["Laptops"]
	
	//web_reg_save_param("cp_facet","LB=facet_prodtype\":[\"","RB=\"],","ORD=ALL","Notfound=warning",LAST);
	
	
	
		web_custom_request("search_4", 
		"URL=https://searchapi-test.hawksearch.net/api/v2/search", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"ClientData\":{\"Custom\":{},\"UserAgent\":\"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Safari/537.36\",\"VisitorId\":\"dcb0a1a2-eb22-4e12-875a-5e3c1b6f2a54\",\"VisitId\":\"395cd5a8-2d7d-4768-b63e-461d94a605d3\"},\"Keyword\":\"{p_search}\",\"FacetSelections\":{\"dte_facet_category\":[\"{cp_facet}\"]},\"query\":\"type:product\",\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr\"}", 
		LAST);

	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1645784949873&action=pid&catentryId={sbtURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/sitesearch?keyword={p_search}&dte_facet_category={cp_category}", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);


	lr_end_transaction(lr_eval_string("{AgentType}CP13_ProductCategory"),LR_AUTO);
	
	
	fcount=atoi(lr_eval_string("{cp_facet_count}"));
	
	pmaxValue = atoi(lr_eval_string("{p_randomNum}"));
	
	if(fcount == 0)
	{
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	else if(pmaxValue>0 && pmaxValue<11)
	{
	
			if(atoi(lr_eval_string("{cp_facet_count}"))>=1)
			{
				
				pmaxValue = atoi(lr_eval_string("{cp_facet_count}"));				
				prandNumber =(rand() % (pmaxValue))+1;				
				sprintf(fspara, "{cp_facet_%d}",prandNumber);				
				lr_save_string(	lr_eval_string(fspara), "cp_facet");
		
				
	lr_start_transaction(lr_eval_string("{AgentType}CP14_Filtering_Search"));
		
	web_reg_find("Search=All","SaveCount=c_ProductAvalibility","Text=PRODUCT AVAILABILITY",LAST);
	
	
	web_custom_request("search_6", 
		"URL=https://searchapi-test.hawksearch.net/api/v2/search", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"ClientData\":{\"Custom\":{},\"UserAgent\":\"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Safari/537.36\",\"VisitorId\":\"dcb0a1a2-eb22-4e12-875a-5e3c1b6f2a54\",\"VisitId\":\"395cd5a8-2d7d-4768-b63e-461d94a605d3\"},\"Keyword\":\"{p_search}\",\"FacetSelections\":{\"dte_facet_category\":[\"{cp_facet}\"],\"dte_facet_shiptype\":[\"Ready to Ship\"]},\"query\":\"type:product\",\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr"
		"\"}", 
		LAST);
	
	lr_end_transaction(lr_eval_string("{AgentType}CP14_Filtering_Search"),LR_AUTO);

	
	lr_start_transaction(lr_eval_string("{AgentType}CP16_Sorting"));
	
	
	web_custom_request("search_8", 
		"URL=https://searchapi-test.hawksearch.net/api/v2/search", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"ClientData\":{\"Custom\":{},\"UserAgent\":\"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Safari/537.36\",\"VisitorId\":\"dcb0a1a2-eb22-4e12-875a-5e3c1b6f2a54\",\"VisitId\":\"395cd5a8-2d7d-4768-b63e-461d94a605d3\"},\"Keyword\":\"{p_search}\",\"FacetSelections\":{\"dte_facet_category\":[\"{cp_facet}\"],\"dte_facet_shiptype\":[\"Ready to Ship\"]},\"query\":\"type:product\",\"SortBy\":\"{cp_SortValue}\",\"ClientGuid\":\""
		"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr\"}", 
		LAST);
	
	lr_end_transaction(lr_eval_string("{AgentType}CP16_Sorting"),LR_AUTO);
	
	if((atoi(lr_eval_string("{c_ProductAvalibility}"))>0))
	{
	
	lr_start_transaction(lr_eval_string("{AgentType}CP14_Filtering_Search_PA"));
	
	web_custom_request("search_2", 
		"URL=https://searchapi-test.hawksearch.net/api/v2/search", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://qa.store.hp.com/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"ClientData\":{\"Custom\":{},\"UserAgent\":\"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.51 Safari/537.36\",\"VisitorId\":\"b11c59cd-03b0-4d6e-b20c-ebe0c03383ff\",\"VisitId\":\"ab32ec08-18d7-4bba-80bb-07855adde92b\"},\"Keyword\":\"{p_search}\",\"FacetSelections\":{},\"query\":\"type:product\",\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr\"}", 
		LAST);

	web_url("HPServices_3", 
		"URL=https://qa.store.hp.com/us-en/shop/HPServices?_=1646211837451&action=pid&catentryId={sbtURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://qa.store.hp.com/us-en/shop/sitesearch?keyword={p_search}", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);
	
	
	lr_end_transaction(lr_eval_string("{AgentType}CP14_Filtering_Search_PA"),LR_AUTO);
	
	lr_think_time(30);
	}
	else
	{
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
	}
	
	
	lr_think_time(30);		
				
	lr_start_transaction(lr_eval_string("{AgentType}CP15_ClearFilters"));
	
	web_custom_request("search_10", 
		"URL=https://searchapi-test.hawksearch.net/api/v2/search", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t52.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"ClientData\":{\"Custom\":{},\"UserAgent\":\"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Safari/537.36\",\"VisitorId\":\"dcb0a1a2-eb22-4e12-875a-5e3c1b6f2a54\",\"VisitId\":\"395cd5a8-2d7d-4768-b63e-461d94a605d3\"},\"Keyword\":\"{p_search}\",\"FacetSelections\":{},\"query\":\"type:product\",\"SortBy\":\"{cp_SortValue}\",\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr\"}", 
		LAST);


	web_url("HPServices_5", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1645785056328&action=pid&catentryId={sbtURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/sitesearch?keyword={p_search}", 
		"Snapshot=t53.inf", 
		"Mode=HTML", 
		LAST);
	
	
	lr_end_transaction(lr_eval_string("{AgentType}CP15_ClearFilters"),LR_AUTO);
	
	}
		
	}
	}
	}
	}
	
	pmaxValue=0;
	prandNumber=0;

	return 0;
}
