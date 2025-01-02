Exchange()
{
	
	
	
		lr_start_transaction("C54_DraftOrder");
	
	web_reg_find("Text=DisplayStatus","SaveCount=Status",LAST);


	web_add_auto_header("SCIAjax", 
		"Y");

	web_add_auto_header("SCIVer", 
		"0.9");

	

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_reg_save_param("cp_OrderHeaderKey4","LB=\"OrderHeaderKey\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_Rorderno","LB=\"OrderNo\":\"","RB=\"","Notfound=warning",LAST);

	web_custom_request("isccs.return.hp.create.SelectReturnReasonBehaviorController.do_3",
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.hp.create.SelectReturnReasonBehaviorController.do",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y",
		"Snapshot=t48.inf",
		"Mode=HTML",
		"Body=scControllerData=%7B%22isccs_return_hp_create_SelectReturnReasonBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_return_hp_create_SelectReturnReasonBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22createReturnOrder%22%2C%22Input%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22PersonInfoShipTo%22%3A%7B%22Company%22%3A%22%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey}%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22ZipCode%22%3A%22{Cp_ZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22{cp_City}%22%2C%22EMailID%22%3A%22{cp_EMailID}%22%2C%22MiddleName%22%3A%22%22%2C%22DayPhone%22%3A%22{cp_DayPhone}%22%2C%22MobilePhone%22%3A%22%22%2C%22AddressLine2%22%3A%22%22%2C%22AddressLine1%22%3A%22{cp_AddressLine1}%22%2C%22Department%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22PersonID%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22EveningPhone%22%3A%22%22%2C%22Country%22%3A%22{cp_Country}%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22isHistory%22%"
		"3A%22N%22%2C%22AddressID%22%3A%22{cp_AddressID}%22%7D%2C%22PersonInfoBillTo%22%3A%7B%22Company%22%3A%22%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey}%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22{cp_City}%22%2C%22EMailID%22%3A%22{cp_EMailID}%22%2C%22MiddleName%22%3A%22%22%2C%22DayPhone%22%3A%22{cp_DayPhone}%22%2C%22MobilePhone%22%3A%22%22%2C%22AddressLine2%22%3A%22%22%2C%22AddressLine1%22%3A%22{cp_AddressLine1}%22%2C%22Department%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22PersonID%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22EveningPhone%22%3A%22%22%2C%22Country%22%3A%22{cp_Country}%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22isHistory%22%3A%22N%22%7D%2C%22OrderLines%22%3A%7B%22OrderLine%22%3A%5B%7B%22DerivedFrom%22%3A%7B%22OrderLineKey%22%3A%22{cp_OrderLineKey}%22%7D%2C%22Item%22%3A%7B%22ItemID%22%3A%22{cp_ItemID}%22%7D%2C%22OrderedQty%22%3A1%2C%22ReturnReason%22%3A%2212%22%2C%22Extn%22%3A%7B%22ExtnSerialNo%22%3"
		"A%22{cp_SerialNumber}%22%2C%22ExtnReturnCondition%22%3A%22%22%7D%7D%5D%7D%2C%22Notes%22%3A%7B%22Note%22%3A%7B%22NoteText%22%3A%22testing%20for%20efs%20%3A%3A%20%20Item%20U10N3E%2C%20S%2FN%20{cp_SerialNumber}%3B%20%7C%20Testing%22%2C%22Priority%22%3A%220.00%22%2C%22VisibleToAll%22%3A%22Y%22%7D%7D%2C%22EntryType%22%3A%22Call%20Center%22%2C%22EnteredBy%22%3A%22{p_SterlingUsers}%22%2C%22Extn%22%3A%7B%7D%7D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y",
		LAST);

	web_submit_data("isccs.return.hp.create.SelectReturnReasonBehaviorController.do_4",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.hp.create.SelectReturnReasonBehaviorController.do",
		"Method=POST",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y",
		"Snapshot=t49.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_return_hp_create_SelectReturnReasonBehaviorController\":{\"controllerId\":\"isccs_return_hp_create_SelectReturnReasonBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"processReturnOrder\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey4}\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	web_submit_data("wizardController.do_3",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do",
		"Method=POST",
		"EncodeAtSign=YES",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y",
		"Snapshot=t50.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scWizardDefId", "Value=isccs.return.hp.wizards.createReturn.CreateReturnWizard", ENDITEM,
		"Name=scWizardCurrPageId", "Value=Page1", ENDITEM,
		"Name=scWizardAction", "Value=NEXT", ENDITEM,
		"Name=scWizardInstanceKey", "Value=1", ENDITEM,
		"Name=isWizard", "Value=true", ENDITEM,
		"Name=wizardData", "Value={\"scWizardDefId\":\"isccs.return.hp.wizards.createReturn.CreateReturnWizard\",\"scWizardCurrPageId\":\"Page1\",\"scWizardAction\":\"NEXT\",\"scWizardInstanceKey\":1,\"isWizard\":true,\"scControllerInput\":{\"Order\":{\"Extn\":{},\"AuthorizedClient\":\"WCS\",\"HOrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"HOrderNo\":\"{cp_OrderNo}\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"EnterpriseCode\":\"USWS\",\"SellerOrganizationCode\":\"USWS\",\"CustomerFirstName\":\"{cp_CustomerFirstName}\",\"CustomerLastName\":\"{cp_CustomerLastName}\",\"CustomerEMailID\":\"{cp_CustomerEMailID}\",\"CustomerPhoneNo\":\"{cp_CustomerPhone}\",\"EntryType\":\"Web\"}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	

	web_submit_data("isccs.return.hp.create.PaymentConfirmationBehaviorController.do",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.hp.create.PaymentConfirmationBehaviorController.do",
		"Method=POST",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y",
		"Snapshot=t53.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_return_hp_create_PaymentConfirmationBehaviorController\":{\"controllerId\":\"isccs_return_hp_create_PaymentConfirmationBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getUserHierarchy\",\"Input\":{\"User\":{\"Loginid\":\"{p_SterlingUsers}\",\"DisplayLocalizedFieldInLocale\":\"en_US_PDT\"}}},{\"mashupRefId\":\"computeRefundPayments\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey4}\"}}},{\"mashupRefId\":\"getCompleteOrderDetails\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey4}\"}}},{\"mashupRefId\":\"HPgetReturn_Threshold_getCommonCodeList\",\"Input\":{\"CommonCode\":{\"CodeType\":\"TOTAL_AMT_THRESHOLD\",\"DocumentType\":\"0003\"}}},{\"mashupRefId\":\"HPgetCompleteOrderDetailsForThreshold\",\"Input\":{\"Order\":{\"DocumentType\":\"0003\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey4}\"}}},{\"mashupRefId\":\"extn_getCommonCodeList\",\"Input\":{\"CommonCodeList\":{\"CodeType\":\"CarrierServiceCode\"}}},{\"mashupRefId\":\"capturePay"
		"ment\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);
	
	if(atoi(lr_eval_string("{Status}"))>0)
		{
		 (lr_end_transaction("C54_DraftOrder", LR_AUTO),LR_PASS);
		}
		else
		{
			(lr_end_transaction("C54_DraftOrder", LR_AUTO),LR_FAIL);
			
		}
	
	
	lr_start_transaction("C55_ExchangeOrder");

	
	web_reg_find("Text=OrderNo","SaveCount=Orderno",LAST);
	
	
	web_reg_save_param("cp_OrderHeaderKey5","LB=\"OrderHeaderKey\":\"","RB=\"","Notfound=warning",LAST);

	web_custom_request("isccs.return.hp.create.PaymentConfirmationBehaviorController.do_2",
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.hp.create.PaymentConfirmationBehaviorController.do",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y",
		"Snapshot=t55.inf",
		"Mode=HTML",
		"Body=scControllerData=%7B%22isccs_return_hp_create_PaymentConfirmationBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_return_hp_create_PaymentConfirmationBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22createExchangeOrder%22%2C%22Input%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22ReturnOrderForExchange%22%3A%7B%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey4}%22%7D%2C%22EntryType%22%3A%22Call%20Center%22%2C%22Extn%22%3A%7B%7D%7D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y",
		LAST);

	web_submit_data("isccs.return.hp.create.PaymentConfirmationBehaviorController.do_3",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.hp.create.PaymentConfirmationBehaviorController.do",
		"Method=POST",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y",
		"Snapshot=t56.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_return_hp_create_PaymentConfirmationBehaviorController\":{\"controllerId\":\"isccs_return_hp_create_PaymentConfirmationBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"computeRefundPayments\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey4}\"}}},{\"mashupRefId\":\"capturePayment\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey5}\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	web_submit_data("isccs.return.hp.create.PaymentConfirmationBehaviorController.do_4",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.hp.create.PaymentConfirmationBehaviorController.do",
		"Method=POST",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y",
		"Snapshot=t57.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_return_hp_create_PaymentConfirmationBehaviorController\":{\"controllerId\":\"isccs_return_hp_create_PaymentConfirmationBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getUserHierarchy\",\"Input\":{\"User\":{\"Loginid\":\"{p_SterlingUsers}\",\"DisplayLocalizedFieldInLocale\":\"en_US_PDT\"}}},{\"mashupRefId\":\"computeRefundPayments\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey4}\"}}},{\"mashupRefId\":\"getCompleteOrderDetails\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey4}\"}}},{\"mashupRefId\":\"HPgetReturn_Threshold_getCommonCodeList\",\"Input\":{\"CommonCode\":{\"CodeType\":\"TOTAL_AMT_THRESHOLD\",\"DocumentType\":\"0003\"}}},{\"mashupRefId\":\"HPgetCompleteOrderDetailsForThreshold\",\"Input\":{\"Order\":{\"DocumentType\":\"0003\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey4}\"}}},{\"mashupRefId\":\"extn_getCommonCodeList\",\"Input\":{\"CommonCodeList\":{\"CodeType\":\"CarrierServiceCode\"}}},{\"mashupRefId\":\"capturePay"
		"ment\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	lr_think_time(14);

	web_custom_request("isccs.return.hp.wizards.createReturn.CreateReturnWizardBehaviorController.do",
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.hp.wizards.createReturn.CreateReturnWizardBehaviorController.do",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y",
		"Snapshot=t58.inf",
		"Mode=HTML",
		"Body=scControllerData=%7B%22isccs_return_hp_wizards_createReturn_CreateReturnWizardBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_return_hp_wizards_createReturn_CreateReturnWizardBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22updateCarrierServiceForExchange%22%2C%22Input%22%3A%7B%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey5}%22%2C%22OrderNo%22%3A%22H3010051003%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22DocumentType%22%3A%220001%22%2C%22CarrierServiceCode%22%3A%22Standard%203-7%20Business%20Days%22%2C%22ResidenceFlag%22%3A%22Y%22%2C%22OriginalCarrierServiceCode%22%3A%22GR%22%2C%22OverallTotals%22%3A%7B%22GrandTotal%22%3A%2245.58%22%7D%7D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y",
		LAST);

	web_submit_data("isccs.return.hp.wizards.createReturn.CreateReturnWizardBehaviorController.do_2",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.hp.wizards.createReturn.CreateReturnWizardBehaviorController.do",
		"Method=POST",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y",
		"Snapshot=t59.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_return_hp_wizards_createReturn_CreateReturnWizardBehaviorController\":{\"controllerId\":\"isccs_return_hp_wizards_createReturn_CreateReturnWizardBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"confirmDraftReturnOrder\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey4}\"}}},{\"mashupRefId\":\"confirmDraftExchangeOrder\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey5}\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	web_custom_request("wizardController.do_4",
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y",
		"Snapshot=t60.inf",
		"Mode=HTML",
		"Body=scWizardDefId=isccs.return.wizards.returnSummary.ReturnSummaryWizard&isWizard=true&wizardData=%7B%22scWizardDefId%22%3A%22isccs.return.wizards.returnSummary.ReturnSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22OrderName%22%3A%22%22%2C%22BillToKey%22%3A%22202210310446355076723512%22%2C%22Displayl%22%3A%22Draft%20Order%20Created%22%2C%22OrderNo%22%3A%22{cp_Rorderno}%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%2245.58%22%7D%2C%22SellerOrganizationName%22%3A%22HP%20US%20Web%20Store%22%2C%22CustomerZipCode%22%3A%22{cp_ZipCode}%22%2C%22CustomerFirstName%22%3A%22{cp_CustomerFirstName}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22PersonInfoBillTo%22%3A%7B%22Company%22%3A%22%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey}%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22{cp_City}%22%2C%22EMailID%22%3A%22{cp_EMailID}%22%2C%22MiddleName%22%3A%22%22%2C%22DayPhone%22%3A%223"
		"{cp_DayPhone}%22%2C%22MobilePhone%22%3A%22%22%2C%22AddressLine2%22%3A%22%22%2C%22AddressLine1%22%3A%22{cp_AddressLine1}%22%2C%22Department%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22PersonID%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22EveningPhone%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%22Country%22%3A%22{cp_Country}%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22isHistory%22%3A%22N%22%7D%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey4}%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22TaxExemptionCertificate%22%3A%22%22%2C%22CustomerPhoneNo%22%3A%22{cp_CustomerPhone}%22%2C%22DocumentType%22%3A%220003%22%2C%22DisplayEntryType%22%3A%22Call%20Center%22%2C%22MaxOrderStatusDesc%22%3A%22Receipt%20Closed%22%2C%22Extn%22%3A%7B%22ExtnUSERTYPE%22%3A%22G%22%2C%22ExtnWebProfileId%22%3A%22136377487%22%7D%2C%22CustomerEMailID%22%3A%22{cp_CustomerEMailID}%22%2C%22CustomerPONo%22%3A%22%22%2C%22EntryType%22%3A%22Call%20Center%22%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%2C%22CustomerLastName%22%3A%22{cp_CustomerLastName}%22%2C%22S"
		"ellerOrganizationCode%22%3A%22USWS%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22PersonInfoShipTo%22%3A%7B%22Company%22%3A%22%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey}%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22{cp_City}%22%2C%22EMailID%22%3A%22{cp_EMailID}%22%2C%22MiddleName%22%3A%22%22%2C%22DayPhone%22%3A%22{cp_DayPhone}%22%2C%22MobilePhone%22%3A%22%22%2C%22AddressLine2%22%3A%22%22%2C%22AddressLine1%22%3A%22{cp_AddressLine1}%22%2C%22Department%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22PersonID%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22EveningPhone%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%22Country%22%3A%22{cp_Country}%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22isHistory%22%3A%22N%22%2C%22AddressID%22%3A%22{cp_AddressID}%22%7D%2C%22isHistory%22%3A%22N%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y",
		LAST);

	web_submit_data("isccs.editors.ReturnEditorBehaviorController.do_2",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.editors.ReturnEditorBehaviorController.do",
		"Method=POST",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y",
		"Snapshot=t61.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_editors_ReturnEditorBehaviorController\":{\"controllerId\":\"isccs_editors_ReturnEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getRequiredEditorAttributes\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey4}\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	web_submit_data("isccs.return.details.ReturnSummaryBehaviorController.do",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.details.ReturnSummaryBehaviorController.do",
		"Method=POST",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y",
		"Snapshot=t62.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_return_details_ReturnSummaryBehaviorController\":{\"controllerId\":\"isccs_return_details_ReturnSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getSalesOrderDetails\",\"Input\":{\"Order\":{\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);

	web_submit_data("isccs.return.details.ReturnSummaryBehaviorController.do_2",
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.details.ReturnSummaryBehaviorController.do",
		"Method=POST",
		"RecContentType=application/json",
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y",
		"Snapshot=t63.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=scControllerData", "Value={\"isccs_return_details_ReturnSummaryBehaviorController\":{\"controllerId\":\"isccs_return_details_ReturnSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCommonCodeList\",\"Input\":{\"CommonCodeList\":{\"CodeType\":\"CarrierServiceCode\"}}}]}}}", ENDITEM,
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM,
		"Name=scFlag", "Value=Y", ENDITEM,
		LAST);
	
	
	
	if(atoi(lr_eval_string("{Orderno}"))>0)
		{
		 (lr_end_transaction("C55_ExchangeOrder", LR_AUTO),LR_PASS);
		}
		else
		{
			(lr_end_transaction("C55_ExchangeOrder", LR_AUTO),LR_FAIL);
			
		}

	return 0;
}
