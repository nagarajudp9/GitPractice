AddToCart_CTO()
{
	
	
		lr_think_time(60);
	web_set_max_html_param_len("99999");
	web_set_max_retries ("5") ;
	
	if(strcmp(lr_eval_string("{cp_CatEntryID}"),"")==0 )		                   
	{
				
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	

if( loyaltyflag == 1)  //AddToCart for Loyalty user
	{
		lr_start_transaction("S23_AddToCart_CTO");
	
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
	
	
	web_convert_param("FinalarrComponent1", "SourceEncoding=URL","TargetEncoding=PLAIN", LAST );
 	web_convert_param("FinalarrPriceSku1", "SourceEncoding=URL","TargetEncoding=PLAIN", LAST );
 	

	web_custom_request("addtocartconfig", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/component/configure/addtocartconfig?responseFormat=json&catalogId=10051&langId=-1&quantity=1", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/ConfigureView?langId=-1&storeId=10151&catalogId=10051&catEntryId={cp_CatEntryID}&urlLangId=&quantity=1", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"inputJson\":{\"country\":\"US\",\"currency\":\"USD\",\"language\":\"en\",\"organizationCode\":\"US_Store\",\"picks\":{\"pick\":[{FinalarrComponent1}]},\"path\":\"{p_ModelRef1}\"},\"inJSONData\":{\"skuPriceJSON\":[{FinalarrPriceSku1}],\"derivedSku\":\"\"},\"currentDate\":\"{p_CurrentDate}\",\"catEntryId\":\"{cp_CatEntryID}\",\"configCatentryId\":\"{cp_CatEntryID}\",\"hasAccessories\":\"true\",\"shipDate\":\"{ShipDate}\",\"leadDays\":\"20.0\"}", 
		LAST);

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
	
	web_url("accessoriesattach", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/component/cto/accessoriesattach?langId=-1&storeId=10151&catalogId=10051&catEntryId={cp_CatEntryID}&configCatentryId={cp_CatEntryID}&responseFormat=json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/AccessoryAttachView?catalogId=10051&storeId=10151&langId=-1&catentryId={cp_CatEntryID}&configCatentryId={cp_CatEntryID}", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	web_url("dealsapi_3", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/product-group/dealsapi?_=1627102170249", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/AccessoryAttachView?catalogId=10051&storeId=10151&langId=-1&catentryId={cp_CatEntryID}&configCatentryId={cp_CatEntryID}", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

web_convert_param("cp_ConfigSKUS1",
	                  "SourceString={p_ConfigSKUS1}",
	                  "SourceEncoding=URL",
	                  "TargetEncoding=HTML",
	                  LAST);
	

	web_url("HPCTOServices", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/HPCTOServices?storeId=10151&langId=-1&parentPartNum={p_PartNumber}&partNumbers={cp_ConfigSKUS1}&fromAttach=true", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/AccessoryAttachView?catalogId=10051&storeId=10151&langId=-1&catentryId={cp_CatEntryID}&configCatentryId={cp_CatEntryID}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);



	
	
	if(atoi(lr_eval_string("{C_cartAdded}"))>0)
    {
	lr_end_transaction("S23_AddToCart_CTO",LR_PASS);
    }
    else
    {
	lr_end_transaction("S23_AddToCart_CTO",LR_FAIL);
	
    lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
    }
	


}

else
	
{
		
		lr_start_transaction("S23_AddToCart_CTO");
	
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
	
	web_url("accessoriesattach", 
		"URL=https://{p_hostName}/wcs/resources/store/10151/component/cto/accessoriesattach?langId=-1&storeId=10151&catalogId=10051&catEntryId={cp_CatEntryID}&configCatentryId={cp_CatEntryID}&responseFormat=json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/AccessoryAttachView?catalogId=10051&storeId=10151&langId=-1&catentryId={cp_CatEntryID}&configCatentryId={cp_CatEntryID}", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	web_url("dealsapi_3", 
		"URL=https://{p_hostName}/us-en/shop/app/api/web/product-group/dealsapi?_=1627102170249", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/AccessoryAttachView?catalogId=10051&storeId=10151&langId=-1&catentryId={cp_CatEntryID}&configCatentryId={cp_CatEntryID}", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_convert_param("cp_ConfigSKUS",
	                  "SourceString={p_ConfigSKUS}",
	                  "SourceEncoding=URL",
	                  "TargetEncoding=HTML",
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
	lr_end_transaction("S23_AddToCart_CTO",LR_PASS);
    }
    else
    {
	lr_end_transaction("S23_AddToCart_CTO",LR_FAIL);
	
    lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
    }
	

}
	
	web_set_max_html_param_len("1024");
	
	lr_think_time(1);
	return 0;
}
