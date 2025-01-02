SignIn()
{
	Home();
	
	lr_think_time(60);

	web_set_max_html_param_len("99999");
	
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	web_reg_find("Text=HPID Login", 
		LAST);
	
	lr_start_transaction(lr_eval_string("{AgentType}S01_LogonForm"));

	web_reg_save_param("cp_AuthLogin","LB=authentication/login/","RB=\r\n","ORD=1","Notfound=Warning",LAST);

	web_url("authorize", 
		"URL=https://directory.stg.cd.id.hp.com/directory/v1/oauth/authorize?response_type=code&client_id={cp_ClientID}&redirect_uri=https%3A%2F%2F{p_hostName}%2Fwebapp%2Fwcs%2Fstores%2Fservlet%2FETRLogonFlow%3FcatalogId%3D10051%26langId%3D-1%26storeId%3D10151&scope=openid+email+profile+user.profile.write+user.profile.username+user.profile.read+offline_access&state=operation:login&nonce=en&prompt=consent", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
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
/*
	web_url("2.0f580d4f.chunk.css.map", 
		"URL=https://static.stg.cd.id.hp.com/login3/static/css/2.0f580d4f.chunk.css.map", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_url("main.35961ab9.chunk.css.map", 
		"URL=https://static.stg.cd.id.hp.com/login3/static/css/main.35961ab9.chunk.css.map", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_url("2.651019e0.chunk.js.map", 
		"URL=https://static.stg.cd.id.hp.com/login3/static/js/2.651019e0.chunk.js.map", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("common.json", 
		"URL=https://login3.stg.cd.id.hp.com/login3/locales/en_US/common.json?v=1.3.28", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_url("main.366ab199.chunk.js.map", 
		"URL=https://static.stg.cd.id.hp.com/login3/static/js/main.366ab199.chunk.js.map", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("countries.json", 
		"URL=https://login3.stg.cd.id.hp.com/login3/locales/en_US/countries.json?v=1.3.28", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);
*/
	lr_end_transaction(lr_eval_string("{AgentType}S01_LogonForm"),LR_AUTO);
	
	return 0;
}
