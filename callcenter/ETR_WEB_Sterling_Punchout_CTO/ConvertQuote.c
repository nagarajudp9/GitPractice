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
	
	web_reg_save_param("cp_merchantName","LB=<input type=\"hidden\" name=\"merchantName\" value=\"","RB=\"/>",LAST);
	
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
		"Name=nickName", "Value=Punchout_CTO_ConvertQuote_{cp_time}", ENDITEM, 
		"Name=addressId", "Value={cp_addressId}", ENDITEM, 
		"Name=firstName", "Value=PerfFirstSMB", ENDITEM, 
		"Name=lastName", "Value=PerfLastSMB", ENDITEM, 
		"Name=organizationName", "Value=HP", ENDITEM, 
		"Name=address1", "Value=PerfAddress1", ENDITEM, 
		"Name=address2", "Value=Ttest", ENDITEM, 
		"Name=city", "Value={p_city}", ENDITEM, 
		"Name=state", "Value={p_state}", ENDITEM,  
		"Name=zipCode", "Value={p_zipCode}", ENDITEM, 
		"Name=country", "Value=US", ENDITEM, 
		"Name=email1", "Value={cp_EmailAccount}", ENDITEM, 
		"Name=phone1", "Value=9878787674", ENDITEM, 
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
		"Name=companyinput", "Value=HP", ENDITEM, 
		"Name=shipAddress1", "Value=PerfAddress1", ENDITEM, 
		"Name=shipAddress2", "Value=", ENDITEM, 
		"Name=shipCity", "Value={p_city}", ENDITEM, 
		"Name=shipState", "Value={p_state}", ENDITEM, 
		"Name=shipZipcode", "Value={p_zipCode}", ENDITEM, 
		"Name=shipPhoneno", "Value=9878787674", ENDITEM, 
		"Name=billFirstName", "Value=PerfFirstSMB", ENDITEM, 
		"Name=billLastName", "Value=PerfLastSMB", ENDITEM, 
		"Name=companyinput1", "Value=", ENDITEM, 
		"Name=billAddress1", "Value=PerfAddress1", ENDITEM, 
		"Name=billAddress2", "Value=", ENDITEM, 
		"Name=billCity", "Value={p_city}", ENDITEM, 
		"Name=billState", "Value={p_state}", ENDITEM, 
		"Name=billZipcode", "Value={p_zipCode}", ENDITEM, 
		"Name=billCountry", "Value=US", ENDITEM, 
		"Name=confirmationEmail", "Value={cp_EmailAccount}", ENDITEM, 
		"Name=billPhoneno", "Value=9878787674", ENDITEM, 
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
	
	web_convert_param("cp_EmailAccountl_URL",
			          "SourceString={cp_EmailAccount}",
			          "SourceEncoding=HTML",
			          "TargetEncoding=URL",
			           LAST);
		
	//web_set_sockets_option("SSL_VERSION", "TLS1.2");
