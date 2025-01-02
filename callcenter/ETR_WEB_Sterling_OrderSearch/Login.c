Login()
{

	web_reg_find("Text=IBM Call Center for Commerce",LAST);	
	
	lr_start_transaction("C01_AgentLogin");

/*Correlation comment - Do not change!  Original value='1512721390372jRCx1Sk6LfrGSulrM6jehp' Name ='scCSRFToken' Type ='Manual'*/
	
	
	web_reg_save_param_regexp(
		"ParamName=scCSRFToken",
		"RegExp=\\ scApplicationInfo\\.setCSRFToken\\('(.*?)'\\)",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/home.do*",
		LAST);
		
	web_reg_find("Text=\"Customer\":","SaveCount=agentCount",LAST);

	web_submit_data("processLogin.do", 
		"Action=https://{p_SterlingHostName}/isccs/isccs/processLogin.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/login.do", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=DisplayUserID", "Value={p_SterlingUsers}", ENDITEM, 
		"Name=Password", "Value={p_password}", ENDITEM, 
		"Name=EnterpriseCode", "Value=", ENDITEM, 
		LAST);

	web_submit_data("isccs.home.HomeInitController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.home.HomeInitController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerInput", "Value={}", ENDITEM, 
		"Name=scControllerData", "Value={\"isccs_home_HomeInitController\":{\"controllerId\":\"isccs_home_HomeInitController\",\"MashupRefs\":{\"MashupRef\":[]},\"ChildControllers\":{\"ChildController\":[{\"controllerId\":\"isccs_home_portlets_OrderPortletInitController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrganizationList\",\"Input\":{},\"mashupRefObj\":{\"cached\":\"PAGE\",\"sourceNamespace\":\"getOrganizationList_output\",\"mashupRefId\":\"getOrganizationList\",\"sequence\":\"\",\""
		"mashupId\":\"orderPortlet_getOrganizationList\",\"callSequence\":\"\",\"sourceBindingOptions\":\"\"}}]}},{\"controllerId\":\"isccs_home_portlets_CustomerPortletInitController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCustomerOrganizationList\",\"Input\":{},\"mashupRefObj\":{\"cached\":\"PAGE\",\"sourceNamespace\":\"getHomeCustomerOrganizationList_output\",\"mashupRefId\":\"getCustomerOrganizationList\",\"sequence\":\"4\",\"mashupId\":\"customerSearch_getOrganizationList\",\""
		"callSequence\":\"\",\"sourceBindingOptions\":\"\"}},{\"mashupRefId\":\"getDisplayRuleDetails\",\"Input\":{},\"mashupRefObj\":{\"cached\":\"PAGE\",\"sourceNamespace\":\"getHomeDisplayCustomerTypeRule_output\",\"mashupRefId\":\"getDisplayRuleDetails\",\"sequence\":\"6\",\"mashupId\":\"customerSearch_getDisplayCustomerTypeRule\",\"callSequence\":\"\",\"sourceBindingOptions\":\"\"}},{\"mashupRefId\":\"getDefaultRuleDetails\",\"Input\":{},\"mashupRefObj\":{\"cached\":\"PAGE\",\"sourceNamespace\":\""
		"getHomeDefaultCustomerTypeRule_output\",\"mashupRefId\":\"getDefaultRuleDetails\",\"sequence\":\"5\",\"mashupId\":\"customerSearch_getDefaultCustomerTypeRule\",\"callSequence\":\"\",\"sourceBindingOptions\":\"\"}}]}},{\"controllerId\":\"isccs_home_portlets_ReturnsPortletInitController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getReturnOrganizationList\",\"Input\":{},\"mashupRefObj\":{\"cached\":\"PAGE\",\"sourceNamespace\":\"getOrganizationList_output\",\"mashupRefId\":\""
		"getReturnOrganizationList\",\"sequence\":\"\",\"mashupId\":\"orderPortlet_getOrganizationList\",\"callSequence\":\"\",\"sourceBindingOptions\":\"\"}}]}},{\"controllerId\":\"isccs_home_portlets_ProductPortletInitController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrgList\",\"Input\":{},\"mashupRefObj\":{\"cached\":\"PAGE\",\"sourceNamespace\":\"enterpriseList\",\"mashupRefId\":\"getOrgList\",\"sequence\":\"\",\"mashupId\":\"productBrowsing_getOrganizationList\",\"callSequence\":\"\","
		"\"sourceBindingOptions\":\"\"}}]}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.editors.HomeEditorBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.HomeEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_HomeEditorBehaviorController\":{\"controllerId\":\"isccs_editors_HomeEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getEnterpriseList\",\"Input\":{\"Organization\":{}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C01_AgentLogin",LR_AUTO);
	
	
//	if(atoi(lr_eval_string("{agentCount}")) > 0)
//		{
//			lr_end_transaction("C01_AgentLogin",LR_PASS);
//
//		}
//		else
//		{
//			lr_end_transaction("C01_AgentLogin",LR_FAIL);
//			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);			
//		}
	
	lr_think_time(10);

	return 0;
}
