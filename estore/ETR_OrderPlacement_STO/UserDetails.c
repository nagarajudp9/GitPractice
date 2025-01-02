UserDetails()
{
   
	web_set_sockets_option("SSL_VERSION", "TLS1.2");	
	
	web_cache_cleanup();
	
	web_cleanup_auto_headers();
	
	web_cleanup_cookies();	
	
	SignInFormFlag=0, GuestFlag=0, LoginFlag=0, hpeppFlag=0, eppFlag=0, gsFlag=0, ctoFlag=0, gs_ccFlag=0, orderflag=0, euaFlag=0, CarepackFlag=0,silverFlag=0,goldFlag=0,platinumFlag=0,Preorder=0;
		
	lr_save_string("NO","CTO");	
	lr_save_string("NO","Supplies");	
	lr_save_string("NO","PDP");	
	lr_save_string("","cp_LoginPaySessionID");	
	lr_save_string("","StoreType");	
	lr_save_string("","StoreType1");	
	lr_save_string("","AgentType");
	lr_save_string("0","cp_iCount");
	lr_save_string("","cartitem");
	
	lr_start_transaction("S60_UniqueVistors");
	lr_end_transaction("S60_UniqueVistors",LR_AUTO);
	
	web_set_max_html_param_len("99999");
	


	return 0;
}
