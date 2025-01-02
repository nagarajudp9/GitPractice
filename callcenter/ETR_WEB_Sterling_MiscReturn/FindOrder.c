FindOrder()
{
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
	
	//web_reg_save_param("cp_MaximumRecords","LB=\"MaximumRecords\":\"","RB=\"","Notfound=warning",LAST);
	
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
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_home_portlets_OrderPortletBehaviorController\":{\"controllerId\":\"isccs_home_portlets_OrderPortletBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrderList\",\"Input\":{\"Order\":{\"EnterpriseCode\":\"USWS\",\"OrderNo\":\"{p_Horder}\",\"MaximumRecords\":\"2\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_convert_param("cp_CustomerEMailID1",
	                  "SourceString={cp_CustomerEMailID}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	
	web_convert_param("cp_City1",
	                  "SourceString={cp_City}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	
		web_convert_param("cp_OrderDate1",
	                  "SourceString={cp_OrderDate}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	/*
	web_reg_save_param("cp_GrandTax1","LB=\"GrandTax\":\"","RB=\"","Notfound=warning",LAST);
	
	web_custom_request("wizardController.do", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.order.wizards.orderSummary.OrderSummaryWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.order.wizards.orderSummary.OrderSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EntryType%22%3A%22Web%22%2C%22CustomerFirstName%22%3A%22{cp_FirstName}%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22MultipleStatusesExist%22%3A%22N%22%2C%22AuthorizedClient%22%3A%22WCS%22%2C%22Extn%22%3A%7B%22ExtnWebProfileId%22%3A%22110283043%22%2C%22ExtnUSERTYPE%22%3A%22G%22%7D%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%2C%22Ta"
		"xExemptionCertificate%22%3A%22%22%2C%22PriceInfo%22%3A%7B%22TotalAmount%22%3A%22{cp_TotalAmount}%22%2C%22Currency%22%3A%22USD%22%7D%2C%22OrderNo%22%3A%22{p_Horder}%22%2C%22CustomerPhoneNo%22%3A%22{cp_CustomerPhone}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22CustomerEMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoBillTo%22%3A%7B%22EMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey1}%22%2C%22Suffix%22%3A%22%22%2C%22Country%22%3A%"
		"22US%22%2C%22DayPhone%22%3A%22{cp_CustomerPhone}%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22{cp_City1}%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22NA%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%"
		"22%3A%22%22%7D%2C%22DocumentType%22%3A%220001%22%2C%22MaxOrderStatusDesc%22%3A%22Shipment%20Line%20Invoiced%22%2C%22MinOrderStatus%22%3A%223700.100%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey1}%22%2C%22CustomerPONo%22%3A%22%22%2C%22OrderDate%22%3A%222020-12-03T06%3A55%3A54%2B00%3A00%22%2C%22DisplayStatus%22%3A%22Shipment%20Line%20Invoiced%22%2C%22OverallStatus%22%3A%22%22%2C%22MaxOrderStatus%22%3A%223700.100%22%2C%22SellerOrganizationName%22%3A%22HP%20US%2"
		"0Web%20Store%22%2C%22PersonInfoShipTo%22%3A%7B%22EMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoKey%22%3A%22{cp_ShipToKey1}%22%2C%22Suffix%22%3A%22%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%22{cp_CustomerPhone}%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22{cp_City1}%22%2C%22AddressID%22%3A%22{cp_AddressID}%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22Pers"
		"onID%22%3A%22%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22Status%22%3A%22Shipment%20Line%20Invoiced%22%2C%22CustomerLastName%22%3A%22{cp_LastName}%22%2C%22HoldFlag%22%3A%22N%22%2C%22CustomerZipCode%22%3A%22{cp_ZipCode}%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22OrderLines%22%3A%7B%2"
		"2OrderLine%22%3A%5B%7B%22IntentionalBackorder%22%3A%22N%22%2C%22InvoicedQuantity%22%3A%221.00%22%2C%22ItemGroupCode%22%3A%22PROD%22%2C%22OptionCapacityRequired%22%3A%220.00%22%2C%22Extn%22%3A%7B%22ExtnGCNumber%22%3A%22%22%7D%2C%22SegmentType%22%3A%22%22%2C%22Timezone%22%3A%22%22%2C%22ImportLicenseNo%22%3A%22%22%2C%22ReturnReason%22%3A%22%22%2C%22ReservationID%22%3A%22%22%2C%22PipelineKey%22%3A%2220131111160246124658%22%2C%22TranDiscrepancyQty%22%3A%220.00%22%2C%22TotalQtyToCancel%22%3A%220.00%22%2"
		"C%22CannotMeetAppt%22%3A%22%22%2C%22Purpose%22%3A%22%22%2C%22DependencyRatio%22%3A%220.00%22%2C%22DeliveryMethod%22%3A%22SHP%22%2C%22Lockid%22%3A%223%22%2C%22ReservationPool%22%3A%22%22%2C%22PersonalizeCode%22%3A%22%22%2C%22Segment%22%3A%22%22%2C%22OrderLineKey%22%3A%22{cp_OrderLineKey1}%22%2C%22IsFirmPredefinedNode%22%3A%22Y%22%2C%22KitCode%22%3A%22%22%2C%22Createprogid%22%3A%22HPSCWCIntegrationServer%22%2C%22PrimeLineNo%22%3A%221%22%2C%22InvoiceBasedOnActuals%22%3A%22N%22%2C%22CustomerLine"
		"PONo%22%3A%22%22%2C%22LineType%22%3A%22%22%2C%22HoldFlag%22%3A%22N%22%2C%22BasicCapacityRequired%22%3A%220.00%22%2C%22SplitFromLineKey%22%3A%22%22%2C%22IsCostOverridden%22%3A%22N%22%2C%22PickableFlag%22%3A%22Y%22%2C%22Modifyprogid%22%3A%22CREATE_SHMNT_INVOICE.0001%22%2C%22Modifyuserid%22%3A%22HPAgentServer%22%2C%22ConditionVariable2%22%3A%22%22%2C%22ConditionVariable1%22%3A%22%22%2C%22ShipTogetherNo%22%3A%22%22%2C%22ShippedQuantity%22%3A%221.00%22%2C%22Modifyts%22%3A%22{cp_OrderDate1}"
		"%3A00%22%2C%22OrderedQty%22%3A%221.00%22%2C%22QuantityToSplit%22%3A%220.00%22%2C%22PackListType%22%3A%22%22%2C%22ReceivedAsComponents%22%3A%22%22%2C%22DepartmentCode%22%3A%22%22%2C%22HoldReasonCode%22%3A%22%22%2C%22SCAC%22%3A%22%22%2C%22Createuserid%22%3A%22HPSCWCIntegrationServer%22%2C%22CustomerPONo%22%3A%22%22%2C%22TransactionalLineId%22%3A%22%22%2C%22EarliestShipDate%22%3A%222020-12-03T07%3A00%3A19%2B00%3A00%22%2C%22IsPriceMatched%22%3A%22N%22%2C%22BackorderNotificationQty%22%3A%220.00%22%2C%2"
		"2InvoiceComplete%22%3A%22Y%22%2C%22PropagationToParentRequired%22%3A%22%22%2C%22SubLineNo%22%3A%221%22%2C%22GiftFlag%22%3A%22N%22%2C%22ReceivedQty%22%3A%220.00%22%2C%22ApptStatus%22%3A%22%22%2C%22CapacityUOM%22%3A%22%22%2C%22FixedPricingQtyPerLine%22%3A%220.00%22%2C%22SplitFromPrimeLineNo%22%3A%220%22%2C%22IsCapacityOverridden%22%3A%22N%22%2C%22FixedCapacityQtyPerLine%22%3A%220.00%22%2C%22EarliestDeliveryDate%22%3A%222020-12-03T07%3A00%3A19%2B00%3A00%22%2C%22PricingDate%22%3A%222020-12-03%22%2C%22"
		"FreightTerms%22%3A%22%22%2C%22CarrierAccountNo%22%3A%22%22%2C%22MaintainRatio%22%3A%22%22%2C%22SplitQty%22%3A%220.00%22%2C%22Createts%22%3A%222020-12-03T07%3A00%3A19%2B00%3A00%22%2C%22FillQuantity%22%3A%220.00%22%2C%22OrderClass%22%3A%22NEW%22%2C%22OverReceiptQuantity%22%3A%220.00%22%2C%22ShipNode%22%3A%22USDC01%22%2C%22CarrierServiceCode%22%3A%22%22%2C%22OtherCharges%22%3A%220.00%22%2C%22SchedFailureReasonCode%22%3A%22%22%2C%22WaitForSeqLine%22%3A%22N%22%2C%22SerialNo%22%3A%22%22%2C%22CanAddServi"
		"ceLines%22%3A%22N%22%2C%22PropagationQty%22%3A%220.00%22%2C%22LineSeqNo%22%3A%221.1%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey1}%22%2C%22OrderingUOM%22%3A%22EACH%22%2C%22OriginalOrderedQty%22%3A%221.00%22%2C%22IsStandaloneService%22%3A%22%22%2C%22SplitFromSubLineNo%22%3A%220%22%2C%22AddToOrderReleaseKey%22%3A%22%22%2C%22DeliveryCode%22%3A%22%22%2C%22ReservationMandatory%22%3A%22N%22%2C%22PersonalizeFlag%22%3A%22%22%2C%22InvoicedExtendedPrice%22%3A%22{cp_UnitPrice1}%22%2C%22isHistory%22%3A%22N%2"
		"2%2C%22FulfillmentType%22%3A%22%22%2C%22ParentOfDependentGroup%22%3A%22N%22%7D%5D%7D%2C%22isHistory%22%3A%22N%22%2C%22OrderName%22%3A%22%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	
web_custom_request("AddressDisplay.html",
		"URL=https://{p_SterlingHostName}/isccs/isccs/common/address/display/templates/AddressDisplay.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);
*/
	web_submit_data("isccs.editors.OrderEditorBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getEnterpriseList\",\"Input\":{\"Organization\":{}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_revert_auto_header("SCIAjax");

	web_revert_auto_header("SCIVer");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("isccs.editors.OrderEditorBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getRequiredEditorAttributes\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("SCIAjax", 
		"Y");

	web_add_auto_header("SCIVer", 
		"0.9");

	web_submit_data("isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t22.inf", 
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
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCommonCodeList\",\"Input\":{\"CommonCodeList\":{\"CodeType\":\"CarrierServiceCode\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);
	
web_reg_save_param("cp_OrderHeaderKey1","LB=\"OrderHeaderKey\":\"","RB=\",","Notfound=warning",LAST);
web_reg_save_param("cp_UnitPrice1","LB=\"UnitPrice\":\"","RB=\"","Notfound=warning",LAST);
	
	web_submit_data("isccs.editors.OrderEditorRTBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorRTBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorRTBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorRTBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getOrderDetailsForCustomer\",\"Input\":{\"Order\":{\"OrderNo\":\"{p_Horder}\",\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

web_reg_save_param("cp_ShipToKey1","LB=\"ShipToKey\":\"","RB=\"","Notfound=warning",LAST);
web_reg_save_param("cp_PersonInfoKey1","LB=\"PersonInfoKey\":\"","RB=\"","Notfound=warning",LAST);

web_reg_save_param("cp_ItemDesc","LB=\"ItemDesc\":\"","RB=\"","Notfound=warning",LAST);
web_reg_save_param("cp_ItemID","LB=\"ItemID\":\"","RB=\"","Notfound=warning",LAST);

web_reg_save_param("cp_OrderLineKey1","LB=\"OrderLineKey\":\"","RB=\"","Notfound=warning",LAST);

	web_submit_data("isccs.order.details.OrderSummaryBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_pricingSummary\",\"Input\":{\"Order\":{\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey1}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_revert_auto_header("SCIAjax");
web_convert_param("cp_ItemDesc1",
	                  "SourceString={cp_ItemDesc}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	  web_convert_param("cp_ItemID1",
	                  "SourceString={cp_ItemID}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	
	web_revert_auto_header("SCIVer");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("isccs.editors.OrderEditorRTBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorRTBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorRTBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorRTBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_customerDetails\",\"Input\":{\"Customer\":{\"CustomerKey\":\"{cp_EMailID}\",\"OrganizationCode\":\"USWS\",\"CustomerID\":\"WCS\",\"CustomerType\":\"02\",\"IgnoreOrdering\":\"Y\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C50_FindOrder",LR_AUTO);
	
		lr_think_time(10);

	return 0;
}
