EUA_LoggedInCheckout()
{
	lr_think_time(60);
	
web_reg_save_param("cp_merchantName","LB=<input type=\"hidden\" name=\"merchantName\" value=\"","RB=\"/>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_sessionid","LB=<input type=\"hidden\" id=\"sessionId\" value=\"","RB=\"/>","Notfound=warning",LAST);	

	web_reg_save_param("cp_authToken","LB=<input type=\"hidden\" id=\"authToken\" value=\"","RB=\"/>","Notfound=warning",LAST);

	web_reg_save_param("cp_FirstNameAccount","LB=<div class=\"lblContact\">","RB= ","Notfound=warning",LAST);
	
	web_reg_save_param("cp_LastNameAccount","LB= ","RB=<br><span class=\"bgHighlight\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_EmailAccount","LB=<span class=\"bgHighlight\">","RB=</span><br>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_PhoneAccount","LB=</span><br>","RB=</div>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentFirstName","LB=data-fn=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentLastName","LB=data-ln=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentNickName","LB=data-nn=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentPhone","LB=data-ph=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentAddress","LB=data-a1=\"","RB=\"","Notfound=warning",LAST);
		
	web_reg_save_param("cp_CurrentCity","LB=data-cy=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentState","LB=data-st=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentZipCode","LB=data-zc=\"","RB=-","Savelen=5","Notfound=warning",LAST);
	
	web_reg_save_param("cp_addressId","LB=data-addr=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_PMTId","LB=data-pmt=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_DefaultaddressId","LB=sDefaultAddrId\" value=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_EstGrandTotal","LB=EstGrandTotal\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_TotalTaxAmount","LB=TotalTaxAmount\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Price","LB=Item_Price\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Name","LB=Item_Name\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Code","LB=Item_Code\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param("cp_tmid","lb=\"tmId\" value=\"","rb=\"/>","notfound=warning",LAST);

	web_save_timestamp_param("cp_time", LAST);
	
	lr_start_transaction("S27_Checkout_LoggedIn_EUA");
	
	///lr_start_sub_transaction("S27-1_Checkout_LoggedIn_EUA_OC","S27_Checkout_LoggedIn_EUA");
	
web_url("OrderCalculate_2", 
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?calculationUsageId=-1&calculationUsageId=-4&calculationUsageId=-6&catalogId=10051&orderId=.&updatePrices=1&langId=-1&storeId=10151&errorViewName=AjaxOrderItemDisplayView&URL=OrderShippingBillingView&QuoteDisable=N&shipmentType=single", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		LAST);

	//lr_end_sub_transaction("S27-1_Checkout_LoggedIn_EUA_OC", LR_AUTO);

	
	web_url("HPServices_6", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1598090770007&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		LAST);
		
	lr_save_string(string_replace(lr_eval_string("{cp_PhoneAccount}"),"(",""),"cp_PhoneAccount1");
	
	lr_save_string(string_replace(lr_eval_string("{cp_PhoneAccount1}"),")",""),"cp_PhoneAccount2");
	
	lr_save_string(string_replace(lr_eval_string("{cp_PhoneAccount2}"),"-",""),"cp_PhoneAccount3");
	
	lr_save_string(string_replace(lr_eval_string("{cp_PhoneAccount3}"),"  ",""),"cp_PhoneAccount");
	
	lr_save_string(string_replace(lr_eval_string("{cp_CurrentPhone}"),"(",""),"cp_CurrentPhone1");
	
	lr_save_string(string_replace(lr_eval_string("{cp_CurrentPhone1}"),")",""),"cp_CurrentPhone2");
	
	lr_save_string(string_replace(lr_eval_string("{cp_CurrentPhone2}"),"-",""),"cp_CurrentPhone3");
	
	lr_save_string(string_replace(lr_eval_string("{cp_CurrentPhone3}"),"  ",""),"cp_CurrentPhone");
	
	web_reg_save_param_ex("ParamName=cp_PaymentRequest","LB=JWT&quot;:&quot;","RB=&quot;","Notfound=warning",LAST);

	//lr_start_sub_transaction("S28-3_LoggedIn_Pay","S27_Checkout_LoggedIn_EUA");
	/*
	web_submit_data("Pay",
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay",
		"Method=POST",
		"EncodeAtSign=YES",
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AETRLogonFlow",
		"Snapshot=t26.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNo}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_correlationId}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld={cp_orderNo}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_correlationId}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"{cp_CurrentAddress}\",\"City\":\"{cp_CurrentCity}\",\"State\":\"{cp_CurrentState}\",\"Zip\":\"{cp_CurrentZipCode}\",\"Country\":\"US\",\"ContactFirstName\":\"{cp_CurrentFirstName}\",\"ContactLastName\":\"{cp_CurrentLastName}\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"Con"
		"tactEmail\":\"\",\"AddressName\":\"{cp_CurrentAddress}\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"{cp_FirstNameAccount}\",\"LastName\":\"{cp_LastNameAccount}\",\"Email\":\"{cp_EmailAccount}\",\"Phone\":\"{cp_PhoneAccount}\",\"Locale\":\"en_US\"},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":{\"IsDisplaySaveProfileFlag\":true,\"IsServiceRequired\":true,\"IsUpdatingUserProfile\":false}}", ENDITEM,
		LAST);

	web_submit_data("Pay_2",
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay",
		"Method=POST",
		"EncodeAtSign=YES",
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AETRLogonFlow",
		"Snapshot=t27.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNo}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_correlationId}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld={cp_orderNo}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_correlationId}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"{cp_CurrentAddress}\",\"City\":\"{cp_CurrentCity}\",\"State\":\"{cp_CurrentState}\",\"Zip\":\"{cp_CurrentZipCode}\",\"Country\":\"US\",\"ContactFirstName\":\"{cp_CurrentFirstName}\",\"ContactLastName\":\"{cp_CurrentLastName}\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"Con"
		"tactEmail\":\"\",\"AddressName\":\"{cp_CurrentAddress}\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"{cp_FirstNameAccount}\",\"LastName\":\"{cp_LastNameAccount}\",\"Email\":\"{cp_EmailAccount}\",\"Phone\":\"{cp_PhoneAccount}\",\"Locale\":\"en_US\"},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":\"\",\"GPay\":{\"IsServiceRequired\":true}}", ENDITEM,
		LAST);
	*/
	if(strcmp(lr_eval_string("{cp_PaymentRequest}"),"")==0)
	{
		//lr_end_sub_transaction("S28-3_LoggedIn_Pay",LR_FAIL);
	
		lr_end_transaction("S27_Checkout_LoggedIn_EUA",LR_PASS);;
		Logout();
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	else
	{
		//lr_end_sub_transaction("S28-3_LoggedIn_Pay",LR_PASS);
	
		lr_end_transaction("S27_Checkout_LoggedIn_EUA",LR_PASS);
		
	}

	CreateQuote();
		
	return 0;
}
