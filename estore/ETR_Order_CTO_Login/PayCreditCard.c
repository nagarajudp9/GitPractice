PayCreditCard()
{

	
	if((strcmp(lr_eval_string("{p_LastName}"),"")==0) || strcmp(lr_eval_string("{cp_merchantName}"),"")==0 || strcmp(lr_eval_string("{cp_addressId}"),"")==0)
	{
		
		Logout();
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	
	}

if(atoi(lr_eval_string("{p_randomNum01}"))<5)
    {
	

	int prandNumber=0;
	
	lr_think_time(120);
	
	web_add_header("Origin", 
		"https://vphcitg.pgs.ext.hp.com");

	if(gs_ccFlag == 1)  // Pay Credit Card for CC user
		
	{
		
		
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
	
	web_reg_save_param("cp_tmid","lb=\"tmId\" value=\"","rb=\"/>","notfound=warning",LAST);
	

	web_save_timestamp_param("cp_time", LAST);
	
	lr_start_transaction("S27_Checkout_CC_Saved");
	
	web_url("OrderCalculate_2", 
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?updatePrices=1&shipmentType=single&calculationUsageId=-1&calculationUsageId=-4&calculationUsageId=-6&errorViewName=AjaxOrderItemDisplayView&catalogId=10051&langId=-1&QuoteDisable=N&URL=OrderShippingBillingView&storeId=10151&orderId=.&testParam=828", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t69.inf", 
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
	
	web_submit_data("AjaxOrderShipInfoUpdate", 
		"Action=https://{p_hostName}/us-en/shop/AjaxOrderShipInfoUpdate", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=editAddress", "Value=true", ENDITEM, 
		"Name=nickName", "Value={cp_CurrentNickName}", ENDITEM, 
		"Name=addressId", "Value={cp_addressId}", ENDITEM, 
		"Name=firstName", "Value={cp_CurrentFirstName}", ENDITEM, 
		"Name=lastName", "Value={cp_CurrentLastName}", ENDITEM, 
		"Name=organizationName", "Value=", ENDITEM, 
		"Name=address1", "Value={cp_CurrentAddress}", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value={cp_CurrentCity}", ENDITEM, 
		"Name=state", "Value={cp_CurrentState}", ENDITEM, 
		"Name=zipCode", "Value={cp_CurrentZipCode}", ENDITEM, 
		"Name=country", "Value=US", ENDITEM, 
		"Name=email1", "Value={p_userEmail}", ENDITEM, 
		"Name=phone1", "Value={cp_CurrentPhone}", ENDITEM, 
		"Name=isResidenceAddr", "Value=true", ENDITEM, 
		"Name=isSmbOrder", "Value=false", ENDITEM, 
		"Name=shipModeId", "Value=12056", ENDITEM, 
		"Name=authToken", "Value={cp_authToken}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=addressType", "Value=S", ENDITEM, 
		"Name=URL", "Value=/", ENDITEM, 
		"Name=correlationId", "Value={cp_correlationId}", ENDITEM, 
		"Name=taxExemptCheck", "Value=false", ENDITEM, 
		"Name=taxExemptOrgName", "Value=", ENDITEM, 
		"Name=phone", "Value={cp_CurrentPhone}", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
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
	
	web_reg_save_param_ex("ParamName=cp_EstGrandTotal","LB=EstGrandTotal\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_TotalTaxAmount","LB=TotalTaxAmount\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Price","LB=Item_Price\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Name","LB=Item_Name\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Code","LB=Item_Code\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param("cp_adjprice","LB=orderSavings\">$","RB=</span>","Notfound=warning",LAST);
		
	web_url("RefreshCheckoutCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCheckoutCart?ajax=true&crID={cp_correlationId}&storeId=10151&langId=-1&catalogId=10051&ccf=false&cof=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);
	
	web_submit_data("HPAddressAdd",
		"Action=https://{p_hostName}/us-en/shop/HPAddressAdd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=shipFirstName", "Value={cp_CurrentFirstName}", ENDITEM, 
		"Name=shipLastName", "Value={cp_CurrentLastName}", ENDITEM, 
		"Name=companyinput", "Value=", ENDITEM, 
		"Name=shipAddress1", "Value={cp_CurrentAddress}", ENDITEM, 
		"Name=shipAddress2", "Value=", ENDITEM, 
		"Name=shipCity", "Value={cp_CurrentCity}", ENDITEM, 
		"Name=shipState", "Value={cp_CurrentState}", ENDITEM, 
		"Name=shipZipcode", "Value={cp_CurrentZipCode}", ENDITEM, 
		"Name=shipPhoneno", "Value={cp_CurrentPhone}", ENDITEM, 
		"Name=billFirstName", "Value={cp_CurrentFirstName}", ENDITEM, 
		"Name=billLastName", "Value={cp_CurrentLastName}", ENDITEM, 
		"Name=companyinput1", "Value=", ENDITEM, 
		"Name=billAddress1", "Value={cp_CurrentAddress}", ENDITEM, 
		"Name=billAddress2", "Value=", ENDITEM, 
		"Name=billCity", "Value={cp_CurrentCity}", ENDITEM, 
		"Name=billState", "Value={cp_CurrentState}", ENDITEM, 
		"Name=billZipcode", "Value={cp_CurrentZipCode}", ENDITEM, 
		"Name=billCountry", "Value=US", ENDITEM, 
		"Name=confirmationEmail", "Value={p_userEmail}", ENDITEM, 
		"Name=billPhoneno", "Value={cp_CurrentPhone}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=selectedShipMethod", "Value=12056", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=chkSCLimit", "Value=true", ENDITEM, 
		"Name=editPmtAddr", "Value=false", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
web_reg_find("Search=All","SaveCount=c_PHCPoller","Text=billto_zipcode",LAST);
	
	web_submit_data("PHCPollerCmd",
		"Action=https://{p_hostName}/us-en/shop/PHCPollerCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=pmtId", "Value={cp_PMTId}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=correlationId", "Value={cp_correlationId}", ENDITEM, 
		"Name=sessionId", "Value={cp_PaySessionID}", ENDITEM, 
		"Name=gcFlag", "Value=false", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=retCCInfo", "Value=false", ENDITEM,
		"Name=langId", "Value=-1", ENDITEM,
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
		
	if(atoi(lr_eval_string("{c_PHCPoller}"))>0)
	{

	lr_end_transaction("S27_Checkout_CC_Saved",LR_PASS);
	}
	else
	{
		lr_end_transaction("S27_Checkout_CC_Saved",LR_FAIL);
		Logout();
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	
	euaFlag=0;
	
	ConfirmOrder();
	
	}
	
	else if(euaFlag==1) // // Pay Credit Card for EUA user
	{
	
	lr_start_transaction("S30_Pay_CC_Review");
	
	//lr_start_sub_transaction("S30-1_HPAddressAdd","S30_Pay_CC_Review");	
	
	web_submit_data("HPAddressAdd",
		"Action=https://{p_hostName}/us-en/shop/HPAddressAdd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t70.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=shipFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=shipLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=companyinput", "Value=", ENDITEM, 
		"Name=shipAddress1", "Value={p_Address1New}", ENDITEM, 
		"Name=shipAddress2", "Value=", ENDITEM, 
		"Name=shipCity", "Value={p_CityNew}", ENDITEM, 
		"Name=shipState", "Value={p_StateNew}", ENDITEM, 
		"Name=shipZipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=shipPhoneno", "Value={p_PhoneNew}", ENDITEM, 
		"Name=billFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=billLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=companyinput1", "Value=", ENDITEM, 
		"Name=billAddress1", "Value={p_Address1New}", ENDITEM, 
		"Name=billAddress2", "Value=", ENDITEM, 
		"Name=billCity", "Value={p_CityNew}", ENDITEM, 
		"Name=billState", "Value={p_StateNew}", ENDITEM, 
		"Name=billZipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=billCountry", "Value=US", ENDITEM, 
		"Name=confirmationEmail", "Value={p_userEmail}", ENDITEM, 
		"Name=billPhoneno", "Value={p_PhoneNew}", ENDITEM, 
		"Name=orderId", "Value={cp_orderIdNew}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNoNew}", ENDITEM, 
		"Name=selectedShipMethod", "Value=12056", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=chkSCLimit", "Value=true", ENDITEM, 
		"Name=editPmtAddr", "Value=false", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	//lr_end_sub_transaction("S30-1_HPAddressAdd",LR_AUTO);

	//lr_start_sub_transaction("S30-2_CallPHC","S30_Pay_CC_Review");

	web_reg_save_param("cp_TokenPickupID","LB=TokenPickupID\":\"","RB=\",\"ContinueURL",LAST);
	lr_save_string(string_replace(lr_eval_string("{cp_EstGrandTotal}"),",",""),"cp_EstGrandTotal02");

	web_custom_request("CallPHC", 
		"URL=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/CallPHC", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Snapshot=t72.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=paymentRequestVM%5BMerchantName%5D={cp_merchantName}&paymentRequestVM%5BAgentId%5D=&paymentRequestVM%5BOrderID%5D={cp_orderNoNew}&paymentRequestVM%5BRequestTime%5D={p_RequestTime}UTC&paymentRequestVM%5BCustomerID%5D=&paymentRequestVM%5BCustomField%5D={cp_orderNoNew}-{cp_time}-10151&paymentRequestVM%5BUserHostAddress%5D={cp_clientip}&paymentRequestVM%5BUserClickTime%5D=8%2F22%2F2022+10%3A11%3A03+AM&paymentRequestVM%5BCulture%5D=en_US&paymentRequestVM%5BEstGrandTotal%5D="
		"{cp_EstGrandTotal02}&paymentRequestVM%5BEstGrandTotal_NoDecimal%5D={cp_EstGrandTotal01}&paymentRequestVM%5BEstGrandTotal_Str%5D={cp_EstGrandTotal02}&paymentRequestVM%5BTotalTaxAmount%5D={cp_TotalTaxAmount}&paymentRequestVM%5BTotalDiscountAmount%5D=&paymentRequestVM%5BIsSaveProfile%5D=true&paymentRequestVM%5BIsComingFromPGS%5D=&paymentRequestVM%5BCurrencyCode%5D=USD&paymentRequestVM%5BCurrencyCode_ISONum%5D=840&paymentRequestVM%5BDefaultPaymentType%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Name%5D={cp_Item_Name}&"
		"paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Code%5D={cp_Item_Code}&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Type%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BQuantity%5D=1&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BMerchant_Item_SKU%5D={cp_Item_Code}&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Price%5D={cp_Item_Price}&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Price_WithTax%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BTax_Amount%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BTax_Rate%5D=&"
		"paymentRequestVM%5BOfferItems%5D%5B0%5D%5BDiscount_Amount%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BDiscount_Amount_WithTax%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BUnit%5D=ea&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Total_Amount%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Total_Amount_WithTax%5D=&paymentRequestVM%5BBillAddress%5D%5BAddressName%5D={p_Address1New}&paymentRequestVM%5BBillAddress%5D%5BAddress1%5D={p_Address1New}&paymentRequestVM%5BBillAddress%5D%5BAddress2%5D=&"
		"paymentRequestVM%5BBillAddress%5D%5BAddress3%5D=&paymentRequestVM%5BBillAddress%5D%5BAddress4%5D=&paymentRequestVM%5BBillAddress%5D%5BCity%5D={p_CityNew}&paymentRequestVM%5BBillAddress%5D%5BCounty%5D=&paymentRequestVM%5BBillAddress%5D%5BState%5D={p_StateNew}&paymentRequestVM%5BBillAddress%5D%5BZip%5D={p_ZipCodeNew}&paymentRequestVM%5BBillAddress%5D%5BCountry%5D=US&paymentRequestVM%5BBillAddress%5D%5BCompanyName%5D=&paymentRequestVM%5BBillAddress%5D%5BContactFirstName%5D={p_FirstNameNew}&"
		"paymentRequestVM%5BBillAddress%5D%5BContactLastName%5D={p_LastNameNew}&paymentRequestVM%5BBillAddress%5D%5BContactDayPhone%5D=&paymentRequestVM%5BBillAddress%5D%5BContactNightPhone%5D=&paymentRequestVM%5BBillAddress%5D%5BContactEmail%5D=&paymentRequestVM%5BBillAddress%5D%5BFax%5D=&paymentRequestVM%5BCustomerInfo%5D%5BFirstName%5D={p_FirstNameNew}&paymentRequestVM%5BCustomerInfo%5D%5BLastName%5D={p_LastNameNew}&paymentRequestVM%5BCustomerInfo%5D%5BEmail%5D={p_userEmail}&"
		"paymentRequestVM%5BCustomerInfo%5D%5BPhone%5D={p_PhoneNew}&paymentRequestVM%5BCustomerInfo%5D%5BHostName%5D=&paymentRequestVM%5BCustomerInfo%5D%5BIPAddress%5D=&paymentRequestVM%5BCustomerInfo%5D%5BHpCustomerNumber%5D=&paymentRequestVM%5BCustomerInfo%5D%5BCompanyName%5D=&paymentRequestVM%5BCustomerInfo%5D%5BIsGuestUser%5D=false&paymentRequestVM%5BReturnKey_Continue%5D="
		"%3FstoreId%3D10151%26amp%3BlangId%3D-1%26amp%3BcalculationUsageId%3D-1%26amp%3BupdatePrices%3D1%26amp%3Bcchost%3Dtrue%26amp%3BorderId%3D.%26amp%3BcrID%3D{cp_correlationIdNew}%26amp%3BQuoteDisable%3DY%26amp%3BrFromPGS%3Dtrue%26amp%3Btld%3D{cp_orderNoNew}-{cp_time}-10151&paymentRequestVM%5BReturnKey_Cancel%5D="
		"%3FstoreId%3D10151%26amp%3BlangId%3D-1%26amp%3BcatalogId%3D10051%26amp%3BcalculationUsageId%3D-1%26amp%3BupdatePrices%3D1%26amp%3BorderId%3D.%26amp%3Bcancel%3Dtrue%26amp%3Bccl%3D1%26amp%3BcrID%3D{cp_correlationIdNew}%26amp%3BQuoteDisable%3DY&paymentRequestVM%5BContinueURL%5D="
		"https%3A%2F%2F{p_hostName}%2Fwebapp%2Fwcs%2Fstores%2Fservlet%2FPGSCCResponseHandlerView%3FstoreId%3D10151%26amp%3BlangId%3D-1%26amp%3BcalculationUsageId%3D-1%26amp%3BupdatePrices%3D1%26amp%3Bcchost%3Dtrue%26amp%3BorderId%3D.%26amp%3BcrID%3D{cp_correlationIdNew}%26amp%3BQuoteDisable%3DY%26amp%3BrFromPGS%3Dtrue%26amp%3Btld%3D{cp_orderNoNew}-{cp_time}-10151&paymentRequestVM%5BCancelURL%5D="
		"https%3A%2F%2F{p_hostName}%2Fwebapp%2Fwcs%2Fstores%2Fservlet%2FPGSCCResponseHandlerView%3FstoreId%3D10151%26amp%3BlangId%3D-1%26amp%3BcatalogId%3D10051%26amp%3BcalculationUsageId%3D-1%26amp%3BupdatePrices%3D1%26amp%3BorderId%3D.%26amp%3Bcancel%3Dtrue%26amp%3Bccl%3D1%26amp%3BcrID%3DH336722912_1598091057298%26amp%3BQuoteDisable%3DY&paymentRequestVM%5BJPMPP_RedirectURL%5D=https%3A%2F%2Fvphcitg.pgs.ext.hp.com%2FPGSAllPayment_V2%2FPayment%2FLanding&paymentRequestVM%5BEmailPaymentFullURL%5D=&"
		"paymentRequestVM%5BLangPack%5D%5BBTN_CANCEL%5D=Cancel&paymentRequestVM%5BLangPack%5D%5BBTN_NEXT%5D=Next&paymentRequestVM%5BLangPack%5D%5BBTN_ISCS_NEXT%5D=Continue+to+Order+Review&paymentRequestVM%5BLangPack%5D%5BCARD_TYPE%5D=Card+Type&paymentRequestVM%5BLangPack%5D%5BCC_EXP_DATE%5D=Expiry+Date&paymentRequestVM%5BLangPack%5D%5BCC_EXP_MONTH%5D=Month&paymentRequestVM%5BLangPack%5D%5BCC_EXP_YEAR%5D=Year&paymentRequestVM%5BLangPack%5D%5BCC_NUMBER%5D=Your+Card+Number&"
		"paymentRequestVM%5BLangPack%5D%5BCUST_FIRST_NAME%5D=Customer+First+Name&paymentRequestVM%5BLangPack%5D%5BCUST_LAST_NAME%5D=Customer+Last+Name&paymentRequestVM%5BLangPack%5D%5BCVV%5D=CVV+Number&paymentRequestVM%5BLangPack%5D%5BCVVToolTip%5D=Your+security+code+or+card+verification+number+is+a+3+or+4+digit+number+found+on+the+front+or+back+of+your+card.&paymentRequestVM%5BLangPack%5D%5BINVALID_CC_EXPYEAR%5D=Please+select+a+year+from+the+list&paymentRequestVM%5BLangPack%5D%5BINVALID_CC_EXPMONTH%5D="
		"Please+select+a+month+from+the+list&paymentRequestVM%5BLangPack%5D%5BINVALID_CC_EXPDATE%5D=Please+check+Expiration+Date&paymentRequestVM%5BLangPack%5D%5BINVALID_CC_NUMBER%5D=Please+enter+the+long+number+on+the+front+of+your+Credit+Card&paymentRequestVM%5BLangPack%5D%5BINVALID_CC_TYPE%5D=The+card+number+does+not+match+the+card+type&paymentRequestVM%5BLangPack%5D%5BINVALID_CUST_INFO%5D=Missing+Customer+First+Name+or+Customer+Last+Name&paymentRequestVM%5BLangPack%5D%5BINVALID_CVV_NUMBER%5D=Please+"
		"enter+your+CVV+number&paymentRequestVM%5BLangPack%5D%5BINVALID_MERCHANT%5D=You+are+not+authorized+to+access+this+page!&paymentRequestVM%5BLangPack%5D%5BORDER_NUMBER%5D=Order+Number&paymentRequestVM%5BLangPack%5D%5BPGS_TITLE%5D=HP+Payment+Security&paymentRequestVM%5BLangPack%5D%5BPLEASE_SELETE_CARDTYPE%5D=Please+select+card+type&paymentRequestVM%5BLangPack%5D%5BPROCESSING%5D=Processing...Please+wait+for+a+moment.&paymentRequestVM%5BLangPack%5D%5BREQURIED%5D=Required&"
		"paymentRequestVM%5BLangPack%5D%5BRETRY%5D=Communication+Error.+Please+retry.&paymentRequestVM%5BLangPack%5D%5BVERIFY_CARD%5D=Verify+Credit+Card&paymentRequestVM%5BLangPack%5D%5BIBAN%5D=IBAN&paymentRequestVM%5BLangPack%5D%5BINVALID_IBAN%5D=INVALID+IBAN+Format&paymentRequestVM%5BLangPack%5D%5BACCOUNT_HOLDER_NAME%5D=Account+Holder+Name&paymentRequestVM%5BLangPack%5D%5BSAVE_CARD%5D=Securely+save+these+card+details+for+faster+payment+in+the+future&paymentRequestVM%5BLangPack%5D%5BTRY_ANOTHER_CARD%5D="
		"You+can+add+another+Credit+Card&paymentRequestVM%5BLangPack%5D%5BTRY_ANOTHER_CARD_INK%5D=Please+review+and+update+your+billing+information&paymentRequestVM%5BGPay%5D=&paymentRequestVM%5BCC%5D%5BIsVK%5D=false&paymentRequestVM%5BCC%5D%5BIsVoicePay%5D=false&paymentRequestVM%5BCC%5D%5BVoicePayUrl%5D=&paymentRequestVM%5BCC%5D%5BIs3DSecure%5D=false&paymentRequestVM%5BCC%5D%5BIsJPMPP3DSecure%5D=false&paymentRequestVM%5BCC%5D%5BJWT%5D="
		"{cp_PaymentRequest}&paymentRequestVM%5BCC%5D%5BAllowedCardTypes%5D%5B%5D=001&paymentRequestVM%5BCC%5D%5BAllowedCardTypes%5D%5B%5D=002&paymentRequestVM%5BCC%5D%5BAllowedCardTypes%5D%5B%5D=003&"
		"paymentRequestVM%5BCC%5D%5BAllowedCardTypes%5D%5B%5D=004&paymentRequestVM%5BCC%5D%5BIsEmailPayment%5D=false&paymentRequestVM%5BCC%5D%5BIsCVVRequired%5D=true&paymentRequestVM%5BCC%5D%5BIsAXBypass3DSecure%5D=false&paymentRequestVM%5BCC%5D%5BIsMCBypass3DSecure%5D=false&paymentRequestVM%5BCC%5D%5BIsVIBypass3DSecure%5D=false&paymentRequestVM%5BCC%5D%5BIsServiceRequired%5D=true&paymentRequestVM%5BCC%5D%5BIsDisplaySaveProfileFlag%5D=true&paymentRequestVM%5BCC%5D%5BIsUpdatingUserProfile%5D=false&"
		"paymentRequestVM%5BDirectDebit%5D=&paymentRequestVM%5BKlarna%5D=&paymentRequestVM%5BPayPal%5D=&paymentMethodVM%5BCCNumber%5D=4112344112344113&paymentMethodVM%5BExpYear%5D=2022&paymentMethodVM%5BExpMonth%5D=12&paymentMethodVM%5BCVV%5D=123&paymentMethodVM%5BCardType%5D=001&paymentMethodVM%5BIsSaveProfile%5D=false&paymentMethodVM%5BCardNickName%5D=", 
		LAST);
	
//lr_end_sub_transaction("S30-2_CallPHC",LR_AUTO);

//lr_start_sub_transaction("S30-3_PGSCCResponseHandlerView","S30_Pay_CC_Review");

	web_submit_data("PGSCCResponseHandlerView", 
		"Action=https://{p_hostName}/webapp/wcs/stores/servlet/PGSCCResponseHandlerView?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_correlationIdNew}&amp;QuoteDisable=Y&amp;rFromPGS=true&amp;tld={cp_orderNoNew}-{cp_time}-10151", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Snapshot=t73.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=mPickupID", "Value={cp_TokenPickupID}", ENDITEM, 
		LAST);
		
//lr_end_sub_transaction("S30-3_PGSCCResponseHandlerView",LR_AUTO);

//lr_start_sub_transaction("S30-4_PHCPollerCmd","S30_Pay_CC_Review");
	
	web_reg_find("Search=All","SaveCount=c_PHCPoller","Text=billto_zipcode",LAST);

	
	web_submit_data("PHCPollerCmd", 
		"Action=https://{p_hostName}/us-en/shop/PHCPollerCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t74.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=tlDataKey", "Value={cp_orderNoNew}-{cp_time}-10151", ENDITEM, 
		"Name=orderId", "Value={cp_orderIdNew}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNoNew}", ENDITEM, 
		"Name=correlationId", "Value={cp_correlationIdNew}", ENDITEM, 
		//"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=sessionId", "Value={cp_PaySessionID}", ENDITEM,
		"Name=gcFlag", "Value=false", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=retCCInfo", "Value=false", ENDITEM,
		"Name=langId", "Value=-1", ENDITEM,
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	//lr_end_sub_transaction("S30-4_PHCPollerCmd",LR_AUTO);
	
	if(atoi(lr_eval_string("{c_PHCPoller}"))>0)
	{

	lr_end_transaction("S30_Pay_CC_Review",LR_PASS);
	}
	else
	{
		lr_end_transaction("S30_Pay_CC_Review",LR_FAIL);
		Logout();
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
ConfirmOrder();
	
	}
	
	else if(loyaltyflag ==1) // Pay Credit Card for Loyalty user
	{
		lr_start_transaction("S30_Pay_CC_Review");

//lr_start_sub_transaction("S30-1_HPAddressAdd","S30_Pay_CC_Review");		

web_submit_data("HPAddressAdd", 
		"Action=https://{p_hostName}/us-en/shop/HPAddressAdd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=shipFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=shipLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=companyinput", "Value=", ENDITEM, 
		"Name=shipAddress1", "Value={p_Address1New}", ENDITEM, 
		"Name=shipAddress2", "Value=", ENDITEM, 
		"Name=shipCity", "Value={p_CityNew}", ENDITEM, 
		"Name=shipState", "Value={p_StateNew}", ENDITEM, 
		"Name=shipZipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=shipPhoneno", "Value={p_PhoneNew}", ENDITEM, 
		"Name=billFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=billLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=companyinput1", "Value=", ENDITEM, 
		"Name=billAddress1", "Value={p_Address1New}", ENDITEM, 
		"Name=billAddress2", "Value=", ENDITEM, 
		"Name=billCity", "Value={p_CityNew}", ENDITEM, 
		"Name=billState", "Value={p_StateNew}", ENDITEM, 
		"Name=billZipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=billCountry", "Value=US", ENDITEM, 
		"Name=confirmationEmail", "Value={p_userEmail}", ENDITEM, 
		"Name=billPhoneno", "Value={p_PhoneNew}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=selectedShipMethod", "Value=12056", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=chkSCLimit", "Value=true", ENDITEM, 
		"Name=editPmtAddr", "Value=false", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
		
	//lr_end_sub_transaction("S30-1_HPAddressAdd",LR_AUTO);

//lr_start_sub_transaction("S30-2_CallPHC","S30_Pay_CC_Review");

	web_reg_save_param("cp_TokenPickupID","LB=TokenPickupID\":\"","RB=\",\"ContinueURL",LAST);
lr_save_string(string_replace(lr_eval_string("{cp_EstGrandTotal}"),",",""),"cp_EstGrandTotal02");	
	
	web_custom_request("CallPHC",
		"URL=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/CallPHC", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=paymentRequestVM%5BMerchantName%5D={cp_merchantName}&paymentRequestVM%5BAgentId%5D=&paymentRequestVM%5BOrderID%5D={cp_orderNo}&paymentRequestVM%5BRequestTime%5D={p_RequestTime}UTC&paymentRequestVM%5BCustomerID%5D=&paymentRequestVM%5BCustomField%5D={cp_orderNo}-{cp_time}-10151&paymentRequestVM%5BUserHostAddress%5D={cp_clientip}&paymentRequestVM%5BUserClickTime%5D=7%2F28%2F2022+8%3A12%3A47+AM&paymentRequestVM%5BCulture%5D=en_US&paymentRequestVM%5BEstGrandTotal%5D={cp_EstGrandTotal02}&"
		"paymentRequestVM%5BEstGrandTotal_NoDecimal%5D={cp_EstGrandTotal01}&paymentRequestVM%5BEstGrandTotal_Str%5D={cp_EstGrandTotal02}&paymentRequestVM%5BTotalTaxAmount%5D=0&paymentRequestVM%5BTotalDiscountAmount%5D=&paymentRequestVM%5BIsSaveProfile%5D=true&paymentRequestVM%5BCurrencyCode%5D=USD&paymentRequestVM%5BCurrencyCode_ISONum%5D=840&paymentRequestVM%5BDefaultPaymentType%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Name%5D={cp_Item_Name}&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Code%5D={cp_Item_Code}&"
		"paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Type%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BQuantity%5D=1&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BMerchant_Item_SKU%5D={cp_Item_Code}&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Price%5D={cp_Item_Price}&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Price_WithTax%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BTax_Amount%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BTax_Rate%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BDiscount_Amount%5D=&"
		"paymentRequestVM%5BOfferItems%5D%5B0%5D%5BDiscount_Amount_WithTax%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BUnit%5D=ea&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Total_Amount%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Total_Amount_WithTax%5D=&paymentRequestVM%5BBillAddress%5D%5BAddressName%5D={p_Address1New}&paymentRequestVM%5BBillAddress%5D%5BAddress1%5D={p_Address1New}&paymentRequestVM%5BBillAddress%5D%5BAddress2%5D=&paymentRequestVM%5BBillAddress%5D%5BAddress3%5D=&"
		"paymentRequestVM%5BBillAddress%5D%5BAddress4%5D=&paymentRequestVM%5BBillAddress%5D%5BCity%5D={p_CityNew}&paymentRequestVM%5BBillAddress%5D%5BCounty%5D=&paymentRequestVM%5BBillAddress%5D%5BState%5D={p_StateNew}&paymentRequestVM%5BBillAddress%5D%5BZip%5D={p_ZipCodeNew}&paymentRequestVM%5BBillAddress%5D%5BCountry%5D=US&paymentRequestVM%5BBillAddress%5D%5BCompanyName%5D=&paymentRequestVM%5BBillAddress%5D%5BContactFirstName%5D={p_FirstNameNew}&paymentRequestVM%5BBillAddress%5D%5BContactLastName%5D={p_LastNameNew}&"
		"paymentRequestVM%5BBillAddress%5D%5BContactDayPhone%5D=&paymentRequestVM%5BBillAddress%5D%5BContactNightPhone%5D=&paymentRequestVM%5BBillAddress%5D%5BContactEmail%5D=&paymentRequestVM%5BBillAddress%5D%5BFax%5D=&paymentRequestVM%5BCustomerInfo%5D%5BFirstName%5D={p_FirstNameNew}&paymentRequestVM%5BCustomerInfo%5D%5BLastName%5D={p_LastNameNew}&paymentRequestVM%5BCustomerInfo%5D%5BEmail%5D={p_userEmail}&paymentRequestVM%5BCustomerInfo%5D%5BPhone%5D={p_PhoneNew}&paymentRequestVM%5BCustomerInfo%5D%5BHostName%5D=&"
		"paymentRequestVM%5BCustomerInfo%5D%5BIPAddress%5D=&paymentRequestVM%5BCustomerInfo%5D%5BHpCustomerNumber%5D=&paymentRequestVM%5BCustomerInfo%5D%5BCompanyName%5D=&paymentRequestVM%5BCustomerInfo%5D%5BIsGuestUser%5D=true&paymentRequestVM%5BReturnKey_Continue%5D="
		"%3FstoreId%3D10151%26amp%3BlangId%3D-1%26amp%3BcalculationUsageId%3D-1%26amp%3BupdatePrices%3D1%26amp%3Bcchost%3Dtrue%26amp%3BorderId%3D.%26amp%3BcrID%3D{cp_correlationId}%26amp%3BQuoteDisable%3DN%26amp%3BrFromPGS%3Dtrue%26amp%3Btld%3D{cp_orderNo}-{cp_time}-10151&paymentRequestVM%5BReturnKey_Cancel%5D="
		"%3FstoreId%3D10151%26amp%3BlangId%3D-1%26amp%3BcatalogId%3D10051%26amp%3BcalculationUsageId%3D-1%26amp%3BupdatePrices%3D1%26amp%3BorderId%3D.%26amp%3Bcancel%3Dtrue%26amp%3Bccl%3D1%26amp%3BcrID%3D{cp_correlationId}%26amp%3BQuoteDisable%3DN&paymentRequestVM%5BContinueURL%5D="
		"https%3A%2F%2F{p_hostName}%2Fwebapp%2Fwcs%2Fstores%2Fservlet%2FPGSCCResponseHandlerView%3FstoreId%3D10151%26amp%3BlangId%3D-1%26amp%3BcalculationUsageId%3D-1%26amp%3BupdatePrices%3D1%26amp%3Bcchost%3Dtrue%26amp%3BorderId%3D.%26amp%3BcrID%3D{cp_correlationId}%26amp%3BQuoteDisable%3DN%26amp%3BrFromPGS%3Dtrue%26amp%3Btld%3D{cp_orderNo}-{cp_time}-10151&paymentRequestVM%5BCancelURL%5D="
		"https%3A%2F%2F{p_hostName}%2Fwebapp%2Fwcs%2Fstores%2Fservlet%2FPGSCCResponseHandlerView%3FstoreId%3D10151%26amp%3BlangId%3D-1%26amp%3BcatalogId%3D10051%26amp%3BcalculationUsageId%3D-1%26amp%3BupdatePrices%3D1%26amp%3BorderId%3D.%26amp%3Bcancel%3Dtrue%26amp%3Bccl%3D1%26amp%3BcrID%3D{cp_correlationId}%26amp%3BQuoteDisable%3DN&paymentRequestVM%5BJPMPP_RedirectURL%5D=https%3A%2F%2Fvphcitg.pgs.ext.hp.com%2FPGSAllPayment_V2%2FPayment%2FLanding&paymentRequestVM%5BEmailPaymentFullURL%5D=&"
		"paymentRequestVM%5BLangPack%5D%5BBTN_CANCEL%5D=Cancel&paymentRequestVM%5BLangPack%5D%5BBTN_NEXT%5D=Next&paymentRequestVM%5BLangPack%5D%5BBTN_ISCS_NEXT%5D=Continue+to+Order+Review&paymentRequestVM%5BLangPack%5D%5BCARD_TYPE%5D=Card+Type&paymentRequestVM%5BLangPack%5D%5BCC_EXP_DATE%5D=Expiry+Date&paymentRequestVM%5BLangPack%5D%5BCC_EXP_MONTH%5D=Month&paymentRequestVM%5BLangPack%5D%5BCC_EXP_YEAR%5D=Year&paymentRequestVM%5BLangPack%5D%5BCC_NUMBER%5D=Your+Card+Number&"
		"paymentRequestVM%5BLangPack%5D%5BCUST_FIRST_NAME%5D=Customer+First+Name&paymentRequestVM%5BLangPack%5D%5BCUST_LAST_NAME%5D=Customer+Last+Name&paymentRequestVM%5BLangPack%5D%5BCVV%5D=CVV+Number&paymentRequestVM%5BLangPack%5D%5BCVVToolTip%5D=Your+security+code+or+card+verification+number+is+a+3+or+4+digit+number+found+on+the+front+or+back+of+your+card.&paymentRequestVM%5BLangPack%5D%5BINVALID_CC_EXPYEAR%5D=Please+select+a+year+from+the+list&paymentRequestVM%5BLangPack%5D%5BINVALID_CC_EXPMONTH%5D="
		"Please+select+a+month+from+the+list&paymentRequestVM%5BLangPack%5D%5BINVALID_CC_EXPDATE%5D=Please+check+Expiration+Date&paymentRequestVM%5BLangPack%5D%5BINVALID_CC_NUMBER%5D=Please+enter+the+long+number+on+the+front+of+your+Credit+Card&paymentRequestVM%5BLangPack%5D%5BINVALID_CC_TYPE%5D=The+card+number+does+not+match+the+card+type&paymentRequestVM%5BLangPack%5D%5BINVALID_CUST_INFO%5D=Missing+Customer+First+Name+or+Customer+Last+Name&paymentRequestVM%5BLangPack%5D%5BINVALID_CVV_NUMBER%5D=Please+"
		"enter+your+CVV+number&paymentRequestVM%5BLangPack%5D%5BINVALID_MERCHANT%5D=You+are+not+authorized+to+access+this+page!&paymentRequestVM%5BLangPack%5D%5BORDER_NUMBER%5D=Order+Number&paymentRequestVM%5BLangPack%5D%5BPGS_TITLE%5D=HP+Payment+Security&paymentRequestVM%5BLangPack%5D%5BPLEASE_SELETE_CARDTYPE%5D=Please+select+card+type&paymentRequestVM%5BLangPack%5D%5BPROCESSING%5D=Processing...Please+wait+for+a+moment.&paymentRequestVM%5BLangPack%5D%5BREQURIED%5D=Required&"
		"paymentRequestVM%5BLangPack%5D%5BRETRY%5D=Communication+Error.+Please+retry.&paymentRequestVM%5BLangPack%5D%5BVERIFY_CARD%5D=Verify+Credit+Card&paymentRequestVM%5BLangPack%5D%5BIBAN%5D=IBAN&paymentRequestVM%5BLangPack%5D%5BINVALID_IBAN%5D=INVALID+IBAN+Format&paymentRequestVM%5BLangPack%5D%5BACCOUNT_HOLDER_NAME%5D=Account+Holder+Name&paymentRequestVM%5BLangPack%5D%5BSAVE_CARD%5D=Securely+save+these+card+details+for+faster+payment+in+the+future&paymentRequestVM%5BLangPack%5D%5BTRY_ANOTHER_CARD%5D="
		"You+can+add+another+Credit+Card&paymentRequestVM%5BLangPack%5D%5BTRY_ANOTHER_CARD_INK%5D=Please+review+and+update+your+billing+information&paymentRequestVM%5BGPay%5D=&paymentRequestVM%5BCC%5D%5BIsVK%5D=false&paymentRequestVM%5BCC%5D%5BIsVoicePay%5D=false&paymentRequestVM%5BCC%5D%5BVoicePayUrl%5D=&paymentRequestVM%5BCC%5D%5BIs3DSecure%5D=false&paymentRequestVM%5BCC%5D%5BIsJPMPP3DSecure%5D=false&paymentRequestVM%5BCC%5D%5BJWT%5D="
		"{cp_PaymentRequest}8&paymentRequestVM%5BCC%5D%5BAllowedCardTypes%5D%5B%5D=001&paymentRequestVM%5BCC%5D%5BAllowedCardTypes%5D%5B%5D=002&paymentRequestVM%5BCC%5D%5BAllowedCardTypes%5D%5B%5D=003&"
		"paymentRequestVM%5BCC%5D%5BAllowedCardTypes%5D%5B%5D=004&paymentRequestVM%5BCC%5D%5BIsEmailPayment%5D=false&paymentRequestVM%5BCC%5D%5BIsCVVRequired%5D=true&paymentRequestVM%5BCC%5D%5BIsAXBypass3DSecure%5D=false&paymentRequestVM%5BCC%5D%5BIsMCBypass3DSecure%5D=false&paymentRequestVM%5BCC%5D%5BIsVIBypass3DSecure%5D=false&paymentRequestVM%5BCC%5D%5BIsServiceRequired%5D=true&paymentRequestVM%5BCC%5D%5BIsDisplaySaveProfileFlag%5D=true&paymentRequestVM%5BCC%5D%5BIsUpdatingUserProfile%5D=false&"
		"paymentRequestVM%5BDirectDebit%5D=&paymentRequestVM%5BKlarna%5D=&paymentRequestVM%5BPayPal%5D=&paymentMethodVM%5BCCNumber%5D=4112344112344113&paymentMethodVM%5BExpYear%5D=2022&paymentMethodVM%5BExpMonth%5D=12&paymentMethodVM%5BCVV%5D=123&paymentMethodVM%5BCardType%5D=001&paymentMethodVM%5BIsSaveProfile%5D=false&paymentMethodVM%5BCardNickName%5D=", 
		LAST);
	
	//lr_end_sub_transaction("S30-2_CallPHC",LR_AUTO);

//lr_start_sub_transaction("S30-3_PGSCCResponseHandlerView","S30_Pay_CC_Review");

	web_submit_data("PGSCCResponseHandlerView",
		"Action=https://{p_hostName}/webapp/wcs/stores/servlet/PGSCCResponseHandlerView?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_correlationId}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld={cp_orderNo}-{cp_time}-10151", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=mPickupID", "Value={cp_TokenPickupID}", ENDITEM, 
		LAST);
	
	//lr_end_sub_transaction("S30-3_PGSCCResponseHandlerView",LR_AUTO);

//lr_start_sub_transaction("S30-4_PHCPollerCmd","S30_Pay_CC_Review");

	web_reg_find("Search=All","SaveCount=c_PHCPoller","Text=billto_zipcode",LAST);

	
	web_submit_data("PHCPollerCmd", 
		"Action=https://{p_hostName}/us-en/shop/PHCPollerCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=tlDataKey", "Value={cp_orderNo}-{cp_time}-10151", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=correlationId", "Value={cp_correlationId}", ENDITEM, 
		"Name=sessionId", "Value={cp_PaySessionID}", ENDITEM, 
		"Name=gcFlag", "Value=false", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM,
		"Name=retCCInfo", "Value=false", ENDITEM,		
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
//lr_end_sub_transaction("S30-4_PHCPollerCmd",LR_AUTO);

	if(atoi(lr_eval_string("{c_PHCPoller}"))>0)
	{

	lr_end_transaction("S30_Pay_CC_Review",LR_PASS);
	}
	else
	{
		lr_end_transaction("S30_Pay_CC_Review",LR_FAIL);
		Logout();
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	
	ConfirmOrder();
	
	}
	else // Pay Credit Card for GS,Gold,Silver,Platinum user
	{
		
	
	
	lr_start_transaction("S30_Pay_CC_Review");	

	//lr_start_sub_transaction("S30-1_HPAddressAdd","S30_Pay_CC_Review");
	
web_submit_data("HPAddressAdd", 
		"Action=https://{p_hostName}/us-en/shop/HPAddressAdd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=shipFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=shipLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=companyinput", "Value=", ENDITEM, 
		"Name=shipAddress1", "Value={p_Address1New}", ENDITEM, 
		"Name=shipAddress2", "Value=", ENDITEM, 
		"Name=shipCity", "Value={p_CityNew}", ENDITEM, 
		"Name=shipState", "Value={p_StateNew}", ENDITEM, 
		"Name=shipZipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=shipPhoneno", "Value={p_PhoneNew}", ENDITEM, 
		"Name=billFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=billLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=companyinput1", "Value=", ENDITEM, 
		"Name=billAddress1", "Value={p_Address1New}", ENDITEM, 
		"Name=billAddress2", "Value=", ENDITEM, 
		"Name=billCity", "Value={p_CityNew}", ENDITEM, 
		"Name=billState", "Value={p_StateNew}", ENDITEM, 
		"Name=billZipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=billCountry", "Value=US", ENDITEM, 
		"Name=confirmationEmail", "Value={p_userEmail}", ENDITEM, 
		"Name=billPhoneno", "Value={p_PhoneNew}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=selectedShipMethod", "Value=12056", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=chkSCLimit", "Value=true", ENDITEM, 
		"Name=editPmtAddr", "Value=false", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
		
	//lr_end_sub_transaction("S30-1_HPAddressAdd",LR_AUTO);

//lr_start_sub_transaction("S30-2_CallPHC","S30_Pay_CC_Review");

	web_reg_save_param("cp_TokenPickupID","LB=TokenPickupID\":\"","RB=\",\"ContinueURL",LAST);	
	lr_save_string(string_replace(lr_eval_string("{cp_EstGrandTotal}"),",",""),"cp_EstGrandTotal02");
	
	web_custom_request("CallPHC",
		"URL=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/CallPHC", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=paymentRequestVM%5BMerchantName%5D={cp_merchantName}&paymentRequestVM%5BAgentId%5D=&paymentRequestVM%5BOrderID%5D={cp_orderNo}&paymentRequestVM%5BRequestTime%5D={p_RequestTime}UTC&paymentRequestVM%5BCustomerID%5D=&paymentRequestVM%5BCustomField%5D={cp_orderNo}-{cp_time}-10151&paymentRequestVM%5BUserHostAddress%5D={cp_clientip}&paymentRequestVM%5BUserClickTime%5D=7%2F28%2F2022+8%3A12%3A47+AM&paymentRequestVM%5BCulture%5D=en_US&paymentRequestVM%5BEstGrandTotal%5D={cp_EstGrandTotal02}&"
		"paymentRequestVM%5BEstGrandTotal_NoDecimal%5D={cp_EstGrandTotal01}&paymentRequestVM%5BEstGrandTotal_Str%5D={cp_EstGrandTotal02}&paymentRequestVM%5BTotalTaxAmount%5D=0&paymentRequestVM%5BTotalDiscountAmount%5D=&paymentRequestVM%5BIsSaveProfile%5D=true&paymentRequestVM%5BCurrencyCode%5D=USD&paymentRequestVM%5BCurrencyCode_ISONum%5D=840&paymentRequestVM%5BDefaultPaymentType%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Name%5D={cp_Item_Name}&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Code%5D={cp_Item_Code}&"
		"paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Type%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BQuantity%5D=1&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BMerchant_Item_SKU%5D={cp_Item_Code}&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Price%5D={cp_Item_Price}&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Price_WithTax%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BTax_Amount%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BTax_Rate%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BDiscount_Amount%5D=&"
		"paymentRequestVM%5BOfferItems%5D%5B0%5D%5BDiscount_Amount_WithTax%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BUnit%5D=ea&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Total_Amount%5D=&paymentRequestVM%5BOfferItems%5D%5B0%5D%5BItem_Total_Amount_WithTax%5D=&paymentRequestVM%5BBillAddress%5D%5BAddressName%5D={p_Address1New}&paymentRequestVM%5BBillAddress%5D%5BAddress1%5D={p_Address1New}&paymentRequestVM%5BBillAddress%5D%5BAddress2%5D=&paymentRequestVM%5BBillAddress%5D%5BAddress3%5D=&"
		"paymentRequestVM%5BBillAddress%5D%5BAddress4%5D=&paymentRequestVM%5BBillAddress%5D%5BCity%5D={p_CityNew}&paymentRequestVM%5BBillAddress%5D%5BCounty%5D=&paymentRequestVM%5BBillAddress%5D%5BState%5D={p_StateNew}&paymentRequestVM%5BBillAddress%5D%5BZip%5D={p_ZipCodeNew}&paymentRequestVM%5BBillAddress%5D%5BCountry%5D=US&paymentRequestVM%5BBillAddress%5D%5BCompanyName%5D=&paymentRequestVM%5BBillAddress%5D%5BContactFirstName%5D={p_FirstNameNew}&paymentRequestVM%5BBillAddress%5D%5BContactLastName%5D={p_LastNameNew}&"
		"paymentRequestVM%5BBillAddress%5D%5BContactDayPhone%5D=&paymentRequestVM%5BBillAddress%5D%5BContactNightPhone%5D=&paymentRequestVM%5BBillAddress%5D%5BContactEmail%5D=&paymentRequestVM%5BBillAddress%5D%5BFax%5D=&paymentRequestVM%5BCustomerInfo%5D%5BFirstName%5D={p_FirstNameNew}&paymentRequestVM%5BCustomerInfo%5D%5BLastName%5D={p_LastNameNew}&paymentRequestVM%5BCustomerInfo%5D%5BEmail%5D={p_userEmail}&paymentRequestVM%5BCustomerInfo%5D%5BPhone%5D={p_PhoneNew}&paymentRequestVM%5BCustomerInfo%5D%5BHostName%5D=&"
		"paymentRequestVM%5BCustomerInfo%5D%5BIPAddress%5D=&paymentRequestVM%5BCustomerInfo%5D%5BHpCustomerNumber%5D=&paymentRequestVM%5BCustomerInfo%5D%5BCompanyName%5D=&paymentRequestVM%5BCustomerInfo%5D%5BIsGuestUser%5D=true&paymentRequestVM%5BReturnKey_Continue%5D="
		"%3FstoreId%3D10151%26amp%3BlangId%3D-1%26amp%3BcalculationUsageId%3D-1%26amp%3BupdatePrices%3D1%26amp%3Bcchost%3Dtrue%26amp%3BorderId%3D.%26amp%3BcrID%3D{cp_correlationId}%26amp%3BQuoteDisable%3DN%26amp%3BrFromPGS%3Dtrue%26amp%3Btld%3D{cp_orderNo}-{cp_time}-10151&paymentRequestVM%5BReturnKey_Cancel%5D="
		"%3FstoreId%3D10151%26amp%3BlangId%3D-1%26amp%3BcatalogId%3D10051%26amp%3BcalculationUsageId%3D-1%26amp%3BupdatePrices%3D1%26amp%3BorderId%3D.%26amp%3Bcancel%3Dtrue%26amp%3Bccl%3D1%26amp%3BcrID%3D{cp_correlationId}%26amp%3BQuoteDisable%3DN&paymentRequestVM%5BContinueURL%5D="
		"https%3A%2F%2F{p_hostName}%2Fwebapp%2Fwcs%2Fstores%2Fservlet%2FPGSCCResponseHandlerView%3FstoreId%3D10151%26amp%3BlangId%3D-1%26amp%3BcalculationUsageId%3D-1%26amp%3BupdatePrices%3D1%26amp%3Bcchost%3Dtrue%26amp%3BorderId%3D.%26amp%3BcrID%3D{cp_correlationId}%26amp%3BQuoteDisable%3DN%26amp%3BrFromPGS%3Dtrue%26amp%3Btld%3D{cp_orderNo}-{cp_time}-10151&paymentRequestVM%5BCancelURL%5D="
		"https%3A%2F%2F{p_hostName}%2Fwebapp%2Fwcs%2Fstores%2Fservlet%2FPGSCCResponseHandlerView%3FstoreId%3D10151%26amp%3BlangId%3D-1%26amp%3BcatalogId%3D10051%26amp%3BcalculationUsageId%3D-1%26amp%3BupdatePrices%3D1%26amp%3BorderId%3D.%26amp%3Bcancel%3Dtrue%26amp%3Bccl%3D1%26amp%3BcrID%3D{cp_correlationId}%26amp%3BQuoteDisable%3DN&paymentRequestVM%5BJPMPP_RedirectURL%5D=https%3A%2F%2Fvphcitg.pgs.ext.hp.com%2FPGSAllPayment_V2%2FPayment%2FLanding&paymentRequestVM%5BEmailPaymentFullURL%5D=&"
		"paymentRequestVM%5BLangPack%5D%5BBTN_CANCEL%5D=Cancel&paymentRequestVM%5BLangPack%5D%5BBTN_NEXT%5D=Next&paymentRequestVM%5BLangPack%5D%5BBTN_ISCS_NEXT%5D=Continue+to+Order+Review&paymentRequestVM%5BLangPack%5D%5BCARD_TYPE%5D=Card+Type&paymentRequestVM%5BLangPack%5D%5BCC_EXP_DATE%5D=Expiry+Date&paymentRequestVM%5BLangPack%5D%5BCC_EXP_MONTH%5D=Month&paymentRequestVM%5BLangPack%5D%5BCC_EXP_YEAR%5D=Year&paymentRequestVM%5BLangPack%5D%5BCC_NUMBER%5D=Your+Card+Number&"
		"paymentRequestVM%5BLangPack%5D%5BCUST_FIRST_NAME%5D=Customer+First+Name&paymentRequestVM%5BLangPack%5D%5BCUST_LAST_NAME%5D=Customer+Last+Name&paymentRequestVM%5BLangPack%5D%5BCVV%5D=CVV+Number&paymentRequestVM%5BLangPack%5D%5BCVVToolTip%5D=Your+security+code+or+card+verification+number+is+a+3+or+4+digit+number+found+on+the+front+or+back+of+your+card.&paymentRequestVM%5BLangPack%5D%5BINVALID_CC_EXPYEAR%5D=Please+select+a+year+from+the+list&paymentRequestVM%5BLangPack%5D%5BINVALID_CC_EXPMONTH%5D="
		"Please+select+a+month+from+the+list&paymentRequestVM%5BLangPack%5D%5BINVALID_CC_EXPDATE%5D=Please+check+Expiration+Date&paymentRequestVM%5BLangPack%5D%5BINVALID_CC_NUMBER%5D=Please+enter+the+long+number+on+the+front+of+your+Credit+Card&paymentRequestVM%5BLangPack%5D%5BINVALID_CC_TYPE%5D=The+card+number+does+not+match+the+card+type&paymentRequestVM%5BLangPack%5D%5BINVALID_CUST_INFO%5D=Missing+Customer+First+Name+or+Customer+Last+Name&paymentRequestVM%5BLangPack%5D%5BINVALID_CVV_NUMBER%5D=Please+"
		"enter+your+CVV+number&paymentRequestVM%5BLangPack%5D%5BINVALID_MERCHANT%5D=You+are+not+authorized+to+access+this+page!&paymentRequestVM%5BLangPack%5D%5BORDER_NUMBER%5D=Order+Number&paymentRequestVM%5BLangPack%5D%5BPGS_TITLE%5D=HP+Payment+Security&paymentRequestVM%5BLangPack%5D%5BPLEASE_SELETE_CARDTYPE%5D=Please+select+card+type&paymentRequestVM%5BLangPack%5D%5BPROCESSING%5D=Processing...Please+wait+for+a+moment.&paymentRequestVM%5BLangPack%5D%5BREQURIED%5D=Required&"
		"paymentRequestVM%5BLangPack%5D%5BRETRY%5D=Communication+Error.+Please+retry.&paymentRequestVM%5BLangPack%5D%5BVERIFY_CARD%5D=Verify+Credit+Card&paymentRequestVM%5BLangPack%5D%5BIBAN%5D=IBAN&paymentRequestVM%5BLangPack%5D%5BINVALID_IBAN%5D=INVALID+IBAN+Format&paymentRequestVM%5BLangPack%5D%5BACCOUNT_HOLDER_NAME%5D=Account+Holder+Name&paymentRequestVM%5BLangPack%5D%5BSAVE_CARD%5D=Securely+save+these+card+details+for+faster+payment+in+the+future&paymentRequestVM%5BLangPack%5D%5BTRY_ANOTHER_CARD%5D="
		"You+can+add+another+Credit+Card&paymentRequestVM%5BLangPack%5D%5BTRY_ANOTHER_CARD_INK%5D=Please+review+and+update+your+billing+information&paymentRequestVM%5BGPay%5D=&paymentRequestVM%5BCC%5D%5BIsVK%5D=false&paymentRequestVM%5BCC%5D%5BIsVoicePay%5D=false&paymentRequestVM%5BCC%5D%5BVoicePayUrl%5D=&paymentRequestVM%5BCC%5D%5BIs3DSecure%5D=false&paymentRequestVM%5BCC%5D%5BIsJPMPP3DSecure%5D=false&paymentRequestVM%5BCC%5D%5BJWT%5D="
		"{cp_PaymentRequest}8&paymentRequestVM%5BCC%5D%5BAllowedCardTypes%5D%5B%5D=001&paymentRequestVM%5BCC%5D%5BAllowedCardTypes%5D%5B%5D=002&paymentRequestVM%5BCC%5D%5BAllowedCardTypes%5D%5B%5D=003&"
		"paymentRequestVM%5BCC%5D%5BAllowedCardTypes%5D%5B%5D=004&paymentRequestVM%5BCC%5D%5BIsEmailPayment%5D=false&paymentRequestVM%5BCC%5D%5BIsCVVRequired%5D=true&paymentRequestVM%5BCC%5D%5BIsAXBypass3DSecure%5D=false&paymentRequestVM%5BCC%5D%5BIsMCBypass3DSecure%5D=false&paymentRequestVM%5BCC%5D%5BIsVIBypass3DSecure%5D=false&paymentRequestVM%5BCC%5D%5BIsServiceRequired%5D=true&paymentRequestVM%5BCC%5D%5BIsDisplaySaveProfileFlag%5D=true&paymentRequestVM%5BCC%5D%5BIsUpdatingUserProfile%5D=false&"
		"paymentRequestVM%5BDirectDebit%5D=&paymentRequestVM%5BKlarna%5D=&paymentRequestVM%5BPayPal%5D=&paymentMethodVM%5BCCNumber%5D=4112344112344113&paymentMethodVM%5BExpYear%5D=2022&paymentMethodVM%5BExpMonth%5D=12&paymentMethodVM%5BCVV%5D=123&paymentMethodVM%5BCardType%5D=001&paymentMethodVM%5BIsSaveProfile%5D=false&paymentMethodVM%5BCardNickName%5D=", 
		LAST);
	//lr_end_sub_transaction("S30-2_CallPHC",LR_AUTO);

//lr_start_sub_transaction("S30-3_PGSCCResponseHandlerView","S30_Pay_CC_Review");

	web_submit_data("PGSCCResponseHandlerView",
		"Action=https://{p_hostName}/webapp/wcs/stores/servlet/PGSCCResponseHandlerView?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_correlationId}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld={cp_orderNo}-{cp_time}-10151", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=mPickupID", "Value={cp_TokenPickupID}", ENDITEM, 
		LAST);
	
	//lr_end_sub_transaction("S30-3_PGSCCResponseHandlerView",LR_AUTO);

//lr_start_sub_transaction("S30-4_PHCPollerCmd","S30_Pay_CC_Review");

	web_reg_find("Search=All","SaveCount=c_PHCPoller","Text=billto_zipcode",LAST);

	web_submit_data("PHCPollerCmd", 
		"Action=https://{p_hostName}/us-en/shop/PHCPollerCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=tlDataKey", "Value={cp_orderNo}-{cp_time}-10151", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=correlationId", "Value={cp_correlationId}", ENDITEM, 
		"Name=sessionId", "Value={cp_PaySessionID}", ENDITEM, 
		"Name=gcFlag", "Value=false", ENDITEM, 
		"Name=retCCInfo", "Value=false", ENDITEM,
		"Name=storeId", "Value=10151", ENDITEM,
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
//lr_end_sub_transaction("S30-4_PHCPollerCmd",LR_AUTO);


	if(atoi(lr_eval_string("{c_PHCPoller}"))>0)
	{

	lr_end_transaction("S30_Pay_CC_Review",LR_PASS);
	}
	else
	{
		lr_end_transaction("S30_Pay_CC_Review",LR_FAIL);
		Logout();
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	
euaFlag=0;

ConfirmOrder();

	}
	
}

else
	
	{
     
	ClearCart();
    }
	return 0;
}
