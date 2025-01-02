AddToCart_Supplies()
{
	lr_think_time(60);
	if (nFound >= 1)
	{

	}
	else
	{ 
		
	web_reg_save_param("cp_cartOrderId","LB=orderId\": [\"","RB=\"]","Notfound=warning",LAST);
	
	web_reg_save_param("cp_orderItemId","LB=\"orderItemId\": [\"","RB=\"],","ORD=ALL","NOTFOUND=warning",LAST);

		lr_start_transaction("CP22_AddToCart_Supplies");
	
		web_submit_data("AddToCartAjax",
			"Action=https://{p_hostName}/us-en/shop/AddToCartAjax", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html",
			"Referer=",			
			"Snapshot=t33.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=catEntryId_1", "Value={C_PDP_SuppliescategoryId}", ENDITEM, 
			"Name=quantity_1", "Value=1", ENDITEM, 
//			"Name=catEntryId_2", "Value={cp_catentry_id_3}", ENDITEM, 
//			"Name=quantity_2", "Value=1", ENDITEM, 
			"Name=storeId", "Value=10151", ENDITEM, 
			"Name=catalogId", "Value=10051", ENDITEM, 
			"Name=langId", "Value=-1", ENDITEM, 
			"Name=orderId", "Value=.", ENDITEM, 
			"Name=calculationUsage", "Value=-1,-2,-5,-6,-7", ENDITEM, 
			"Name=inventoryValidation", "Value=true", ENDITEM, 
			"Name=URL", "Value=", ENDITEM, 
			"Name=updatePrices", "Value=1", ENDITEM, 
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
		
		lr_end_transaction("CP22_AddToCart_Supplies",LR_AUTO);
	}
		
		
	return 0;
}
