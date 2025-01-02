MLP()
{
	
	/*int mlpi,mlpcount;
	
	lr_think_time(60);
	
	web_reg_find("Search=All","SaveCount=c_MLP1","Text=var pagelevels = 'mlp",LAST);	
		
	
	web_reg_save_param("cp_MLPCatEntryId","lb=\" data-ui='{\"modelId\":\"","rb=\"","ord=all",LAST);
	web_reg_save_param("cp_categoryId","LB=name=\"headerCategoryId\" value=\"","RB=\"/>",LAST);
		

	lr_start_transaction("CP06_MLP");
	
	web_url("MLP", 
		"URL=https://{p_hostName}/us-en/shop/mlp/{p_mlp}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);
	
	mlpcount=atoi(lr_eval_string("{cp_MLPCatEntryId_count}"));
	
	if(mlpcount == 0)
	{
		lr_exit(LR_EXIT_ACTION_AND_CONTINUE,LR_AUTO);
	}
	
	else
	{
	
	
	lr_save_string(lr_eval_string("{cp_MLPCatEntryId_1}"), "MLPURL");
		
	for (mlpi=1; mlpi<(lr_paramarr_len("cp_MLPCatEntryId")); mlpi++)
{
	lr_save_string(lr_paramarr_idx("cp_MLPCatEntryId", mlpi+1), "MLPCatID");
	lr_save_string(lr_eval_string("{MLPURL}%2C{MLPCatID}"), "MLPURL");
}
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&categoryId={cp_categoryId}&_=1515133214835&action=cupis&catentryId={MLPURL}&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/mlp/{p_mlp}", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("CP06_MLP",LR_AUTO);
	
	}*/
	
	int mlpi,mlpcount;
	
	lr_think_time(5);
	
	web_reg_find("Search=All","SaveCount=c_MLP1","Text=var pagelevels = 'mlp",LAST);	
	web_reg_find("Search=All","SaveCount=c_MLP2","Text=pagelevelvalue = 'mlp",LAST);	
	web_reg_find("Search=All","SaveCount=c_Home","Text=HomePage.jsp",LAST);
	web_reg_save_param("C_MlpcategoryId","lb=\" data-ui='{\"modelId\":\"","rb=\"","ord=all","Notfound=warning",LAST);
		
	web_reg_save_param("cp_categoryId","LB=name=\"headerCategoryId\" value=\"","RB=\"/>","Notfound=warning",LAST);
	
	lr_start_transaction(lr_eval_string("{AgentType}CP06_MLP"));
	
		web_url("MLP", 
		"URL=https://{p_hostName}/us-en/shop/mlp/{p_mlp}{StoreType}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	mlpcount=atoi(lr_eval_string("{C_MlpcategoryId_count}"));	
	if(mlpcount == 0)
	{
		
		lr_end_transaction(lr_eval_string("{AgentType}CP06_MLP"),LR_PASS);	
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);		
	}	
	else
	{
		lr_save_string(lr_eval_string("{C_MlpcategoryId_1}"), "mlpURL");
		for (mlpi=1; mlpi<(lr_paramarr_len("C_MlpcategoryId")); mlpi++)
		{
			lr_save_string(lr_paramarr_idx("C_MlpcategoryId", mlpi+1), "mlpCatID");
			lr_save_string(lr_eval_string("{mlpURL}%2C{mlpCatID}"), "mlpURL");
		}
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
	
	if(((atoi(lr_eval_string("{c_MLP1}"))>0) || (atoi(lr_eval_string("{c_MLP2}"))>0))&& (atoi(lr_eval_string("{c_Home}"))==0))
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
