Login_PSA()
{
	
	
SignIn();
	
web_set_max_retries ("5");

lr_think_time(60);
	
	lr_start_transaction("CP02_UserLogin_PSA");
	web_add_header("Access-Control-Request-Headers", 
		"content-type");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"https://login3.stg.cd.id.hp.com");

	web_custom_request("session", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/auth/session", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param("cp_CSRFToken","LB=csrfToken\":\"","RB=\"","ORD=1","Notfound=Warning",LAST);

	web_custom_request("session_2", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/auth/session", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"flow\":\"https://directory.stg.cd.id.hp.com/directory/v1/authentication/login/"
		"{cp_AuthLogin}\"}", 
		LAST);

	web_url("country", 
		"URL=https://static.stg.cd.id.hp.com/login3/country", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("Origin");

	web_add_header("Access-Control-Request-Headers", 
		"content-type,csrf-token");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"https://login3.stg.cd.id.hp.com");

	web_custom_request("check-username", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/session/check-username", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);
	
	web_add_cookie("s_sq=hphqglobaldev%3D%2526pid%253Dhttps%25253A%25252F%25252Flogin3.stg.cd.id.hp.com%25252Flogin3%25253Fflow%25253Dhttps%25253A%25252F%25252Fdirectory.stg.cd.id.hp.com%25252Fdirectory%25252Fv1%25252Fauthentication%25252Flogin%25252F{cp_AuthLogin}%2526oid%253DfunctionWn%252528%252529%25257B%25257D%2526oidt%253D2%2526ot%253DSUBMIT; DOMAIN="
		"ui-backend.stg.cd.id.hp.com");

	web_add_header("CSRF-TOKEN", 
		"{cp_CSRFToken}");

	web_custom_request("check-username_2", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/session/check-username", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"username\":\"{p_psaUser}\"}", 
		LAST);

	web_add_header("Access-Control-Request-Headers", 
		"content-type,csrf-token");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_custom_request("username-password", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/session/username-password", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("CSRF-TOKEN", 
		"{cp_CSRFToken}");
	
	web_reg_save_param("cp_Code","LB=code=","RB=&state","ORD=1","Notfound=Warning",LAST);

	web_custom_request("username-password_2", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/session/username-password", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"username\":\"{p_psaUser}@hpid\",\"password\":\"{p_psaPassword}\"}", 
		LAST);
	
	web_add_header("Upgrade-Insecure-Requests", 
		"1");
	
	web_reg_save_param("cp_KryptoNew","LB=krypto=","RB=&ddkey","ORD=1","Notfound=Warning",LAST);
	
	web_reg_save_param("cp_Krypto","LB=&krypto=","RB=%3D&ddkey","ORD=1",LAST);
	
	web_reg_save_param_ex("ParamName=cp_clientip","LB=clientip:\"","RB=\",","Notfound=Warning",LAST);

	web_url("ETRLogonFlow", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/ETRLogonFlow?catalogId=10051&langId=-1&storeId=10151&code={cp_Code}&state=operation:login", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");
	
	//web_reg_find("Search=All","Text=\"userType\": \"A\"","savecount=Register",LAST);
	
	web_reg_find("Search=All","Text=Release Lock","savecount=Register",LAST);

	
	web_reg_save_param("cp_iCount","LB=\"iCount\": ","RB=,","Notfound=warning",LAST);

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1611899967465&action=cupids&catentryId=3074457345619573822%2C3074457345619562324%2C3074457345619562320%2C3074457345619533327%2C3074457345618514833%2C3074457345618982329%2C3074457345619317819%2C3074457345619673829%2C3074457345619534818&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/TopCategoriesDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_KryptoNew}&ddkey=https%3AETRLogonFlow", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		LAST);
	
	
	
	if(atoi(lr_eval_string("{Register}"))>0)
        {
		    
						
			lr_end_transaction("CP02_UserLogin_PSA",LR_PASS);
        }
    else
        {
    		    		
    		lr_end_transaction("CP02_UserLogin_PSA",LR_FAIL);
    		CC_Logout();    		
            lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
        }	
	
		
	lr_save_string(lr_eval_string("{p_psaUser}"), "p_userEmail");
	lr_save_string("?pStoreID=fedex","StoreType");
	lr_save_string("&pStoreID=fedex","StoreType1");
	
	LoginFlag=1;
	psaFlag=1;
	
	
	
	return 0;
}
