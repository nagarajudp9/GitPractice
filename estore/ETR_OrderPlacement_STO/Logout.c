Logout()
{
	
	if(LoginFlag==1)
	{
		
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1"); 
	web_reg_find("Text=<title>Sign In", LAST);		
	
	lr_start_transaction("S00_Logout");
	
	web_url("Logoff", 
		"URL=https://{p_hostName}/us-en/shop/Logoff?catalogId=10051&myAcctMain=1&langId=-1&storeId=10151&deleteCartCookie=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t78.inf", 
		"Mode=HTML", 
		LAST);
		
		
	web_url("HPServices_9", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1532680635287&action=cupis&catentryId=3074457345618619819%2C3074457345618619818%2C1543651%2C1243165&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/", 
		"Snapshot=t145.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("S00_Logout",LR_AUTO);
		
	}
	
	LoginFlag=0;
	GuestFlag=0;
	
	
	return 0;
}
