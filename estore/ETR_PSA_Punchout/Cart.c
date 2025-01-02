Cart()
{
	int vccount,vci;
	
	lr_think_time(120);
	
	web_set_max_html_param_len("999999");
	
	if(atoi(lr_eval_string("{cp_iCount}"))==0)
	{
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}
	else
	{
		
	web_reg_save_param("cp_authToken","LB=<input type=\"hidden\" name=\"authToken\" id=\"authToken\" value=\"","RB=\"/>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_orderId","LB=<input type=\"hidden\" name=\"orderId\" id=\"orderId\" value=\"","RB=\"/>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_correlationId","LB=<input type=\"hidden\" name=\"correlationId\" id=\"correlationId\" value=\"","RB=\"/>","Notfound=warning",LAST)
		;
	web_reg_save_param("cp_orderNo","LB=<input type=\"hidden\" name=\"ormOrderId\" id=\"ormOrderId\" value=\"","RB=\"/>","Notfound=warning",LAST);	
	
	web_reg_save_param("cp_krypto","LB=&krypto=","RB=&ddkey","Notfound=warning",LAST);
	
	web_reg_save_param("cp_offerprice","LB=<span>$","RB= <span class=\"ptax\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_orderItemId","LB=\"productrow\" id=\"cItem","RB=\">","ORD=ALL","Notfound=warning",LAST);	
	
	web_reg_save_param("cp_VCartCatEntryId","LB=data-ui='{\"itemId\":\"","RB=\",","Notfound=warning","ORD=ALL",LAST);
		
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
		
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1"); 
	
	lr_start_transaction("CP24_ViewCart");
	
	
	web_url("OrderCalculate",
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?updatePrices=1&calculationUsageId=-1&catalogId=10051&langId=-1&storeId=10151&URL=AjaxOrderItemDisplayView",
		"TargetFrame=", 
		"Resource=0", 
		"Referer=https://{p_hostName}/us-en/shop/AccessoryAttachView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_Krypto}&ddkey=https%3AOrderConfigurationAdd",
		"RecContentType=text/html", 
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
	     "URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513665735409&action=cupis&catentryId={VCURL}&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t56.inf",
		"Mode=HTML", 
		LAST);
	
	
	
	
	
	lr_end_transaction("CP24_ViewCart",LR_AUTO);
	}
	
	web_set_max_html_param_len("1024");
	return 0;
}
