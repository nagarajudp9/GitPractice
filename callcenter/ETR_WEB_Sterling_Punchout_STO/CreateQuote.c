CreateQuote()
{
	if(strcmp(lr_eval_string("{cp_addressId}"),"")==0)
	{
		//Logout();
		lr_save_string("NO","Supplies");
		lr_save_string("NO","PDP");
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}
	
	web_save_timestamp_param("cp_time", LAST);
	lr_output_message("Timestamp: %s", lr_eval_string("{cp_time}"));
	
	//web_reg_save_param("cp_addressId","LB=\"addressId\": \"","RB=\"","Notfound=warning",LAST);
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	lr_start_transaction("CP46_CreateQuote");

	web_submit_data("AjaxQuoteCreate", 
		"Action=https://{p_hostName}/us-en/shop/AjaxQuoteCreate", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Snapshot=t206.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=firstName", "Value=PerfFirstSMB", ENDITEM, 
		"Name=lastName", "Value=PerfLastSMB", ENDITEM, 
		"Name=organizationName", "Value=hpc", ENDITEM, 
		"Name=address1", "Value=PerfAddress1", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value={p_city}", ENDITEM, 
		"Name=state", "Value={p_state}", ENDITEM,  
		"Name=zipCode", "Value={p_zipCode}", ENDITEM, 
		"Name=country", "Value=US", ENDITEM, 
		"Name=email1", "Value={cp_EmailAccount}", ENDITEM, 
		"Name=phone1", "Value=1234567890", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=nickName", "Value=PerfFirstSMB{cp_time}", ENDITEM, 
		"Name=subAuthNo", "Value=12345678901", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=true", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	web_submit_data("SendQuoteToTibco", 
		"Action=https://{p_hostName}/us-en/shop/SendQuoteToTibco", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t51.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=quoteNo", "Value={cp_quoteNo}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	//web_reg_save_param("cp_quoteNo","LB=input type=\"hidden\" name=\"quoteNo\" value=\"","RB=\" />","NotFound=Warning",LAST);
	
	web_reg_save_param("cp_quoteNo","LB=\"quoteNo\" value=\"","RB=\"","NotFound=Warning",LAST);

	web_submit_data("quoteDetailsView", 
		"Action=https://{p_hostName}/us-en/shop/quoteDetailsView?catalogId=10051&langId=-1&storeId=10151", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Snapshot=t207.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=quoteId", "Value={cp_orderId}", ENDITEM, 
		"Name=quoteCreated", "Value=Y", ENDITEM, 
		LAST);

	web_url("HPServices_9", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1527256210425&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/quoteDetailsView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t212.inf", 
		"Mode=HTML", 
		LAST);

	if(strcmp(lr_eval_string("{cp_quoteNo}"),"")!=0)
		{
			lr_end_transaction("CP46_CreateQuote",LR_PASS);
			ConvertQuote();

		}
		else
		{
			lr_end_transaction("CP46_CreateQuote",LR_FAIL);
			Cart();
			RemoveCart();
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}
	
	return 0;
}
