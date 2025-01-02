CC_byName()
{
	
	
	int pmax,prand,custNamecount;
	
	//web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
	lr_start_transaction("C02_CustomerSearchLink");	


	web_submit_data("wizardController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scWizardDefId", "Value=isccs.customer.wizards.customerSearch.CustomerSearchWizard", ENDITEM, 
		"Name=isWizard", "Value=true", ENDITEM, 
		"Name=wizardData", "Value={\"scWizardDefId\":\"isccs.customer.wizards.customerSearch.CustomerSearchWizard\",\"isWizard\":true,\"scControllerInput\":{}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C02_CustomerSearchLink",LR_AUTO);	
	
	web_reg_save_param("cp_HPPID","LB=\"HPPID\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CustomerKey","LB=\"CustomerKey\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_custName","LB=\"UserID\":\"","RB=\"","ORD=ALL","Notfound=warning",LAST);
	
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
	lr_start_transaction("C03_CS_ByName");

	web_custom_request("isccs.customer.search.CustomerListScreenBehaviorController.do_5", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.customer.search.CustomerListScreenBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_customer_search_CustomerListScreenBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_customer_search_CustomerListScreenBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22getCustomerList%22%2C%22Input%22%3A%7B%22Customer%22%3A%7B%22ApplyQueryTimeout%22%3A%22Y%22%2C%22CallingOrganizationCode%22%3A%22USWS%22%2C%22CustomerType%22%3A%2202%22%2C%22HPCustomerSearch%22%3A%7B%22HPSearchKey%22%3A%22{p_CustomerSearchByName}%22%2C%22HPSearchType%22%3A%22firs"
		"tlast%22%2C%22HPSearchCond%22%3A%22Exact%20Match%22%7D%7D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	lr_end_transaction("C03_CS_ByName",LR_AUTO);
	
	custNamecount=atoi(lr_eval_string("{cp_custName_count}"));
	
	if(custNamecount == 0)
	{
		lr_exit(LR_EXIT_ACTION_AND_CONTINUE,LR_AUTO);
	}

	else
	{
	
pmax=atoi(lr_eval_string("{cp_custName_count}"));
					
prand= (rand() % pmax)+1;
			
sprintf(spara,"{cp_custName_%d}",prand);
			
	lr_save_string(lr_eval_string(spara),"cp_UserId");	
	
	web_set_sockets_option("CLOSE_KEEPALIVE_CONNECTIONS","1");
	
	lr_start_transaction("C04_CustomerSelection");
	
	
	web_custom_request("wizardController.do_4", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.customer.wizards.customerDetails.CustomerDetailsWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.customer.wizards.customerDetails.CustomerDetailsWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Customer%22%3A%7B%22CustomerContactList%22%3A%7B%22CustomerContact%22%3A%5B%7B%22LastName%22%3A%22ARMSTRONG%22%2C%22UserID%22%3A%22taarmstrong62%40yahoo.com%22%2C%22EmailID%22%3A%22taarmstrong62%40yahoo.com%22%2C%22FullName%22%3A%22TONY%2C%20ARMSTRONG%22%2C%22Name%22%3A%22{p_CustomerSearchByName}%22%2C%22FirstName%22%3A%22TONY%22%2C%22CustomerAdditionalAddre"
		"ssList%22%3A%7B%22CustomerAdditionalAddress%22%3A%5B%7B%22PersonInfo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22State%22%3A%22%22%2C%22LastName%22%3A%22ARMSTRONG%22%2C%22CombinedAddressLine%22%3A%22%22%2C%22Country%22%3A%22%22%2C%22EmailID%22%3A%22taarmstrong62%40yahoo.com%22%2C%22FirstName%22%3A%22TONY%22%2C%22City%22%3A%22%22%2C%22ZipCode%22%3A%22%22%7D%7D%5D%7D%2C%22Phone%22%3A%22%22%7D%5D%7D%2C%22CartItems%22%3A%22Y%22%2C%22OrganizationCode%22%3A%22USWS%22%2C%22CustomerKey%22%3A%2{cp_CustomerKey}%22%2C%22"
		"SMBId%22%3A%22%22%2C%22HPPID%22%3A%22{cp_HPPID}%22%2C%22DBSrc%22%3A%22WCS%22%2C%22CIDNumber%22%3A%22%22%2C%22CompanyName%22%3A%22%22%2C%22SystemType%22%3A%22ETR%22%2C%22LastVisit%22%3A%22Oct%2003%2C%202014%22%2C%22CustomerType%22%3A%2202%22%2C%22PricingStatus%22%3A%22EPP_00%22%2C%22CustomerID%22%3A%22WCS%22%2C%22SMBProfileType%22%3A%22Consumer%22%2C%22CIC%22%3A%22%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);


	web_submit_data("isccs.common.notes.CustomerNoteDisplayBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.common.notes.CustomerNoteDisplayBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_common_notes_CustomerNoteDisplayBehaviorController\":{\"controllerId\":\"isccs_common_notes_CustomerNoteDisplayBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getNoteList\",\"Input\":{\"Note\":{\"TableKey\":\"{cp_CustomerKey}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C04_CustomerSelection",LR_AUTO);
	
	}
	
	
	lr_save_string("YES","CustomerSearch");
	
	return 0;
}
