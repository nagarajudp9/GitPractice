MyAccount()
{

	web_save_timestamp_param("cp_time", LAST);
	
	lr_start_transaction("S41_MyAccount");

	web_url("MyAccountPage", 
		"URL=https://{p_hostName}/us-en/shop/MyAccountFormView?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_={cp_time}&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyOrdersView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("S41_MyAccount",LR_AUTO);
	

if(atoi(lr_eval_string("{p_randomNumber}"))<40)
	{
		
	
	web_set_max_html_param_len("99999");
	
	web_reg_save_param("cp_authToken","LB=authToken=","RB=&amp;","ORD=1","NOTFOUND=warning",LAST);

	lr_think_time(30);
	
//	web_reg_find("Text=Your Orders",LAST);

lr_start_transaction("S42_MyOrders");

	web_url("MyOrdersView", 
		"URL=https://{p_hostName}/us-en/shop/MyOrdersView?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t81.inf", 
		"Mode=HTML", 
		LAST);
	
	web_save_timestamp_param("cp_time", LAST);
	
	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_={cp_time}&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MyOrdersView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("S42_MyOrders",LR_AUTO);
	
	lr_start_transaction(lr_eval_string("{AgentType}S43_MySubscriptions"));
	
	//web_reg_find("Text=My Subscriptions",LAST);
	
	web_url("MySubscription",
		"URL=https://{p_hostName}/us-en/shop/MySubscriptionsView?catalogId=10051&storeId=10151&langId=-1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t93.inf", 
		"Mode=HTML", 
		LAST);
	
	web_save_timestamp_param("cp_time", LAST);
	
	web_url("HPServices_6",
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_={cp_time}&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/ManageSubscription?orderStatusStyle=strong&catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t59.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("{AgentType}S43_MySubscriptions"),LR_AUTO);
	
	web_save_timestamp_param("cp_time", LAST);
	
	lr_start_transaction(lr_eval_string("{AgentType}S50_ManageSubscription"));
	
	web_url("ManageSubscription", 
		"URL=https://{p_hostName}/us-en/shop/ManageSubscription?catalogId=10051&orderStatusStyle=strong&storeId=10151&langId=-1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/MySavedCards?catalogId=10051&storeId=10151&langId=-1", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_3", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_={cp_time}&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/ManageSubscription?catalogId=10051&orderStatusStyle=strong&storeId=10151&langId=-1", 
		"Snapshot=t56.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("{AgentType}S50_ManageSubscription"),LR_AUTO);
	
	web_save_timestamp_param("cp_time", LAST);
	
	lr_start_transaction(lr_eval_string("{AgentType}S43_MyDevices"));
	
	web_url("ManageMyDevicesView", 
		"URL=https://{p_hostName}/us-en/shop/ManageMyDevicesView?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/ManageSubscription?catalogId=10051&orderStatusStyle=strong&storeId=10151&langId=-1", 
		"Snapshot=t570.inf", 
		"Mode=HTML", 
		LAST);

	
	web_url("HPServices_4", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_={cp_time}&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/ManageMyDevicesView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t573.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("{AgentType}S43_MyDevices"),LR_AUTO);
	
	/*
	web_save_timestamp_param("cp_time", LAST);
	
	lr_start_transaction(lr_eval_string("{AgentType}S43_AddDevices"));
	
	
	web_submit_data("ManageDeviceCmd", 
		"Action=https://{p_hostName}/us-en/shop/ManageDeviceCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/ManageMyDevicesView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t574.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=langId", "Value=-1", ENDITEM, 
		"Name=storeId", "Value=10151", ENDITEM, 
		LAST);

	
	web_custom_request("HPAddDeviceCmd", 
		"URL=https://{p_hostName}/us-en/shop/HPAddDeviceCmd", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/ManageMyDevicesView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t590.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=serialNo=5CG8347PSM&productNumber=K0Q14A#BGJ&nickName=PerfTesing&token={cp_authToken}",
		LAST);

	
		web_url("ManageMyDevicesView_2", 
		"URL=https://{p_hostName}/us-en/shop/ManageMyDevicesView?catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/ManageMyDevicesView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t596.inf", 
		"Mode=HTML", 
		LAST);

	web_url("HPServices_5",
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_={cp_time}&action=cupids&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/ManageMyDevicesView?catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t598.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction(lr_eval_string("{AgentType}S43_AddDevices"),LR_AUTO);
*/


	lr_start_transaction(lr_eval_string("{AgentType}S45_MyAddressBook"));

	web_url("AddressBookDashboard", 
		"URL=https://{p_hostName}/us-en/shop/AddressBookDashboard?addressBookStyle=strong&catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t113.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("HPServices_8", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1512990878844&action=cupis&catentryId=&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AddressBookDashboard?addressBookStyle=strong&catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t100.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("{AgentType}S45_MyAddressBook"),LR_AUTO);

	lr_start_transaction(lr_eval_string("{AgentType}S46_AddShippingAddress"));

	web_url("AddAddress", 
		"URL=https://{p_hostName}/us-en/shop/AddAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AddressBookDashboard?addressBookStyle=strong&catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t125.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("HPServices_9", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1512990910049&action=cupis&catentryId=&modelId=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AddAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t110.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("{AgentType}S46_AddShippingAddress"),LR_AUTO);

	web_convert_param("cp_authToken_HTML",
					  "SourceString={cp_authToken}",
					  "SourceEncoding=URL",
					  "TargetEncoding=HTML",
					  LAST);

	if((atoi(lr_eval_string("{p_MelissaRandomNo}")))>0 && (atoi(lr_eval_string("{p_MelissaRandomNo}")))<51)
	{

	web_reg_save_param("cp_MAddress1","LB=AddressLine1\":\"","RB=\"","ORD=ALL",LAST);
	                   
	web_reg_save_param("cp_MCity","LB=City\":\"","RB=\"","ORD=ALL",LAST);
	
	web_reg_save_param("cp_MState","LB=State\":\"","RB=\"","ORD=ALL",LAST);
	                                                         
	web_reg_save_param("cp_MZipCode","LB=PostalCode\":\"","RB=-","Savelen=5","ORD=ALL",LAST);
	
	lr_start_transaction(lr_eval_string("{AgentType}S46_AddShippingAddress_TypeAhead"));
	
	web_submit_data("address-recommendations", 
		"Action=https://{p_hostName}/wcs/resources/store/10151/address-recommendations", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_hostName}/us-en/shop/OrderShippingBillingView?catalogId=10051&langId=-1&storeId=10151&krypto="
		"buKgCPx3sbwr8R3rKFTaoafunlwAO6bkLcMZDCbhB3omQkpPEVsOTf7LJiZRANCMEf6LnuEb%2FxLhilRWgO5EgXmMKMbjgIGq4T88lHqa1wTkwkHwaIcc4jy4jg7vYqaaRSh%2FII0oamh724BO7OJlxSXOmRH8vV2oIShk%2FT%2FOqmuw%2BEXz1GKcYCsXplE8qV8Van8fN3wBuJCIhfjNXgjJ7R5nsdrHDyAsA6Pvcl15WeiqU5NJSdL7rfUrvS16F9fE3oCfAUg8lXSnp%2FN4zWHt4%2BxFMunzF9a6aRhpRF2RMAayoNjUWItvt8mUh6A0WiF1aFTokZvhW3GPq6OnNuXTDbwflBMjk%2FNA%2B1xoSiEXZ0%2B6F37Gg66FmA2Iw4GB8U3bn4evo2PHZC9x2CESTAk5YQ%3D%3D&ddkey=https%3AOrderCalculate", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=ff", "Value={p_MelissaAddress}", ENDITEM,
		LAST);

	mj=rand()% (atoi(lr_eval_string("{cp_MAddress1_count}")))+1;
	
	lr_save_int(mj,"PartNo");
	
	lr_save_string(lr_eval_string(lr_eval_string("{cp_MAddress1_{PartNo}}")),"p_Address1New");
	
	lr_save_string(lr_eval_string(lr_eval_string("{cp_MCity_{PartNo}}")),"p_CityNew");
	
	lr_save_string(lr_eval_string(lr_eval_string("{cp_MState_{PartNo}}")),"p_StateNew");
	
	lr_save_string(lr_eval_string(lr_eval_string("{cp_MZipCode_{PartNo}}")),"p_ZipCodeNew");
	
	lr_save_string(lr_eval_string("{p_FirstName}"),"p_FirstNameNew");
	
	lr_save_string(lr_eval_string("{p_LastName}"),"p_LastNameNew");
	
	lr_save_string(lr_eval_string("{p_CompanyName}"),"p_CompanyNameNew");
	
	lr_save_string(lr_eval_string("{p_Address2}"),"p_Address2New");
	
	lr_save_string(lr_eval_string("{p_Phone}"),"p_PhoneNew");
	
	lr_end_transaction(lr_eval_string("{AgentType}S46_AddShippingAddress_TypeAhead"),LR_AUTO);
	
	lr_start_transaction(lr_eval_string("{AgentType}S47_SubmitShippingAddress"));

	web_url("CertifiedAddressValidateCmds", 
		//"URL=https://{p_hostName}/us-en/shop/CertifiedAddressValidateCmds?address1={p_Address1New}&address2=&city={p_CityNew}&country=US&zipCode={p_ZipCodeNew}&state={p_StateNew}&name={p_LastName}", 
		  "URL=https://{p_hostName}/us-en/shop/CertifiedAddressValidateCmds?address1={p_Address1New}&address2=&city={p_CityNew}&country=US&zipCode={p_ZipCodeNew}&state={p_StateNew}&name={p_LastName}", 
		  "TargetFrame=",
		  "Resource=0", 
		  "RecContentType=text/html", 
		  "Referer=https://{p_hostName}/us-en/shop/AddAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151", 
		  "Snapshot=t142.inf", 
		  "Mode=HTML", 
		  LAST);

	web_custom_request("HPAddEditAddressCmd", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/HPAddEditAddressCmd", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AddAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		//"Body=storeId=10151&catalogId=10051&langId=-1&status=Shipping&country=US&email1=&addressType=Shipping&authToken={cp_authToken}&nickName=Perf&oldNickName=&firstName={p_FirstName}&lastName={p_LastName}&addrTypeAheadInput=&address1={p_Address1New}=&city={p_CityNew}&state={p_StateNew}&zipCode={p_ZipCodeNew}&addonzipcode=&comapany=&smbFlag=C&phone=(+364+)+278+-+4868+Ext.+362468&phone2=362468", 
		  "Body=storeId=10151&catalogId=10051&langId=-1&status=Shipping&country=US&email1=&addressType=Shipping&authToken={cp_authToken}&nickName=perf&oldNickName=&firstName={p_FirstName}&lastName={p_LastName}&addrTypeAheadInput=&address1={p_Address1New}&address2=&city={p_CityNew}&state={p_StateNew}&zipCode={p_ZipCodeNew}&addonzipcode=&comapany=&smbFlag=C&phone=(+989+)+898+-+9898+Ext.+989898&phone2=989898", 
		LAST);

	web_url("AddressBookDashboard_2",
		"URL=https://{p_hostName}/us-en/shop/AddressBookDashboard?storeId=10151&catalogId=10051&langId-1&asm=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AddAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t145.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("HPServices_10", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1512991089276&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AddressBookDashboard?storeId=10151&catalogId=10051&langId-1&asm=1", 
		"Snapshot=t121.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("{AgentType}S47_SubmitShippingAddress"),LR_AUTO);
	
	

	lr_start_transaction(lr_eval_string("{AgentType}S48_EditShippingAddress"));

	web_url("EditAddress", 
		"URL=https://{p_hostName}/us-en/shop/EditAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151&addressId=13926156", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AddressBookDashboard?storeId=10151&catalogId=10051&langId-1&asm=1", 
		"Snapshot=t158.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("HPServices_11", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1512991308014&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/EditAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151&addressId=13926156", 
		"Snapshot=t129.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("{AgentType}S48_EditShippingAddress"),LR_AUTO);

	lr_start_transaction(lr_eval_string("{AgentType}S49_UpdateShippingAddress"));

	web_url("CertifiedAddressValidateCmds_2", 
		//"URL=https://{p_hostName}/us-en/shop/CertifiedAddressValidateCmds?address1={p_Address1New}&address2=&city={p_CityNew}&country=US&zipCode={p_ZipCodeNew}&state={p_StateNew}&name={p_LastName}", 
		  "URL=https://{p_hostName}/us-en/shop/CertifiedAddressValidateCmds?address1={p_Address1New}&address2=&city={p_CityNew}&country=US&zipCode={p_ZipCodeNew}&state={p_StateNew}&name={p_LastName}", 
		  "TargetFrame=",
		  "Resource=0", 
		  "RecContentType=text/html", 
		  "Referer=https://{p_hostName}/us-en/shop/EditAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151&addressId=13926156", 
		  "Snapshot=t170.inf", 
		  "Mode=HTML", 
		  LAST);

	web_custom_request("HPAddEditAddressCmd",
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/HPAddEditAddressCmd", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AddAddress?authToken=90341041%252CSf4Bagl6giQB6vpVQQxAPhMV%252B9UCQ9VI5UbjlHhL5IA%253D&catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t4.inf",
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		//"Body=storeId=10151&catalogId=10051&langId=-1&status=Shipping&country=US&email1=&addressType=Shipping&authToken={cp_authToken}&nickName=Perf&oldNickName=&firstName={p_FirstName}&lastName={p_LastName}&addrTypeAheadInput=&address1={p_Address1New}=&city={p_CityNew}&state={p_StateNew}&zipCode={p_ZipCodeNew}&addonzipcode=&comapany=&smbFlag=C&phone=(+364+)+278+-+4868+Ext.+362468&phone2=362468", 
		  "Body=storeId=10151&catalogId=10051&langId=-1&status=Shipping&country=US&email1=&addressType=Shipping&authToken={cp_authToken}&nickName=perf&oldNickName=&firstName={p_FirstName}&lastName={p_LastName}&addrTypeAheadInput=&address1={p_Address1New}&address2=&city={p_CityNew}&state={p_StateNew}&zipCode={p_ZipCodeNew}&addonzipcode=&comapany=&smbFlag=C&phone=(+989+)+898+-+9898+Ext.+989898&phone2=989898", 
		LAST);

	web_url("AddressBookDashboard_3",
		"URL=https://{p_hostName}/us-en/shop/AddressBookDashboard?storeId=10151&catalogId=10051&langId-1&asu=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/EditAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151&addressId=13926156", 
		"Snapshot=t172.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("HPServices_12", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1512991357746&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AddressBookDashboard?storeId=10151&catalogId=10051&langId-1&asu=1", 
		"Snapshot=t143.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("{AgentType}S49_UpdateShippingAddress"),LR_AUTO);
	
	
	
	//web_reg_find("Text=Update personal details",LAST);

	lr_start_transaction(lr_eval_string("{AgentType}S43_UpdatePersonaldetails"));

	web_url("UserRegistrationForm_2", 
		"URL=https://{p_hostName}/us-en/shop/UserRegistrationForm?authToken={cp_authToken}&editRegistration=Y&catalogId=10051&langId=-1&storeId=10151&userRegistrationStyle=strong", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t210.inf", 
		"Mode=HTML", 
		LAST);
		
	web_url("HPServices_13",
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1512991732082&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/UserRegistrationForm?authToken={cp_authToken}&editRegistration=Y&catalogId=10051&langId=-1&storeId=10151&userRegistrationStyle=strong", 
		"Snapshot=t151.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("{AgentType}S43_UpdatePersonaldetails"),LR_AUTO);
	}
	
	else
	{

	if((atoi(lr_eval_string("{p_MelissaRandomNo}")))>0 && (atoi(lr_eval_string("{p_MelissaRandomNo}")))<51)
	{
	lr_save_string("123 Perf Street","p_Address1New");
	
	lr_save_string(lr_eval_string("{p_city}"),"p_CityNew");
	
	lr_save_string(lr_eval_string("{p_state}"),"p_StateNew");
	
	lr_save_string(lr_eval_string("{p_zipCode}"),"p_ZipCodeNew");
	
	lr_save_string(lr_eval_string("{p_FirstName}"),"p_FirstNameNew");
	
	lr_save_string(lr_eval_string("{p_LastName}"),"p_LastNameNew");
	
	lr_save_string(lr_eval_string("{p_CompanyName}"),"p_CompanyNameNew");
	
	lr_save_string(lr_eval_string("{p_Address2}"),"p_Address2New");
	
	lr_save_string(lr_eval_string("{p_Phone}"),"p_PhoneNew");
	}
	else
	{
	lr_save_string(lr_eval_string("{p_Address1}"),"p_Address1New");
	
	lr_save_string(lr_eval_string("{p_city}"),"p_CityNew");
	
	lr_save_string(lr_eval_string("{p_state}"),"p_StateNew");
	
	lr_save_string(lr_eval_string("{p_zipCode}"),"p_ZipCodeNew");
	
	lr_save_string(lr_eval_string("{p_FirstName}"),"p_FirstNameNew");
	
	lr_save_string(lr_eval_string("{p_LastName}"),"p_LastNameNew");
	
	lr_save_string(lr_eval_string("{p_CompanyName}"),"p_CompanyNameNew");
	
	lr_save_string(lr_eval_string("{p_Address2}"),"p_Address2New");
	
	lr_save_string(lr_eval_string("{p_Phone}"),"p_PhoneNew");
	}
	lr_start_transaction(lr_eval_string("{AgentType}S47_SubmitShippingAddress"));

	web_url("CertifiedAddressValidateCmds", 
		//"URL=https://{p_hostName}/us-en/shop/CertifiedAddressValidateCmds?address1={p_Address1New}&address2=&city={p_CityNew}&country=US&zipCode={p_ZipCodeNew}&state={p_StateNew}&name={p_LastName}", 
		  "URL=https://{p_hostName}/us-en/shop/CertifiedAddressValidateCmds?address1={p_Address1New}&address2=&city={p_CityNew}&country=US&zipCode={p_ZipCodeNew}&state={p_StateNew}&name={p_LastName}", 
		  "TargetFrame=",
		  "Resource=0", 
		  "RecContentType=text/html", 
		  "Referer=https://{p_hostName}/us-en/shop/AddAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151", 
		  "Snapshot=t142.inf", 
		  "Mode=HTML", 
		  LAST);

	web_custom_request("HPAddEditAddressCmd", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/HPAddEditAddressCmd", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AddAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		//"Body=storeId=10151&catalogId=10051&langId=-1&status=Shipping&country=US&email1=&addressType=Shipping&authToken={cp_authToken}&nickName=Perf&oldNickName=&firstName={p_FirstName}&lastName={p_LastName}&addrTypeAheadInput=&address1={p_Address1New}=&city={p_CityNew}&state={p_StateNew}&zipCode={p_ZipCodeNew}&addonzipcode=&comapany=&smbFlag=C&phone=(+364+)+278+-+4868+Ext.+362468&phone2=362468", 
		  "Body=storeId=10151&catalogId=10051&langId=-1&status=Shipping&country=US&email1=&addressType=Shipping&authToken={cp_authToken}&nickName=perf&oldNickName=&firstName={p_FirstName}&lastName={p_LastName}&addrTypeAheadInput=&address1={p_Address1New}&address2=&city={p_CityNew}&state={p_StateNew}&zipCode={p_ZipCodeNew}&addonzipcode=&comapany=&smbFlag=C&phone=(+989+)+898+-+9898+Ext.+989898&phone2=989898", 
		LAST);

	web_url("AddressBookDashboard_2",
		"URL=https://{p_hostName}/us-en/shop/AddressBookDashboard?storeId=10151&catalogId=10051&langId-1&asm=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AddAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t145.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("HPServices_10", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1512991089276&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AddressBookDashboard?storeId=10151&catalogId=10051&langId-1&asm=1", 
		"Snapshot=t121.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("{AgentType}S47_SubmitShippingAddress"),LR_AUTO);
	
	

	lr_start_transaction(lr_eval_string("{AgentType}S48_EditShippingAddress"));

	web_url("EditAddress", 
		"URL=https://{p_hostName}/us-en/shop/EditAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151&addressId=13926156", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AddressBookDashboard?storeId=10151&catalogId=10051&langId-1&asm=1", 
		"Snapshot=t158.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("HPServices_11", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1512991308014&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/EditAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151&addressId=13926156", 
		"Snapshot=t129.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("{AgentType}S48_EditShippingAddress"),LR_AUTO);

	lr_start_transaction(lr_eval_string("{AgentType}S49_UpdateShippingAddress"));

	web_url("CertifiedAddressValidateCmds_2", 
		//"URL=https://{p_hostName}/us-en/shop/CertifiedAddressValidateCmds?address1={p_Address1New}&address2=&city={p_CityNew}&country=US&zipCode={p_ZipCodeNew}&state={p_StateNew}&name={p_LastName}", 
		  "URL=https://{p_hostName}/us-en/shop/CertifiedAddressValidateCmds?address1={p_Address1New}&address2=&city={p_CityNew}&country=US&zipCode={p_ZipCodeNew}&state={p_StateNew}&name={p_LastName}", 
		  "TargetFrame=",
		  "Resource=0", 
		  "RecContentType=text/html", 
		  "Referer=https://{p_hostName}/us-en/shop/EditAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151&addressId=13926156", 
		  "Snapshot=t170.inf", 
		  "Mode=HTML", 
		  LAST);

	web_custom_request("HPAddEditAddressCmd",
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/HPAddEditAddressCmd", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AddAddress?authToken=90341041%252CSf4Bagl6giQB6vpVQQxAPhMV%252B9UCQ9VI5UbjlHhL5IA%253D&catalogId=10051&langId=-1&storeId=10151", 
		"Snapshot=t4.inf",
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		//"Body=storeId=10151&catalogId=10051&langId=-1&status=Shipping&country=US&email1=&addressType=Shipping&authToken={cp_authToken}&nickName=Perf&oldNickName=&firstName={p_FirstName}&lastName={p_LastName}&addrTypeAheadInput=&address1={p_Address1New}=&city={p_CityNew}&state={p_StateNew}&zipCode={p_ZipCodeNew}&addonzipcode=&comapany=&smbFlag=C&phone=(+364+)+278+-+4868+Ext.+362468&phone2=362468", 
		  "Body=storeId=10151&catalogId=10051&langId=-1&status=Shipping&country=US&email1=&addressType=Shipping&authToken={cp_authToken}&nickName=perf&oldNickName=&firstName={p_FirstName}&lastName={p_LastName}&addrTypeAheadInput=&address1={p_Address1New}&address2=&city={p_CityNew}&state={p_StateNew}&zipCode={p_ZipCodeNew}&addonzipcode=&comapany=&smbFlag=C&phone=(+989+)+898+-+9898+Ext.+989898&phone2=989898", 
		LAST);

	web_url("AddressBookDashboard_3",
		"URL=https://{p_hostName}/us-en/shop/AddressBookDashboard?storeId=10151&catalogId=10051&langId-1&asu=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/EditAddress?authToken={cp_authToken}&catalogId=10051&langId=-1&storeId=10151&addressId=13926156", 
		"Snapshot=t172.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("HPServices_12", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1512991357746&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/AddressBookDashboard?storeId=10151&catalogId=10051&langId-1&asu=1", 
		"Snapshot=t143.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("{AgentType}S49_UpdateShippingAddress"),LR_AUTO);
	
	
	
	// web_reg_find("Text=Update personal details",LAST);

	lr_start_transaction(lr_eval_string("{AgentType}S43_UpdatePersonaldetails"));

	web_url("UserRegistrationForm_2", 
		"URL=https://{p_hostName}/us-en/shop/UserRegistrationForm?authToken={cp_authToken}&editRegistration=Y&catalogId=10051&langId=-1&storeId=10151&userRegistrationStyle=strong", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Snapshot=t210.inf", 
		"Mode=HTML", 
		LAST);
		
	web_url("HPServices_13",
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&_=1512991732082&action=cupis&catentryId=&modelId=&retainPOCart=false", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/UserRegistrationForm?authToken={cp_authToken}&editRegistration=Y&catalogId=10051&langId=-1&storeId=10151&userRegistrationStyle=strong", 
		"Snapshot=t151.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("{AgentType}S43_UpdatePersonaldetails"),LR_AUTO);
	
	}
	
	
	
	LoginFlag=1;

	
	web_set_max_html_param_len("1024");
	
	}
	
	else
	{
		 lr_exit(LR_EXIT_ACTION_AND_CONTINUE,LR_AUTO);
	}
	return 0;
}
