Business()


{
	
	int pmaxValue=0;
	
	web_save_timestamp_param("cp_time", LAST); //1600153594317  
	
	pmaxValue = atoi(lr_eval_string("{p_randnum}"));
	
	
		
if(pmaxValue>0 && pmaxValue<30)	

	{
	
	lr_start_transaction("S00_HpServices_Appstore");
	
	//lr_start_sub_transaction("S00-1_HpServices_Appstore_2to5Items","S00_HpServices_Appstore");
	
web_url("HPServices",
		"URL=https://{p_hostname}/us-en/shop/HPServices?_={cp_time}&action=cupids&catentryId={p_businesscatentryId_2}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostname}/us-en/shop/slp/", 
		"Snapshot=t111.inf", 
		"Mode=HTML", 
		LAST);
	//lr_end_sub_transaction("S00-1_HpServices_Appstore_2to5Items",LR_AUTO);
	
	
lr_end_transaction("S00_HpServices_Appstore", LR_AUTO);
   
	}
	
	else if(pmaxValue>30 && pmaxValue<80)

			{
	
	lr_start_transaction("S00_HpServices_Appstore");
	
	//lr_start_sub_transaction("S00-2_HpServices_Appstore_25_Items","S00_HpServices_Appstore");
	
	web_url("HPServices",
		"URL=https://{p_hostname}/us-en/shop/HPServices?_={cp_time}&action=cupids&catentryId={p_businesscatentryId_25}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostname}/us-en/shop/slp/", 
		"Snapshot=t111.inf", 
		"Mode=HTML", 
		LAST);
	//lr_end_sub_transaction("S00-2_HpServices_Appstore_25_Items",LR_AUTO);
	
	
lr_end_transaction("S00_HpServices_Appstore", LR_AUTO);
   
	}

else
{
	
	lr_start_transaction("S00_HpServices_Appstore");
	
//lr_start_sub_transaction("S00-3_HpServices_Appstore_50_Items","S00_HpServices_Appstore");

	web_url("HPServices",
		"URL=https://{p_hostname}/us-en/shop/HPServices?_={cp_time}&action=cupids&catentryId={p_businesscatentryId_50}&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostname}/us-en/shop/slp/", 
		"Snapshot=t111.inf", 
		"Mode=HTML", 
		LAST);
	//lr_end_sub_transaction("S00-3_HpServices_Appstore_50_Items",LR_AUTO);
	
lr_end_transaction("S00_HpServices_Appstore", LR_AUTO);
}

return 0;

}
