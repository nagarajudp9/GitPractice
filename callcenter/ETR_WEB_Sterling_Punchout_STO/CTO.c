CTO()
{
	
	
	/*
	lr_think_time(100);
	
web_set_max_html_param_len("999999");
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
	
	web_reg_save_param("cp_CatEntryID","LB=data-a2c='{\"itemId\":\"","RB=\"",LAST);
	web_reg_find("Text={p_PartNumber}",LAST);
	
	
	//lr_think_time(5);
	
	lr_start_transaction("CP09_SearchByCTO");

	web_url("SearchDisplay_2", 
		"URL=https://{p_hostName}/us-en/shop/SearchDisplay?client=&searchTerm={p_PartNumber}&search=&charset=utf-8&storeId=10151&catalogId=10051&langId=-1&beginIndex=0&pageSize=12&akamai-feo=off", 
		//"URL=http://{p_hostName}/us-en/shop/SearchDisplay?client=&searchTerm=Y3U25AV_1&search=&charset=utf-8&storeId=10151&catalogId=10051&langId=-1&beginIndex=0&pageSize=12 HTTP/1.1"
		"TargetFrame=",
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/SearchDisplay?client=&searchTerm={p_PartNumber}&search=&charset=utf-8&storeId=10151&catalogId=10051&langId=-1&beginIndex=0&pageSize=50",
		//"Referer=http://{p_hostName}/",
		"Snapshot=t15.inf",
		"Mode=HTML", 
		LAST);
	
	
	lr_end_transaction("CP09_SearchByCTO",LR_AUTO);
	
	CTO_Web();
	
	lr_think_time(10);
	
	*/
	
	
	int pdpi,pdpcount;
	lr_think_time(100);
	
	web_set_max_html_param_len("999999");	
	
		
	//lr_think_time(5);
	
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
	lr_start_transaction("CP09_SearchByCTO");

	
	web_reg_save_param("cp_pdpurl","LB=com/us-en/shop/pdp/","RB=\"",LAST);
	//web_reg_save_param("cp_catentryid","lb=catentry_id\":[\"","rb=\"]",LAST);
	
	web_custom_request("autocomplete_2", 
		"URL=https://searchapi-test.hawksearch.net/api/autocomplete", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"ClientGuid\":\"cc79148f6e9a47cbbbe8b0e3ae0f6e89\",\"IndexName\":\"etr\",\"ClientData\":{\"Custom\":{},\"UserAgent\":\"Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36\",\"VisitorId\":\"1f8a791c-c3b3-4dfa-8a06-fe1e6b13dee8\",\"VisitId\":\"5d9be6d3-a7d9-44f6-901f-e4012b169093\"},\"DisplayFullResponse\":true,\"Keyword\":\"{p_CTOPartnumber}\"}", 
		LAST);
	


	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_reg_save_param("cp_catentryid","lb=\"catentryId\":\"","rb=\",",LAST);
	
	web_reg_find("Text=Customize & buy","savecount=C_CTOCount",LAST);
	
	web_url("sync", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/pdp%2F{cp_pdpurl}/sync", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{cp_pdpurl}", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/pdp%2F{cp_pdpurl}/async", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{cp_pdpurl}", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1662046653068&action=pid&catentryId={cp_catentryid}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{cp_pdpurl}", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	
	lr_end_transaction("CP09_SearchByCTO",LR_AUTO);
	
	
	//CTO_Web();
	
 lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	
	
	lr_think_time(10);
	
	
	
	return 0;
}
