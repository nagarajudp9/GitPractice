MLP()
{
	int mlpi,mlpcount;
	int mlpcount1;
	
	lr_think_time(20);
	
	web_reg_find("Text=mlpList","SaveCount=MLP_Products",LAST);
 	web_reg_save_param("cp_MLPmodelID","lb=\"modelId\":\"","rb=\"","ORD=all","Notfound=warning",LAST);
 	web_reg_save_param("cp_Catentryid","lb=\"catentryId\":\"","rb=\",","ORD=all","Notfound=warning",LAST);
 	web_save_timestamp_param("cp_time", LAST);
 
	lr_start_transaction(lr_eval_string("{AgentType}CP06_MLP"));
 
	web_url("p_MLP", 
		"URL=https://{p_hostName}/us-en/shop/mlp/{p_mlp}{StoreType}",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
  
	

	
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
		
		lr_end_transaction(lr_eval_string("{AgentType}CP06_MLP"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);		
	}
	

web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/mlp/{p_mlp}", 
		"Snapshot=t3.inf", 
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

	web_url("productSettings", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/component/productSettings", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);	
	
	web_convert_param("p_MLP01",
	                  "SourceString={p_mlp}",
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
	

	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&categoryId={cp_categoryId}&pstoreId=fedex&_=1612877140474&action=cupids&catentryId=&modelId={mlpURL}&retainPOCart=false", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/mlp/{p_mlp}{StoreType}", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
	
		if(atoi(lr_eval_string("{MLP_Products}"))>0)
		{
			lr_end_transaction(lr_eval_string("{AgentType}CP06_MLP"),LR_PASS);	
		}
		else
		{
			lr_end_transaction(lr_eval_string("{AgentType}CP06_MLP"),LR_FAIL);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);		
		}
	
	return 0;
}
