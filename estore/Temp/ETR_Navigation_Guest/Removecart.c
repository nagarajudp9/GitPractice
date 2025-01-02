Removecart()
{
	
	
	//lr_start_transaction(lr_eval_string("S25_RemoveCart{cartitem}"));
	
	lr_start_transaction("S25_RemoveCart");

	
	web_submit_data("AjaxOrderChangeServiceItemDelete",
		"Action=https://{p_hostName}/us-en/shop/AjaxOrderChangeServiceItemDelete", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 	
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=calculationUsage", "Value=-1,-2,-5,-6,-7", ENDITEM, 
		"Name=check", "Value=*n", ENDITEM, 
		"Name=orderItemId", "Value={cp_orderItemId}", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cql", "Value=40", ENDITEM, 
		"Name=cal", "Value=15000", ENDITEM, 
		LAST);

	web_url("RefreshCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCart?ajax=true&storeId=10151&langId=-1&catalogId=10051&ccf=false&cql=40&cal=15000", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	
	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1626328453603&action=cupids&catentryId=&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("ValidateConfigurationCmd", 
		"Action=https://{p_hostName}/us-en/shop/ValidateConfigurationCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 	
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderID", "Value={cp_orderId}", ENDITEM, 
		"Name=isReOrderFlag", "Value=true", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cql", "Value=40", ENDITEM, 
		"Name=cal", "Value=15000", ENDITEM, 
		LAST);
	//lr_end_transaction(lr_eval_string("S25_RemoveCart{cartitem}"),LR_AUTO);
	
	lr_end_transaction("S25_RemoveCart", LR_AUTO);


	return 0;
}
