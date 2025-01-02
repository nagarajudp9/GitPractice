LineItems()
{

	
	
	for(i=1;i<=2;i++)
		
	{
		web_cache_cleanup();
		PDP_CTO();
		
		AddToCart_CTO();
		
		lr_save_string("_2Items","cartLineitem");
	
	//web_cleanup_auto_headers();
	//web_cleanup_cookies();		
				
		}
	
	
	
	return 0;
}
