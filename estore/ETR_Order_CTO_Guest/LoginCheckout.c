LoginCheckout()
{
			
lr_think_time(60);

web_set_max_html_param_len("15000");
	
lr_save_string("_CTO","cartitem");

if(strcmp(lr_eval_string("{cp_orderId}"),"")==0 || strcmp(lr_eval_string("{cp_orderItemId_count}"),"")==0)
	{
		
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);
	}
	
	else
		
	{

		//HomePage();
		
		lr_start_transaction(lr_eval_string("S27_Checkout_Login"));
		
		
		web_submit_data("CheckHPIDRedirection", 
		"Action=https://{p_hostName}/us-en/shop/CheckHPIDRedirection", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=logonId", "Value={p_checkoutUser}", ENDITEM, 
		"Name=rememberMe", "Value=true", ENDITEM, 
		"Name=token", "Value=NA", ENDITEM, 
		"Name=landingURL", "Value=%2Fus%2Fen%2FOrderCalculate%3FupdatePrices%3D1%26shipmentType%3Dsingle%26calculationUsageId%3D-1%26calculationUsageId%3D-4%26calculationUsageId%3D-6%26errorViewName%3DAjaxOrderItemDisplayView%26catalogId%3D10051%26langId%3D-1%26QuoteDisable%3DN%26URL%3DOrderShippingBillingView%26storeId%3D10151%26orderId%3D.", ENDITEM, 
		"Name=cartURL", "Value=https%3A%2F%2F{p_hostName}%2Fus%2Fen%2FAjaxOrderItemDisplayView%3FcatalogId%3D10051%26langId%3D-1%26storeId%3D10151%26krypto%3D{cp_krypto}%26ddkey%3Dhttps%253AOrderCalculate", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cql", "Value=40", ENDITEM, 
		"Name=cal", "Value=6000", ENDITEM, 
		LAST);

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/
	web_reg_save_param("cp_AuthLogin","LB=authentication/login/","RB=&login_hint=","ORD=1","Notfound=Warning",LAST);
	
		
	web_convert_param("p_checkoutUser_URL",
	                  "SourceString={p_checkoutUser}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	web_revert_auto_header("Origin");
	web_url("authorize", 
        "URL=https://directory.stg.cd.id.hp.com/directory/v1/oauth/authorize?response_type=code&client_id=A5bBp8xBaTL8hg7e1SVvlwynjhHhARqO&redirect_uri=https%3A%2F%2F{p_hostName}%2Fwebapp%2Fwcs%2Fstores%2Fservlet%2FETRLogonFlow%3FcatalogId%3D10051%26langId%3D-1%26storeId%3D10151&scope=openid+email+profile+user.profile.write+user.profile.username+user.profile.read+offline_access&state=operation:cartLogin|{p_checkoutUser}&nonce=en&prompt=consent&target=password&allow_return=true&login_hint="
		"{p_checkoutUser}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

		
		/*
	
	web_submit_data("CheckHPIDRedirection", 
		"Action=https://{p_hostName}/us-en/shop/CheckHPIDRedirection", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?storeId=10151&catalogId=10051&langId=-1&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=logonId", "Value={p_checkoutUser}", ENDITEM, 
		"Name=rememberMe", "Value=true", ENDITEM, 
		"Name=token", "Value=NA", ENDITEM, 
		//"Value=%2Fus-en%2Fshop%2FOrderCalculate%3FcalculationUsageId%3D-1%26calculationUsageId%3D-4%26calculationUsageId%3D-6%26catalogId%3D10051%26orderId%3D.%26updatePrices%3D1%26langId%3D-1%26storeId%3D10151%26errorViewName%3DAjaxOrderItemDisplayView%26URL%3DOrderShippingBillingView%26QuoteDisable%3DN%26shipmentType%3Dsingle", ENDITEM, 
		"Name=landingURL", "Value=%2Fus-en%2Fshop%2FOrderCalculate%3FcalculationUsageId%3D-1%26calculationUsageId%3D-4%26calculationUsageId%3D-6%26catalogId%3D10051%26orderId%3D.%26updatePrices%3D1%26langId%3D-1%26storeId%3D10151%26errorViewName%3DAjaxOrderItemDisplayView%26URL%3DOrderShippingBillingView%26QuoteDisable%3DN%26shipmentType%3Dsingle", ENDITEM, 
		"Name=cartURL", "Value=https%3A%2F%2F{p_hostName}%2Fus-en%2Fshop%2FAjaxOrderItemDisplayView%3FstoreId%3D10151%26catalogId%3D10051%26langId%3D-1%26krypto%3D{cp_krypto}3D%26ddkey%"
		"3Dhttps%253AOrderCalculate", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cql", "Value=40", ENDITEM, 
		"Name=cal", "Value=6000", ENDITEM, 
		LAST);

	/*
	web_submit_data("CheckHPIDRedirection", 
		"Action=https://{p_hostName}/us-en/shop/CheckHPIDRedirection", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=logonId", "Value={p_checkoutUser}", ENDITEM, 
		"Name=rememberMe", "Value=true", ENDITEM, 
		"Name=token", "Value=NA", ENDITEM, 
		"Name=landingURL", "Value=%2Fus%2Fen%2FOrderCalculate%3FupdatePrices%3D1%26shipmentType%3Dsingle%26calculationUsageId%3D-1%26calculationUsageId%3D-4%26calculationUsageId%3D-6%26errorViewName%3DAjaxOrderItemDisplayView%26catalogId%3D10051%26langId%3D-1%26QuoteDisable%3DN%26URL%3DOrderShippingBillingView%26storeId%3D10151%26orderId%3D.", ENDITEM, 
		"Name=cartURL", "Value=https%3A%2F%2F{p_hostName}%2Fus%2Fen%2FAjaxOrderItemDisplayView%3FcatalogId%3D10051%26langId%3D-1%26storeId%3D10151%26krypto%3D{cp_krypto}%26ddkey%3Dhttps%253AOrderCalculate", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cql", "Value=40", ENDITEM, 
		"Name=cal", "Value=6000", ENDITEM, 
		LAST);
		
	web_reg_save_param("cp_AuthLogin","LB=authentication/login/","RB=&login_hint=","ORD=1","Notfound=Warning",LAST);
	
		
	web_convert_param("p_checkoutUser_URL",
	                  "SourceString={p_checkoutUser}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	

	web_url("authorize", 
		"URL=https://directory.stg.cd.id.hp.com/directory/v1/oauth/authorize?response_type=code&client_id={cp_ClientID}&redirect_uri=https%3A%2F%2F{p_hostName}%2Fwebapp%2Fwcs%2Fstores%2Fservlet%2FETRLogonFlow%3FcatalogId%3D10051%26langId%3D-1%26storeId%3D10151&scope=openid+email+profile+user.profile.write+user.profile.username+user.profile.read+offline_access&state=operation:cartLogin|{p_checkoutUser_URL}&nonce=en&prompt=consent&target=password&allow_return=true&login_hint="
		"{p_checkoutUser}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AjaxOrderItemDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);
*/
	web_add_header("Access-Control-Request-Headers", 
		"content-type");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"https://login3.stg.cd.id.hp.com");

	web_custom_request("session", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/auth/session", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param("cp_CSRFToken","LB=csrfToken\":\"","RB=\"","ORD=1","Notfound=Warning",LAST);

	web_custom_request("session_2", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/auth/session", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"flow\":\"https://directory.stg.cd.id.hp.com/directory/v1/authentication/login/"
		"{cp_AuthLogin}\"}", 
		LAST);

	web_url("country", 
		"URL=https://static.stg.cd.id.hp.com/login3/country", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("Origin");

	web_add_header("Access-Control-Request-Headers", 
		"content-type,csrf-token");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"https://login3.stg.cd.id.hp.com");

	web_custom_request("check-username", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/session/check-username", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);
	
	web_add_cookie("s_sq=hphqglobaldev%3D%2526pid%253Dhttps%25253A%25252F%25252Flogin3.stg.cd.id.hp.com%25252Flogin3%25253Fflow%25253Dhttps%25253A%25252F%25252Fdirectory.stg.cd.id.hp.com%25252Fdirectory%25252Fv1%25252Fauthentication%25252Flogin%25252F{cp_AuthLogin}%2526oid%253DfunctionWn%252528%252529%25257B%25257D%2526oidt%253D2%2526ot%253DSUBMIT; DOMAIN="
		"ui-backend.stg.cd.id.hp.com");

	web_add_header("CSRF-TOKEN", 
		"{cp_CSRFToken}");

	web_custom_request("check-username_2", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/session/check-username", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"username\":\"{p_checkoutUser}\"}", 
		LAST);
	


	lr_end_transaction(lr_eval_string("S27_Checkout_Login"),LR_AUTO);

	lr_start_transaction("S27_Checkout_SignIn");
	
web_add_header("Access-Control-Request-Headers", 
		"content-type,csrf-token");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_custom_request("username-password", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/session/username-password", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("CSRF-TOKEN", 
		"{cp_CSRFToken}");
	
	web_reg_save_param("cp_Code","LB=code=","RB=&state","ORD=1","Notfound=Warning",LAST);

	web_custom_request("username-password_2", 
		"URL=https://ui-backend.stg.cd.id.hp.com/bff/v1/session/username-password", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"username\":\"{p_checkoutUser}@hpid\",\"password\":\"{p_password}\"}", 
		LAST);
	
	web_add_header("Upgrade-Insecure-Requests", 
		"1");
	
		
	web_reg_save_param("cp_Krypto","LB=&krypto=","RB=%3D&ddkey","ORD=1",LAST);
	
	//web_reg_save_param_ex("ParamName=cp_clientip","LB=clientip:\"","RB=\",",LAST);
		
//	web_reg_save_param("cp_Krypto","LB=&krypto=","RB=%3D&ddkey","ORD=1",LAST);
	
	web_reg_save_param("cp_merchantName","LB=<input type=\"hidden\" name=\"merchantName\" value=\"","RB=\"/>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_sessionid","LB=<input type=\"hidden\" id=\"sessionId\" value=\"","RB=\"/>","Notfound=warning",LAST);	

	web_reg_save_param("cp_authToken","LB=<input type=\"hidden\" id=\"authToken\" value=\"","RB=\"/>","Notfound=warning",LAST);

	web_reg_save_param("cp_FirstNameAccount","LB=<div class=\"lblContact\">","RB= ","Notfound=warning",LAST);
	
	web_reg_save_param("cp_LastNameAccount","LB= ","RB=<br><span class=\"bgHighlight\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_EmailAccount","LB=<span class=\"bgHighlight\">","RB=</span><br>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_PhoneAccount","LB=</span><br>","RB=</div>","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentFirstName","LB=data-fn=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentLastName","LB=data-ln=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentNickName","LB=data-nn=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentPhone","LB=data-ph=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentAddress","LB=data-a1=\"","RB=\"","Notfound=warning",LAST);
		
	web_reg_save_param("cp_CurrentCity","LB=data-cy=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentState","LB=data-st=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CurrentZipCode","LB=data-zc=\"","RB=-","Savelen=5","Notfound=warning",LAST);
	
	web_reg_save_param("cp_addressId","LB=data-addr=\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_PMTId","LB=data-pmt=\"","RB=\"","Notfound=warning",LAST);

	web_reg_save_param_ex("ParamName=cp_EstGrandTotal","LB=EstGrandTotal\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_TotalTaxAmount","LB=TotalTaxAmount\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Price","LB=Item_Price\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Name","LB=Item_Name\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param_ex("ParamName=cp_Item_Code","LB=Item_Code\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	web_reg_save_param("cp_tmid","lb=\"tmId\" value=\"","rb=\"/>","notfound=warning",LAST);

	web_save_timestamp_param("cp_time", LAST);
	

	web_url("ETRLogonFlow", 
		//"URL=https://{p_hostName}/webapp/wcs/stores/servlet/ETRLogonFlow?catalogId=10051&langId=-1&storeId=10151&code={cp_Code}&state=operation:login", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/ETRLogonFlow?catalogId=10051&langId=-1&storeId=10151&code={cp_Code}&state=operation:cartLogin%7C{p_checkoutUser}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);
	
	web_add_header("X-Requested-With",
		"XMLHttpRequest");
	
	
	web_reg_find("Search=All","Text=\"userType\": \"R\"","savecount=Register",LAST);
	
	web_reg_save_param("cp_iCount","LB=\"iCount\": ","RB=,","Notfound=warning",LAST);

	web_url("HPServices_2", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1611899967465&action=cupids&catentryId=3074457345619573822%2C3074457345619562324%2C3074457345619562320%2C3074457345619533327%2C3074457345618514833%2C3074457345618982329%2C3074457345619317819%2C3074457345619673829%2C3074457345619534818&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/TopCategoriesDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_Krypto}&ddkey=https%3AETRLogonFlow", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		LAST);
	

	web_reg_save_param("cp_PaymentRequest","LB=JWT&quot;:&quot;","RB=&quot;","Notfound=warning",LAST);
	
	//lr_start_sub_transaction("S28-3_Login_Pay","S27_Checkout_SignIn");

	web_submit_data("Pay",
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay",
		"Method=POST",
		"EncodeAtSign=YES",
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t26.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNo}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_correlationId}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld={cp_orderNo}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_correlationId}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"{cp_CurrentAddress}\",\"City\":\"{cp_CurrentCity}\",\"State\":\"{cp_CurrentState}\",\"Zip\":\"{cp_CurrentZipCode}\",\"Country\":\"US\",\"ContactFirstName\":\"{cp_CurrentFirstName}\",\"ContactLastName\":\"{cp_CurrentLastName}\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"Con"
		"tactEmail\":\"\",\"AddressName\":\"{cp_CurrentAddress}\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"{cp_FirstNameAccount}\",\"LastName\":\"{cp_LastNameAccount}\",\"Email\":\"{cp_EmailAccount}\",\"Phone\":\"{cp_PhoneAccount}\",\"Locale\":\"en_US\"},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":{\"IsDisplaySaveProfileFlag\":true,\"IsServiceRequired\":true,\"IsUpdatingUserProfile\":false}}", ENDITEM,
		LAST);

	web_submit_data("Pay_2",
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay",
		"Method=POST",
		"EncodeAtSign=YES",
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t27.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNo}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_correlationId}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld={cp_orderNo}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_correlationId}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"{cp_CurrentAddress}\",\"City\":\"{cp_CurrentCity}\",\"State\":\"{cp_CurrentState}\",\"Zip\":\"{cp_CurrentZipCode}\",\"Country\":\"US\",\"ContactFirstName\":\"{cp_CurrentFirstName}\",\"ContactLastName\":\"{cp_CurrentLastName}\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"Con"
		"tactEmail\":\"\",\"AddressName\":\"{cp_CurrentAddress}\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"{cp_FirstNameAccount}\",\"LastName\":\"{cp_LastNameAccount}\",\"Email\":\"{cp_EmailAccount}\",\"Phone\":\"{cp_PhoneAccount}\",\"Locale\":\"en_US\"},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":\"\",\"GPay\":{\"IsServiceRequired\":true}}", ENDITEM,
		LAST);
		
	//lr_end_sub_transaction("S28-3_Login_Pay",LR_AUTO);


	lr_end_transaction("S27_Checkout_SignIn",LR_AUTO);
	
	lr_save_string(lr_eval_string("{p_checkoutUser}"), "p_userEmail"); 
	
	lr_think_time(120);
	
	web_save_timestamp_param("cp_time", LAST);

	lr_save_string(lr_eval_string("{p_FirstName}"),"p_FirstNameNew");	
	lr_save_string(lr_eval_string("{p_LastName}"),"p_LastNameNew");
	lr_save_string(lr_eval_string("{p_CompanyName}"),"p_CompanyNameNew");
	lr_save_string(lr_eval_string("{p_Address1}"),"p_Address1New");
	lr_save_string(lr_eval_string("{p_Address2}"),"p_Address2New");
	lr_save_string(lr_eval_string("{p_Phone}"),"p_PhoneNew");
	lr_save_string(lr_eval_string("{p_city}"),"p_CityNew");
	lr_save_string(lr_eval_string("{p_state}"),"p_StateNew");
	lr_save_string(lr_eval_string("{p_zipCode}"),"p_ZipCodeNew");
	
	web_reg_save_param("cp_addressId","LB=\"addressId\": \"","RB=\"","Notfound=warning",LAST);
	
	lr_start_transaction("S28_CheckoutDetails_Login");
				
	////lr_start_sub_transaction("S28-1_Login_AjaxOrderShipInfoUpdate","S28_CheckoutDetails_Login");
	
	web_submit_data("AjaxOrderShipInfoUpdate", 
		"Action=https://{p_hostName}/webapp/wcs/stores/servlet/AjaxOrderShipInfoUpdate", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html",
		"Referer=https://{p_hostName}/us-en/shop",
		"Snapshot=t48.inf",
		"Mode=HTML", 
		ITEMDATA, 
		"Name=editAddress", "Value=false", ENDITEM, 
		"Name=nickName", "Value=EStore_STO_LoginCheckout_{cp_time}", ENDITEM, 
		"Name=firstName", "Value={p_FirstNameNew}", ENDITEM, 
		"Name=lastName", "Value={p_LastNameNew}", ENDITEM, 
		"Name=organizationName", "Value=", ENDITEM, 
		"Name=address1", "Value={p_Address1New}", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value={p_CityNew}", ENDITEM, 
		"Name=state", "Value={p_StateNew}", ENDITEM, 
		"Name=zipCode", "Value={p_ZipCodeNew}", ENDITEM, 
		"Name=country", "Value=US", ENDITEM, 
		"Name=email1", "Value={p_userEmail}", ENDITEM, 
		"Name=phone1", "Value={p_PhoneNew}", ENDITEM, 
		"Name=isResidenceAddr", "Value=false", ENDITEM, 
		"Name=isSmbOrder", "Value=false", ENDITEM, 
		"Name=shipModeId", "Value=12056", ENDITEM, 
		"Name=authToken", "Value={cp_authToken}", ENDITEM, 
		"Name=orderId", "Value={cp_orderId}", ENDITEM, 
		"Name=addressType", "Value=S", ENDITEM, 
		"Name=URL", "Value=/", ENDITEM, 
		"Name=correlationId", "Value={cp_correlationId}", ENDITEM, 
		"Name=taxExemptCheck", "Value=false", ENDITEM, 
		"Name=taxExemptOrgName", "Value=", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=catalogId", "Value=10051", ENDITEM, 
		"Name=ccf", "Value=false", ENDITEM, 
		"Name=cof", "Value=true", ENDITEM, 
		LAST);
		
	////lr_end_sub_transaction("S28-1_Login_AjaxOrderShipInfoUpdate",LR_AUTO);
		
	web_reg_save_param("cp_EstGrandTotal","LB=EstGrandTotal\": \"","RB=\",\r\n","Notfound=warning",LAST);
	web_reg_save_param("cp_TotalTaxAmount","LB=TotalTaxAmount\": \"","RB=\",\r\n","Notfound=warning",LAST);
	web_reg_save_param("cp_Item_Price","LB=Item_Price\": \"","RB=\",\r\n","Notfound=warning",LAST);
	web_reg_save_param("cp_Item_Name","LB=Item_Name\": \"","RB=\",\r\n","Notfound=warning",LAST);
	web_reg_save_param("cp_Item_Code","LB=Item_Code\": \"","RB=\",\r\n","Notfound=warning",LAST);
	
	
	////lr_start_sub_transaction("S28-2_Login_RefreshCheckoutCart","S28_CheckoutDetails_Login");

		
	web_url("RefreshCheckoutCart", 
		"URL=https://{p_hostName}/us-en/shop/RefreshCheckoutCart?ajax=true&crID={cp_correlationId}&storeId=10151&langId=-1&catalogId=10051&ccf=false&cof=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?updatePrices=1&calculationUsageId=-1&catalogId=10051&langId=-1&storeId=10151&orderId=.", 
		"Snapshot=t103.inf", 
		"Mode=HTML", 
		LAST);
	
