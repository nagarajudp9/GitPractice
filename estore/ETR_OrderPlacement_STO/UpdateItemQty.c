UpdateItemQty()
{
	
	if(Preorder == 1)
	{
	
	}
	
	else
	{
	
	if(GuestFlag==1)
	{
	lr_save_string("","cartitem");
	
	PDP();
	
	AddToCart();
	
	if(strcmp(lr_eval_string("{cp_orderItemId_1}"),"")==0)
	{
		Logout();
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}

	lr_start_transaction(lr_eval_string("S24_ViewCart_UpdateQuantity"));
	
	web_submit_data("AjaxOrderChangeServiceItemUpdate", 
		"Action=https://{p_hostName}/us-en/shop/AjaxOrderChangeServiceItemUpdate", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=calculationUsage", "Value=-1,-2,-5,-6,-7", ENDITEM, 
		"Name=inventoryValidation", "Value=true", ENDITEM, 
		"Name=orderItemId", "Value={cp_orderItemId_1}", ENDITEM, 
		"Name=quantity", "Value={p_Quantity}", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cql", "Value=40", ENDITEM, 
		"Name=cal", "Value=6000", ENDITEM, 
		LAST);

	
	web_revert_auto_header("Origin");

	web_url("RefreshCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCart?orderId={cp_orderId}&calculationUsage=-1%2C-2%2C-5%2C-6%2C-7&inventoryValidation=true&orderItemId={cp_orderItemId_1}&quantity={p_Quantity}&storeId=10151&langId=-1&catalogId=10051&ccf=false&cql=40&cal=6000&ajax=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With",
		"XMLHttpRequest");

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1596284145467&action=cupids&catentryId=427613&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);
	
	web_submit_data("ValidateConfigurationCmd", 
		"Action=https://{p_hostName}/us-en/shop/ValidateConfigurationCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderID", "Value={cp_orderItemId_1}", ENDITEM, 
		"Name=isReOrderFlag", "Value=true", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cql", "Value=40", ENDITEM, 
		"Name=cal", "Value=6000", ENDITEM, 
		LAST);
	
//	web_custom_request("HPLoyaltyEligibleCheckCmd_2", 
//		"URL=https://{p_hostName}/us-en/shop/HPLoyaltyEligibleCheckCmd", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=https://{p_hostName}/{StoreType}", 
//		"Snapshot=t9.inf", 
//		"Mode=HTML", 
//		"EncType=", 
//		LAST);

	lr_end_transaction(lr_eval_string("S24_ViewCart_UpdateQuantity"),LR_AUTO);
	}
	
	}
	return 0;
}
