Dealspage()
{
	
	lr_think_time(60);
	
	pmaxValue = atoi(lr_eval_string("{p_randomNum}") );	
	
	web_reg_find("Search=All","SaveCount=c_Deals","Text=jsonAvailableDeals",LAST);
	
	web_reg_find("Search=All","SaveCount=c_Home","Text=HomePage.jsp",LAST);
	
	web_save_timestamp_param("cp_time", LAST);     
	
	
	if ( pmaxValue < 9)
		
	{
		
	
	lr_start_transaction(lr_eval_string("{AgentType}S17_DealsAPI"));
	      
    web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    
    
	
	 
	 
	}
	
	else
		
	{
	 
 lr_start_transaction(lr_eval_string("{AgentType}S17_DealsAPI"));

web_url("dealsapi", 
        "URL=https://{p_hostName}/webapp/wcs/stores/servlet/DealsAPI?catalogId=10051&langId=-1&storeId=10151{StoreType}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer=https://{p_hostName}/us-en/shop", 
        "Snapshot=t28.inf", 
        "Mode=HTTP", 
        LAST);    


 
	}
 
	
	if((atoi(lr_eval_string("{c_Deals}"))>0) && (atoi(lr_eval_string("{c_Home}"))==0))
	{
		lr_end_transaction(lr_eval_string("{AgentType}S17_DealsAPI"),LR_PASS);
	}
	
	else
	{
		lr_end_transaction(lr_eval_string("{AgentType}S17_DealsAPI"),LR_FAIL);
	}
	return 0;
}
