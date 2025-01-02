CC_OrderCreation()
{
	//web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_reg_save_param("cp_krypto","LB=krypto=","RB=&ddkey","Notfound=warning",LAST);
	
	web_reg_save_param("cp_PaySessionID","LB=JSESSIONID=0000","RB=:","Notfound=Warning",LAST);
	
	
web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");

	lr_start_transaction("C05_CC_OpenPunchOut");
	
	web_url("browseEstore", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/browseEstore?storeId=10151&ccCustId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("C05_CC_OpenPunchOut",LR_AUTO);
	
	
	web_reg_save_param("cp_AuthId","lb/dig=WC_AUTHENTICATION_########=","rb=;","notfound=warning",LAST);
	
	web_reg_save_param("cp_krypto","LB=krypto=","RB=&ddkey","Notfound=warning",LAST);
	
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
	lr_start_transaction("C06_CC_WebLogin");
	
	web_set_max_retries ("5") ;
	
	web_custom_request("cclogon",
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/cclogon", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"Body=URL=browseEstore&reLogonURL=ccStoreLogonView&ccCustId=&storeId=10151&logonId={p_CSRuserName}&logonPassword={p_CSRpassword}&csrLoginBtn=", 
		LAST);


	lr_end_transaction("C06_CC_WebLogin",LR_AUTO);
	
	
	
	//web_reg_find("Text=Customer Profile Search",		LAST);
	
	web_reg_save_param("cp_krypto","LB=krypto=","RB=&ddkey","Notfound=warning",LAST);
	
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
	lr_start_transaction("C02_CC_CustomerSearchLink");

	web_url("SearchUserView", 
		"URL=https://{p_hostName}/us-en/shopn/SearchUserView?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/TopCategoriesDisplay?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3Acclogon", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513234854468&action=cupis&catentryId=&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/SearchUserView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=http%3ASearchUserView", 
		"Snapshot=t46.inf", 
		"Mode=HTML", 
		LAST);

	
	lr_end_transaction("C02_CC_CustomerSearchLink",LR_AUTO);
	
	pmaxValue = atoi(lr_eval_string("{p_randomNo}"));			
	if(pmaxValue>0 && pmaxValue<5)
		{		
	
	web_reg_save_param("cp_CustomerKey","LB=\"MEMBER_ID\":","RB=,\"","Notfound=warning",LAST);
	
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
	
	lr_start_transaction("C03_CC_CS_ByEmail");

	web_submit_data("HPCCSearchUserCmd", 
		"Action=https://{p_hostName}/webapp/wcs/stores/servlet/HPCCSearchUserCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/SearchUserView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=http%3ASearchUserView", 
		"Snapshot=t54.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=URL", "Value=/", ENDITEM, 
		"Name=min_row", "Value=0", ENDITEM, 
		"Name=max_row", "Value=10", ENDITEM, 
		"Name=addressType", "Value=B", ENDITEM, 
		"Name=firstNameType", "Value=is", ENDITEM, 
		"Name=firstName", "Value=PFName", ENDITEM, 
		"Name=lastNameType", "Value=is", ENDITEM, 
		"Name=lastName", "Value=PLName", ENDITEM, 
		"Name=email1Type", "Value=contains", ENDITEM, 
		"Name=email1", "Value={p_CustomerSearchByEmail}", ENDITEM, 
		"Name=fullPhone", "Value=", ENDITEM, 
		"Name=phonenumberinput_Prt1", "Value=", ENDITEM, 
		"Name=phonenumberinput_Prt2", "Value=", ENDITEM, 
		"Name=phonenumberinput_Prt3", "Value=", ENDITEM, 
		"Name=zipCode", "Value=", ENDITEM, 
		LAST);

	lr_end_transaction("C03_CC_CS_ByEmail",LR_AUTO);
	
	web_reg_save_param("cp_krypto","LB=krypto=","RB=&ddkey","Notfound=warning",LAST);

	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
	lr_start_transaction("C04_CC_CustomerSelection");
	
//	web_reg_find("Text=HP Store Laptops, Desktops, Printers, Tablets &amp; More | HP.com Official Store", 
//		LAST);

	web_url("browseEstore_2", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/browseEstore?ccCustId={cp_CustomerKey}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t55.inf", 
		"Mode=HTML", 
		LAST);

	
	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513234927823&action=cupis&catentryId=1514654%2C3074457345618494834%2C1075162%2C582661%2C1543651%2C1661653%2C1661652&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/TopCategoriesDisplay?catalogId=10051&storeId=10151&krypto={cp_krypto}&ddkey=https%3AbrowseEstore", 
		"Snapshot=t58.inf", 
		"Mode=HTML", 
		LAST);

	
	lr_end_transaction("C04_CC_CustomerSelection",LR_AUTO);
	
	CustomerFlag=1;
	
	}
	
	else if(pmaxValue>=5 && pmaxValue<9)
	{
		
	web_reg_save_param("cp_CustomerKey","LB=\"MEMBER_ID\":","RB=,\"","Notfound=warning",LAST);	
	
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
		
	lr_start_transaction("C03_CC_CS_ByEmail");

	web_submit_data("HPCCSearchUserCmd", 
		"Action=https://{p_hostName}/webapp/wcs/stores/servlet/HPCCSearchUserCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/SearchUserView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=http%3ASearchUserView", 
		"Snapshot=t54.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=URL", "Value=/", ENDITEM, 
		"Name=min_row", "Value=0", ENDITEM, 
		"Name=max_row", "Value=10", ENDITEM, 
		"Name=addressType", "Value=B", ENDITEM, 
		"Name=firstNameType", "Value=is", ENDITEM, 
		"Name=firstName", "Value=PFName", ENDITEM, 
		"Name=lastNameType", "Value=is", ENDITEM, 
		"Name=lastName", "Value=PLName", ENDITEM, 
		"Name=email1Type", "Value=contains", ENDITEM, 
		"Name=email1", "Value={p_CustomerSearch_CCSaved}", ENDITEM, 
		"Name=fullPhone", "Value=", ENDITEM, 
		"Name=phonenumberinput_Prt1", "Value=", ENDITEM, 
		"Name=phonenumberinput_Prt2", "Value=", ENDITEM, 
		"Name=phonenumberinput_Prt3", "Value=", ENDITEM, 
		"Name=zipCode", "Value=", ENDITEM, 
		LAST);

	lr_end_transaction("C03_CC_CS_ByEmail",LR_AUTO);
	
	web_reg_save_param("cp_krypto","LB=krypto=","RB=&ddkey","Notfound=warning",LAST);
	
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");

	lr_start_transaction("C04_CC_CustomerSelection");
	
//	web_reg_find("Text=HP Store Laptops, Desktops, Printers, Tablets &amp; More | HP.com Official Store", 
//		LAST);

	web_url("browseEstore_2", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/browseEstore?ccCustId={cp_CustomerKey}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t55.inf", 
		"Mode=HTML", 
		LAST);

	
	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513234927823&action=cupis&catentryId=1514654%2C3074457345618494834%2C1075162%2C582661%2C1543651%2C1661653%2C1661652&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/TopCategoriesDisplay?catalogId=10051&storeId=10151&krypto={cp_krypto}&ddkey=https%3AbrowseEstore", 
		"Snapshot=t58.inf", 
		"Mode=HTML", 
		LAST);

	
	lr_end_transaction("C04_CC_CustomerSelection",LR_AUTO);
	
	CustomerFlag=1;
	
	gs_ccFlag=0;
	
		
	}
	
	else
	{
		
		web_reg_save_param("cp_CustomerKey","LB=\"MEMBER_ID\":","RB=,\"","Notfound=warning",LAST);
		
		web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
		
		lr_start_transaction("C03_CC_CS_ByEmail");
		
		
		web_submit_data("HPCCSearchUserCmd", 
		"Action=https://{p_hostName}/us-en/shop/HPCCSearchUserCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/SearchUserView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=URL", "Value=/", ENDITEM, 
		"Name=min_row", "Value=0", ENDITEM, 
		"Name=max_row", "Value=10", ENDITEM, 
		"Name=addressType", "Value=B", ENDITEM, 
		"Name=firstNameType", "Value=is", ENDITEM, 
		"Name=firstName", "Value=PFName", ENDITEM, 
		"Name=lastNameType", "Value=is", ENDITEM, 
		"Name=lastName", "Value=PLName", ENDITEM, 
		"Name=email1Type", "Value=is", ENDITEM, 
		"Name=email1", "Value={p_CSbySMBProfile}", ENDITEM, 
		"Name=fullPhone", "Value=", ENDITEM, 
		"Name=phonenumberinput_Prt1", "Value=", ENDITEM, 
		"Name=phonenumberinput_Prt2", "Value=", ENDITEM, 
		"Name=phonenumberinput_Prt3", "Value=", ENDITEM, 
		"Name=zipCode", "Value=", ENDITEM, 
		LAST);
		
	lr_end_transaction("C03_CC_CS_ByEmail",LR_AUTO);
	
	web_reg_save_param("cp_krypto","LB=krypto=","RB=&ddkey","Notfound=warning",LAST);
	
	web_reg_save_param("cp_orderId","LB=<input type=\"hidden\" name=\"orderId\" id=\"orderId\" value=\"","RB=\"/>","Notfound=warning",LAST);	
	web_reg_save_param("cp_orderItemId","LB=\"productrow\" id=\"cItem","RB=\">","ORD=ALL","Notfound=warning",LAST);		
	
web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");

	lr_start_transaction("C04_CC_CustomerSelection");
	
//	web_reg_find("Text=HP Store Laptops, Desktops, Printers, Tablets &amp; More | HP.com Official Store", 
//		LAST);

	web_url("browseEstore_2", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/browseEstore?ccCustId={cp_CustomerKey}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t55.inf", 
		"Mode=HTML", 
		LAST);

	
	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1513234927823&action=cupis&catentryId=1514654%2C3074457345618494834%2C1075162%2C582661%2C1543651%2C1661653%2C1661652&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/TopCategoriesDisplay?catalogId=10051&storeId=10151&krypto={cp_krypto}&ddkey=https%3AbrowseEstore", 
		"Snapshot=t58.inf", 
		"Mode=HTML", 
		LAST);

	
	lr_end_transaction("C04_CC_CustomerSelection",LR_AUTO);
	
	CustomerFlag=1;
	
	SmbFlag=1;	
	
	pmaxValue = atoi(lr_eval_string("{cp_orderItemId_count}"));	
	if(pmaxValue>0)
	{
		RemoveCart();
	}
	
		
	
	}
	
	
pmaxValue=0;
prandNumber=0;

	
	return 0;
}
