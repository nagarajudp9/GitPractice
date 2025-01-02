Return()
{
	
	if(strcmp(lr_eval_string("{cp_Status}"),"Shipment Line Invoiced")==0 || strcmp(lr_eval_string("{cp_Status}"),"Partially Shipment Line Invoiced")==0)
	
	{
	
	lr_start_transaction("C57-1_CreateReturn");

	web_submit_data("wizardController.do_6", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t54.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=scWizardDefId", "Value=isccs.return.hp.wizards.createReturn.CreateReturnWizard", ENDITEM, 
		"Name=isWizard", "Value=true", ENDITEM, 
		"Name=wizardData", "Value={\"scWizardDefId\":\"isccs.return.hp.wizards.createReturn.CreateReturnWizard\",\"isWizard\":true,\"scControllerInput\":{\"Order\":{\"Extn\":{},\"AuthorizedClient\":\"WCS\",\"HOrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"HOrderNo\":\"{p_Horder}\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"EnterpriseCode\":\"USWS\",\"SellerOrganizationCode\":\"USWS\",\"CustomerFirstName\":\"{cp_FirstName}\",\"CustomerLastName\":\"{cp_LastName}\",\"CustomerEMailID\":\""
		"{cp_EMailID}\",\"CustomerPhoneNo\":\"{cp_DayPhone}\",\"EntryType\":\"Web\"}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_revert_auto_header("SCIAjax");

	web_revert_auto_header("SCIVer");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("isccs.editors.ReturnEditorBehaviorController.do_5", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.ReturnEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t55.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_ReturnEditorBehaviorController\":{\"controllerId\":\"isccs_editors_ReturnEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getEnterpriseList\",\"Input\":{\"Organization\":{}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_add_auto_header("SCIAjax", 
		"Y");

	web_add_auto_header("SCIVer", 
		"0.9");

	web_submit_data("isccs.editors.ReturnEditorBehaviorController.do_6", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.ReturnEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t56.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_ReturnEditorBehaviorController\":{\"controllerId\":\"isccs_editors_ReturnEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getRequiredEditorAttributes\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.return.hp.create.SelectReturnReasonBehaviorController.do_5", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.hp.create.SelectReturnReasonBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t57.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_hp_create_SelectReturnReasonBehaviorController\":{\"controllerId\":\"isccs_return_hp_create_SelectReturnReasonBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCommonCodeListAPI\",\"Input\":{\"CommonCode\":{\"CodeType\":\"RETURN_FEES_DEFAULT\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.return.hp.create.SelectReturnReasonBehaviorController.do_6", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.hp.create.SelectReturnReasonBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t58.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_hp_create_SelectReturnReasonBehaviorController\":{\"controllerId\":\"isccs_return_hp_create_SelectReturnReasonBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOriginalOrderLineListWithReturn\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C57-1_CreateReturn",LR_AUTO);

	web_reg_save_param("cp_OrderHeaderKey1","LB=\"OrderHeaderKey\":\"","RB=\"","Notfound=warning",LAST);
	
	lr_think_time(10);
	
	lr_start_transaction("C57-2_CreateNext");

	web_custom_request("isccs.return.hp.create.SelectReturnReasonBehaviorController.do_7", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.hp.create.SelectReturnReasonBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t59.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_return_hp_create_SelectReturnReasonBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_return_hp_create_SelectReturnReasonBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22createReturnOrder%22%2C%22Input%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22PersonInfoShipTo%22%3A%7B%22EMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey_2}%22%2C%22Suffix%22%3A%22%22%2C%22"
		"Country%22%3A%22US%22%2C%22DayPhone%22%3A%22{cp_DayPhone}%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22ZipCode%22%3A%22{cp_CustomerZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22{cp_City1}%22%2C%22AddressID%22%3A%22{cp_AddressID}%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressL"
		"ine1%22%3A%22123%20Perf%20Street%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22PersonInfoBillTo%22%3A%7B%22EMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey_1}%22%2C%22Suffix%22%3A%22%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%22{cp_DayPhone}%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22ZipCode%22%3A%22{cp_CustomerZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22{cp_City1}%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22PersonID%22%3A%22%"
		"22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22NA%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%22123%20Perf%20Street%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22OrderLines%22%3A%7B%22OrderLine%22%3A%5B%7B%22DerivedFrom%22%3A%7B%22OrderLineKey%22%3A%22{cp_OrderLineKey}%22%7D%2C%22OrderedQty%22%3A1%2C%22ReturnReason%22%3A%2212%22%7D%5D%7D%2C%22Notes%22%3A%7B%22Note%22%3A%7B%22NoteText%2"
		"2%3A%22Testing%22%2C%22Priority%22%3A%220.00%22%2C%22VisibleToAll%22%3A%22Y%22%2C%22ContactType%22%3A%22EMAIL%22%2C%22ContactReference%22%3A%22test%40test.com%22%7D%7D%2C%22EntryType%22%3A%22Call%20Center%22%2C%22Extn%22%3A%7B%7D%7D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	web_reg_save_param("cp_Rorder","LB=\"OrderNo\":\"","RB=\"","Notfound=warning",LAST);
	
	web_submit_data("isccs.return.hp.create.SelectReturnReasonBehaviorController.do_8", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.hp.create.SelectReturnReasonBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t60.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_hp_create_SelectReturnReasonBehaviorController\":{\"controllerId\":\"isccs_return_hp_create_SelectReturnReasonBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"processReturnOrder\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey1}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("wizardController.do_7", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t61.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=scWizardDefId", "Value=isccs.return.hp.wizards.createReturn.CreateReturnWizard", ENDITEM, 
		"Name=scWizardCurrPageId", "Value=Page1", ENDITEM, 
		"Name=scWizardAction", "Value=NEXT", ENDITEM, 
		"Name=scWizardInstanceKey", "Value=1", ENDITEM, 
		"Name=isWizard", "Value=true", ENDITEM, 
		"Name=wizardData", "Value={\"scWizardDefId\":\"isccs.return.hp.wizards.createReturn.CreateReturnWizard\",\"scWizardCurrPageId\":\"Page1\",\"scWizardAction\":\"NEXT\",\"scWizardInstanceKey\":1,\"isWizard\":true,\"scControllerInput\":{\"Order\":{\"Extn\":{},\"AuthorizedClient\":\"WCS\",\"HOrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"HOrderNo\":\"{p_Horder}\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"EnterpriseCode\":\"USWS\",\"SellerOrganizationCode\":\"USWS\",\"CustomerFirstName\":\""
		"{cp_FirstName}\",\"CustomerLastName\":\"{cp_LastName}\",\"CustomerEMailID\":\"{cp_EMailID}\",\"CustomerPhoneNo\":\"{cp_DayPhone}\",\"EntryType\":\"Web\"}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_custom_request("OrderTotal_Return.html_2", 
		"URL=https://{p_SterlingHostName}/isccs/isccs/order/details/templates/OrderTotal_Return.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t62.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("OrderTotal_OrderPricingSummaryLink.html_2", 
		"URL=https://{p_SterlingHostName}/isccs/isccs/order/details/templates/OrderTotal_OrderPricingSummaryLink.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t63.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("SCIAjax");

	web_revert_auto_header("SCIVer");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("SCIAjax", 
		"Y");

	web_add_auto_header("SCIVer", 
		"0.9");

	web_submit_data("isccs.return.hp.create.PaymentConfirmationBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.hp.create.PaymentConfirmationBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t64.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_hp_create_PaymentConfirmationBehaviorController\":{\"controllerId\":\"isccs_return_hp_create_PaymentConfirmationBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getUserHierarchy\",\"Input\":{\"User\":{\"Loginid\":\"{p_SterlingUsers}\",\"DisplayLocalizedFieldInLocale\":\"en_US_PDT\"}}},{\"mashupRefId\":\"computeRefundPayments\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey1}\"}}},{\"mashupRefId\":\""
		"getCompleteOrderDetails\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey1}\"}}},{\"mashupRefId\":\"HPgetReturn_Threshold_getCommonCodeList\",\"Input\":{\"CommonCode\":{\"CodeType\":\"TOTAL_AMT_THRESHOLD\",\"DocumentType\":\"0003\"}}},{\"mashupRefId\":\"HPgetCompleteOrderDetailsForThreshold\",\"Input\":{\"Order\":{\"DocumentType\":\"0003\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey1}\"}}},{\"mashupRefId\":\"extn_getCommonCodeList\",\"Input\":{\"CommonCodeList\":{\"CodeType\":\""
		"CarrierServiceCode\"}}},{\"mashupRefId\":\"capturePayment\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C57-2_CreateNext",LR_AUTO);

	
	lr_think_time(10);
	
	
	lr_start_transaction("C57-3_ReturnConfirm");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("isccs.return.hp.wizards.createReturn.CreateReturnWizardBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.hp.wizards.createReturn.CreateReturnWizardBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t65.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_hp_wizards_createReturn_CreateReturnWizardBehaviorController\":{\"controllerId\":\"isccs_return_hp_wizards_createReturn_CreateReturnWizardBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"confirmDraftReturnOrder\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey1}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_revert_auto_header("SCIAjax");

	web_revert_auto_header("SCIVer");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("SCIAjax", 
		"Y");

	web_add_auto_header("SCIVer", 
		"0.9");

	web_custom_request("wizardController.do_8", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t66.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.return.wizards.returnSummary.ReturnSummaryWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.return.wizards.returnSummary.ReturnSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EntryType%22%3A%22Call%20Center%22%2C%22CustomerFirstName%22%3A%22{cp_FirstName}%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%2C%22TaxExemptionCertificate%22%3A%22%22%2C%22PriceInfo%22%3A%7B%22TotalAmount%22%3A%2283.82%22%2C%22Currency%22%3A%22USD%22%7D%2C%22OrderNo%22%3A%22{cp_Rorder}%22%2"
		"C%22CustomerPhoneNo%22%3A%22{cp_DayPhone}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22CustomerEMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoBillTo%22%3A%7B%22EMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey_1}%22%2C%22Suffix%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%22{cp_DayPhone}%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22ZipCode%22%3A%22{cp_CustomerZipCode}%22%2C%22Title%22%3A%22"
		"%22%2C%22City%22%3A%22{cp_City1}%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22NA%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%22123%20Perf%20Street%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22DocumentType%22%3A%220003%22%2C%22MaxOrderStatusDesc%22%3A%22Created%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22OrderHeaderK"
		"ey%22%3A%22{cp_OrderHeaderKey1}%22%2C%22CustomerPONo%22%3A%22%22%2C%22DisplayStatus%22%3A%22Draft%20Order%20Created%22%2C%22DisplayEntryType%22%3A%22Call%20Center%22%2C%22SellerOrganizationName%22%3A%22HP%20US%20Web%20Store%22%2C%22PersonInfoShipTo%22%3A%7B%22EMailID%22%3A%22{cp_CustomerEMailID1}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey_2}%22%2C%22Suffix%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22Country%22%3A%22US%22%2C%2"
		"2DayPhone%22%3A%22{cp_DayPhone}%22%2C%22ZipCode%22%3A%22{cp_CustomerZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22{cp_City1}%22%2C%22AddressID%22%3A%22{cp_AddressID}%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%22123%20Perf%20Street%22%2C%22AddressLine2%22%3A%2"
		"2%22%7D%2C%22CustomerLastName%22%3A%22{cp_LastName}%22%2C%22CustomerZipCode%22%3A%22{cp_CustomerZipCode}%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22isHistory%22%3A%22N%22%2C%22OrderName%22%3A%22%22%2C%22BillToKey%22%3A%22{cp_PersonInfoKey_1}%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("isccs.editors.ReturnEditorBehaviorController.do_7", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.ReturnEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t67.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_ReturnEditorBehaviorController\":{\"controllerId\":\"isccs_editors_ReturnEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getEnterpriseList\",\"Input\":{\"Organization\":{}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.editors.ReturnEditorBehaviorController.do_8", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.ReturnEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t68.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_ReturnEditorBehaviorController\":{\"controllerId\":\"isccs_editors_ReturnEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getRequiredEditorAttributes\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey1}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.return.details.ReturnSummaryBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.details.ReturnSummaryBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t69.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_details_ReturnSummaryBehaviorController\":{\"controllerId\":\"isccs_return_details_ReturnSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getSalesOrderDetails\",\"Input\":{\"Order\":{\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C57-3_ReturnConfirm",LR_AUTO);

	lr_think_time(10);
	
}

	Logout();
	
return 0;

}
