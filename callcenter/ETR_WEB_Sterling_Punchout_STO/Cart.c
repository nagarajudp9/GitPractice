Cart()
{

  	lr_think_time(120);
		
	//moved the below web_reg_save_param calls from checkout action
	web_reg_save_param("cp_authToken","LB=<input type=\"hidden\" name=\"authToken\" id=\"authToken\" value=\"","RB=\"/>","Notfound=warning",LAST);
	web_reg_save_param("cp_orderId","LB=<input type=\"hidden\" name=\"orderId\" id=\"orderId\" value=\"","RB=\"/>","Notfound=warning",LAST);	
	web_reg_save_param("cp_correlationId","LB=<input type=\"hidden\" name=\"correlationId\" id=\"correlationId\" value=\"","RB=\"/>","Notfound=warning",LAST);
	web_reg_save_param("cp_orderNo","LB=<input type=\"hidden\" name=\"ormOrderId\" id=\"ormOrderId\" value=\"","RB=\"/>","Notfound=warning",LAST);	
	web_reg_save_param("cp_krypto","LB=&krypto=","RB=&ddkey","Notfound=warning",LAST);
	web_reg_save_param("cp_offerprice","LB=<span>$","RB=</span>","Notfound=warning",LAST);
	web_reg_save_param("cp_adjprice","LB=<div class=\"lblRcSaved\">You saved <span>$","RB=</span> on your order</div>","Notfound=warning",LAST);
	
	//added by sivakami
	web_reg_save_param("cp_orderItemId","LB=&orderItemId=","RB=&","ORD=ALL","NOTFOUND=warning",LAST);	
	
	//web_set_sockets_option("SSL_VERSION", "TLS1.2");
//	
//	web_reg_find("Text=hpusstore - Shopping Cart", 
//		LAST);
	
web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");

	lr_start_transaction("CP24_ViewCart");

	web_url("OrderCalculate", 
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?updatePrices=1&calculationUsageId=-1&catalogId=10051&langId=-1&storeId=10151&URL=AjaxOrderItemDisplayView", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);
	//=https://perf.store.hp.com/us-en/shop/OrderCalculate?calculationUsageId=-1&catalogId=10051&updatePrices=1&langId=-1&storeId=10151&URL=AjaxOrderItemDisplayView"
	web_url("AjaxOrderItemDisplayView", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=http%3AOrderCalculate", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t60.inf", 
		"Mode=HTML", 
		LAST);



	
	lr_end_transaction("CP24_ViewCart",LR_AUTO);
	
	
	return 0;
}
