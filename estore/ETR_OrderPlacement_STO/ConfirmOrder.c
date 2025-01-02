ConfirmOrder(int pType)
{
	int cp_adjpricenew,adj;
	long file;
	
	lr_think_time(120);
	
	if(strcmp(lr_eval_string("{cp_adjprice}"),"0.00")==0)
	{
		lr_save_int(0,"cp_adjpricenew");
	}
	else
	{
	
	lr_save_string(string_replace(lr_eval_string("{cp_adjprice}"),",",""),"cp_adjprice");
	
	adj=atoi(lr_eval_string("{cp_adjprice}"));
	
	lr_save_int(adj,"cp_adjpricenew");

	}
	web_save_timestamp_param("cp_time", LAST);
	
	if(pType==1) // Submit order for guest user
	{
	
		if (Preorder==1) //PreOrder R2
		{
		web_reg_find("Search=All","SaveCount=c_ManageSub","Text=SUCCESSFUL_SUBSCRIPTION",LAST);
	
	lr_start_transaction("S35_SubmitOrder_CC");	
	lr_start_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),"S35_SubmitOrder_CC");	
	//lr_start_sub_transaction("S35-1_HPManageSubscriptionCmd","S35_SubmitOrder_CC");	
	
	web_submit_data("HPManageSubscriptionCmd", 
		"Action=https://{p_hostName}/us-en/shop/HPManageSubscriptionCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_orderNo}_{cp_time}&QuoteDisable=Y&tld={cp_orderNo}-{cp_time}-10151", 
		"Snapshot=t124.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=emailInput", "Value={p_userEmail}", ENDITEM, 
		"Name=userType", "Value=G", ENDITEM, 
		"Name=subscribeOption", "Value=true", ENDITEM, 
		"Name=firstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=lastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=webSource", "Value=1", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	//lr_end_sub_transaction("S35-1_HPManageSubscriptionCmd",LR_AUTO);	
	
	if(atoi(lr_eval_string("{c_ManageSub}"))>0)
	{

	}
	else
	{
		lr_end_transaction("S35_SubmitOrder_CC",LR_FAIL);		
		lr_end_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),LR_FAIL);	
		Logout();
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	web_reg_find("Search=All","SaveCount=c_OrderStatus","Text=paymentMessage\": \"Order Decline\"",LAST);
	
	//lr_start_sub_transaction("S35-2_OrderSubmitServiceCmd","S35_SubmitOrder_CC");
	//Add the Value "Name=hasPreOrderSKU", "Value=true", ENDITEM, As part of R2
	web_submit_data("OrderSubmitServiceCmd",
		"Action=https://{p_hostName}/us-en/shop/OrderSubmitServiceCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_orderNo}_{cp_time}&QuoteDisable=Y&tld={cp_orderNo}-{cp_time}-10151", 
		"Snapshot=t125.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=shipto_firstname", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=shipto_lastname", "Value={p_LastNameNew}", ENDITEM, 
		"Name=shipto_address1", "Value={p_Address1New}", ENDITEM, 
		"Name=shipto_address2", "Value=", ENDITEM, 
		"Name=shipto_city", "Value={p_CityNew}", ENDITEM, 
		"Name=shipto_state", "Value={p_StateNew}", ENDITEM, 
		"Name=shipto_stateprovince", "Value={p_StateNew}", ENDITEM, 
		"Name=shipto_zipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=shipto_country", "Value=US", ENDITEM, 
		"Name=shipto_phonenumber", "Value={p_PhoneNew}", ENDITEM, 
		"Name=isBusinessPurchase", "Value=false", ENDITEM,
		"Name=shippingContactFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=shippingContactLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=shippingCompanyName", "Value=", ENDITEM, 
		"Name=shippingAddress1", "Value={p_Address1New}", ENDITEM, 
		"Name=shippingAddress2", "Value=", ENDITEM, 
		"Name=shippingCity", "Value={p_CityNew}", ENDITEM, 
		"Name=shippingState", "Value={p_StateNew}", ENDITEM, 
		"Name=shippingZip", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=shippingPhoneNumber", "Value={p_PhoneNew}", ENDITEM, 
		"Name=billingContactFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=billingContactLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=billto_NickName", "Value=", ENDITEM, 
		"Name=billto_firstname", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=billto_lastname", "Value={p_LastNameNew}", ENDITEM, 
		"Name=billto_address1", "Value={p_Address1New}", ENDITEM, 
		"Name=billto_address2", "Value=", ENDITEM, 
		"Name=billto_city", "Value={p_CityNew}", ENDITEM, 
		"Name=billto_state", "Value={p_StateNew}", ENDITEM, 
		"Name=billto_stateprovince", "Value={p_StateNew}", ENDITEM, 
		"Name=billto_zipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=billto_country", "Value=US", ENDITEM, 
		"Name=billto_phone_number", "Value={p_PhoneNew}", ENDITEM, 
		"Name=confirmationEmail", "Value={p_userEmail}", ENDITEM, 
		"Name=addressId", "Value={cp_addressId}", ENDITEM, 
		"Name=logonID", "Value={p_userEmail}", ENDITEM, 
		"Name=safeTechSessionId", "Value=${cp_orderNo}_{cp_time}", ENDITEM, 
		"Name=paymentType", "Value=creditcard", ENDITEM, 
		"Name=isPartnerAgentOrder", "Value=false", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=ormorder", "Value={cp_orderNo}", ENDITEM, 
		"Name=aoID", "Value=", ENDITEM, 
		"Name=taxCheck", "Value=0", ENDITEM, 
		"Name=selectedShipMethod", "Value=12056", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=chkSCLimit", "Value=true", ENDITEM, 
		"Name=policyId", "Value=", ENDITEM, 
		"Name=tmId", "Value={cp_tmid}", ENDITEM,
	//	"Name=tmId", "Value={cp_tmid}", ENDITEM,
		"Name=hasPreOrderSKU", "Value=true", ENDITEM, 
		"Name=tokenPOBtn", "Value="
		"03AGdBq27CpuErAcsDJ_ZZTWgQ3p7kOarOOopN4tZUj_cUxp0skU0cXxdbiZiH9I0jK-Uz8axJz0SdTO4MaNWAzmwqXCv-gAhtzh_dHARgGFMbh1Jc1R1qj-nnVpxMLAtpCzldgCvhZZVBSSrWMigoNjohfSnWgK4FxFl2TwA9MQOYd97ok67qewoj4rG6Xi9w5jOBjims7i32Q9BBW-WapOOB6Pk1H652kgdp2uFd8mZXKf4RkNN7zR7mKkTCyOWfbFuKztwQVIMZhDyYntSIC234M6tBEQlmkTqtLrz0QKUvnLSNpMs-3_ZhQ-1nkYSx013qbBXPeTW0I6Pv1BB2mtBf18Zq42eqylIZ5W1P7U0Rb2xBqCmf5PHLq4uwvR4HM3XecPidSyNZwo43IkvHb0pbeJ5D6gw1Q1T1FF1y6pTaiIi4OGCzBVxd9TbtBZOGx8VcnfN1D3Aqvgeg2yxs2uaebS2b9sTdfA", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	//lr_end_sub_transaction("S35-2_OrderSubmitServiceCmd",LR_AUTO);	
	
	if(atoi(lr_eval_string("{c_OrderStatus}"))>0)
	{
		
		web_url("OrderDeclineView", 
		"URL=https://{p_hostName}/us-en/shop/OrderDeclineView?storeId=10151&langId=-1&catalogId=10051&payMethod=Credit&lastFour=4113&ormOrderId={cp_orderNo}&cardName=VISA", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t68.inf", 
		"Mode=HTML", 
		LAST);
		
		lr_end_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),LR_AUTO);		
		lr_end_transaction("S35_SubmitOrder_CC",LR_AUTO);
		
		Logout();
		
		lr_start_transaction("S35-1_SubmitOrder_CC_OrderDecline");		
		lr_end_transaction("S35-1_SubmitOrder_CC_OrderDecline",LR_AUTO);	
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
	}
		
	web_reg_find("Text=Order number",LAST);
	
	web_reg_save_param("cp_HOrderNum","LB=<div class=\"secRt\">","RB=</div>", LAST);
	web_reg_save_param("cp_HOrderEmail","LB=<div class=\"secRt bgHighlight lblEmail\">","RB=</div>", LAST);
	
	//lr_start_sub_transaction("S35-3_OrderShippingBillingConfirmationView","S35_SubmitOrder_CC");

	web_submit_data("OrderShippingBillingConfirmationView",
		"Action=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Method=POST", 
		"RecContentType=text/html",		
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_correlationId}&QuoteDisable=N&tld={cp_orderNo}-{cp_time}-10151",
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=shipmentTypeId", "Value=1", ENDITEM, 
		"Name=emailSender", "Value={p_userEmail}", ENDITEM, 
		"Name=sessionKey", "Value=", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=corelID", "Value={cp_correlationId}", ENDITEM, 
		"Name=totalAdjValue", "Value={cp_adjpricenew}.00", ENDITEM, 
		"Name=statId", "Value=", ENDITEM, 
		"Name=gPay", "Value=", ENDITEM, 
		"Name=suspiciousFlag", "Value=", ENDITEM, 
		LAST);
	
