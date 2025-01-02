BackToCart()
{
	
	lr_start_transaction("S27-1_BackToCart");

	web_url("OrderCalculate_3",
		"URL=https://{p_hostName}/us-en/shop/OrderCalculate?updatePrices=1&calculationUsageId=-1&errorViewName=AjaxOrderItemDisplayView&catalogId=10051&langId=-1&URL=AjaxOrderItemDisplayView{StoreType}&storeId=10151&orderId=.", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
//		"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
//		"7Pr%2B96L4o%2FD16gEd6Xmq62yduoUT2tGgU4KmQ%2Fgs41GVNjPWe9cFZs48oQurALdeP2YdIOEQpxj7jTkCvtbHFwjAXpFA20Fs8U80xgwAfZgNBJvLQVAXk9WIS06A9LDtBcFfbWsT6xXpplsl9fdXPyfmdDtFzi%2BatT4gXQ4WDwH4VfcF%2F%2FRKmTFX9QEPxZVAFGHZV%2Bu4LL7o5XmtC2FE6rKXc7Unx%2FrI5YvDtjfqAF2CG6mEoV3EQNo0DTj8BNY6UEMM8%2FXJNFqrMzJzbHdlxc%2FpgMH6JvRZm8keGvV%2BVsZLYQ2tw%2FakSfP68XY5YCxbMHxfVHW5Td0TRX24LOLz7Q%3D%3D&ddkey=https%3AOrderCalculate", 
		"Referer=",
		"Snapshot=t31.inf",
		"Mode=HTML", 
		LAST);
	
	web_url("AjaxOrderItemDisplayView", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto=7Pr%2B96L4o%2FD16gEd6Xmq62yduoUT2tGgU4KmQ%2Fgs41GVNjPWe9cFZs48oQurALdeP2YdIOEQpxj7jTkCvtbHFwjAXpFA20Fs8U80xgwAfZgNBJvLQVAXk9WIS06A9LDtBcFfbWsT6xXpplsl9fdXPyfmdDtFzi%2BatT4gXQ4WDwH4VfcF%2F%2FRKmTFX9QEPxZVAFGHZV%2Bu4LL7o5XmtC2FE6rKXc7Unx%2FrI5YvDtjfqAF2CG6mEoV3EQNo0DTj8BNY6UEMM8%2FXJNFqrMzJzbHdlxc%2FpgMH6JvRZm8keGvV%2BVsZLYQ2tw%2FakSfP68XY5YCxbMHxfVHW5Td0TRX24LOLz7Q%3D%3D&ddkey=http%3AOrderCalculate", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t60.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_5", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1517463582674&action=cupis&catentryId=&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto=fwKOiVCKimwjkaPO2EMI7lY493CtZk6yS5OxeymVkevYGluMfIhDRUpZDQrGCitj%2FyZKQyrYRx7ewzvzQgdVDzO2Z6nivlYGv1LSzt7Ie8DazP0XZEzRwb2LDkDPjJRUvX27xbhPoWD66Q%2BB05PeHUkx3Ffhx%2FwpezqKgQBZlz1ZB22qqx6LJvL9pQGZTmTtoKkLwnq0X2Tb7EEucpYYbj4HiLw8qb0tGWJ6K0VlGNl%2BQtI62RMDpeyExWaAxna%2FqlbuUozl0oW%2BYHI%2BVywlZA%3D%3D&ddkey=https%3AOrderCalculate", 
		"Referer=",
		"Snapshot=t32.inf",
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("S27-1_BackToCart",LR_AUTO);
	
	return 0;
}
