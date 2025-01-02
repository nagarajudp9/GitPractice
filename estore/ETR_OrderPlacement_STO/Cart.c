Cart()
{
	int vccount,vci;
	
	lr_think_time(120);
	if ( Preorder == 1)
		
	{
	
	}
	
	else
	{
		
	
	
	if(atoi(lr_eval_string("{cp_iCount}"))==0)
	{
		Logout();
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}
	else
	{
		
	web_reg_save_param("cp_authToken","LB=<input type=\"hidden\" name=\"authToken\" id=\"authToken\" value=\"","RB=\"/>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_orderId","LB=<input type=\"hidden\" name=\"orderId\" id=\"orderId\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param("cp_correlationId","LB=<input type=\"hidden\" name=\"correlationId\" id=\"correlationId\" value=\"","RB=\"/>",LAST);
	web_reg_save_param("cp_orderNo","LB=<input type=\"hidden\" name=\"ormOrderId\" id=\"ormOrderId\" value=\"","RB=\"/>",LAST);	
	
	web_reg_save_param("cp_krypto","LB=&krypto=","RB=&ddkey",LAST);
	
	web_reg_save_param("cp_offerprice","LB=<span>$","RB= <span class=\"ptax\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_orderItemId","LB=\"productrow\" id=\"cItem","RB=\">","ORD=ALL",LAST);	
	
	web_reg_save_param("cp_VCartCatEntryId","LB=data-ui='{\"itemId\":\"","RB=\",","Notfound=warning","ORD=ALL",LAST);
	
	web_add_cookie("CC_FINGERPRINT=3081777001; DOMAIN=perf.store.hp.com");
		
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
		
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1"); 
	
	lr_start_transaction("S24_ViewCart");
	
	lr_start_sub_transaction(lr_eval_string("S24-1_ViewCart{cartitem}"),"S24_ViewCart");

	web_url("OrderCalculate",
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?updatePrices=1&calculationUsageId=-1&catalogId=10051&langId=-1&storeId=10151&URL=AjaxOrderItemDisplayView",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	web_convert_param("authToken_URL1",
		"SourceString={cp_authToken}",
		"SourceEncoding=HTML",
		"TargetEncoding=URL",
		LAST);
	
	vccount=atoi(lr_eval_string("{cp_VCartCatEntryId_count}"));
	
	if(vccount == 0)
	{
		lr_save_string(lr_eval_string(""),"VCURL");
	}
	else
	{
		lr_save_string(lr_eval_string("{cp_VCartCatEntryId_1}"), "VCURL");
		
		for (vci=1; vci<(lr_paramarr_len("cp_VCartCatEntryId")); vci++)
		{
			lr_save_string(lr_paramarr_idx("cp_VCartCatEntryId", vci+1), "VCCatID");
			
			lr_save_string(lr_eval_string("{VCURL}%2C{VCCatID}"), "VCURL");
		}
	}

	web_url("HPServices_5",
	   
	    "URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1644907570100&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto=ES6mvaQoFBXEQT3cHjUHhZnRuNfRSlEGnTiSDuNkM6UqlyEU79xh75eH0ug0xEaOZoV%2FUfN9p4MInB69O3WaeYIYoA1xE9ZE8hcG1py8eXuirp2PzwFioAjEfEV91QbGRAVfQwf8A%2BzZzQ%2B1tKG%2B69moQ7Ye91N76OHY6WYS3B44OyWbuWNRIokwAdZybFrQL3WzT62nfPazkHIUOxNYfa9AsZz9Je1k9IryYSQKOH4%3D&ddkey=https%3AOrderCalculate",
		"Referer=",
		"Snapshot=t56.inf",
		"Mode=HTML", 
		LAST);
	
	/*web_custom_request("HPLoyaltyEligibleCheckCmd_2", 
		"URL=https://{p_hostName}/us-en/shop/HPLoyaltyEligibleCheckCmd", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/{StoreType}", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);*/
	
	lr_end_sub_transaction(lr_eval_string("S24-1_ViewCart{cartitem}"),LR_AUTO);
	
	lr_end_transaction("S24_ViewCart",LR_AUTO);
	}
	}
	
	return 0;
}
