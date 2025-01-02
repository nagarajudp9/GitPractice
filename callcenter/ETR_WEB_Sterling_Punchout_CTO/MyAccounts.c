MyAccounts()
{
	lr_think_time(10);
		
		web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	lr_start_transaction("CP36_ManageAccounts");
	
	web_reg_find("Search=All",
	             "Savecount=ManageAccount",
	             "Text=My Orders",
	             LAST);
	web_reg_save_param("cp_krypto","LB=krypto=","RB=&ddkey","Notfound=warning",LAST);
	/*web_url("SMBPrivateAccountManagementView", 
		"URL=https://perf.store.hp.com/us-en/shop/SMBPrivateAccountManagementView?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://perf.store.hp.com/us-en/shop/TopCategoriesDisplay?storeId=10151&catalogId=10051&langId=-1&krypto=Cv5Z37LTiqMMQK2QtFY%2BeaQcMkHGf6K3%2BTAxEWvx5WUK2c4uKKbQW%2F8H7h13yMI1oDzYB7AZN8ZzyDbaBG3eCY6pZVSP3PdtE8usxetQZ8DYdPKx6HipB0M8s0C2KAo1PBzLGsPkC9w2ahFK3ZBJHrRsrpKwumkKCm8hm3yBmqPp2VyEj20OzPcTgQz30w3ngVgDWDwwjFI6gyUw43LOYmSBVtOC2Re4QczMStnZbzQlIUoooMoKjkb87B5wwpCBB1vMlm1sDu2MYrRvoEa2GGdGZCVP%2FA0bEDfOrdtosp0%3D&ddkey=https%3Acclogon", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);*/
	
	web_url("SMBPrivateAccountManagementView", 
		"URL=https://{p_hostName}/us-en/shop/SMBPrivateAccountManagementView?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop/TopCategoriesDisplay?storeId=10151&catalogId=10051&langId=-1&krypto={cp_krypto}3D&ddkey=https%3Acclogon",		
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

	prandNumber = atoi(lr_eval_string("{p_randomNum}"));
	if(prandNumber<5)
	{
		web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	lr_start_transaction("CP37_AcctSearch_ByID");
	
	web_reg_find("Text=AccountsByAccountId","SaveCount=AsIdCount",LAST);
	web_reg_save_param("cp_AccountId","LB=\"account_id\": \"","RB=\",","ORD=ALL","NotFound=Warning",LAST);

	web_submit_data("GetSMBPrivateAccountUsers_2", 
		"Action=https://{p_hostName}/us-en/shop/GetSMBPrivateAccountUsers", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Snapshot=t67.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=actionName", "Value=AccountsByAccountId", ENDITEM, 
		"Name=account_id", "Value={p_as_byId}", ENDITEM, 
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
			lr_end_transaction("CP37_AcctSearch_ByID",LR_PASS);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
			
		}
	
	}
	
	else if(prandNumber<8)
		
	{		
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");			
	lr_start_transaction("CP37_AcctSearch_ByName");
	
	web_reg_find("Text=AccountsByAccountName","SaveCount=AsNameCount",LAST);
	web_reg_save_param("cp_AccountId","LB=\"account_id\": \"","RB=\",","ORD=ALL","NotFound=Warning",LAST);
	
	web_submit_data("GetSMBPrivateAccountUsers_4", 
		"Action=https://{p_hostName}/us-en/shop/GetSMBPrivateAccountUsers", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Snapshot=t81.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=actionName", "Value=AccountsByAccountName", ENDITEM, 
		"Name=account_id", "Value=", ENDITEM, 
		"Name=accountname", "Value={p_as_byName}", ENDITEM, 
		"Name=accountNameType", "Value=is", ENDITEM, 
		"Name=endUserEmailType", "Value=is", ENDITEM, 
		"Name=endUserEmail", "Value=", ENDITEM, 
		"Name=pageIndex", "Value=1", ENDITEM, 
		"Name=fetchSelfAccounts", "Value=", ENDITEM, 
		LAST);

		if(atoi(lr_eval_string("{AsNameCount}")) > 0)
		{
			lr_end_transaction("CP37_AcctSearch_ByName",LR_PASS);

		}
		else
		{
			lr_end_transaction("CP37_AcctSearch_ByName",LR_AUTO);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
		}
	
	}
				
	else 
	{
		web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");	
	//lr_start_transaction("CP37_AcctSearch_ByEmail");

	web_reg_find("Text=AccountsByEndUserEmai","SaveCount=AsEmailCount",LAST);
	web_reg_save_param("cp_AccountId","LB=\"account_id\": \"","RB=\",","ORD=ALL","NotFound=Warning",LAST);

	web_submit_data("GetSMBPrivateAccountUsers_5", 
		"Action=https://{p_hostName}/us-en/shop/GetSMBPrivateAccountUsers", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Snapshot=t88.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=actionName", "Value=AccountsByEndUserEmail", ENDITEM, 
		"Name=account_id", "Value=", ENDITEM, 
		"Name=accountname", "Value=", ENDITEM, 
		"Name=accountNameType", "Value=begins", ENDITEM, 
		"Name=endUserEmailType", "Value=is", ENDITEM, 
		"Name=endUserEmail", "Value={p_as_byEmail}", ENDITEM, 
		"Name=pageIndex", "Value=1", ENDITEM, 
		"Name=fetchSelfAccounts", "Value=", ENDITEM, 
		LAST);	
	
		if(atoi(lr_eval_string("{AsEmailCount}")) > 0)
		{
			//lr_end_transaction("CP37_AcctSearch_ByEmail",LR_PASS);

		}
		else
		{
			//lr_end_transaction("CP37_AcctSearch_ByEmail",LR_FAIL);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}
	
		}	
		
	pmaxValue = atoi(lr_eval_string("{cp_AccountId_count}"));	
	if(pmaxValue>0)
	{
		prandNumber = (rand() % (pmaxValue))+1;
		sprintf(spara, "{cp_AccountId_%d}",prandNumber);		
		lr_save_string(lr_eval_string(spara),"cp_AccountId");
			web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
		//lr_start_transaction("CP38_ViewAccountUsers");
	
		web_reg_find("Text=accountname","SaveCount=ViewAccCount",LAST);
	
		web_submit_data("GetSMBPrivateAccountUsers_3", 
			"Action=https://{p_hostName}/us-en/shop/GetSMBPrivateAccountUsers", 
			"Method=POST", 
			"RecContentType=text/html", 
			"Snapshot=t40.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=actionName", "Value=GetAccountUsers", ENDITEM, 
			"Name=account_id", "Value={cp_AccountId}", ENDITEM, 
			LAST);
		
			if(atoi(lr_eval_string("{ViewAccCount}")) > 0)
			{
				//lr_end_transaction("CP38_ViewAccountUsers",LR_PASS);
			}
			else
			{
				//lr_end_transaction("CP38_ViewAccountUsers",LR_FAIL);
				lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
			}
	}	
	
	lr_think_time(10);	
		
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);

	return 0;
}
