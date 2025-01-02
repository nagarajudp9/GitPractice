MyOrders_Guest()
{
	
	
	Home();
	pmaxValue = atoi(lr_eval_string("{p_randomNum}") );	
	
	if (pmaxValue > 2)
		
	{
		
	web_reg_save_param("cp_krypto","LB=&krypto=","RB=&ddkey", LAST);
	
	web_reg_save_param("cp_recaptcha","LB=data-sitekey=\"","RB=\"","Notfound=warning",LAST);
	
	lr_start_transaction(lr_eval_string("{AgentType}S55_MyAccountOrders"));
	
	
	web_url("MyAccountOrderStatusView",
		"URL=https://{p_hostName}/us-en/shop/MyAccountOrderStatusView?catalogId=10051&langId=-1&storeId=10151", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1598275770946&action=cupids&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyAccountOrderStatusView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	

	lr_end_transaction(lr_eval_string("{AgentType}S55_MyAccountOrders"),LR_AUTO);

		
	lr_start_transaction(lr_eval_string("{AgentType}S56_FindOrder"));
	
	web_add_header("Origin", 
		"https://{p_hostName}");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_save_param("cp_krypto","LB=&krypto=","RB=&ddkey", LAST);
	
	
	
	web_url("OrderValidateCmd", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/OrderValidateCmd?storeId=10151&catalogId=10051&URL=/us/en/OrderStatusFinalResultView?catalogId=10051&langId=-1&storeId=10151&ccFlow=Y&OrderId={p_forder}&PhoneNoOrEmail={p_femail}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	
/*	web_submit_data("OrderValidateCmd", 
		"Action=https://qa.store.hp.com/us-en/shop/OrderValidateCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://qa.store.hp.com/us-en/shop/OrderValidateCmd", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=URL", "Value=/us-en/shop/OrderStatusFinalResultView?catalogId=10051&langId=-1&storeId=10151", ENDITEM, 
		"Name=OrderId", "Value=H344957705", ENDITEM, 
		"Name=PhoneNoOrEmail", "Value=Puser202203161349.312@mail.com", ENDITEM, 
		"Name=BillPhoneNoOrEmail", "Value=3010", ENDITEM, 
		"Name=skipCaptchaFlag", "Value=false", ENDITEM, 
//		"Name=g-recaptcha-response", "Value="
//		"03AGdBq26J7MtMfhX3kvn0GAWCkYDAYJj04vfJW4lmgZzCm5-fe5a1A461mFCHaaqeo-bgYor4bkaiNxraqKwDShNWe6H2QhUMVWHk5gkR7k0xpoZ-5k_JbDQX_WVuV3h3rPiUIf2tevp0N9aM4qFDCsWic3xt8hv6wJ_ULzDwVhqhWTXSfyPtVifHeh8JcIsRyTIBKUWQ29-fyPUvP0Bq3VzIjaQi1rBhzLLy9wqaUQk0nEpSzEyWqbMr94ShJldIUpQs81v-I4duiu9HQFWraVVF-z-raYa4wpPe-PZmx6ASPi0hdTqELHBd5pzZjx1rvZOcSq8C6DQO20mXPVWWRs4ymFp-QjCt4pDJjdVcWpv9nlAyogV3mOmB_B3F9C5oJ2pzT42ajklsYpuF18Z3D3bBahNJmpi4c1X-sMsLGgB-X3T7b5FHhTTnDcNGWFw_FlAFWDsDtKe5wsXxKO03vJ30qlb6GiQLbrpbrdI9pXaVHXtEtFyl"
//		"rYY", ENDITEM, 
		LAST);

	/*
	web_submit_data("OrderValidateCmd", 
		"Action=https://{p_hostName}/us-en/shop/OrderValidateCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyAccountOrderStatusView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=URL", "Value=/us-en/shop/OrderStatusFinalResultView?catalogId=10051&langId=-1&storeId=10151", ENDITEM, 
		"Name=OrderId", "Value=H344957705", ENDITEM, 
		"Name=PhoneNoOrEmail", "Value=Puser202203161349.312@mail.com", ENDITEM, 
		"Name=BillPhoneNoOrEmail", "Value=3010", ENDITEM, 
		"Name=skipCaptchaFlag", "Value=false", ENDITEM, 
		"Name=g-recaptcha-response", "Value=03AGdBq26J7MtMfhX3kvn0GAWCkYDAYJj04vfJW4lmgZzCm5-fe5a1A461mFCHaaqeo-bgYor4bkaiNxraqKwDShNWe6H2QhUMVWHk5gkR7k0xpoZ-5k_JbDQX_WVuV3h3rPiUIf2tevp0N9aM4qFDCsWic3xt8hv6wJ_ULzDwVhqhWTXSfyPtVifHeh8JcIsRyTIBKUWQ29-fyPUvP0Bq3VzIjaQi1rBhzLLy9wqaUQk0nEpSzEyWqbMr94ShJldIUpQs81v-I4duiu9HQFWraVVF-z-raYa4wpPe-PZmx6ASPi0hdTqELHBd5pzZjx1rvZOcSq8C6DQO20mXPVWWRs4ymFp-QjCt4pDJjdVcWpv9nlAyogV3mOmB_B3F9C5oJ2pzT42ajklsYpuF18Z3D3bBahNJmpi4c1X-sMsLGgB-X3T7b5FHhTTnDcNGWFw_FlAFWDsDtKe5wsXxKO03vJ30qlb6GiQLbrpbrdI9pXaVHXtEtFylrYY", ENDITEM, 
		LAST);
	*/
web_url("OrderStatusFinalResultView", 
		"URL=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?storeId=10151&catalogId=10051&krypto={cp_krypto}&ddkey=https%3AOrderValidateCmd", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyAccountOrderStatusView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);	
	
	
	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1598275880056&action=cupids&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?catalogId=10051&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderValidateCmd", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);
		
	lr_end_transaction(lr_eval_string("{AgentType}S56_FindOrder"),LR_AUTO);
	}
	return 0;
}
