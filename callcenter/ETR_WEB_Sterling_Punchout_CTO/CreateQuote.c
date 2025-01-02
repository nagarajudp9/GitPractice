CreateQuote()
{
	if(strcmp(lr_eval_string("{cp_addressId}"),"")==0)
	{
		//CC_Logout();
		lr_save_string("NO","Supplies");
		lr_save_string("NO","PDP");
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}
	
	web_save_timestamp_param("cp_time", LAST);
	lr_output_message("Timestamp: %s", lr_eval_string("{cp_time}"));
	
	//web_reg_save_param("cp_addressId","LB=\"addressId\": \"","RB=\"","Notfound=warning",LAST);
		web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
		
	//	web_reg_save_param("cp_quoteNo","LB=\"quoteNo\": \"","RB=\"","NotFound=Warning",LAST);
			//web_reg_save_param("cp_quoteNo","LB=input type=\"hidden\" name=\"quoteNo\" value=\"","RB=\" />","NotFound=Warning",LAST);
		
			lr_save_string(lr_eval_string("{p_Address1}"),"p_Address1New");
	
	lr_save_string(lr_eval_string("{p_city}"),"p_CityNew");
	
	lr_save_string(lr_eval_string("{p_state}"),"p_StateNew");
	
	lr_save_string(lr_eval_string("{p_zipCode}"),"p_ZipCodeNew");
	
	lr_save_string(lr_eval_string("pfirst"),"p_FirstNameNew");
	
	lr_save_string(lr_eval_string("pLastName"),"p_LastNameNew");
	
	lr_save_string(lr_eval_string("HP"),"p_CompanyNameNew");
	
	lr_save_string(lr_eval_string("{p_Address2}"),"p_Address2New");
	
	lr_save_string(lr_eval_string("{cp_CurrentPhone}"),"p_PhoneNew");
	
	lr_start_transaction("CP46_CreateQuote");
	
		web_submit_data("AjaxQuoteCreate", 
		"Action=https://{p_hostName}/us-en/shop/AjaxQuoteCreate", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t50.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=firstName", "Value=perfTest", ENDITEM, 
		"Name=lastName", "Value=perfLast", ENDITEM, 
		"Name=organizationName", "Value=", ENDITEM, 
		"Name=address1", "Value={p_Address1New}", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value={p_city}", ENDITEM, 
		"Name=state", "Value={p_StateNew}", ENDITEM, 
		"Name=zipCode", "Value={p_zipCode}", ENDITEM, 
		"Name=country", "Value=US", ENDITEM, 
		"Name=email1", "Value={cp_EmailAccount}", ENDITEM, 
		"Name=phone1", "Value={p_PhoneNew}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=nickName", "Value=perfTest{cp_time}", ENDITEM, 
		"Name=subAuthNo", "Value=98787876741", ENDITEM,
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
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
	
web_reg_save_param("cp_quoteNo","LB=\"quoteNo\" value=\"","RB=\"","NotFound=Warning",LAST);


	web_submit_data("quoteDetailsView", 
		"Action=https://{p_hostName}/us-en/shop/quoteDetailsView?catalogId=10051&langId=-1&storeId=10151", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t52.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=quoteId", "Value={cp_orderId}", ENDITEM, 
		"Name=quoteCreated", "Value=Y", ENDITEM, 
		LAST);

	web_url("HPServices_7", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1598090991683&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/quoteDetailsView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t53.inf", 
		"Mode=HTML", 
		LAST);


	/*
	web_submit_data("AjaxOrderShipInfoUpdate", 
		"Action=https://{p_hostName}/us-en/shop/AjaxOrderShipInfoUpdate", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Snapshot=t202.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=editAddress", "Value=true", ENDITEM, 
		"Name=nickName", "Value=Punchout_CTO_CQ_{cp_time}", ENDITEM, 
		"Name=addressId", "Value={cp_addressId}", ENDITEM, 
		"Name=firstName", "Value=PerfFirstSMB", ENDITEM, 
		"Name=lastName", "Value=PerfLastSMB", ENDITEM, 
		"Name=organizationName", "Value=HP", ENDITEM, 
		"Name=address1", "Value=PerfAddress1", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value={p_city}", ENDITEM, 
		"Name=state", "Value={p_state}", ENDITEM,  
		"Name=zipCode", "Value={p_zipCode}", ENDITEM, 
		"Name=country", "Value=US", ENDITEM, 
		"Name=email1", "Value={ccp_EmailAccountl}", ENDITEM, 
		"Name=phone1", "Value=9878787674", ENDITEM, 
		"Name=isResidenceAddr", "Value=true", ENDITEM, 
		"Name=isSmbOrder", "Value=true", ENDITEM, 
		"Name=shipModeId", "Value=12056", ENDITEM, 
		"Name=authToken", "Value={cp_authToken}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=addressType", "Value=S", ENDITEM, 
		"Name=URL", "Value=/", ENDITEM, 
		"Name=correlationId", "Value={cp_correlationId}", ENDITEM, 
		"Name=taxExemptCheck", "Value=false", ENDITEM, 
		"Name=taxExemptOrgName", "Value=", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=true", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);

	web_url("RefreshCheckoutCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCheckoutCart?ajax=true&crID={cp_correlationId}&storeId=10151&langId=-1&catalogId=10051&ccf=true&cof=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t204.inf", 
		"Mode=HTML", 
		LAST);

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
		"Name=organizationName", "Value=HP", ENDITEM, 
		"Name=address1", "Value=PerfAddress1", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value={p_city}", ENDITEM, 
		"Name=state", "Value={p_state}", ENDITEM,  
		"Name=zipCode", "Value={p_zipCode}", ENDITEM, 
		"Name=country", "Value=US", ENDITEM, 
		"Name=email1", "Value={ccp_EmailAccountl}", ENDITEM, 
		"Name=phone1", "Value=9878787674", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=nickName", "Value=PerfFirstSMB{cp_time}", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=true", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	web_reg_save_param("cp_quoteNo","LB=input type=\"hidden\" name=\"quoteNo\" value=\"","RB=\" />","NotFound=Warning",LAST);

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
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1527256210425&action=cupis&catentryId=&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/quoteDetailsView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t212.inf", 
		"Mode=HTML", 
		LAST);
*/
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
