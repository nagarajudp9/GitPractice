HomePage()
{
	int Homei,Homecount;
	
	lr_think_time(60);
	
	web_reg_find("Text=<div class=\"home\">","SaveCount=Home_count",LAST);
	web_save_timestamp_param("cp_time", LAST);  
	
	
	lr_start_transaction(lr_eval_string("{AgentType}CP00_Homepage"));
		
	lr_start_sub_transaction("CP00-1_Homepage",(lr_eval_string("{AgentType}CP00_Homepage")));
		
	web_url("HomePage", 
		"URL=https://{p_hostName}/us-en/shop", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	lr_end_sub_transaction("CP00-1_Homepage", LR_AUTO);
	
	web_reg_save_param("cp_ClientID","LB=client_id=","RB=&amp","ORD=1","Notfound=Warning",LAST);
	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("dealsapi", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t62.inf", 
		"Mode=HTTP", 
		LAST);
		
		web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_={cp_time}&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
		
	//web_reg_save_param("cp_catentryID","LB=\",\"catentryId\":\"","RB=\",\"","ORD=ALL","Notfound=Warning",LAST);
	web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/%2F/async", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	
/*	Homecount=atoi(lr_eval_string("{cp_catentryID_count}"));	
		if(Homecount == 0)
		{
			
			lr_end_transaction(lr_eval_string("{AgentType}CP00_Homepage"),LR_FAIL);			
		    lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
			
		}	
		else
		{
			lr_save_string(lr_eval_string("{cp_catentryID_1}"), "HomeURL");
			for (Homei=1; Homei<(lr_paramarr_len("cp_catentryID")); Homei++)
			{
				lr_save_string(lr_paramarr_idx("cp_catentryID", Homei+1), "HomeCatID");
				lr_save_string(lr_eval_string("{HomeURL},{HomeCatID}"), "HomeURL");
			}
		}
	
*/
//lr_start_sub_transaction("CP00-2_HPServices",(lr_eval_string("{AgentType}CP00_Homepage")));
	
	
	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1624368711398&action=pid&catentryId={HomeURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
		

		
	//lr_start_sub_transaction("CP00-2_HPServices",(lr_eval_string("{AgentType}CP00_Homepage")));	
	web_url("product", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/product?itemId=3074457345620259318,3074457345619946825,3074457345619771820,3074457345620066319,3074457345619801822,3074457345620102824,3074457345619771822,3074457345620106821,3074457345618663818,3074457345619668320,3074457345619797825,3074457345619797831&limit=12&select=itemId,sku,name,attributes", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1647249778313&action=pid&catentryId=3074457345618663818,3074457345619668320,3074457345619771820,3074457345619771822,3074457345619797825,3074457345619797831,3074457345619801822,3074457345619946825,3074457345620066319,3074457345620102824,3074457345620106821,3074457345620259318&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
		
		
		
	//lr_end_sub_transaction("CP00-2_HPServices", LR_AUTO);

		if(atoi(lr_eval_string("{Home_count}"))>0)
		{
			lr_end_transaction(lr_eval_string("{AgentType}CP00_Homepage"),LR_PASS);
		}
		else
		{
			lr_end_transaction(lr_eval_string("{AgentType}CP00_Homepage"),LR_FAIL);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);							
		}
	
	
	return 0;
}
