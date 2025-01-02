Return()
{

	
	
	lr_think_time(100);
	
		web_set_sockets_option("SSL_VERSION", "TLS1.2");
		
	web_set_max_html_param_len("9024");
	
	/*S57_01_ReturnsInformation*/
	
	web_reg_find("Text=START A RETURN","savecount=C_StartCount",LAST);

	lr_start_transaction("S57_01_ReturnsInformation");

		web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("ContentView", 
		"URL=https://{p_hostName}/us-en/shop/ContentView?eSpotName=ReturnsandExchanges&catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("HPServices_1", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1612374958995&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cv/returnsandexchanges", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	
	if( atoi(lr_eval_string("{C_StartCount}")) > 0)
    {
	
		lr_end_transaction("S57_01_ReturnsInformation",LR_PASS);
    }
    else
    {
	
    	lr_end_transaction("S57_01_ReturnsInformation",LR_FAIL);
	
    	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
    }
	
	/*S57_02_StartReturn*/

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_start_transaction("S57_02_StartReturn");

	
	web_url("MyOrdersLanding", 
		"URL=https://{p_hostName}/us-en/shop/MyOrdersLanding?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cv/returnsandexchanges", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1612374981291&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyAccountOrderStatusView?catalogId=10051&langId=-1&storeId=10151&ddkey=https%3AMyOrdersLanding", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://{p_hostName}");

	lr_end_transaction("S57_02_StartReturn", LR_AUTO);

	
	/*S57_03_OrderStatus*/
	
	
	
	lr_start_transaction("S57_03_OrderStatus");

	
	web_reg_save_param("cp_krypto","LB=&krypto=","RB=\"", LAST);
	web_reg_save_param("cp_essentialData","LB=\"essentialData\" value=\"","RB=\"", LAST);

	web_add_header("Upgrade-Insecure-Requests", 
		"1");
	
	web_url("OrderValidateCmd", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/OrderValidateCmd?storeId=10151&catalogId=10051&URL=/us-en/shop/OrderStatusFinalResultView?catalogId=10051&langId=-1&storeId=10151&ccFlow=Y&OrderId={p_RorderNumber}&PhoneNoOrEmail={p_ReturnEmail}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");


web_reg_save_param("cp_krypto","LB=&krypto=","RB=\"", LAST);

//web_reg_find("Text=Return Item(s)","savecount=C_RItemsCount",LAST);
	
	web_url("OrderStatusFinalResultView", 
		"URL=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?catalogId=10051&langId=-1&storeId=10151&storeId=10151&krypto={cp_krypto}%3D&ddkey=https%3AOrderValidateCmd", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("HPServices_15", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1612375242807&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?catalogId=10051&langId=-1&storeId=10151&storeId=10151&krypto={cp_krypto}%3D&ddkey=https%3AOrderValidateCmd", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);



web_add_auto_header("Origin",
		"https://{p_hostName}");


	//if( atoi(lr_eval_string("{C_RItemsCount}")) > 0)
    //{
	
		lr_end_transaction("S57_03_OrderStatus",LR_AUTO);
    //}
    //else
    //{
	
    	//lr_end_transaction("S57_03_OrderStatus",LR_FAIL);
	
    	//lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
    //}
		
	/*S57_04_ReturnItems*/
	
	lr_think_time(10);

	lr_start_transaction("S57_04_ReturnItems");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_reg_save_param("cp_OrderLineKey","LB=\"OrderLineKey\": \"","RB=\"", "Notfound=warning",LAST);
	
	web_reg_save_param("cp_ItemID","LB=\"ItemID\": \"","RB=\"", "Notfound=warning",LAST);
	
	web_submit_data("HPReturnsCmd", 
		"Action=https://{p_hostName}/us-en/shop/HPReturnsCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?storeId=10151&storeId=10151&catalogId=10051&langId=-1&krypto={cp_krypto}&ddkey=https%3AOrderValidateCmd", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=essentialData", "Value={cp_essentialData}", ENDITEM, 
		"Name=ormOrder", "Value={p_RorderNumber}", ENDITEM, 
		"Name=subscription", "Value=0", ENDITEM, 
		"Name=action", "Value=getOrderDetailsForReturn", ENDITEM, 
		LAST);
	
	
	lr_end_transaction("S57_04_ReturnItems", LR_AUTO);

	/*S57_05_RequestReturn*/
	
	lr_think_time(10);
	
	
	lr_start_transaction("S57_05_RequestReturn");



	web_revert_auto_header("Origin");

	web_revert_auto_header("X-Requested-With");

	web_add_header("Origin", 
		"https://{p_hostName}");
	
web_custom_request("HPReturnsCmd_2", 
		"URL=https://{p_hostName}/us-en/shop/HPReturnsCmd", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?storeId=10151&storeId=10151&catalogId=10051&langId=-1&krypto={cp_krypto}8&ddkey=https%3AOrderValidateCmd", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=essentialData={cp_essentialData}&returnData={\"OrderNo\":\"{p_RorderNumber}\",\"Notes\":{\"Note\":{\"NoteText\":\"Testing\"}},\"Extn\":{\"ExtnReturnType\":\"N\"},\"OrderLines\":{\"OrderLine\":[{\"OrderedQty\":\"1\",\"ReturnReason\":\"3\",\"DerivedFrom\":{\"OrderLineKey\":\"{cp_OrderLineKey}\"},\"ItemDetails\":{\"ItemID\":\""
		"{cp_ItemID}\"},\"Extn\":{\"ExtnReturnCondition\":\"Arrived Damaged:Product damaged, but box OK\",\"ExtnSerialNo\":\"\"}}]}}&action=summaryReturnOrder", 
		LAST);

	
	web_reg_save_param("cp_ReturnOrder","LB=\"OrderNo\": \"","RB=\"","Notfound=warning",LAST);
	
	web_custom_request("HPReturnsCmd_3", 
		"URL=https://{p_hostName}/us-en/shop/HPReturnsCmd", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?storeId=10151&storeId=10151&catalogId=10051&langId=-1&krypto={cp_krypto}&ddkey=https%3AOrderValidateCmd", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=essentialData={cp_essentialData}&returnData={\"OrderNo\":\"{p_RorderNumber}\",\"Notes\":{\"Note\":{\"NoteText\":\"Testing\"}},\"Extn\":{\"ExtnReturnType\":\"N\"},\"OrderLines\":{\"OrderLine\":[{\"OrderedQty\":\"1\",\"ReturnReason\":\"3\",\"DerivedFrom\":{\"OrderLineKey\":\"{cp_OrderLineKey}\"},\"ItemDetails\":{\"ItemID\":\""
		"{cp_ItemID}\"},\"Extn\":{\"ExtnReturnCondition\":\"Arrived Damaged:Product damaged, but box OK\",\"ExtnSerialNo\":\"\"}}]}}&action=createReturnOrder", 
		LAST);

	lr_end_transaction("S57_05_RequestReturn", LR_AUTO);

	/*S57_06_ViewOrderDetails*/
	
	lr_think_time(60);
	
web_reg_find("Text=inProgress","savecount=C_RConfirmCount",LAST);
	
lr_start_transaction("S57_06_ViewOrderDetails");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("OrderStatusFinalResultView_2", 
		"URL=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?catalogId=10051&langId=-1&storeId=10151&storeId=10151&krypto={cp_krypto}%3D&ddkey=https%3AOrderValidateCmd", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?catalogId=10051&langId=-1&storeId=10151&storeId=10151&krypto={cp_krypto}%3D&ddkey=https%3AOrderValidateCmd", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("HPServices_16", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1612375365777&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?catalogId=10051&langId=-1&storeId=10151&storeId=10151&krypto={cp_krypto}%3D&ddkey=https%3AOrderValidateCmd", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);

if( atoi(lr_eval_string("{C_RConfirmCount}")) > 0)
    {
	
		lr_end_transaction("S57_06_ViewOrderDetails",LR_PASS);
    }
    else
    {
	
    	lr_end_transaction("S57_06_ViewOrderDetails",LR_FAIL);
	
    	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
    }
	
    lr_think_time(100);
    
	return 0;
}