LoggedInCheckout_EUA()
{
	
	web_set_max_html_param_len("99999");
	
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
	
	
	web_url("OrderCalculate_2", 
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?updatePrices=1&shipmentType=single&calculationUsageId=-1&calculationUsageId=-4&calculationUsageId=-6&errorViewName=AjaxOrderItemDisplayView&catalogId=10051&langId=-1&QuoteDisable=N&URL=OrderShippingBillingView&storeId=10151&orderId=.", 
		"Resource=0", 
		"RecContentType=text/html", 
	//	"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		LAST);

	
	
	web_url("HPServices_6", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1598090770007&action=cupids&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
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
	
	if(strcmp(lr_eval_string("{cp_PaymentRequest}"),"")==0)
	{

	
		lr_end_transaction("S27_Checkout_LoggedIn_EUA",LR_FAIL);
		
		Logout();
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	else
	{

	
		lr_end_transaction("S27_Checkout_LoggedIn_EUA",LR_PASS);
		
	}

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
	

	
/*	lr_start_transaction("S28_CheckoutDetails_LoggedIn_EUA");
	
//	lr_start_sub_transaction("S28-1_LoggedIn_AjaxOrderShipInfoUpdate","S28_CheckoutDetails_LoggedIn_EUA");	

	web_submit_data("AjaxOrderShipInfoUpdate_2", 
		"Action=https://{p_hostName}/us-en/shop/AjaxOrderShipInfoUpdate", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t47.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=editAddress", "Value=false", ENDITEM, 
		"Name=nickName", "Value=EStore_STO_LoggedInCheckout_EUA_{cp_time}", ENDITEM, 
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
		"Name=isSmbOrder", "Value=true", ENDITEM, 
		"Name=shipModeId", "Value=12056", ENDITEM, 
		"Name=authToken", "Value={cp_authToken}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=addressType", "Value=S", ENDITEM, 
		"Name=URL", "Value=/", ENDITEM, 
		"Name=correlationId", "Value={cp_correlationId}", ENDITEM, 
		"Name=taxExemptCheck", "Value=false", ENDITEM, 
		"Name=taxExemptOrgName", "Value=", ENDITEM, 
		"Name=phone", "Value={p_PhoneNew}", ENDITEM, 
		"Name=sDefaultAddrId", "Value={cp_DefaultaddressId}", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	if(strcmp(lr_eval_string("{cp_addressId}"),"")==0)
		
	{
//		lr_end_sub_transaction("S28-1_LoggedIn_AjaxOrderShipInfoUpdate",LR_FAIL);
		
		lr_end_transaction("S28_CheckoutDetails_LoggedIn_EUA",LR_FAIL);
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	else
	{
//		lr_end_sub_transaction("S28-1_LoggedIn_AjaxOrderShipInfoUpdate",LR_PASS);
	}
	
//	lr_start_sub_transaction("S28-2_LoggedIn_RefreshCheckoutCart","S28_CheckoutDetails_LoggedIn_EUA");

	web_url("RefreshCheckoutCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCheckoutCart?ajax=true&crID=H336722760_1598090762897&storeId=10151&langId=-1&catalogId=10051&ccf=false&cof=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		LAST);
	
//	lr_end_sub_transaction("S28-2_LoggedIn_RefreshCheckoutCart",LR_AUTO);
	
		if(strcmp(lr_eval_string("{cp_TotalTaxAmount}"),"")==0)
	{
		
//	lr_end_sub_transaction("S28-2_LoggedIn_RefreshCheckoutCart",LR_FAIL);
	
	lr_end_transaction("S28_CheckoutDetails_LoggedIn_EUA",LR_FAIL);
	
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	
	}
	else
	{	
//	lr_end_sub_transaction("S28-2_LoggedIn_RefreshCheckoutCart",LR_PASS);
	
//	lr_end_transaction("S28_CheckoutDetails_LoggedIn_EUA",LR_PASS);
	}
	
	lr_end_transaction("S28_CheckoutDetails_LoggedIn_EUA",LR_AUTO);
*/	
	web_reg_save_param("cp_quoteNo","LB=\"quoteNo\": \"","RB=\"","NotFound=Warning",LAST);
	
	lr_start_transaction("S61_CreateQuote");

	web_submit_data("AjaxQuoteCreate", 
		"Action=https://{p_hostName}/us-en/shop/AjaxQuoteCreate", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t50.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
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
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=subAuthNo", "Value=12345678901", ENDITEM, 
		"Name=nickName", "Value={p_FirstNameNew}{cp_time}", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);

	web_submit_data("SendQuoteToTibco", 
		"Action=https://{p_hostName}/us-en/shop/SendQuoteToTibco", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t51.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=quoteNo", "Value={cp_quoteNo}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);

	web_submit_data("quoteDetailsView", 
		"Action=https://{p_hostName}/us-en/shop/quoteDetailsView?catalogId=10051&langId=-1&storeId=10151", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t52.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=quoteId", "Value={cp_orderId}", ENDITEM, 
		"Name=quoteCreated", "Value=Y", ENDITEM, 
		LAST);

	web_url("HPServices_7", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1598090991683&action=cupids&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/quoteDetailsView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t53.inf", 
		"Mode=HTML", 
		LAST);

	if(strcmp(lr_eval_string("{cp_quoteNo}"),"")!=0)
		{
			lr_end_transaction("S61_CreateQuote",LR_PASS);
			
		

		}
		else
		{
			lr_end_transaction("S61_CreateQuote",LR_FAIL);
			
			Cart();
			
			RemoveCart();
			
			Logout();
			
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
		}
	
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
	
	web_reg_save_param("cp_orderIdNew","LB=<input type=\"hidden\" name=\"orderId\" value=\"","RB=\"/>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_correlationIdNew","LB=&crID=","RB=&QuoteDisable","Notfound=warning",LAST);
	
	web_reg_save_param("cp_orderNoNew","LB=\"OrderID\": \"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_PartnerId","LB=Please enter a valid location\" value=\"","RB=\" />","Notfound=warning",LAST);
	
	web_reg_save_param("cp_PartnerName","LB=Please enter a valid name\" value=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_PartnerCity","LB=Please enter a valid city\" value=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_PartnerState","LB=Please enter a valid state\" value=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_PartnerZipCode","LB=Please enter a valid zip code\" value=\"","RB=\"","Notfound=warning",LAST);
	
	web_save_timestamp_param("cp_time", LAST);
	
	lr_start_transaction("S62_ConvertQuoteToOrder");
	
	
web_url("QuoteGenerateOrder", 
		"URL=https://{p_hostName}/us-en/shop/QuoteGenerateOrder?pStoreID=fedex&createOrder=Y&catalogId=10051&orderId={cp_orderId}&storeId=10151&langId=-1&errorViewName=AjaxOrderItemDisplayView&QuoteDisable=Y&URL=OrderShippingBillingView", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/quoteDetailsView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);
	/*
	web_url("QuoteGenerateOrder", 
		"URL=https://{p_hostName}/us-en/shop/QuoteGenerateOrder?errorViewName=AjaxOrderItemDisplayView&catalogId=10051&langId=-1&QuoteDisable=Y&URL=OrderShippingBillingView&storeId=10151&orderId={cp_orderId}&createOrder=Y", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/quoteDetailsView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t54.inf", 
		"Mode=HTML", 
		LAST);
*/
	web_url("HPServices_8", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1598091062018&action=cupids&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t55.inf", 
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
	

	
	web_submit_data("Pay_3",
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay",
		"Method=POST",
		"EncodeAtSign=YES",
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t26.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNoNew}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNoNew}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_correlationIdNew}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld={cp_orderNoNew}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_correlationIdNew}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"{cp_CurrentAddress}\",\"City\":\"{cp_CurrentCity}\",\"State\":\"{cp_CurrentState}\",\"Zip\":\"{cp_CurrentZipCode}\",\"Country\":\"US\",\"ContactFirstName\":\"{cp_CurrentFirstName}\",\"ContactLastName\":\"{cp_CurrentLastName}\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"Con"
		"tactEmail\":\"\",\"AddressName\":\"{cp_CurrentAddress}\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"{cp_FirstNameAccount}\",\"LastName\":\"{cp_LastNameAccount}\",\"Email\":\"{cp_EmailAccount}\",\"Phone\":\"{cp_PhoneAccount}\",\"Locale\":\"en_US\"},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":{\"IsDisplaySaveProfileFlag\":true,\"IsServiceRequired\":true,\"IsUpdatingUserProfile\":false}}", ENDITEM,
		LAST);

	web_submit_data("Pay_4",
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay",
		"Method=POST",
		"EncodeAtSign=YES",
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t27.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNoNew}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNoNew}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_correlationIdNew}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld={cp_orderNoNew}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_correlationIdNew}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"{cp_CurrentAddress}\",\"City\":\"{cp_CurrentCity}\",\"State\":\"{cp_CurrentState}\",\"Zip\":\"{cp_CurrentZipCode}\",\"Country\":\"US\",\"ContactFirstName\":\"{cp_CurrentFirstName}\",\"ContactLastName\":\"{cp_CurrentLastName}\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"Con"
		"tactEmail\":\"\",\"AddressName\":\"{cp_CurrentAddress}\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"{cp_FirstNameAccount}\",\"LastName\":\"{cp_LastNameAccount}\",\"Email\":\"{cp_EmailAccount}\",\"Phone\":\"{cp_PhoneAccount}\",\"Locale\":\"en_US\"},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":\"\",\"GPay\":{\"IsServiceRequired\":true}}", ENDITEM,
		LAST);
	

	
	if(strcmp(lr_eval_string("{cp_PaymentRequest}"),"")==0)
	{

	
		lr_end_transaction("S62_ConvertQuoteToOrder",LR_FAIL);
		
		Logout();
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	else
	{

	
		lr_end_transaction("S62_ConvertQuoteToOrder",LR_PASS);
		
	}
	
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
	
	
	
/*	lr_start_transaction("S28_CheckoutDetails_LoggedIn_EUA");
	
//	lr_start_sub_transaction("S28-1_LoggedIn_AjaxOrderShipInfoUpdate","S28_CheckoutDetails_LoggedIn_EUA");	

	web_submit_data("AjaxOrderShipInfoUpdate_3", 
		"Action=https://{p_hostName}/us-en/shop/AjaxOrderShipInfoUpdate", 
		"Method=POST", 
		"RecContentType=text/html", 
	"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t67.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=editAddress", "Value=false", ENDITEM, 
		"Name=nickName", "Value=EStore_STO_LoggedInCheckout_EUA_{cp_time}", ENDITEM, 
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
		"Name=isSmbOrder", "Value=true", ENDITEM, 
		"Name=shipModeId", "Value=12056", ENDITEM, 
		"Name=authToken", "Value={cp_authToken}", ENDITEM, 
		"Name=orderId", "Value={cp_orderIdNew}", ENDITEM, 
		"Name=addressType", "Value=S", ENDITEM, 
		"Name=URL", "Value=/", ENDITEM, 
		"Name=correlationId", "Value={cp_correlationIdNew}", ENDITEM, 
		"Name=taxExemptCheck", "Value=false", ENDITEM, 
		"Name=taxExemptOrgName", "Value=", ENDITEM, 
		"Name=phone", "Value={p_PhoneNew}", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	if(strcmp(lr_eval_string("{cp_addressId}"),"")==0)
		
	{
//		lr_end_sub_transaction("S28-1_LoggedIn_AjaxOrderShipInfoUpdate",LR_FAIL);
		
		lr_end_transaction("S28_CheckoutDetails_LoggedIn_EUA",LR_FAIL);
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	else
	{
//		lr_end_sub_transaction("S28-1_LoggedIn_AjaxOrderShipInfoUpdate",LR_AUTO);
	}
	
	web_reg_save_param_ex("ParamName=cp_EstGrandTotal","LB=EstGrandTotal\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_TotalTaxAmount","LB=TotalTaxAmount\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Price","LB=Item_Price\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Name","LB=Item_Name\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Code","LB=Item_Code\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param("cp_adjprice","LB=orderSavings\">$","RB=</span>","Notfound=warning",LAST);
	
//	lr_start_sub_transaction("S28-2_LoggedIn_RefreshCheckoutCart","S28_CheckoutDetails_LoggedIn_EUA");	

	web_url("RefreshCheckoutCart_2", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCheckoutCart?ajax=true&crID=H336722912_1598091057298&storeId=10151&langId=-1&catalogId=10051&ccf=false&cof=true", 
		"Resource=0", 
		"RecContentType=text/html", 
	"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t68.inf", 
		"Mode=HTML", 
		LAST);

	if(strcmp(lr_eval_string("{cp_TotalTaxAmount}"),"")==0)
	{
		
//	lr_end_sub_transaction("S28-2_LoggedIn_RefreshCheckoutCart",LR_FAIL);
	
	lr_end_transaction("S28_CheckoutDetails_LoggedIn_EUA",LR_FAIL);
	}
	else
	{	
//	lr_end_sub_transaction("S28-2_LoggedIn_RefreshCheckoutCart",LR_PASS);
	
	lr_end_transaction("S28_CheckoutDetails_LoggedIn_EUA",LR_PASS);
	}
	
//	Pay_CreditCard(2);
	
*/

if(atoi(lr_eval_string("{p_randomNo}"))<7)
	{
	Pay_CreditCard(2);
	}
	else
	{
		BackToCart();
		RemoveCart();
	}
	
	return 0;
}
