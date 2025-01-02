ClearCart()
{
	lr_save_string("NO","CTO");
	lr_save_string("NO","Supplies");
	lr_save_string("NO","PDP");	
	
	lr_save_string("","cartitem");
	
	if(LoginFlag==1)
	{
		
		if(strcmp(lr_eval_string("{cp_iCount}"),"0")==0)
			{
		
			}
			else
			{
				Cart();
				RemoveCart();
			}
	}
	return 0;
}
