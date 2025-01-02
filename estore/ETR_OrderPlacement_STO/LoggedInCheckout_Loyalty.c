LoggedInCheckout_Loyalty()
{
	lr_think_time(60);

web_set_max_html_param_len("99999");

	web_reg_save_param_ex("ParamName=cp_tmid","LB=\"tmId\" value=\"","RB=\"/>",LAST);	

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

	web_reg_save_param_ex("ParamName=cp_EstGrandTotal","LB=EstGrandTotal\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_TotalTaxAmount","LB=TotalTaxAmount\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Price","LB=Item_Price\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Name","LB=Item_Name\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Code","LB=Item_Code\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_save_timestamp_param("cp_time", LAST);
	
	lr_start_transaction(lr_eval_string("S27_Checkout_LoggedIn{cartitem}"));
	
	web_reg_save_param_ex("ParamName=cp_krypto1","LB=&krypto=","RB=&ddkey", SEARCH_FILTERS,"Scope=Headers",LAST);
	
	

	web_url("OrderCalculate_2", 
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?updatePrices=1&shipmentType=single&calculationUsageId=-1&calculationUsageId=-4&calculationUsageId=-6&errorViewName=AjaxOrderItemDisplayView&catalogId=10051&langId=-1&QuoteDisable=N&URL=OrderShippingBillingView&storeId=10151&orderId=.", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t78.inf", 
		"Mode=HTML", 
		LAST);

	

	web_url("HPServices_11", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1599330360985&action=cupids&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto1}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t80.inf", 
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
	


	web_submit_data("Pay",
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay",
		"Method=POST",
		"EncodeAtSign=YES",
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop",
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
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t27.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNo}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_correlationId}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld={cp_orderNo}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_correlationId}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"{cp_CurrentAddress}\",\"City\":\"{cp_CurrentCity}\",\"State\":\"{cp_CurrentState}\",\"Zip\":\"{cp_CurrentZipCode}\",\"Country\":\"US\",\"ContactFirstName\":\"{cp_CurrentFirstName}\",\"ContactLastName\":\"{cp_CurrentLastName}\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"Con"
		"tactEmail\":\"\",\"AddressName\":\"{cp_CurrentAddress}\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"{cp_FirstNameAccount}\",\"LastName\":\"{cp_LastNameAccount}\",\"Email\":\"{cp_EmailAccount}\",\"Phone\":\"{cp_PhoneAccount}\",\"Locale\":\"en_US\"},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":\"\",\"GPay\":{\"IsServiceRequired\":true}}", ENDITEM,
		LAST);
		


	
	lr_end_transaction(lr_eval_string("S27_Checkout_LoggedIn{cartitem}"),LR_AUTO);

	
	lr_think_time(120);
	
	lr_save_string(lr_eval_string("{p_Address1}"),"p_Address1New");
	
	lr_save_string(lr_eval_string("{p_city}"),"p_CityNew");
	
	lr_save_string(lr_eval_string("{p_state}"),"p_StateNew");
	
	lr_save_string(lr_eval_string("{p_zipCode}"),"p_ZipCodeNew");
	
	lr_save_string(lr_eval_string("{p_FirstName}"),"p_FirstNameNew");
	
	lr_save_string(lr_eval_string("{p_LastName}"),"p_LastNameNew");
	
	lr_save_string(lr_eval_string("{p_CompanyName}"),"p_CompanyNameNew");
	
	lr_save_string(lr_eval_string("{p_Address2}"),"p_Address2New");
	
	lr_save_string(lr_eval_string("{p_Phone}"),"p_PhoneNew");
	
	web_reg_save_param("cp_addressId","LB=\"addressId\": \"","RB=\"","Notfound=warning",LAST);
	
	lr_start_transaction(lr_eval_string("S28_CheckoutDetails_LoggedIn{cartitem}"));



	web_submit_data("AjaxOrderShipInfoUpdate",
		"Action=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderShipInfoUpdate", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?calculationUsageId=-1&updatePrices=1&catalogId=10051&orderId=.&langId=-1&storeId=10151", 
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=editAddress", "Value=false", ENDITEM, 
		"Name=nickName", "Value=EStore_STO_LoggedInCheckout_{cp_time}", ENDITEM, 
		"Name=firstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=lastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=organizationName", "Value=", ENDITEM, 
		"Name=address1", "Value={p_Address1New}", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value={p_CityNew}", ENDITEM, 
		"Name=state", "Value={p_StateNew}", ENDITEM, 
		"Name=zipCode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=country", "Value=US", ENDITEM, 
		"Name=email1", "Value={p_userEmail}", ENDITEM, 
		"Name=phone1", "Value={p_PhoneNew}", ENDITEM, 
		"Name=isResidenceAddr", "Value=false", ENDITEM, 
		"Name=isSmbOrder", "Value=false", ENDITEM, 
		"Name=shipModeId", "Value=12056", ENDITEM, 
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
		"Name=redeemPoints", "Value={p_rewardsApply}", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
		
	

	if(strcmp(lr_eval_string("{cp_addressId}"),"")==0)
		
	{

		
		lr_end_transaction("S28_CheckoutDetails_LoggedIn{cartitem}",LR_FAIL);
		
		Logout();
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	else
	{

	}	
		
web_reg_save_param_ex("ParamName=cp_EstGrandTotal","LB=EstGrandTotal\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_TotalTaxAmount","LB=TotalTaxAmount\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Price","LB=Item_Price\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Name","LB=Item_Name\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Code","LB=Item_Code\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param("cp_adjprice","LB=orderSavings\">$","RB=</span>","Notfound=warning",LAST);
		

		
		web_url("RefreshCheckoutCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCheckoutCart?ajax=true&crID={cp_correlationId}&storeId=10151&langId=-1&catalogId=10051&ccf=false&cof=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?updatePrices=1&calculationUsageId=-1&catalogId=10051&langId=-1&storeId=10151&orderId=.", 
		"Snapshot=t103.inf", 
		"Mode=HTML", 
		LAST);
		
		
		if(strcmp(lr_eval_string("{cp_TotalTaxAmount}"),"")==0)
	{
		


	lr_end_transaction("S28_CheckoutDetails_LoggedIn{cartitem}",LR_FAIL);
	
	Logout();

	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	
	}
	else
	{	

	}
		
		

web_convert_param("cp_pdpname",
			                  "SourceString={cp_pdpname}",
			                  "SourceEncoding=HTML",
			                  "TargetEncoding=URL",
			                  LAST);
		
		lr_end_transaction(lr_eval_string("S28_CheckoutDetails_LoggedIn{cartitem}"),LR_AUTO);
		
		
		
//	Pay_CreditCard(4);
	if(atoi(lr_eval_string("{p_randomNo}"))<7)
	{
	Pay_CreditCard(4);
	}
	else
	{
		BackToCart();
		RemoveCart();
	}	

	return 0;
}
