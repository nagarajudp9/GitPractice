ViewCart()
{	
	
	int vccount,vci;
	
	web_reg_save_param("cp_CatEntryId","LB=\"sku\":\"","RB=\",","ORD=ALL",LAST);

	web_reg_save_param("cp_krypto","LB=&krypto=","RB=&ddkey",LAST);
	
	
	web_reg_save_param("cp_orderItemId","LB=\"productrow\" id=\"cItem","RB=\">",LAST);
	web_reg_save_param("cp_orderId","LB=\"orderId\" value=\"","RB=\"",LAST);
	
	
	lr_start_transaction("S24_ViewCart");
 
	web_url("OrderCalculate", 
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?calculationUsageId=-1&catalogId=10051&updatePrices=1&langId=-1&storeId=10151&URL=AjaxOrderItemDisplayView", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/mdp/{p_MDP}", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);
	
	
	vccount=atoi(lr_eval_string("{cp_CatEntryId_count}"));
	
	if(vccount == 0)
	{
		lr_save_string(lr_eval_string(""),"VCURL");
	}
	else
	{
		lr_save_string(lr_eval_string("{cp_CatEntryId_1}"), "VCURL");
		
		for (vci=1; vci<(lr_paramarr_len("cp_CatEntryId")); vci++)
		{
			lr_save_string(lr_paramarr_idx("cp_CatEntryId", vci+1), "VCCatID");
			
			lr_save_string(lr_eval_string("{VCURL}%2C{VCCatID}"), "VCURL");
		}
	}


	web_url("HPServices_6", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1626157903514&action=cupids&catentryId={VCURL}&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("S24_ViewCart",LR_AUTO);
	
	
		pmaxValue = atoi(lr_eval_string("{p_randomNum}"));			
	
	if(pmaxValue>0 && pmaxValue<5)
	{
	
		lr_start_transaction("S27_Checkout_Guest");
	
	lr_start_sub_transaction("S27-1_Checkout_Guest_Navigation","S27_Checkout_Guest");
	
	//lr_start_sub_transaction(lr_eval_string("S27-1_Checkout_Guest_OC{cartitem}"),"S27_Checkout_Guest");
		
	web_url("OrderCalculate_2", 
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?updatePrices=1&shipmentType=single&calculationUsageId=-1&calculationUsageId=-4&calculationUsageId=-6&errorViewName=AjaxOrderItemDisplayView&catalogId=10051&langId=-1&QuoteDisable=N&URL=OrderShippingBillingView&storeId=10151&orderId=.", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);
	
	//lr_end_sub_transaction(lr_eval_string("S27-1_Checkout_Guest_OC{cartitem}"),LR_AUTO);

	web_url("HPServices_4",
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513772230601&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto=iMFALsTsuaO8R%2F7ab6uCT2PolvC2%2BQn5ZmFuRtC5l450iAvidp9Mhq7qCGUKYPFTp%2BFnZzGJXz8ork7GqRwumYnH3bO0DZYTtp%2B%2BH9RiMtz1zz7yCYRHjjnaWa3ccM136hyP7nvfTrPDrrY4FM92KYNpsrFW7oPo%2Br1CaA7bOB8s5QS4rfaeebYaLdNRBApOcoSGFXlVwcoc1YfsxKFDF%2FmXtMrh4Q%2FJ6a4D8MSFJLNbUqOMtB31GhMtUVZkG1aREoFKd0fAPgQLiZmntnCrG8HiUVI9hzoP1sA3ELPHCfdP8xs5n2DUNZL9na8QmgaYagW830XXqKO%2BSEDYoak4PQ%3D%3D&ddkey=https%3AOrderCalculate", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);
		
	lr_end_sub_transaction("S27-1_Checkout_Guest_Navigation",LR_AUTO);
	
	lr_end_transaction("S27_Checkout_Guest",LR_AUTO);	

	
	
	
	
	}
	
	Removecart();

	

	return 0;
}
