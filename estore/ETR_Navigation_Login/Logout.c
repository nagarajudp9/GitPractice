Logout()
{
	
	if(LoginFlag==1)
	{
		
	lr_start_transaction(lr_eval_string("{AgentType}S00_Logout"));

	web_url("Logoff", 
		"URL=https://{p_hostName}/us-en/shop/Logoff?myAcctMain=1&catalogId=10051&langId=-1&deleteCartCookie=true&storeId=10151", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/TopCategoriesDisplayView?catalogId=10051&langId=-1&storeId=10151&pStoreID=bizclubplatinum", 
		"Referer=",
		"Snapshot=t35.inf",
		"Mode=HTML", 
		LAST);

	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1532670903295&action=cupids&catentryId=3074457345618619819%2C3074457345618619818%2C1543651%2C1243165&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/Logoff?myAcctMain=1&catalogId=10051&langId=-1&deleteCartCookie=true&storeId=10151", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("{AgentType}S00_Logout"),LR_AUTO);
	
	}
	
	LoginFlag=0;
	GuestFlag=0;
	return 0;
}
