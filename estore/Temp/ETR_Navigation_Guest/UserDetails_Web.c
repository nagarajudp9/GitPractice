UserDetails_Web()
{
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	web_set_max_html_param_len("4024");
	
	web_cache_cleanup();
	web_cleanup_auto_headers();
	web_cleanup_cookies();	
	
	lr_save_string("NO","CTO");
	lr_save_string("NO","Supplies");
	lr_save_string("NO","PDP");
	
	lr_save_string("","AgentType");
	
	lr_start_transaction(lr_eval_string("{AgentType}S60_UniqueVistors"));
	lr_end_transaction(lr_eval_string("{AgentType}S60_UniqueVistors"),LR_AUTO);
	
	GuestFlag=0,LoginFlag=0,mFound=0,pmaxValue=0, prandNumber=0,AddToCartFlag=0;
	
	return 0;
}
