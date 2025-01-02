Landingpage()
{
		

		int CLPi,CLPcount;
int CLP1i,CLP1count;

	lr_think_time(5);
	
	web_reg_find("Text=category-landing-page","SaveCount=CLP_Products",LAST);
	web_reg_save_param("cp_CLPmodelID1","lb=\"modelId\":\"","rb=\",","ORD=all",LAST);
	web_save_timestamp_param("cp_time", LAST);

	lr_start_transaction(lr_eval_string("{AgentType}CP04_CategoryLanding"));
	//lr_start_sub_transaction("CP04-1_CategoryLanding",(lr_eval_string("{AgentType}S04_CategoryLanding")));
		
	web_url("{p_landing}", 
		"URL=https://{p_hostName}/us-en/shop/cat/{p_landing}",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_sub_transaction("CP04-1_CategoryLanding", LR_AUTO);
	
	web_url("sync", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/cat%2F{p_landing}/sync", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	
	CLPcount=atoi(lr_eval_string("{cp_CLPmodelID1_count}"));	
		if(CLPcount == 0)
		{
		
		lr_end_transaction(lr_eval_string("{AgentType}CP04_CategoryLanding"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
			
		}	
		else
		{
			lr_save_string(lr_eval_string("{cp_CLPmodelID1_1}"), "CLPURL");
			for (CLPi=1; CLPi<(lr_paramarr_len("cp_CLPmodelID1")); CLPi++)
			{
				lr_save_string(lr_paramarr_idx("cp_CLPmodelID1", CLPi+1), "CLPCatID");
				lr_save_string(lr_eval_string("{CLPURL},{CLPCatID}"), "CLPURL");
			}
		}
	
		
		web_save_timestamp_param("cp_time", LAST);
		
	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_landing}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
		
		web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cupids&catentryId=&modelId={CLPURL}&langId=-1&storeId=10151&catalogId=10051",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_landing}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/cat%2F{p_landing}}/async", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
		
		web_url("dealsapi", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_landing}}", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
		
		
	//lr_start_sub_transaction("CP04-2_HPServices",(lr_eval_string("{AgentType}S04_CategoryLanding")));
	
	web_url("HPServices_3",
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={CLPURL}&modelId=&langId=-1&storeId=10151&catalogId=10051",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_Landing}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	
	//lr_end_sub_transaction("CP04-2_HPServices", LR_AUTO);
	
if(atoi(lr_eval_string("{CLP_Products}"))>0)
		{
			lr_end_transaction(lr_eval_string("{AgentType}CP04_CategoryLanding"),LR_PASS);
		}
		else
		{
		lr_end_transaction(lr_eval_string("{AgentType}CP04_CategoryLanding"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}

		
	return 0;
}
