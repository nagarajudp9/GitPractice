ConfirmOrder()
{
	
	int cp_adjpricenew,adj;
		long file;
	
	if(strcmp(lr_eval_string("{cp_adjprice}"),"")==0 )
	{
	
	cp_adjpricenew = 0;

	
	}
	else
	{ 
		
	//lr_save_string(string_replace(lr_eval_string("{cp_adjprice}"),",",""),"cp_adjprice");
	
	adj=atoi(lr_eval_string("{cp_adjprice}"));
	
	lr_save_int(adj,"cp_adjpricenew");
		
	}
	
	
	
//	lr_output_message("The value of adj price is %d",cp_adjpricenew);
	
	lr_think_time(120);
	
	lr_start_transaction("S35_SubmitOrder_CC");
	
	lr_start_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}{cartLineitem}"),"S35_SubmitOrder_CC");	
	
	web_save_timestamp_param("cp_time", LAST);
	
	if(LoginFlag == 0)

	{
	
		//lr_start_sub_transaction(lr_eval_string("S35-1_HPManageSubscriptionCmd{cartitem}{cartLineitem}"),"S35_SubmitOrder_CC");
		
		web_submit_data("HPManageSubscriptionCmd", 
		"Action=https://{p_hostName}/us-en/shop/HPManageSubscriptionCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_correlationId}&QuoteDisable=N&tld={cp_orderNo}-{cp_time}-10151", 
		"Snapshot=t35.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=emailInput", "Value={p_userEmail}", ENDITEM, 
		"Name=userType", "Value=G", ENDITEM, 
		"Name=subscribeOption", "Value=true", ENDITEM, 
		"Name=firstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=lastName", "Value=Perf", ENDITEM, 
		"Name=webSource", "Value=1", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
	
	
	//lr_end_sub_transaction(lr_eval_string("S35-1_HPManageSubscriptionCmd{cartitem}{cartLineitem}"),LR_AUTO);
	
	}
	
	web_reg_find("Search=All","SaveCount=c_OrderStatus","Text=paymentMessage\": \"Order Decline\"",LAST);

	//lr_start_sub_transaction(lr_eval_string("S35-2_OrderSubmitServiceCmd{cartitem}{cartLineitem}"),"S35_SubmitOrder_CC");
	
	web_submit_data("OrderSubmitServiceCmd",
		"Action=https://{p_hostName}/us-en/shop/OrderSubmitServiceCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?storeId=10151&langId=-1&calculationUsageId=-1&updatePrices=1&cchost=true&orderId=.&crID={cp_correlationId}&QuoteDisable=N&tld={cp_orderNo}-{cp_time}-10151", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=shipto_firstname", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=shipto_lastname", "Value=Perf", ENDITEM, 
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
		"Name=shippingContactLastName", "Value=Perf", ENDITEM, 
		"Name=shippingAddress1", "Value=57", ENDITEM, 
		"Name=shippingAddress2", "Value=", ENDITEM, 
		"Name=shippingCity", "Value={p_CityNew}", ENDITEM, 
		"Name=shippingState", "Value={p_StateNew}", ENDITEM, 
		"Name=shippingZip", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=shippingPhoneNumber", "Value={p_PhoneNew}", ENDITEM, 
		"Name=billingContactFirstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=billingContactLastName", "Value=Perf", ENDITEM, 
		"Name=billto_NickName", "Value=", ENDITEM, 
		"Name=billto_firstname", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=billto_lastname", "Value=Perf", ENDITEM, 
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
		"Name=isSmbOrder", "Value=false", ENDITEM, 
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
		"Name=paymenttype", "Value=creditcard", ENDITEM, 
		"Name=chkSCLimit", "Value=true", ENDITEM, 
		"Name=policyId", "Value=", ENDITEM, 
		"Name=tmId", "Value={tmId}", ENDITEM, 
		"Name=allowedShipMethodsCodes", "Value=Standard|2Day", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
//lr_end_sub_transaction(lr_eval_string("S35-2_OrderSubmitServiceCmd{cartitem}{cartLineitem}"),LR_AUTO);

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
		
	lr_end_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}{cartLineitem}"),LR_AUTO);
		
		lr_end_transaction("S35_SubmitOrder_CC",LR_AUTO);
		
	
		lr_start_transaction("S35-1_SubmitOrder_CC_OrderDecline");
		
		lr_end_transaction("S35-1_SubmitOrder_CC_OrderDecline",LR_AUTO);
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
		
		if( LoginFlag == 1)
		
	{
		Logout();
	}
		
	}
	
	
	web_reg_find("Text=Order number",LAST);

	//lr_start_sub_transaction(lr_eval_string("S35-3_OrderShippingBillingConfirmationView{cartitem}{cartLineitem}"),"S35_SubmitOrder_CC");
	
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
//lr_end_sub_transaction(lr_eval_string("S35-3_OrderShippingBillingConfirmationView{cartitem}{cartLineitem}"),LR_AUTO);

//lr_start_sub_transaction(lr_eval_string("S35-4_HPServices{cartitem}{cartLineitem}"),"S35_SubmitOrder_CC");
	
	web_url("HPServices_7", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1582255063748&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		LAST);
//lr_end_sub_transaction(lr_eval_string("S35-4_HPServices{cartitem}{cartLineitem}"),LR_AUTO);

	web_add_header("Origin", 
		"https://{p_hostName}");
		
//lr_start_sub_transaction(lr_eval_string("S35-5_FDPromotionCmd{cartitem}{cartLineitem}"),"S35_SubmitOrder_CC");

	web_submit_data("FDPromotionCmd", 
		"Action=https://{p_hostName}/us-en/shop/FDPromotionCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingConfirmationView", 
		"Snapshot=t39.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=requesttype", "Value=ajax", ENDITEM, 
		LAST);
	
//lr_end_sub_transaction(lr_eval_string("S35-5_FDPromotionCmd{cartitem}{cartLineitem}"),LR_AUTO);



	lr_end_sub_transaction(lr_eval_string("S35-1_SubmitOrder_CC{cartitem}{cartLineitem}"),LR_AUTO);
	
	lr_end_transaction("S35_SubmitOrder_CC",LR_AUTO);
	
if( LoginFlag == 1)
		
	{
		Logout();
	}	
	
	lr_think_time(1);
	return 0;
}
