UserDetails_Mob()
{
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	web_set_max_html_param_len("1024");
	
	web_cache_cleanup();
	web_cleanup_auto_headers();
	web_cleanup_cookies();	
	
	lr_save_string("NO","CTO");
	lr_save_string("NO","Supplies");
	lr_save_string("NO","PDP");

	web_add_header("User-Agent","{p_mUserAgent}"); /*MobileFlow*/
	
	lr_save_string("Mob_","AgentType");
	
	lr_start_transaction(lr_eval_string("{AgentType}S60_UniqueVistors"));
	lr_end_transaction(lr_eval_string("{AgentType}S60_UniqueVistors"),LR_AUTO);
	
	lr_save_string("","StoreType");
	lr_save_string("","StoreType1");
	
	return 0;
}
