UserDetails()
{
	
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	web_set_max_html_param_len("91024");
	
	web_cache_cleanup();
	web_cleanup_auto_headers();
	web_cleanup_cookies();	
	
	
	lr_save_string("","AgentType");
	
	
	SignInFormFlag=0, GuestFlag=0, LoginFlag=0, hpeppFlag=0, eppFlag=0, gsFlag=0, SmbFlag=0, CarepackFlag=0;
	
	pmaxValue=0, prandNumber=0;
	
	lr_save_string("NO","CTO");
	lr_save_string("NO","Supplies");
	lr_save_string("NO","PDP");
	lr_save_string("","StoreType");
	
	return 0;
}
