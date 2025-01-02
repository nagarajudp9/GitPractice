MassNotes()
{

	pmaxValue = atoi(lr_eval_string("{p_randomNum}"));			
	if(pmaxValue>0 && pmaxValue<8)
		{	


	lr_start_transaction("C54-1_MassNotes_Add");

	web_submit_data("extn.massNotesScreen.massOrderNotesScreenInitController.do",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/extn.massNotesScreen.massOrderNotesScreenInitController.do",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t12.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"extn_massNotesScreen_massOrderNotesScreenInitController\":{\"controllerId\":\"extn_massNotesScreen_massOrderNotesScreenInitController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrganizationList\",\"Input\":{}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	lr_end_transaction("C54-1_MassNotes_Add",LR_AUTO);
	
	//lr_think_time(10);

	web_reg_find("Text=Draft Order Created",LAST);
	
	lr_start_transaction("C54-2_MassNotes_Update");

	web_custom_request("extn.massNotesScreen.massOrderNotesScreenBehaviorController.do",
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/extn.massNotesScreen.massOrderNotesScreenBehaviorController.do",

		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y",
		"Snapshot=t14.inf",
		"Mode=HTML",
		"Body=scControllerData=%7B%22extn_massNotesScreen_massOrderNotesScreenBehaviorController%22%3A%7B%22controllerId%22%3A%22extn_massNotesScreen_massOrderNotesScreenBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22changeOrder%22%2C%22Input%22%3A%7B%22Order%22%3A%7B%22OrderNo%22%3A%22{p_Horder}%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22Notes%22%3A%7B%22Note%22%3A%7B%22NoteText%22%3A%22Backordered%20status%22%2C%22ContactUser%22%3A%22{p_SterlingUsers}%22%2C%22Priority%22%3A%221%22%7D%7D%7D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y",
		LAST);

	lr_end_transaction("C54-2_MassNotes_Update",LR_AUTO);

	
	//lr_think_time(10);
	
	}
	
		else if(pmaxValue>=8 && pmaxValue<=10)
		
	{
	
	web_reg_find("text=OrganizationName","savecount=Coupancode",LAST);
	
    lr_start_transaction("C87_CoupanCodeSearch");

	web_submit_data("wizardController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scWizardDefId", "Value=isccs.coupon.wizards.CouponSearchWizard", ENDITEM, 
		"Name=isWizard", "Value=true", ENDITEM, 
		"Name=wizardData", "Value={\"scWizardDefId\":\"isccs.coupon.wizards.CouponSearchWizard\",\"isWizard\":true,\"scControllerInput\":{\"Order\":{\"EnterpriseCode\":\"USWS\",\"FromOrderDate\":\"2022-06-06\",\"ToOrderDate\":\"2022-12-11\",\"OrderLine\":{\"Promotion\":{\"Extn\":{\"ExtnAwardId\":\"{p_CouponCode}\",\"ExtnAwardIdQryType\":\"EQ\"}}},\"CustomerEMailIDQryType\":\"EQ\",\"AdvancedSearch\":\"true\",\"FireSearch\":\"true\"}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);
    
    /*

	web_reg_save_param("cp_OrderNo","lb=OrderNo\":\"","rb=\",","notfound=warning",LAST);
	web_reg_save_param("cp_orderheaderkey","lb=OrderHeaderKey\":\"","rb=\",","notfound=warning",LAST);
	web_reg_save_param("cp_Email","lb=EMailID\":\"","rb=\",","notfound=warning",LAST);
	web_reg_save_param("cp_Orderlinekey","lb=OrderLineKey\":\"","rb=\"}","ORD=ALL","notfound=warning",LAST);
//	web_add_auto_header("X-Requested-With","XMLHttpRequest");
	web_reg_save_param("cp_EveningPhone","lb=EveningPhone\":\"","rb=\",","notfound=warning",LAST);
	web_reg_save_param("cp_AddressLine1","lb=AddressLine1\":\"","rb=\",","notfound=warning",LAST);
	web_reg_save_param("cp_Firstname","lb=\"FirstName\":\"","rb=\",","notfound=warning",LAST);
	web_reg_save_param("cp_PersonInfoKey","lb=PersonInfoKey\":\"","rb=\",","notfound=warning",LAST);
	web_reg_save_param("cp_AddressID","lb=AddressID\":\"","rb=\",","notfound=warning",LAST);
	
		
	//web_reg_save_param("cp_EMailID","LB=\"EMailID\":\"","RB=\"","Notfound=warning",LAST);
	
	*/
	
	web_reg_save_param("cp_CustomerPhoneNo","lb=CustomerPhoneNo\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_EnterpriseName","lb=EnterpriseName\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_EntryType","lb=EntryType\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_MaxOrderStatusDesc","lb=MaxOrderStatusDesc\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_DocumentType","lb=DocumentType\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_OrderDate","lb=OrderDate\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_PromotionKey","lb=PromotionKey\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_StatusDescription","lb=StatusDescription\":\"","rb=\"}]}","notfound=warning",LAST);
web_reg_save_param("cp_HoldType","lb=HoldType\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_Status_1","lb=Status\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_PromotionId","lb=PromotionId\":\"","rb=\"","notfound=warning",LAST);
web_reg_save_param("cp_EMailID","lb=EMailID\":\"","rb=\"","notfound=warning","convert=HTML_TO_URL",LAST);
   web_reg_save_param("cp_OrderType","lb=OrderType\":\"","rb=\"","notfound=warning",LAST);
   web_reg_save_param("cp_Status","lb=Status\":\"","rb=\"","notfound=warning",LAST);
   web_reg_save_param("cp_CustomerLastName","lb=CustomerLastName\":\"","rb=\"","notfound=warning",LAST);
   web_reg_save_param("cp_OrderLineKey_1","lb=OrderLineKey\":\"","rb=\"","notfound=warning",LAST);
   web_reg_save_param("cp_TotalAmount","lb=TotalAmount\":\"","rb=\"}","notfound=warning",LAST);
    web_reg_save_param("cp_Zipcode","lb=\"ZipCode\":\"","rb=\"","notfound=warning",LAST);
    web_reg_save_param("cp_City","lb=\"City\":\"","rb=\"","notfound=warning",LAST);

	web_reg_save_param("cp_OrderNo","lb=OrderNo\":\"","rb=\",","notfound=warning",LAST);
	web_reg_save_param("cp_orderheaderkey","lb=OrderHeaderKey\":\"","rb=\",","notfound=warning",LAST);
	web_reg_save_param("cp_Email","lb=EMailID\":\"","rb=\",","notfound=warning",LAST);
	web_reg_save_param("cp_Orderlinekey","lb=OrderLineKey\":\"","rb=\"}","notfound=warning",LAST);
	
	web_reg_save_param("cp_EveningPhone","lb=EveningPhone\":\"","rb=\"","notfound=warning",LAST);
	web_reg_save_param("cp_AddressLine1","lb=AddressLine1\":\"","rb=\",","notfound=warning",LAST);
	web_reg_save_param("cp_Firstname","lb=\"FirstName\":\"","rb=\",","notfound=warning",LAST);
	web_reg_save_param("cp_PersonInfoKey","lb=PersonInfoKey\":\"","rb=\",","notfound=warning",LAST);
	web_reg_save_param("cp_AddressID","lb=AddressID\":\"","rb=\",","notfound=warning",LAST);
	 web_reg_save_param("cp_PersonInfoKey_1","lb=PersonInfoKey\":\"","rb=\"","notfound=warning",LAST);
	web_reg_save_param("cp_DayPhone","lb=DayPhone\":\"","rb=\"","notfound=warning",LAST);
  
   web_reg_save_param("cp_Orderlinekey_3","lb=OrderLineKey\":\"","rb=\"","notfound=warning",LAST);
    web_reg_save_param("cp_Orderlinekey_2","lb=OrderLineKey\":\"","rb=\"","notfound=warning",LAST);
	
	
	
	web_submit_data("isccs.coupon.search.CouponListScreenBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.coupon.search.CouponListScreenBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_coupon_search_CouponListScreenBehaviorController\":{\"controllerId\":\"isccs_coupon_search_CouponListScreenBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrderListForCouponSearch\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":\"10\",\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"Order\":{\"EnterpriseCode\":\"USWS\",\"FromOrderDate\":\"2022-06-06T00:00:00+05:30\",\"ToOrderDate\":\"2022-12-09T00:00:00+05:30\",\"OrderLine\":{\"Promotion\":{\"Extn\":{\"ExtnAwardId\":\"{p_CouponCode}\",\"ExtnAwardIdQryType\":\"EQ\"}}}}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);
		
	
		
		
	
	lr_end_transaction("C87_CoupanCodeSearch",LR_AUTO);
	
	//lr_think_time(10);
	
	web_reg_find("Search=Body",
		"Text=OrderNo",
		"savecount=Order",
		LAST);
   
    
lr_start_transaction("C87-1_CoupanOrderSelection");


		
		web_custom_request("wizardController.do_2", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.order.wizards.orderSummary.OrderSummaryWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.order.wizards.orderSummary.OrderSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22{cp_orderheaderkey}%22%2C%22PersonInfoBillTo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22EveningPhone%22%3A%22{cp_EveningPhone}%22%2C%22AddressLine1%22%3A%22{cp_AddressLine1}%22%2C%22AddressLine2%22%3A%22%22%2C%22City%22%3A%22{cp_City}%22%2C%22MobilePhone%22%3A%22%22%2C%22ZipCode%22%3A%22{cp_Zipcode}%22%2C%22Suffix%22%3A%22%22%2C%22State%22%3A%22NY%"
		"22%2C%22DayPhone%22%3A%22{cp_DayPhone}%22%2C%22Country%22%3A%22US%22%2C%22EMailID%22%3A%22{cp_EMailID}%22%2C%22FirstName%22%3A%22{cp_Firstname}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey}%22%2C%22Company%22%3A%22%22%7D%2C%22OrderType%22%3A%22{cp_OrderType}%22%2C%22isHistory%22%3A%22N%22%2C%22Extn%22%3A%7B%22ExtnUSERTYPE%22%3A%22G%22%2C%22ExtnCustomerType%22%3A%22GS%22%2C%22ExtnWebProfileId%22%3A%2261329066%22%7D%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22OrderNo%22%3A%22{cp_OrderNo}%22%2C%22Customer"
		"ZipCode%22%3A%22{cp_Zipcode}%22%2C%22Status%22%3A%22{cp_Status_1}%22%2C%22DocumentType%22%3A%22{cp_DocumentType}%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22SellerOrganizationName%22%3A%22{cp_EnterpriseName}%22%2C%22CustomerLastName%22%3A%22{cp_CustomerLastName}%22%2C%22AuthorizedClient%22%3A%22WCS%22%2C%22HoldFlag%22%3A%22N%22%2C%22OrderHoldTypes%22%3A%7B%22OrderHoldType%22%3A%5B%7B%22ReasonText%22%3A%22Remorse%20Expires%3A%2006%2F26%2F2018%2013%3A05%3A01%22%2C%22Status%22%3A%22{cp_Status}%22"
		"%2C%22OrderHeaderKey%22%3A%22{cp_orderheaderkey}%22%2C%22HoldType%22%3A%22{cp_HoldType}%22%2C%22StatusDescription%22%3A%22{cp_StatusDescription}%22%7D%5D%7D%2C%22EnterpriseName%22%3A%22{cp_EnterpriseName}%22%2C%22EntryType%22%3A%22{cp_EntryType}%22%2C%22MaxOrderStatusDesc%22%3A%22Sent%20To%20Node%22%2C%22CustomerPhoneNo%22%3A%22{cp_DayPhone}%22%2C%22OrderLines%22%3A%7B%22OrderLine%22%3A%5B%7B%22Promotions%22%3A%7B%22Promotion%22%3A%5B%7B%22PromotionKey%22%3A%22{cp_PromotionKey}%22%2C%22Extn%22%3A%7B%22ExtnAwardI"
		"d%22%3A%22{p_CouponCode}%22%7D%2C%22PromotionId%22%3A%22{cp_PromotionId}%22%7D%5D%7D%2C%22OrderLineKey%22%3A%22{cp_Orderlinekey_3}%22%7D%2C%7B%22Promotions%22%3A%7B%7D%2C%22OrderLineKey%22%3A%22{cp_Orderlinekey_3}%22%7D%2C%7B%22Promotions%22%3A%7B%7D%2C%22OrderLineKey%22%3A%22{cp_Orderlinekey_3}%22%7D%2C%7B%22Promotions%22%3A%7B%7D%2C%22OrderLineKey%22%3A%22{cp_Orderlinekey_3}%22%7D%2C%7B%22Promotions%22%3A%7B%7D%2C%22OrderLineKey%22%3A%22{cp_Orderlinekey_3}%22%7D%2C%7B%22Promotions%22%"
		"3A%7B%7D%2C%22OrderLineKey%22%3A%22{cp_Orderlinekey_3}%22%7D%2C%7B%22Promotions%22%3A%7B%7D%2C%22OrderLineKey%22%3A%22{cp_Orderlinekey_3}%22%7D%2C%7B%22Promotions%22%3A%7B%7D%2C%22OrderLineKey%22%3A%22{cp_Orderlinekey}%22%7D%2C%7B%22Promotions%22%3A%7B%7D%2C%22OrderLineKey%22%3A%22{cp_Orderlinekey_3}%22%7D%2C%7B%22Promotions%22%3A%7B%7D%2C%22OrderLineKey%22%3A%22{cp_Orderlinekey_3}%22%7D%2C%7B%22Promotions%22%3A%7B%7D%2C%22OrderLineKey%22%3A%22{cp_Orderlinekey_3}%22"
		"%7D%2C%7B%22Promotions%22%3A%7B%7D%2C%22OrderLineKey%22%3A%22{cp_Orderlinekey_3}%22%7D%2C%7B%22Promotions%22%3A%7B%7D%2C%22OrderLineKey%22%3A%22{cp_Orderlinekey_2}%22%7D%2C%7B%22Promotions%22%3A%7B%7D%2C%22OrderLineKey%22%3A%22{cp_OrderLineKey_1}%22%7D%5D%7D%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22{cp_TotalAmount}%22%7D%2C%22CustomerEMailID%22%3A%22{cp_EMailID}%22%2C%22PersonInfoShipTo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22EveningPhone%22%3A%22{cp_EveningPhone}"
		"%22%2C%22AddressLine1%22%3A%22{cp_AddressLine1}%22%2C%22AddressLine2%22%3A%22%22%2C%22City%22%3A%22{cp_City}%22%2C%22MobilePhone%22%3A%22%22%2C%22ZipCode%22%3A%22{cp_Zipcode}%22%2C%22AddressID%22%3A%22{cp_AddressID}%22%2C%22Suffix%22%3A%22%22%2C%22State%22%3A%22NY%22%2C%22DayPhone%22%3A%22{cp_DayPhone}%22%2C%22Country%22%3A%22US%22%2C%22EMailID%22%3A%22{cp_EMailID}%22%2C%22FirstName%22%3A%22{cp_Firstname}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey_1}%22%2C%22Company%22%3A%22%22%7D%2C%22Order"
		"Date%22%3A%22{cp_OrderDate}%22%2C%22CustomerFirstName%22%3A%22{cp_Firstname}%22%2C%22OverallStatus%22%3A%22%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	web_submit_data("isccs.editors.OrderEditorBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getRequiredEditorAttributes\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_orderheaderkey}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_custom_request("AddressDisplay.html", 
		"URL=https://{p_SterlingHostName}/isccs/isccs/common/address/display/templates/AddressDisplay.html?scFlag=Y", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded", 
		LAST);
//
//	web_custom_request("AddressDisplay.html_2", 
//		"URL=https://{p_SterlingHostName}/isccs/isccs/common/address/display/identifiers/US/AddressDisplay.html?scFlag=Y", 
//		"Method=GET", 
//		"TargetFrame=", 
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
//		"Snapshot=t11.inf", 
//		"Mode=HTML", 
//		"EncType=application/x-www-form-urlencoded", 
//		LAST);


	web_submit_data("isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCompleteOrderLineList\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":10,\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"OrderLine\":{\"OrderHeaderKey\":\"{cp_orderheaderkey}\",\"Order\":{\"EnterpriseCode\":\"USWS\",\"SellerOrganizationCode\":\"USWS\"}}}}"
		"]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryLinesBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCompleteShipmentDetails\",\"Input\":{\"Order\":{\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\",\"OrderHeaderKey\":\"{cp_orderheaderkey}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t14.inf", 
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
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_pricingSummary\",\"Input\":{\"Order\":{\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\",\"OrderHeaderKey\":\"{cp_orderheaderkey}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.editors.OrderEditorRTBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorRTBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorRTBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorRTBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_customerDetails\",\"Input\":{\"Customer\":{\"CustomerKey\":\"{cp_Email}\",\"OrganizationCode\":\"USWS\",\"CustomerID\":\"WCS\",\"CustomerType\":\"02\",\"IgnoreOrdering\":\"Y\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	//web_add_header("X-Requested-With","XMLHttpRequest");

	web_submit_data("isccs.editors.OrderEditorRTBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorRTBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorRTBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorRTBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getOrderDetailsForCustomer\",\"Input\":{\"Order\":{\"OrderNo\":\"{cp_OrderNo}\",\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);
	
	lr_end_transaction("C87-1_CoupanOrderSelection",LR_AUTO);
	
	lr_think_time(10);
	

	}
		
		else
			
		{
			
			lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_PASS);

		}
	
	
	
	return 0;
}
