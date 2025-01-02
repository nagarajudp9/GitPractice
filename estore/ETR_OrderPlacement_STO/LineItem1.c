LineItem1()
{
		
	if(GuestFlag==1)
	{
	lr_save_string("","cartitem");
	
	if (atoi(lr_eval_string("{p_randomNo}"))<7)
	{
	PDP();
	
	AddToCart();
	}
	else
	{
		PDP_Supplies();
		
		AddToCart();
	}
	}
	
	return 0;
}
