QuoteSearch()
{
	
	lr_start_transaction("C71-1_QuoteSearch");

	web_submit_data("wizardController.do",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do",
		"Method=POST",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t11.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scWizardDefId", "Value=isccs.quote.wizards.quoteSearch.QuoteSearchWizard", ENDITEM,
		"Name=isWizard", "Value=true", ENDITEM,
		"Name=wizardData", "Value={\"scWizardDefId\":\"isccs.quote.wizards.quoteSearch.QuoteSearchWizard\",\"isWizard\":true,\"scControllerInput\":{}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	lr_end_transaction("C71-1_QuoteSearch",LR_AUTO);

	lr_start_transaction("C71-2_Search_ByQuote");

	web_reg_save_param("cp_QuoteLastName","LB=\"LastName\":\"","RB=\",","ORD=1","Notfound=warning",LAST);
		
	web_reg_save_param("cp_QuoteExpiryDate","LB=\"ExpiryDate\":\"","RB=\",","Notfound=warning",LAST);
		
	web_reg_save_param("cp_QuoteCustomerId","LB=\"CustomerId\":\"","RB=\",","Notfound=warning",LAST);
		
	web_reg_save_param("cp_QuoteUpdatedOn","LB=\"UpdatedOn\":\"","RB=\",","Notfound=warning",LAST);
		
	web_reg_save_param("cp_QuoteFirstName","LB=\"FirstName\":\"","RB=\",","Notfound=warning",LAST);
		
	web_reg_save_param("cp_QuoteEmail","LB=\"Email\":\"","RB=\",","Notfound=warning",LAST);
		
	web_reg_save_param("cp_QuoteUser","LB=\"CreatedBy\":\"","RB=\"","Notfound=warning",LAST);

	web_custom_request("isccs.quote.search.QuoteListScreenBehaviorController.do",
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.quote.search.QuoteListScreenBehaviorController.do",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t13.inf",
		"Mode=HTML",
		"Body=scControllerData=%7B%22isccs_quote_search_QuoteListScreenBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_quote_search_QuoteListScreenBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22getQuoteList%22%2C%22Input%22%3A%7B%22Quote%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22QuoteNo%22%3A%22{p_QuoteNumber}%22%2C%22HPQuoteSearch%22%3A%7B%22HPSearchCond%22%3A%22Exact%20Match%22%7D%7D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y",
		LAST);

	lr_end_transaction("C71-2_Search_ByQuote",LR_AUTO);

	lr_start_transaction("C71-3_QuoteSelection");

	web_submit_data("wizardController.do_2",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do",
		"Method=POST",
		"EncodeAtSign=YES",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t14.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scWizardDefId", "Value=isccs.customer.wizards.customerDetails.CustomerDetailsWizard", ENDITEM,
		"Name=isWizard", "Value=true", ENDITEM,
		"Name=wizardData", "Value={\"scWizardDefId\":\"isccs.customer.wizards.customerDetails.CustomerDetailsWizard\",\"isWizard\":true,\"scControllerInput\":{\"Customer\":{\"LastName\":\"{cp_QuoteLastName}\",\"ExpiryDate\":\"{cp_QuoteExpiryDate}\",\"Status\":\"RDY\",\"ProfileType\":\"C\",\"CustomerId\":\"{cp_QuoteCustomerId}\",\"UpdatedOn\":\"{cp_QuoteUpdatedOn}\",\"FirstName\":\"{cp_QuoteFirstName}\",\"Email\":\"{cp_QuoteEmail}\",\"QuoteNo\":\"{p_QuoteNumber}\",\"Company\":\"\",\"CreatedBy\":\"{cp_CreatedBy}\",\"CustomerKey\":\"{cp_QuoteCustomerId}\",\"OrganizationCode\":\"USWS\",\"CustomerID\":\"WCS\",\"CustomerType\":\"02\",\"IgnoreOrdering\":\"Y\"}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	web_submit_data("isccs.common.notes.CustomerNoteDisplayBehaviorController.do",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.common.notes.CustomerNoteDisplayBehaviorController.do",
		"Method=POST",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t17.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_common_notes_CustomerNoteDisplayBehaviorController\":{\"controllerId\":\"isccs_common_notes_CustomerNoteDisplayBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getNoteList\",\"Input\":{\"Note\":{\"TableKey\":\"{cp_QuoteCustomerId}\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	lr_end_transaction("C71-3_QuoteSelection",LR_AUTO);
	
	lr_think_time(10);
	
	
	return 0;
}
