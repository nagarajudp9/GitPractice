Pay_AmexCard()
{
	if(strcmp(lr_eval_string("{cp_orderId}"),"")==0)
		{
			CC_Logout();
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
		}	
	
	lr_think_time(120);
	
	lr_start_transaction("CP30_Pay_AC_Review");	
	web_submit_data("PHCReceiver", 
				"Action=https://vphcitg.pgs.ext.hp.com/PHCReceiver", 
				"Method=POST", 
				"RecContentType=text/html", 
				"Referer=https://vphcitg.pgs.ext.hp.com/PHCJSReceiver/ajax_xdm.htm", 
				"Snapshot=t172.inf", 
				"Mode=HTML", 
				"EncodeAtSign=YES", 
				ITEMDATA, 
				"Name=JsonRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"OrderID\":\"{cp_orderNo}\",\"CustomerID\":\"\",\"CustomerInfo\":{\"FirstName\":\"Perffirst\",\"LastName\":\"Perflast\",\"Email\":\"radhika.arunachalam@hp.com\",\"Phone\":\"1234567890\",\"HpCustomerNumber\":\"\"},\"BillAddress\":{\"AddressName\":\"Perfdrive\",\"Address1\":\"Perfdrive\",\"Address2\":\"\",\"Address3\":\"\",\"Address4\":\"\",\"City\":\"{p_city}\",\"State\":\"{p_state}\",\"Zip\":\"{p_zipCode}\",\"Country\":\"US\",\"ContactLastName\":\""
				"Perflast\",\"ContactDayPhone\":\"1234567890\",\"ContactNightPhone\":\"\",\"ContactEmail\":\"\",\"Fax\":\"\"},\"ShipToAddress\":{\"AddressName\":\"Perfdrive\",\"Address1\":\"Perfdrive\",\"Address2\":\"\",\"Address3\":\"\",\"Address4\":\"\",\"City\":\"{p_city}\",\"State\":\"{p_state}\",\"Zip\":\"{p_zipCode}\",\"Country\":\"US\",\"CompanyName\":\"\",\"ContactLastName\":\"Perflast\",\"ContactDayPhone\":\"545-453-5454\",\"ContactNightPhone\":\"\",\"ContactEmail\":\"\",\"Fax\":\"\"},\"IsManualTransaction\":\"true\",\"IsSaveProfile\":"
				"\"false\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"CreditCards\":[{\"CCNumber\":\"341134113411347\",\"CardType\":\"003\",\"LastFour\":\"4113\",\"CCToken\":\"\",\"CCSignature\":\"\",\"CCExpYear\":2017,\"CCExpMon\":12,\"CVV\":\"123\",\"CCIssueNo\":\"\",\"CCStartYear\":\"\",\"CCStartMon\":\"\",\"CVVMatchResult\":\"\",\"IsSaveProfile\":false}]}", ENDITEM, 
				LAST);

		
		web_url("OrderShippingBillingView_2", 
		"URL=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_orderNo}_{cp_time}&tld={cp_orderNo}-{cp_time}-10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://vphcitg.pgs.ext.hp.com/HostPaymentETR/ETRPHCPage.aspx", 
		"Snapshot=t110.inf", 
		"Mode=HTML", 
		LAST);
		
		
		web_url("HPServices_5", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513772436684&action=cupis&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_orderNo}_{cp_time}&tld={cp_orderNo}-{cp_time}-10151", 
		"Snapshot=t50.inf", 
		"Mode=HTML", 
		LAST);

		
		web_reg_save_param("payment","LB=\"orderStatus\": ","RB=,","NOTFOUND=warning",LAST);
	
		
		web_submit_data("PHCPollerCmd", 
		"Action=https://{p_hostName}/us-en/shop/PHCPollerCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_orderNo}_{cp_time}&tld={cp_orderNo}-{cp_time}-10151", 
		"Snapshot=t116.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=tlDataKey", "Value={cp_orderNo}-{cp_time}-10151", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=correlationId", "Value={cp_orderNo}_{cp_time}", ENDITEM, 
		"Name=sessionId", "Value={cp_sessionid}", ENDITEM, 
		"Name=gcFlag", "Value=false", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
		
	if(strcmp(lr_eval_string("{payment}"),"")==0)
	{
		lr_end_transaction("CP30_Pay_AC_Review",LR_AUTO);
		ConfirmOrder(1);
	}
	else
	{
		lr_end_transaction("CP30_Pay_AC_Review",LR_FAIL);
		RemoveCart();			
		//CC_Logout();			
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	
	return 0;
}