//	if(strcmp(lr_eval_string("{cp_TotalTaxAmount}"),"")==0)
//	{
//		
//	//lr_end_sub_transaction("S28-2_Login_RefreshCheckoutCart",LR_FAIL);
//	
//	}
//	else
//	{	
//		//lr_end_sub_transaction("S28-2_Login_RefreshCheckoutCart",LR_PASS);
//	}

	web_convert_param("cp_pdpname",
	                 "SourceString={cp_pdpname}",
		             "SourceEncoding=HTML",
		             "TargetEncoding=URL",
		              LAST);
	
//	//lr_start_sub_transaction("S28-3_Login_Pay","S28_CheckoutDetails_Login");
	
	web_reg_save_param("cp_PaymentRequest","LB=JWT&quot;:&quot;","RB=&quot;","Notfound=warning",LAST);

	web_submit_data("Pay", 
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t33.inf",
		"Mode=HTML", 
		ITEMDATA, 
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNo}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld="
		"{cp_orderNo}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"{p_Address1New}\",\"City\":\"{p_CityNew}\",\"State\":\"{p_StateNew}\",\"Zip\":\"{p_ZipCodeNew}\",\"Country\":\"US\",\"ContactFirstName\":\"test\",\""
		"ContactLastName\":\"test\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"ContactEmail\":\"\",\"AddressName\":\"test\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"{p_FirstNameNew}\",\"LastName\":\"{p_LastNameNew}\",\"Email\":\"{p_userEmail}\",\"Phone\":\"{p_PhoneNew}\",\"Locale\":\"en_US\",\"IsGuestUser\":true},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\""
		"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":{\"IsDisplaySaveProfileFlag\":true,\"IsServiceRequired\":true,\"IsUpdatingUserProfile\":false}}", ENDITEM, 
		LAST);
		
	web_submit_data("Pay_2", 
		"Action=https://vphcitg.pgs.ext.hp.com/PGSAllpayment_V2/Payment/Pay", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"{cp_krypto}&ddkey=https%3AOrderCalculate", 
		"Snapshot=t33.inf",
		"Mode=HTML", 
		ITEMDATA, 
		"Name=phcRequest", "Value={\"MerchantName\":\"{cp_merchantName}\",\"AgentId\":\"\",\"OrderID\":\"{cp_orderNo}\",\"RequestTime\":\"{p_RequestTime}UTC\",\"CustomerID\":\"\",\"CustomField\":\"{cp_orderNo}-{cp_time}-10151\",\"Culture\":\"en_US\",\"ReturnKey_Continue\":\"?storeId=10151&amp;langId=-1&amp;calculationUsageId=-1&amp;updatePrices=1&amp;cchost=true&amp;orderId=.&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N&amp;rFromPGS=true&amp;tld="
		"{cp_orderNo}-{cp_time}-10151\",\"IsSaveProfile\":true,\"ReturnKey_Cancel\":\"?storeId=10151&amp;langId=-1&amp;catalogId=10051&amp;calculationUsageId=-1&amp;updatePrices=1&amp;orderId=.&amp;cancel=true&amp;ccl=1&amp;crID={cp_orderNo}_{cp_time}&amp;QuoteDisable=N\",\"EstGrandTotal\":\"{cp_EstGrandTotal}\",\"TotalTaxAmount\":\"{cp_TotalTaxAmount}\",\"PurchaseCountry\":\"US\",\"BillAddress\":{\"Address1\":\"{p_Address1New}\",\"City\":\"{p_CityNew}\",\"State\":\"{p_StateNew}\",\"Zip\":\"{p_ZipCodeNew}\",\"Country\":\"US\",\"ContactFirstName\":\"test\",\""
		"ContactLastName\":\"test\",\"ContactDayPhone\":\"\",\"ContactNightPhone\":\"\",\"ContactEmail\":\"\",\"AddressName\":\"test\",\"Address2\":\"\",\"CompanyName\":\"\"},\"CustomerInfo\":{\"FirstName\":\"{p_FirstNameNew}\",\"LastName\":\"{p_LastNameNew}\",\"Email\":\"{p_userEmail}\",\"Phone\":\"{p_PhoneNew}\",\"Locale\":\"en_US\",\"IsGuestUser\":true},\"OfferItems\":[{\"Item_Name\":\"{cp_Item_Name}\",\"Item_Code\":\"{cp_Item_Code}\",\"Item_Type\":\"\",\"Quantity\":\"1\",\"Merchant_Item_SKU\":\"{cp_Item_Code}\",\""
		"Item_Price\":\"{cp_Item_Price}\",\"Item_Price_WithTax\":\"\",\"Tax_Amount\":\"\",\"Tax_Rate\":\"\",\"Discount_Amount\":\"\",\"Discount_Amount_WithTax\":\"\",\"Unit\":\"ea\",\"Item_Total_Amount\":\"\",\"Item_Total_Amount_WithTax\":\"\"}],\"CC\":\"\",\"GPay\":{\"IsServiceRequired\":true}}", ENDITEM, 
		LAST);

//	//lr_end_sub_transaction("S28-3_Login_Pay",LR_AUTO);

	lr_end_transaction("S28_CheckoutDetails_Login",LR_AUTO);
	
	lr_save_string(string_replace(lr_eval_string("{cp_EstGrandTotal}"),".",""),"cp_EstGrandTotal01");
	}
	
	LoginFlag = 1;
	
	web_set_max_html_param_len("1024");
	
	
	return 0;
}
