AddToCart()
{
	
	if(strcmp("YES",lr_eval_string("{Supplies}"))==0)
	{
		AddToCart_Supplies();
		
		Cart();
		
		lr_save_string("NO","Supplies");
	}
	else
	{
		AddToCart_STO();
		
		Cart();
		
		lr_save_string("NO","PDP");
	}	
	
	return 0;
}
