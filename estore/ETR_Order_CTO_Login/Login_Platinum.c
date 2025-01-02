Login_Platinum()
{
	SignIn();
	
	lr_think_time(60);

	lr_start_transaction("S02_UserLogin_Platinum");
/*	
	web_add_auto_header("Origin", 
		"https://login.stg.cd.id.hp.com");

	web_custom_request("AWc7nCRAeesaa3d7C6NSzroEywK1AAAAAAAAAABJf4-AlTvwnJLWw4DjWa6Yt3mEoPGVRFwUMzLBxL9kcmWY8RUpSAxyzjR7ZDZpsyYp17c1HmkWGn3YHjVgIV-G8hefWCNg1OZDCx8Q8iWQ31d8_z5wVxjUA2gq0pAea7ANWIWyxeTj9wl9vl1Pe1QevK0xF_rl7JkOKBtVqgLdBGxvlNA4LCgiVC2Qi_OF1TgvFw5ehqeSjufwJL-JjWb2zMvp", 
		"URL=https://directory.stg.cd.id.hp.com/directory/v1/authentication/login/{cp_CorrelationParameter2}", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://login.stg.cd.id.hp.com/login-ui?flow=https://directory.stg.cd.id.hp.com/directory/v1/authentication/login/{cp_CorrelationParameter}", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
		
	web_add_header("Accept-Encoding","gzip,deflate,br");
	web_add_header("content-type","application/json;charset=utf8");

	web_custom_request("AWc7nCRAeesaa3d7C6NSzroEywK1AAAAAAAAAABJf4-AlTvwnJLWw4DjWa6Yt3mEoPGVRFwUMzLBxL9kcmWY8RUpSAxyzjR7ZDZpsyYp17c1HmkWGn3YHjVgIV-G8hefWCNg1OZDCx8Q8iWQ31d8_z5wVxjUA2gq0pAea7ANWIWyxeTj9wl9vl1Pe1QevK0xF_rl7JkOKBtVqgLdBGxvlNA4LCgiVC2Qi_OF1TgvFw5ehqeSjufwJL-JjWb2zMvp_2", 
		"URL=https://directory.stg.cd.id.hp.com/directory/v1/authentication/login/{cp_CorrelationParameter2}", 
		"Method=PUT", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://login.stg.cd.id.hp.com/login-ui?flow=https://directory.stg.cd.id.hp.com/directory/v1/authentication/login/{cp_CorrelationParameter}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		"Body={\"schemas\":[\"urn:pingidentity:scim:api:messages:2.0:AuthenticationRequest\"],\"meta\":{\"resourceType\":\"login\",\"location\":\"https://directory.stg.cd.id.hp.com/directory/v1/authentication/login/"
		"{cp_CorrelationParameter2}\"},\"followUp\":{\"type\":\"authorize\",\"$ref\":\"https://directory.stg.cd.id.hp.com/directory/v1/oauth/authorize/"
		"{cp_CorrelationParameter1}\"},\"client\":{\"name\":\"{cp_ClientName}\",\"description\":\"{\\\"enabled\\\":true,\\\"displayName\\\":\\\"HP.com ITG Store\\\",\\\"domain\\\":\\\"hpid\\\",\\\"extendedMeta\\\":{\\\"createdByClient\\\":\\\"@devPortal@\\\",\\\"lastModifiedByClient\\\":\\\"@devPortal@\\\"},\\\"legalZone\\\":\\\"GLOBAL\\\",\\\"origination\\\":\\\"apigee\\\",\\\"validateEmailAfter\\\":-1}\"},\"urn:hpid"
		":governance:authenticator:client:1.0\":{\"status\":\"ready\"},\"urn:pingidentity:scim:api:messages:2.0:ExternalIdentityAuthenticationRequest\":{\"providers\":[],\"status\":\"ready\"},\"urn:hpid:governance:authenticator:marketingConsents:1.0\":{\"status\":\"ready\"},\"urn:pingidentity:scim:api:messages:2.0:RegistrationAuthenticationRequest\":{\"registrableAttributes\":[\"countryResidence\",\"emails\",\"enabled\",\"legalZone\",\"locale\",\"marketingConsents\",\"name\",\"password\",\"phoneNumbers\","
		"\"termsAndConditions\",\"type\",\"userName\"],\"passwordRequirements\":[{\"type\":\"length\",\"description\":\"The password must contain between 8 and 256 characters.\",\"minPasswordLength\":\"8\",\"maxPasswordLength\":\"256\"},{\"type\":\"regularExpression\",\"description\":\"The password must contain three of the following:  English uppercase characters (A through Z);  English lowercase characters (a through z);  Numerals (0 through 9);  Non-alphabetic characters (such as !, $, #, %).\",\""
		"matchBehavior\":\"require-match\",\"matchPattern\":\"(?=.{8,})((?=.*\\\\d)(?=.*[a-z])(?=.*[A-Z])|(?=.*\\\\d)(?=.*[a-zA-Z])(?=.*[\\\\W_])|(?=.*[a-z])(?=.*[A-Z])(?=.*[\\\\W_])).*\"}],\"status\":\"ready\"},\"urn:hpid:governance:authenticator:checkUsername:1.0\":{\"status\":\"ready\",\"userName\":\"{p_platinumUser}\"},\"urn:hpid:governance:authenticator:termsAndConditions:1.0\":{\"status\":\"ready\"},\"urn:pingidentity:scim:api:messages:2.0:UsernamePasswordAuthenticationRequest\":{\""
		"passwordExpiring\":false,\"usernameRecovery\":{\"type\":\"HPID Username Recovery Flow Handler\",\"$ref\":\"https://directory.stg.cd.id.hp.com/directory/v1/authentication/account/HPID%20Username%20Recovery%20Flow%20Handler/"
		"{cp_UserNameFlowHandler}\"},\"passwordRecovery\":{\"type\":\"HPID Password Recovery Flow Handler\",\"$ref\":\"https://directory.stg.cd.id.hp.com/directory/v1/authentication/account/HPID%20Password%20Recovery%20Flow%20Handler/"
		"{cp_PasswordFlowHandler}\"},\"status\":\"ready\"},\"urn:hpid:governance:authenticator:customCaptcha:1.0\":{\"captchaKey\":\"{cp_CaptchaKey}=:1599034250830\",\"captchaImage\":\"{cp_CaptchaImage}\",\"required\":true,\"recaptchaKey\":\"6LeIxAcTAAAAAJcZVRqyHh71UMIEGNQ_MXjiZKhI\",\"status\":\"ready\"},\"urn"
		":hpid:governance:authenticator:checkPasswordAge:1.0\":{\"status\":\"ready\"}}", 
		LAST);

	web_add_header("Access-Control-Request-Headers", 
		"content-type");

	web_add_header("Access-Control-Request-Method", 
		"PUT");
	

	web_custom_request("AWc7nCRAeesaa3d7C6NSzroEywK1AAAAAAAAAABJf4-AlTvwnJLWw4DjWa6Yt3mEoPGVRFwUMzLBxL9kcmWY8RUpSAxyzjR7ZDZpsyYp17c1HmkWGn3YHjVgIV-G8hefWCNg1OZDCx8Q8iWQ31d8_z5wVxjUA2gq0pAea7ANWIWyxeTj9wl9vl1Pe1QevK0xF_rl7JkOKBtVqgLdBGxvlNA4LCgiVC2Qi_OF1TgvFw5ehqeSjufwJL-JjWb2zMvp_3", 
		"URL=https://directory.stg.cd.id.hp.com/directory/v1/authentication/login/{cp_CorrelationParameter2}", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://login.stg.cd.id.hp.com/login-ui/password", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
		
	web_reg_save_param("cp_CorrelationParameter3","LB=v1/oauth/authorize/","RB=\"}","ORD=1",LAST);
	
	web_add_header("Accept-Encoding","gzip,deflate,br");
	web_add_header("content-type","application/json;charset=utf8");

	web_custom_request("AWc7nCRAeesaa3d7C6NSzroEywK1AAAAAAAAAABJf4-AlTvwnJLWw4DjWa6Yt3mEoPGVRFwUMzLBxL9kcmWY8RUpSAxyzjR7ZDZpsyYp17c1HmkWGn3YHjVgIV-G8hefWCNg1OZDCx8Q8iWQ31d8_z5wVxjUA2gq0pAea7ANWIWyxeTj9wl9vl1Pe1QevK0xF_rl7JkOKBtVqgLdBGxvlNA4LCgiVC2Qi_OF1TgvFw5ehqeSjufwJL-JjWb2zMvp_4", 
		"URL=https://directory.stg.cd.id.hp.com/directory/v1/authentication/login/{cp_CorrelationParameter2}", 
		"Method=PUT", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://login.stg.cd.id.hp.com/login-ui/password", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"Body={\"schemas\":[\"urn:pingidentity:scim:api:messages:2.0:AuthenticationRequest\"],\"meta\":{\"resourceType\":\"login\",\"location\":\"https://directory.stg.cd.id.hp.com/directory/v1/authentication/login/"
		"{cp_CorrelationParameter2}\"},\"followUp\":{\"type\":\"authorize\",\"$ref\":\"https://directory.stg.cd.id.hp.com/directory/v1/oauth/authorize/"
		"{cp_CorrelationParameter1}\"},\"client\":{\"name\":\"{cp_ClientName}\",\"description\":\"{\\\"enabled\\\":true,\\\"displayName\\\":\\\"HP.com ITG Store\\\",\\\"domain\\\":\\\"hpid\\\",\\\"extendedMeta\\\":{\\\"createdByClient\\\":\\\"@devPortal@\\\",\\\"lastModifiedByClient\\\":\\\"@devPortal@\\\"},\\\"legalZone\\\":\\\"GLOBAL\\\",\\\"origination\\\":\\\"apigee\\\",\\\"validateEmailAfter\\\":-1}\"},\"urn:hpid"
		":governance:authenticator:client:1.0\":{\"status\":\"ready\"},\"urn:pingidentity:scim:api:messages:2.0:ExternalIdentityAuthenticationRequest\":{\"providers\":[],\"status\":\"ready\"},\"urn:hpid:governance:authenticator:marketingConsents:1.0\":{\"status\":\"ready\"},\"urn:pingidentity:scim:api:messages:2.0:RegistrationAuthenticationRequest\":{\"registrableAttributes\":[\"countryResidence\",\"emails\",\"enabled\",\"legalZone\",\"locale\",\"marketingConsents\",\"name\",\"password\",\"phoneNumbers\","
		"\"termsAndConditions\",\"type\",\"userName\"],\"passwordRequirements\":[{\"type\":\"length\",\"description\":\"The password must contain between 8 and 256 characters.\",\"minPasswordLength\":\"8\",\"maxPasswordLength\":\"256\"},{\"type\":\"regularExpression\",\"description\":\"The password must contain three of the following:  English uppercase characters (A through Z);  English lowercase characters (a through z);  Numerals (0 through 9);  Non-alphabetic characters (such as !, $, #, %).\",\""
		"matchBehavior\":\"require-match\",\"matchPattern\":\"(?=.{8,})((?=.*\\\\d)(?=.*[a-z])(?=.*[A-Z])|(?=.*\\\\d)(?=.*[a-zA-Z])(?=.*[\\\\W_])|(?=.*[a-z])(?=.*[A-Z])(?=.*[\\\\W_])).*\"}],\"status\":\"ready\"},\"urn:hpid:governance:authenticator:checkUsername:1.0\":{\"status\":\"ready\",\"userName\":\"{p_platinumUser}\"},\"urn:hpid:governance:authenticator:termsAndConditions:1.0\":{\"status\":\"ready\"},\"urn:pingidentity:scim:api:messages:2.0:UsernamePasswordAuthenticationRequest\":{\""
		"passwordExpiring\":false,\"usernameRecovery\":{\"type\":\"HPID Username Recovery Flow Handler\",\"$ref\":\"https://directory.stg.cd.id.hp.com/directory/v1/authentication/account/HPID%20Username%20Recovery%20Flow%20Handler/"
		"{cp_UserNameFlowHandler}\"},\"passwordRecovery\":{\"type\":\"HPID Password Recovery Flow Handler\",\"$ref\":\"https://directory.stg.cd.id.hp.com/directory/v1/authentication/account/HPID%20Password%20Recovery%20Flow%20Handler/"
		"{cp_PasswordFlowHandler}\"},\"status\":\"ready\",\"username\":\"{p_platinumUser}@hpid\",\"password\":\"{p_password}\"},\"urn:hpid:governance:authenticator:customCaptcha:1.0\":{\"captchaKey\":\"{cp_CaptchaKey}=:1599034250830\",\"captchaImage\":\"{cp_CaptchaImage}\",\"required\":true,\"recaptchaKey\":\"{cp_ReCaptchaKey}\",\"status\":\"ready\"},\"urn"
		":hpid:governance:authenticator:checkPasswordAge:1.0\":{\"userName\":\"{p_platinumUser}\",\"clientName\":\"{cp_ClientName}\"}}", 
		LAST);
	
	web_reg_save_param("cp_FinalState","LB=v1/oauth/authorize?final_state=","RB=\"}","ORD=1",LAST);

	web_url("AWc7nCRAeesaa3d7C6NSzroEywK1AAAAAAAAAAA1COuLWyYO94KxgWkYG5jKmcFl1Bzta0sX94AOU9a2o9FMwVqZWO3Kju0fN7YzbMrWjRwG_wnGnC1zUEPt8xpMlK8ZyY0JuI6rIFHlTWpG-pxCcJMme7mRB2V5l5wESLNiujEivq_UprRdeh1agbru0AXSaGGcQr9mlqPMQdqY7oa6iwTmUw0pBFh4B6NbId2qXfMv45VVigS5rcilebxsZhdr", 
		"URL=https://directory.stg.cd.id.hp.com/directory/v1/oauth/authorize/{cp_CorrelationParameter3}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://login.stg.cd.id.hp.com/login-ui/password", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("Origin");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");
	
	web_reg_save_param("cp_Krypto","LB=&krypto=","RB=%3D&ddkey","ORD=1",LAST);
	
	web_reg_save_param("cp_PaySessionID","LB=JSESSIONID=0000","RB=:","Notfound=warning",LAST);
	
	web_reg_save_param("cp_clientip","LB=clientip:\"","RB=\",","Notfound=Warning",LAST);

	web_url("authorize_2", 
		"URL=https://directory.stg.cd.id.hp.com/directory/v1/oauth/authorize?final_state={cp_FinalState}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://login.stg.cd.id.hp.com/login-ui/password", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_find("Search=All","Text=\"userType\": \"R\"","savecount=Register",LAST);
	
	web_reg_save_param("cp_iCount","LB=\"iCount\": ","RB=,","Notfound=warning",LAST);

	web_url("HPServices", 
		"URL=https://{p_hostName}/us-en/shop/HPServices?langId=-1&storeId=10151&catalogId=10051&pstoreId=&_=1599033901675&action=cupids&catentryId=3074457345619623818%2C3074457345619633325%2C3074457345619562320%2C3074457345619533327%2C3074457345619583826%2C3074457345619317819%2C3074457345619673829%2C3074457345619203818%2C3074457345619645319%2C3074457345619534818&modelId=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/TopCategoriesDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_Krypto}%3D&ddkey=https%3AETRLogonFlow", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Origin", 
		"https://{p_hostName}");

	web_custom_request("HPLoyaltyEligibleCheckCmd", 
		"URL=https://{p_hostName}/us-en/shop/HPLoyaltyEligibleCheckCmd", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_hostName}/us-en/shop/TopCategoriesDisplayView?catalogId=10051&langId=-1&storeId=10151&krypto={cp_Krypto}%3D&ddkey=https%3AETRLogonFlow", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);
	
	web_revert_auto_header("Origin");
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
		"Body={\"username\":\"{p_platinumUser}\"}", 
		LAST);

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
		"Body={\"username\":\"{p_platinumUser}@hpid\",\"password\":\"{p_password}\"}", 
		LAST);
	
	web_add_header("Upgrade-Insecure-Requests", 
		"1");
	
	web_reg_save_param("cp_KryptoNew","LB=krypto=","RB=&ddkey","ORD=1","Notfound=Warning",LAST);
	
	web_reg_save_param("cp_Krypto","LB=krypto=","RB=&ddkey","ORD=1",LAST);
	
	web_reg_save_param("cp_clientip","LB=clientip:\"","RB=\",","Notfound=Warning",LAST);

	web_url("ETRLogonFlow", 
		"URL=https://{p_hostName}/webapp/wcs/stores/servlet/ETRLogonFlow?catalogId=10051&langId=-1&storeId=10151&code={cp_Code}&state=operation:login", 
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
		"{cp_KryptoNew}&ddkey=https%3AETRLogonFlow", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		LAST);
	
	if(atoi(lr_eval_string("{Register}"))>0)
        {
			lr_end_transaction("S02_UserLogin_Platinum",LR_PASS);
        }
    else
        {
    		lr_end_transaction("S02_UserLogin_Platinum",LR_FAIL);
    		
            lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
        }
    
	LoginFlag=1;
	platinumFlag=1;	
	
	lr_save_string(lr_eval_string("{p_platinumUser}"), "p_userEmail"); 
	
	lr_save_string("?pStoreID=bizclubplatinum","StoreType");
	lr_save_string("&pStoreID=bizclubplatinum","StoreType1");
	return 0;
}
