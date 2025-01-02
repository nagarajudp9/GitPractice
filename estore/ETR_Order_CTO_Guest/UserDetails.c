UserDetails()
{
		
	web_set_sockets_option("SSL_VERSION", "TLS1.2");	
	
	web_cache_cleanup();
	web_cleanup_auto_headers();
	web_cleanup_cookies();		
	
	lr_start_transaction("S60_UniqueVistors");
	lr_end_transaction("S60_UniqueVistors",LR_AUTO);
	
	web_set_max_html_param_len("1024");
	
	lr_save_string("","AgentType");
	lr_save_string("","cartitem");
	lr_save_string("","cartLineitem");
	
	CarepackFlag=0,LoginFlag=0,Stoflag=0;
	prandNumber=0;
	
	return 0;
}