//	lr_end_sub_transaction("S35-3_OrderShippingBillingConfirmationView",LR_AUTO);
	
	//lr_start_sub_transaction("S35-4_HPServices","S35_SubmitOrder_CC");
	
	web_url("HPServices_7", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1524723620827&action=cupis&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Snapshot=t86.inf", 
		"Mode=HTML", 
		LAST);	
	
	//lr_end_sub_transaction("S35-4_HPServices",LR_AUTO);
	
	//lr_start_sub_transaction("S35-5_FDPromotionCmd","S35_SubmitOrder_CC");

	web_submit_data("FDPromotionCmd", 
		"Action=https://{p_hostName}/us-en/shop/FDPromotionCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Snapshot=t132.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=requesttype", "Value=ajax", ENDITEM, 
		LAST);
	
	//lr_end_sub_transaction("S35-5_FDPromotionCmd",LR_AUTO);
	
	lr_end_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),LR_AUTO);
	lr_end_transaction("S35_SubmitOrder_CC",LR_AUTO);	
	
	 		
	}	
		else  // Submit order for guest user
	
		{
	web_reg_find("Search=All","SaveCount=c_ManageSub","Text=SUCCESSFUL_SUBSCRIPTION",LAST);
	
	lr_start_transaction("S35_SubmitOrder_CC");	
	lr_start_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),"S35_SubmitOrder_CC");	
	//lr_start_sub_transaction("S35-1_HPManageSubscriptionCmd","S35_SubmitOrder_CC");	
	
	web_submit_data("HPManageSubscriptionCmd", 
		"Action=https://{p_hostName}/us-en/shop/HPManageSubscriptionCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_orderNo}_{cp_time}&QuoteDisable=Y&tld={cp_orderNo}-{cp_time}-10151", 
		"Snapshot=t124.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=emailInput", "Value={p_userEmail}", ENDITEM, 
		"Name=userType", "Value=G", ENDITEM, 
		"Name=subscribeOption", "Value=true", ENDITEM, 
		"Name=firstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=lastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=webSource", "Value=1", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	//lr_end_sub_transaction("S35-1_HPManageSubscriptionCmd",LR_AUTO);	
	
	if(atoi(lr_eval_string("{c_ManageSub}"))>0)
	{

	}
	else
	{
		lr_end_transaction("S35_SubmitOrder_CC",LR_FAIL);		
		lr_end_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),LR_FAIL);	
		Logout();
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	web_reg_find("Search=All","SaveCount=c_OrderStatus","Text=paymentMessage\": \"Order Decline\"",LAST);
	
	//lr_start_sub_transaction("S35-2_OrderSubmitServiceCmd","S35_SubmitOrder_CC");
	
	web_submit_data("OrderSubmitServiceCmd",
		"Action=https://{p_hostName}/us-en/shop/OrderSubmitServiceCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_orderNo}_{cp_time}&QuoteDisable=Y&tld={cp_orderNo}-{cp_time}-10151", 
		"Snapshot=t125.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=shipto_firstname", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=shipto_lastname", "Value={p_LastNameNew}", ENDITEM, 
		"Name=shipto_address1", "Value={p_Address1New}", ENDITEM, 
		"Name=shipto_address2", "Value=", ENDITEM, 
		"Name=shipto_city", "Value={p_CityNew}", ENDITEM, 
		"Name=shipto_state", "Value={p_StateNew}", ENDITEM, 
		"Name=shipto_stateprovince", "Value={p_StateNew}", ENDITEM, 
		"Name=shipto_zipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=shipto_country", "Value=US", ENDITEM, 
		"Name=shipto_phonenumber", "Value={p_PhoneNew}", ENDITEM, 
		"Name=isBusinessPurchase", "Value=false", ENDITEM,
		"Name=shippingContactFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=shippingContactLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=shippingCompanyName", "Value=", ENDITEM, 
		"Name=shippingAddress1", "Value={p_Address1New}", ENDITEM, 
		"Name=shippingAddress2", "Value=", ENDITEM, 
		"Name=shippingCity", "Value={p_CityNew}", ENDITEM, 
		"Name=shippingState", "Value={p_StateNew}", ENDITEM, 
		"Name=shippingZip", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=shippingPhoneNumber", "Value={p_PhoneNew}", ENDITEM, 
		"Name=billingContactFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=billingContactLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=billto_NickName", "Value=", ENDITEM, 
		"Name=billto_firstname", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=billto_lastname", "Value={p_LastNameNew}", ENDITEM, 
		"Name=billto_address1", "Value={p_Address1New}", ENDITEM, 
		"Name=billto_address2", "Value=", ENDITEM, 
		"Name=billto_city", "Value={p_CityNew}", ENDITEM, 
		"Name=billto_state", "Value={p_StateNew}", ENDITEM, 
		"Name=billto_stateprovince", "Value={p_StateNew}", ENDITEM, 
		"Name=billto_zipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=billto_country", "Value=US", ENDITEM, 
		"Name=billto_phone_number", "Value={p_PhoneNew}", ENDITEM, 
		"Name=confirmationEmail", "Value={p_userEmail}", ENDITEM, 
		"Name=addressId", "Value={cp_addressId}", ENDITEM, 
		"Name=logonID", "Value={p_userEmail}", ENDITEM, 
		"Name=safeTechSessionId", "Value=${cp_orderNo}_{cp_time}", ENDITEM, 
		"Name=paymentType", "Value=creditcard", ENDITEM, 
		"Name=isPartnerAgentOrder", "Value=false", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=ormorder", "Value={cp_orderNo}", ENDITEM, 
		"Name=aoID", "Value=", ENDITEM, 
		"Name=taxCheck", "Value=0", ENDITEM, 
		"Name=selectedShipMethod", "Value=12056", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=chkSCLimit", "Value=true", ENDITEM, 
		"Name=policyId", "Value=", ENDITEM, 
		"Name=tmId", "Value={cp_tmid}", ENDITEM,
	//	"Name=tmId", "Value={cp_tmid}", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	//lr_end_sub_transaction("S35-2_OrderSubmitServiceCmd",LR_AUTO);	
	
	if(atoi(lr_eval_string("{c_OrderStatus}"))>0)
	{
		
		web_url("OrderDeclineView", 
		"URL=https://{p_hostName}/us-en/shop/OrderDeclineView?storeId=10151&langId=-1&catalogId=10051&payMethod=Credit&lastFour=4113&ormOrderId={cp_orderNo}&cardName=VISA", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t68.inf", 
		"Mode=HTML", 
		LAST);
		
		lr_end_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),LR_AUTO);		
		lr_end_transaction("S35_SubmitOrder_CC",LR_AUTO);
		
		Logout();
		
		lr_start_transaction("S35-1_SubmitOrder_CC_OrderDecline");		
		lr_end_transaction("S35-1_SubmitOrder_CC_OrderDecline",LR_AUTO);	
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
	}
		
	web_reg_find("Text=Order number",LAST);
	
	web_reg_save_param("cp_HOrderNum","LB=<div class=\"secRt\">","RB=</div>", LAST);
	web_reg_save_param("cp_HOrderEmail","LB=<div class=\"secRt bgHighlight lblEmail\">","RB=</div>", LAST);
	
	//lr_start_sub_transaction("S35-3_OrderShippingBillingConfirmationView","S35_SubmitOrder_CC");

	web_submit_data("OrderShippingBillingConfirmationView",
		"Action=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Method=POST", 
		"RecContentType=text/html",		
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_correlationId}&QuoteDisable=N&tld={cp_orderNo}-{cp_time}-10151",
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=shipmentTypeId", "Value=1", ENDITEM, 
		"Name=emailSender", "Value={p_userEmail}", ENDITEM, 
		"Name=sessionKey", "Value=", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=corelID", "Value={cp_correlationId}", ENDITEM, 
		"Name=totalAdjValue", "Value={cp_adjpricenew}.00", ENDITEM, 
		"Name=statId", "Value=", ENDITEM, 
		"Name=gPay", "Value=", ENDITEM, 
		LAST);
	
	//lr_end_sub_transaction("S35-3_OrderShippingBillingConfirmationView",LR_AUTO);
	
