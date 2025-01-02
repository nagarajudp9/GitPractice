RemoveCart()
{
	
	int i,pmaxValue=0;
	char rpara[50];
	
	pmaxValue = atoi(lr_eval_string("{cp_orderItemId_count}"));
	for(i=1;i<=pmaxValue;i++)
	{
		sprintf(rpara, "{cp_orderItemId_%d}", i);		
		lr_save_string(	lr_eval_string(rpara), "orderItemId");
			web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
		lr_start_transaction("CP25_RemoveCart");
		
		web_submit_data("AjaxOrderChangeServiceItemDelete", 
		"Action=https://{p_hostName}/us-en/shop/AjaxOrderChangeServiceItemDelete", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html;charset=UTF-8", 
		//"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto=vLoQS0WOaJ4MpjiQKQu6w1afmh3fxvNBS4vqBz7kJtI1x9i2Us%2B556%2FSzkP19jBJEx89PrLsFvKb9yJLIi%2BT7koZnv2Ui4gt6szEM0ACXg4NNIeEeDqMU4vVZpHAKIacP3blYYr0BN1AILXLJNTQJsyY1Wwe%2FKZATm%2BwyM43zboaf2S6hs%2B7bIBZ9TjEXY01z8QhB%2FSTcBOb3W%2FvwB4o6kc8OhXo9HxLdrZqD2drfDY4V1X1evHvsQqtRI0Uq8Yc&ddkey=http%3AOrderCalculate", 
		"Snapshot=t71.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=calculationUsage", "Value=-1,-2,-5,-6,-7", ENDITEM, 
		"Name=check", "Value=*n", ENDITEM, 
		"Name=orderItemId", "Value={orderItemId}", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cql", "Value=40", ENDITEM, 
		"Name=cal", "Value=8000", ENDITEM, 
		LAST);

		web_url("RefreshCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCart?ajax=true&storeId=10151&langId=-1&catalogId=10051&ccf=false&cql=40&cal=8000", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html;charset=UTF-8", 
		//"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto=vLoQS0WOaJ4MpjiQKQu6w1afmh3fxvNBS4vqBz7kJtI1x9i2Us%2B556%2FSzkP19jBJEx89PrLsFvKb9yJLIi%2BT7koZnv2Ui4gt6szEM0ACXg4NNIeEeDqMU4vVZpHAKIacP3blYYr0BN1AILXLJNTQJsyY1Wwe%2FKZATm%2BwyM43zboaf2S6hs%2B7bIBZ9TjEXY01z8QhB%2FSTcBOb3W%2FvwB4o6kc8OhXo9HxLdrZqD2drfDY4V1X1evHvsQqtRI0Uq8Yc&ddkey=http%3AOrderCalculate", 
		"Snapshot=t72.inf", 
		"Mode=HTML", 
		LAST);
		
		web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1532680219795&action=cupis&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html;charset=UTF-8", 
		//"Referer=https://{p_hostName}/us-en/shop/TopCategoriesDisplayView?catalogId=10051&langId=-1&storeId=10151&currentPage=SigninPage", 
		 "Referer=",
		"Snapshot=t54.inf",
		"Mode=HTML", 
		LAST);
	
		lr_end_transaction("CP25_RemoveCart",LR_AUTO);		
	
	}
	
	
	
	return 0;
}
