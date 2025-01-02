Mob_AddToCart_CTO()
{
	lr_think_time(100);
	
	web_add_header("User-Agent","{p_mUserAgent}"); 

	web_set_max_html_param_len("9999");
	
	web_reg_find("Text=Official Site","SaveCount=PDPCount",LAST );
	
	web_reg_save_param("cp_CatEntryID","LB=data-a2c='{\"itemId\":\"","RB=\"",LAST);
	
	web_reg_save_param("cp_partnumber","LB=data-bv-productId=\"","RB=_1\"","RelFrameID=1","ORD=1","Notfound=warning",LAST);
	
	web_reg_save_param("cp_PDPCatEntryId","LB=id=\"price_holder_","RB=\" data",LAST);

	lr_start_transaction("S08_MoB_PDP");

	web_url("PDP_page", 
		"URL=https://{p_hostName}/us-en/shop/{p_Mobpdpurl}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("HPServices",
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1581000132651&action=cupids&catentryId={cp_CatEntryID}&modelId=",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop/{p_Mobpdpurl}",
		"Snapshot=t5.inf",
		"Mode=HTML",
		LAST);
		
	lr_end_transaction("S08_MoB_PDP",LR_AUTO);
	
	web_reg_find("Search=All","SaveCount=c_orderId1","Text=orderId",LAST);
	
	web_reg_find("Search=All","SaveCount=c_orderItemId1","Text=orderItemId",LAST);
	
	web_reg_save_param("cp_ShipDate","LB=shipDate\": \"","RB=\",",LAST);
	
	web_reg_save_param_ex("ParamName=cp_orderItemId","LB=orderItemId\": [\"","RB=\"],","NotFound=Warning",LAST);	
	web_reg_save_param_ex("ParamName=cp_orderId","LB=orderId\": [\"","RB=\"],","NotFound=Warning",LAST);	

	lr_start_transaction("S23_Mob_HPCTORestAddToCart_CTO");
	
	
	web_submit_data("HPCTORestAddToCartCmd", 
		"Action=https://{p_hostName}/us-en/shop/HPCTORestAddToCartCmd", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/pdp/hp-spectre-laptop-15t-eb000-191b0av-1", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=catentryId", "Value=3074457345619623823", ENDITEM, 
		LAST);

/*
	web_submit_data("HPCTORestAddToCartCmd",
		"Action=https://{p_hostName}/us-en/shop/HPCTORestAddToCartCmd",
		//"Action=https://{p_hostName}/us-en/shop/HPCTORestAddToCartCmd",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html;charset=UTF-8",
		"Referer=https://{p_hostName}/us-en/shop/{p_Mobpdpurl}",
		"Snapshot=t10.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=catentryId", "Value={cp_CatEntryID}", ENDITEM,
		LAST);
*/	
	web_url("HPServices_2", 
		//"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1581000156519&action=pids&catentryId=1338657%2C911654%2C911656%2C1272160%2C1652155%2C1272158%2C1272157%2C1272162%2C689659%2C914652&modelId=", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1581000156519&action=pids&catentryId={cp_CatEntryID}&modelId=", 
		"TargetFrame=",
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/{p_Mobpdpurl}", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	
	web_url("ConfigureView",
		"URL=https://{p_hostName}/us-en/shop/ConfigureView?catalogId=10051&langId=-1&storeId=10151&urlLangId=&catEntryId={cp_CatEntryID}&quantity=1",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop/{p_Mobpdpurl}",
		"Snapshot=t16.inf",
		"Mode=HTML",
		LAST);
	
	//web_reg_find("Text=Cart summary",LAST );
	
	web_reg_save_param("cp_krypto","LB=&krypto=","RB=\"","NotFound=Warning",LAST);
	
	web_convert_param("c_ShipDate",
	                  "SourceString={cp_ShipDate}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);

	web_url("AccessoryAttachView",
		"URL=https://{p_hostName}/us-en/shop/AccessoryAttachView?shipDate={c_ShipDate}&selectedRecommConfig=recConfig1&catEntryId={cp_CatEntryID}&storeId=10151",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop/{p_Mobpdpurl}",
		"Snapshot=t16.inf",
		"Mode=HTML",
		LAST);
		
	web_url("HPServices_3",
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1581000171454&action=cupids&catentryId={cp_CatEntryID}&modelId=",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop/AccessoryAttachView?shipDate={c_ShipDate}&selectedRecommConfig=recConfig1&catEntryId={cp_CatEntryID}&storeId=10151",
		"Snapshot=t18.inf",
		"Mode=HTML",
		LAST);
		
	//lr_end_transaction("S23_Mob_HPCTORestAddToCart_CTO", LR_AUTO);

	if((atoi(lr_eval_string("{c_orderId1}"))>0) && (atoi(lr_eval_string("{c_orderItemId1}"))>0))
	{
		lr_end_transaction("S23_Mob_HPCTORestAddToCart_CTO",LR_PASS);
	}
	
	else
	{
		lr_end_transaction("S23_Mob_HPCTORestAddToCart_CTO",LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		
	}
	
	
	lr_think_time(10);
			
	lr_start_transaction("S25_Mob_RemoveCart");
		
	web_submit_data("AjaxOrderChangeServiceItemDelete", 
		"Action=https://{p_hostName}/us-en/shop/AjaxOrderChangeServiceItemDelete", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/{p_Mobpdpurl}", 
		"Snapshot=t71.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=calculationUsage", "Value=-1,-2,-5,-6,-7", ENDITEM, 
		"Name=check", "Value=*n", ENDITEM, 
		"Name=orderItemId", "Value={cp_orderItemId}", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cql", "Value=40", ENDITEM, 
		"Name=cal", "Value=8000", ENDITEM, 
		LAST);

	web_url("RefreshCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCart?ajax=true&storeId=10151&langId=-1&catalogId=10051&ccf=false&cql=40&cal=8000", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t72.inf", 
		"Mode=HTML", 
		LAST);
		
	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1582525007382&action=cupids&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		 "Referer=",
		"Snapshot=t54.inf",
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("S25_Mob_RemoveCart",LR_AUTO);		
	
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	
	return 0;
}
