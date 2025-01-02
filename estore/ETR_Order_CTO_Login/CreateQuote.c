CreateQuote()
{
	if(strcmp(lr_eval_string("{cp_addressId}"),"")==0)
	{
		Logout();
		
	}
	
	lr_save_string(lr_eval_string("{p_Address1}"),"p_Address1New");
	
	lr_save_string(lr_eval_string("{p_city}"),"p_CityNew");
	
	lr_save_string(lr_eval_string("{p_state}"),"p_StateNew");
	
	lr_save_string(lr_eval_string("{p_zipCode}"),"p_ZipCodeNew");
	
	lr_save_string(lr_eval_string("{p_FirstName}"),"p_FirstNameNew");
	
	lr_save_string(lr_eval_string("{p_LastName}"),"p_LastNameNew");
	
	lr_save_string(lr_eval_string("{p_CompanyName}"),"p_CompanyNameNew");
	
	lr_save_string(lr_eval_string("{p_Address2}"),"p_Address2New");
	
	lr_save_string(lr_eval_string("{p_Phone}"),"p_PhoneNew");
	
	/*

	web_reg_save_param("cp_addressId","LB=\"addressId\": \"","RB=\"","Notfound=warning",LAST);
	
	lr_start_transaction("S28_CheckoutDetails_LoggedIn_EUA");
	
	//lr_start_sub_transaction("S28-1_LoggedIn_AjaxOrderShipInfoUpdate","S28_CheckoutDetails_LoggedIn_EUA");	

	web_submit_data("AjaxOrderShipInfoUpdate_2", 
		"Action=https://{p_hostName}/us-en/shop/AjaxOrderShipInfoUpdate", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t47.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=editAddress", "Value=false", ENDITEM, 
		"Name=nickName", "Value=EStore_STO_LoggedInCheckout_EUA_{cp_time}", ENDITEM, 
		"Name=firstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=lastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=organizationName", "Value=", ENDITEM, 
		"Name=address1", "Value={p_Address1New}", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value={p_CityNew}", ENDITEM, 
		"Name=state", "Value={p_StateNew}", ENDITEM, 
		"Name=zipCode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=country", "Value=US", ENDITEM, 
		"Name=email1", "Value={p_userEmail}", ENDITEM, 
		"Name=phone1", "Value={p_PhoneNew}", ENDITEM, 
		"Name=isResidenceAddr", "Value=false", ENDITEM, 
		"Name=isSmbOrder", "Value=true", ENDITEM, 
		"Name=shipModeId", "Value=12056", ENDITEM, 
		"Name=authToken", "Value={cp_authToken}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=addressType", "Value=S", ENDITEM, 
		"Name=URL", "Value=/", ENDITEM, 
		"Name=correlationId", "Value={cp_correlationId}", ENDITEM, 
		"Name=taxExemptCheck", "Value=false", ENDITEM, 
		"Name=taxExemptOrgName", "Value=", ENDITEM, 
		"Name=phone", "Value={p_PhoneNew}", ENDITEM, 
		"Name=sDefaultAddrId", "Value={cp_DefaultaddressId}", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	if(strcmp(lr_eval_string("{cp_addressId}"),"")==0)
		
	{
		//lr_end_sub_transaction("S28-1_LoggedIn_AjaxOrderShipInfoUpdate",LR_FAIL);
		
		lr_end_transaction("S28_CheckoutDetails_LoggedIn_EUA",LR_FAIL);
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	else
	{
		//lr_end_sub_transaction("S28-1_LoggedIn_AjaxOrderShipInfoUpdate",LR_PASS);
	}
	
	//lr_start_sub_transaction("S28-2_LoggedIn_RefreshCheckoutCart","S28_CheckoutDetails_LoggedIn_EUA");

	web_url("RefreshCheckoutCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCheckoutCart?ajax=true&crID=H336722760_1598090762897&storeId=10151&langId=-1&catalogId=10051&ccf=false&cof=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		LAST);
	
	//lr_end_sub_transaction("S28-2_LoggedIn_RefreshCheckoutCart",LR_AUTO);
	
	lr_end_transaction("S28_CheckoutDetails_LoggedIn_EUA",LR_AUTO);
*/	
//	web_reg_save_param("cp_quoteNo","LB=\"quoteNo\": \"","RB=\"","NotFound=Warning",LAST);
	
	lr_start_transaction("S61_CreateQuote");
	web_reg_save_param("cp_quoteNo","LB=\"quoteNo\": \"","RB=\",","NotFound=Warning",LAST);
/*
	web_submit_data("AjaxQuoteCreate", 
		"Action=https://qa.store.hp.com/us-en/shop/AjaxQuoteCreate", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://qa.store.hp.com/us-en/shop/OrderShippingBillingView?storeId=10151&catalogId=10051&langId=-1&krypto="
		"3EGPRo0I%2FfkgsaILuuv314lDgrZTLXJSwhn0B6TvWS5LnFw%2FNxvszi5iJAbRnwDnLu%2BVrdVUjo8%2FE0FwMH2bOZP8UyCCU6X3xGQvLTcVvCPFYZZX7S9sAfoslG2DEtm3iOaWj2UXoLBTrpFj5QT8lx6x4lGNnfErcnzyPNko7y2bR433trVXHVXqc0PYBSAkMYWT%2BAwReijc35SR2QxwyyD4LddiCloxoXBcMIH6Aaxg9sv5LIFwWM3nR9JCB%2B1ViEVv4kB88hOv51iNnTL03X1Zp%2BZKWU2RjDFWnBH6qh5PwqQ37wfSwyHDib6hntNBhOjktMcqlOKZO2qAvMinmL6CHZgQJKWZhY8lEC5S0UpEGcZK47qTbZmnJC8G9wnYBqptSuAhsrmySR9JcISHaQ%3D%3D&ddkey=https%3AOrderCalculate", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=firstName", "Value=Pfirst", ENDITEM, 
		"Name=lastName", "Value=Perf", ENDITEM, 
		"Name=organizationName", "Value=PerfAcc001", ENDITEM, 
		"Name=address1", "Value=test", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value=New York", ENDITEM, 
		"Name=state", "Value=NY", ENDITEM, 
		"Name=zipCode", "Value=10007", ENDITEM, 
		"Name=country", "Value=US", ENDITEM, 
		"Name=email1", "Value=smb_pf_eua_v1_a01@yopmail.com", ENDITEM, 
		"Name=phone1", "Value=1234567890", ENDITEM, 
		"Name=orderId", "Value=61114361557727", ENDITEM, 
		"Name=subAuthNo", "Value=12345678901", ENDITEM, 
		"Name=nickName", "Value=Pfirst1621015373535", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
*/
 	web_submit_data("AjaxQuoteCreate", 
		"Action=https://{p_hostName}/us-en/shop/AjaxQuoteCreate", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t50.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=firstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=lastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=organizationName", "Value=", ENDITEM, 
		"Name=address1", "Value={p_Address1New}", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value={p_CityNew}", ENDITEM, 
		"Name=state", "Value={p_StateNew}", ENDITEM, 
		"Name=zipCode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=country", "Value=US", ENDITEM, 
		"Name=email1", "Value={p_euaUser}", ENDITEM, 
		"Name=phone1", "Value={p_PhoneNew}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=subAuthNo", "Value=12345678901", ENDITEM, 
		"Name=nickName", "Value={p_FirstNameNew}{cp_time}", ENDITEM, 
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
		"Referer=https://{p_hostName}/us-en/shop",
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

//web_reg_save_param("cp_quoteNo","LB=\"quoteNo\" value=\"","RB=\"","NotFound=Warning",LAST);

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

	if(strcmp(lr_eval_string("{cp_quoteNo}"),"")!=0)//cp_quoteNo
		{
			lr_end_transaction("S61_CreateQuote",LR_PASS);
			
		ConvertQuote();

		}
		else
		{
			lr_end_transaction("S61_CreateQuote",LR_FAIL);
			
			Cart();
			
			RemoveCart();
			
			Logout();
			
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
		}
		
	return 0;
}
