DealsPage()
{
	
	
	lr_think_time(60);
		
	web_reg_find("Search=All",
		"SaveCount=c_OfficialStore",
		"Text=Official Site",
		LAST);
	
	lr_start_transaction("CP17_Dealspage");
	
	web_url("DealsView",
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsView?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1505911390976&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/DealsView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("CP17_Dealspage",LR_AUTO);
	
	
	
	return 0;
}
