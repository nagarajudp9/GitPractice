Cancel()
{
	
	lr_think_time(100);
	
		web_set_sockets_option("SSL_VERSION", "TLS1.2");
		
	web_set_max_html_param_len("9024");
	
	lr_start_transaction("S58_01_OrderStatusPage");
	
	web_reg_save_param("cp_krypto","LB=&krypto=","RB=%3D%3D&ddkey", LAST);
	
	//web_reg_find("Text=orderCancelReturnBtn","savecount=C_CancelCount",LAST);
	
	web_url("OrderValidateCmd", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/OrderValidateCmd?storeId=10151&catalogId=10051&URL=/us/en/OrderStatusFinalResultView?catalogId=10051&langId=-1&storeId=10151&ccFlow=Y&OrderId={p_Corder}&PhoneNoOrEmail={p_Cemail}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
/*	
//web_reg_save_param("cp_krypto","LB=&krypto=","RB=\"", LAST);


	
	web_url("OrderStatusFinalResultView", 
		"URL=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?catalogId=10051&langId=-1&storeId=10151&storeId=10151&krypto={cp_krypto}%3D&ddkey=https%3AOrderValidateCmd", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

web_add_header("X-Requested-With", 		"XMLHttpRequest");
*/	
web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1643369639910&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?catalogId=10051&storeId=10151&storeId=10151&langId=-1&krypto={cp_krypto}%3D&ddkey=https%3AOrderValidateCmd", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);


//if( atoi(lr_eval_string("{C_CancelCount}")) > 0)
//    {
//	
		lr_end_transaction("S58_01_OrderStatusPage",LR_AUTO);
   // }
    //else
    //{
	
    	//lr_end_transaction("S58_01_OrderStatusPage",LR_FAIL);
	
    	//lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
    //}
		
		
	lr_think_time(10);
	
//lr_end_transaction("S58_01_OrderStatusPage", LR_AUTO);


lr_start_transaction("S58_02_CancelOrder");

		web_custom_request("HPOrderCancelCmd", 
		"URL=https://{p_hostName}/us-en/shop/HPOrderCancelCmd", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?catalogId=10051&storeId=10151&storeId=10151&langId=-1&krypto={cp_krypto}%3D&ddkey=https%3AOrderValidateCmd", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=ormOrder={p_Corder}&cancelReason=Duplicate order&cancelComment=Tesing-Perf", 
		LAST);

lr_end_transaction("S58_02_CancelOrder", LR_AUTO);

web_reg_find("Text=cancelStatus == \"Cancelled\"","savecount=C_CancelCount1",LAST);

lr_start_transaction("S58_03_OrderDetails");


web_url("OrderStatusFinalResultView", 
		"URL=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?catalogId=10051&storeId=10151&storeId=10151&langId=-1&krypto={cp_krypto}%3D&ddkey=https%3AOrderValidateCmd", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?catalogId=10051&storeId=10151&storeId=10151&langId=-1&krypto={cp_krypto}%3D&ddkey=https%3AOrderValidateCmd", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);


	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1643369978320&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderStatusFinalResultView?catalogId=10051&storeId=10151&storeId=10151&langId=-1&krypto={cp_krypto}%3D&ddkey=https%3AOrderValidateCmd", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	//lr_end_transaction("S58_03_OrderDetails", LR_AUTO);
	
	if( atoi(lr_eval_string("{C_CancelCount1}")) > 0)
    {
	
		lr_end_transaction("S58_03_OrderDetails",LR_PASS);
    }
    else
    {
	
    	lr_end_transaction("S58_03_OrderDetails",LR_FAIL);
	
    	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
    }
		
	
	
	lr_think_time(10);

	return 0;
}
