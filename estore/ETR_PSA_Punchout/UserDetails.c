UserDetails()
{
	
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	web_cache_cleanup();
	web_cleanup_auto_headers();
	web_cleanup_cookies();
	
	web_set_max_html_param_len("1024");
	
	SignInFormFlag=0, GuestFlag=0, LoginFlag=0, hpeppFlag=0, eppFlag=0, gsFlag=0, psaFlag=0;
	
	pmaxValue=0, prandNumber=0;
	
	lr_save_string("","AgentType");
	
	lr_start_transaction("S60_UniqueVistors");
	lr_end_transaction("S60_UniqueVistors",LR_AUTO);
		
	lr_save_string("NO","CTO");
	lr_save_string("NO","Supplies");
	lr_save_string("NO","PDP");
	
	
	return 0;
}
