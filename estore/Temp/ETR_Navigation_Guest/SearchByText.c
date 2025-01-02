SearchByText()
{
	/* Validation Date : 09-04-2022
	   Release         : FY22 - R3
	   Resource        : Nagaraju */
	
	int sbti,sbtcount;
	char fspara[200];	
	int si,catcount,fcount,fcount01;	
	int pmaxValue=0, prandNumber=0;
//	int arrSize;
  //  int ord;
  //  char * flightID;
     
    
	
	lr_think_time(60);
	
	web_set_max_html_param_len("99024");
	
	web_reg_find("Search=All","SaveCount=c_Search","Text=SEARCH RESULTS",LAST);
	
	web_reg_find("Search=All","SaveCount=c_Home","Text=HomePage.jsp",LAST);
	
	web_add_auto_header("accept-language",
		"en-US,en;q=0.9");
	
	
	
	lr_start_transaction(lr_eval_string("{AgentType}S09_Search"));
	
			
	web_url("sync", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/sitesearch%2F/sync", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/sitesearch?keyword={p_Search}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);


web_reg_save_param("sbtcatentryid","lb=\"catentry_id\":[\"","rb=\"],","ord=all",LAST);
web_reg_save_param("cp_SortValue","LB=Value\":\"","RB=\",\"IsDefault","ord=ALL",LAST);
web_reg_save_param("cp_facet","LB=,\"Field\":\"","RB=\",\"","ord=ALL",LAST);
web_reg_save_param("cp_facet01","LB=,\"Field\":\"","RB=\",\"","ord=ALL",LAST);

	
	web_reg_find("Search=All","SaveCount=c_PA","Text=PRODUCT AVAILABILITY",LAST);
	
	web_reg_save_param("cp_category","LB=dte_facet_category\":[\"","RB=\"]","ORD=ALL","Notfound=warning",LAST);
	
	
	web_custom_request("search_2", 
		"URL=https://searchapi-test.hawksearch.net/api/v2/search", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"query\":\"type:product\",\"ClientData\":{\"VisitId\":\"1f8a791c-c3b3-4dfa-8a06-fe1e6b13dee8\",\"VisitorId\":\"5d9be6d3-a7d9-44f6-901f-e4012b169093\",\"UserAgent\":\"Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36\",\"Custom\":{}},\"Keyword\":\"{p_Search}\",\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr\"}", 
		LAST);

/*	
	arrSize = lr_paramarr_len("cp_facet");
flightID = lr_paramarr_idx("cp_facet", arrSize);
arrSize = arrSize-3;
for (ord=1; ord <= arrSize;  ord) {
lr_save_string (lr_paramarr_idx("cp_facet", ord), "cp_facet");

ord= ord+1;
}

arrSize = lr_paramarr_len("cp_facet01");
flightID = lr_paramarr_idx("cp_facet01", arrSize);
arrSize = arrSize-3;
for (ord=1; ord <= arrSize;  ord) {
lr_save_string (lr_paramarr_idx("cp_facet01", ord), "cp_facet01");

ord= ord+1;
}

*/
		sbtcount=atoi(lr_eval_string("{sbtcatentryid_count}"));
	
	if(sbtcount == 0)
	{
		lr_end_transaction(lr_eval_string("{AgentType}S09_Search"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}	
	else
	{
		lr_save_string(lr_eval_string("{sbtcatentryid_1}"), "sbtURL");
		for (sbti=1; sbti<(lr_paramarr_len("sbtcatentryid")); sbti++)
		{
			lr_save_string(lr_paramarr_idx("sbtcatentryid", sbti+1), "sbtCatID");
			lr_save_string(lr_eval_string("{sbtURL},{sbtCatID}"), "sbtURL");
		}
	}

	web_save_timestamp_param("cp_time", LAST);

	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={sbtURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/sitesearch?keyword={p_Search}", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);


	if((atoi(lr_eval_string("{c_Search}"))>0) && (atoi(lr_eval_string("{c_Home}"))==0))
	{
		lr_end_transaction(lr_eval_string("{AgentType}S09_Search"),LR_PASS);
	}
	
	else
	{
		lr_end_transaction(lr_eval_string("{AgentType}S09_Search"),LR_FAIL);		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
		
	
	lr_think_time(30);
	
	
	
	fcount=atoi(lr_eval_string("{cp_facet_count}"));
	fcount01=atoi(lr_eval_string("{cp_facet01_count}"));
	
	pmaxValue = atoi(lr_eval_string("{p_randomNum}"));
	
	if(fcount == 0 || fcount01 == 0 )
	{
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	else if(pmaxValue>0 && pmaxValue<2)
	{
		
		
	if(atoi(lr_eval_string("{cp_category_count}"))>=1)
	{
		
		
		lr_save_string(lr_paramarr_random("cp_category"),"cp_category");
	
	web_reg_save_param("sbtcatentryid","lb=\"catentry_id\":[\"","rb=\"],","ord=all",LAST);
		
	lr_start_transaction(lr_eval_string("{AgentType}S13_ProductCategory"));
	
	web_custom_request("search_4", 
		"URL=https://searchapi-test.hawksearch.net/api/v2/search", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"ClientData\":{\"Custom\":{},\"UserAgent\":\"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Safari/537.36\",\"VisitorId\":\"dcb0a1a2-eb22-4e12-875a-5e3c1b6f2a54\",\"VisitId\":\"395cd5a8-2d7d-4768-b63e-461d94a605d3\"},\"Keyword\":\"{p_Search}\",\"FacetSelections\":{\"dte_facet_category\":[\"{cp_category}\"]},\"query\":\"type:product\",\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr\"}", 
		LAST);
	
	
	sbtcount=atoi(lr_eval_string("{sbtcatentryid_count}"));
	
	if(sbtcount == 0)
	{
		lr_end_transaction(lr_eval_string("{AgentType}S13_ProductCategory"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}	
	else
	{
		lr_save_string(lr_eval_string("{sbtcatentryid_1}"), "sbtURL");
		for (sbti=1; sbti<(lr_paramarr_len("sbtcatentryid")); sbti++)
		{
			lr_save_string(lr_paramarr_idx("sbtcatentryid", sbti+1), "sbtCatID");
			lr_save_string(lr_eval_string("{sbtURL},{sbtCatID}"), "sbtURL");
		}
	}

	web_save_timestamp_param("cp_time", LAST);

	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=ipd&catentryId={sbtURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/sitesearch?keyword={p_Search}&dte_facet_category={cp_category}", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);


	lr_end_transaction(lr_eval_string("{AgentType}S13_ProductCategory"),LR_AUTO);
	
	}
	
	
	lr_save_string(lr_paramarr_random("cp_facet"),"cp_facet");
	lr_save_string(lr_paramarr_random("cp_facet01"),"cp_facet01");
	
	web_reg_save_param("cp_facetValue01","LB={cp_facet}\":[\"","RB=\"],\"", "ord=ALL",LAST);
	web_reg_save_param("cp_facetValue02","LB={cp_facet01}\":[\"","RB=\"],\"","ord=ALL",LAST);

	//Etrxa Call for caputuring the facevalues
	
	web_custom_request("search_2", 
		"URL=https://searchapi-test.hawksearch.net/api/v2/search", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"query\":\"type:product\",\"ClientData\":{\"VisitId\":\"1f8a791c-c3b3-4dfa-8a06-fe1e6b13dee8\",\"VisitorId\":\"5d9be6d3-a7d9-44f6-901f-e4012b169093\",\"UserAgent\":\"Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36\",\"Custom\":{}},\"Keyword\":\"{p_Search}\",\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr\"}", 
		LAST);
	
	fcount=atoi(lr_eval_string("{cp_facetValue01_count}"));
	fcount01=atoi(lr_eval_string("{cp_facetValue02_count}"));
	
	if(fcount == 0 || fcount01 == 0 )
	{
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}

// pick the random Values
	lr_save_string(lr_paramarr_random("cp_facetValue01"),"cp_facetValue01");
	lr_save_string(lr_paramarr_random("cp_facetValue02"),"cp_facetValue02");
	lr_save_string(lr_paramarr_random("cp_SortValue"),"cp_SortValue");

	
	lr_start_transaction(lr_eval_string("{AgentType}S16_Sorting"));

web_reg_save_param("sbtcatentryid","lb=\"catentry_id\":[\"","rb=\"],","ord=all",LAST);
			
	web_custom_request("search_4",
		"URL=https://searchapi-test.hawksearch.net/api/v2/search", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"query\":\"type:product\",\"ClientData\":{\"VisitId\":\"1f8a791c-c3b3-4dfa-8a06-fe1e6b13dee8\",\"VisitorId\":\"5d9be6d3-a7d9-44f6-901f-e4012b169093\",\"UserAgent\":\"Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36\",\"Custom\":{}},\"SortBy\":\"{cp_SortValue}\",\"Keyword\":\"{p_Search}\",\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr\"}", 
		LAST);

	sbtcount=atoi(lr_eval_string("{sbtcatentryid_count}"));
	
	if(sbtcount == 0)
	{
		lr_end_transaction(lr_eval_string("{AgentType}S16_Sorting"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}	
	else
	{
		lr_save_string(lr_eval_string("{sbtcatentryid_1}"), "sbtURL");
		for (sbti=1; sbti<(lr_paramarr_len("sbtcatentryid")); sbti++)
		{
			lr_save_string(lr_paramarr_idx("sbtcatentryid", sbti+1), "sbtCatID");
			lr_save_string(lr_eval_string("{sbtURL},{sbtCatID}"), "sbtURL");
		}
	}

	web_save_timestamp_param("cp_time", LAST);

	web_url("HPServices_5", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={sbtURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/sitesearch?keyword={p_Search}&sort={cp_SortValue}", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		LAST);


	lr_end_transaction(lr_eval_string("{AgentType}S16_Sorting"),LR_AUTO);

	

	lr_start_transaction(lr_eval_string("{AgentType}S14_Filtering_Search"));


web_reg_save_param("sbtcatentryid","lb=\"catentry_id\":[\"","rb=\"],","ord=all",LAST);
	
	web_custom_request("search_8", 
		"URL=https://searchapi-test.hawksearch.net/api/v2/search", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"query\":\"type:product\",\"ClientData\":{\"VisitId\":\"1f8a791c-c3b3-4dfa-8a06-fe1e6b13dee8\",\"VisitorId\":\"5d9be6d3-a7d9-44f6-901f-e4012b169093\",\"UserAgent\":\"Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36\",\"Custom\":{}},\"FacetSelections\":{\"{cp_facet}\":[\"{cp_facetValue01}\"]},\"SortBy\":\"{cp_SortValue}\",\"Keyword\":\"{p_Search}\",\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr\"}", 
		LAST);

	sbtcount=atoi(lr_eval_string("{sbtcatentryid_count}"));
	
	if(sbtcount == 0)
	{
		lr_end_transaction(lr_eval_string("{AgentType}S14_Filtering_Search"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}	
	else
	{
		lr_save_string(lr_eval_string("{sbtcatentryid_1}"), "sbtURL");
		for (sbti=1; sbti<(lr_paramarr_len("sbtcatentryid")); sbti++)
		{
			lr_save_string(lr_paramarr_idx("sbtcatentryid", sbti+1), "sbtCatID");
			lr_save_string(lr_eval_string("{sbtURL},{sbtCatID}"), "sbtURL");
		}
	}


	web_save_timestamp_param("cp_time", LAST);
	
	web_url("HPServices_7", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={sbtURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/sitesearch?{cp_facet}={cp_facetValue01}&keyword={p_Search}&sort={cp_SortValue}", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("{AgentType}S14_Filtering_Search"),LR_AUTO);
	
	
	lr_think_time(10);	
	
	if(strcmp(lr_eval_string("{cp_facet}"),lr_eval_string("{cp_facet01}")) == 0)
		
		{
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}


	lr_start_transaction(lr_eval_string("{AgentType}S14_MultiFiltering_Search"));


web_reg_save_param("sbtcatentryid","lb=\"catentry_id\":[\"","rb=\"],","ord=all",LAST);
	
	web_custom_request("search_8", 
		"URL=https://searchapi-test.hawksearch.net/api/v2/search", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		//"Body={\"query\":\"type:product\",\"ClientData\":{\"VisitId\":\"1f8a791c-c3b3-4dfa-8a06-fe1e6b13dee8\",\"VisitorId\":\"5d9be6d3-a7d9-44f6-901f-e4012b169093\",\"UserAgent\":\"Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36\",\"Custom\":{}},\"FacetSelections\":{\"{cp_facet}\":[\"{cp_facetValue01}\"]},\"SortBy\":\"{cp_SortValue}\",\"inventory_status\":[\"In Stock\"]},\"Keyword\":\"{p_Search}\",\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr\"}", 
		"Body={\"query\":\"type:product\",\"ClientData\":{\"VisitId\":\"2fa8087b-50af-4655-84ac-6cb481124f9e\",\"VisitorId\":\"167d305c-b8c0-42b7-8fd3-196fcfe5a2d5\",\"UserAgent\":\"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36\",\"Custom\":{}},\"FacetSelections\":{\"{cp_facet}\":[\"{cp_facetValue01}\"],\"inventory_status\":[\"In Stock\"]},\"SortBy\":\"{cp_SortValue}\",\"Keyword\":\"{p_Search}\",\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr\"}", 
		LAST);

	sbtcount=atoi(lr_eval_string("{sbtcatentryid_count}"));
	
	if(sbtcount == 0)
	{
		lr_end_transaction(lr_eval_string("{AgentType}S14_MultiFiltering_Search"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}	
	else
	{
		lr_save_string(lr_eval_string("{sbtcatentryid_1}"), "sbtURL");
		for (sbti=1; sbti<(lr_paramarr_len("sbtcatentryid")); sbti++)
		{
			lr_save_string(lr_paramarr_idx("sbtcatentryid", sbti+1), "sbtCatID");
			lr_save_string(lr_eval_string("{sbtURL},{sbtCatID}"), "sbtURL");
		}
	}


	web_save_timestamp_param("cp_time", LAST);
	
	web_url("HPServices_7", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={sbtURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/sitesearch?{cp_facet}={cp_facetValue01}&keyword={p_Search}&sort={cp_SortValue}",
		"Referer=https:///us-en/shop/sitesearch?dte_facet_{cp_facet}_type={cp_facetValue01}&{cp_facet01}_status={cp_facetValue02}&keyword={cp_SortValue}",		
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		LAST);

		lr_end_transaction(lr_eval_string("{AgentType}S14_MultiFiltering_Search"),LR_AUTO);

		lr_think_time(10);	
		
		//filteringSearch_PA
	
	if((atoi(lr_eval_string("{c_PA}"))>0))
	{
		
	lr_start_transaction(lr_eval_string("{AgentType}S14_Filtering_Search_PA"));


	web_custom_request("search_3", 
		"URL=https://searchapi-test.hawksearch.net/api/v2/search", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"query\":\"type:product\",\"ClientData\":{\"VisitId\":\"166d27c3-62e7-4835-8145-5c882998a9ff\",\"VisitorId\":\"b9c4a4cb-0fe3-4a15-99e3-4d4817a378aa\",\"UserAgent\":\"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36\",\"Custom\":{}},\"FacetSelections\":{\"inventory_status\":[\"In Stock\"]},\"SortBy\":\"{cp_SortValue}\",\"Keyword\":\"{p_Search}\",\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\"}", 
		LAST);


	lr_end_transaction(lr_eval_string("{AgentType}S14_Filtering_Search_PA"),LR_AUTO);
	}
	//END
	


		lr_think_time(10);			
				
	lr_start_transaction(lr_eval_string("{AgentType}S15_ClearFilters"));
	
	web_custom_request("search_10", 
		"URL=https://searchapi-test.hawksearch.net/api/v2/search", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t52.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"ClientData\":{\"Custom\":{},\"UserAgent\":\"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Safari/537.36\",\"VisitorId\":\"dcb0a1a2-eb22-4e12-875a-5e3c1b6f2a54\",\"VisitId\":\"395cd5a8-2d7d-4768-b63e-461d94a605d3\"},\"Keyword\":\"{p_Search}\",\"FacetSelections\":{},\"query\":\"type:product\",\"SortBy\":\"{cp_SortValue}\",\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr\"}", 
		LAST);


	web_save_timestamp_param("cp_time", LAST);
	
	web_url("HPServices_5", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=ipd&catentryId={sbtURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/sitesearch?keyword={p_Search}", 
		"Snapshot=t53.inf", 
		"Mode=HTML", 
		LAST);
	
	
	lr_end_transaction(lr_eval_string("{AgentType}S15_ClearFilters"),LR_AUTO);

	}
	else
	{
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
	}
	
	
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
	
	pmaxValue=0;
	prandNumber=0;

	return 0;
}
