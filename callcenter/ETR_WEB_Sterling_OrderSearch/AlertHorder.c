AlertHorder()
{
	
	lr_start_transaction("C53-1_HOrder_CreateAlert");
	
	web_custom_request("wizardController.do_6", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t39.inf", 
		"Mode=HTTP", 
		"Body=scWizardDefId=isccs.alert.wizards.createAlert.CreateAlertWizard&isWizard=true&wizardData="
		 "%7B%22scWizardDefId%22%3A%22isccs.alert.wizards.createAlert.CreateAlertWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22PersonInfoBillTo%22%3A%7B%22{cp_personInfoBill}Company%22%3A%22%22%7D%2C%22DisplayEntryType%22%3A%22Web%22%2C%22isHistory%22%3A%22N%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22OrderNo%22%3A%22%7Bp_quickOrder%7D%22%2C%22CustomerZipCode%22%3A%2210007%22%2C%22DocumentType%22%3A%220001%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22OrderName%22%3A%22%22%2C%22SellerOrganizationName%22%3A%22HP%20US%20Web%20Store%22%2C%22CustomerPONo%22%3A%22%22%2C%22CustomerLastName%22%3A%22Development%22%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%2C%22EntryType%22%3A%22Web%22%2C%22MaxOrderStatusDesc%22%3A%22{cp_MaxOrderStatus}%22%2C%22CustomerPhoneNo%22%3A%22{cp_CustomerPhone}%22%2C%22DisplayStatus%22%3A%22{cp_DisplayStatus}%22%2C%22"
		 "PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22{cp_TotalAmount}%22%7D%2C%22CustomerEMailID%22%3A%22{cp_CustomerEMailID}%22%2C%22TaxExemptionCertificate%22%3A%22%22%2C%22PersonInfoShipTo%22%3A%7B%22{cp_personInfoShip}Company%22%3A%22%22%2C%22HasMultipleAddresses%22%3A%22N%22%7D%2C%22CustomerFirstName%22%3A%22{cp_CustomerFirstName}%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22"
		 "HasPendingChanges%22%3A%22N%22%2C%22CarrierServiceCode%22%3A%22YS%22%2C%22Status%22%3A%22{cp_MaxOrderStatus}%22%2C%22SupportLevel%22%3A%22Full%22%2C%22ReturnOrders%22%3A%7B%7D%2C%22MultipleStatusesExist%22%3A%22N%22%2C%22ShipToKey%22%3A%22{cp_ShipKey}%22%2C%22HoldFlag%22%3A%22N%22%2C%22OrderHoldTypes%22%3A%7B%22OrderHoldType%22%3A%5B%7B%22Status%22%3A%22{cp_OrderHoldType}%22%7D%5D%7D%2C%22Modifications%22%3A%7B%7D%2C%22OverallTotals%22%3A%7B%22GrandTotal%22%3A%22{cp_TotalAmount}%22%7D%2C%22OrderDate%22%3A%22{cp_OrderDate}%22%2C%22OverallStatus%22%3A%22%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y",
		 LAST);
	
	web_submit_data("isccs.alert.create.CreateAlertBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.alert.create.CreateAlertBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_alert_create_CreateAlertBehaviorController\":{\"controllerId\":\"isccs_alert_create_CreateAlertBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getQueueList\",\"Input\":{\"Queue\":{\"CallingOrganizationCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C53-1_HOrder_CreateAlert",LR_AUTO);

	web_reg_save_param("cp_inboxKey","LB=\"InboxKey\":\"","RB=\",","NotFound=Warning",LAST);
	lr_start_transaction("C53-2_HOrder_AlertConfirm");

	web_submit_data("isccs.alert.create.CreateAlertBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.alert.create.CreateAlertBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_alert_create_CreateAlertBehaviorController\":{\"controllerId\":\"isccs_alert_create_CreateAlertBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"createAlert\",\"Input\":{\"Inbox\":{\"EnterpriseKey\":\"USWS\",\"ExceptionType\":\"YCD_BACK_ORDER_CHECK\",\"Priority\":1,\"QueueKey\":\"2014093006275358173\",\"Order\":{\"OrderNo\":\"{p_Horder}\",\"DocumentType\":\"0001\"},\"DetailDescription\":\"test\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);
	
	web_reg_save_param("cp_followdate","LB=\"FollowupDate\":\"","RB=T","NotFound=Warning",LAST);
	
	web_reg_save_param("cp_GeneratedDate","LB=\"GeneratedOn\":\"","RB=\",","NotFound=Warning",LAST);
	
	web_reg_save_param("cp_LastOccured","LB=\"LastOccurredOn\":\"","RB=\",","NotFound=Warning",LAST);
	
	web_reg_save_param("cp_followupdate","LB=\"FollowupDate\":\"","RB=T","NotFound=Warning",LAST);

	web_submit_data("wizardController.do_6", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t46.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scWizardDefId", "Value=isccs.alert.wizards.manageAlert.ManageAlertWizard", ENDITEM, 
		"Name=isWizard", "Value=true", ENDITEM, 
		"Name=wizardData", "Value={\"scWizardDefId\":\"isccs.alert.wizards.manageAlert.ManageAlertWizard\",\"isWizard\":true,\"scControllerInput\":{\"Inbox\":{\"ExceptionTypeDescription\":\"YCD_BACK_ORDER_CHECK\",\"InboxKey\":\"{cp_inboxKey}\",\"ExceptionType\":\"YCD_BACK_ORDER_CHECK\",\"EnterpriseKey\":\"USWS\"}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C53-2_HOrder_AlertConfirm",LR_AUTO);

	lr_start_transaction("C53-3_HOrder_AlertConfirmDetails");
	
	web_submit_data("isccs.alert.manage.ManageAlertBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.alert.manage.ManageAlertBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t44.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_alert_manage_ManageAlertBehaviorController\":{\"controllerId\":\"isccs_alert_manage_ManageAlertBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"alertDetails_changeException\",\"Input\":{\"Inbox\":{\"InboxKey\":\"{cp_inboxKey}\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"EnterpriseKey\":\"USWS\",\"Priority\":1,\"Status\":\"OPEN\",\"FollowupDate\":\"{cp_followupdate}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.home.portlets.MyAlertsPortletBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.home.portlets.MyAlertsPortletBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t45.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_home_portlets_MyAlertsPortletBehaviorController\":{\"controllerId\":\"isccs_home_portlets_MyAlertsPortletBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getMyAlertsAndQueues\",\"Input\":{\"getAlertStatisticsForUser\":{}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C53-3_HOrder_AlertConfirmDetails",LR_AUTO);
	
	
	
	lr_think_time(10);

	return 0;
}
