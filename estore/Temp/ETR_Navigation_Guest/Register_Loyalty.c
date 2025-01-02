Register_Loyalty()
{
	Home();
	
	lr_think_time(30);
	
	lr_start_transaction(lr_eval_string("{AgentType}S36_LoyaltyLanding"));

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("LoadLoyaltyLandingPageCmd", 
		"URL=https://{p_hostName}/us-en/shop/LoadLoyaltyLandingPageCmd?catalogId=10051&userTyp=G&storeId=10151", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1613311917282&action=cupids&catentryId=&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/LoadLoyaltyLandingPageCmd?catalogId=10051&userTyp=G&storeId=10151", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction(lr_eval_string("{AgentType}S36_LoyaltyLanding"),LR_AUTO);
	
	//Home();
	
	lr_start_transaction(lr_eval_string("{AgentType}S36_SignUp"));

	web_set_max_html_param_len("764");
		
	web_reg_find("Text=HPID Login", 
		LAST);

	web_add_header("Upgrade-Insecure-Requests", 
		"1");
	
	web_reg_save_param("cp_AuthLogin","LB=authentication/login/","RB=&target","ORD=1","Notfound=Warning",LAST);

	web_url("authorize", 
		"URL=https://directory.stg.cd.id.hp.com/directory/v1/oauth/authorize?response_type=code&client_id={cp_ClientID}&redirect_uri=https%3A%2F%2F{p_hostName}%2Fwebapp%2Fwcs%2Fstores%2Fservlet%2FETRLogonFlow%3FcatalogId%3D10051%26langId%3D-1%26storeId%3D10151&scope=openid+email+profile+user.profile.write+user.profile.username+user.profile.read+offline_access&state=operation:register&nonce=en&prompt=consent&target=create", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("common.json", 
		"URL=https://login3.stg.cd.id.hp.com/login3/locales/en_US/common.json?v=1.3.28", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_url("countries.json", 
		"URL=https://login3.stg.cd.id.hp.com/login3/locales/en_US/countries.json?v=1.3.28", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("X-Requested-With");

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
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	
	
	web_reg_save_param("cp_CSRFToken","LB=csrfToken\":\"","RB=\"","ORD=1","Notfound=Warning",LAST);
	
	web_reg_save_param("cp_Captcha","LB=arkose\",\"data\":\"","RB=\"","ORD=1","Notfound=Warning",LAST);

	web_custom_request("session_2", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/auth/session", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t7.inf", 
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
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("Origin");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("Access-Control-Request-Headers", 
		"csrf-token");

	web_add_auto_header("Access-Control-Request-Method", 
		"GET");

	web_add_auto_header("Origin", 
		"https://login3.stg.cd.id.hp.com");

	web_custom_request("tncs", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/session/sign-up/tncs?locale=en_US&country=IN", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("supported-countries", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/session/sms/supported-countries", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("Access-Control-Request-Headers");

	web_revert_auto_header("Access-Control-Request-Method");

	web_add_header("CSRF-TOKEN", 
		"{cp_CSRFToken}");

	web_url("tncs_2", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/session/sign-up/tncs?locale=en_US&country=IN", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("CSRF-TOKEN", 
		"{cp_CSRFToken}");

	web_url("supported-countries_2", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/session/sms/supported-countries", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("CSRF-TOKEN={cp_CSRFToken}; DOMAIN=login3.stg.cd.id.hp.com");

	web_revert_auto_header("Origin");

	web_url("sign-up", 
		"URL=https://login3.stg.cd.id.hp.com/login3/sign-up", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);


	
	lr_end_transaction(lr_eval_string("{AgentType}S36_SignUp"), LR_AUTO);

	
	
	web_set_max_html_param_len("1024");
	
	LoginFlag=1;
	
	return 0;
}
