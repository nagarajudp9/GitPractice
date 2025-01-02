RemoveCart()
{
	int i,pmaxValue=0;
	char rpara[50];
	
	lr_think_time(5);
	
	
	for(i=1;i<=lr_paramarr_len("cp_orderItemId");i++)
	{
		
		lr_save_string(lr_paramarr_idx("cp_orderItemId", i), "orderItemId");
			
		lr_start_transaction("S25_RemoveCart");
		
		web_submit_data("AjaxOrderChangeServiceItemDelete", 
		"Action=https://{p_hostName}/us-en/shop/AjaxOrderChangeServiceItemDelete", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
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
		"RecContentType=text/html", 
		"Snapshot=t72.inf", 
		"Mode=HTML", 
		LAST);
		
		web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1582525007382&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"Resource=0", 
		"RecContentType=text/html", 
		 "Referer=",
		"Snapshot=t54.inf",
		"Mode=HTML", 
		LAST);
	
		lr_end_transaction("S25_RemoveCart",LR_AUTO);		
	
	}
	
	
	if( LoginFlag == 1)
		
	{
		Logout();
	}
	return 0;
}
