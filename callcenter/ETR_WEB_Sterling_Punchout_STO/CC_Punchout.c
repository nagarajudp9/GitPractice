CC_Punchout()
{
	
	
	//web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	CustomerFlag=0;
	
	if(strcmp("YES",lr_eval_string("{CustomerSearch}"))==0)
	{
	
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");	
		
	lr_start_transaction("C05_CS_OpenPunchOut");

web_set_max_retries ("5") ;
//	web_reg_find("Text=WebStore SignIn For Callcenter Agents",
//		LAST);

	web_url("browseEstore", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/browseEstore?storeId=10151&ccCustId={cp_CustomerKey}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("C05_CS_OpenPunchOut",LR_AUTO);
	
	web_reg_save_param("cp_krypto","LB=krypto=","RB=&ddkey","Notfound=warning",LAST);

	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
	lr_start_transaction("C06_WebLogin");

//	web_reg_find("Text=HP Store Laptops, Desktops, Printers, Tablets &amp; More | HP.com Official Store", 
//		LAST);


	web_submit_data("cclogon", 
		"Action=https://{p_hostName}/webapp/wcs/stores/servlet/cclogon", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=URL", "Value=browseEstore", ENDITEM, 
		"Name=reLogonURL", "Value=ccStoreLogonView", ENDITEM, 
		"Name=ccCustId", "Value=", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=logonId", "Value={p_CSRuserName}", ENDITEM, 
		"Name=logonPassword", "Value={p_CSRpassword}", ENDITEM, 
		"Name=csrLoginBtn", "Value=", ENDITEM, 
		LAST);



	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513234814929&action=cupis&catentryId=1514654%2C3074457345618494834%2C1075162%2C582661%2C1543651%2C1661653%2C1661652&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/TopCategoriesDisplay?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3Acclogon", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("C06_WebLogin",LR_AUTO);
	
	}
	
	else
		
	{
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");	
		
	lr_start_transaction("C05_OpenPunchOut");

//	web_reg_find("Text=WebStore SignIn For Callcenter Agents", 
	//	LAST);

	
	web_url("browseEstore", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/browseEstore?storeId=10151&ccCustId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
	    "Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("C05_OpenPunchOut",LR_AUTO);

//	web_reg_find("Text=HP Store Laptops, Desktops, Printers, Tablets &amp; More | HP.com Official Store", 
//		LAST);
	
	web_reg_save_param("cp_krypto","LB=krypto=","RB=&ddkey","Notfound=warning",LAST);
	
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
	lr_start_transaction("C06_WebLogin");

	web_set_max_retries ("5") ;
	
	web_submit_data("cclogon", 
		"Action=https://{p_hostName}/webapp/wcs/stores/servlet/cclogon", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=URL", "Value=browseEstore", ENDITEM, 
		"Name=reLogonURL", "Value=ccStoreLogonView", ENDITEM, 
		"Name=ccCustId", "Value=", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=logonId", "Value={p_CSRuserName}", ENDITEM, 
		"Name=logonPassword", "Value={p_CSRpassword}", ENDITEM, 
		"Name=csrLoginBtn", "Value=", ENDITEM, 
		LAST);



	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513234814929&action=cupis&catentryId=1514654%2C3074457345618494834%2C1075162%2C582661%2C1543651%2C1661653%2C1661652&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/TopCategoriesDisplay?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3Acclogon", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("C06_WebLogin",LR_AUTO);
	
	
	
	}
	
	
	return 0;
}
