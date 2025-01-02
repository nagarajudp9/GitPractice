UserDetails_Web()
{
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	web_set_max_html_param_len("1024");
	
	web_cache_cleanup();
	web_cleanup_auto_headers();
	web_cleanup_cookies();	
	
	lr_save_string("NO","CTO");
	lr_save_string("NO","Supplies");
	lr_save_string("NO","PDP");
	
	lr_save_string("","AgentType");
	
	lr_start_transaction(lr_eval_string("{AgentType}S60_UniqueVistors"));
	lr_end_transaction(lr_eval_string("{AgentType}S60_UniqueVistors"),LR_AUTO);
	SignInFormFlag=0, GuestFlag=0, LoginFlag=0, hpeppFlag=0, eppFlag=0, gsFlag=0,silverFlag=0,goldFlag=0,platinumFlag=0,pmaxValue=0, prandNumber=0,AddToCartFlag=0;
	
	lr_save_string("","StoreType");
	lr_save_string("","StoreType1");
	
	return 0;
}
