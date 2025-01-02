Landingpage()
{
		

		int CLPi,CLPcount;
int CLP1i,CLP1count;

int CLPinkToneri,CLPinkTonercount;
	lr_think_time(5);
	
	web_reg_find("Text=category-landing-page","SaveCount=CLP_Products",LAST);
	web_reg_save_param("cp_CLPmodelID1","lb=\"modelId\":\"","rb=\",","ORD=all",LAST);
	web_save_timestamp_param("cp_time", LAST);

	lr_start_transaction(lr_eval_string("{AgentType}CP04_CategoryLanding"));
	
	//lr_start_transaction("CP04_CategoryINKT");

	//lr_start_sub_transaction("CP04-1_CategoryLanding",(lr_eval_string("{AgentType}CP04_CategoryLanding")));
		
	web_url("p_Landing", 
		"URL=https://{p_hostName}/us-en/shop/cat/{p_landing}",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
	
	//lr_end_sub_transaction("CP04-1_CategoryLanding", LR_AUTO);
	
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
	
	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_landing}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
		
		
	//	lr_end_transaction("CP04_CategoryINKT", LR_AUTO);

	web_url("dealsapi", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_landing}}", 
		"Snapshot=t2.inf", 
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
	//lr_start_sub_transaction("CP04-2_HPServices",(lr_eval_string("{AgentType}CP04_CategoryLanding")));
	
	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cupids&catentryId=&modelId={CLPURL}&langId=-1&storeId=10151&catalogId=10051",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_landing}", 
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

		

	lr_think_time(30);
	
	web_reg_find("Text=category-landing-page","SaveCount=CLPinkToner_Products",LAST);
	web_reg_save_param("cp_CLPinkTonerModelID1","lb=\"modelId\":\"","rb=\",\"","ORD=all",LAST);
	web_save_timestamp_param("cp_time", LAST); //1600153594317 


	lr_start_transaction(lr_eval_string("{AgentType}CP04_CategoryINKT"));
	lr_start_sub_transaction("CP04-1_CategoryLanding",(lr_eval_string("{AgentType}CP04_CategoryINKT")));
	
	web_url("p_inkTonerProducts", 
		"URL=https://{p_hostName}/us-en/shop/cat/{p_inkTonerProducts}",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_sub_transaction("CP04-1_CategoryLanding", LR_AUTO);
	
	CLPinkTonercount=atoi(lr_eval_string("{cp_CLPinkTonerModelID1_count}"));	
		if(CLPinkTonercount == 0)
		{
			
		lr_end_transaction(lr_eval_string("{AgentType}CP04_CategoryINKT"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
			
		}	
		else
		{
			lr_save_string(lr_eval_string("{cp_CLPinkTonerModelID1_1}"), "CLPinkTonerURL1");
			for (CLPinkToneri=1; CLPinkToneri<(lr_paramarr_len("cp_CLPinkTonerModelID1")); CLPinkToneri++)
			{
				lr_save_string(lr_paramarr_idx("cp_CLPinkTonerModelID1", CLPinkToneri+1), "CLPinkTonerCatID");
				lr_save_string(lr_eval_string("{CLPinkTonerURL1},{CLPinkTonerCatID}"), "CLPinkTonerURL1");
			}
		}
	
	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_inkTonerProducts}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	
	
		
	web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/cat%2F{p_inkTonerProducts}/async",  
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_inkTonerProducts}", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_start_sub_transaction("CP04-2_HPServices",(lr_eval_string("{AgentType}CP04_CategoryINKT")));
	
	web_url("HPServices_2",
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cusipd&catentryId=&modelId={CLPinkTonerURL1}&langId=-1&storeId=10151&catalogId=10051",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_inkTonerProducts}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=ipd&catentryId=&modelId={CLPinkTonerURL1}&langId=-1&storeId=10151&catalogId=10051",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_inkTonerProducts}", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	
	lr_end_sub_transaction("CP04-2_HPServices", LR_AUTO);
	
	web_save_timestamp_param("cp_time", LAST);
	//lr_start_sub_transaction("CP17-1_DealsAPI",(lr_eval_string("{AgentType}CP04_CategoryINKT")));
		
	    web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    

	
	//lr_end_sub_transaction("CP17-1_DealsAPI", LR_AUTO);
	
	if(atoi(lr_eval_string("{CLPinkToner_Products}"))>0)
		{
			lr_end_transaction(lr_eval_string("{AgentType}CP04_CategoryINKT"),LR_PASS);
		}
		else
		{
			lr_end_transaction(lr_eval_string("{AgentType}CP04_CategoryINKT"),LR_FAIL);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}
		
	return 0;
}
