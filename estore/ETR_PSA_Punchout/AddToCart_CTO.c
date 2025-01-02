AddToCart_CTO()
{
	
	
	web_set_max_html_param_len("99999");	
	
	if(strcmp(lr_eval_string("{cp_CatEntryID}"),"")==0 )		                   
	{
				
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
		
		
	lr_start_transaction("CP23_AddToCart_CTO");
	

	
	web_url("@self", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/person/@self", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?langId=-1&storeId=10151&catalogId=10051&catEntryId={cp_CatEntryID}&urlLangId=&quantity=1", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	
	web_add_auto_header("Origin", 
		"https://{p_hostName}");
/*
	web_custom_request("guestidentity", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/guestidentity?updateCookies=true", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?langId=-1&storeId=10151&catalogId=10051&catEntryId={cp_CatEntryID}&urlLangId=&quantity=1", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"params\":{\"updateCookies\":true}}", 
		LAST);
	
*/	
	web_convert_param("FinalarrComponent", "SourceEncoding=URL","TargetEncoding=PLAIN", LAST );
 	web_convert_param("FinalarrPriceSku", "SourceEncoding=URL","TargetEncoding=PLAIN", LAST );
 	

	web_custom_request("addtocartconfig", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/component/configure/addtocartconfig?responseFormat=json&catalogId=10051&langId=-1&quantity=1", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?langId=-1&storeId=10151&catalogId=10051&catEntryId={cp_CatEntryID}&urlLangId=&quantity=1", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"inputJson\":{\"country\":\"US\",\"currency\":\"USD\",\"language\":\"en\",\"organizationCode\":\"US_Store\",\"picks\":{\"pick\":[{FinalarrComponent}]},\"path\":\"{p_ModelRef}\"},\"inJSONData\":{\"skuPriceJSON\":[{FinalarrPriceSku}],\"derivedSku\":\"\"},\"currentDate\":\"{p_CurrentDate}\",\"catEntryId\":\"{cp_CatEntryID}\",\"configCatentryId\":\"{cp_CatEntryID}\",\"hasAccessories\":\"true\",\"shipDate\":\"{ShipDate}\",\"leadDays\":\"20.0\"}", 
		LAST);

//web_reg_save_param("cp_iCount","LB=\"iCount\": ","RB=,","Notfound=warning",LAST);


web_reg_save_param("cp_AddAccessories","LB=\"catentryId\":\"","RB=\",","Ordinal=All","Notfound=warning",LAST);


	
	web_url("accessoriesattach",
		"URL=https://{p_hostName}/wcs/resources/store/10151/component/configure/accessoriesattach?langId=-1&storeId=10151&catalogId=10051&catEntryId={cp_CatEntryID}&configCatentryId={cp_CatEntryID}&responseFormat=json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/AccessoryAttachView?catalogId=10051&storeId=10151&langId=-1&catEntryId={cp_CatEntryID}&configCatentryId={cp_CatEntryID}", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	
web_url("configure", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/seo/configure?path=%2Fus-en%2Fshop%2FAccessoryAttachView%3FcatalogId%3D10051%26storeId%3D10151%26langId%3D-1%26catEntryId%3D{cp_CatEntryID}%26shipDate%3D04%2F20%2F2022%26configCatentryId%3D{cp_CatEntryID}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/AccessoryAttachView?catalogId=10051&storeId=10151&langId=-1&catEntryId={cp_CatEntryID}&shipDate=04/20/2022&configCatentryId={cp_CatEntryID}", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

//"iCount": 2,
web_reg_save_param("cp_iCount","LB=iCount\": ","RB=,",LAST);

web_reg_find("Search=All","Text=Just added to cart","savecount=C_cartAdded",LAST);
	
	web_url("HPServices_5", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1627102161609&action=c&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AccessoryAttachView?catalogId=10051&storeId=10151&langId=-1&catentryId={cp_CatEntryID}&configCatentryId={cp_CatEntryID}", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);
	

	web_url("HPCTOServices", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/HPCTOServices?storeId=10151&langId=-1&parentPartNum={p_PartNumber}&partNumbers={cp_ConfigSKUS}&fromAttach=true", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/AccessoryAttachView?catalogId=10051&storeId=10151&langId=-1&catentryId={cp_CatEntryID}&configCatentryId={cp_CatEntryID}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	 
	
	if(atoi(lr_eval_string("{C_cartAdded}"))>0)
    {
	lr_end_transaction("CP23_AddToCart_CTO",LR_PASS);
    }
    else
    {
	lr_end_transaction("CP23_AddToCart_CTO",LR_FAIL);
	
    lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
    }
	
	lr_think_time(1);
	
		
	web_set_max_html_param_len("99999");
	
	return 0;
}
