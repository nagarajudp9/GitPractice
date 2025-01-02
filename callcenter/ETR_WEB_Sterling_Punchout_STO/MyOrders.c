MyOrders()
{	
	lr_think_time(10);
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
	lr_start_transaction("CP36_ManageAccounts");
	
	web_reg_find("Search=All",
	             "Savecount=ManageAccount",
	             "Text=My Orders",
	             LAST);
	
	web_url("SMBPrivateAccountManagementView", 
		"URL=https://{p_hostName}/us-en/shop/SMBPrivateAccountManagementView?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1526314724165&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("GetSMBPrivateAccountUsers", 
		"Action=https://{p_hostName}/us-en/shop/GetSMBPrivateAccountUsers", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=actionName", "Value=AllAccountsBySalesRep", ENDITEM, 
		"Name=account_id", "Value=", ENDITEM, 
		"Name=accountname", "Value=", ENDITEM, 
		"Name=accountNameType", "Value=is", ENDITEM, 
		"Name=endUserEmailType", "Value=is", ENDITEM, 
		"Name=endUserEmail", "Value=", ENDITEM, 
		"Name=pageIndex", "Value=1", ENDITEM, 
		"Name=fetchSelfAccounts", "Value=true", ENDITEM, 
		LAST);
	
	if(strcmp(lr_eval_string("{ManageAccount}"),"1")==0)
		{
			lr_end_transaction("CP36_ManageAccounts",LR_PASS);

		}
		else
		{
			lr_end_transaction("CP36_ManageAccounts",LR_FAIL);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}
	
	lr_think_time(10);
	
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
	lr_start_transaction("CP39_MyOrders");
	
	//web_reg_find("Text=Order status","SaveCount=MyOrdersCount",LAST);

	/*web_url("PunchoutOrdersView", 
		"URL=https://{p_hostName}/us-en/shop/PunchoutOrdersView?storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1526369812046&action=cupis&catentryId=&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);*/
	web_url("PunchoutOrdersView", 
		"URL=https://{p_hostName}/us-en/shop/PunchoutOrdersView?storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop/SMBPrivateAccountManagementView?catalogId=10051&langId=-1&storeId=10151",		
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_3", 
		//"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1526369812046&action=cupis&catentryId=&modelId=",
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1628515038140&action=cupids&catentryId=&modelId=&retainPOCart=false",		
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop/PunchoutOrdersView?storeId=10151&catalogId=10051",		
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);
	
	//if(atoi(lr_eval_string("{MyOrdersCount}")) > 0)
		//{
			lr_end_transaction("CP39_MyOrders",LR_PASS);

		//}
		//else
		//{
			//lr_end_transaction("CP39_MyOrders",LR_FAIL);
			//lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		//}
		
	lr_think_time(10);
	
	prandNumber = atoi(lr_eval_string("{p_randomNum}"));
	if(prandNumber<10)
	{
	
		web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
		
	lr_start_transaction("CP40_OS_ByNo");
	
	web_reg_find("Text=orderNo","SaveCount=OsNoCount",LAST);
	web_reg_save_param("cp_OrderNo","LB=\"orderNo\": \"","RB=\",","ORD=ALL","NotFound=Warning",LAST);
	web_reg_save_param("cp_MemberId","LB=\"memberId\": \"","RB=\",","ORD=ALL","NotFound=Warning",LAST);

	web_submit_data("GetPunchoutOrders", 
		"Action=https://{p_hostName}/us-en/shop/GetPunchoutOrders", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=extOrderId", "Value={p_os_byNo}", ENDITEM, 
		"Name=emailId", "Value=", ENDITEM, 
		"Name=accName", "Value=", ENDITEM, 
		"Name=fromDate", "Value=", ENDITEM, 
		"Name=toDate", "Value=", ENDITEM, 
		"Name=pageIndex", "Value=1", ENDITEM, 
		"Name=status", "Value=", ENDITEM, 
		"Name=partnerLocId", "Value=", ENDITEM, 
		"Name=subsidyEnabled", "Value=false", ENDITEM, 
		"Name=emailMatchingCondition", "Value=is", ENDITEM, 
		"Name=accNameMatchingCondition", "Value=is", ENDITEM, 
		LAST);	
	
	if(atoi(lr_eval_string("{OsNoCount}")) > 0)
		{
			lr_end_transaction("CP40_OS_ByNo",LR_PASS);

		}
		else
		{
			lr_end_transaction("CP40_OS_ByNo",LR_FAIL);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	
		}
		
	}
	else 
	{
		
	/*lr_start_transaction("CP40_OS_ByDate");
	
	web_reg_find("Text=orderNo","SaveCount=OsNoCount",LAST);
	web_reg_save_param("cp_OrderNo","LB=\"orderNo\": \"","RB=\",","ORD=ALL","NotFound=Warning",LAST);
	web_reg_save_param("cp_MemberId","LB=\"memberId\": \"","RB=\",","ORD=ALL","NotFound=Warning",LAST);
	
	web_submit_data("GetPunchoutOrders_2", 
		"Action=https://{p_hostName}/us-en/shop/GetPunchoutOrders", 
		"Method=POST", 
		"TargetFrame=", 		
		"RecContentType=text/html", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=extOrderId", "Value=", ENDITEM, 
		"Name=emailId", "Value=", ENDITEM, 
		"Name=accName", "Value=", ENDITEM, 
		"Name=fromDate", "Value={p_searchByStartDate}", ENDITEM, 
		"Name=toDate", "Value={p_searchByEndDate}", ENDITEM, 
		"Name=pageIndex", "Value=1", ENDITEM, 
		"Name=status", "Value=", ENDITEM, 
		"Name=partnerLocId", "Value=", ENDITEM, 
		"Name=subsidyEnabled", "Value=false", ENDITEM, 
		"Name=emailMatchingCondition", "Value=is", ENDITEM, 
		"Name=accNameMatchingCondition", "Value=is", ENDITEM, 
		LAST);
	
	if(atoi(lr_eval_string("{OsNoCount}")) > 0)
		{
			lr_end_transaction("CP40_OS_ByDate",LR_PASS);

		}
		else
		{
			lr_end_transaction("CP40_OS_ByDate",LR_FAIL);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	
		}*/
	
	}
	
	if(atoi(lr_eval_string("{cp_MemberId_count}"))==0)
		{
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);

		}
	
	pmaxValue = atoi(lr_eval_string("{cp_OrderNo_count}"));	
	if(pmaxValue>0)
	{
		prandNumber = (rand() % (pmaxValue))+1;
		sprintf(spara, "{cp_OrderNo_%d}",prandNumber);	
		sprintf(parakey, "{cp_MemberId_%d}",prandNumber);			
		lr_save_string(lr_eval_string(spara),"cp_OrderNo");
		lr_save_string(lr_eval_string(parakey),"cp_MemberId");	
		web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");

		lr_start_transaction("CP41_ViewOrder");
	
		//web_reg_find("Text=Order Number<span><strong>H","SaveCount=ViewOrderCount",LAST);
	
		web_url("browseEstore_2", 
			"URL=https://{p_hostName}/us-en/shop/browseEstore?punchoutOrderNo={cp_OrderNo}&ccCustId={cp_MemberId}&storeId=10151&catalogId=10051", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Snapshot=t63.inf", 
			"Mode=HTML", 
			LAST);
	
		web_url("HPServices_7", 
			"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1526370447336&action=cupis&catentryId=&modelId=&retainPOCart=false", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Snapshot=t64.inf", 
			"Mode=HTML", 
			LAST);
		
		//if(atoi(lr_eval_string("{ViewOrderCount}")) > 0)
		//	{
				lr_end_transaction("CP41_ViewOrder",LR_PASS);
		//	}
		//	else
		//	{
		//		lr_end_transaction("CP41_ViewOrder",LR_FAIL);
		//		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		//	}		
	}	
	
	lr_think_time(10);
	
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
	
	return 0;
}
