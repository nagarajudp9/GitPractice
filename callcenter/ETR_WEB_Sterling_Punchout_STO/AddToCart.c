AddToCart()
{
	
	if(strcmp("YES",lr_eval_string("{CTO}"))==0)
	{
		AddToCart_CTO();
		
			if((atoi(lr_eval_string("{p_TypeOfSell}")))==1)
	
		{
			Cart_CTO();
		}
		
		
		if((atoi(lr_eval_string("{p_TypeOfSell}")))==0)
	
		{
			Cart();
		}
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
	
	//moved from Cart() Block to here by Sivakami
	if(strcmp(lr_eval_string("{cp_cartOrderId}"),"")==0)
	{
		//Logout();
		//CC_Logout();
		lr_save_string("NO","Supplies");
		lr_save_string("NO","PDP");
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}	
	
	return 0;
}
