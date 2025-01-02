AddToCart()
{
	
	int icount1;
	
	
	mFound = atoi(lr_eval_string("{c_OutOfStock}"));
	
		
	pmaxValue = atoi(lr_eval_string("{p_randomNum}") );	
	
if ( AddToCartFlag == 1 && pmaxValue == 1 && mFound == 0)
		
	{
	
		web_reg_save_param("cp_orderId","LB=\"orderId\": [\"","RB=\"","NotFound=Warning",LAST);
	
lr_start_transaction(lr_eval_string("S22_AddToCart{cartitem}"));
	
	web_submit_data("AddToCartAjax",
		"Action=https://{p_hostName}/us-en/shop/AddToCartAjax", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=calculationUsage", "Value=-1,-2,-5,-6,-7", ENDITEM, 
		"Name=inventoryValidation", "Value=true", ENDITEM, 
		"Name=URL", "Value=", ENDITEM, 
		"Name=updatePrices", "Value=1", ENDITEM, 
		"Name=isGC", "Value=N", ENDITEM,
		"Name=requesttype", "Value=ajax", ENDITEM, 
		"Name=orderId", "Value=.", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=catEntryId", "Value={cp_catEntryIdAddtocart}", ENDITEM, 
		"Name=quantity", "Value=1", ENDITEM, 
		LAST);

	
	
	web_url("HPServices_5", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?_=1626157870305&action=c&catentryId=&modelId=&langId=-1&storeId=10151&catalogId=10051", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/mdp/{p_MDP}", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);



/*

web_url("accessories",
		"URL=https://{p_hostName}/wcs/resources/store/10151/component/product/accessories?productId={cp_catEntryIdAddtocart}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/us-en/shop/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

*/


icount1=atoi(lr_eval_string("{cp_orderId_count}"));
	if(icount1 == 0)
	{
	
		lr_end_transaction(lr_eval_string("S22_AddToCart{cartitem}"),LR_PASS);	
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);		
	}	
	else	
		
	{
lr_end_transaction(lr_eval_string("S22_AddToCart{cartitem}"),LR_PASS);

	}
			
	ViewCart();
	

}
	
	
	return 0;
}
