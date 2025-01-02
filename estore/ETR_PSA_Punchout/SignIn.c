SignIn()
{
	Home();
	
	lr_think_time(60);

//	web_set_max_html_param_len("99");
	
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	web_reg_find("Text=HPID Login", 
		LAST);
	
	lr_start_transaction("CP01_LogonForm");
	
	web_reg_save_param("cp_AuthLogin","LB=authentication/login/","RB=\r\n","ORD=1","Notfound=Warning",LAST);
	
	web_url("authorize", 
		"URL=https://directory.stg.cd.id.hp.com/directory/v1/oauth/authorize?response_type=code&client_id={cp_ClientID}&redirect_uri=https%3A%2F%2F{p_hostName}%2Fwebapp%2Fwcs%2Fstores%2Fservlet%2FETRLogonFlow%3FcatalogId%3D10051%26langId%3D-1%26storeId%3D10151&scope=openid+email+profile+user.profile.write+user.profile.username+user.profile.read+offline_access&state=operation:login&nonce=en&prompt=consent", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("CP01_LogonForm",LR_AUTO);
	
	SignInFormFlag=1;
		
	return 0;
}
