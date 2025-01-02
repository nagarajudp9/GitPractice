Checkout()
{
	
	if(strcmp(lr_eval_string("{cp_orderId}"),"")==0 || strcmp(lr_eval_string("{cp_orderItemId_count}"),"")==0)
	{
		
		Logout();
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}
	
	else
		
	{
	
	if(gsFlag == 1 || platinumFlag == 1 || goldFlag == 1 || silverFlag == 1 || loyaltyflag == 1  )
	{
		
	LoggedInCheckout();	 
	
	}
	
	else if(euaFlag == 1)
		{
		
		EUA_LoggedInCheckout();
	    
		}
	
	else if(gs_ccFlag == 1)
		{
		
		LoggedInCheckout_CCSaved();
	    
		}
	
	
	else 
		
		{
		
		Logout();
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
		
	}
	
	}
	return 0;
}