web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
web_submit_data("ETRPHCPage.aspx",
		"Action=https://vphcitg.pgs.ext.hp.com/HostPaymentETR/ETRPHCPage.aspx", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Snapshot=t252.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=merchantName", "Value={cp_merchantName}", ENDITEM, 
		"Name=ccflow", "Value=true", ENDITEM, 
		"Name=phcData", "Value="
		"%7B%22MerchantName%22%3A%22{cp_merchantName}%22%2C%22OrderID%22%3A%22{cp_orderNo}%22%2C%22CustomerID%22%3A%22%22%2C%22CustomerInfo%22%3A%7B%22FirstName%22%3A%22PerfFirstSMB%22%2C%22LastName%22%3A%22PerfLastSMB%22%2C%22Email%22%3A%22{cp_userEmail_URL}%22%2C%22Phone%22%3A%229878787674%22%2C%22HpCustomerNumber%22%3A%22%22%2C%22CompanyName%22%3A%22%22%7D%2C%22BillAddress%22%3A%7B%22AddressName%22%3A%22PerfAddress1%22%2C%22Address1%22%3A%22PerfAddress1%22%2C%22Address2%22"
		"%3A%22%22%2C%22Address3%22%3A%22%22%2C%22Address4%22%3A%22%22%2C%22City%22%3A%22{p_city}%22%2C%22State%22%3A%22{p_state}%22%2C%22Zip%22%3A%22{p_zipCode}%22%2C%22Country%22%3A%22US%22%2C%22CompanyName%22%3A%22%22%2C%22ContactLastName%22%3A%22PerfLastSMB%22%2C%22ContactDayPhone%22%3A%22%22%2C%22ContactNightPhone%22%3A%22%22%2C%22ContactEmail%22%3A%22%22%2C%22Fax%22%3A%22%22%7D%2C%22ShipToAddress%22%3A%7B%22AddressName%22%3A%22PerfAddress1%22%2C%22Address1%22%3A%22PerfAddress1%22%2C%22Address2%22%3A%22%22%2C%22Add"
		"ress3%22%3A%22%22%2C%22Address4%22%3A%22%22%2C%22City%22%3A%22{p_city}%22%2C%22State%22%3A%22{p_state}%22%2C%22Zip%22%3A%22{p_zipCode}%22%2C%22Country%22%3A%22US%22%2C%22CompanyName%22%3A%22HP%22%2C%22ContactLastName%22%3A%22PerfLastSMB%22%2C%22ContactDayPhone%22%3A%22%22%2C%22ContactNightPhone%22%3A%22%22%2C%22ContactEmail%22%3A%22%22%2C%22Fax%22%3A%22%22%7D%2C%22IsManualTransaction%22%3A%22true%22%2C%22IsSaveProfile%22%3A%22false%22%2C%22CustomField%22%3A%22{cp_orderNo}-{cp_time}-10151%22%2C%22"
		"CreditCards%22%3A%5B%7B%22CCNumber%22%3A%22%22%2C%22CardType%22%3A%22%22%2C%22LastFour%22%3A%22%22%2C%22CCToken%22%3A%22%22%2C%22CCSignature%22%3A%22%22%2C%22CCExpYear%22%3A0%2C%22CCExpMon%22%3A0%2C%22CVV%22%3A%22%22%2C%22CCIssueNo%22%3A%22%22%2C%22CCStartYear%22%3A%22%22%2C%22CCStartMon%22%3A%22%22%2C%22CVVMatchResult%22%3A%22%22%2C%22IsSaveProfile%22%3Afalse%7D%5D%7D", ENDITEM, 
		"Name=orderData", "Value="
		"%7B%22ReturnPage%22%3A%22OrderShippingBillingView%22%2C%22ReturnKey_Continue%22%3A%22storeId%3D10151%26amp%3BlangId%3D-1%26amp%3BcalculationUsageId%3D-1%26amp%3BupdatePrices%3D1%26amp%3Bcchost%3Dtrue%26amp%3BorderId%3D.%26amp%3BcrID%3D{cp_orderNo}_{cp_time}%26tld%3D{cp_orderNo}-{cp_time}-10151%22%2C%22ReturnKey_Cancel%22%3A%22storeId%3D10151%26amp%3BlangId%3D-1%26amp%3BcatalogId%3D10051%26amp%3BcalculationUsageId%3D-1%26amp%3BupdatePrices%3D1%26amp%3BorderId%3D.%26amp%3Bcancel%3Dtrue%26amp%3Bc"
		"cl%3D1%26amp%3BcrID%3D{cp_orderNo}_{cp_time}%22%2C%22CartPage%22%3A%22OrderShippingBillingView%22%2C%22CartKey_Continue%22%3A%22storeId%3D10151%26amp%3BlangId%3D-1%26amp%3BcatalogId%3D10051%26amp%3BorderId%3D.%26amp%3BcalculationUsageId%3D-1%26amp%3BupdatePrices%3D1%26amp%3Bcancel%3Dtrue%26amp%3BerrorViewName%3DAjaxOrderItemDisplayView%26amp%3BURL%3DAjaxOrderItemDisplayView%22%2C%22Title%22%3A%22hpusstore%20-%20Shipping%20and%20Billing%20Display%22%2C%22cntry%22%3A%22US%22%2C%22dCntry%22%3A%22Un"
		"ited%20States%22%2C%22Timeout%22%3A10000%2C%22Items%22%3A%5B%7B%22dn%22%3A%22{cp_pdpname}%22%2C%22pn%22%3A%22{cp_sku}%22%2C%22qty%22%3A%221%22%2C%22esd%22%3A%22Ship%20date%3A%2005%2F25%2F18%22%2C%22pMsg%22%3A%22%26nbsp%3B%22%2C%22gsPrice%22%3A%22%24{cp_price}%22%2C%22lPrice%22%3A%22%24{cp_price}%22%2C%22oPrice%22%3A%22%24{cp_offerprice}%22%2C%22showSTP%22%3Afalse%2C%22sMsg%22%3A%22%22%2C%22ctoBom%22%3A%22%22%7D%5D%2C%22cpn%22%3A%5B%5D%2C%22gcPay%22%3A%5B%5D%2C%22sVGC%22%3A%5B%5D%2C%22Summary%22%3A%5B%7B%22id%22%3A%22sMethod%22%2C%22value%22%3"
		"A%22Standard%203-6%20business%20days%20(FREE)"
		"%22%7D%2C%7B%22id%22%3A%22tShip%22%2C%22value%22%3A%22FREE%22%7D%2C%7B%22id%22%3A%22tTax%22%2C%22value%22%3A%22%243.11%22%7D%2C%7B%22id%22%3A%22tSub%22%2C%22value%22%3A%22%24{cp_offerprice}%22%7D%2C%7B%22id%22%3A%22tAdj%22%2C%22value%22%3A%22%24{cp_adjprice}%22%7D%2C%7B%22id%22%3A%22gMsg%22%2C%22value%22%3A%22Your%20credit%20card%20infromation%20will%20be%20saved%20only%20if%20you%20register%20for%20an%20account%20at%20the%20end%20of%20the%20checkout%20process.%22%7D%2C%7B%22id%22%3A%22tGrand%22%2C%22value%22%3A%22%"
		"2438.10%22%7D%2C%7B%22id%22%3A%22tBalance%22%2C%22value%22%3A%22%2438.10%22%7D%2C%7B%22id%22%3A%22tGrandNoTax%22%2C%22value%22%3A%22%24{cp_offerprice}%22%7D%2C%7B%22id%22%3A%22signin%22%2C%22value%22%3A%22Sign%20in%2FRegister%22%7D%2C%7B%22id%22%3A%22savearea%22%2C%22value%22%3A%22Y%22%7D%2C%7B%22id%22%3A%22ccsave%22%2C%22value%22%3A%22Y%22%7D%2C%7B%22id%22%3A%22nname%22%2C%22value%22%3A%22%22%7D%2C%7B%22id%22%3A%22ccphone%22%2C%22value%22%3A%22%3C"
		"!--%20BEGIN%20CustomerPhoneContentRecommendation.jsp%20--%3E1-888-897-8561%3C!--%20END%20CustomerPhoneContentRecommendation.jsp%20--%3E%22%7D%2C%7B%22id%22%3A%22cInfo%22%2C%22value%22%3A%22PerfFirstSMB%20PerfLastSMB%3Cbr%2F%3E%3Cspan%20class%3D%5C%22bgHighlight%5C%22%3E{cp_userEmail_URL}%3C%2Fspan%3E%3Cbr%2F%3E(%20123%20)"
		"%20456%20-%207890%22%7D%2C%7B%22id%22%3A%22sAddr%22%2C%22value%22%3A%22PerfFirstSMB%20PerfLastSMB%3Cbr%2F%3EHP%3Cbr%2F%3EPerfAddress1%3Cbr%2F%3E{p_city}%2C%20{p_state}%20{p_zipCode}%22%7D%2C%7B%22id%22%3A%22bAddr%22%2C%22value%22%3A%22PerfFirstSMB%20PerfLastSMB%3Cbr%2F%3EPerfAddress1%3Cbr%2F%3E{p_city}%2C%20{p_state}%20{p_zipCode}%22%7D%5D%7D", ENDITEM, 
		LAST);

	lr_end_transaction("CP28_CheckoutDetails_LoggedIn_SMB",LR_AUTO);
	
	gs_ccFlag = 0;		
		
	}

	
	return 0;
}