//	lr_start_sub_transaction("S35-4_HPServices","S35_SubmitOrder_CC");
	
	web_url("HPServices_7", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1524723620827&action=cupis&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Snapshot=t86.inf", 
		"Mode=HTML", 
		LAST);	
	
//	lr_end_sub_transaction("S35-4_HPServices",LR_AUTO);
	
//	lr_start_sub_transaction("S35-5_FDPromotionCmd","S35_SubmitOrder_CC");

	web_submit_data("FDPromotionCmd", 
		"Action=https://{p_hostName}/us-en/shop/FDPromotionCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Snapshot=t132.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=requesttype", "Value=ajax", ENDITEM, 
		LAST);
	
	//lr_end_sub_transaction("S35-5_FDPromotionCmd",LR_AUTO);
	
	lr_end_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),LR_AUTO);
	lr_end_transaction("S35_SubmitOrder_CC",LR_AUTO);	
			
	}
	}
	else if(pType==2) // Submit order for EUA user
	{
	
	web_reg_find("Search=All","SaveCount=c_OrderStatus","Text=paymentMessage\": \"Order Decline\"",LAST);
	
	lr_start_transaction("S35_SubmitOrder_CC_SMB");
	
	lr_start_sub_transaction("S35-1_SubmitOrder_CC_SMB_STO","S35_SubmitOrder_CC_SMB");
		
	web_submit_data("OrderSubmitServiceCmd", 
		"Action=https://{p_hostName}/us-en/shop/OrderSubmitServiceCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
	"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t76.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=shipto_firstname", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=shipto_lastname", "Value={p_LastNameNew}", ENDITEM, 
		"Name=shipto_companyname", "Value=", ENDITEM, 
		"Name=shipto_address1", "Value={p_Address1New}", ENDITEM, 
		"Name=shipto_address2", "Value=", ENDITEM, 
		"Name=shipto_city", "Value={p_CityNew}", ENDITEM, 
		"Name=shipto_state", "Value={p_StateNew}", ENDITEM, 
		"Name=shipto_stateprovince", "Value={p_StateNew}", ENDITEM, 
		"Name=shipto_zipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=shipto_country", "Value=US", ENDITEM, 
		"Name=shipto_phonenumber", "Value={p_PhoneNew}", ENDITEM, 
		"Name=isBusinessPurchase", "Value=true", ENDITEM, 
		"Name=shippingContactFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=shippingContactLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=shippingCompanyName", "Value=", ENDITEM, 
		"Name=shippingAddress1", "Value={p_Address1New}", ENDITEM, 
		"Name=shippingAddress2", "Value=", ENDITEM, 
		"Name=shippingCity", "Value={p_CityNew}", ENDITEM, 
		"Name=shippingState", "Value={p_StateNew}", ENDITEM, 
		"Name=shippingZip", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=shippingPhoneNumber", "Value={p_PhoneNew}", ENDITEM, 
		"Name=billingContactFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=billingContactLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=billto_NickName", "Value=EStore_STO_LoggedInCheckout_EUA_{cp_time}", ENDITEM, 
		"Name=billto_firstname", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=billto_lastname", "Value={p_LastNameNew}", ENDITEM, 
		"Name=billto_companyname", "Value=", ENDITEM, 
		"Name=companyinput1", "Value=", ENDITEM, 
		"Name=billto_address1", "Value={p_Address1New}", ENDITEM, 
		"Name=billto_address2", "Value=", ENDITEM, 
		"Name=billto_city", "Value={p_CityNew}", ENDITEM, 
		"Name=billto_state", "Value={p_StateNew}", ENDITEM, 
		"Name=billto_stateprovince", "Value={p_StateNew}", ENDITEM, 
		"Name=billto_zipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=billto_country", "Value=US", ENDITEM, 
		"Name=billto_phone_number", "Value={p_PhoneNew}", ENDITEM, 
		"Name=confirmationEmail", "Value={p_userEmail}", ENDITEM, 
		"Name=addressId", "Value={cp_addressId}", ENDITEM, 
		"Name=logonID", "Value={p_userEmail}", ENDITEM, 
		"Name=gPay", "Value=", ENDITEM, 
		"Name=paymentType", "Value=creditcard", ENDITEM, 
		"Name=suspiciousFlag", "Value=", ENDITEM, 
		"Name=isSmbOrder", "Value=true", ENDITEM, 
		"Name=isPartnerAgentOrder", "Value=false", ENDITEM, 
		"Name=partnerLocId", "Value={cp_PartnerId}", ENDITEM, 
		"Name=partnerRepId", "Value={cp_PartnerId}", ENDITEM, 
		"Name=partnerPO", "Value=", ENDITEM, 
		"Name=partnerName", "Value={cp_PartnerName}", ENDITEM, 
		"Name=partnerCity", "Value={cp_PartnerCity}", ENDITEM, 
		"Name=partnerState", "Value={cp_PartnerState}", ENDITEM, 
		"Name=partnerZip", "Value={cp_PartnerZipCode}", ENDITEM, 
		"Name=orderId", "Value={cp_orderIdNew}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNoNew}", ENDITEM, 
		"Name=ormorder", "Value={cp_orderNoNew}", ENDITEM, 
		"Name=aoID", "Value=", ENDITEM, 
		"Name=taxCheck", "Value=0", ENDITEM, 
		"Name=selectedShipMethod", "Value=12056", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=chkSCLimit", "Value=true", ENDITEM, 
		"Name=policyId", "Value=", ENDITEM, 
		"Name=tmId", "Value={cp_tmid}", ENDITEM, 
		"Name=allowedShipMethodsCodes", "Value=Standard", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	if(atoi(lr_eval_string("{c_OrderStatus}"))>0)
	{
		
		web_url("OrderDeclineView", 
		"URL=https://{p_hostName}/us-en/shop/OrderDeclineView?storeId=10151&langId=-1&catalogId=10051&payMethod=Credit&lastFour=4113&ormOrderId={cp_orderNo}&cardName=VISA", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t68.inf", 
		"Mode=HTML", 
		LAST);
		
		lr_end_sub_transaction("S35-1_SubmitOrder_CC_SMB_STO",LR_AUTO);
		
		lr_end_transaction("S35_SubmitOrder_CC_SMB",LR_AUTO);
		
		Logout();
		
		lr_start_transaction("S35-1_SubmitOrder_CC_OrderDecline");
		
		lr_end_transaction("S35-1_SubmitOrder_CC_OrderDecline",LR_AUTO);
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
	}
	
	web_reg_find("Text=Order number",LAST);

	web_submit_data("OrderShippingBillingConfirmationView", 
		"Action=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Method=POST", 
		"RecContentType=text/html", 
	"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t77.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=orderId", "Value={cp_orderIdNew}", ENDITEM, 
		"Name=shipmentTypeId", "Value=1", ENDITEM, 
		"Name=emailSender", "Value={p_userEmail}", ENDITEM, 
		"Name=sessionKey", "Value=", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=corelID", "Value={cp_correlationIdNew}", ENDITEM, 
		"Name=totalAdjValue", "Value={cp_adjpricenew}.00", ENDITEM, 
		"Name=statId", "Value=", ENDITEM, 
		"Name=gPay", "Value=", ENDITEM, 
		"Name=suspiciousFlag", "Value=", ENDITEM, 
		LAST);

	web_url("HPServices_9", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1598091273529&action=cupids&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Snapshot=t78.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("FDPromotionCmd", 
		"Action=https://{p_hostName}/us-en/shop/FDPromotionCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Snapshot=t79.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderId", "Value={cp_orderIdNew}", ENDITEM, 
		"Name=requesttype", "Value=ajax", ENDITEM, 
		LAST);

	lr_end_sub_transaction("S35-1_SubmitOrder_CC_SMB_STO",LR_AUTO);
	lr_end_transaction("S35_SubmitOrder_CC_SMB",LR_AUTO);
			
	}
	else if(pType==3) // submit order for CC Saved user
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
	
//	web_reg_find("Search=All","SaveCount=c_OrderStatus","Text=paymentMessage\": \"Order Decline\"",LAST);
	
	lr_start_transaction("S35_SubmitOrder_CC");
	
	lr_start_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),"S35_SubmitOrder_CC");
	
