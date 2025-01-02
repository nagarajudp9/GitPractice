MDP()
{
	
	int MDPi,MDPcount;
	
		lr_think_time(5);
		
	web_reg_find("Text=mdpList","SaveCount=MDP_Products",LAST);
	web_reg_save_param("cp_MDPcatentryID","LB=\"catentryId\":\"","RB=\",\"","ORD=ALL",LAST);
	web_reg_save_param_regexp("ParamName=cp_catEntryIdAddtocart","RegExp=\"catentryId\":\"(.*?)\",(.*?)\"product_type\":\"STO\",","Notfound=warning", "Group=1",LAST);
	web_save_timestamp_param("cp_time", LAST); 

	lr_start_transaction(lr_eval_string("{AgentType}CP07_MDP"));
 
	web_url("{p_mdp}", 
		"URL=https://{p_hostName}/us-en/shop/mdp/{p_mdp}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
	MDPcount=atoi(lr_eval_string("{cp_MDPcatentryID_count}"));	
		if(MDPcount == 0)
		{
			
		lr_end_transaction("CP07_MDP",LR_FAIL);
    	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	
		}	
		else
		{
			lr_save_string(lr_eval_string("{cp_MDPcatentryID_1}"), "MDPURL");
			for (MDPi=1; MDPi<(lr_paramarr_len("cp_MDPcatentryID")); MDPi++)
			{
				lr_save_string(lr_paramarr_idx("cp_MDPcatentryID", MDPi+1), "MDPCatID");
				lr_save_string(lr_eval_string("{MDPURL},{MDPCatID}"), "MDPURL");
			}
		}
		
			web_convert_param("p_MDP01",
	                  "SourceString={p_mdp}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);

	web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/vwa%2F{p_MDP01}/async", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/mlp/{p_mdp}", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/mdp/{p_mdp}", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);
		
		web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151{StoreType}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    
		
	/*web_url("dealsapi", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/vwa/{p_mdp}", 
		"Snapshot=t62.inf", 
		"Mode=HTML", 
		LAST);*/

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId={MDPURL}&modelId=&langId=-1&storeId=10151&catalogId=10051",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/mdp/{p_mdp}", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);
		
		if(atoi(lr_eval_string("{MDP_Products}"))>0)
		{
			lr_end_transaction(lr_eval_string("{AgentType}CP07_MDP"),LR_PASS);
			//AddToCartFlag = 1;
			lr_save_string("_MDP","cartitem");
		}
		else
		{
		lr_end_transaction("CP07_MDP",LR_FAIL);
    	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	
		}
	
	
	
		
	return 0;
}