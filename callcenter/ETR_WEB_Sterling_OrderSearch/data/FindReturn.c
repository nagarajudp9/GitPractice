FindReturn()
{

	lr_think_time(72);

	lr_start_transaction("clk_findreturn");

	web_submit_data("isccs.home.portlets.ReturnsPortletBehaviorController.do", 
		"Action=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/scuiimpl/controller/default/isccs.home.portlets.ReturnsPortletBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_home_portlets_ReturnsPortletBehaviorController\":{\"controllerId\":\"isccs_home_portlets_ReturnsPortletBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getReturnOrderList\",\"Input\":{\"Order\":{\"OrderNo\":\"R320206539\",\"MaximumRecords\":\"2\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1512721390372jRCx1Sk6LfrGSulrM6jehp", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_custom_request("wizardController.do_2", 
		"URL=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.return.wizards.returnSummary.ReturnSummaryWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.return.wizards.returnSummary.ReturnSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22201711171144324224928967%22%2C%22PersonInfoBillTo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22LastName%22%3A%22Reddy%22%2C%22EveningPhone%22%3A%22%22%2C%22AddressLine1%22%3A%22Shipping%22%2C%22isHistory%22%3A%22N%22%2C%22AddressLine2%22%3A%22Address%22%2C%22City%22%3A%22austin%22%2C%22MobilePhone%22%3A%22%22%2C%22ZipCode%"
		"22%3A%2278763%22%2C%22PersonID%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22State%22%3A%22TX%22%2C%22DayPhone%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22Country%22%3A%22US%22%2C%22EMailID%22%3A%22testeppuseruat2%40yopmail.com%22%2C%22Title%22%3A%22%22%2C%22FirstName%22%3A%22Vikram%22%2C%22PersonInfoKey%22%3A%22201711171144324224928969%22%2C%22Company%22%3A%22%22%7D%2C%22isHistory%22%3A%22N%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22OrderNo%22%3A%22R320206539%22%2C%22CustomerZipCode%22%3A%2278763%22"
		"%2C%22Status%22%3A%22Created%22%2C%22DocumentType%22%3A%220003%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22OrderName%22%3A%22%22%2C%22SellerOrganizationName%22%3A%22HP%20US%20Web%20Store%22%2C%22CustomerPONo%22%3A%22%22%2C%22CustomerLastName%22%3A%22Reddy%22%2C%22MultipleStatusesExist%22%3A%22N%22%2C%22HoldFlag%22%3A%22N%22%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%2C%22EntryType%22%3A%22Call%20Center%22%2C%22MaxOrderStatusDesc%22%3A%22Created%22%2C%22Custom"
		"erPhoneNo%22%3A%22%22%2C%22DisplayStatus%22%3A%22Created%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22216.49%22%7D%2C%22TaxExemptionCertificate%22%3A%22%22%2C%22CustomerEMailID%22%3A%22testeppuseruat2%40yopmail.com%22%2C%22PersonInfoShipTo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22LastName%22%3A%22Reddy%22%2C%22EveningPhone%22%3A%22%22%2C%22AddressLine1%22%3A%22Shipping%22%2C%22isHistory%22%3A%22N%22%2C%22AddressLine2%22%3A%22Address%22%2C%22City%22%3A%22austin%22%2C%"
		"22MobilePhone%22%3A%22%22%2C%22ZipCode%22%3A%2278763%22%2C%22AddressID%22%3A%22temp_chkOut_Vikram%20Reddy1508867191078%22%2C%22PersonID%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22State%22%3A%22TX%22%2C%22DayPhone%22%3A%224082298191%22%2C%22Department%22%3A%22%22%2C%22Country%22%3A%22US%22%2C%22EMailID%22%3A%22%22%2C%22Title%22%3A%22%22%2C%22FirstName%22%3A%22Vikram%22%2C%22PersonInfoKey%22%3A%22201711171144324224928968%22%2C%22Company%22%3A%22%22%7D%2C%22OrderDate%22%3A%222017-11-17T11%3A44%3A32%2B0"
		"0%3A00%22%2C%22CustomerFirstName%22%3A%22Vikram%22%2C%22OverallStatus%22%3A%22%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%7D%7D%7D&scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		EXTRARES, 
		"Url=../isccs/resources/css/icons/images/returnOrder48x48.png", "Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.editors.ReturnEditorBehaviorController.do", 
		"Action=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/scuiimpl/controller/default/isccs.editors.ReturnEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_ReturnEditorBehaviorController\":{\"controllerId\":\"isccs_editors_ReturnEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getRequiredEditorAttributes\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"201711171144324224928967\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1512721390372jRCx1Sk6LfrGSulrM6jehp", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		EXTRARES, 
		"Url=/isccs/ibmjs/idx/themes/oneui/dijit/images/spriteArrows.png", "Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/ibmjs/idx/themes/oneui/oneui_opt.css?scetag=6f44c2812a532466be224d4a5f005d9db3248601", ENDITEM, 
		LAST);

	web_submit_data("isccs.return.details.ReturnSummaryLinesBehaviorController.do", 
		"Action=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/scuiimpl/controller/default/isccs.return.details.ReturnSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_details_ReturnSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_return_details_ReturnSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCompleteOrderLineList\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":10,\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"OrderLine\":{\"OrderHeaderKey\":\"201711171144324224928967\",\"Order\":{\"EnterpriseCode\":\"USWS\",\"SellerOrganizationCode\":\"USWS\""
		"}}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1512721390372jRCx1Sk6LfrGSulrM6jehp", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		EXTRARES, 
		"Url=/isccs//isccs/resources/css/icons/images/noProductThumbnail.png", "Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", ENDITEM, 
		LAST);

	lr_end_transaction("clk_findreturn",LR_AUTO);

	return 0;
}
