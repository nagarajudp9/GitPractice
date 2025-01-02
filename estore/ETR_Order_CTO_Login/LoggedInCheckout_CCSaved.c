LoggedInCheckout_CCSaved()
{
	if(gs_ccFlag==1) // Pay review for CC Saved user		
	{
	
	web_reg_save_param("cp_merchantName","LB=<input type=\"hidden\" name=\"merchantName\" value=\"","RB=\"/>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_sessionid","LB=<input type=\"hidden\" id=\"sessionId\" value=\"","RB=\"/>","Notfound=warning",LAST);	

	web_reg_save_param("cp_authToken","LB=<input type=\"hidden\" id=\"authToken\" value=\"","RB=\"/>","Notfound=warning",LAST);

	web_reg_save_param("cp_FirstNameAccount","LB=<div class=\"lblContact\">","RB= ","Notfound=warning",LAST);
	
	web_reg_save_param("cp_LastNameAccount","LB= ","RB=<br><span class=\"bgHighlight\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_EmailAccount","LB=<span class=\"bgHighlight\">","RB=</span><br>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_PhoneAccount","LB=</span><br>","RB=</div>","Savelen=18","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentFirstName","LB=data-fn=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentLastName","LB=data-ln=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentNickName","LB=data-nn=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentPhone","LB=data-ph=\"","RB=\"","Savelen=18","Notfound=warning",LAST);
	
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
	
	//lr_start_sub_transaction("S27-1_Checkout_LoggedIn_CC_OC","S27_Checkout_CC_Saved");
	
	web_url("OrderCalculate_2", 
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?updatePrices=1&shipmentType=single&calculationUsageId=-1&calculationUsageId=-4&calculationUsageId=-6&errorViewName=AjaxOrderItemDisplayView&catalogId=10051&langId=-1&QuoteDisable=N&URL=OrderShippingBillingView&storeId=10151&orderId=.", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t69.inf", 
		"Mode=HTML", 
		LAST);
	
	//lr_end_sub_transaction("S27-1_Checkout_LoggedIn_CC_OC", LR_AUTO);

	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513772230601&action=cupis&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
	//"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto=iMFALsTsuaO8R%2F7ab6uCT2PolvC2%2BQn5ZmFuRtC5l450iAvidp9Mhq7qCGUKYPFTp%2BFnZzGJXz8ork7GqRwumYnH3bO0DZYTtp%2B%2BH9RiMtz1zz7yCYRHjjnaWa3ccM136hyP7nvfTrPDrrY4FM92KYNpsrFW7oPo%2Br1CaA7bOB8s5QS4rfaeebYaLdNRBApOcoSGFXlVwcoc1YfsxKFDF%2FmXtMrh4Q%2FJ6a4D8MSFJLNbUqOMtB31GhMtUVZkG1aREoFKd0fAPgQLiZmntnCrG8HiUVI9hzoP1sA3ELPHCfdP8xs5n2DUNZL9na8QmgaYagW830XXqKO%2BSEDYoak4PQ%3D%3D&ddkey=https%3AOrderCalculate", 
		"Snapshot=t30.inf", 
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
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNo}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_correlationId}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld={cp_orderNo}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_correlationId}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"\",\"City\":\"\",\"State\":\"\",\"Zip\":\"\",\"Country\":\"US\",\"ContactFirstName\":\"\",\"ContactLastName\":\"\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"Con"
		"tactEmail\":\"\",\"AddressName\":\"\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"\",\"LastName\":\"\",\"Email\":\"\",\"Phone\":\"\",\"Locale\":\"en_US\"},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":\"\",\"GPay\":{\"IsServiceRequired\":true}}", ENDITEM,
		LAST);
	
	web_reg_save_param_ex("ParamName=cp_EstGrandTotal","LB=EstGrandTotal\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_TotalTaxAmount","LB=TotalTaxAmount\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Price","LB=Item_Price\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Name","LB=Item_Name\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Code","LB=Item_Code\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param("cp_adjprice","LB=orderSavings\">$","RB=</span>","Notfound=warning",LAST);
		
	web_url("RefreshCheckoutCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCheckoutCart?ajax=true&crID=H336722506_1598018785982&storeId=10151&langId=-1&catalogId=10051&ccf=false&cof=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_save_string(string_replace(lr_eval_string("{cp_EstGrandTotal}"),",",""),"cp_EstGrandTotal1");
	
	lr_save_string(string_replace(lr_eval_string("{cp_EstGrandTotal1}"),".",""),"cp_EstGrandTotal01");
	
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
	
	web_submit_data("PHCPollerCmd",
		"Action=https://{p_hostName}/us-en/shop/PHCPollerCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"Hzh4v%2FelY76bfygJoJ%2BzDzv0Z7W%2BdBiTjv3Cwe25ufgD0FDse6z9oUfCSR1q26V59PL5b7jx5AEp5ziOTujx5kVXRTl3%2BUQa%2FUWbsKpVAOSj69Nm7tbeZT7fFQo%2F14MPTFaurEfRd5RrN6NV170HiIS2YQuhoUQ3JjENgv5GnyaMftFj4ph5vVvK8AZgxOXWV3W8saaWTrKxR3m%2F3UtlzV16wjD9zFsrFbyiDXyqihoDbjs72nkKEua5x9dwVGsaFoj4WxiePLSGJDN3g34TxzuYhGJCyomTv%2BwEgG644ku6eaaAPFQzFA3Mo3xd62lbDGFlFHBpRIUC%2BhiBVJDjpx9xLYlJBMVxYQovgYmQ3qllTKzuOrAZxU1zxK0vZqzG%2FwicJJrhONBCZ91eUw2P5w%3D%3D&ddkey=https%3AOrderCalculate", 
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
		
	lr_end_transaction("S27_Checkout_CC_Saved",LR_AUTO);
	
	}
	
	return 0;
}
