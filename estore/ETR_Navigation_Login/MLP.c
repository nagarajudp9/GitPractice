MLP()
{
	
	
	//int MLPi,MLPcount;
	int mlpi,mlpcount;
	int mlpcount1;
	
	lr_think_time(30);
	
	web_reg_find("Text=mlpList","SaveCount=MLP_Products",LAST);
 	web_reg_save_param("cp_MLPmodelID","lb=\"modelId\":\"","rb=\"","ORD=all","Notfound=warning",LAST);
 	web_reg_save_param("cp_Catentryid","lb=\"catentryId\":\"","rb=\",","ORD=all","Notfound=warning",LAST);
 	web_save_timestamp_param("cp_time", LAST);
 
	lr_start_transaction(lr_eval_string("{AgentType}S06_MLP"));
 
	
	web_url("{p_MLP}", 
		"URL=https://{p_hostName}/us-en/shop/mlp/{p_MLP}{StoreType}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

  
	/*	MLPcount=atoi(lr_eval_string("{cp_MLPmodelID_count}"));	
		if(MLPcount == 0)
		{
			
			lr_end_transaction(lr_eval_string("{AgentType}S06_MLP"),LR_FAIL);	
		    lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
			
		}	
		else
		{
			lr_save_string(lr_eval_string("{cp_MLPmodelID_1}"), "mlpURL");
			for (MLPi=1; MLPi<(lr_paramarr_len("cp_MLPmodelID")); MLPi++)
			{
				lr_save_string(lr_paramarr_idx("cp_MLPmodelID", MLPi+1), "MLPCatID");
				lr_save_string(lr_eval_string("{mlpURL},{MLPCatID}"), "mlpURL");
			}
		}*/
		
		
		mlpcount=atoi(lr_eval_string("{cp_MLPmodelID_count}"));	
	mlpcount1=atoi(lr_eval_string("{cp_Catentryid_count}"));
	if(mlpcount != 0)
	{
		lr_save_string(lr_eval_string("{cp_MLPmodelID_1}"), "mlpURL");
		for (mlpi=1; mlpi<(lr_paramarr_len("cp_MLPmodelID")); mlpi++)
		{
			lr_save_string(lr_paramarr_idx("cp_MLPmodelID", mlpi+1), "mlpCatID");
			lr_save_string(lr_eval_string("{mlpURL}%2C{mlpCatID}"), "mlpURL");
		}
		
	}	
	else if (mlpcount1 != 0)
	{
		lr_save_string(lr_eval_string("{cp_Catentryid_1}"), "mlpURL");
		for (mlpi=1; mlpi<(lr_paramarr_len("cp_Catentryid")); mlpi++)
		{
			lr_save_string(lr_paramarr_idx("cp_Catentryid", mlpi+1), "mlpCatID");
			lr_save_string(lr_eval_string("{mlpURL}%2C{mlpCatID}"), "mlpURL");
		}
	        	
	        }
	else{
				
		lr_end_transaction(lr_eval_string("{AgentType}S06_MLP"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	
	
	
	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/mlp/{p_MLP}", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
		
		
		if( eppFlag == 1 || silverFlag == 1 || goldFlag == 1 || platinumFlag == 1 ||  euaFlag == 1 )

	{

  	//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S06_MLP")));
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
 
    	//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S06_MLP")));
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
		
		web_url("productSettings", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/component/productSettings", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
		
		
		web_convert_param("p_MLP01",
	                  "SourceString={p_MLP}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
		
		web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/mlp%2F{p_MLP01}/async", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
		
		

//	web_url("HPServices_2", 
//	//	"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId=&modelId={MLPURL}&storeId=10151&catalogId=10051",        
//        "URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=pid&catentryId=&modelId={MLPURL}&langId=-1&storeId=10151&catalogId=10051",		
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=https://{p_hostName}/us-en/shop/mlp/{P_MLP}", 
//		"Snapshot=t3.inf", 
//		"Mode=HTML", 
//		LAST);
		
		
		web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cupids&catentryId=&modelId={MLPURL}&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/mlp/{p_MLP}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

		
		if(atoi(lr_eval_string("{MLP_Products}"))>0)
		{
			lr_end_transaction(lr_eval_string("{AgentType}S06_MLP"),LR_PASS);	
		}
		else
		{
			lr_end_transaction(lr_eval_string("{AgentType}S06_MLP"),LR_FAIL);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);		
		}
	
	return 0;
}
