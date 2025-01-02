FindOrder()
{

	lr_think_time(10);
	
	web_reg_save_param("cp_OrderHeaderKey","LB=\"OrderHeaderKey\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_FirstName","LB=\"FirstName\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_MiddleName","LB=\"MiddleName\":\"","RB=\"","Notfound=warning",LAST);

	web_reg_save_param("cp_LastName","LB=\"LastName\":\"","RB=\"","Notfound=warning",LAST);

	web_reg_save_param("cp_AddressLine1","LB=\"AddressLine1\":\"","RB=\"","Notfound=warning",LAST);

	web_reg_save_param("cp_AddressLine2","LB=\"AddressLine2\":\"","RB=\"","Notfound=warning",LAST);

	web_reg_save_param("cp_City","LB=\"City\":\"","RB=\"","Notfound=warning",LAST);

	web_reg_save_param("cp_MobilePhone","LB=\"MobilePhone\":\"","RB=\"","Notfound=warning",LAST);

	web_reg_save_param("cp_ZipCode","LB=\"ZipCode\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_State","LB=\"State\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_Country","LB=\"Country\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_EMailID","LB=\"EMailID\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_OrderLineKey","LB=\"OrderLineKey\":\"","RB=\",","ORD=1","Notfound=warning",LAST);
	
	web_reg_save_param("cp_EnterpriseCode","LB=\"EnterpriseCode\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_OrderNo","LB=\"OrderNo\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_Status","LB=\"Status\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_TotalAmount","LB=\"TotalAmount\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_AddressID","LB=\"AddressID\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_DayPhone","LB=\"DayPhone\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_OrderDate","LB=\"OrderDate\":\"","RB=\"","Notfound=warning",LAST);

	web_reg_save_param("cp_CustomerFirstName","LB=\"CustomerFirstName\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CustomerLastName","LB=\"CustomerLastName\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CustomerEMailID","LB=\"CustomerEMailID\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CustomerZipCode","LB=\"CustomerZipCode\":\"","RB=\"","Notfound=warning",LAST);
	
	//web_reg_save_param("cp_MaximumRecords","LB=\"MaximumRecords\":\"","RB=\"",LAST);
	
	web_reg_save_param("cp_ReturnOrder","LB=\"OrderNo\":\"","RB=\",","Notfound=warning",LAST);
	
	web_reg_save_param("cp_PersonInfoKey","LB=\"PersonInfoKey\":\"","RB=\"","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CustomerPhone","LB=\"CustomerPhoneNo\":\"","RB=\",","Notfound=warning",LAST);
	
	
	web_reg_save_param("cp_MaxOrderStatus","LB=MaxOrderStatusDesc\":\"","RB=\",","Notfound=warning",LAST);
	
	web_reg_save_param("cp_DisplayStatus","LB=DisplayStatus\":\"","RB=\",","Notfound=warning",LAST);
	
	web_reg_save_param("cp_OrderDate","LB=OrderDate\":\"","RB=\",","Notfound=warning",LAST);
	
	

	lr_start_transaction("C50_FindOrder");

	web_submit_data("isccs.home.portlets.OrderPortletBehaviorController.do",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.home.portlets.OrderPortletBehaviorController.do",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t15.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_home_portlets_OrderPortletBehaviorController\":{\"controllerId\":\"isccs_home_portlets_OrderPortletBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrderList\",\"Input\":{\"Order\":{\"OrderNo\":\"{p_Horder}\",\"EnterpriseCode\":\"USWS\",\"MaximumRecords\":\"2\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	web_submit_data("isccs.editors.OrderEditorBehaviorController.do",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorBehaviorController.do",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t16.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getRequiredEditorAttributes\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);
	
	
	
	web_reg_save_param("cp_ShipKey","LB=\"ShipToKey\":\"","RB=\",","Notfound=warning",LAST);
	
	web_reg_save_param("cp_OrderHoldType","LB={\"Status\":\"","RB=\"}]},\"EnterpriseName","Notfound=warning",LAST);

	
	web_custom_request("wizardController.do",
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t79.inf",
		"Mode=HTTP",
		"Body=scWizardDefId=isccs.order.wizards.orderSummary.OrderSummaryWizard&isWizard=true&wizardData=%7B%22scWizardDefId%22%3A%22isccs.order.wizards.orderSummary.OrderSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22PersonInfoBillTo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22EveningPhone%22%3A%22%22%2C%22AddressLine1%22%3A%22{cp_AddressLine1}%22%2C%22isHistory%22%3A%22N%22%2C%22AddressLine2%22%3A%22{cp_AddressLine2}%22%2C%22City%22%3A%22{cp_City}%22%2C%22MobilePhone%22%3A%22%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22PersonID%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22DayPhone%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22Country%22%3A%22US%22%2C%22EMailID%22%3A%22{cp_EMailID}%22%2C%22Title%22%3A%22%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey_1}%22%2C%22Company%22%3A%22%22%7D%2C%22isHistory%22%3A%22N%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22OrderNo%2"
		"2%3A%22{p_Horder}%22%2C%22CustomerZipCode%22%3A%22{cp_ZipCode}%22%2C%22Status%22%3A%22" 
		"%22%2C%22DocumentType%22%3A%220001%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22OrderName%22%3A%22%22%2C%22SellerOrganizationName%22%3A%22HP%20US%20Web%20Store%22%2C%22CustomerPONo%22%3A%22%22%2C%22CustomerLastName%22%3A%22{cp_CustomerLastName}%22%2C%22MultipleStatusesExist%22%3A%22N%22%2C%22HoldFlag%22%3A%22N%22%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%2C%22EntryType%22%3A%22Web%22%2C%22MaxOrderStatusDesc%22%3A%22{cp_Status}%22%2C%22CustomerPhoneNo%22%3A%22%20%22%2C%22DisplayStatus%22%3A%22Shipment%20Line%20Invoiced%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22339.98%22%7D%2C%22TaxExemptionCertificate%22%3A%22%22%2C%22CustomerEMailID%22%3A%22{cp_CustomerEMailID}%22%2C%22PersonInfoShipTo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22EveningPhone%22%3A%22%22%2C%22AddressLine1%22%3A%22{cp_AddressLine1}%22%2C%22isHis"
		"tory%22%3A%22N%22%2C%22AddressLine2%22%3A%22{cp_AddressLine2}%22%2C%22City%22%3A%22{cp_City}%22%2C%22MobilePhone%22%3A%22%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22AddressID%22%3A%22{cp_AddressID}%22%2C%22PersonID%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22DayPhone%22%3A%22{cp_DayPhone}%22%2C%22Department%22%3A%22%22%2C%22Country%22%3A%22US%22%2C%22EMailID%22%3A%22%22%2C%22Title%22%3A%22%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey_2}%22%2C%22Company%22%3A%22%22%7D%2C%22OrderDate%22%3A%22{cp_OrderDate}%22%2C%22CustomerFirstName%22%3A%22{cp_CustomerFirstName}%22%2C%22OverallStatus%22%3A%22%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y",
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryLinesBehaviorController.do",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryLinesBehaviorController.do",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t20.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCompleteShipmentDetails\",\"Input\":{\"Order\":{\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryBehaviorController.do",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryBehaviorController.do",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t21.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCommonCodeList\",\"Input\":{\"CommonCodeList\":{\"CodeType\":\"CarrierServiceCode\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryLinesBehaviorController.do_2",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryLinesBehaviorController.do",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t22.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCompleteOrderLineList\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":10,\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"OrderLine\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"Order\":{\"EnterpriseCode\":\"USWS\",\"SellerOrganizationCode\":\"USWS\"}}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	web_submit_data("isccs.editors.OrderEditorRTBehaviorController.do",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorRTBehaviorController.do",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t23.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorRTBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorRTBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getOrderDetailsForCustomer\",\"Input\":{\"Order\":{\"OrderNo\":\"{p_Horder}\",\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryBehaviorController.do_2",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryBehaviorController.do",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t24.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_pricingSummary\",\"Input\":{\"Order\":{\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	web_submit_data("isccs.editors.OrderEditorRTBehaviorController.do_2",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorRTBehaviorController.do",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t25.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorRTBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorRTBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_customerDetails\",\"Input\":{\"Customer\":{\"CustomerKey\":\"perftestingestoretru@mail.com\",\"OrganizationCode\":\"USWS\",\"CustomerID\":\"WCS\",\"CustomerType\":\"02\",\"IgnoreOrdering\":\"Y\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	lr_end_transaction("C50_FindOrder",LR_AUTO);
	
	//lr_think_time(10);
	
	if(strcmp(lr_eval_string("{cp_Status}"),"Shipment Line Invoiced")==0)
		
	{
		
		CTO();
		
		if(atoi(lr_eval_string("{p_iteration}"))>=0)
		{
			
			BlockReturn();
			AlertHorder();
			
		}
		
		
		return 0;
		
	}
	
	
	else if(strcmp(lr_eval_string("{cp_Status}"),"Shipment Line Invoiced")==0 || strcmp(lr_eval_string("{cp_Status}"),"Shipment Line Invoiced")==0)
		
	{
		
		if(atoi(lr_eval_string("{p_iteration}"))>=0)
		{
			
			BlockReturn();
		}
		
		return 0;
		
	}
	
	else if(strcmp(lr_eval_string("{cp_Status}"),"Shipment Line Invoiced")==0)
		
	{
		
		if(atoi(lr_eval_string("{p_iteration}"))>=0)
		{
			
			AlertHorder();
	}
		
		return 0;
		
	}

	
	return 0;
}
