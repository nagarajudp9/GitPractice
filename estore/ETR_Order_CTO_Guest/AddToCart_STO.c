AddToCart_STO()
{
	lr_think_time(60);
	
	web_reg_save_param("cp_cartOrderId","LB=orderId\": [\"","RB=\"]","Notfound=warning",LAST);
	
	web_reg_save_param("cp_orderItemId","LB=\"orderItemId\": [\"","RB=\"],","ORD=ALL","NOTFOUND=warning",LAST);

	if (nFound > 0)
	{
	lr_exit(LR_EXIT_ACTION_AND_CONTINUE,LR_AUTO);
	
	}
	 else
	 	
	 {
	 
	
if(CarepackFlag==1)
	{
		lr_start_transaction("S22_AddToCart_CP");

		web_submit_data("AddToCartAjax", 
				"Action=https://{p_hostName}/us-en/shop/AddToCartAjax", 
				"Method=POST", 
				"TargetFrame=", 
				"RecContentType=text/html", 
				"Referer=",
				"Snapshot=t19.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=storeId", "Value=10151", ENDITEM, 
				"Name=catalogId", "Value=10051", ENDITEM, 
				"Name=langId", "Value=-1", ENDITEM, 
				"Name=orderId", "Value=.", ENDITEM, 
				"Name=calculationUsage", "Value=-1,-2,-5,-6,-7", ENDITEM, 
				"Name=inventoryValidation", "Value=true", ENDITEM, 
				"Name=URL", "Value=", ENDITEM, 
				"Name=updatePrices", "Value=1", ENDITEM, 
				"Name=isGC", "Value=N", ENDITEM, 
				"Name=catEntryId", "Value={cp_catentry_id}", ENDITEM, 
				"Name=quantity", "Value=1", ENDITEM, 
				"Name=elgblSku", "Value=MY12345", ENDITEM, 
				"Name=requesttype", "Value=ajax", ENDITEM, 
				LAST);
		
		web_url("HPServices_4", 
			"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513755452943&action=c", 
			"Resource=0", 
			"RecContentType=text/html", 
			//"Referer=https://{p_hostName}/us-en/shop/TopCategoriesDisplayView?catalogId=10051&langId=-1&storeId=10151&currentPage=SigninPage", 
			 "Referer=",
			"Snapshot=t54.inf",
			"Mode=HTML", 
			LAST);
			
		lr_end_transaction("S22_AddToCart_CP",LR_AUTO);
		
	}
	
	else
	
	{
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1"); 	
	lr_start_transaction("S22_AddToCart");

	web_submit_data("AddToCartAjax", 
			"Action=https://{p_hostName}/us-en/shop/AddToCartAjax", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=",
			"Snapshot=t19.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=storeId", "Value=10151", ENDITEM, 
			"Name=catalogId", "Value=10051", ENDITEM, 
			"Name=langId", "Value=-1", ENDITEM, 
			"Name=orderId", "Value=.", ENDITEM, 
			"Name=calculationUsage", "Value=-1,-2,-5,-6,-7", ENDITEM, 
			"Name=inventoryValidation", "Value=true", ENDITEM, 
			"Name=URL", "Value=", ENDITEM, 
			"Name=updatePrices", "Value=1", ENDITEM, 
			"Name=isGC", "Value=N", ENDITEM, 
			"Name=catEntryId", "Value={cp_catentry_id}", ENDITEM, 
			"Name=quantity", "Value=1", ENDITEM, 
			"Name=requesttype", "Value=ajax", ENDITEM, 
			LAST);
	
	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513755452943&action=c", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/TopCategoriesDisplayView?catalogId=10051&langId=-1&storeId=10151&currentPage=SigninPage", 
		 "Referer=",
		"Snapshot=t54.inf",
		"Mode=HTML", 
		LAST);
		
	lr_end_transaction("S22_AddToCart",LR_AUTO);
	}
	
	Stoflag = 1;
	 }
	
	return 0;
}
