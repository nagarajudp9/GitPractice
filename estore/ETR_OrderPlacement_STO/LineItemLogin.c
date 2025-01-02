LineItemLogin()
{
		
	if(LoginFlag==1 && loyaltyFlag==0)
	{
	lr_save_string("","cartitem");
	
	if (atoi(lr_eval_string("{p_randomNo}"))<8)
	{
	PDP_Login();
	
	AddToCart();
	}
	else
	{
	PDP_Supplies_Login();
	
	AddToCart();	
	}
	}
	else if(LoginFlag==1 && loyaltyFlag==1)
	{
	
	
	PDP_Loyalty();
	
	AddToCart_STO();
	
	lr_save_string("_Rewards","cartitem");
	
	Cart_Loyalty();
	}
	
	return 0;
}
