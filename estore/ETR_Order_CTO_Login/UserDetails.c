UserDetails()
{
	
	web_cache_cleanup();
	web_cleanup_auto_headers();
	web_cleanup_cookies();
	
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	lr_save_string("","StoreType");
	lr_save_string("","StoreType1");
	
	lr_save_string("","AgentType");
	lr_save_string("","cartitem");
		
	web_set_max_html_param_len("1024");
	
	lr_start_transaction("S60_UniqueVistors");
	lr_end_transaction("S60_UniqueVistors",LR_AUTO);
	
	gsFlag=0, gs_ccFlag=0, euaFlag=0, silverFlag=0,goldFlag=0,platinumFlag=0,LoginFlag=0,loyaltyflag=0;
	

	return 0;
}
