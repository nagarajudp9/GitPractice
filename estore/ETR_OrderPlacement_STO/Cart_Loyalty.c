Cart_Loyalty()
{
	int vccount,vci;
	if(atoi(lr_eval_string("{cp_iCount}"))==0)
	{
		Logout();
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}
	else
	{
	
	web_reg_save_param_ex("ParamName=cp_orderId","LB=<input type=\"hidden\" name=\"orderId\" id=\"orderId\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param_ex("ParamName=cp_krypto","LB=&krypto=","RB=&ddkey", SEARCH_FILTERS,"Scope=Headers",LAST);
	
	web_reg_save_param_ex("ParamName=cp_authToken","LB=<input type=\"hidden\" name=\"authToken\" id=\"authToken\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param_ex("ParamName=cp_correlationId","LB=<input type=\"hidden\" name=\"correlationId\" id=\"correlationId\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param_ex("ParamName=cp_orderNo","LB=<input type=\"hidden\" name=\"ormOrderId\" id=\"ormOrderId\" value=\"","RB=\"/>",LAST);
	
//	web_reg_save_param_ex("ParamName=cp_PDPCatEntryId","LB=id=\"price_holder_","RB=\" data-ui","Ordinal=ALL",LAST);
	
	web_reg_save_param("cp_VCartCatEntryId","LB=data-ui='{\"itemId\":\"","RB=\",","Notfound=warning","ORD=ALL",LAST);
	
//	web_reg_save_param_ex("ParamName=cp_adjprice","LB=cartTotalAdj\">$","RB=</span","NotFound=Warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_orderItemId","LB=\"productrow\" id=\"cItem","RB=\">","Ordinal=ALL","NotFound=Warning",LAST);	
	
	lr_start_transaction("S24_ViewCart");
	
	lr_start_sub_transaction(lr_eval_string("S24-1_ViewCart{cartitem}"),"S24_ViewCart");
	
	web_url("OrderCalculate",
			"URL=https://{p_hostName}/us-en/shop/OrderCalculate?selectedRecommConfig=recConfig1&updatePrices=1&calculationUsageId=-1&catalogId=10051&langId=-1&URL=AjaxOrderItemDisplayView{StoreType}&storeId=10151", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=https://{p_hostName}/us-en/shop",
			"Snapshot=t19.inf", 
			"Mode=http", 
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
	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1582254725512&action=cupids&catentryId={VCURL}&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_Krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin",
		"https://{p_hostName}");

	lr_end_sub_transaction(lr_eval_string("S24-1_ViewCart{cartitem}"),LR_AUTO);
	
	lr_end_transaction("S24_ViewCart",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("S24_ViewCart_ApplyRewards");

	
	web_submit_data("AjaxLoyaltyRewardsApply", 
		"Action=https://{p_hostName}/us-en/shop/AjaxLoyaltyRewardsApply", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t74.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=redeemPoints", "Value={p_rewardsApply}", ENDITEM, 
		LAST);

	web_url("RefreshCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCart?ajax=true&storeId=10151&langId=-1&catalogId=10051&ccf=false&cql=40&cal=15000", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t75.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_10", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1599330344331&action=cupids&catentryId={VCURL}&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t77.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("S24_ViewCart_ApplyRewards", LR_AUTO);

	
	}
	
	lr_think_time(60);
	
	return 0;
}
