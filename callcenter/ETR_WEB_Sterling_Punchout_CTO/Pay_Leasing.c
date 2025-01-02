Pay_Leasing()
{
	
		web_save_timestamp_param("cp_time", LAST);
	lr_output_message("Timestamp: %s", lr_eval_string("{cp_time}"));

	pmaxValue = atoi(lr_eval_string("{p_randomNum}"));		
	if(pmaxValue<5)
	{
		
	web_reg_save_param("cp_addressId","lb=addressId\": \"","rb=\",","notfound=warning",LAST);

	web_reg_find("Search=Body","Text=organizationName","savecount=Order",LAST);
		
		web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");	
	lr_start_transaction("CP50_CreateLO");
		

	
	web_submit_data("AjaxOrderShipInfoUpdate", 
		"Action=https://{p_hostName}/us-en/shop/AjaxOrderShipInfoUpdate", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto3}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t184.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=editAddress", "Value=true", ENDITEM, 
		"Name=nickName", "Value={cp_userEmail}", ENDITEM, 
		"Name=addressId", "Value={cp_addressId}", ENDITEM, 
		"Name=firstName", "Value=PFName", ENDITEM, 
		"Name=lastName", "Value=PLName", ENDITEM,  
		"Name=organizationName", "Value=HP", ENDITEM, 
		"Name=address1", "Value={cp_address1}", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value={p_city}", ENDITEM, 
		"Name=state", "Value={p_state}", ENDITEM, 
		"Name=zipCode", "Value={p_zipCode}", ENDITEM, 
		"Name=country", "Value=US", ENDITEM, 
		"Name=email1", "Value={cp_userEmail}", ENDITEM, 
		"Name=phone1", "Value=9878787674", ENDITEM, 
		"Name=isResidenceAddr", "Value=true", ENDITEM, 
		"Name=isSmbOrder", "Value=true", ENDITEM, 
		"Name=shipModeId", "Value=12056", ENDITEM, 
		"Name=authToken", "Value={cp_AuthId}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=addressType", "Value=S", ENDITEM, 
		"Name=URL", "Value=/", ENDITEM, 
		"Name=correlationId", "Value={cp_orderNo}_{cp_time}", ENDITEM, 
		"Name=taxExemptCheck", "Value=false", ENDITEM, 
		"Name=taxExemptOrgName", "Value=", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=true", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);

	web_url("RefreshCheckoutCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCheckoutCart?ajax=true&crID={cp_orderNo}_{cp_time}&storeId=10151&langId=-1&catalogId=10051&ccf=true&cof=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto3}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t187.inf", 
		"Mode=HTML", 
		LAST);
	
	
		lr_end_transaction("CP50_CreateLO",LR_AUTO);
	
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");		
		lr_start_transaction("CP51_SubmitOrder_LO");
	
	
	web_submit_data("ccAjaxSubmitOrderComments", 
		"Action=https://{p_hostName}/us-en/shop/ccAjaxSubmitOrderComments", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		//"{cp_krypto_3}&ddkey=https%3AOrderCalculate", 
		"Referer=",
		"Snapshot=t37.inf",
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=orderComment", "Value=test", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=true", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);


	web_submit_data("OrderSubmitServiceCmd", 
		"Action=https://{p_hostName}/us-en/shop/OrderSubmitServiceCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto3}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t189.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=shipto_firstname", "Value={cp_firstname}", ENDITEM, 
		"Name=shipto_lastname", "Value={cp_lastname}", ENDITEM, 
		"Name=shipto_companyname", "Value=HP", ENDITEM, 
		"Name=shipto_address1", "Value={cp_address1}", ENDITEM, 
		"Name=shipto_address2", "Value=", ENDITEM, 
		"Name=shipto_city", "Value={p_city}", ENDITEM, 
		"Name=shipto_state", "Value={p_state}", ENDITEM, 
		"Name=shipto_stateprovince", "Value={p_state}", ENDITEM, 
		"Name=shipto_zipcode", "Value={p_zipCode}", ENDITEM, 
		"Name=shipto_country", "Value=US", ENDITEM, 
		"Name=shipto_phonenumber", "Value=9878787674", ENDITEM, 
		"Name=isBusinessPurchase", "Value=true", ENDITEM, 
		"Name=shippingContactFirstName", "Value={cp_firstname}", ENDITEM, 
		"Name=shippingContactLastName", "Value={cp_lastname}", ENDITEM, 
		"Name=shippingCompanyName", "Value=HP", ENDITEM, 
		"Name=shippingAddress1", "Value={cp_address1}", ENDITEM, 
		"Name=shippingAddress2", "Value=", ENDITEM, 
		"Name=shippingCity", "Value={p_city}", ENDITEM, 
		"Name=shippingState", "Value={p_state}", ENDITEM, 
		"Name=shippingZip", "Value={p_zipCode}", ENDITEM, 
		"Name=shippingPhoneNumber", "Value=9878787674", ENDITEM, 
		"Name=billingContactFirstName", "Value={cp_firstname}", ENDITEM, 
		"Name=billingContactLastName", "Value={cp_lastname}", ENDITEM, 
		"Name=billto_NickName", "Value=", ENDITEM, 
		"Name=billto_firstname", "Value={cp_firstname}", ENDITEM, 
		"Name=billto_lastname", "Value={cp_lastname}", ENDITEM, 
		"Name=billto_address1", "Value={cp_address1}", ENDITEM, 
		"Name=billto_address2", "Value=", ENDITEM, 
		"Name=billto_city", "Value={p_city}", ENDITEM, 
		"Name=billto_state", "Value={p_state}", ENDITEM, 
		"Name=billto_stateprovince", "Value={p_state}", ENDITEM, 
		"Name=billto_zipcode", "Value={p_zipCode}", ENDITEM, 
		"Name=billto_country", "Value=US", ENDITEM, 
		"Name=billto_phone_number", "Value=9878787674", ENDITEM, 
		"Name=confirmationEmail", "Value={cp_userEmail}", ENDITEM, 
		"Name=addressId", "Value={cp_addressId}", ENDITEM, 
		"Name=logonID", "Value={cp_userEmail}", ENDITEM, 
		"Name=safeTechSessionId", "Value={cp_orderNo}_{cp_time}", ENDITEM, 
		"Name=paymentType", "Value=lease", ENDITEM, 
		"Name=ani", "Value=3333333333", ENDITEM, 
		"Name=salNumber", "Value=9878787674", ENDITEM, 
		"Name=mailHPFS", "Value=perftesting_leasing@hp.com", ENDITEM, 
		"Name=isSmbOrder", "Value=true", ENDITEM, 
		"Name=isPartnerAgentOrder", "Value=false", ENDITEM, 
		"Name=partnerLocId", "Value=", ENDITEM, 
		"Name=partnerRepId", "Value=", ENDITEM, 
		"Name=partnerPO", "Value=", ENDITEM, 
		"Name=partnerName", "Value=", ENDITEM, 
		"Name=partnerCity", "Value=", ENDITEM, 
		"Name=partnerState", "Value=", ENDITEM, 
		"Name=partnerZip", "Value=", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=ormorder", "Value={cp_orderNo}", ENDITEM, 
		"Name=aoID", "Value=", ENDITEM, 
		"Name=taxCheck", "Value=0", ENDITEM, 
		"Name=selectedShipMethod", "Value=12056", ENDITEM, 
		"Name=paymenttype", "Value=lease", ENDITEM, 
		"Name=chkSCLimit", "Value=true", ENDITEM, 
		"Name=policyId", "Value=", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=true", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);



	web_submit_data("OrderShippingBillingConfirmationView", 
		"Action=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingConfirmationView", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto3}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t192.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=shipmentTypeId", "Value=1", ENDITEM, 
		"Name=emailSender", "Value={cp_userEmail}", ENDITEM, 
		"Name=sessionKey", "Value=", ENDITEM, 
		"Name=paymenttype", "Value=lease", ENDITEM, 
		"Name=corelID", "Value={cp_orderNo}_{cp_time}", ENDITEM, 
		"Name=totalAdjValue", "Value=0", ENDITEM, 
		LAST);


	web_url("HPServices_9", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1530611330097&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingConfirmationView", 
		"Snapshot=t195.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("FDPromotionCmd", 
		"Action=https://{p_hostName}/us-en/shop/FDPromotionCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingConfirmationView", 
		"Snapshot=t197.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=requesttype", "Value=ajax", ENDITEM, 
		LAST);
	
	lr_end_transaction("CP51_SubmitOrder_LO",LR_AUTO);

//	if(atoi(lr_eval_string("{Order}")) > 0)
//		{
//			lr_end_transaction("CP07_PlaceOrder",LR_PASS);
//
//		}
//		else
//		{
//			lr_end_transaction("CP07_PlaceOrder",LR_FAIL);
//			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);			
//		}
//		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
		
	}
	
	else
	{
		
	web_reg_save_param("cp_AddressId","lb=addressId\": \"","rb=\",","notfound=warning",LAST);
	//web_reg_save_param("cp_addr","LB=data-addr=\"","RB=\"","Notfound=warning",LAST); 
		web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
	lr_start_transaction("CP52_CreateAO");


	web_submit_data("AjaxOrderShipInfoUpdate", 
		"Action=https://{p_hostName}/us-en/shop/AjaxOrderShipInfoUpdate", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto_3}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t35.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=editAddress", "Value=true", ENDITEM, 
		"Name=nickName", "Value={cp_userEmail}", ENDITEM, 
		"Name=addressId", "Value={cp_addressId}", ENDITEM, 
		"Name=firstName", "Value=PFName", ENDITEM, 
		"Name=lastName", "Value=PLName", ENDITEM,  
		"Name=organizationName", "Value=HP", ENDITEM, 
		"Name=address1", "Value={cp_address1}", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value={p_city}", ENDITEM, 
		"Name=state", "Value={p_state}", ENDITEM, 
		"Name=zipCode", "Value={p_zipCode}", ENDITEM, 
		"Name=country", "Value=US", ENDITEM, 
		"Name=email1", "Value={cp_userEmail}", ENDITEM, 
		"Name=phone1", "Value=9878787674", ENDITEM, 
		"Name=isResidenceAddr", "Value=true", ENDITEM, 
		"Name=isSmbOrder", "Value=true", ENDITEM, 
		"Name=shipModeId", "Value=12056", ENDITEM, 
		"Name=authToken", "Value={cp_AuthId}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=addressType", "Value=S", ENDITEM, 
		"Name=URL", "Value=/", ENDITEM, 
		"Name=correlationId", "Value={cp_orderNo}_{cp_time}", ENDITEM, 
		"Name=taxExemptCheck", "Value=false", ENDITEM, 
		"Name=taxExemptOrgName", "Value=", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=true", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);

	web_url("RefreshCheckoutCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCheckoutCart?ajax=true&crID={cp_orderNo}_{cp_time}&storeId=10151&langId=-1&catalogId=10051&ccf=true&cof=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto_3}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("CP52_CreateAO",LR_AUTO);
		web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
		lr_start_transaction("CP53_SubmitOrder_AO");


	web_submit_data("ccAjaxSubmitOrderComments", 
		"Action=https://{p_hostName}/us-en/shop/ccAjaxSubmitOrderComments", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto_3}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=orderComment", "Value=test", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=true", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);

	web_submit_data("OrderSubmitServiceCmd", 
		"Action=https://{p_hostName}/us-en/shop/OrderSubmitServiceCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto_3}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=shipto_firstname", "Value={cp_firstname}", ENDITEM, 
		"Name=shipto_lastname", "Value={cp_lastname}", ENDITEM, 
		"Name=shipto_companyname", "Value=HP", ENDITEM, 
		"Name=shipto_address1", "Value={cp_address1}", ENDITEM, 
		"Name=shipto_address2", "Value=", ENDITEM, 
		"Name=shipto_city", "Value={p_city}", ENDITEM, 
		"Name=shipto_state", "Value={p_state}", ENDITEM, 
		"Name=shipto_stateprovince", "Value={p_state}", ENDITEM, 
		"Name=shipto_zipcode", "Value={p_zipCode}", ENDITEM, 
		"Name=shipto_country", "Value=US", ENDITEM, 
		"Name=shipto_phonenumber", "Value=9878787674", ENDITEM, 
		"Name=isBusinessPurchase", "Value=true", ENDITEM, 
		"Name=shippingContactFirstName", "Value={cp_firstname}", ENDITEM, 
		"Name=shippingContactLastName", "Value={cp_lastname}", ENDITEM, 
		"Name=shippingCompanyName", "Value=HP", ENDITEM, 
		"Name=shippingAddress1", "Value={cp_address1}", ENDITEM, 
		"Name=shippingAddress2", "Value=", ENDITEM, 
		"Name=shippingCity", "Value={p_city}", ENDITEM, 
		"Name=shippingState", "Value={p_state}", ENDITEM, 
		"Name=shippingZip", "Value={p_zipCode}", ENDITEM, 
		"Name=shippingPhoneNumber", "Value=9878787674", ENDITEM, 
		"Name=billingContactFirstName", "Value={cp_firstname}", ENDITEM, 
		"Name=billingContactLastName", "Value={cp_lastname}", ENDITEM, 
		"Name=billto_NickName", "Value=", ENDITEM, 
		"Name=billto_firstname", "Value={cp_firstname}", ENDITEM, 
		"Name=billto_lastname", "Value={cp_lastname}", ENDITEM, 
		"Name=billto_address1", "Value={cp_address1}", ENDITEM, 
		"Name=billto_address2", "Value=", ENDITEM, 
		"Name=billto_city", "Value={p_city}", ENDITEM, 
		"Name=billto_state", "Value={p_state}", ENDITEM, 
		"Name=billto_stateprovince", "Value={p_state}", ENDITEM, 
		"Name=billto_zipcode", "Value={p_zipCode}", ENDITEM, 
		"Name=billto_country", "Value=US", ENDITEM, 
		"Name=billto_phone_number", "Value=9878787674", ENDITEM, 
		"Name=confirmationEmail", "Value={cp_userEmail}", ENDITEM, 
		"Name=addressId", "Value={cp_addressId}", ENDITEM, 
		"Name=logonID", "Value={cp_userEmail}", ENDITEM, 
		"Name=safeTechSessionId", "Value={cp_orderNo}_{cp_time}", ENDITEM, 
		"Name=paymentType", "Value=ACWR", ENDITEM, 
		"Name=ani", "Value=3333333333", ENDITEM, 
		"Name=ACHPRN", "Value=9878787674", ENDITEM, 
		"Name=ACHSAP", "Value=9876543210", ENDITEM, 
		"Name=chkType", "Value={PaymentType}", ENDITEM, 
		"Name=isSmbOrder", "Value=true", ENDITEM, 
		"Name=isPartnerAgentOrder", "Value=false", ENDITEM, 
		"Name=partnerLocId", "Value=", ENDITEM, 
		"Name=partnerRepId", "Value=", ENDITEM, 
		"Name=partnerPO", "Value=", ENDITEM, 
		"Name=partnerName", "Value=", ENDITEM, 
		"Name=partnerCity", "Value=", ENDITEM, 
		"Name=partnerState", "Value=", ENDITEM, 
		"Name=partnerZip", "Value=", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=ormorder", "Value={cp_orderNo}", ENDITEM, 
		"Name=aoID", "Value=", ENDITEM, 
		"Name=taxCheck", "Value=0", ENDITEM, 
		"Name=selectedShipMethod", "Value=12056", ENDITEM, 
		"Name=paymenttype", "Value=ACWR", ENDITEM, 
		"Name=chkSCLimit", "Value=true", ENDITEM, 
		"Name=policyId", "Value=", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=true", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);

	

	web_submit_data("OrderShippingBillingConfirmationView", 
		"Action=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingConfirmationView", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto_3}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=shipmentTypeId", "Value=1", ENDITEM, 
		"Name=emailSender", "Value={cp_userEmail}", ENDITEM, 
		"Name=sessionKey", "Value=", ENDITEM, 
		"Name=paymenttype", "Value=ACWR", ENDITEM, 
		"Name=corelID", "Value={cp_orderNo}_{cp_time}", ENDITEM, 
		"Name=totalAdjValue", "Value=0", ENDITEM, 
		LAST);

	

	web_url("HPServices_7", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1530682049317&action=cupis&catentryId=&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingConfirmationView", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		LAST);

	
	web_submit_data("FDPromotionCmd", 
		"Action=https://{p_hostName}/us-en/shop/FDPromotionCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingConfirmationView", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=requesttype", "Value=ajax", ENDITEM, 
		LAST);
	
	
	lr_end_transaction("CP53_SubmitOrder_AO", LR_AUTO);
	
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
		
	}
	
	

	return 0;
}
