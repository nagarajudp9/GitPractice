AdvanceOrderSearch()
{
	
	lr_start_transaction("C55-1_OrderSearch");

	

	web_submit_data("wizardController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scWizardDefId", "Value=isccs.order.wizards.orderSearch.OrderSearchWizard", ENDITEM, 
		"Name=isWizard", "Value=true", ENDITEM, 
		"Name=wizardData", "Value={\"scWizardDefId\":\"isccs.order.wizards.orderSearch.OrderSearchWizard\",\"isWizard\":true,\"scControllerInput\":{\"manageType\":\"\"}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.search.OrderListScreenBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.search.OrderListScreenBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_search_OrderListScreenBehaviorController\":{\"controllerId\":\"isccs_order_search_OrderListScreenBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrderList\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":10,\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"Order\":{\"OrderNo\":\"00\",\"AuthorizedClient\":\"Caas\",\"AuthorizedClientQryType\":\"NE\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

		lr_end_transaction("C55-1_OrderSearch",LR_AUTO);

	//lr_think_time(10);
	
	web_reg_save_param("cp_OrderHeaderKey","LB=\"OrderHeaderKey\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_OrderNo","LB=\"OrderNo\":\"","RB=\"","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CustomerFirstName","LB=\"CustomerFirstName\":\"","RB=\"","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CustomerLastName","LB=\"CustomerLastName\":\"","RB=\"","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CustomerZipCode","LB=\"CustomerZipCode\":\"","RB=\"","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_TotalAmount","LB=\"TotalAmount\":\"","RB=\"","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CustomerEMailID","LB=\"CustomerEMailID\":\"","RB=\"","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_CustomerPhone","LB=\"CustomerPhoneNo\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_PersonalInfoKey","LB=\"PersonInfoKey\":\"","RB=\"","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_AddressLine","LB=\"AddressLine1\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	pmaxValue = atoi(lr_eval_string("{p_randomNum}"));			
	if(pmaxValue<3)
	{


	lr_start_transaction("C55-2_Search_ByZIPCode");

	web_submit_data("isccs.order.search.OrderListScreenBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.search.OrderListScreenBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_search_OrderListScreenBehaviorController\":{\"controllerId\":\"isccs_order_search_OrderListScreenBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrderList\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":10,\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"Order\":{\"ApplyQueryTimeout\":\"Y\",\"DraftOrderFlag\":\"N\",\"ReadFromHistory\":\"N\",\"CustomerZipCode\":\"{p_zipCode}\",\"OrderBy\":{\"Attribute\":{\"Name\":\""
		"OrderDate-Y\"}},\"AuthorizedClient\":\"Caas\",\"AuthorizedClientQryType\":\"NE\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C55-2_Search_ByZIPCode",LR_AUTO);
	
		pmaxValue = atoi(lr_eval_string("{cp_OrderNo_count}"));
		
		prandNumber = (rand() % (pmaxValue))+1;
		
		sprintf(spara, "{cp_OrderNo_%d}",prandNumber);
		lr_save_string(	lr_eval_string(spara), "cp_OrderNo");
		
		sprintf(spara, "{cp_OrderHeaderKey_%d}",prandNumber);
		lr_save_string(	lr_eval_string(spara), "cp_OrderHeaderKey");
		
		sprintf(spara, "{cp_CustomerFirstName_%d}",prandNumber);
		lr_save_string(	lr_eval_string(spara), "cp_CustomerFirstName");
		
		sprintf(spara, "{cp_CustomerLastName_%d}",prandNumber);
		lr_save_string(	lr_eval_string(spara), "cp_CustomerLastName");
		
		sprintf(spara, "{cp_CustomerZipCode_%d}",prandNumber);
		lr_save_string(	lr_eval_string(spara), "cp_CustomerZipCode");
		
		sprintf(spara, "{cp_TotalAmount_%d}",prandNumber);
		lr_save_string(	lr_eval_string(spara), "cp_TotalAmount");
		
		sprintf(spara, "{cp_CustomerEMailID_%d}",prandNumber);
		lr_save_string(	lr_eval_string(spara), "cp_CustomerEMailID");
		
		sprintf(spara, "{cp_CustomerPhone_%d}",prandNumber);
		lr_save_string(	lr_eval_string(spara), "cp_CustomerPhone");

		sprintf(spara, "{cp_PersonalInfoKey_%d}",prandNumber);
		lr_save_string(	lr_eval_string(spara), "cp_PersonalInfoKey");
		
		sprintf(spara, "{cp_AddressLine_%d}",prandNumber);
		lr_save_string(	lr_eval_string(spara), "cp_AddressLine");
		
	web_reg_save_param("cp_OrderNo1","LB=\"OrderNo\":\"","RB=\"","Notfound=warning",LAST);	

	lr_start_transaction("C55-3_OrderSelection");

	web_custom_request("wizardController.do_4", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.order.wizards.orderSummary.OrderSummaryWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.order.wizards.orderSummary.OrderSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22DocumentType%22%3A%220001%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22OrderNo%22%3A%22{cp_OrderNo}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22{cp_TotalAmount}%22%7D%2C%22PersonInfoShipTo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22LastN"
		"ame%22%3A%22{cp_CustomerLastName}%22%2C%22EveningPhone%22%3A%22%22%2C%22AddressLine1%22%3A%22{cp_AddressLine}%22%2C%22isHistory%22%3A%22N%22%2C%22AddressLine2%22%3A%22%22%2C%22City%22%3A%22newyork%22%2C%22MobilePhone%22%3A%22%22%2C%22ZipCode%22%3A%22{cp_CustomerZipCode}%22%2C%22AddressID%22%3A%22address%40hp.com%22%2C%22PersonID%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22State%22%3A%22NY%22%2C%22DayPhone%22%3A%22{cp_CustomerPhone}%22%2C%22Department%22%3A%22%22%2C%22Country%22%3A%22US%22%2C%22EMailID%22%3A%22address%40hp.com%22%2C%22Title%22%3A%22"
		"%22%2C%22FirstName%22%3A%22{cp_CustomerFirstName}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonalInfoKey}%22%2C%22Company%22%3A%22%22%7D%2C%22isHistory%22%3A%22N%22%2C%22CustomerFirstName%22%3A%22{cp_CustomerFirstName}%22%2C%22CustomerLastName%22%3A%22{cp_CustomerLastName}%22%2C%22CustomerEMailID%22%3A%22{cp_CustomerEMailID}%22%2C%22CustomerPhoneNo%22%3A%22{cp_CustomerPhone}%22%2C%22CustomerZipCode%22%3A%22{cp_CustomerZipCode}%22%2C%22BillToID%22%3A%22%22%2C%22CustomerID%22%3A%22%22%2C%22EntryType%22%3A%22Call%20Center%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22TaxExemptF"
		"lag%22%3A%22N%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	

	web_submit_data("isccs.order.details.OrderSummaryBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCommonCodeList\",\"Input\":{\"CommonCodeList\":{\"CodeType\":\"CarrierServiceCode\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCompleteShipmentDetails\",\"Input\":{\"Order\":{\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryLinesBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCompleteOrderLineList\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":10,\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"OrderLine\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"Order\":{\"EnterpriseCode\":\"USWS\",\"SellerOrganizationCode\":\"USWS\"}}}}"
		"]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.editors.OrderEditorRTBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorRTBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorRTBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorRTBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getOrderDetailsForCustomer\",\"Input\":{\"Order\":{\"OrderNo\":\"{cp_OrderNo1}\",\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryBehaviorController.do", 
		"Method=POST", 
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
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorRTBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorRTBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_customerDetails\",\"Input\":{\"Customer\":{\"CustomerKey\":\"{cp_CustomerEMailID}\",\"OrganizationCode\":\"USWS\",\"CustomerID\":\"WCS\",\"CustomerType\":\"02\",\"IgnoreOrdering\":\"Y\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C55-3_OrderSelection",LR_AUTO);
	
	}else if(pmaxValue<6)
	{

	web_reg_save_param("cp_PersonalInfoKey","LB=\"PersonInfoKey\":\"","RB=\"","ORD=ALL","Notfound=warning",LAST);


	lr_start_transaction("C55-3_Search_ByCompanyName");

	web_submit_data("isccs.order.search.OrderListScreenBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.search.OrderListScreenBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_search_OrderListScreenBehaviorController\":{\"controllerId\":\"isccs_order_search_OrderListScreenBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getPersonInfoList\",\"Input\":{\"PersonInfo\":{\"Company\":\"{p_CompanyName}\",\"CompanyQryType\":\"EQ\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);
	
	
	web_submit_data("isccs.order.search.OrderListScreenBehaviorController.do_3", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.search.OrderListScreenBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_search_OrderListScreenBehaviorController\":{\"controllerId\":\"isccs_order_search_OrderListScreenBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrderList\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":10,\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"Order\":{\"ApplyQueryTimeout\":\"Y\",\"EnterpriseCode\":\"USWS\",\"DraftOrderFlag\":\"N\",\"ReadFromHistory\":\"N\",\"OrderBy\":{\"Attribute\":{\"Name\":\""
		"OrderDate-Y\"}},\"AuthorizedClient\":\"Caas\",\"AuthorizedClientQryType\":\"NE\",\"SearchByAddress\":{\"ComplexQuery\":{\"Operator\":\"AND\"}},\"Extn\":{\"ExtnSMBFLAG\":\"true\"},\"ComplexQuery\":{\"Or\":{\"Exp\":[{\"Name\":\"BillToKey\",\"Value\":\"{cp_PersonalInfoKey_1}\"},{\"Name\":\"BillToKey\",\"Value\":\"{cp_PersonalInfoKey_2}\"},{\"Name\":\"BillToKey\",\"Value\":\"{cp_PersonalInfoKey_3}\"},{\"Name\":\"BillToKey\",\"Value\":\"{cp_PersonalInfoKey_4}\"},{\"Name\":\"BillToKey\",\"Value\":\"{cp_PersonalInfoKey_5}\"},{\"Name\":\"BillToKey\",\"Value\":\"{cp_PersonalInfoKey_6}\"},{\"Name\":\"BillToKey\",\"Value\":\"{cp_PersonalInfoKey_7}\"},{\"Name\":\"BillToKey\",\"Value\":\"{cp_PersonalInfoKey_8}\"},{\"Name\":\"BillToKey\",\"Value\":\"{cp_PersonalInfoKey_9}\"},{\"Name\":\"BillToKey\",\"Value\":\"{cp_PersonalInfoKey_10}\"}]}}}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);
	
	
	lr_end_transaction("C55-3_Search_ByCompanyName",LR_AUTO);	
	}
	
	else
	
	{

web_reg_save_param("cp_PersonInfoKey","lb=PersonInfoKey\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_ExtnUSERTYPE","lb=ExtnUSERTYPE\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_ExtnWebProfileId","lb=ExtnWebProfileId\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_email","lb=EMailID\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_LastName","lb=LastName\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_AddressLine1","lb=AddressLine1\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_City","lb=City\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_ZipCode","lb=ZipCode\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_AddressID","lb=AddressID\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_State","lb=State\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_DayPhone","lb=DayPhone\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_totalamount","lb=TotalAmount\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_FirstName","lb=FirstName\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_orderno","lb=OrderNo\":\"","rb=\"",LAST);

lr_start_transaction("C55-4_Search_ByShiptoEmail");

	web_submit_data("isccs.order.search.OrderListScreenBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.search.OrderListScreenBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_search_OrderListScreenBehaviorController\":{\"controllerId\":\"isccs_order_search_OrderListScreenBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrderList\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":10,\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"Order\":{\"ApplyQueryTimeout\":\"Y\",\"DraftOrderFlag\":\"N\",\"ReadFromHistory\":\"N\",\"Extn\":{\"ExtnShipToEmailQryType\":\"EQ\",\"ExtnShipToEmail\":\""
		"{p_SearchByShiptoEmail}\"},\"OrderBy\":{\"Attribute\":{\"Name\":\"OrderDate-Y\"}},\"AuthorizedClient\":\"Caas\",\"AuthorizedClientQryType\":\"NE\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_custom_request("wizardController.do_2", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.order.wizards.orderSummary.OrderSummaryWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.order.wizards.orderSummary.OrderSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22DocumentType%22%3A%220001%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey_1}%22%2C%22OrderNo%22%3A%22{cp_orderno}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22{cp_totalamount}%22%7D%2C%22PersonInfoShipTo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22LastN"
		"ame%22%3A%22{cp_LastName}%22%2C%22EveningPhone%22%3A%22%22%2C%22AddressLine1%22%3A%22{cp_AddressLine1}%22%2C%22isHistory%22%3A%22N%22%2C%22AddressLine2%22%3A%22%22%2C%22City%22%3A%22{cp_City}%22%2C%22MobilePhone%22%3A%22%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22AddressID%22%3A%22{cp_AddressID}%22%2C%22PersonID%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22DayPhone%22%3A%22{cp_DayPhone}%22%2C%22Department%22%3A%22%22%2C%22Country%22%3A%22US%22%2C%22EMailID%22%3A%22{cp_email}%22%2C%22Title%22%3A%22%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey}%22%2C%22Company%22%3A%22%22%7D%2C%22isHistory%22%3A%22N%22%2C%22CustomerFirstName%22%3A%22{cp_FirstName}%22%2C%22CustomerLastName%22%3A%22{cp_LastName}%22%2C%22CustomerEMailID%22%3A%22{cp_email}%22%2C%22CustomerPhoneNo%22%3A%22{cp_DayPhone}%22%2C%22CustomerZipCode%22%3A%22{cp_ZipCode}%22%2C%22BillToID%22%3A%22%22%2C%22CustomerID%22%3A%22%22%2C%22EntryType%22%3A%22Call%20Center%22%2C%22SellerOrganizat"
		"ionCode%22%3A%22USWS%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22Extn%22%3A%7B%22ExtnUSERTYPE%22%3A%22{cp_ExtnUSERTYPE}%22%2C%22ExtnWebProfileId%22%3A%22{cp_ExtnWebProfileId}%22%7D%2C%22AuthorizedClient%22%3A%22WCS%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCompleteShipmentDetails\",\"Input\":{\"Order\":{\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey_1}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryLinesBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCompleteOrderLineList\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":10,\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"OrderLine\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey_1}\",\"Order\":{\"EnterpriseCode\":\"USWS\",\"SellerOrganizationCode\":\"USWS\"}}}}"
		"]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCommonCodeList\",\"Input\":{\"CommonCodeList\":{\"CodeType\":\"CarrierServiceCode\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_pricingSummary\",\"Input\":{\"Order\":{\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey_1}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.editors.OrderEditorRTBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorRTBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorRTBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorRTBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_customerDetails\",\"Input\":{\"Customer\":{\"CustomerKey\":\"{cp_ExtnWebProfileId}\",\"OrganizationCode\":\"USWS\",\"CustomerID\":\"WCS\",\"CustomerType\":\"02\",\"IgnoreOrdering\":\"Y\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.editors.OrderEditorRTBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorRTBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorRTBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorRTBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getOrderDetailsForCustomer\",\"Input\":{\"Order\":{\"OrderNo\":\"{cp_orderno}\",\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	
	lr_end_transaction("C55-4_Search_ByShiptoEmail", LR_AUTO);
	}
	lr_think_time(10);
	return 0;
}
