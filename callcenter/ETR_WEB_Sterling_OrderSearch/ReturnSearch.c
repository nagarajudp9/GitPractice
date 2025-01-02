ReturnSearch()
{
	
	lr_start_transaction("C59_ReturnSearch");

	web_submit_data("wizardController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scWizardDefId", "Value=isccs.return.wizards.returnSearch.ReturnSearchWizard", ENDITEM, 
		"Name=isWizard", "Value=true", ENDITEM, 
		"Name=wizardData", "Value={\"scWizardDefId\":\"isccs.return.wizards.returnSearch.ReturnSearchWizard\",\"isWizard\":true,\"scControllerInput\":{}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.return.search.ReturnListScreenBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.search.ReturnListScreenBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_search_ReturnListScreenBehaviorController\":{\"controllerId\":\"isccs_return_search_ReturnListScreenBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_return_usergrpperm\",\"Input\":{\"User\":{\"Loginid\":\"{p_SterlingUsers}\",\"DisplayLocalizedFieldInLocale\":\"en_US_EST\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.return.search.ReturnSearchBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.search.ReturnSearchBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_search_ReturnSearchBehaviorController\":{\"controllerId\":\"isccs_return_search_ReturnSearchBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_userpreference\",\"Input\":{\"User\":{\"Loginid\":\"{p_SterlingUsers}\",\"DisplayLocalizedFieldInLocale\":\"en_US_EST\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.return.search.ReturnSearchBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.search.ReturnSearchBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_search_ReturnSearchBehaviorController\":{\"controllerId\":\"isccs_return_search_ReturnSearchBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_returnReason\",\"Input\":{}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C59_ReturnSearch",LR_AUTO);
	
	lr_think_time(10);
	
	
	return 0;
}
