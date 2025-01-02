CC_Logout()
{
	
web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	lr_start_transaction("CP30_EndCall");
	
	web_url("browseEstore_3", 
		"URL=https://{p_hostName}/us-en/shop/browseEstore?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html;charset=UTF-8", 
		//"Referer=http://{p_hostName}/webapp/wcs/stores/servlet/TopCategoriesDisplay?catalogId=10051&storeId=10151&krypto=MgAJar2j2aZbjugfAG531xVkRS6ocbCc7bh0tGnEIuCgAhnWN8lkJPzoFdZA3ApEZQg38aHYcFDmPanXaDkK6TvzH7t91ZHaYmRFjYN%2FQ4%2F9YssnHvadAmqFPuaio9l%2F8j%2FzbmJWtrroO0wxUPp5jc4UkmYWO3AN69R1w1bw%2BkM%3D&ddkey=https%3AbrowseEstore", 
		"Referer=",
		"Snapshot=t63.inf",
		"Mode=HTML", 
		LAST);

	
	lr_end_transaction("CP30_EndCall",LR_AUTO);
	
	web_reg_find("Text=Callcenter Generic Page", 
		LAST);
	
	web_reg_save_param("cp_krypto","LB=&krypto=","RB=&ddkey","Notfound=warning",LAST);
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	lr_start_transaction("CP30_Logout");
	

	web_url("ccEndCustomerCall", 
		"URL=https://{p_hostName}/us-en/shop/ccEndCustomerCall?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html;charset=UTF-8", 
		//"Referer=http://{p_hostName}/webapp/wcs/stores/servlet/TopCategoriesDisplay?catalogId=10051&langId=-1&storeId=10151&krypto=hPGCQHDV2irOX49ZEviI9ENZKaWXVm6hPyvUObb2OjSvsln%2Bjo4xsNiVzk%2FutWuiGNcbZFPNkMNJi7REnaIiCze%2BIQZv1OUq8pSPMsWoYcETCNRcPZxThUMjIUQgms4R6vcAhiFF3E7UUrRrMtARHCQErwD3g07BgDOh2VhMtv0%3D&ddkey=http%3AbrowseEstore", 
		"Referer=",
		"Snapshot=t71.inf",
		"Mode=HTML", 
		LAST);
	

	lr_end_transaction("CP30_Logout",LR_AUTO);
	

	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	lr_start_transaction("CP30_Signout");

	web_url("Signout from Punch-Out", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/ccGenericView?catalogId=10051&storeId=10151&langId=-1&krypto={cp_krypto}&ddkey=https%3ALogoff", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html;charset=UTF-8", 
		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/ccGenericView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=http%3AccEndCustomerCall", 
		"Snapshot=t72.inf",
		"Mode=HTML", 
		LAST);

	lr_end_transaction("CP30_Signout",LR_AUTO);
	
	
	
	
	return 0;
}
