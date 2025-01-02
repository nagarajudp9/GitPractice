CustomerSearch()
{
	
	lr_start_transaction("C03_FindCustomers");

	web_custom_request("wizardController.do_3", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.customer.wizards.customerSearch.CustomerSearchWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.customer.wizards.customerSearch.CustomerSearchWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%7D%7D&scCSRFToken="
		"{scCSRFToken}&scFlag=Y", 
		LAST);
	
	web_reg_save_param("cp_CustomerKey","LB=\"CustomerKey\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_HPId","LB=\"HPPID\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CartItemStatus","LB=CartItems\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CustomerEMailID","LB=\"UserID\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CustomerFirstName","LB=\"FirstName\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CustomerLastName","LB=\"LastName\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CustomerType","LB=\"CustomerType\":\"","RB=\"","Notfound=warning",LAST);

	web_reg_save_param("cp_FullName","LB=\"FullName\":\"","RB=\"","Notfound=warning",LAST);
	


	web_custom_request("isccs.customer.search.CustomerListScreenBehaviorController.do", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.customer.search.CustomerListScreenBehaviorController.do", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_customer_search_CustomerListScreenBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_customer_search_CustomerListScreenBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22getCustomerList%22%2C%22scPaginationStrategy%22%3A%22NEXTPAGE%22%2C%22scPageSize%22%3A10%2C%22scPageNumber%22%3A1%2C%22scPreviousPageRecord%22%3A%7B%7D%2C%22Input%22%3A%7B%22Customer%22%3A%7B%22ApplyQueryTimeout%22%3A%22Y%22%2C%22CallingOrganizationCode%22%3A%22USWS%22%2C%22CustomerType%22%3A%2202%22%2C%22HPCustomerSearch%22%3A%7B%22HPSearchKey%22%3A%22{p_CustomerSearchByName}%22%2C%22HPSearchType%22%3A%22lastName%22%2C%22HPSearchCond%22%3A%22Exact%20Match%22%7D%7D%7D%7D%5D%7D%7D%7D"
		"&scControllerInput=%7B%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	lr_end_transaction("C03_FindCustomers",LR_AUTO);

	//lr_think_time(10);
	

		
		lr_start_transaction("C04_CustomerSelection");
	
	

	web_custom_request("wizardController.do_3", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.customer.wizards.customerDetails.CustomerDetailsWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.customer.wizards.customerDetails.CustomerDetailsWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Customer%22%3A%7B%22CustomerContactList%22%3A%7B%22CustomerContact%22%3A%5B%7B%22LastName%22%3A%22{cp_CustomerLastName}%22%2C%22UserID%22%3A%22{cp_CustomerEMailID}%22%2C%22EmailID%22%3A%22{cp_CustomerEMailID}%22%2C%22FullName%22%3A%22{cp_FullName}%22%2C%22Name%22%3A%22{cp_CustomerFirstName}%20{cp_CustomerLastName}%22%2C%22FirstName%22%3A%22{cp_CustomerFirstName}%22%2C"
		"%22CustomerAdditionalAddressList%22%3A%7B%22CustomerAdditionalAddress%22%3A%5B%7B%22PersonInfo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22State%22%3A%22%22%2C%22LastName%22%3A%22{cp_CustomerLastName}%22%2C%22CombinedAddressLine%22%3A%22%22%2C%22Country%22%3A%22%22%2C%22EmailID%22%3A%22{cp_CustomerEMailID}%22%2C%22FirstName%22%3A%22{cp_CustomerFirstName}%22%2C%22City%22%3A%22%22%2C%22ZipCode%22%3A%22%22%7D%7D%5D%7D%2C%22Phone%22%3A%22%22%7D%5D%7D%2C%22CartItems%22%3A%22{cp_CartItemStatus}%22%2C%22OrganizationCode%22%3A%22USWS%22%2C%2"
		"2CustomerKey%22%3A%22{cp_CustomerKey}%22%2C%22SMBId%22%3A%22%22%2C%22HPPID%22%3A%22{cp_HPId}%22%2C%22DBSrc%22%3A%22WCS%22%2C%22CIDNumber%22%3A%22%22%2C%22CompanyName%22%3A%22%22%2C%22SystemType%22%3A%22ETR%22%2C%22LastVisit%22%3A%22Aug%2031%2C%202016%22%2C%22CustomerType%22%3A%22{cp_CustomerType}%22%2C%22PricingStatus%22%3A%22GS%22%2C%22CustomerID%22%3A%22WCS%22%2C%22SMBProfileType%22%3A%22Consumer%22%2C%22CIC%22%3A%22%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);


	web_submit_data("isccs.common.notes.CustomerNoteDisplayBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.common.notes.CustomerNoteDisplayBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_common_notes_CustomerNoteDisplayBehaviorController\":{\"controllerId\":\"isccs_common_notes_CustomerNoteDisplayBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getNoteList\",\"Input\":{\"Note\":{\"TableKey\":\"{cp_CustomerKey}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);


	
	lr_end_transaction("C04_CustomerSelection",LR_AUTO);

	

	lr_think_time(10);
	
	
	return 0;
}