//	web_reg_find("Search=All","SaveCount=c_ManageSub","Text=SUCCESSFUL_SUBSCRIPTION",LAST);

	web_reg_find("Search=All","SaveCount=c_OrderStatus","Text=paymentMessage\": \"Order Decline\"",LAST);
		
	web_submit_data("OrderSubmitServiceCmd", 
		"Action=https://{p_hostName}/us-en/shop/OrderSubmitServiceCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_orderNo}_{cp_time}&QuoteDisable=Y&tld={cp_orderNo}-{cp_time}-10151", 
		"Snapshot=t125.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=shipto_firstname", "Value={cp_CurrentFirstName}", ENDITEM, 
		"Name=shipto_lastname", "Value={cp_CurrentLastName}", ENDITEM, 
		"Name=shipto_address1", "Value={cp_CurrentAddress}", ENDITEM, 
		"Name=shipto_address2", "Value=", ENDITEM, 
		"Name=shipto_city", "Value={cp_CurrentCity}", ENDITEM, 
		"Name=shipto_state", "Value={cp_CurrentState}", ENDITEM, 
		"Name=shipto_stateprovince", "Value={cp_CurrentState}", ENDITEM, 
		"Name=shipto_zipcode", "Value={cp_CurrentZipCode}", ENDITEM, 
		"Name=shipto_country", "Value=US", ENDITEM, 
		"Name=shipto_phonenumber", "Value=1234567890", ENDITEM, 
		"Name=isBusinessPurchase", "Value=false", ENDITEM, 
		"Name=shippingContactFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=shippingContactLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=shippingCompanyName", "Value=", ENDITEM, 
		"Name=shippingAddress1", "Value={p_Address1New}", ENDITEM, 
		"Name=shippingAddress2", "Value=", ENDITEM, 
		"Name=shippingCity", "Value={p_CityNew}", ENDITEM, 
		"Name=shippingState", "Value={p_StateNew}", ENDITEM, 
		"Name=shippingZip", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=shippingPhoneNumber", "Value={p_PhoneNew}", ENDITEM, 
		"Name=billingContactFirstName", "Value={cp_CurrentFirstName}", ENDITEM, 
		"Name=billingContactLastName", "Value={cp_CurrentAddress}", ENDITEM, 
		"Name=billto_NickName", "Value=", ENDITEM, 
		"Name=billto_firstname", "Value={cp_CurrentFirstName}", ENDITEM, 
		"Name=billto_lastname", "Value={cp_CurrentAddress}", ENDITEM, 
		"Name=billto_address1", "Value={cp_CurrentAddress}", ENDITEM, 
		"Name=billto_address2", "Value=", ENDITEM, 
		"Name=billto_city", "Value={cp_CurrentCity}", ENDITEM, 
		"Name=billto_state", "Value={cp_CurrentState}", ENDITEM, 
		"Name=billto_stateprovince", "Value={cp_CurrentState}", ENDITEM, 
		"Name=billto_zipcode", "Value={cp_CurrentZipCode}", ENDITEM, 
		"Name=billto_country", "Value=US", ENDITEM, 
		"Name=billto_phone_number", "Value={cp_CurrentPhone}", ENDITEM, 
		"Name=confirmationEmail", "Value={p_userEmail}", ENDITEM, 
		"Name=addressId", "Value={cp_addressId}", ENDITEM, 
		"Name=logonID", "Value={p_userEmail}", ENDITEM, 
		"Name=safeTechSessionId", "Value=${cp_orderNo}_{cp_time}", ENDITEM, 
		"Name=paymentType", "Value=creditcard", ENDITEM, 
		"Name=isPartnerAgentOrder", "Value=false", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=ormorder", "Value={cp_orderNo}", ENDITEM, 
		"Name=aoID", "Value=", ENDITEM, 
		"Name=taxCheck", "Value=0", ENDITEM, 
		"Name=selectedShipMethod", "Value=12056", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=chkSCLimit", "Value=true", ENDITEM, 
		"Name=policyId", "Value=", ENDITEM, 
		"Name=tmId", "Value={cp_tmid}", ENDITEM,
	//	"Name=tmId", "Value={cp_tmid}", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	if(atoi(lr_eval_string("{c_OrderStatus}"))>0)
	{
		
		web_url("OrderDeclineView", 
		"URL=https://{p_hostName}/us-en/shop/OrderDeclineView?storeId=10151&langId=-1&catalogId=10051&payMethod=Credit&lastFour=4113&ormOrderId={cp_orderNo}&cardName=VISA", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t68.inf", 
		"Mode=HTML", 
		LAST);
		
		lr_end_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),LR_AUTO);
		
		lr_end_transaction("S35_SubmitOrder_CC",LR_AUTO);
		
		Logout();
		
		lr_start_transaction("S35-1_SubmitOrder_CC_OrderDecline");
		
		lr_end_transaction("S35-1_SubmitOrder_CC_OrderDecline",LR_AUTO);
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
	}
		
	web_reg_find("Text=Order number",LAST);

	web_submit_data("OrderShippingBillingConfirmationView",
		"Action=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Method=POST", 
		"RecContentType=text/html",		
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_correlationId}&QuoteDisable=N&tld={cp_orderNo}-{cp_time}-10151",
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=shipmentTypeId", "Value=1", ENDITEM, 
		"Name=emailSender", "Value={p_userEmail}", ENDITEM, 
		"Name=sessionKey", "Value=", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=corelID", "Value={cp_correlationId}", ENDITEM, 
		"Name=totalAdjValue", "Value={cp_adjpricenew}.00", ENDITEM, 
		"Name=statId", "Value=", ENDITEM, 
		"Name=gPay", "Value=", ENDITEM, 
		LAST);
		
	web_url("HPServices_7", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1524723620827&action=cupis&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Snapshot=t86.inf", 
		"Mode=HTML", 
		LAST);	

	web_submit_data("FDPromotionCmd", 
		"Action=https://{p_hostName}/us-en/shop/FDPromotionCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Snapshot=t132.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=requesttype", "Value=ajax", ENDITEM, 
		LAST);
	lr_end_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),LR_AUTO);

	lr_end_transaction("S35_SubmitOrder_CC",LR_AUTO);
	}
	else if(pType==4) // Submit order for loyalty user
	{
	lr_start_transaction("S35_SubmitOrder_CC");
	
	lr_start_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),"S35_SubmitOrder_CC");
	
	web_save_timestamp_param("cp_time", LAST);
	
