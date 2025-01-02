CLP_CP()
{
	int CLPcarei,CLPcarecount;
	lr_think_time(30);
	web_reg_save_param("cp_CLPcarepack","lb=\"modelId\":\"","rb=\",\"","ORD=all",LAST);

	web_reg_find("Text=category-landing-page","SaveCount=CLPinkToner_Products",LAST);

	lr_start_transaction(lr_eval_string("{AgentType}S04_CategoryLanding_Carepacks"));
	
	web_url("{p_carepack_products}", 
		"URL=https://{p_hostName}/us-en/shop/cat/{p_carepack_products}{StoreType}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
		CLPcarecount=atoi(lr_eval_string("{cp_CLPcarepack_count}"));	
		if(CLPcarecount == 0)
		{
			
		lr_end_transaction(lr_eval_string("{AgentType}S04_CategoryLanding_Carepacks"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
			
		}	
		else
		{
			lr_save_string(lr_eval_string("{cp_CLPcarepack_1}"), "CLPCareURL");
			for (CLPcarei=1; CLPcarei<(lr_paramarr_len("cp_CLPcarepack")); CLPcarei++)
			{
				lr_save_string(lr_paramarr_idx("cp_CLPcarepack", CLPcarei+1), "CLPcareCatID");
				lr_save_string(lr_eval_string("{CLPCareURL},{CLPcareCatID}"), "CLPCareURL");
			}
		}
		
	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1645774887283&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_carepack_products}", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
		
	if( eppFlag == 1 || silverFlag == 1 || goldFlag == 1 || platinumFlag == 1 ||  euaFlag == 1 )

	{

  	//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S04_CategoryLanding_Carepacks")));
	web_save_timestamp_param("cp_time", LAST);
	web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151{StoreType1}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    
    	
	//lr_end_sub_transaction("S17-1_DealsAPI", LR_AUTO);
	
	}

	else

  	{ 
 
    	//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S04_CategoryLanding_Carepacks")));
        web_save_timestamp_param("cp_time", LAST);
    	web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    
    
    	//lr_end_sub_transaction("S17-1_DealsAPI", LR_AUTO);

	}


	/*web_url("DealsAPI_2", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_carepack_products}", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);*/

	web_url("HPServices_5", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1645774888408&action=ipd&catentryId=&modelId={CLPCareURL}&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_carepack_products}", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	
	web_url("footer", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/component/footer", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_carepack_products}", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);
		if(atoi(lr_eval_string("{CLPinkToner_Products}"))>0)
		{
			lr_end_transaction(lr_eval_string("{AgentType}S04_CategoryLanding_Carepacks"),LR_PASS);
		}
		else
		{
			lr_end_transaction(lr_eval_string("{AgentType}S04_CategoryLanding_Carepacks"),LR_FAIL);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}

		
	return 0;
}
