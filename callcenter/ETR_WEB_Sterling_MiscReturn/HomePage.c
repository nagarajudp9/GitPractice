HomePage()
{
	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_reg_find("Text=IBM Call Center for Commerce", 
		LAST);
	
	
	lr_start_transaction("C00_Homepage");

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	
	web_url("login.do", 
		"URL=https://{p_SterlingHostName}/isccs/isccs/login.do", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");


	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");


	lr_end_transaction("C00_Homepage",LR_AUTO);

lr_think_time(20);

	return 0;
}
