Login_GS()
{
	
	SignIn();
	
	lr_think_time(60);
	
	lr_start_transaction(lr_eval_string("{AgentType}S02_UserLogin_GS"));
	
	lr_start_sub_transaction(lr_eval_string("{AgentType}S02-1_HPID_UserLogin_GS"),lr_eval_string("{AgentType}S02_UserLogin_GS"));

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
		"Body={\"username\":\"{p_gsUser}\"}", 
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
		"Body={\"username\":\"{p_gsUser}@hpid\",\"password\":\"{p_password}\"}", 
		LAST);

	lr_end_sub_transaction(lr_eval_string("{AgentType}S02-1_HPID_UserLogin_GS"),LR_AUTO);

	lr_start_sub_transaction(lr_eval_string("{AgentType}S02-2_ETR_UserLogin_GS"),lr_eval_string("{AgentType}S02_UserLogin_GS"));

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
	
	web_reg_find("Search=All","Text=\"userType\": \"R\"","savecount=Register",LAST);
	
	web_reg_save_param("cp_iCount","LB=\"iCount\": ","RB=,","Notfound=warning",LAST);

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1611899967465&action=cupids&catentryId={HomeURL}&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/TopCategoriesDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_KryptoNew}&ddkey=https%3AETRLogonFlow", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		LAST);
	
	if(atoi(lr_eval_string("{Register}"))>0)
        {
		    
			lr_end_sub_transaction(lr_eval_string("{AgentType}S02-2_ETR_UserLogin_GS"),LR_PASS);
			
			lr_end_transaction(lr_eval_string("{AgentType}S02_UserLogin_GS"),LR_PASS);
        }
    else
        {
    		lr_end_sub_transaction(lr_eval_string("{AgentType}S02-2_ETR_UserLogin_GS"),LR_FAIL);
    		
    		lr_end_transaction(lr_eval_string("{AgentType}S02_UserLogin_GS"),LR_FAIL);
    		
            lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
        }	
	
	
	LoginFlag=1;
	gsFlag=1;	
	
	lr_save_string(lr_eval_string("{p_gsUser}"), "p_userEmail"); 
	lr_save_string("","StoreType");
	lr_save_string("","StoreType1");
	
	return 0;
}