//	web_reg_find("Search=All","SaveCount=c_ManageSub","Text=SUCCESSFUL_SUBSCRIPTION",LAST);

	web_reg_find("Search=All","SaveCount=c_OrderStatus","Text=paymentMessage\": \"Order Decline\"",LAST);

	//lr_start_sub_transaction(lr_eval_string("S35-2_OrderSubmitServiceCmd{cartitem}"),"S35_SubmitOrder_CC");

	web_submit_data("OrderSubmitServiceCmd", 
		"Action=https://{p_hostName}/us-en/shop/OrderSubmitServiceCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_orderNo}_{cp_time}&QuoteDisable=Y&tld={cp_orderNo}-{cp_time}-10151", 
		"Snapshot=t125.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=shipto_firstname", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=shipto_lastname", "Value={p_LastNameNew}", ENDITEM, 
		"Name=shipto_address1", "Value={p_Address1New}", ENDITEM, 
		"Name=shipto_address2", "Value=", ENDITEM, 
		"Name=shipto_city", "Value={p_CityNew}", ENDITEM, 
		"Name=shipto_state", "Value={p_StateNew}", ENDITEM, 
		"Name=shipto_stateprovince", "Value={p_StateNew}", ENDITEM, 
		"Name=shipto_zipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=shipto_country", "Value=US", ENDITEM, 
		"Name=shipto_phonenumber", "Value={p_PhoneNew}", ENDITEM, 
		"Name=isBusinessPurchase", "Value=false", ENDITEM, 
		"Name=shippingContactFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=shippingContactLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=shippingCompanyName", "Value=", ENDITEM, 
		"Name=shippingAddress1", "Value={p_Address1New}", ENDITEM, 
		"Name=shippingAddress2", "Value=", ENDITEM, 
		"Name=shippingCity", "Value={p_CityNew}", ENDITEM, 
		"Name=shippingState", "Value={p_StateNew}", ENDITEM, 
		"Name=shippingZip", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=shippingPhoneNumber", "Value={p_PhoneNew}", ENDITEM, 
		"Name=billingContactFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=billingContactLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=billto_NickName", "Value=", ENDITEM, 
		"Name=billto_firstname", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=billto_lastname", "Value={p_LastNameNew}", ENDITEM, 
		"Name=billto_address1", "Value={p_Address1New}", ENDITEM, 
		"Name=billto_address2", "Value=", ENDITEM, 
		"Name=billto_city", "Value={p_CityNew}", ENDITEM, 
		"Name=billto_state", "Value={p_StateNew}", ENDITEM, 
		"Name=billto_stateprovince", "Value={p_StateNew}", ENDITEM, 
		"Name=billto_zipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=billto_country", "Value=US", ENDITEM, 
		"Name=billto_phone_number", "Value={p_PhoneNew}", ENDITEM, 
		"Name=confirmationEmail", "Value={p_userEmail}", ENDITEM, 
		"Name=addressId", "Value={cp_addressId}", ENDITEM, 
		"Name=logonID", "Value={p_userEmail}", ENDITEM, 
		"Name=safeTechSessionId", "Value=${cp_orderNo}_{cp_time}", ENDITEM, 
		"Name=paymentType", "Value=creditcard", ENDITEM, 
		"Name=isPartnerAgentOrder", "Value=false", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=ormorder", "Value={cp_orderNo}", ENDITEM, 
		"Name=aoID", "Value=", ENDITEM, 
		"Name=taxCheck", "Value=0", ENDITEM, 
		"Name=selectedShipMethod", "Value=12056", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=chkSCLimit", "Value=true", ENDITEM, 
		"Name=policyId", "Value=", ENDITEM, 
		"Name=tmId", "Value={cp_tmid}", ENDITEM,
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=redeemPoints", "Value={p_rewardsApply}", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	//lr_end_sub_transaction(lr_eval_string("S35-2_OrderSubmitServiceCmd{cartitem}"),LR_AUTO);
	
	if(atoi(lr_eval_string("{c_OrderStatus}"))>0)
	{
		
		web_url("OrderDeclineView", 
		"URL=https://{p_hostName}/us-en/shop/OrderDeclineView?storeId=10151&langId=-1&catalogId=10051&payMethod=Credit&lastFour=4113&ormOrderId={cp_orderNo}&cardName=VISA", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t68.inf", 
		"Mode=HTML", 
		LAST);
		
		lr_end_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),LR_AUTO);
		
		lr_end_transaction("S35_SubmitOrder_CC",LR_AUTO);
		
	
		Logout();
		
		lr_start_transaction("S35-1_SubmitOrder_CC_OrderDecline");
		
		lr_end_transaction("S35-1_SubmitOrder_CC_OrderDecline",LR_AUTO);
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
	}
	
	web_reg_find("Text=Thank you for your order",LAST);

	
	//lr_start_sub_transaction(lr_eval_string("S35-3_OrderShippingBillingConfirmationView{cartitem}"),"S35_SubmitOrder_CC");
	
	web_submit_data("OrderShippingBillingConfirmationView",
		"Action=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Method=POST", 
		"RecContentType=text/html",		
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_correlationId}&QuoteDisable=N&tld={cp_orderNo}-{cp_time}-10151",
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=shipmentTypeId", "Value=1", ENDITEM, 
		"Name=emailSender", "Value={p_userEmail}", ENDITEM, 
		"Name=sessionKey", "Value=", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=corelID", "Value={cp_correlationId}", ENDITEM, 
		"Name=totalAdjValue", "Value={cp_adjpricenew}.00", ENDITEM, 
		"Name=statId", "Value=", ENDITEM, 
		"Name=gPay", "Value=", ENDITEM, 
		LAST);
	//lr_end_sub_transaction(lr_eval_string("S35-3_OrderShippingBillingConfirmationView{cartitem}"),LR_AUTO);

