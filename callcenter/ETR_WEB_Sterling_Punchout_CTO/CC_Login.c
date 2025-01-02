CC_Login()
{
	
		
	
	web_reg_find("Text=IBM Call Center for Commerce", "savecount=abc",LAST);
	
	web_set_max_retries("5");
	
	lr_think_time(40);
	
	web_reg_save_param("cp_PaySessionID","LB=JSESSIONID=0000","RB=:","Notfound=Warning",LAST);
	
	lr_start_transaction("C00_Homepage");

	web_url("login.do", 
		"URL=https://{p_SterlingHostName}/isccs/isccs/login.do", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");


	lr_end_transaction("C00_Homepage",LR_AUTO);

lr_think_time(20);

	web_reg_find("Text=IBM Call Center for Commerce",
		LAST);
	
	
	web_reg_save_param_regexp(
		"ParamName=scCSRFToken",
		"RegExp=\\ scApplicationInfo\\.setCSRFToken\\('(.*?)'\\)",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/home.do*",
		LAST);
	
	lr_start_transaction("C01_AgentLogin");

	web_submit_data("processLogin.do", 
		"Action=https://{p_SterlingHostName}/isccs/isccs/processLogin.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/login.do", 
		"Snapshot=t6.inf", 
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
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerInput", "Value={}", ENDITEM, 
		"Name=scControllerData", "Value={\"isccs_home_HomeInitController\":{\"controllerId\":\"isccs_home_HomeInitController\",\"MashupRefs\":{\"MashupRef\":[]},\"ChildControllers\":{\"ChildController\":[{\"controllerId\":\"isccs_home_portlets_OrderPortletInitController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrganizationList\",\"Input\":{},\"mashupRefObj\":{\"sourceNamespace\":\"getOrganizationList_output\",\"callSequence\":\"\",\"mashupRefId\":\"getOrganizationList\",\"sequence\":\"\",\""
		"sourceBindingOptions\":\"\",\"mashupId\":\"orderPortlet_getOrganizationList\"}}]}},{\"controllerId\":\"isccs_home_portlets_CustomerPortletInitController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCustomerOrganizationList\",\"Input\":{},\"mashupRefObj\":{\"sourceNamespace\":\"getHomeCustomerOrganizationList_output\",\"callSequence\":\"\",\"mashupRefId\":\"getCustomerOrganizationList\",\"sequence\":\"4\",\"sourceBindingOptions\":\"\",\"mashupId\":\"customerSearch_getOrganizationList\"}},"
		"{\"mashupRefId\":\"getDisplayRuleDetails\",\"Input\":{},\"mashupRefObj\":{\"sourceNamespace\":\"getHomeDisplayCustomerTypeRule_output\",\"callSequence\":\"\",\"mashupRefId\":\"getDisplayRuleDetails\",\"sequence\":\"6\",\"sourceBindingOptions\":\"\",\"mashupId\":\"customerSearch_getDisplayCustomerTypeRule\"}},{\"mashupRefId\":\"getDefaultRuleDetails\",\"Input\":{},\"mashupRefObj\":{\"sourceNamespace\":\"getHomeDefaultCustomerTypeRule_output\",\"callSequence\":\"\",\"mashupRefId\":\""
		"getDefaultRuleDetails\",\"sequence\":\"5\",\"sourceBindingOptions\":\"\",\"mashupId\":\"customerSearch_getDefaultCustomerTypeRule\"}}]}},{\"controllerId\":\"isccs_home_portlets_ReturnsPortletInitController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getReturnOrganizationList\",\"Input\":{},\"mashupRefObj\":{\"sourceNamespace\":\"getOrganizationList_output\",\"callSequence\":\"\",\"mashupRefId\":\"getReturnOrganizationList\",\"sequence\":\"\",\"sourceBindingOptions\":\"\",\"mashupId\":\""
		"orderPortlet_getOrganizationList\"}}]}},{\"controllerId\":\"isccs_home_portlets_ProductPortletInitController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrgList\",\"Input\":{},\"mashupRefObj\":{\"sourceNamespace\":\"enterpriseList\",\"callSequence\":\"\",\"mashupRefId\":\"getOrgList\",\"sequence\":\"\",\"sourceBindingOptions\":\"\",\"mashupId\":\"productBrowsing_getOrganizationList\"}}]}},{\"controllerId\":\"isccs_home_portlets_CouponPortletInitController\",\"MashupRefs\":{\"MashupRef\""
		":[{\"mashupRefId\":\"getOrgList\",\"Input\":{},\"mashupRefObj\":{\"cached\":\"PAGE\",\"sourceNamespace\":\"enterpriseList\",\"mashupRefId\":\"getOrgList\",\"mashupId\":\"orderPortlet_getOrganizationList\"}}]}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_revert_auto_header("SCIAjax");

	web_revert_auto_header("SCIVer");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("isccs.editors.HomeEditorBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.HomeEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_HomeEditorBehaviorController\":{\"controllerId\":\"isccs_editors_HomeEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getEnterpriseList\",\"Input\":{\"Organization\":{}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_add_auto_header("SCIAjax", 
		"Y");

	web_add_auto_header("SCIVer", 
		"0.9");

	web_submit_data("isccs.home.portlets.MyAlertsPortletBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.home.portlets.MyAlertsPortletBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_home_portlets_MyAlertsPortletBehaviorController\":{\"controllerId\":\"isccs_home_portlets_MyAlertsPortletBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getMyAlertsAndQueues\",\"Input\":{\"getAlertStatisticsForUser\":{}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C01_AgentLogin",LR_AUTO);

//	lr_think_time(20);

	return 0;
}
