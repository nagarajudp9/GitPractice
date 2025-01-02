CTO_Web()
{
	web_set_max_html_param_len("999999");
	
	if(strcmp(lr_eval_string("{cp_CatEntryID}"),"")==0 )
		
	{
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
		}
	
	lr_start_transaction("CP20_CustomizeAndBuy");

	
	//web_reg_save_param("cp_SecureKey","LB=var shaPwd = \"","RB=\";",LAST);
	//web_reg_save_param("cp_LeadDays","LB=var _leadDays = \"","RB=\";",LAST);
	
	web_reg_find("Search=All","SaveCount=c_CTOWeb1","Text=ConfigureView",LAST);


web_url("sync",
		"URL=https://{p_hostName}/us-en/shop/app/api/web/graphql/page/ConfigureView%3FlangId%3D-1%26storeId%3D10151%26catalogId%3D10051%26catEntryId%3D{cp_CatEntryID}%26urlLangId%3D%26quantity%3D1/sync", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?langId=-1&storeId=10151&catalogId=10051&catEntryId={cp_CatEntryID}&urlLangId=&quantity=1", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	


if(strcmp(lr_eval_string("{cp_SecureKey}"),"")==0 || strcmp(lr_eval_string("{cp_LeadDays}"),"")==0 || strcmp(lr_eval_string("{c_CTOWeb1}"),"0")==0 ||strcmp(lr_eval_string("{c_CTOWeb2}"),"0")==0)
	{
		lr_end_transaction(lr_eval_string("CP20_CustomizeAndBuy"),LR_FAIL);
		
		CC_Logout();    		
       		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	web_convert_param("cname",
	                  "SourceString={productName}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	
		web_convert_param("cp_pdpname",
	                  "SourceString={productName}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	
	
web_convert_param("cp_ConfigSKUS",
	                  "SourceString={p_ConfigSKUS}",
	                  "SourceEncoding=URL",
	                  "TargetEncoding=HTML",
	                  LAST);

 web_reg_save_param("parentPartNum","LB=item\":\"","RB=\"}",LAST);

  web_custom_request("processconfigurationpicksjson", 
		"URL=https://{p_ctohostName}/SterlingConfigRESTfulWebSvcApp/rest/configs/json/processconfigurationpicksjson?webSvcSessionID=&tokenID=&apiTemplateJSONString=&inJSONString=%7B%22include%22%3A%5B%7B%22clazz%22%3A%22Messages%22%7D%2C%7B%22clazz%22%3A%22Property%22%2C%22name%22%3A%22_isViewable%7C%7C_quantity%7C%7C_rulePick%7C%7CUI%3A+PRE+PICK+GUIDING+TEXT%7C%7CUI%3A+POST+PICK+GUIDING+TEXT%7C%7CUI%3A+SUPPRESS+NONE+SELECTION%7C%7CUI%3A+"
		"REQUIRED%7C%7C_dsku%22%7D%5D%2C%22country%22%3A%22US%22%2C%22currency%22%3A%22USD%22%2C%22language%22%3A%22en%22%2C%22organizationCode%22%3A%22US_Store%22%2C%22path%22%3A%22{cp_ModelRefParam}%22%2C%22picks%22%3A%7B%22pick%22%3A%5B{FinalarrComponent}%5D%7D%2C%22addPick%22%3A%5B%5D%2C%22removePick%22%3A%5B%5D%7D&callback="
		"_jqjsp", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?catalogId=10051&urlLangId=&langId=-1&storeId=10151&catEntryId={cp_CatEntryID}&quantity=1", 
		"Snapshot=t452.inf", 
		LAST);

 
 web_reg_save_param("ShipDate","LB=shipDate\": \"","RB=\"}",LAST);
	
	web_url("getshipdate", 
		"URL=https://{p_ctohostName}/SterlingConfigRESTfulWebSvcApp/rest/configs/json/getshipdate?storeId=10151&webSvcSessionID=&apiTemplateJSONString=&calendarId=CTO-CALENDAR-NB&leadDays=20.0&currentDate={p_CurrentDate}&callback=_ship_id", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	  if(strcmp(lr_eval_string("{parentPartNum}"),"")==0)
	{
		lr_end_transaction(lr_eval_string("CP20_CustomizeAndBuy"),LR_FAIL);
		
		CC_Logout();    		
       		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	  web_convert_param("SortedPrimarySku",
	                  "SourceString={SortedPrimarySku}",
	                  "SourceEncoding=URL",
	                  "TargetEncoding=PLAIN",
	                  LAST);
	  
	//  web_reg_save_param("cp_krypto","LB=&krypto=","RB=&ddkey", LAST);
	  
	  lr_save_string(string_replace(lr_eval_string("{SortedPrimarySku}"),"#","%23"),"SortedPrimarySku01");
	  
	web_url("PriceStrikeThroughDynamicKitDisplayCmd", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/PriceStrikeThroughDynamicKitDisplayCmd?storeId=10151&usertype=&catentryId={cp_CatEntryID}&skus={SortedPrimarySku01}&crossSell=&pStoreId=&currentDate={p_CurrentDate}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?langId=-1&storeId=10151&catalogId=10051&catEntryId={cp_CatEntryID}&urlLangId=&quantity=1", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);
  
	
	 lr_end_transaction("CP20_CustomizeAndBuy",LR_AUTO);
 
	 lr_think_time(10);
	 
	 	web_set_max_html_param_len("1024");
	
	return 0;
}
