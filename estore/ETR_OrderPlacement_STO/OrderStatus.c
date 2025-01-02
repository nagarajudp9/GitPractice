OrderStatus()
{
	
	int Hcount;
	
	lr_think_time(60);
	
	if(orderflag==1)
		
	{	

	web_save_timestamp_param("cp_time", LAST);
	
	lr_start_transaction("S63_MyAccount");

	web_url("MyAccountPage", 
		"URL=https://{p_hostName}/us-en/shop/MyAccountFormView?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_={cp_time}&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyOrdersView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("S63_MyAccount",LR_AUTO);

web_reg_save_param("cp_Horders","LB=Processing\"},{\"ormOrder\":\"","RB=\",\"grandTotal","ORD=ALL","Notfound=Warning",LAST);
	
	lr_start_transaction("S56_MyOrders_WithOrders");

	web_url("MyOrdersView", 
		"URL=https://{p_hostName}/us-en/shop/MyOrdersView?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t81.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("HPServices_8", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1524723754863&action=cupis&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyOrdersView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t134.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("S56_MyOrders_WithOrders",LR_AUTO);

	
	Hcount=atoi(lr_eval_string("{cp_Horders_count}"));
	
	if(Hcount == 0)
	{
	
	}
	
	else
		
	{
		lr_save_string(lr_paramarr_random("cp_Horders"),"cp_Horders");
		
		web_reg_save_param("cp_HPartNum","LB=partNum=","RB=}","Notfound=Warning",LAST);
	
	web_url("MyOrdersView_2",
		"URL=https://{p_hostName}/us-en/shop/MyOrdersView?catalogId=10051&langId=-1&storeId=10151&extOrderId={cp_Horders}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyOrdersView?catalogId=10051&storeId=10151&langId=-1", 
		"Snapshot=t134.inf", 
		"Mode=HTML", 
		LAST);

web_save_timestamp_param("cp_time", LAST);

	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_={cp_time}&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyOrdersView?catalogId=10051&langId=-1&storeId=10151&extOrderId={cp_Horders}", 
		"Snapshot=t141.inf", 
		"Mode=HTML", 
		LAST);

lr_start_transaction("S43_CreateCase");


	web_custom_request("CustomerPortalCmd_2", 
		"URL=https://{p_hostName}/us-en/shop/CustomerPortalCmd", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyOrdersView?catalogId=10051&langId=-1&storeId=10151&extOrderId={cp_Horders}", 
		"Snapshot=t201.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=caseDetails=[{\"TypeOfIssue\":\"Delivery Problem, Lost/Stolen\",\"Issuedetail\":\"Damaged/Wrong Shipment\",\"Description\":\"PerfTesting\",\"ProductNumber\":\"{cp_HPartNum}\",\"OrderNumber\":\"{cp_Horders}\",\"Quantity\":\"1\",\"CustomerName\":\"CC Perf\",\"HPSentoutcome\":\" \",\"URLWebPage\":\" \",\"HPMessage\":\" \",\"Customeremail\":\"{p_gsUser}\"}]&caseFlow=createCase", 
		LAST);

web_save_timestamp_param("cp_time", LAST);

	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_={cp_time}&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyCaseView?catalogId=10051&storeId=10151&langId=-1", 
		"Snapshot=t225.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("S43_CreateCase", LR_AUTO);

	
	lr_start_transaction("S43_Mycases");
	
	web_url("MyCaseView", 
		"URL=https://{p_hostName}/us-en/shop/MyCaseView?catalogId=10051&storeId=10151&langId=-1", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/MyAccountFormView?catalogId=10051&storeId=10151&langId=-1&krypto={cp_Krypto}&currentPage=SigninPage&ddkey=https%3AETRLogonFlow", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_={cp_time}&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyCaseView?catalogId=10051&storeId=10151&langId=-1", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_save_param("cp_CaseNumbers","LB=CaseNumber\": \"","RB=\",","ORD=ALL","Notfound=Warning",LAST);
	
	web_submit_data("CustomerPortalCmd", 
		"Action=https://{p_hostName}/us-en/shop/CustomerPortalCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyCaseView?catalogId=10051&storeId=10151&langId=-1", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=caseFlow", "Value=getCases", ENDITEM, 
		LAST);

lr_end_transaction("S43_Mycases", LR_AUTO);


	}

	
	}
	
	return 0;
}
