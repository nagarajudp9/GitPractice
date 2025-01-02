ViewQuotes()
{
	int pmaxValue=0, prandNumber=0;
	char spara[100];
	
	lr_start_transaction("S63_MyAccount");

	web_url("MyAccountFormView", 
		"URL=https://{p_hostName}/us-en/shop/MyAccountFormView?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1527295949924&action=cupis&catentryId=&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyAccountFormView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("S63_MyAccount",LR_AUTO);
	
	lr_start_transaction("S64_MyQuotes");

	web_url("MyQuotesView", 
		"URL=https://{p_hostName}/us-en/shop/MyQuotesView?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyAccountFormView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1527296062059&action=cupis&catentryId=&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyQuotesView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		LAST);
	
	//"QuoteId": "37892446227538",
	web_reg_save_param("cp_QuoteIds","LB=\"QuoteId\": \"","RB=\"","ORD=ALL","Notfound=warning",LAST);

	web_submit_data("HPFetchQuote", 
		"Action=https://{p_hostName}/us-en/shop/HPFetchQuote", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyQuotesView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t63.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		LAST);

	lr_end_transaction("S64_MyQuotes",LR_AUTO);
	
	pmaxValue = atoi(lr_eval_string("{cp_QuoteIds_count}"));	
	if(pmaxValue>0)
	{
		prandNumber = (rand() % (pmaxValue))+1;
		sprintf(spara, "{cp_QuoteIds_%d}",prandNumber);		
		lr_save_string(lr_eval_string(spara),"cp_QuoteIds");
		
	lr_start_transaction("S65_ViewQuoteInfo");

	web_url("quoteDetailsView", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/quoteDetailsView?quoteId={cp_QuoteIds}&catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyQuotesView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t69.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_5", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1527296244086&action=cupis&catentryId=&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/quoteDetailsView?quoteId={cp_QuoteIds}&catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t70.inf", 
		"Mode=HTML", 
		LAST);

		lr_end_transaction("S65_ViewQuoteInfo",LR_AUTO);
	}	

	Logout();
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);

	return 0;
}