//	lr_start_sub_transaction(lr_eval_string("S35-4_HPServices{cartitem}"),"S35_SubmitOrder_CC");

	web_url("HPServices_7", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1524723620827&action=cupis&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Snapshot=t86.inf", 
		"Mode=HTML", 
		LAST);	

	
	//lr_end_sub_transaction(lr_eval_string("S35-4_HPServices{cartitem}"),LR_AUTO);

	//lr_start_sub_transaction(lr_eval_string("S35-5_FDPromotionCmd{cartitem}"),"S35_SubmitOrder_CC");

	web_add_header("Origin", 
		"https://{p_hostName}");

	web_submit_data("FDPromotionCmd", 
		"Action=https://{p_hostName}/us-en/shop/FDPromotionCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Snapshot=t132.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=requesttype", "Value=ajax", ENDITEM, 
		LAST);
		
	//lr_end_sub_transaction(lr_eval_string("S35-5_FDPromotionCmd{cartitem}"),LR_AUTO);
	
	lr_end_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),LR_AUTO);
	
	lr_end_transaction("S35_SubmitOrder_CC",LR_AUTO);
			

	
	lr_think_time(1);
		
	}
	else if(pType==5) // Submit order for loggedIn user except CC Saved and EUA user
	{
		
//	web_reg_find("Search=All","SaveCount=c_ManageSub","Text=SUCCESSFUL_SUBSCRIPTION",LAST);
	
	lr_start_transaction("S35_SubmitOrder_CC");	
	lr_start_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),"S35_SubmitOrder_CC");

	web_reg_find("Search=All","SaveCount=c_OrderStatus","Text=paymentMessage\": \"Order Decline\"",LAST);
	
