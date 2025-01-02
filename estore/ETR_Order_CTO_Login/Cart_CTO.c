Cart_CTO()
{
	
		int pdpi,pdpcount;
	
	if(atoi(lr_eval_string("{cp_iCount}"))==0)
	{
		Logout();
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}
	
	else 
	
	{
	
	if( loyaltyflag == 1)
	{
	web_reg_save_param("cp_orderId","LB=<input type=\"hidden\" name=\"orderId\" id=\"orderId\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param_ex("ParamName=cp_krypto","LB=&krypto=","RB=&ddkey", LAST);
	
	web_reg_save_param_ex("ParamName=cp_authToken","LB=<input type=\"hidden\" name=\"authToken\" id=\"authToken\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param("cp_correlationId","LB=<input type=\"hidden\" name=\"correlationId\" id=\"correlationId\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param("cp_orderNo","LB=<input type=\"hidden\" name=\"ormOrderId\" id=\"ormOrderId\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param("cp_PDPCatEntryId","LB=id=\"price_holder_","RB=\" data-ui","Ordinal=ALL",LAST);
	
	web_reg_save_param_ex("ParamName=cp_adjprice","LB=cartTotalAdj\">$","RB=</span","NotFound=Warning",LAST);
	
	web_reg_save_param("cp_orderItemId","LB=\"productrow\" id=\"cItem","RB=\">","Ordinal=ALL",LAST);	
	
	lr_save_string("_CTO_Rewards","cartitem");
	
	
		
	lr_start_transaction("S24_ViewCart_CTO");
	
	lr_start_sub_transaction(lr_eval_string("S24-1_ViewCart{cartitem}"),"S24_ViewCart_CTO");
	
	web_url("OrderCalculate",
			"URL=https://{p_hostName}/us-en/shop/OrderCalculate?selectedRecommConfig=recConfig1&updatePrices=1&calculationUsageId=-1&catalogId=10051&langId=-1&URL=AjaxOrderItemDisplayView&storeId=10151", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=https://{p_hostName}/us-en/shop",
			"Snapshot=t19.inf", 
			"Mode=http", 
			LAST);
	
	
	lr_save_string(lr_eval_string("{cp_PDPCatEntryId_1}"), "PDPURL");
		
	for (pdpi=1; pdpi<(lr_paramarr_len("cp_PDPCatEntryId")); pdpi++)
{
	lr_save_string(lr_paramarr_idx("cp_PDPCatEntryId", pdpi+1), "PDPCatID");
	lr_save_string(lr_eval_string("{PDPURL}%2C{PDPCatID}"), "PDPURL");
}

	web_reg_find("Text=My HP Rewards","savecount=C_RedeemCount",LAST);

	web_url("HPServices_4",
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1582254725512&action=cupids&catentryId={PDPURL}&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	
	
	web_add_header("Origin", 
		"https://{p_hostName}");
/*
	web_submit_data("ValidateConfigurationCmd", 
		"Action=https://{p_hostName}/us-en/shop/ValidateConfigurationCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderID", "Value={cp_orderId}", ENDITEM, 
		"Name=isReOrderFlag", "Value=true", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cql", "Value=40", ENDITEM, 
		"Name=cal", "Value=6000", ENDITEM, 
		LAST);
*/
		lr_end_sub_transaction(lr_eval_string("S24-1_ViewCart{cartitem}"),LR_AUTO);
	
	lr_end_transaction("S24_ViewCart_CTO",LR_AUTO);
	
	lr_think_time(5);
	
	if(atoi(lr_eval_string("{C_RedeemCount}"))>0)
    {
	
		lr_start_transaction("S24_ViewCart_CTO_ApplyRewards");

	
		web_submit_data("AjaxLoyaltyRewardsApply", 
		"Action=https://{p_hostName}/us-en/shop/AjaxLoyaltyRewardsApply", 
		"Method=POST", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t74.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=redeemPoints", "Value={p_rewardsApply}", ENDITEM, 
		LAST);

	web_revert_auto_header("Origin");

	web_url("RefreshCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCart?ajax=true&storeId=10151&langId=-1&catalogId=10051&ccf=false&cql=40&cal=15000", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t75.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://{p_hostName}");

	web_submit_data("ValidateConfigurationCmd", 
		"Action=https://{p_hostName}/us-en/shop/ValidateConfigurationCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t76.inf", 
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

	web_url("HPServices_10", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1599330344331&action=cupids&catentryId={PDPURL}&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t77.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");
	
	lr_end_transaction("S24_ViewCart_CTO_ApplyRewards", LR_AUTO);

    }

	
	
	}
	else
	{
	
	web_reg_save_param_ex("ParamName=cp_orderId","LB=<input type=\"hidden\" name=\"orderId\" id=\"orderId\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param_ex("ParamName=cp_krypto","LB=&krypto=","RB=&ddkey", LAST);
	
	web_reg_save_param_ex("ParamName=cp_authToken","LB=<input type=\"hidden\" name=\"authToken\" id=\"authToken\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param("cp_correlationId","LB=<input type=\"hidden\" name=\"correlationId\" id=\"correlationId\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param("cp_orderNo","LB=<input type=\"hidden\" name=\"ormOrderId\" id=\"ormOrderId\" value=\"","RB=\"/>","NotFound=Warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_PDPCatEntryId","LB=id=\"price_holder_","RB=\" data-ui","Ordinal=ALL",LAST);
	
	web_reg_save_param_ex("ParamName=cp_adjprice","LB=cartTotalAdj\">$","RB=</span","NotFound=Warning",LAST);
	
	web_reg_save_param("cp_orderItemId","LB=\"productrow\" id=\"cItem","RB=\">","Ordinal=ALL",LAST);	
	
	lr_start_transaction("S24_ViewCart_CTO");
	
	lr_start_sub_transaction("S24-1_ViewCart_CTO","S24_ViewCart_CTO");
	
	web_url("OrderCalculate",
			"URL=https://{p_hostName}/us-en/shop/OrderCalculate?selectedRecommConfig=recConfig1&updatePrices=1&calculationUsageId=-1&catalogId=10051&langId=-1&URL=AjaxOrderItemDisplayView&storeId=10151", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=https://{p_hostName}/us-en/shop",
			"Snapshot=t19.inf", 
			"Mode=http", 
			LAST);
	
	
	lr_save_string(lr_eval_string("{cp_PDPCatEntryId_1}"), "PDPURL");
		
	for (pdpi=1; pdpi<(lr_paramarr_len("cp_PDPCatEntryId")); pdpi++)
{
	lr_save_string(lr_paramarr_idx("cp_PDPCatEntryId", pdpi+1), "PDPCatID");
	lr_save_string(lr_eval_string("{PDPURL}%2C{PDPCatID}"), "PDPURL");
}
	
	
	
	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1582254725512&action=cupids&catentryId={PDPURL}&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("HPLoyaltyEligibleCheckCmd_5", 
		"URL=https://{p_hostName}/us-en/shop/HPLoyaltyEligibleCheckCmd", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t70.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);

	web_add_header("Origin", 
		"https://{p_hostName}");

	web_submit_data("ValidateConfigurationCmd", 
		"Action=https://{p_hostName}/us-en/shop/ValidateConfigurationCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderID", "Value={cp_orderId}", ENDITEM, 
		"Name=isReOrderFlag", "Value=true", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cql", "Value=40", ENDITEM, 
		"Name=cal", "Value=6000", ENDITEM, 
		LAST);

lr_end_sub_transaction("S24-1_ViewCart_CTO",LR_AUTO);
	
	lr_end_transaction("S24_ViewCart_CTO",LR_AUTO);
	
	}
	
	}
	lr_think_time(60);
	return 0;
}
