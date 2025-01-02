LineItem5()
{
		
	if(GuestFlag==1)
	{
	
		if (atoi(lr_eval_string("{p_randomNo}"))<8)
		{
	PDP();
	
	AddToCart_STO();
		
	for(i=1;i<=4;i++)
		{
		PDP_Login();
		
		AddToCart_STO();
		
		
		}
lr_save_string("_5Items","cartitem");	
	Cart();
		}
		else
		{
			PDP_Supplies();
	
	AddToCart_Supplies();

		
	for(i=1;i<=4;i++)
		{
		PDP_Supplies_Login();
		
		AddToCart_Supplies();
		
			
		}	
	Cart();
		}
	}
	return 0;
}
