Checkout()
{

	if(strcmp(lr_eval_string("{cp_orderId}"),"")==0 || strcmp(lr_eval_string("{cp_orderItemId_count}"),"")==0)
	{
		Logout();
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}
	
		
	if(LoginFlag==1 || SignInFormFlag==1)
	{
		if(hpeppFlag==1)
		{		
			lr_save_string("_R","USER");		
			LoggedInCheckout();
		}
		
		else if(eppFlag==1)
		{		
			lr_save_string("_R","USER");		
			LoggedInCheckout();
		}
		
		else if(silverFlag==1)
		{		
			lr_save_string("_R","USER");		
			LoggedInCheckout();
		}
		
		else if(goldFlag==1)
		{		
			lr_save_string("_R","USER");		
			LoggedInCheckout();
		}
		
		else if(platinumFlag==1)
		{		
			lr_save_string("_R","USER");		
			LoggedInCheckout();
		}
		
		else if(gsFlag==1)
		{
			lr_save_string("_R","USER");		
			LoggedInCheckout();	      	
	    }
		else if(gs_ccFlag==1)
		{
			lr_save_string("_R","USER");
			LoggedInCheckout_CCSaved();
		}
		else if(euaFlag==1)
		{
			lr_save_string("_R","USER");
			LoggedInCheckout_EUA();
		}
		
		else if(loyaltyFlag==1)
		{
			lr_save_string("_R","USER");
			LoggedInCheckout_Loyalty();
		}
	}
	
	else if(GuestFlag==1)
	{

	}
		
	return 0;
}
