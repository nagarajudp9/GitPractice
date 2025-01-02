CLP_AC()
{
		
int CLPARi,CLPARcount;
//"catentryId":"1698654","
	lr_think_time(30);

web_reg_find("Text=category-landing-page","SaveCount=CLPACC_Products",LAST);

lr_start_transaction(lr_eval_string("{AgentType}S04_CategoryLanding_Accessories"));
	web_add_auto_header("Accept-Language", 		"en-US,en;q=0.9");

	web_url("{p_acc_products}", 
		"URL=https://{p_hostName}/us-en/shop/cat/{p_acc_products}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
		
		
		
	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1645780791226&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_acc_products}", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

/*	web_url("DealsAPI", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_acc_products}", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);*/
		
		web_save_timestamp_param("cp_time", LAST);
		//lr_start_sub_transaction("S17-1_DealsAPI",(lr_eval_string("{AgentType}S04_CategoryLanding_Accessories")));
		
	 web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);  
	
	//lr_end_sub_transaction("S17-1_DealsAPI", LR_AUTO);
	
		
		//"catentryId":"1698654","i
	web_reg_save_param("cp_CLPaccessories","lb=\"catentryId\":\"","rb=\",","ORD=all","Notfound=warning",LAST);
	
		web_url("async", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/cat%2F{p_acc_products}/async", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	
/*	
	CLPARcount=atoi(lr_eval_string("{cp_CLPaccessories_count}"));	
		if(CLPARcount == 0)
		{
			
		lr_end_transaction(lr_eval_string("{AgentType}S04_CategoryLanding_Accessories"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
			
		}	
		else
		{
			lr_save_string(lr_eval_string("{cp_CLPaccessories_1}"), "CLPAccURL");
			for (CLPARi=1; CLPARi<(lr_paramarr_len("cp_CLPaccessories")); CLPARi++)
			{
				lr_save_string(lr_paramarr_idx("cp_CLPaccessories", CLPARi+1), "CLPAccCatID");
				lr_save_string(lr_eval_string("{CLPAccURL},{CLPAccCatID}"), "CLPAccURL");
			}
		}

*/

web_url("HPServices_2",
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1645780792682&action=ipd&catentryId=1056168,1085820,1165742,137344,1471802,3074457345618857322,3074457345619612825,3074457345619668320,3074457345619682328,3074457345620001825,3074457345620016819,3074457345620137319&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/cat/{p_acc_products}", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	if(atoi(lr_eval_string("{CLPACC_Products}"))>0)
		{
			lr_end_transaction(lr_eval_string("{AgentType}S04_CategoryLanding_Accessories"),LR_PASS);
		}
		else
		{
			lr_end_transaction(lr_eval_string("{AgentType}S04_CategoryLanding_Accessories"),LR_FAIL);
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}

	return 0;
}
