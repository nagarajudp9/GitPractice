AddToCart_STO()
{
	lr_think_time(60);

	if (nFound > 0)
	{

	}
	else
	{ 
	web_reg_save_param("cp_cartOrderId","LB=orderId\": [\"","RB=\"]","NOTFOUND=warning",LAST);
	
	web_reg_save_param("cp_orderItemId","LB=\"orderItemId\": [\"","RB=\"],","ORD=ALL","NOTFOUND=warning",LAST);
	
	if(CarepackFlag==1)
	{
	
	lr_start_transaction("S22_AddToCart_CP");

	web_submit_data("AddToCartAjax", 
			"Action=https://{p_hostName}/us-en/shop/AddToCartAjax", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=",
			"Snapshot=t19.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=storeId", "Value=10151", ENDITEM, 
			"Name=catalogId", "Value=10051", ENDITEM, 
			"Name=langId", "Value=-1", ENDITEM, 
			"Name=orderId", "Value=.", ENDITEM, 
			"Name=calculationUsage", "Value=-1,-2,-5,-6,-7", ENDITEM, 
			"Name=inventoryValidation", "Value=true", ENDITEM, 
			"Name=URL", "Value=", ENDITEM, 
			"Name=updatePrices", "Value=1", ENDITEM, 
			"Name=isGC", "Value=N", ENDITEM, 
			"Name=catEntryId", "Value={cp_catentry_id}", ENDITEM, 
			"Name=quantity", "Value=1", ENDITEM, 
			"Name=elgblSku", "Value=56784899", ENDITEM, 
			"Name=requesttype", "Value=ajax", ENDITEM, 
			LAST);
		
	web_reg_save_param("cp_iCount","LB=iCount\": ","RB=,",LAST);
		
	web_url("HPServices_4", 
			"URL=https://{p_hostName}/us-en/shop/HPServices?_=1644907542220&action=c&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051",
			"Resource=0", 
			"RecContentType=text/html", 
			//"Referer=https://{p_hostName}/us-en/shop/TopCategoriesDisplayView?catalogId=10051&langId=-1&storeId=10151&currentPage=SigninPage", 
			 "Referer=",
			"Snapshot=t54.inf",
			"Mode=HTML", 
			LAST);
			
	lr_end_transaction("S22_AddToCart_CP",LR_AUTO);
		
	}
	
	else if ( Preorder == 1)
		
	{
		
		lr_start_transaction("S22_AddToCart_PreOrder");

	web_submit_data("AddToCartAjax", 
		"Action=https://{p_hostName}/us-en/shop/AddToCartAjax", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDPpre}", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=orderId", "Value=.", ENDITEM, 
		"Name=calculationUsage", "Value=-1,-2,-5,-6,-7", ENDITEM, 
		"Name=inventoryValidation", "Value=true", ENDITEM, 
		"Name=URL", "Value=", ENDITEM, 
		"Name=updatePrices", "Value=1", ENDITEM, 
		"Name=isGC", "Value=N", ENDITEM, 
		"Name=catEntryId", "Value={cp_catentry_id}", ENDITEM, 
		"Name=quantity", "Value=1", ENDITEM, 
		"Name=isPreOrder", "Value=true", ENDITEM, 
		"Name=requesttype", "Value=ajax", ENDITEM, 
		LAST);
		
		lr_end_transaction("S22_AddToCart_PreOrder",LR_AUTO);
		
		lr_start_transaction("S27-1_Checkout_Guest_PreOrder");

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
	web_reg_save_param("cp_correlationId","LB=<input type=\"hidden\" id=\"correlationId\" name=\"correlationId\" value=\"","RB=\"/>","Notfound=warning",LAST);
	web_reg_save_param("cp_addressId","LB=data-addr=\"","RB=\"","Notfound=warning",LAST);
	web_reg_save_param("cp_orderNo","LB=<input type=\"hidden\" id=\"ormOrderId\" value=\"","RB=\"/>","Notfound=warning",LAST);
	//<input type="hidden" name="orderId" value="65767737367126"/>
	web_reg_save_param("cp_orderId","LB=<input type=\"hidden\" name=\"orderId\" value=\"","RB=\"/>","Notfound=warning",LAST);
	//<input type="hidden" id="ormOrderId" value="H3012751052"/>
	web_reg_save_param("cp_PMTId","LB=data-pmt=\"","RB=\"","Notfound=warning",LAST);
	//<input type="hidden" id="tmId" value="H3012751052_1632113755917"/>
	web_reg_save_param("cp_tmid","lb=<input type=\"hidden\" id=\"tmId\" value=\"","rb=\"/>","notfound=warning",LAST);

	web_reg_save_param_ex("ParamName=cp_EstGrandTotal","LB=EstGrandTotal\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_TotalTaxAmount","LB=TotalTaxAmount\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Price","LB=Item_Price\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Name","LB=Item_Name\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Code","LB=Item_Code\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_url("OrderShippingBillingView",
		"URL=https://{p_hostName}/us-en/shop/OrderShippingBillingView?calculationUsageId=-1&calculationUsageId=-4&catalogId=10051&orderId=.&updatePrices=1&storeId=10151&langId=-1&shipmentType=single", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/{p_PDPpre}", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param("cp_iCount","LB=iCount\": ","RB=,",LAST);

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1632113762502&action=cupids&catentryId=&modelId=&retainPOCart=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?calculationUsageId=-1&calculationUsageId=-4&catalogId=10051&orderId=.&updatePrices=1&storeId=10151&langId=-1&shipmentType=single", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
		
	lr_end_transaction("S27-1_Checkout_Guest_PreOrder", LR_AUTO);

	
	
		
	}

	else
	{
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1"); 	
	
	lr_start_transaction(lr_eval_string("S22_AddToCart{cartitem}"));

	web_submit_data("AddToCartAjax", 
			"Action=https://{p_hostName}/us-en/shop/AddToCartAjax", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=",
			"Snapshot=t19.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=storeId", "Value=10151", ENDITEM, 
			"Name=catalogId", "Value=10051", ENDITEM, 
			"Name=langId", "Value=-1", ENDITEM, 
			"Name=orderId", "Value=.", ENDITEM, 
			"Name=calculationUsage", "Value=-1,-2,-5,-6,-7", ENDITEM, 
			"Name=inventoryValidation", "Value=true", ENDITEM, 
			"Name=URL", "Value=", ENDITEM, 
			"Name=updatePrices", "Value=1", ENDITEM, 
			"Name=isGC", "Value=N", ENDITEM, 
			"Name=catEntryId", "Value={cp_catentry_id}", ENDITEM, 
			"Name=quantity", "Value=1", ENDITEM, 
			"Name=requesttype", "Value=ajax", ENDITEM, 
			LAST);
	
	web_reg_save_param("cp_iCount","LB=iCount\": ","RB=,",LAST);
	
	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1644907542220&action=c&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 		
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/TopCategoriesDisplayView?catalogId=10051&langId=-1&storeId=10151&currentPage=SigninPage", 
		 "Referer=",
		"Snapshot=t54.inf",
		"Mode=HTML", 
		LAST);
		
	lr_end_transaction(lr_eval_string("S22_AddToCart{cartitem}"),LR_AUTO);
	}
	
	}
	
	return 0;
}
