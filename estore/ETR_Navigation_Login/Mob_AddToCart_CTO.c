Mob_AddToCart_CTO()
{
	lr_think_time(30);
	
	web_add_header("User-Agent","{p_mUserAgent}"); 

	web_set_max_html_param_len("9999");
	
	web_reg_find("Text=Official Site","SaveCount=PDPCount",LAST );
	
	web_reg_save_param("cp_CatEntryID","LB=\"catentryId\":\"","RB=\",",LAST);	
	web_set_option("MaxRedirectionDepth", "0", LAST);

	lr_start_transaction("S08_MoB_PDP");

	web_url("PDP_page", 
		"URL=https://{p_hostName}/us-en/shop/{p_Mobpdpurl}{StoreType}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	web_set_option("MaxRedirectionDepth", "10", LAST);
	
	web_url("HPServices",
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1581000132651&action=cupids&catentryId={p_Mobpdpurl1}&modelId=",
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
	
	web_reg_save_param("cp_ShipDate","LB=shipDate\": \"","RB=\",", LAST);	
	
	web_reg_save_param_ex("ParamName=cp_orderItemId","LB=orderItemId\": [\"","RB=\"],","NotFound=Warning",LAST);	
	web_reg_save_param_ex("ParamName=cp_orderId","LB=orderId\": [\"","RB=\"],","NotFound=Warning",LAST);	

	lr_start_transaction("S23_Mob_HPCTORestAddToCart_CTO");

	web_submit_data("HPCTORestAddToCartCmd",		
		"Action=https://{p_hostName}/us-en/shop/HPCTORestAddToCartCmd",		
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop/{p_Mobpdpurl}",
		"Snapshot=t10.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=catentryId", "Value={p_Mobpdpurl1}", ENDITEM,
		LAST);

	
	
	web_reg_save_param("cp_krypto","LB=&krypto=","RB=\"","NotFound=Warning",LAST);
	
	web_convert_param("c_ShipDate",
	                  "SourceString={cp_ShipDate}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);

	web_url("AccessoryAttachView",
		"URL=https://{p_hostName}/us-en/shop/AccessoryAttachView?shipDate={c_ShipDate}&selectedRecommConfig=recConfig1&catEntryId={p_Mobpdpurl1}&storeId=10151",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop/{p_Mobpdpurl}",
		"Snapshot=t16.inf",
		"Mode=HTML",
		LAST);
		
	web_url("HPServices_3",
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1581000171454&action=cupids&catentryId={p_Mobpdpurl1}&modelId=",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop/AccessoryAttachView?shipDate={c_ShipDate}&selectedRecommConfig=recConfig1&catEntryId={p_Mobpdpurl1}&storeId=10151",
		"Snapshot=t18.inf",
		"Mode=HTML",
		LAST);
		
	
	web_url("getconfigurationmodeljson", 
		"URL=https://{p_ctohostName}/SterlingConfigRESTfulWebSvcApp/rest/configs/json/getconfigurationmodeljson?webSvcSessionID=&tokenID=&apiTemplateJSONString=&inJSONString=%7B%22include%22%3A%5B%7B%22clazz%22%3A%22Tab%22%7D%2C%7B%22clazz%22%3A%22Property%22%2C%22name%22%3A%22UI%3A+ICON+GRAPHIC%7C%7CUI%3A+DISPLAY+NAME%7C%7CUI%3A+DEFAULT+SELECTION%7C%7C_description%7C%7CUI%3A+PRODUCT+NAME%7C%7CUI%3A+OPTION+CLASS+VIEW%7C%7CUI%3A+LEAD+"
		"TIME%7C%7CHP_SHIP_DATE_CALENDAR_ID%7C%7CHP_Frogger_Message%7C%7CHP_Frogger_PublishedDate%7C%7CHP_UI_Frogger_DisplayMessage%7C%7CUI%3A+CONTROL%7C%7CUI%3A+SUPPRESS+NONE+SELECTION%7C%7CUI%3A+CONSTANT+GUIDING+TEXT%7C%7C_dsku%7C%7CUI%3A+DISPLAY+ADDITIONAL+"
		"INFO%7C%7C_startdate%7C%7C_enddate%7C%7C_sku%7C%7CHP_CROSSSELL_ITEMS%7C%7CHP_MODEL_HAS_CROSS_SELL%7C%7CHP_CLASS_HAS_CROSS_SELL%22%7D%5D%2C%22country%22%3A%22US%22%2C%22language%22%3A%22en%22%2C%22organizationCode%22%3A%22US_Store%22%2C%22path%22%3A%22US_005FStore%2FStore%2F{p_Mobgetconfig}%22%7D&callback=_jqjsp", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("HPCTOServices", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/HPCTOServices?&partNumbers={p_mobpartnum}&fromAttach=true", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/AccessoryAttachView?shipDate=10%2F04%2F2021&selectedRecommConfig=recConfig1&catEntryId=3074457345619699821&storeId=10151",
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
	

	if((atoi(lr_eval_string("{c_orderId1}"))>0) && (atoi(lr_eval_string("{c_orderItemId1}"))>0))
	{
		lr_end_transaction("S23_Mob_HPCTORestAddToCart_CTO",LR_PASS);
	}
	
	else
	{
		lr_end_transaction("S23_Mob_HPCTORestAddToCart_CTO",LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		
	}
	
	
	lr_think_time(15);
			
	lr_start_transaction("S25_Mob_RemoveCart");
		
	web_submit_data("AjaxOrderChangeServiceItemDelete", 
		"Action=https://{p_hostName}/us-en/shop/AjaxOrderChangeServiceItemDelete", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=http%3AOrderCalculate", 
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
	
	return 0;
}
