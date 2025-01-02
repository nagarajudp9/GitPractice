CTO()
{
	
	lr_start_transaction("C52-1_CTO_OrderLine");
	
	web_submit_data("isccs.editors.OrderEditorBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getRequiredEditorAttributes\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_custom_request("wizardController.do_2", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.order.wizards.orderLineSummary.OrderLineSummaryWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.order.wizards.orderLineSummary.OrderLineSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22DocumentType%22%3A%220001%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22OrderNo%22%3A%22{cp_OrderNo}%22%2C%22EntryType%22%3A%22Web%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22OrderLineKey%22%3A%22{cp_OrderLineKey}%22%2C%22CustomerFirstName%22%3A%22{cp_CustomerFirstName}%22%2C%22CustomerL"
		"astName%22%3A%22{cp_CustomerLastName}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22isHistory%22%3A%22N%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%7D%2C%22TaxExemptFlag%22%3A%22N%22%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	web_submit_data("isccs.order.details.OrderLineSummaryBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderLineSummaryBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderLineSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderLineSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCommonCodeListAPI\",\"Input\":{\"CommonCodeList\":{\"CodeType\":\"CarrierServiceCode\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.details.OrderLineSummaryBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderLineSummaryBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderLineSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderLineSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCompleteOrderDetails\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);
		
		
	lr_end_transaction("C52-1_CTO_OrderLine",LR_AUTO);

	lr_start_transaction("C52-2_CTO_Components");

	web_submit_data("isccs.order.details.OrderLineSummaryLinesBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderLineSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderLineSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderLineSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCompleteOrderLineList\",\"Input\":{\"OrderLine\":{\"BundleParentOrderLineKey\":\"{cp_OrderLineKey}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C52-2_CTO_Components",LR_AUTO);

	lr_start_transaction("C52-3_CTO_LinesNotes");

	web_submit_data("isccs.common.notes.NoteDisplayBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.common.notes.NoteDisplayBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_common_notes_NoteDisplayBehaviorController\":{\"controllerId\":\"isccs_common_notes_NoteDisplayBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getNoteList\",\"Input\":{\"Note\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"OrderLineKey\":\"{cp_OrderLineKey}\",\"OrderLineNote\":\"Y\",\"Exclude\":[\"SystemNote\"]}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C52-3_CTO_LinesNotes",LR_AUTO);

	lr_start_transaction("C52-4_CTO_Fulfillment");
	
	web_submit_data("isccs.shipment.shipmentTracking.LineTrackingBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.shipment.shipmentTracking.LineTrackingBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_shipment_shipmentTracking_LineTrackingBehaviorController\":{\"controllerId\":\"isccs_shipment_shipmentTracking_LineTrackingBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCompleteOrderLineDetails\",\"Input\":{\"OrderLineDetail\":{\"OrderLineKey\":\"{cp_OrderLineKey}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);


	lr_end_transaction("C52-4_CTO_Fulfillment",LR_AUTO);
	
	lr_think_time(10);
	
	
	return 0;
}
