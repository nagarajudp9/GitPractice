CustomerSearch()
{

	lr_think_time(410);

	lr_start_transaction("clk_findcustomers");

	web_custom_request("wizardController.do_3", 
		"URL=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.customer.wizards.customerSearch.CustomerSearchWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.customer.wizards.customerSearch.CustomerSearchWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Customer%22%3A%7B%22HPCustomerSearch%22%3A%7B%22HPSearchKey%22%3A%22perftestingestoretru%40mail.com%22%2C%22HPSearchType%22%3A%22email%22%2C%22HPSearchCond%22%3A%22Exact%20Match%22%7D%2C%22CallingOrganizationCode%22%3A%22USWS%22%2C%22CustomerType%22%3A%2202%22%2C%22AdvancedSearch%22%3A%22true%22%2C%22FireSearch%22%3A%22true%22%7D%7D%7D&scCSRFToken="
		"1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		EXTRARES, 
		"Url=../isccs/resources/css/icons/images/customer48x48.png", "Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", ENDITEM, 
		LAST);

	web_custom_request("isccs.customer.search.CustomerListScreenBehaviorController.do", 
		"URL=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/scuiimpl/controller/default/isccs.customer.search.CustomerListScreenBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t35.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_customer_search_CustomerListScreenBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_customer_search_CustomerListScreenBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22getCustomerList%22%2C%22Input%22%3A%7B%22Customer%22%3A%7B%22ApplyQueryTimeout%22%3A%22Y%22%2C%22CallingOrganizationCode%22%3A%22USWS%22%2C%22CustomerType%22%3A%2202%22%2C%22HPCustomerSearch%22%3A%7B%22HPSearchKey%22%3A%22perftestingestoretru%40mail.com%22%2C%22HPSearchTy"
		"pe%22%3A%22email%22%2C%22HPSearchCond%22%3A%22Exact%20Match%22%7D%7D%7D%7D%5D%7D%7D%7D&scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		LAST);

	lr_end_transaction("clk_findcustomers",LR_AUTO);

	return 0;
}