Misc()
{
	if(strcmp(lr_eval_string("{cp_Status}"),"Shipment Line Invoiced")==0 || strcmp(lr_eval_string("{cp_Status}"),"Partially Shipment Line Invoiced")==0)
	
	{
	
	lr_start_transaction("C51-1_MC_ManageCharges");

	web_add_auto_header("SCIAjax", 
		"Y");

	web_add_auto_header("SCIVer", 
		"0.9");

	web_custom_request("wizardController.do_2", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=extn.wizards.addModifyCharges.HPAddModifyChargesWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22extn.wizards.addModifyCharges.HPAddModifyChargesWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EntryType%22%3A%22Web%22%2C%22CustomerFirstName%22%3A%22{cp_FirstName}%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22AuthorizedClient%22%3A%22WCS%22%2C%22Extn%22%3A%7B%22ExtnWebProfileId%22%3A%22110283043%22%2C%22ExtnUSERTYPE%22%3A%22G%22%7D%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%2C%22TaxExemptionCertificate%22%3A%22%22%2C%"
		"22PriceInfo%22%3A%7B%22TotalAmount%22%3A%22{cp_TotalAmount}%22%2C%22Currency%22%3A%22USD%22%7D%2C%22OrderNo%22%3A%22{p_Horder}%22%2C%22CustomerPhoneNo%22%3A%22{cp_CustomerPhone}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22CustomerEMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoBillTo%22%3A%7B%22EMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey1}%22%2C%22Suffix%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%22Country%22%3A%22US%2"
		"2%2C%22DayPhone%22%3A%22{cp_CustomerPhone}%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22{cp_City1}%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22NA%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%"
		"22%22%7D%2C%22DocumentType%22%3A%220001%22%2C%22MaxOrderStatusDesc%22%3A%22Shipment%20Line%20Invoiced%22%2C%22MinOrderStatus%22%3A%223700.100%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey1}%22%2C%22CustomerPONo%22%3A%22%22%2C%22DisplayStatus%22%3A%22Draft%20Order%20Created%22%2C%22DisplayEntryType%22%3A%22Web%22%2C%22MaxOrderStatus%22%3A%223700.100%22%2C%22SellerOrganizationName%22%3A%22HP%20US%20Web%20Store%22%2C%22PersonInfoShipTo%22%3A%7B%22EMailID%22%3A%"
		"22{cp_CustomerEMailID1}%22%2C%22PersonInfoKey%22%3A%22{cp_ShipToKey1}%22%2C%22Suffix%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%22{cp_CustomerPhone}%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22{cp_City1}%22%2C%22AddressID%22%3A%22{cp_AddressID}%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%"
		"22%3A%22{cp_FirstName}%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22CustomerLastName%22%3A%22{cp_LastName}%22%2C%22CustomerZipCode%22%3A%22{cp_ZipCode}%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22isHistory%22%3A%22N%22%2C%22OrderName%22%3A%22%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);
/*
	web_custom_request("OrderTotal_NoOrderPricingSummaryLink.html", 
		"URL=https://{p_SterlingHostName}/isccs/isccs/order/details/templates/OrderTotal_NoOrderPricingSummaryLink.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);
*/
	web_submit_data("isccs.editors.OrderEditorBehaviorController.do_3", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getRequiredEditorAttributes\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey1}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_revert_auto_header("SCIAjax");

	web_revert_auto_header("SCIVer");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("isccs.order.details.OrderPricingSummaryLinesBehaviorController.do", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderPricingSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_order_details_OrderPricingSummaryLinesBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_order_details_OrderPricingSummaryLinesBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22getCompleteOrderLineList%22%2C%22scPaginationStrategy%22%3A%22NEXTPAGE%22%2C%22scPageSize%22%3A10%2C%22scPageNumber%22%3A1%2C%22scPreviousPageRecord%22%3A%7B%7D%2C%22Input%22%3A%7B%22OrderLine%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%7D%2C%22Orde"
		"rHeaderKey%22%3A%22{cp_OrderHeaderKey1}%22%7D%7D%7D%5D%7D%7D%7D&scControllerInput="
		"%7B%22Order%22%3A%7B%22EntryType%22%3A%22Web%22%2C%22CustomerFirstName%22%3A%22{cp_FirstName}%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22AuthorizedClient%22%3A%22WCS%22%2C%22Extn%22%3A%7B%22ExtnWebProfileId%22%3A%22110283043%22%2C%22ExtnUSERTYPE%22%3A%22G%22%7D%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%2C%22TaxExemptionCertificate%22%3A%22%22%2C%22PriceInfo%22%3A%7B%22TotalAmount%22%3A%22{cp_TotalAmount}%22%2C%22Currency%22%3A%22USD%22%7D%2C%22OrderNo%22%3A%22{p_Horder}%22%2C%22CustomerPhon"
		"eNo%22%3A%22{cp_CustomerPhone}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22CustomerEMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoBillTo%22%3A%7B%22EMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey1}%22%2C%22Suffix%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%22{cp_CustomerPhone}%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22"
		"%3A%22{cp_City1}%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22NA%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22DocumentType%22%3A%220001%22%2C%22MaxOrderStatusDesc%22%3A%22Shipment%20Line%20Invoiced%22%2C%22MinOrderStatus%22%3A%223700."
		"100%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey1}%22%2C%22CustomerPONo%22%3A%22%22%2C%22DisplayStatus%22%3A%22Draft%20Order%20Created%22%2C%22DisplayEntryType%22%3A%22Web%22%2C%22MaxOrderStatus%22%3A%223700.100%22%2C%22SellerOrganizationName%22%3A%22HP%20US%20Web%20Store%22%2C%22PersonInfoShipTo%22%3A%7B%22EMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoKey%22%3A%22{cp_ShipToKey1}%22%2C%22Suffix%22%3A%22%22%2C%22Countr"
		"yDesc%22%3A%22US%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%22{cp_CustomerPhone}%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22{cp_City1}%22%2C%22AddressID%22%3A%22{cp_AddressID}%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%2"
		"2Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22CustomerLastName%22%3A%22{cp_LastName}%22%2C%22CustomerZipCode%22%3A%22{cp_ZipCode}%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22isHistory%22%3A%22N%22%2C%22OrderName%22%3A%22%22%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("SCIAjax", 
		"Y");

	web_add_auto_header("SCIVer", 
		"0.9");

	web_submit_data("isccs.order.details.OrderPricingSummaryBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderPricingSummaryBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderPricingSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderPricingSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_customerDetails\",\"Input\":{\"Customer\":{\"CustomerID\":\"WCS\",\"CustomerType\":\"02\",\"IgnoreOrdering\":\"Y\",\"CustomerKey\":\"{cp_EMailID}\",\"OrganizationCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");
/*
	web_custom_request("OrderPricingSummaryAdjustments_LineTax.html", 
		"URL=https://{p_SterlingHostName}/isccs/isccs/order/details/templates/OrderPricingSummaryAdjustments_LineTax.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		LAST);
*/
	lr_end_transaction("C51-1_MC_ManageCharges",LR_AUTO);
	
		lr_think_time(10);

	lr_start_transaction("C51-2_MC_AddModify");

	web_custom_request("isccs.order.addModifyCharges.AddModifyChargesPopupInitController.do", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupInitController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		"Body=scControllerInput=%7B%22LineMode%22%3A%22Y%22%2C%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey1}%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22OrderLines%22%3A%7B%22OrderLine%22%3A%7B%22OrderLineKey%22%3A%22{cp_OrderLineKey1}%22%2C%22ItemDetails%22%3A%7B%22PrimaryInformation%22%3A%7B%22ExtendedDisplayDescription%22%3A%22{cp_ItemDesc1}%20({cp_ItemID1})"
		"%22%7D%7D%7D%7D%2C%22DocumentType%22%3A%220001%22%2C%22OrderNo%22%3A%22{p_Horder}%22%2C%22Extn%22%3A%7B%7D%7D%7D&scControllerData="
		"%7B%22isccs_order_addModifyCharges_AddModifyChargesPopupInitController%22%3A%7B%22controllerId%22%3A%22isccs_order_addModifyCharges_AddModifyChargesPopupInitController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%5D%7D%2C%22ChildControllers%22%3A%7B%22ChildController%22%3A%5B%7B%22controllerId%22%3A%22isccs_common_notes_OrderNoteInitController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22getOrderNoteMashup%22%2C%22Input%22%3A%7B%7D%2C%22mashupRefObj%22%3A%7B%22sour"
		"ceNamespace%22%3A%22getContactTypeList_output%22%2C%22callSequence%22%3A%22%22%2C%22mashupRefId%22%3A%22getOrderNoteMashup%22%2C%22sequence%22%3A%225%22%2C%22sourceBindingOptions%22%3A%22%22%2C%22mashupId%22%3A%22common_getContactTypeList%22%7D%7D%2C%7B%22mashupRefId%22%3A%22getCustomerSatisfactionList%22%2C%22Input%22%3A%7B%7D%2C%22mashupRefObj%22%3A%7B%22sourceNamespace%22%3A%22getNoteCustomerSatisfactionList_output%22%2C%22callSequence%22%3A%22%22%2C%22mashupRefId%22%3A%22getCustomerSatisfactio"
		"nList%22%2C%22sequence%22%3A%22%22%2C%22sourceBindingOptions%22%3A%22%22%2C%22mashupId%22%3A%22common_getNoteCustomerSatisfactionList%22%7D%7D%5D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);
/*
	web_custom_request("AddModifyChargesPopup_LineMode.html", 
		"URL=https://{p_SterlingHostName}/isccs/isccs/order/addModifyCharges/templates/AddModifyChargesPopup_LineMode.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t35.inf", 
		"Mode=HTML", 
		LAST);

*/	
	web_reg_save_param("cp_GrandTax1","LB=\"Tax\":\"","RB=\"","Notfound=warning",LAST);
	
	web_submit_data("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\":{\"controllerId\":\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCompleteOrderLineDetails\",\"Input\":{\"OrderLineDetail\":{\"OrderLineKey\":\"{cp_OrderLineKey1}\"},\"LineMode\":\"Y\"}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\":{\"controllerId\":\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_addModifyCharges_getUserHierarchy\",\"Input\":{\"User\":{}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_3", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\":{\"controllerId\":\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_addModifyCharges_GetReturnOrderList\",\"Input\":{\"Order\":{\"OrderLine\":{\"DerivedFromOrderHeaderKey\":\"{cp_OrderHeaderKey1}\",\"DerivedFromOrderLineKey\":\"{cp_OrderLineKey1}\"}}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_4", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t39.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\":{\"controllerId\":\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_addModifyCharges_GetReversalLimitMatrix\",\"Input\":{\"CommonCode\":{\"ComplexQuery\":{\"Or\":{\"Exp\":[{\"Name\":\"CodeShortDescription\",\"Value\":\"HP-SUPERUSER-GROUP\"},{\"Name\":\"CodeShortDescription\",\"Value\":\"HP-CSR-MANUALREL-RET-GRP\"}]}}}"
		"}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_5", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\":{\"controllerId\":\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_paymentdetails\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey1}\",\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_custom_request("isccs.order.addModifyCharges.ChargeFieldsInitController.do", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.ChargeFieldsInitController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		"Body=scControllerInput="
		"%7B%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey1}%22%2C%22DocumentType%22%3A%220001%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22Extn%22%3A%7B%22ExtnIsTaxExemptOrder%22%3A%22false%22%7D%2C%22OrderLines%22%3A%7B%22OrderLine%22%3A%7B%22HasRelatedLines%22%3A%22N%22%2C%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey1}%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%7D%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22AuthorizedClient%22%3A%22WCS%22%2C%22DocumentType%22"
		"%3A%220001%22%2C%22Extn%22%3A%7B%22ExtnIsTaxExemptOrder%22%3A%22false%22%7D%7D%2C%22LineCharges%22%3A%7B%7D%2C%22MaxLineStatus%22%3A%223700.100%22%2C%22ItemGroupCode%22%3A%22PROD%22%2C%22OrderDates%22%3A%7B%22OrderDate%22%3A%5B%7B%22DateTypeId%22%3A%22HP_EST_DELIVERY_DATE%22%7D%2C%7B%22ActualDate%22%3A%22{cp_OrderDate1}%22%2C%22DateTypeId%22%3A%22YCD_COMPLETELY_SHIPPED_OR_CANCELLED%22%7D%5D%7D%2C%22OrderedQty%22%3A%221.00%22%2C%22ShipNode%22%3A%22USDC01%22%2C%22CarrierServiceCode"
		"%22%3A%22%22%2C%22OpenQty%22%3A%220.00%22%2C%22OrderLineKey%22%3A%22{cp_OrderLineKey1}%22%2C%22ComputedPrice%22%3A%7B%22LineTotal%22%3A%22{cp_TotalAmount}%22%2C%22ExtendedPrice%22%3A%22{cp_UnitPrice1}%22%2C%22Tax%22%3A%22{cp_GrandTax1}%22%2C%22Discount%22%3A%220.00%22%2C%22UnitPrice%22%3A%22{cp_UnitPrice1}%22%2C%22Charges%22%3A%220.00%22%7D%2C%22DeliveryMethodName%22%3A%22Shipping%22%2C%22KitCode%22%3A%22%22%2C%22PrimeLineNo%22%3A%221%22%2C%22IsBundleComponent%22%3A%22N%22%2C%22MaxLineStatusDesc%22%3A%22Shipment%20Line%20In"
		"voiced%22%2C%22DisplayStatus%22%3A%22Shipment%20Line%20Invoiced%22%2C%22IsPriceMatched%22%3A%22N%22%2C%22LinePriceInfo%22%3A%7B%22ListPrice%22%3A%22{cp_UnitPrice1}%22%2C%22InvoicedLineTotal%22%3A%22{cp_TotalAmount}%22%2C%22RepricingQty%22%3A%221.00%22%2C%22TaxableFlag%22%3A%22N%22%2C%22UnitPrice%22%3A%22{cp_UnitPrice1}%22%2C%22IsLinePriceForInformationOnly%22%3A%22N%22%2C%22InvoicedPricingQty%22%3A%221.00%22%2C%22PricingQtyConversionFactor%22%3A%220.00%22%2C%22PricingUOM%22%3A%22EACH%22%2C%22SettledQuantity%22%3A%220.00%2"
		"2%2C%22LineTotal%22%3A%22{cp_TotalAmount}%22%2C%22SettledAmount%22%3A%220.00%22%2C%22BundleTotal%22%3A%220.00%22%2C%22OrderedPricingQty%22%3A%221.00%22%2C%22ActualPricingQty%22%3A%221.00%22%2C%22RetailPrice%22%3A%22{cp_UnitPrice1}%22%2C%22DiscountPercentage%22%3A%220.00%22%2C%22IsPriceLocked%22%3A%22Y%22%7D%2C%22OverallStatus%22%3A%22%22%2C%22ShipnodeFullDescription%22%3A%22HP%20US%20DC%2CMillington%22%2C%22GiftFlag%22%3A%22N%22%2C%22PersonInfoShipTo%22%3A%7B%22EMailID%22%3A%22perteststore20201203064815.912%40hmai"
		"l.com%22%2C%22PersonInfoKey%22%3A%22{cp_ShipToKey1}%22%2C%22Suffix%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%22{cp_CustomerPhone}%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22{cp_City1}%22%2C%22AddressID%22%3A%22{cp_AddressID}%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22isHistory%22"
		"%3A%22N%22%2C%22EveningPhone%22%3A%22%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22LineTaxes%22%3A%7B%22LineTax%22%3A%5B%7B%22ChargeName%22%3A%22%22%2C%22ChargeCategory%22%3A%22Price%22%2C%22ChargeNameKey%22%3A%22%22%2C%22Tax%22%3A%22{cp_GrandTax1}%22%2C%22InvoicedTax%22%3A%22{cp_GrandTax1}%22%2C%22TaxName%22%3A%22Sales%20Tax%22%7D%5D%7D%2C%22Status%22%3A%22Shipment%20Line%20Invoice"
		"d%22%2C%22MinLineStatus%22%3A%223700.100%22%2C%22ShipnodeDescription%22%3A%22HP%20US%20DC%22%2C%22HoldFlag%22%3A%22N%22%2C%22IsRelatedLine%22%3A%22N%22%2C%22IsOpenBox%22%3A%22N%22%2C%22DeliveryMethod%22%3A%22SHP%22%2C%22IsBundleParent%22%3A%22N%22%7D%7D%7D%7D&scControllerData="
		"%7B%22isccs_order_addModifyCharges_ChargeFieldsInitController%22%3A%7B%22controllerId%22%3A%22isccs_order_addModifyCharges_ChargeFieldsInitController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22getChargeCategoryList%22%2C%22Input%22%3A%7B%7D%7D%2C%7B%22mashupRefId%22%3A%22extn_getChargeCategoryToHide%22%2C%22Input%22%3A%7B%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);
/*
	web_custom_request("ChargeFields_IsNewChargeInLineMode.html", 
		"URL=https://{p_SterlingHostName}/isccs/isccs/order/addModifyCharges/templates/ChargeFields_IsNewChargeInLineMode.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		LAST);
*/
	lr_end_transaction("C51-2_MC_AddModify",LR_AUTO);
	
	
		lr_think_time(10);

	lr_start_transaction("C51-3_MC_AddCharges");

	web_submit_data("isccs.order.addModifyCharges.ChargeFieldsBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.ChargeFieldsBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_addModifyCharges_ChargeFieldsBehaviorController\":{\"controllerId\":\"isccs_order_addModifyCharges_ChargeFieldsBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getChargeNameList\",\"Input\":{\"ChargeName\":{\"ChargeCategory\":\"LineReversal\",\"DocumentType\":\"0001\",\"CallingOrganizationCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C51-3_MC_AddCharges",LR_AUTO);

	
		lr_think_time(10);
		
	lr_start_transaction("C51-4_MC_Apply");

	web_custom_request("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_6", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22lineCharges_changeOrder%22%2C%22Input%22%3A%7B%22Order%22%3A%7B%22Notes%22%3A%5B%7B%22Note%22%3A%7B%22NoteText%22%3A%22test%22%2C%22Priority%22%3A%220%22%2C%22VisibleToAll%22%3A%22Y%22%2C%22ContactType%22%3A%22EMAIL%22%2C%22ContactReference%22%3A%22tes"
		"t%40test.com%22%7D%7D%5D%2C%22HeaderCharges%22%3A%7B%22HeaderCharge%22%3A%7B%22ChargeCategory%22%3A%22LineReversal%22%2C%22ChargeName%22%3A%22Agent-related%20Adjustments%22%2C%22ChargeAmount%22%3A10%2C%22IsNewCharge%22%3A%22Y%22%2C%22ChargeType%22%3A%22CPL%22%7D%2C%22OrderLineKey%22%3A%22{cp_OrderLineKey1}%22%7D%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey1}%22%2C%22BypassPricing%22%3A%22Y%22%2C%22OrderLines%22%3A%7B%22OrderLine%22%3A%7B%22LineCharges%22%3A%5B%5D%2C%22LineTaxes%22%3A%5"
		"B%7B%22LineTax%22%3A%5B%7B%22ChargeName%22%3A%22%22%2C%22ChargeCategory%22%3A%22Price%22%2C%22ChargeNameKey%22%3A%22%22%2C%22Tax%22%3A%22{cp_GrandTax1}%22%2C%22InvoicedTax%22%3A%22{cp_GrandTax1}%22%2C%22TaxName%22%3A%22Sales%20Tax%22%7D%5D%7D%5D%2C%22LinePriceInfo%22%3A%7B%22ListPrice%22%3A%22{cp_UnitPrice1}%22%2C%22InvoicedLineTotal%22%3A%22{cp_TotalAmount}%22%2C%22RepricingQty%22%3A%221.00%22%2C%22TaxableFlag%22%3A%22N%22%2C%22UnitPrice%22%3A%22{cp_UnitPrice1}%22%2C%22IsLinePriceForInformationOnly%22%3A%22N%22%2C%22InvoicedPricingQty%2"
		"2%3A%221.00%22%2C%22PricingQtyConversionFactor%22%3A%220.00%22%2C%22PricingUOM%22%3A%22EACH%22%2C%22SettledQuantity%22%3A%220.00%22%2C%22LineTotal%22%3A%22{cp_TotalAmount}%22%2C%22SettledAmount%22%3A%220.00%22%2C%22BundleTotal%22%3A%220.00%22%2C%22OrderedPricingQty%22%3A%221.00%22%2C%22ActualPricingQty%22%3A%221.00%22%2C%22RetailPrice%22%3A%22{cp_UnitPrice1}%22%2C%22DiscountPercentage%22%3A%220.00%22%2C%22IsPriceLocked%22%3A%22Y%22%7D%2C%22IsBundleParent%22%3A%22N%22%2C%22ComputedPrice%22%3A%7B%22LineTotal%22%3A%2"
		"2{cp_TotalAmount}%22%2C%22ExtendedPrice%22%3A%22{cp_UnitPrice1}%22%2C%22Tax%22%3A%22{cp_GrandTax1}%22%2C%22Discount%22%3A%220.00%22%2C%22UnitPrice%22%3A%22{cp_UnitPrice1}%22%2C%22Charges%22%3A%220.00%22%7D%7D%7D%2C%22ReversalLimitMatrix%22%3A%7B%22bShipReversalPercentage%22%3A100%2C%22bRecycleFeeReversalPercentage%22%3A0%2C%22bLineReversalPercentage%22%3A100%2C%22bLineTaxReversalPercentage%22%3A0%2C%22bShipReversalValue%22%3A99999%2C%22bRecycleFeeReversalValue%22%3A0%2C%22bLineReversalValue%22%3A99999%2C%22bLineTaxReversalValue%2"
		"2%3A0%7D%7D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	web_reg_save_param("cp_InvoiceNo1","LB=\"InvoiceNo\":\"","RB=\"","Notfound=warning",LAST);
	web_reg_save_param("cp_OrderInvoiceKey1","LB=\"OrderInvoiceKey\":\"","RB=\"","Notfound=warning",LAST);
	
	web_custom_request("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_7", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22extn_addModifyCharges_recordInvoiceCreation%22%2C%22Input%22%3A%7B%22PendingInvoiceCreation%22%3A%7B%22LineChargesList%22%3A%7B%22LineCharge%22%3A%5B%7B%22ChargeAmount%22%3A%2210%22%2C%22ChargeName%22%3A%22Agent-related%20Adjustments(Reversal)"
		"%5B1%5D%22%2C%22IsNewCharge%22%3A%22Y%22%2C%22ChargeCategory%22%3A%22LineReversal%22%2C%22IsDiscount%22%3A%22N%22%2C%22ChargePerUnit%22%3A%220%22%2C%22InvoicedChargePerLine%22%3A%2210%22%2C%22ChargePerLine%22%3A%2210%22%2C%22IsManual%22%3A%22Y%22%2C%22InvoicedChargeAmount%22%3A%2210%22%2C%22IsBillable%22%3A%22N%22%7D%5D%7D%2C%22LineTaxesList%22%3A%7B%22LineTax%22%3A%5B%7B%22ChargeCategory%22%3A%22LineTaxReversal%22%2C%22Tax%22%3A%220.70%22%2C%22InvoicedTax%22%3A%220.70%22%2C%22TaxName%22%3A%22Line"
		"TaxReversal(Reversal)%5B1%5D%22%7D%5D%7D%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey1}%22%2C%22OrderLineKey%22%3A%22{cp_OrderLineKey1}%22%2C%22OrderedQty%22%3A%221.00%22%7D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	web_submit_data("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_8", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t46.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\":{\"controllerId\":\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_addModifyCharges_ChangeOrderInvoice\",\"Input\":{\"OrderInvoice\":{\"InvoiceNo\":\"{cp_InvoiceNo1}\",\"OrderInvoiceKey\":\"{cp_OrderInvoiceKey1}\",\"Extn\":{\"ExtnMOrderNo\":\"{cp_InvoiceNo1}\",\"IsNewCAASMisc\":\"FALSE\"}}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_revert_auto_header("SCIAjax");

	web_revert_auto_header("SCIVer");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	
	web_custom_request("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_9", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t47.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22saveOrderNote%22%2C%22Input%22%3A%7B%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey1}%22%2C%22Notes%22%3A%7B%22Note%22%3A%7B%22NoteText%22%3A%22%3Cdiv%3E%3Cb%3E%20Reason%20%3A%20%3C%2Fb%3ELineReversal%20-%20Agent-related%20Adjustments"
		"(Reversal)"
		"%5B1%5D%3Cbr%2F%3E%3Cb%3E%20%24%20Value%20%3A%20%3C%2Fb%3E10.00%3Cbr%2F%3E%3Cb%3E%20%24%20Tax%20value%20%3A%20%3C%2Fb%3E0.70%3Cbr%2F%3E%3Cb%3E%20%24%20Total%20%3A%20%3C%2Fb%3E10.70%3Cbr%2F%3E%3Cb%3E%20Date%20%3A%20%3C%2Fb%3E{p_CurrentDate}%3Cbr%2F%3E%3Cb%3E%20User%20ID%3A%20%3C%2Fb%3E{p_SterlingUsers}%3Cbr%2F%3E%3Cb%3E%20Notes%20%3A%20%3C%2Fb%3Etest%3Cbr%2F%3E%3Cb%3E%20Order%20%23%20%3A%20%3C%2Fb%3E{p_Horder}%20-%20{cp_InvoiceNo1}%3Cbr%2F%3E%3Cb%3E%20Product%20Details%20%3A%20%3C%2Fb%3E{cp_ItemDesc1}"
		"%20M653x%20({cp_ItemID1})%3C%2Fdiv%3E%22%2C%22Priority%22%3A%220%22%2C%22VisibleToAll%22%3A%22Y%22%2C%22ContactType%22%3A%22EMAIL%22%2C%22ContactReference%22%3A%22test%40test.com%22%2C%22ContactUser%22%3A%22{p_SterlingUsers}%22%2C%22ReasonCode%22%3A%22CREDIT_NOTE%22%7D%7D%2C%22SelectMethod%22%3A%22WAIT%22%7D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_header("SCIAjax", 
		"Y");

	web_add_header("SCIVer", 
		"0.9");

	web_custom_request("isccs.order.details.OrderPricingSummaryBehaviorController.do_2", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.details.OrderPricingSummaryBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_order_details_OrderPricingSummaryBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_order_details_OrderPricingSummaryBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22getCompleteOrderDetails%22%2C%22Input%22%3A%7B%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey1}%22%7D%7D%7D%2C%7B%22mashupRefId%22%3A%22getCompleteOrderLineList%22%2C%22scPaginationStrategy%22%3A%22NEXTPAGE%22%2C%22scPageSize%22%3A%2210%22%2C%22scPageNumbe"
		"r%22%3A1%2C%22scPreviousPageRecord%22%3A%7B%7D%2C%22Input%22%3A%7B%22OrderLine%22%3A%7B%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey1}%22%7D%7D%7D%5D%7D%7D%7D&scControllerInput="
		"%7B%22Order%22%3A%7B%22EntryType%22%3A%22Web%22%2C%22CustomerFirstName%22%3A%22{cp_FirstName}%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22AuthorizedClient%22%3A%22WCS%22%2C%22Extn%22%3A%7B%22ExtnWebProfileId%22%3A%22110283043%22%2C%22ExtnUSERTYPE%22%3A%22G%22%7D%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%2C%22TaxExemptionCertificate%22%3A%22%22%2C%22PriceInfo%22%3A%7B%22TotalAmount%22%3A%22{cp_TotalAmount}%22%2C%22Currency%22%3A%22USD%22%7D%2C%22OrderNo%22%3A%22{p_Horder}%22%2C%22CustomerPhon"
		"eNo%22%3A%22{cp_CustomerPhone}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22CustomerEMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoBillTo%22%3A%7B%22EMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey1}%22%2C%22Suffix%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%22{cp_CustomerPhone}%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22"
		"%3A%22{cp_City1}%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22NA%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22DocumentType%22%3A%220001%22%2C%22MaxOrderStatusDesc%22%3A%22Shipment%20Line%20Invoiced%22%2C%22MinOrderStatus%22%3A%223700."
		"100%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey1}%22%2C%22CustomerPONo%22%3A%22%22%2C%22DisplayStatus%22%3A%22Draft%20Order%20Created%22%2C%22DisplayEntryType%22%3A%22Web%22%2C%22MaxOrderStatus%22%3A%223700.100%22%2C%22SellerOrganizationName%22%3A%22HP%20US%20Web%20Store%22%2C%22PersonInfoShipTo%22%3A%7B%22EMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoKey%22%3A%22{cp_ShipToKey1}%22%2C%22Suffix%22%3A%22%22%2C%22Countr"
		"yDesc%22%3A%22US%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%22{cp_CustomerPhone}%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22{cp_City1}%22%2C%22AddressID%22%3A%22{cp_AddressID}%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%2"
		"2Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22CustomerLastName%22%3A%22{cp_LastName}%22%2C%22CustomerZipCode%22%3A%22{cp_ZipCode}%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22isHistory%22%3A%22N%22%2C%22OrderName%22%3A%22%22%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	lr_end_transaction("C51-4_MC_Apply",LR_AUTO);

	
	lr_think_time(10);
	
	}
		
	
		Logout();
	return 0;
}
