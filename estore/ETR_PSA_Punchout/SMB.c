SMB()
{
	//CC_Punchout();
	
	lr_think_time(10);
	
	//web_set_max_html_param_len("50000");
	
	prandNumber = atoi(lr_eval_string("{p_randomNum}"));
	if(prandNumber<3)
	{
		prandNumber = atoi(lr_eval_string("{p_randomNum}"));
		if(prandNumber<3)
		{
			MyAccounts();
		}
		else if (prandNumber<5)
		{
			MyOrders();
		}
		else
		{
			MyQuotes();
		}
	}
	else
	{
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
		"RecContentType=text/html;charset=UTF-8", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1526314724165&action=cupis&catentryId=&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html;charset=UTF-8", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("GetSMBPrivateAccountUsers", 
		"Action=https://{p_hostName}/us-en/shop/GetSMBPrivateAccountUsers", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html;charset=UTF-8", 
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
	
	if(strcmp(lr_eval_string("{ManageAccount}"),"0")==0)
		{
			lr_end_transaction("CP36_ManageAccounts",LR_FAIL);
			CC_Logout();    		
       		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);

		}
		else
		{
			lr_end_transaction("CP36_ManageAccounts",LR_PASS);
			
		}
	
	lr_think_time(10);
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	lr_start_transaction("CP37_AcctSearch_ByID");
	
	web_reg_find("Text=AccountsByAccountId","SaveCount=AsIdCount",LAST);
	web_reg_save_param("cp_AccountId","LB=\"account_id\": [\"","RB=\"","ORD=ALL","NotFound=Warning",LAST);

	web_submit_data("GetSMBPrivateAccountUsers_2", 
		"Action=https://{p_hostName}/us-en/shop/GetSMBPrivateAccountUsers", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html;charset=UTF-8", 
		"Snapshot=t67.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=actionName", "Value=AccountsByAccountId", ENDITEM, 
		"Name=account_id", "Value={p_as_byIdSmb}", ENDITEM, 
		"Name=accountname", "Value=", ENDITEM, 
		"Name=accountNameType", "Value=is", ENDITEM, 
		"Name=endUserEmailType", "Value=is", ENDITEM, 
		"Name=endUserEmail", "Value=", ENDITEM, 
		"Name=pageIndex", "Value=1", ENDITEM, 
		"Name=fetchSelfAccounts", "Value=", ENDITEM, 
		LAST);
		
		if(atoi(lr_eval_string("{AsIdCount}")) > 0)
		{
			lr_end_transaction("CP37_AcctSearch_ByID",LR_PASS);

		}
		else
		{
			lr_end_transaction("CP37_AcctSearch_ByID",LR_FAIL);
			
			CC_Logout();
       		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
			
		}
	
	pmaxValue = atoi(lr_eval_string("{cp_AccountId_count}"));	
	if(pmaxValue>0)
	{
		prandNumber = (rand() % (pmaxValue))+1;
		sprintf(spara, "{cp_AccountId_%d}",prandNumber);		
		lr_save_string(lr_eval_string(spara),"cp_AccountId");
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");		
		lr_start_transaction("CP38_ViewAccountUsers");
	
		web_reg_find("Text=account_id","SaveCount=ViewAccCount",LAST);
		web_reg_save_param("cp_usersId","LB=\"usersId\": \"","RB=\",","ORD=ALL",LAST);
	
		web_submit_data("GetSMBPrivateAccountUsers_3", 
			"Action=https://{p_hostName}/us-en/shop/GetSMBPrivateAccountUsers", 
			"Method=POST", 
			"RecContentType=text/html;charset=UTF-8", 
			"Snapshot=t40.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=actionName", "Value=GetAccountUsers", ENDITEM, 
			"Name=account_id", "Value={cp_AccountId}", ENDITEM, 
			LAST);
		
			if(atoi(lr_eval_string("{ViewAccCount}")) > 0)
			{
				lr_end_transaction("CP38_ViewAccountUsers",LR_PASS);
			}
			else
			{
				lr_end_transaction("CP38_ViewAccountUsers",LR_FAIL);
				CC_Logout();    		
        lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
			}
	}	
	
	lr_think_time(10);	
		
	pmaxValue = atoi(lr_eval_string("{cp_usersId_count}"));	
	if(pmaxValue>0)
	{
		prandNumber = (rand() % (pmaxValue))+1;
		sprintf(spara, "{cp_usersId_%d}",prandNumber);		
		lr_save_string(lr_eval_string(spara),"cp_usersId");
	}	
	//web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");		
	lr_start_transaction("CP45_PunchoutPsaCustomer");	
	
	web_reg_save_param("cp_orderId","LB=<input type=\"hidden\" name=\"orderId\" id=\"orderId\" value=\"","RB=\"/>","Notfound=warning",LAST);	
	web_reg_save_param("cp_orderItemId","LB=\"productrow\" id=\"cItem","RB=\">","ORD=ALL","Notfound=warning",LAST);		
	
	web_url("browseEstore_2", 
		"URL=https://{p_hostName}/us-en/shop/browseEstore?ccCustId={cp_usersId}", 
		"TargetFrame=", 
		"RecContentType=text/html;charset=UTF-8", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1526640064892&action=cupis&catentryId=726888%2C582661%2C348654%2C139456%2C1641153%2C1632153%2C836219%2C903590%2C726888%2C726326%2C3074457345618730321%2C394302%2C1760658%2C1578653%2C1406669%2C1661651%2C1270659%2C1030653%2C1733652%2C3074457345618488819&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html;charset=UTF-8", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("CP45_PunchoutPsaCustomer", LR_AUTO);
	
	psaFlag=1;	
	
	pmaxValue = atoi(lr_eval_string("{cp_orderItemId_count}"));	
	if(pmaxValue>0)
	{
		RemoveCart();
	}
	
	}
	
	return 0;
}
