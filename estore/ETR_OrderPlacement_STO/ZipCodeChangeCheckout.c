ZipCodeChangeCheckout()
{
	if(GuestFlag==1)
	{
		if ( Preorder == 1)
		
	{
	
	}
		
		else
		{

	lr_start_transaction("S27_Checkout_ChangeZipcode");
	
	web_url("AjaxOrderShipEstimate",
		"URL=https://{p_hostName}/us-en/shop/AjaxOrderShipEstimate?orderId={cp_orderId}&zipCode={p_ChangeZipCode}&authToken={authToken_URL1}&URL=%2F&storeId=10151&langId=-1&catalogId=10051&ccf=false&cql=40&cal=6000",
		"Resource=0",
		"RecContentType=text/html",
		///"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate",
		"Snapshot=t35.inf",
		"Mode=HTML",
		LAST);

	web_url("RefreshCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCart?ajax=true&storeId=10151&langId=-1&catalogId=10051&ccf=false&cql=40&cal=6000", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		LAST);

/*	web_url("HPServices_5", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1524810312436&action=pis&catentryId={p_PDPURL}&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		LAST);
*/
	lr_end_transaction("S27_Checkout_ChangeZipcode",LR_AUTO);
	
	lr_think_time(60);
	
	lr_save_string(lr_eval_string("{p_GuestUserEmail}"), "p_userEmail");
		
	web_reg_save_param("cp_merchantName","LB=<input type=\"hidden\" name=\"merchantName\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param("cp_sessionid","LB=<input type=\"hidden\" id=\"sessionId\" value=\"","RB=\"/>","Notfound=warning",LAST);	
	
	web_reg_save_param("cp_tmid","lb=\"tmId\" value=\"","rb=\"/>","notfound=warning",LAST);
	
	//web_reg_find("Text=\r\n\t\t\thpusstore - Shipping and Billing Display\r\n\t\t", LAST);

	lr_start_transaction("S27_Checkout_Guest");
	
	lr_start_sub_transaction(lr_eval_string("S27-1_Checkout_Guest{cartitem}"),"S27_Checkout_Guest");
		
	web_url("OrderCalculate_2", 
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?updatePrices=1&shipmentType=single&calculationUsageId=-1&calculationUsageId=-4&calculationUsageId=-6&errorViewName=AjaxOrderItemDisplayView&catalogId=10051&langId=-1&QuoteDisable=N&URL=OrderShippingBillingView&storeId=10151&orderId=.", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_4",
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513772230601&action=cupis&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto=iMFALsTsuaO8R%2F7ab6uCT2PolvC2%2BQn5ZmFuRtC5l450iAvidp9Mhq7qCGUKYPFTp%2BFnZzGJXz8ork7GqRwumYnH3bO0DZYTtp%2B%2BH9RiMtz1zz7yCYRHjjnaWa3ccM136hyP7nvfTrPDrrY4FM92KYNpsrFW7oPo%2Br1CaA7bOB8s5QS4rfaeebYaLdNRBApOcoSGFXlVwcoc1YfsxKFDF%2FmXtMrh4Q%2FJ6a4D8MSFJLNbUqOMtB31GhMtUVZkG1aREoFKd0fAPgQLiZmntnCrG8HiUVI9hzoP1sA3ELPHCfdP8xs5n2DUNZL9na8QmgaYagW830XXqKO%2BSEDYoak4PQ%3D%3D&ddkey=https%3AOrderCalculate", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);
		
	lr_end_sub_transaction(lr_eval_string("S27-1_Checkout_Guest{cartitem}"),LR_AUTO);
	
	lr_end_transaction("S27_Checkout_Guest",LR_AUTO);	
		}
	lr_think_time(1);
	
	}
	
	return 0;
}
