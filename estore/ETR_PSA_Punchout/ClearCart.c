ClearCart()
{
	if(strcmp(lr_eval_string("{cp_iCount}"),"0")==0)
			{
		
			}
			else
			{
				Cart();
				RemoveCart();
			}
	
		
	return 0;
}
