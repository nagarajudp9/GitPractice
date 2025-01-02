MyQuotes()
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
	
	if(strcmp(lr_eval_string("{ManageAccount}"),"1")==0)
		{
			lr_end_transaction("CP36_ManageAccounts",LR_PASS);

		}
		else
		{
			lr_end_transaction("CP36_ManageAccounts",LR_FAIL);
			CC_Logout();    		
       		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}
	
	lr_think_time(10);
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");	
	lr_start_transaction("CP42_MyQuotes");
	
	web_reg_find("Text=Quote","SaveCount=MyQuotesCount",LAST);

	web_url("PunchoutQuotesView",
		"URL=https://{p_hostName}/us-en/shop/PunchoutQuotesView?storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html;charset=UTF-8", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1526298613304&action=cupis&catentryId=&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html;charset=UTF-8", 
		"Referer=https://{p_hostName}/us-en/shop/PunchoutQuotesView?storeId=10151&catalogId=10051", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	
	if(atoi(lr_eval_string("{MyQuotesCount}")) > 0)
		{
			lr_end_transaction("CP42_MyQuotes",LR_PASS);

		}
		else
		{
			lr_end_transaction("CP42_MyQuotes",LR_FAIL);
			CC_Logout();    		
       		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}
	
	lr_think_time(10);
	
	prandNumber = atoi(lr_eval_string("{p_randomNum}"));
	if(prandNumber<0)
	{
	

	}
	else
	{
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");			
	lr_start_transaction("CP43_QS_ByDate");
	
	web_reg_find("Text=quoteNumber","SaveCount=QsNoCount",LAST);
	//web_reg_find("Text=Quote","SaveCount=MyQuotesCount",LAST);
	web_reg_save_param("cp_QuoteNo","LB=\"quoteNumber\": \"","RB=\"","ORD=ALL","NotFound=Warning",LAST);
	web_reg_save_param("cp_MemberId","LB=\"memberId\": \"","RB=\"","ORD=ALL","NotFound=Warning",LAST);

	web_submit_data("GetPunchoutQuotes", 
		"Action=https://{p_hostName}/us-en/shop/GetPunchoutQuotes", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html;charset=UTF-8", 
		"Snapshot=t54.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=quoteNumber", "Value=", ENDITEM, 
		"Name=endUserEmail", "Value=", ENDITEM, 
		"Name=accountName", "Value=", ENDITEM, 
		"Name=accountNameMatchCondition", "Value=is", ENDITEM, 
		"Name=emailMatchCondition", "Value=is", ENDITEM, 
		"Name=fromDate", "Value={p_searchByStartDate}", ENDITEM, 
		"Name=toDate", "Value={p_searchByEndDate}", ENDITEM, 
		"Name=pageIndex", "Value=1", ENDITEM, 
		"Name=qcid", "Value=", ENDITEM, 
		LAST);
	
	if(atoi(lr_eval_string("{QsNoCount}")) > 0)
		{
			lr_end_transaction("CP43_QS_ByDate",LR_PASS);

		}
		else
		{
			lr_end_transaction("CP43_QS_ByDate",LR_PASS);
			CC_Logout();    		
       		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	
		}
		
	}	
			
	pmaxValue = atoi(lr_eval_string("{MyQuotesCount}"));	
	if(pmaxValue>0)
	{
		prandNumber = (rand() % (pmaxValue))+1;
		sprintf(spara, "{cp_QuoteNo_%d}",prandNumber);
		sprintf(parakey, "{cp_MemberId_%d}",prandNumber);		
		lr_save_string(lr_eval_string(spara),"cp_QuoteNo");
		lr_save_string(lr_eval_string(parakey),"cp_MemberId");
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");		
		lr_start_transaction("CP44_ViewQuote");
	
		web_reg_find("Text=Quote","SaveCount=ViewQuoteCount",LAST);
	
		web_url("browseEstore_2", 
			"URL=https://{p_hostName}/us-en/shop/browseEstore?ccQotNo={cp_QuoteNo}&ccCustId={cp_MemberId}", 
			//"URL=https://{p_hostName}/us-en/shop/browseEstore?ccQotNo={cp_QuoteNo}&ccCustId={cp_MemberId}",
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html;charset=UTF-8", 
			"Snapshot=t33.inf", 
			"Mode=HTML", 
			LAST);
	
		
		web_url("HPServices_4", 
			"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1526298736135&action=cupis&catentryId=&modelId=", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html;charset=UTF-8", 
			"Snapshot=t38.inf", 
			"Mode=HTML", 
			LAST);
		
		if(atoi(lr_eval_string("{ViewQuoteCount}")) > 0)
			{
				lr_end_transaction("CP44_ViewQuote",LR_PASS);
			}
			else
			{
				lr_end_transaction("CP44_ViewQuote",LR_FAIL);
				CC_Logout();    		
       			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
			}
	}	
	
	lr_think_time(10);
	
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
			
	return 0;
}
