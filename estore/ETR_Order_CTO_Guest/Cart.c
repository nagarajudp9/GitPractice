Cart()
{
	//web_set_max_html_param_len("999999");
	
	
	if(atoi(lr_eval_string("{cp_iCount}"))==0)
	{
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}
	
	if(Stoflag == 1)
	{
	
		lr_save_string("_CTO+STO","cartitem");
		
	}
	
	else
	{
		
	lr_save_string("_CTO","cartitem");
	
	}
	web_reg_save_param("cp_orderId","LB=<input type=\"hidden\" name=\"orderId\" id=\"orderId\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param("cp_krypto","LB=&krypto=","RB=&ddkey", LAST);
	
	web_reg_save_param("cp_authToken","LB=<input type=\"hidden\" name=\"authToken\" id=\"authToken\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param("cp_correlationId","LB=<input type=\"hidden\" name=\"correlationId\" id=\"correlationId\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param("cp_orderNo","LB=<input type=\"hidden\" name=\"ormOrderId\" id=\"ormOrderId\" value=\"","RB=\"/>",LAST);
	
	//web_reg_save_param("cp_PDPCatEntryId","LB=id=\"price_holder_","RB=\" data-ui='{","Ordinal=ALL",LAST);
	
	web_reg_save_param("cp_PDPCatEntryId","LB=id=\"price_holder_","RB=\" data-ui","Ordinal=ALL",LAST);
	
	web_reg_save_param("cp_adjprice","LB=cartTotalAdj\">$","RB=</span","NotFound=Warning",LAST);
	
	web_reg_save_param("cp_orderItemId","LB=\"productrow\" id=\"cItem","RB=\">","Ordinal=ALL",LAST);	
	
	lr_start_transaction("S24_ViewCart_CTO");
	
	lr_start_sub_transaction(lr_eval_string("S24-1_ViewCart{cartitem}{cartLineitem}"),"S24_ViewCart_CTO");
	
	web_url("OrderCalculate", 
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?selectedRecommConfig=recConfig1&updatePrices=1&calculationUsageId=-1&catalogId=10051&langId=-1&URL=AjaxOrderItemDisplayView&storeId=10151", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);
	
	if(lr_paramarr_len("cp_PDPCatEntryId") > 0)
    {
		web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1582254725512&action=cupids&catentryId={PDPURL}&modelId=&retainPOCart=false", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);


    }
	

	

	web_add_header("Origin", 
		"https://{p_hostName}");

	web_submit_data("ValidateConfigurationCmd", 
		"Action=https://{p_hostName}/us-en/shop/ValidateConfigurationCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
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
	
	
	lr_end_sub_transaction(lr_eval_string("S24-1_ViewCart{cartitem}{cartLineitem}"),LR_AUTO);
	lr_end_transaction("S24_ViewCart_CTO",LR_AUTO);
	
	lr_think_time(1);
	
	//web_set_max_html_param_len("1024");
	return 0;
}
