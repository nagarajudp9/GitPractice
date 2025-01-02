AddToCart()
{
	
	if(strcmp("YES",lr_eval_string("{CTO}"))==0)
	{
		AddToCart_CTO();
		
		Cart_CTO();
		
		//Free();
		lr_save_string("NO","CTO");
	}
	
	else if(strcmp("YES",lr_eval_string("{Supplies}"))==0)
	{
		AddToCart_Supplies();
		Cart();
		lr_save_string("NO","Supplies");
	}
	
	else if(strcmp("YES",lr_eval_string("{PDP}"))==0)
	{
		AddToCart_STO();
		Cart();
		lr_save_string("NO","PDP");
	}
	else 
	{
		//CC_Logout();	
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}
	
	return 0;
}
