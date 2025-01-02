ConvertQuote()
{
	web_save_timestamp_param("cp_time", LAST);
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	lr_start_transaction("CP47_ConvertQuoteToOrder");

	web_url("QuoteGenerateOrder", 
		"URL=https://{p_hostName}/us-en/shop/QuoteGenerateOrder?errorViewName=AjaxOrderItemDisplayView&catalogId=10051&langId=-1&QuoteDisable=Y&URL=OrderShippingBillingView&storeId=10151&orderId={cp_orderId}&createOrder=Y",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/quoteDetailsView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t213.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param("cp_merchantName","LB=<input type=\"hidden\" name=\"merchantName\" value=\"","RB=\"/>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_addressId","LB=<input type=\"hidden\" id=\"sAddrId\" name=\"sAddrId\" value=\"","RB=\">","Notfound=warning",LAST);	
	
	web_reg_save_param("cp_orderId","LB=<input type=\"hidden\" id=\"orderId\" value=\"","RB=\"/>","Notfound=warning",LAST);	
	web_reg_save_param("cp_orderNo","LB=<input type=\"hidden\" id=\"ormOrderId\" value=\"","RB=\"/>","Notfound=warning",LAST);
	web_reg_save_param("cp_authToken","LB=<input type=\"hidden\" id=\"authToken\" value=\"","RB=\"/>","Notfound=warning",LAST);		
	web_reg_save_param("cp_correlationId","LB=<input type=\"hidden\" id=\"correlationId\" name=\"correlationId\" value=\"","RB=\"/>","Notfound=warning",LAST);
	web_reg_save_param("cp_sessionid","LB=<input type=\"hidden\" id=\"sessionId\" value=\"","RB=\"/>","Notfound=warning",LAST);		
	web_reg_save_param("cp_safeTechSessionId","LB=<input type=\"hidden\" id=\"safeTechSessionId\" value=\"","RB=\"/>","Notfound=warning",LAST);		
	
	/*<input type="hidden" id="orderId" value="37892445241470"/>
	<input type="hidden" id="ormOrderId" value="H322200304"/>
	<input type="hidden" id="authToken" value="61051051%2CMFbJw3KSz8JLgi8MymdpXYpSHfck%2F3O4jsmZ8KecSIY%3D"/>
	<input type="hidden" id="correlationId" name="correlationId" value="H322200304_1527349927973"/>
	<input type="hidden" id="sessionId" value="gIHAup-Vldvx7fEzHnM5aYY"/>
	<input type="hidden" id="safeTechSessionId" name="safeTechSessionId" value="H322200304_1527349927973"/>*/
	
	web_url("OrderShippingBillingView", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AQuoteGenerateOrder",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t75.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_10", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1527256231381&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t215.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("CP47_ConvertQuoteToOrder",LR_AUTO);
	
	if(gs_ccFlag!=1)
	{
		
	web_save_timestamp_param("cp_time", LAST);
	lr_output_message("Timestamp: %s", lr_eval_string("{cp_time}"));
	
	web_reg_save_param("cp_addressId","LB=\"addressId\": \"","RB=\"","Notfound=warning",LAST);
	
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
	lr_start_transaction("CP28_CheckoutDetails_LoggedIn_SMB");

	web_submit_data("AjaxOrderShipInfoUpdate_2", 
		"Action=https://{p_hostName}/us-en/shop/AjaxOrderShipInfoUpdate", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Snapshot=t247.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=editAddress", "Value=true", ENDITEM, 
		"Name=nickName", "Value=Punchout_STO_ConvertQuote_{cp_time}", ENDITEM, 
		"Name=addressId", "Value={cp_addressId}", ENDITEM, 
		"Name=firstName", "Value=PerfFirstSMB", ENDITEM, 
		"Name=lastName", "Value=PerfLastSMB", ENDITEM, 
		"Name=organizationName", "Value=PerfTest", ENDITEM, 
		"Name=address1", "Value=PerfAddress1", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value={p_city}", ENDITEM, 
		"Name=state", "Value={p_state}", ENDITEM,  
		"Name=zipCode", "Value={p_zipCode}", ENDITEM, 
		"Name=country", "Value=US", ENDITEM, 
		"Name=email1", "Value={cp_userEmail}", ENDITEM, 
		"Name=phone1", "Value=1234567890", ENDITEM, 
		"Name=isResidenceAddr", "Value=true", ENDITEM, 
		"Name=isSmbOrder", "Value=true", ENDITEM, 
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
		"Name=ccf", "Value=true", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);

	web_url("RefreshCheckoutCart_2", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCheckoutCart?ajax=true&crID={cp_orderNo}_{cp_time}&storeId=10151&langId=-1&catalogId=10051&ccf=true&cof=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t248.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("HPAddressAdd", 
		"Action=https://{p_hostName}/us-en/shop/HPAddressAdd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Snapshot=t249.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=shipFirstName", "Value=PerfFirstSMB", ENDITEM, 
		"Name=shipLastName", "Value=PerfLastSMB", ENDITEM, 
		"Name=companyinput", "Value=PerfTest", ENDITEM, 
		"Name=shipAddress1", "Value=PerfAddress1", ENDITEM, 
		"Name=shipAddress2", "Value=", ENDITEM, 
		"Name=shipCity", "Value={p_city}", ENDITEM, 
		"Name=shipState", "Value={p_state}", ENDITEM, 
		"Name=shipZipcode", "Value={p_zipCode}", ENDITEM, 
		"Name=shipPhoneno", "Value=1234567890", ENDITEM, 
		"Name=billFirstName", "Value=PerfFirstSMB", ENDITEM, 
		"Name=billLastName", "Value=PerfLastSMB", ENDITEM, 
		"Name=companyinput1", "Value=", ENDITEM, 
		"Name=billAddress1", "Value=PerfAddress1", ENDITEM, 
		"Name=billAddress2", "Value=", ENDITEM, 
		"Name=billCity", "Value={p_city}", ENDITEM, 
		"Name=billState", "Value={p_state}", ENDITEM, 
		"Name=billZipcode", "Value={p_zipCode}", ENDITEM, 
		"Name=billCountry", "Value=US", ENDITEM, 
		"Name=confirmationEmail", "Value={cp_userEmail}", ENDITEM, 
		"Name=billPhoneno", "Value=1234567890", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=selectedShipMethod", "Value=12056", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=chkSCLimit", "Value=true", ENDITEM, 
		"Name=editPmtAddr", "Value=false", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=true", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	web_convert_param("cp_pdpname",
			          "SourceString={cp_pdpname}",
			          "SourceEncoding=HTML",
			          "TargetEncoding=URL",
			           LAST);
	
	web_convert_param("cp_userEmail_URL",
			          "SourceString={cp_userEmail}",
			          "SourceEncoding=HTML",
			          "TargetEncoding=URL",
			           LAST);
		
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");


	lr_end_transaction("CP28_CheckoutDetails_LoggedIn_SMB",LR_AUTO);
	
	gs_ccFlag=1;		
		
	}

	
	return 0;
}