//	lr_start_sub_transaction("S35-2_OrderSubmitServiceCmd","S35_SubmitOrder_CC");
	
	web_submit_data("OrderSubmitServiceCmd",
		"Action=https://{p_hostName}/us-en/shop/OrderSubmitServiceCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_orderNo}_{cp_time}&QuoteDisable=Y&tld={cp_orderNo}-{cp_time}-10151", 
		"Snapshot=t125.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=shipto_firstname", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=shipto_lastname", "Value={p_LastNameNew}", ENDITEM, 
		"Name=shipto_address1", "Value={p_Address1New}", ENDITEM, 
		"Name=shipto_address2", "Value=", ENDITEM, 
		"Name=shipto_city", "Value={p_CityNew}", ENDITEM, 
		"Name=shipto_state", "Value={p_StateNew}", ENDITEM, 
		"Name=shipto_stateprovince", "Value={p_StateNew}", ENDITEM, 
		"Name=shipto_zipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=shipto_country", "Value=US", ENDITEM, 
		"Name=shipto_phonenumber", "Value={p_PhoneNew}", ENDITEM, 
		"Name=isBusinessPurchase", "Value=false", ENDITEM,
		"Name=shippingContactFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=shippingContactLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=shippingCompanyName", "Value=", ENDITEM, 
		"Name=shippingAddress1", "Value={p_Address1New}", ENDITEM, 
		"Name=shippingAddress2", "Value=", ENDITEM, 
		"Name=shippingCity", "Value={p_CityNew}", ENDITEM, 
		"Name=shippingState", "Value={p_StateNew}", ENDITEM, 
		"Name=shippingZip", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=shippingPhoneNumber", "Value={p_PhoneNew}", ENDITEM, 
		"Name=billingContactFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=billingContactLastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=billto_NickName", "Value=", ENDITEM, 
		"Name=billto_firstname", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=billto_lastname", "Value={p_LastNameNew}", ENDITEM, 
		"Name=billto_address1", "Value={p_Address1New}", ENDITEM, 
		"Name=billto_address2", "Value=", ENDITEM, 
		"Name=billto_city", "Value={p_CityNew}", ENDITEM, 
		"Name=billto_state", "Value={p_StateNew}", ENDITEM, 
		"Name=billto_stateprovince", "Value={p_StateNew}", ENDITEM, 
		"Name=billto_zipcode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=billto_country", "Value=US", ENDITEM, 
		"Name=billto_phone_number", "Value={p_PhoneNew}", ENDITEM, 
		"Name=confirmationEmail", "Value={p_userEmail}", ENDITEM, 
		"Name=addressId", "Value={cp_addressId}", ENDITEM, 
		"Name=logonID", "Value={p_userEmail}", ENDITEM, 
		"Name=safeTechSessionId", "Value=${cp_orderNo}_{cp_time}", ENDITEM, 
		"Name=paymentType", "Value=creditcard", ENDITEM, 
		"Name=isPartnerAgentOrder", "Value=false", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=ormOrderId", "Value={cp_orderNo}", ENDITEM, 
		"Name=ormorder", "Value={cp_orderNo}", ENDITEM, 
		"Name=aoID", "Value=", ENDITEM, 
		"Name=taxCheck", "Value=0", ENDITEM, 
		"Name=selectedShipMethod", "Value=12056", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=chkSCLimit", "Value=true", ENDITEM, 
		"Name=policyId", "Value=", ENDITEM, 
		"Name=tmId", "Value={cp_tmid}", ENDITEM,
	//	"Name=tmId", "Value={cp_tmid}", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	//lr_end_sub_transaction("S35-2_OrderSubmitServiceCmd",LR_AUTO);	
	
	if(atoi(lr_eval_string("{c_OrderStatus}"))>0)
	{
		
		web_url("OrderDeclineView", 
		"URL=https://{p_hostName}/us-en/shop/OrderDeclineView?storeId=10151&langId=-1&catalogId=10051&payMethod=Credit&lastFour=4113&ormOrderId={cp_orderNo}&cardName=VISA", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t68.inf", 
		"Mode=HTML", 
		LAST);
		
		lr_end_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),LR_AUTO);		
		lr_end_transaction("S35_SubmitOrder_CC",LR_AUTO);
		
		Logout();
		
		lr_start_transaction("S35-1_SubmitOrder_CC_OrderDecline");		
		lr_end_transaction("S35-1_SubmitOrder_CC_OrderDecline",LR_AUTO);		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
	}
		
	web_reg_find("Text=Order number",LAST);
	
	web_reg_save_param("cp_HOrderNum","LB=<div class=\"secRt\">","RB=</div>", LAST);
	web_reg_save_param("cp_HOrderEmail","LB=<div class=\"secRt bgHighlight lblEmail\">","RB=</div>", LAST);
	
	//lr_start_sub_transaction("S35-3_OrderShippingBillingConfirmationView","S35_SubmitOrder_CC");

	web_submit_data("OrderShippingBillingConfirmationView",
		"Action=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Method=POST", 
		"RecContentType=text/html",		
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_correlationId}&QuoteDisable=N&tld={cp_orderNo}-{cp_time}-10151",
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=shipmentTypeId", "Value=1", ENDITEM, 
		"Name=emailSender", "Value={p_userEmail}", ENDITEM, 
		"Name=sessionKey", "Value=", ENDITEM, 
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=corelID", "Value={cp_correlationId}", ENDITEM, 
		"Name=totalAdjValue", "Value={cp_adjpricenew}.00", ENDITEM, 
		"Name=statId", "Value=", ENDITEM, 
		"Name=gPay", "Value=", ENDITEM, 
		LAST);
	
	//lr_end_sub_transaction("S35-3_OrderShippingBillingConfirmationView",LR_AUTO);
	
	//lr_start_sub_transaction("S35-4_HPServices","S35_SubmitOrder_CC");
	
	web_url("HPServices_7", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1524723620827&action=cupis&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Snapshot=t86.inf", 
		"Mode=HTML", 
		LAST);	
	
	//lr_end_sub_transaction("S35-4_HPServices",LR_AUTO);
	
	//lr_start_sub_transaction("S35-5_FDPromotionCmd","S35_SubmitOrder_CC");

	web_submit_data("FDPromotionCmd", 
		"Action=https://{p_hostName}/us-en/shop/FDPromotionCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Snapshot=t132.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=requesttype", "Value=ajax", ENDITEM, 
		LAST);
	
	//lr_end_sub_transaction("S35-5_FDPromotionCmd",LR_AUTO);
	
	lr_end_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}"),LR_AUTO);
	lr_end_transaction("S35_SubmitOrder_CC",LR_AUTO);	
	
	
		
	}	
	
	return 0;
}
