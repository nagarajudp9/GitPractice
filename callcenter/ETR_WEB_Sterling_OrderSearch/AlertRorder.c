AlertRorder()
{
	
	web_reg_save_param("cp_OrderHeaderKey","LB=\"OrderHeaderKey\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);
		
	web_reg_save_param("cp_HoldFlag","LB=\"HoldFlag\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);

	
	web_reg_save_param("cp_Rorder","LB=\"OrderNo\":\"R","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	//,"PersonInfoKey":"{cp_PersonInfoKey}","Company":""},
	
	web_reg_save_param("cp_PersonInfoKey","LB=\"PersonInfoKey\":\"","RB=\"","ORD=ALL","Notfound=warning",LAST);

	web_reg_save_param("cp_TotalAmt","LB=\"TotalAmount\":\"","RB=\"},","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_custFName","LB=\"CustomerFirstName\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_custLName","LB=\"CustomerLastName\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_AddressLine1","LB=\"AddressLine1\":\"","RB=\"","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_City","LB=\"City\":\"","RB=\"","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_custEmail","LB=\"CustomerEMailID\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_custPhone","LB=\"CustomerPhoneNo\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_custZip","LB=\"CustomerZipCode\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	//web_reg_save_param("cp_ExtnsnRel","LB=\"Extn\":{},\"EnterpriseCode\":\"USWS\",\"OrderNo\":\"R","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	lr_start_transaction("C64-1_Return_ViewSearch");

web_custom_request("isccs.return.search.ReturnListScreenBehaviorController.do_5", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.search.ReturnListScreenBehaviorController.do", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t59.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_return_search_ReturnListScreenBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_return_search_ReturnListScreenBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22getReturnList%22%2C%22scPaginationStrategy%22%3A%22NEXTPAGE%22%2C%22scPageSize%22%3A10%2C%22scPageNumber%22%3A1%2C%22scPreviousPageRecord%22%3A%7B%7D%2C%22Input%22%3A%7B%22Order%22%3A%7B%22ApplyQueryTimeout%22%3A%22Y%22%2C%22FromOrderDate%22%3A%222017-05-05%22%2C%22DraftOrderFlag"
		"%22%3A%22N%22%2C%22ReadFromHistory%22%3A%22N%22%2C%22Status%22%3A%22%20%22%2C%22OrderBy%22%3A%7B%22Attribute%22%3A%7B%22Name%22%3A%22OrderDate-Y%22%7D%7D%7D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	web_submit_data("isccs.return.search.ReturnListScreenBehaviorController.do_6", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.search.ReturnListScreenBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t60.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_search_ReturnListScreenBehaviorController\":{\"controllerId\":\"isccs_return_search_ReturnListScreenBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getExceptionList\",\"Input\":{\"Inbox\":{\"ComplexQuery\":{\"Or\":{\"Exp\":[{\"Name\":\"OrderNo\",\"Value\":\"R{cp_Rorder_1}\"},{\"Name\":\"OrderNo\",\"Value\":\"R{cp_Rorder_2}\"},{\"Name\":\"OrderNo\",\"Value\":\"R{cp_Rorder_3}\"},{\"Name\":\"OrderNo\",\"Value\":\"R{cp_Rorder_4}\"},{\"Name\":"
		"\"OrderNo\",\"Value\":\"R{cp_Rorder_5}\"},{\"Name\":\"OrderNo\",\"Value\":\"R{cp_Rorder_6}\"},{\"Name\":\"OrderNo\",\"Value\":\"R{cp_Rorder_7}\"},{\"Name\":\"OrderNo\",\"Value\":\"R{cp_Rorder_8}\"},{\"Name\":\"OrderNo\",\"Value\":\"R{cp_Rorder_9}\"},{\"Name\":\"OrderNo\",\"Value\":\"R{cp_Rorder_10}\"}]}},\"ActiveFlag\":\"Y\",\"Status\":\"OPEN\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C64-1_Return_ViewSearch",LR_AUTO);
	
	pextn= atoi(lr_eval_string("{cp_HoldFlag_count}"));
	
	prand= (rand()%pextn)+1;
	
	sprintf(spara,"{cp_HoldFlag_%d}",prand);
	lr_save_string(lr_eval_string(spara),"cp_OrderHeaderKey");
	
//	sprintf(parahold,"{cp_PersonInfoShip_%d}",prand);
//	lr_save_string(lr_eval_string(parahold),"cp_PersonInfoShip");
	
	sprintf(parahold,"{cp_PersonInfoKey_%d}",prand);
	lr_save_string(lr_eval_string(parahold),"cp_PersonInfoKey");
	
	sprintf(parahold,"{cp_Rorder_%d}",prand);
	lr_save_string(lr_eval_string(parahold),"cp_Rorder");
	
	sprintf(parahold,"{cp_TotalAmt_%d}",prand);
	lr_save_string(lr_eval_string(parahold),"cp_TotalAmt");
	
	sprintf(parahold,"{cp_custFName_%d}",prand);
	lr_save_string(lr_eval_string(parahold),"cp_custFName");
	
	sprintf(parahold,"{cp_custLName_%d}",prand);
	lr_save_string(lr_eval_string(parahold),"cp_custLName");
	
	sprintf(parahold,"{cp_AddressLine1_%d}",prand);
	lr_save_string(lr_eval_string(parahold),"cp_AddressLine1");
	
	sprintf(parahold,"{cp_City_%d}",prand);
	lr_save_string(lr_eval_string(parahold),"cp_City");
	
	sprintf(parahold,"{cp_custEmail_%d}",prand);
	lr_save_string(lr_eval_string(parahold),"cp_custEmail");
	
	sprintf(parahold,"{cp_custPhone_%d}",prand);
	lr_save_string(lr_eval_string(parahold),"cp_custPhone");
	
	sprintf(parahold,"{cp_custZip_%d}",prand);
	lr_save_string(lr_eval_string(parahold),"cp_custZip");
	
	
	lr_start_transaction("C64-2_Return_Selection");
	
	web_custom_request("wizardController.do_7", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t61.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.return.wizards.returnSummary.ReturnSummaryWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.return.wizards.returnSummary.ReturnSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22DocumentType%22%3A%220003%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22OrderNo%22%3A%22R{cp_Rorder}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22	%22%7D%2C%22PersonInfoShipTo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22Las"
		"tName%22%3A%22{cp_custLName}%22%2C%22EveningPhone%22%3A%22%22%2C%22AddressLine1%22%3A%22{cp_AddressLine1}%22%2C%22isHistory%22%3A%22N%22%2C%22AddressLine2%22%3A%22%22%2C%22City%22%3A%22{cp_City}%22%2C%22MobilePhone%22%3A%22%22%2C%22ZipCode%22%3A%22{cp_custZip}%22%2C%22AddressID%22%3A%22temp_chkOut_{cp_custFName}1509468122901%22%2C%22PersonID%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22State%22%3A%22TX%22%2C%22DayPhone%22%3A%22{cp_custPhone}%22%2C%22Department%22%3A%22%22%2C%22Country%22%3A%22US%22%2C%22EMailID%22%3A%22%22%2C%22Title%22%3A%22"
		"%22%2C%22FirstName%22%3A%22{cp_custFName}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey}%22%2C%22Company%22%3A%22%22%7D%2C%22isHistory%22%3A%22N%22%2C%22CustomerFirstName%22%3A%22{cp_custFName}%22%2C%22CustomerLastName%22%3A%22{cp_custLName}%22%2C%22CustomerEMailID%22%3A%22{cp_custEmail}%22%2C%22CustomerPhoneNo%22%3A%22%22%2C%22CustomerZipCode%22%3A%22{cp_custZip}%22%2C%22BillToID%22%3A%22%22%2C%22CustomerID%22%3A%22%22%2C%22EntryType%22%3A%22Call%20Center%22%2C%22SellerOrganizationCode%22%3A%22USWS%22"
		"%2C%22TaxExemptFlag%22%3A%22N%22%2C%22Extn%22%3A%7B%7D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	web_submit_data("isccs.return.details.ReturnSummaryLinesBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.details.ReturnSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t62.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_details_ReturnSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_return_details_ReturnSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCompleteOrderLineList\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":10,\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"OrderLine\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"Order\":{\"EnterpriseCode\":\"USWS\",\"SellerOrganizationCode\":\"USWS\""
		"}}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);
	
	lr_end_transaction("C64-2_Return_Selection",LR_AUTO);

	
	lr_start_transaction("C65-1_ROrder_CreateAlert");
	
	web_custom_request("wizardController.do_13", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t247.inf", 
		"Mode=HTTP", 
		"Body=scWizardDefId=isccs.alert.wizards.createAlert.CreateAlertWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.alert.wizards.createAlert.CreateAlertWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22DocumentType%22%3A%220003%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22OrderNo%22%3A%22R{cp_Rorder}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22{cp_TotalAmt}%22%7D%2C%22PersonInfoShipTo%22%3A%7B%22{cp_PersonInfoShip}Company%22%3A%22%22%7D%2C%22isHistory%22%3A%22N%22%2C%22CustomerFirstName%22%3A%22{cp_custFName}%22%2C%22CustomerLastName%22%3A%22{cp_custLName}%22%2C%22CustomerEMailID%22%3A%22{cp_custEmail}%22%2C%22CustomerPhoneNo%22%3A%22{cp_custPhone}%22%2C%22CustomerZipCode%22%3A%22{cp_custZip}%22%2C%22BillToID%22%3A%22%22%2C%22CustomerID%22%3A%22%22%2C%22EntryType%22%3A%22Call%20Center%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	web_reg_save_param("cp_queuKey","LB=\"HP_RETURN_ORDER_Q\",\"QueueKey\":\"","RB=\"","Notfound=warning",LAST);
	
	web_submit_data("isccs.alert.create.CreateAlertBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.alert.create.CreateAlertBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_alert_create_CreateAlertBehaviorController\":{\"controllerId\":\"isccs_alert_create_CreateAlertBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getQueueList\",\"Input\":{\"Queue\":{\"CallingOrganizationCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C65-1_ROrder_CreateAlert",LR_AUTO);
	
	web_reg_save_param("cp_inboxKey","LB=\"InboxKey\":\"","RB=\"",LAST);
	
	lr_start_transaction("C65-2_ROrder_AlertConfirm");

	web_custom_request("isccs.alert.create.CreateAlertBehaviorController.do_2", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.alert.create.CreateAlertBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t249.inf", 
		"Mode=HTTP", 
		"Body=scControllerData="
		"%7B%22isccs_alert_create_CreateAlertBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_alert_create_CreateAlertBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22createAlert%22%2C%22Input%22%3A%7B%22Inbox%22%3A%7B%22EnterpriseKey%22%3A%22USWS%22%2C%22ExceptionType%22%3A%22YCD_VERIFY_ADDRESS%22%2C%22Priority%22%3A1%2C%22QueueKey%22%3A%22{cp_queuKey}%22%2C%22Order%22%3A%7B%22OrderNo%22%3A%22R{cp_Rorder}%22%2C%22DocumentType%22%3A%220003%22%7D%2C%"
		"22DetailDescription%22%3A%22This%20is%20sample%20test1	%22%7D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

//	if(strcmp(lr_eval_string("{cp_inboxKey}"),"")==0)
//	{
//	
//		
//		lr_end_transaction("C65-2_ROrder_AlertConfirm",LR_AUTO);
//		
//		return 0;
//		
//	}
//	
	//web_set_max_html_param_len("10000");
	
	//web_reg_save_param("cp_alert","LB={\"Inbox\":{\"","RB=EnterpriseKey\":\"USWS\"",LAST);
	
	web_reg_save_param("cp_followdate","LB=\"FollowupDate\":\"","RB=T",LAST);
	
	web_custom_request("wizardController.do_14", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t250.inf", 
		"Mode=HTTP", 
		"Body=scWizardDefId=isccs.alert.wizards.manageAlert.ManageAlertWizard&isWizard=true&wizardData=%7B%22scWizardDefId%22%3A%22isccs.alert.wizards.manageAlert.ManageAlertWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Inbox%22%3A%7B%22ExceptionTypeDescription%22%3A%22Verify%20Address%22%2C%22InboxKey%22%3A%22{cp_inboxKey}%22%2C%22ExceptionType%22%3A%22YCD_VERIFY_ADDRESS%22%2C%22EnterpriseKey%22%3A%22USWS%22%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%7D%7D%7D&"
		"scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	lr_end_transaction("C65-2_ROrder_AlertConfirm",LR_AUTO);

	lr_start_transaction("C65-3_ROrder_AlertConfirmDetails");

	web_submit_data("isccs.alert.manage.ManageAlertBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.alert.manage.ManageAlertBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t252.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_alert_manage_ManageAlertBehaviorController\":{\"controllerId\":\"isccs_alert_manage_ManageAlertBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"alertDetails_changeException\",\"Input\":{\"Inbox\":{\"InboxKey\":\"{cp_inboxKey}\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"EnterpriseKey\":\"USWS\",\"Priority\":1,\"Status\":\"OPEN\",\"FollowupDate\":\"{cp_followdate}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.home.portlets.MyAlertsPortletBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.home.portlets.MyAlertsPortletBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t253.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_home_portlets_MyAlertsPortletBehaviorController\":{\"controllerId\":\"isccs_home_portlets_MyAlertsPortletBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getMyAlertsAndQueues\",\"Input\":{\"getAlertStatisticsForUser\":{}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C65-3_ROrder_AlertConfirmDetails",LR_AUTO);
	
	lr_think_time(10);
	return 0;
}
