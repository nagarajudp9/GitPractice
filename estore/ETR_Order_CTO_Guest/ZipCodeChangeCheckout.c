ZipCodeChangeCheckout()
{
	
	lr_save_string("_CTO","cartitem");
	
	if(strcmp(lr_eval_string("{cp_orderId}"),"")==0 || strcmp(lr_eval_string("{cp_orderItemId_count}"),"")==0)
	{
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}
	
	else
		
	{
		
	
	lr_start_transaction("S27_Checkout_ChangeZipcode");
	
	web_url("AjaxOrderShipEstimate",
		"URL=https://{p_hostName}/us-en/shop/AjaxOrderShipEstimate?orderId={cp_orderId}&zipCode={p_ChangeZipCode}&authToken={authToken_URL1}&URL=%2F&storeId=10151&langId=-1&catalogId=10051&ccf=false&cql=40&cal=6000",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t35.inf",
		"Mode=HTML",
		LAST);

	web_reg_find("Text=HP US Store - Shopping Cart", 
		LAST);

	web_url("RefreshCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCart?ajax=true&storeId=10151&langId=-1&catalogId=10051&ccf=false&cql=40&cal=6000", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_5", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1524810312436&action=pis&catentryId=&modelId=&retainPOCart=false", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		LAST);


	lr_end_transaction("S27_Checkout_ChangeZipcode",LR_AUTO);
	
		lr_think_time(60);
	
		web_reg_save_param("cp_merchantName","LB=<input type=\"hidden\" name=\"merchantName\" value=\"","RB=\"/>",LAST);
	
	web_reg_save_param("cp_sessionid","LB=<input type=\"hidden\" id=\"sessionId\" value=\"","RB=\"/>","Notfound=warning",LAST);	
	
	web_reg_save_param("cp_tmid","lb=\"tmId\" value=\"","rb=\"/>","notfound=warning",LAST);
	
	web_reg_find("Text=\r\n\t\t\thpusstore - Shipping and Billing Display\r\n\t\t", LAST);
	
	web_reg_save_param("cp_krypto","LB=&krypto=","RB=&ddkey", LAST);
		
	web_reg_save_param("cp_offerprice","LB=oPrice\": \"$","RB=\",",LAST);
	
	web_reg_save_param("cp_price","LB=\"gsPrice\": \"$","RB=\",",LAST);
	
		
	lr_start_transaction("S27_Checkout_Guest");
	
	lr_start_sub_transaction(lr_eval_string("S27-1_Checkout_Guest{cartitem}{cartLineitem}"),"S27_Checkout_Guest");
	
	web_reg_save_param("tmId","LB=\"tmId\" value=\"","RB=\"/>",LAST);
	
	//lr_start_sub_transaction(lr_eval_string("S27-1_Checkout_Guest_OC{cartitem}{cartLineitem}"),"S27_Checkout_Guest");
	
	web_url("OrderCalculate_2", 
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?updatePrices=1&shipmentType=single&calculationUsageId=-1&calculationUsageId=-4&calculationUsageId=-6&errorViewName=AjaxOrderItemDisplayView&catalogId=10051&langId=-1&QuoteDisable=N&URL=OrderShippingBillingView&storeId=10151&orderId=.", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);
	
	//lr_end_sub_transaction(lr_eval_string("S27-1_Checkout_Guest_OC{cartitem}{cartLineitem}"),LR_AUTO);
	
	web_url("HPServices_5", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1582254758534&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_sub_transaction(lr_eval_string("S27-1_Checkout_Guest{cartitem}{cartLineitem}"),LR_AUTO);
	
	lr_end_transaction("S27_Checkout_Guest",LR_AUTO);
	
	lr_think_time(1);
	
	web_save_timestamp_param("cp_time", LAST);
	
	lr_save_string(lr_eval_string("{p_GuestUserEmail}"),"p_userEmail");
		
	if(atoi(lr_eval_string("{p_MelissaRandomNo}"))>0 && atoi(lr_eval_string("{p_MelissaRandomNo}"))<5)
	{

	web_reg_save_param("cp_MAddress1","LB=AddressLine1\":\"","RB=\"","ORD=ALL",LAST);
		                   
	web_reg_save_param("cp_MCity","LB=City\":\"","RB=\"","ORD=ALL",LAST);
	
	web_reg_save_param("cp_MState","LB=State\":\"","RB=\"","ORD=ALL",LAST);
	                                                         
	web_reg_save_param("cp_MZipCode","LB=PostalCode\":\"","RB=-","ORD=ALL",LAST);
	
	lr_start_transaction("S28_Checkout_Guest_TypeAhead");
		
	web_submit_data("address-recommendations", 
		"Action=https://{p_hostName}/wcs/resources/store/10151/address-recommendations", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"buKgCPx3sbwr8R3rKFTaoafunlwAO6bkLcMZDCbhB3omQkpPEVsOTf7LJiZRANCMEf6LnuEb%2FxLhilRWgO5EgXmMKMbjgIGq4T88lHqa1wTkwkHwaIcc4jy4jg7vYqaaRSh%2FII0oamh724BO7OJlxSXOmRH8vV2oIShk%2FT%2FOqmuw%2BEXz1GKcYCsXplE8qV8Van8fN3wBuJCIhfjNXgjJ7R5nsdrHDyAsA6Pvcl15WeiqU5NJSdL7rfUrvS16F9fE3oCfAUg8lXSnp%2FN4zWHt4%2BxFMunzF9a6aRhpRF2RMAayoNjUWItvt8mUh6A0WiF1aFTokZvhW3GPq6OnNuXTDbwflBMjk%2FNA%2B1xoSiEXZ0%2B6F37Gg66FmA2Iw4GB8U3bn4evo2PHZC9x2CESTAk5YQ%3D%3D&ddkey=https%3AOrderCalculate", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=ff", "Value={p_MelissaAddress}", ENDITEM,
		LAST);

	mj=rand()% (atoi(lr_eval_string("{cp_MAddress1_count}")))+1;
	
	lr_save_int(mj,"PartNo");
	
	lr_save_string(lr_eval_string(lr_eval_string("{cp_MAddress1_{PartNo}}")),"p_Address1New");
	
	lr_save_string(lr_eval_string(lr_eval_string("{cp_MCity_{PartNo}}")),"p_CityNew");
	
	lr_save_string(lr_eval_string(lr_eval_string("{cp_MState_{PartNo}}")),"p_StateNew");
	
	lr_save_string(lr_eval_string(lr_eval_string("{cp_MZipCode_{PartNo}}")),"p_ZipCodeNew");
	
	lr_save_string(lr_eval_string("{p_FirstName}"),"p_FirstNameNew");
	
	lr_save_string(lr_eval_string("{p_LastName}"),"p_LastNameNew");
	
	lr_save_string(lr_eval_string("{p_CompanyName}"),"p_CompanyNameNew");
	
	lr_save_string(lr_eval_string("{p_Address2}"),"p_Address2New");
	
	lr_save_string(lr_eval_string("{p_Phone}"),"p_PhoneNew");
	
	lr_end_transaction("S28_Checkout_Guest_TypeAhead",LR_AUTO);

	web_reg_save_param("cp_addressId","LB=addressId\": \"","RB=\"","Notfound=warning",LAST);	
	
	lr_start_transaction("S28_CheckoutDetails_Guest");	
	
	//lr_start_sub_transaction("S28-1_Guest_AjaxOrderShipInfoUpdate","S28_CheckoutDetails_Guest");
	
	web_submit_data("AjaxOrderShipInfoUpdate", 
		"Action=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderShipInfoUpdate", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=editAddress", "Value=false", ENDITEM, 
		"Name=nickName", "Value=EStore_CTO_GC_{cp_time}", ENDITEM, 
		"Name=firstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=lastName", "Value=Perf", ENDITEM, 
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
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	//lr_end_sub_transaction("S28-1_Guest_AjaxOrderShipInfoUpdate",LR_AUTO);

	web_reg_save_param("cp_EstGrandTotal","LB=EstGrandTotal\": \"","RB=\",\r\n","Notfound=warning",LAST);
	web_reg_save_param("cp_EstGrandTotal02","LB=EstGrandTotal\": \"","RB=.","Notfound=warning",LAST);
	web_reg_save_param("cp_TotalTaxAmount","LB=TotalTaxAmount\": \"","RB=\",\r\n","Notfound=warning",LAST);
	web_reg_save_param("cp_Item_Price","LB=Item_Price\": \"","RB=\",\r\n","Notfound=warning",LAST);
	web_reg_save_param("cp_Item_Name","LB=Item_Name\": \"","RB=\",\r\n","Notfound=warning",LAST);
	web_reg_save_param("cp_Item_Code","LB=Item_Code\": \"","RB=\",\r\n","Notfound=warning",LAST);

	//lr_start_sub_transaction("S28-2_Guest_RefreshCheckoutCart","S28_CheckoutDetails_Guest");

	web_url("RefreshCheckoutCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCheckoutCart?ajax=true&crID={cp_correlationId}&storeId=10151&langId=-1&catalogId=10051&ccf=false&cof=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);


	if(strcmp(lr_eval_string("{cp_TotalTaxAmount}"),"")==0)
	{
		
	//lr_end_sub_transaction("S28-2_Guest_RefreshCheckoutCart",LR_FAIL);
	
	}
	else
	{	
		//lr_end_sub_transaction("S28-2_Guest_RefreshCheckoutCart",LR_PASS);
	}

	//lr_start_sub_transaction("S28-3_Guest_Pay","S28_CheckoutDetails_Guest");

	web_reg_save_param("cp_PaymentRequest","LB=JWT&quot;:&quot;","RB=&quot;","Notfound=warning",LAST);

	web_submit_data("Pay", 
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t33.inf",
		"Mode=HTML", 
		ITEMDATA, 
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNo}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld="
		"{cp_orderNo}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"{p_Address1New}\",\"City\":\"{p_CityNew}\",\"State\":\"{p_StateNew}\",\"Zip\":\"{p_ZipCodeNew}\",\"Country\":\"US\",\"ContactFirstName\":\"test\",\""
		"ContactLastName\":\"Perf\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"ContactEmail\":\"\",\"AddressName\":\"test\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"{p_FirstNameNew}\",\"LastName\":\"Perf\",\"Email\":\"{p_userEmail}\",\"Phone\":\"{p_PhoneNew}\",\"Locale\":\"en_US\",\"IsGuestUser\":true},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\""
		"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":{\"IsDisplaySaveProfileFlag\":true,\"IsServiceRequired\":true,\"IsUpdatingUserProfile\":false}}", ENDITEM, 
		LAST);
	
web_reg_save_param("cp_EstGrandTotal01","LB=EstGrandTotal_NoDecimal&quot;:","RB=,&quot;EstGrandTotal",LAST);

	web_submit_data("Pay_2", 
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t33.inf",
		"Mode=HTML", 
		ITEMDATA, 
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNo}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld="
		"{cp_orderNo}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"{p_Address1New}\",\"City\":\"{p_CityNew}\",\"State\":\"{p_StateNew}\",\"Zip\":\"{p_ZipCodeNew}\",\"Country\":\"US\",\"ContactFirstName\":\"test\",\""
		"ContactLastName\":\"Perf\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"ContactEmail\":\"\",\"AddressName\":\"test\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"{p_FirstNameNew}\",\"LastName\":\"Perf\",\"Email\":\"{p_userEmail}\",\"Phone\":\"{p_PhoneNew}\",\"Locale\":\"en_US\",\"IsGuestUser\":true},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\""
		"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":\"\",\"GPay\":{\"IsServiceRequired\":true}}", ENDITEM, 
		LAST);

	//lr_end_sub_transaction("S28-3_Guest_Pay",LR_AUTO);

	lr_end_transaction("S28_CheckoutDetails_Guest",LR_AUTO);
	
	//lr_save_string(string_replace(lr_eval_string("{cp_EstGrandTotal}"),".",""),"cp_EstGrandTotal01");
	
	}
	else
	{

	if((atoi(lr_eval_string("{p_MelissaRandomNo}")))>0 && (atoi(lr_eval_string("{p_MelissaRandomNo}")))<25)
	{
		
	lr_save_string("123 Perf Street","p_Address1New");
	
	lr_save_string(lr_eval_string("{p_city}"),"p_CityNew");
	
	lr_save_string(lr_eval_string("{p_state}"),"p_StateNew");
	
	lr_save_string(lr_eval_string("{p_zipCode}"),"p_ZipCodeNew");
	
	lr_save_string(lr_eval_string("{p_FirstName}"),"p_FirstNameNew");
	
	lr_save_string(lr_eval_string("{p_LastName}"),"p_LastNameNew");
	
	lr_save_string(lr_eval_string("{p_CompanyName}"),"p_CompanyNameNew");
	
	lr_save_string(lr_eval_string("{p_Address2}"),"p_Address2New");
	
	lr_save_string(lr_eval_string("{p_Phone}"),"p_PhoneNew");
	}
	else
	{
	lr_save_string(lr_eval_string("{p_Address1}"),"p_Address1New");
	
	lr_save_string(lr_eval_string("{p_city}"),"p_CityNew");
	
	lr_save_string(lr_eval_string("{p_state}"),"p_StateNew");
	
	lr_save_string(lr_eval_string("{p_zipCode}"),"p_ZipCodeNew");
	
	lr_save_string(lr_eval_string("{p_FirstName}"),"p_FirstNameNew");
	
	lr_save_string(lr_eval_string("{p_LastName}"),"p_LastNameNew");
	
	lr_save_string(lr_eval_string("{p_CompanyName}"),"p_CompanyNameNew");
	
	lr_save_string(lr_eval_string("{p_Address2}"),"p_Address2New");
	
	lr_save_string(lr_eval_string("{p_Phone}"),"p_PhoneNew");
	}
	
	web_reg_save_param("cp_addressId","LB=\"addressId\": \"","RB=\"",LAST);
	
	lr_start_transaction("S28_CheckoutDetails_Guest");
		
	//lr_start_sub_transaction("S28-1_Guest_AjaxOrderShipInfoUpdate","S28_CheckoutDetails_Guest");
	
	web_submit_data("AjaxOrderShipInfoUpdate", 
		"Action=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderShipInfoUpdate", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=editAddress", "Value=false", ENDITEM, 
		"Name=nickName", "Value=EStore_CTO_GC_{cp_time}", ENDITEM, 
		"Name=firstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=lastName", "Value=Perf", ENDITEM, 
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
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	//lr_end_sub_transaction("S28-1_Guest_AjaxOrderShipInfoUpdate",LR_AUTO);

	web_reg_save_param("cp_EstGrandTotal","LB=EstGrandTotal\": \"","RB=\",\r\n","Notfound=warning",LAST);
	web_reg_save_param("cp_EstGrandTotal02","LB=EstGrandTotal\": \"","RB=.","Notfound=warning",LAST);
	web_reg_save_param("cp_TotalTaxAmount","LB=TotalTaxAmount\": \"","RB=\",\r\n","Notfound=warning",LAST);
	web_reg_save_param("cp_Item_Price","LB=Item_Price\": \"","RB=\",\r\n","Notfound=warning",LAST);
	web_reg_save_param("cp_Item_Name","LB=Item_Name\": \"","RB=\",\r\n","Notfound=warning",LAST);
	web_reg_save_param("cp_Item_Code","LB=Item_Code\": \"","RB=\",\r\n","Notfound=warning",LAST);

	//lr_start_sub_transaction("S28-2_Guest_RefreshCheckoutCart","S28_CheckoutDetails_Guest");

	web_url("RefreshCheckoutCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCheckoutCart?ajax=true&crID={cp_correlationId}&storeId=10151&langId=-1&catalogId=10051&ccf=false&cof=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);

	if(strcmp(lr_eval_string("{cp_TotalTaxAmount}"),"")==0)
	{
		
	//lr_end_sub_transaction("S28-2_Guest_RefreshCheckoutCart",LR_FAIL);
	
	}
	else
	{	
		//lr_end_sub_transaction("S28-2_Guest_RefreshCheckoutCart",LR_PASS);
	}

	//lr_start_sub_transaction("S28-3_Guest_Pay","S28_CheckoutDetails_Guest");

	web_reg_save_param("cp_PaymentRequest","LB=JWT&quot;:&quot;","RB=&quot;","Notfound=warning",LAST);

	web_submit_data("Pay", 
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t33.inf",
		"Mode=HTML", 
		ITEMDATA, 
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNo}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld="
		"{cp_orderNo}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"{p_Address1New}\",\"City\":\"{p_CityNew}\",\"State\":\"{p_StateNew}\",\"Zip\":\"{p_ZipCodeNew}\",\"Country\":\"US\",\"ContactFirstName\":\"test\",\""
		"ContactLastName\":\"Perf\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"ContactEmail\":\"\",\"AddressName\":\"test\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"{p_FirstNameNew}\",\"LastName\":\"Perf\",\"Email\":\"{p_userEmail}\",\"Phone\":\"{p_PhoneNew}\",\"Locale\":\"en_US\",\"IsGuestUser\":true},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\""
		"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":{\"IsDisplaySaveProfileFlag\":true,\"IsServiceRequired\":true,\"IsUpdatingUserProfile\":false}}", ENDITEM, 
		LAST);
	
	web_reg_save_param("cp_EstGrandTotal01","LB=EstGrandTotal_NoDecimal&quot;:","RB=,&quot;EstGrandTotal",LAST);
	
	web_submit_data("Pay_2", 
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t33.inf",
		"Mode=HTML", 
		ITEMDATA, 
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNo}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld="
		"{cp_orderNo}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"{p_Address1New}\",\"City\":\"{p_CityNew}\",\"State\":\"{p_StateNew}\",\"Zip\":\"{p_ZipCodeNew}\",\"Country\":\"US\",\"ContactFirstName\":\"test\",\""
		"ContactLastName\":\"Perf\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"ContactEmail\":\"\",\"AddressName\":\"test\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"{p_FirstNameNew}\",\"LastName\":\"Perf\",\"Email\":\"{p_userEmail}\",\"Phone\":\"{p_PhoneNew}\",\"Locale\":\"en_US\",\"IsGuestUser\":true},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\""
		"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":\"\",\"GPay\":{\"IsServiceRequired\":true}}", ENDITEM, 
		LAST);

	//lr_end_sub_transaction("S28-3_Guest_Pay",LR_AUTO);

	lr_end_transaction("S28_CheckoutDetails_Guest",LR_AUTO);
	
	//lr_save_string(string_replace(lr_eval_string("{cp_EstGrandTotal}"),".",""),"cp_EstGrandTotal01");

	}
	
	}
	
	lr_think_time(60);

return 0;
}
