ViewAll()
{
	int VWAcount,VWAi,randNumber,pmaxValue;
	int viewflag=1;
	char mainfilters[100];
	char mainfilters1[100];
	
	
	web_cache_cleanup();
	web_cleanup_cookies();
	lr_think_time(20);	

	//View all items
	
	//web_reg_find("Text=vwaList","SaveCount=c_ViewAll",LAST);
	
	web_reg_find("Text=View all items","SaveCount=c_ViewAll",LAST);
	


	lr_start_transaction(lr_eval_string("{AgentType}CP05_ViewAll"));
	//lr_start_sub_transaction("CP05-1_ViewAll",(lr_eval_string("{AgentType}S05_ViewAll")));

	
	web_url("p_ViewAll",
		"URL=https://{p_hostName}/us-en/shop/vwa/{p_vwa}",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	//lr_end_sub_transaction("CP05-1_ViewAll", LR_AUTO);
	
	//lr_start_sub_transaction("CP05-2_HPServices",(lr_eval_string("{AgentType}S05_ViewAll")));
  
		
	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1626179256356&action=cus&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t59.inf", 
		"Mode=HTML", 
		LAST);
	
	
	web_url("dealsapi", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151",  
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t62.inf", 
		"Mode=HTTP", 
		LAST);
		
  	web_reg_save_param("cp_VWAproductId","lb=\"productId\":\"","rb=\"","ord=all",LAST);
	web_reg_save_param("main","lb=\"}],\"key\":\"","rb=\"}","ord=all",LAST);
	web_reg_save_param("main1","lb=\"displayName\":\"","rb=\",\"displaySequence\":","ord=all","Notfound=warning",LAST);
	
	web_reg_save_param("main_all","lb=\"facetValue\"","rb=\"displaySequence","ord=all","Notfound=warning",LAST);
	web_reg_save_param("cp_sort","LB=sortDropdown\" value='","RB=\'>","ORD=ALL","Notfound=warning",LAST);
	
	
	web_url("sync", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/vwa%2F{p_vwa}/sync", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/vwa/{p_vwa}", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	
	pmaxValue = atoi(lr_eval_string("{main_count}"));
   	randNumber = (rand() % (pmaxValue))+1;
  
  sprintf(mainfilters1, "{main1_%d}",randNumber);
  sprintf(mainfilters, "{main_%d}",randNumber);	

	lr_save_string(lr_eval_string(mainfilters),"mainfilter");
	lr_save_string(lr_eval_string(mainfilters1),"mainfilter1");
	
	VWAcount=atoi(lr_eval_string("{cp_VWAproductId_count}"));
	if(VWAcount == 0)
	{
		
		lr_end_transaction(lr_eval_string("{AgentType}CP05_ViewAll"),LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}	
	else
	{
		lr_save_string(lr_eval_string("{cp_VWAproductId_1}"), "VWAURL");
		for (VWAi=1; VWAi<(lr_paramarr_len("cp_VWAproductId")); VWAi++)
		{
			lr_save_string(lr_paramarr_idx("cp_VWAproductId", VWAi+1), "VWACatID");
			lr_save_string(lr_eval_string("{VWAURL},{VWACatID}"), "VWAURL");
		}
	}
	
	
	web_reg_find("Search=All","SaveCount=c_ProductAvalibility","Text=PRODUCT AVAILABILITY",LAST);

	
	web_url("finder-results", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/component/vwa/finder-results?path=vwa%2F{p_vwa}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/vwa/{p_vwa}", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1626179257621&action=cupids&catentryId={VWAURL}&modelId=&langId=-1&storeId=10151&catalogId=10051",  
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t63.inf", 
		"Mode=HTML", 
		LAST);

	//lr_end_sub_transaction("CP05-2_HPServices", LR_AUTO);
	
	if(atoi(lr_eval_string("{c_ViewAll}"))>0)
	{
		lr_end_transaction(lr_eval_string("{AgentType}CP05_ViewAll"),LR_PASS);
	}	
	else
	{
		lr_end_transaction(lr_eval_string("{AgentType}CP05_ViewAll"),LR_FAIL);		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
		
	lr_think_time(20);
	
	//sorting started	
	
	lr_start_transaction(lr_eval_string("{AgentType}CP16_Sorting"));
			
	
	web_reg_save_param("cp_catentryId","lb=\"catentryId\":\"","rb=\",","ord=all",LAST);
	
	web_url("finder-results", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/component/vwa/finder-results?path=vwa%2F{p_vwa}&orderBy={p_sort}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);	
	
	
	web_url("vwa", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/seo/vwa?path=vwa%2F{p_vwa}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/vwa/{p_vwa}?orderBy={p_sort}", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	
	VWAcount=atoi(lr_eval_string("{cp_catentryId_count}"));
		if(VWAcount == 0)
		{
			
			lr_end_transaction(lr_eval_string("{AgentType}CP16_Sorting"),LR_AUTO);;
		    lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
			
		}	
		else
		{
			lr_save_string(lr_eval_string("{cp_catentryId_1}"), "VWAURL");
			for (VWAi=1; VWAi<(lr_paramarr_len("cp_catentryId")); VWAi++)
			{
				lr_save_string(lr_paramarr_idx("cp_catentryId", VWAi+1), "VWACatID");
				lr_save_string(lr_eval_string("{VWAURL},{VWACatID}"), "VWAURL");
			}
		}
		
		
		web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1646221538898&action=pid&catentryId={VWAURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/vwa/{p_sort}?orderBy={p_sort}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);


			
	lr_end_transaction(lr_eval_string("{AgentType}CP16_Sorting"),LR_AUTO);
	
	
	if(strcmp(lr_eval_string("{cp_subfilter1}"),"")==0 && strcmp(lr_eval_string("{cp_subfilter2}"),"")==0)
	{
				
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
			
	pmaxValue = atoi(lr_eval_string("{p_randomNum}"));	
	
	if(pmaxValue>0 && pmaxValue<2)
			
	{
		
		
	if(strcmp(lr_eval_string("{cp_subfilter1}"),"")>0 && strcmp(lr_eval_string("{cp_subfilter2}"),"")>0 && strcmp(lr_eval_string("{cp_subfilter3}"),"")>0 && strcmp(lr_eval_string("{cp_subfilter4}"),"") == 0 )
		
	{

		lr_save_string(lr_eval_string("{cp_subfilter1}"), "cp_subfilter4");
	}
	
	else if(strcmp(lr_eval_string("{cp_subfilter1}"),"")>0 && strcmp(lr_eval_string("{cp_subfilter2}"),"")>0 && strcmp(lr_eval_string("{cp_subfilter3}"),"")== 0 && strcmp(lr_eval_string("{cp_subfilter4}"),"") == 0 )
		
	{
		lr_save_string(lr_eval_string("{cp_subfilter2}"), "cp_subfilter3");
		lr_save_string(lr_eval_string("{cp_subfilter1}"), "cp_subfilter4");
	}
	

	lr_save_string(lr_eval_string(lr_eval_string("{cp_subfilter{p_vwarand}}")), "cp_subfilter");
	

	lr_start_transaction(lr_eval_string("{AgentType}CP14_Filtering_VWA"));
	
	
	web_url("finder-results", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/component/vwa/finder-results?path=vwa%2F{p_vwa}%2FPrice%3D800-1000&orderBy={p_sort}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/vwa/business-solutions/Price=800-1000?orderBy={p_sort}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	

	
	web_url("vwa", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/seo/vwa?path=vwa%2F{p_vwa}%2FPrice%3D800-1000", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/vwa/{p_vwa}/Price=800-1000?orderBy={p_sort}", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1646221538898&action=pid&catentryId={VWAURL}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/vwa/{p_vwa}/Price=800-1000?orderBy={p_sort}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);


	lr_end_transaction(lr_eval_string("{AgentType}CP14_Filtering_VWA"),LR_AUTO);
					
	lr_think_time(30);
	
	if((atoi(lr_eval_string("{c_ProductAvalibility}"))>0))
	{
	
	lr_start_transaction(lr_eval_string("{AgentType}CP14_Filtering_VWA_PA"));
	
	
	web_url("finder-results", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/component/vwa/finder-results?path=vwa%2F{p_vwa}%2Favailability%3DIn-Stock", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/vwa/{p_vwa}/availability=In-Stock", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	
	web_url("vwa", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/seo/vwa?path=vwa%2F{p_vwa}%2Favailability%3DIn-Stock", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/vwa/{p_vwa}/availability=In-Stock", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	
	
	lr_end_transaction(lr_eval_string("{AgentType}CP14_Filtering_VWA_PA"),LR_AUTO);
	
	lr_think_time(30);
	}
	else
	{
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_AUTO);
	}

					
	lr_start_transaction(lr_eval_string("{AgentType}CP15_ClearFilters"));
			
	web_url("finder-results_6", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/component/vwa/finder-results?path=vwa%2F{p_vwa}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/wcs/resources/store/10151/seo/vwa?path=vwa/{p_vwa}", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("vwa", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/seo/vwa?path=vwa/{p_vwa}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/wcs/resources/store/10151/seo/vwa?path=vwa/{p_vwa}", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	
	lr_end_transaction(lr_eval_string("{AgentType}CP15_ClearFilters"),LR_AUTO);
	
	}
	

	return 0;
}