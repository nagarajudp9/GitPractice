Cart()
{
	
	lr_think_time(120);
	
	if(strcmp(lr_eval_string("{cp_orderId}"),"")==0)
	{
		//CC_Logout()
		lr_save_string("NO","Supplies");
		lr_save_string("NO","PDP");
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}
		
	//moved the below web_reg_save_param calls from checkout action
	web_reg_save_param("cp_authToken","LB=<input type=\"hidden\" name=\"authToken\" id=\"authToken\" value=\"","RB=\"/>","Notfound=warning",LAST);
	web_reg_save_param("cp_orderId","LB=<input type=\"hidden\" name=\"orderId\" id=\"orderId\" value=\"","RB=\"/>","Notfound=warning",LAST);	
	web_reg_save_param("cp_correlationId","LB=<input type=\"hidden\" name=\"correlationId\" id=\"correlationId\" value=\"","RB=\"/>","Notfound=warning",LAST);
	web_reg_save_param("cp_orderNo","LB=<input type=\"hidden\" name=\"ormOrderId\" id=\"ormOrderId\" value=\"","RB=\"/>","Notfound=warning",LAST);	
	web_reg_save_param("cp_krypto","LB=&krypto=","RB=&ddkey","Notfound=warning",LAST);
	web_reg_save_param("cp_offerprice","LB=<span>$","RB=</span>","Notfound=warning",LAST);
	web_reg_save_param("cp_adjprice","LB=<div class=\"lblRcSaved\">You saved <span>$","RB=</span> on your order</div>","Notfound=warning",LAST);
	
	//added by sivakami
	//<p><a href="/us-en/shop/ConfigureView?selectedRecommConfig=&orderItemId=113090632&ctoCacheInvalidationCnt=33&catEntryId=3074457345618510327&catalogId=10051&langId=-1&contractId=10003&storeId=10151&fromURL=AjaxOrderItemDisplayView">Edit your configuration</a></p>
//web_reg_save_param("cp_orderItemId","LB=&orderItemId=","RB=&","ORD=ALL","NOTFOUND=warning",LAST);

web_reg_save_param("cp_orderItemId","LB=\"productrow\" id=\"cItem","RB=\">","Ordinal=ALL","NOTFOUND=warning",LAST);		
	
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	//web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
//	web_reg_find("Text=hpusstore - Shopping Cart", 		LAST);
		
	lr_start_transaction("CP24_ViewCart");

	web_url("OrderCalculate", 
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?updatePrices=1&calculationUsageId=-1&catalogId=10051&langId=-1&storeId=10151&URL=AjaxOrderItemDisplayView", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("AjaxOrderItemDisplayView", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=http%3AOrderCalculate", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t60.inf", 
		"Mode=HTML", 
		LAST);


	web_url("HPServices_5", 
	    "URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513755452943&action=c", 
		//"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513755663426&action=upis&catentryId=586657%2C586655%2C283651%2C283653&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto=ES6mvaQoFBXEQT3cHjUHhZnRuNfRSlEGnTiSDuNkM6UqlyEU79xh75eH0ug0xEaOZoV%2FUfN9p4MInB69O3WaeYIYoA1xE9ZE8hcG1py8eXuirp2PzwFioAjEfEV91QbGRAVfQwf8A%2BzZzQ%2B1tKG%2B69moQ7Ye91N76OHY6WYS3B44OyWbuWNRIokwAdZybFrQL3WzT62nfPazkHIUOxNYfa9AsZz9Je1k9IryYSQKOH4%3D&ddkey=https%3AOrderCalculate",
		"Referer=",
		"Snapshot=t56.inf",
		"Mode=HTML", 
		LAST);
	
	
	lr_end_transaction("CP24_ViewCart",LR_AUTO);
	
	
	return 0;
}
