LoggedInCheckout()
{
	lr_think_time(60);
	
	if(strcmp(lr_eval_string("{cp_orderId}"),"")==0 )
	{
		CC_Logout();
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}
		
	if(psaFlag==1)
	{
		
		lr_think_time(120);
		
	web_submit_data("ccAjaxManageLVOFlag", 
		"Action=https://{p_hostName}/us-en/shop/ccAjaxManageLVOFlag", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?storeId=10151&catalogId=10051&krypto={cp_krypto}&ddkey=https%3AbrowseEstore", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=lvoFlag", "Value=0", ENDITEM, 
		LAST);
		
		
	web_reg_save_param("cp_merchantName","LB=<input type=\"hidden\" name=\"merchantName\" value=\"","RB=\"/>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_sessionid","LB=<input type=\"hidden\" id=\"sessionId\" value=\"","RB=\"/>","Notfound=warning",LAST);	

	web_reg_save_param("cp_authToken","LB=<input type=\"hidden\" id=\"authToken\" value=\"","RB=\"/>","Notfound=warning",LAST);

	web_reg_save_param("cp_FirstNameAccount","LB=<div class=\"lblContact\">","RB= ","Notfound=warning",LAST);
	
	web_reg_save_param("cp_LastNameAccount","LB= ","RB=<br><span class=\"bgHighlight\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_EmailAccount","LB=<span class=\"bgHighlight\">","RB=</span><br>","Notfound=warning",LAST);

//	web_reg_save_param("cp_PhoneAccount","LB=</span><br>","RB=</div>","Notfound=warning",LAST);
	
//	web_reg_save_param("cp_CurrentFirstName","LB=data-fn=\"","RB=\"","Notfound=warning",LAST);
	
//	web_reg_save_param("cp_CurrentLastName","LB=data-ln=\"","RB=\"","Notfound=warning",LAST);
	
//	web_reg_save_param("cp_CurrentNickName","LB=data-nn=\"","RB=\"","Notfound=warning",LAST);
	
//	web_reg_save_param("cp_CurrentPhone","LB=data-ph=\"","RB=\"","Notfound=warning",LAST);
	
//	web_reg_save_param("cp_CurrentAddress","LB=data-a1=\"","RB=\"","Notfound=warning",LAST);
		
//	web_reg_save_param("cp_CurrentCity","LB=data-cy=\"","RB=\"","Notfound=warning",LAST);
	
//	web_reg_save_param("cp_CurrentState","LB=data-st=\"","RB=\"","Notfound=warning",LAST);
	
//	web_reg_save_param("cp_CurrentZipCode","LB=data-zc=\"","RB=-","Savelen=5","Notfound=warning",LAST);
	
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
	
	
	lr_start_transaction("CP27_Checkout_LoggedIn_PSA");
	

	//web_reg_save_param("cp_addr","LB=data-addr=\"","RB=\"","Notfound=warning",LAST);
	web_reg_save_param("cp_companyName","LB=data-cn=\"","RB=\"","Notfound=warning",LAST);
	web_reg_save_param("cp_userEmail","LB=data-em=\"","RB=\"","Notfound=warning",LAST);
	
	
	
	
	web_url("OrderCalculate", 
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?calculationUsageId=-1&calculationUsageId=-4&calculationUsageId=-6&catalogId=10051&orderId=.&updatePrices=1&langId=-1&storeId=10151&errorViewName=AjaxOrderItemDisplayView&URL=OrderShippingBillingView&QuoteDisable=N&shipmentType=single", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?storeId=10151&catalogId=10051&krypto={cp_krypto}&ddkey=https%3AbrowseEstore", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
			LAST);
	/*
	web_url("OrderCalculate_2",
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?updatePrices=1&shipmentType=single&calculationUsageId=-1&calculationUsageId=-4&calculationUsageId=-6&errorViewName=AjaxOrderItemDisplayView&catalogId=10051&langId=-1&QuoteDisable=N&URL=OrderShippingBillingView&storeId=10151&orderId=.", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		LAST);
*/
	web_url("HPServices_6", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1598090770007&action=cupids&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		LAST);

		web_submit_data("ValidateConfigurationCmd", 
		"Action=https://{p_hostName}/us-en/shop/ValidateConfigurationCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&catalogId=10051&langId=-1&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderID", "Value={cp_orderId}", ENDITEM, 
		"Name=isReOrderFlag", "Value=true", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=true", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);

	
	web_reg_save_param_ex("ParamName=cp_PaymentRequest","LB=JWT&quot;:&quot;","RB=&quot;","Notfound=warning",LAST);

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
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"{p_psaUser}\",\"OrderID\":\"{cp_orderNo}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_correlationId}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld={cp_orderNo}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_correlationId}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"{p_Address1}\",\"City\":\"{p_city}\",\"State\":\"{p_state}\",\"Zip\":\"{p_zipCode}\",\"Country\":\"US\",\"ContactFirstName\":\"pfirst\",\"ContactLastName\":\"Perf\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"Con"
		"tactEmail\":\"\",\"AddressName\":\"{p_Address1}\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"{cp_FirstNameAccount}\",\"LastName\":\"{cp_LastNameAccount}\",\"Email\":\"{cp_EmailAccount}\",\"Phone\":\"{cp_PhoneAccount}\",\"Locale\":\"en_US\"},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":{\"IsDisplaySaveProfileFlag\":true,\"IsServiceRequired\":true,\"IsUpdatingUserProfile\":false}}", ENDITEM,
		LAST);
*/
/*
		web_submit_data("Init", 
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/VK/Init", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=MerchantName", "Value={cp_merchantName}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=transactionTypeCode", "Value=PAN", ENDITEM, 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_submit_data("Init_2", 
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/VK/Init", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=MerchantName", "Value={cp_merchantName}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=transactionTypeCode", "Value=CVV", ENDITEM, 
		LAST);
*/
	lr_end_transaction("CP27_Checkout_LoggedIn_PSA",LR_AUTO);
	
		prandNumber = atoi(lr_eval_string("{p_randomNum}"));
		if(prandNumber<8)
		{
			CreateQuote();
		}
		else
		{
			CreatePO();
		}
	
	}
	 
	else
		
	{
	
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}
	
	
	/*
	else if(gs_ccFlag= =1)
	{
		
		lr_think_time(120);
	
	//lr_think_time(60);
	
	lr_save_string(lr_eval_string("cc_uat_r5_0001%40hotmail.com"), "p_userEmail");
	
	web_reg_save_param("cp_merchantName","LB=<input type=\"hidden\" name=\"merchantName\" value=\"","RB=\"/>","Notfound=warning",LAST);	
	web_reg_save_param("cp_sessionid","LB=<input type=\"hidden\" id=\"sessionId\" value=\"","RB=\"/>","Notfound=warning",LAST);	
	web_reg_save_param("paymentId","LB=data-pmt=\"","RB=\"","Notfound=warning",LAST);
	web_reg_save_param("cp_addr","LB=data-addr=\"","RB=\"","Notfound=warning",LAST);
	web_reg_save_param("cp_companyName","LB=data-cn=\"","RB=\"","Notfound=warning",LAST);
	web_reg_save_param("cp_userEmail","LB=data-em=\"","RB=\"","Notfound=warning",LAST);
			
		web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	lr_start_transaction("CP27_Checkout_LoggedIn");
	
	
	web_url("OrderCalculate_2", 
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?updatePrices=1&calculationUsageId=-1&calculationUsageId=-3&calculationUsageId=-4&errorViewName=AjaxOrderItemDisplayView&catalogId=10051&langId=-1&URL=OrderShippingBillingView&storeId=10151&orderId=.", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html;charset=UTF-8", 
		"Snapshot=t69.inf", 
		"Mode=HTML", 
		LAST);
	
	
		
	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513772230601&action=cupis&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html;charset=UTF-8", 
		//"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto=iMFALsTsuaO8R%2F7ab6uCT2PolvC2%2BQn5ZmFuRtC5l450iAvidp9Mhq7qCGUKYPFTp%2BFnZzGJXz8ork7GqRwumYnH3bO0DZYTtp%2B%2BH9RiMtz1zz7yCYRHjjnaWa3ccM136hyP7nvfTrPDrrY4FM92KYNpsrFW7oPo%2Br1CaA7bOB8s5QS4rfaeebYaLdNRBApOcoSGFXlVwcoc1YfsxKFDF%2FmXtMrh4Q%2FJ6a4D8MSFJLNbUqOMtB31GhMtUVZkG1aREoFKd0fAPgQLiZmntnCrG8HiUVI9hzoP1sA3ELPHCfdP8xs5n2DUNZL9na8QmgaYagW830XXqKO%2BSEDYoak4PQ%3D%3D&ddkey=https%3AOrderCalculate", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);	
	
	lr_end_transaction("CP27_Checkout_LoggedIn",LR_AUTO);
	
	
	lr_think_time(295);
	
	//lr_think_time(120);
	
	web_reg_save_param("cp_addressId","LB=\"addressId\": \"","RB=\"","Notfound=warning",LAST);
	
	web_save_timestamp_param("cp_time", LAST);
	//lr_output_message("Timestamp: %s", lr_eval_string("{cp_time}"));
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");	
	lr_start_transaction("CP28_CheckoutDetails_LoggedIn");

	web_submit_data("AjaxOrderShipInfoUpdate", 
		"Action=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderShipInfoUpdate", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html;charset=UTF-8", 
		//"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?calculationUsageId=-1&updatePrices=1&catalogId=10051&orderId=.&langId=-1&storeId=10151", 
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=editAddress", "Value=false", ENDITEM, 
		"Name=nickName", "Value=EStore_PSA_LoggedInCheckout_{cp_time}", ENDITEM, 
		"Name=firstName", "Value=Perffirst", ENDITEM, 
		"Name=lastName", "Value=Perflast", ENDITEM, 
		"Name=organizationName", "Value=", ENDITEM, 
		"Name=address1", "Value=Perfdrive", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value={p_city}", ENDITEM, 
		"Name=state", "Value={p_state}", ENDITEM, 
		"Name=zipCode", "Value={p_zipCode}", ENDITEM, 
		"Name=country", "Value=US", ENDITEM, 
		"Name=email1", "Value={p_userEmail}", ENDITEM, 
		"Name=phone1", "Value=1234567890", ENDITEM, 
		"Name=isResidenceAddr", "Value=false", ENDITEM, 
		"Name=isSmbOrder", "Value=false", ENDITEM, 
		"Name=shipModeId", "Value=11558", ENDITEM, 
		"Name=authToken", "Value={cp_authToken}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=addressType", "Value=S", ENDITEM, 
		"Name=URL", "Value=/", ENDITEM, 
		"Name=correlationId", "Value={cp_correlationId}", ENDITEM, 
		"Name=taxExemptCheck", "Value=false", ENDITEM, 
		"Name=taxExemptOrgName", "Value=", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);		
		
	web_url("RefreshCheckoutCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCheckoutCart?ajax=true&crID={cp_correlationId}&storeId=10151&langId=-1&catalogId=10051&ccf=false&cof=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html;charset=UTF-8", 
		//"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?updatePrices=1&calculationUsageId=-1&catalogId=10051&langId=-1&storeId=10151&orderId=.", 
		"Snapshot=t103.inf", 
		"Mode=HTML", 
		LAST);
	
		
	web_convert_param("cname",
			          "SourceString={cname}",
			          "SourceEncoding=HTML",
			          "TargetEncoding=URL",
			           LAST);
		
			//web_set_sockets_option("SSL_VERSION", "2&3");
			
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");	

//I Frame implementation in place of ETRPHCPage-PGS as Part of R3

web_submit_data("Pay", 
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Method=POST", 
		"RecContentType=text/html;charset=UTF-8", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t33.inf",
		"Mode=HTML", 
		ITEMDATA, 
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNo}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld="
		"{cp_orderNo}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"Perfdrive\",\"City\":\"{p_city}\",\"State\":\"{p_state}\",\"Zip\":\"{p_zipCode}\",\"Country\":\"US\",\"ContactFirstName\":\"test\",\""
		"ContactLastName\":\"test\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"ContactEmail\":\"\",\"AddressName\":\"test\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"Perffirst\",\"LastName\":\"Perflast\",\"Email\":\"{p_userEmail}\",\"Phone\":\"1234567890\",\"Locale\":\"en_US\",\"IsGuestUser\":true},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\""
		"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":{\"IsDisplaySaveProfileFlag\":true,\"IsServiceRequired\":true,\"IsUpdatingUserProfile\":false}}", ENDITEM, 
		LAST);
		
	web_submit_data("Pay_2", 
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Method=POST", 
		"RecContentType=text/html;charset=UTF-8", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t33.inf",
		"Mode=HTML", 
		ITEMDATA, 
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNo}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld="
		"{cp_orderNo}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"Perfdrive\",\"City\":\"{p_city}\",\"State\":\"{p_state}\",\"Zip\":\"{p_zipCode}\",\"Country\":\"US\",\"ContactFirstName\":\"test\",\""
		"ContactLastName\":\"test\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"ContactEmail\":\"\",\"AddressName\":\"test\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"Perffirst\",\"LastName\":\"Perflast\",\"Email\":\"{p_userEmail}\",\"Phone\":\"1234567890\",\"Locale\":\"en_US\",\"IsGuestUser\":true},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\""
		"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":\"\",\"GPay\":{\"IsServiceRequired\":true}}", ENDITEM, 
		LAST);



	lr_end_transaction("CP28_CheckoutDetails_LoggedIn",LR_AUTO);
	
	gs_ccFlag=1;
			
		
		
	}

	else
	{
		
		lr_save_string(lr_eval_string("{p_CustomerSearch_CCSaved}"), "p_userEmail");
		
		gs_ccFlag=0;
		
	}
	*/
	return 0;
}
