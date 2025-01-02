ResolveHold()
{
	pmax= atoi(lr_eval_string("{cp_HoldFlag_count}"));
	
	while(i<=pmax)
	{
				
		sprintf(parahold,"{cp_HoldFlag_%d}",i);
		
		lr_save_string(lr_eval_string(parahold),"cp_HoldFlag");
		
		if(strcmp("Y",lr_eval_string("{cp_HoldFlag}"))==0)
		{
			flag=i;
			}
			
		i++;
	}
	
	lr_output_message(lr_eval_string("{cp_HoldFlag}"));
	
	if(flag!=1)
	{
		
	sprintf(parahold,"{cp_HoldFlag_%d}",flag);
	
	lr_save_string(lr_eval_string(parahold),"cp_HoldFlag");
	
	sprintf(parahold,"{cp_OrderHeaderKey_%d}",flag);
	lr_save_string(lr_eval_string(parahold),"cp_OrderHeaderKey");
	
	sprintf(parahold,"{cp_PersonInfoShip_%d}",flag);
	lr_save_string(lr_eval_string(parahold),"cp_PersonInfoShip");
	
	sprintf(parahold,"{cp_Rorder_%d}",flag);
	lr_save_string(lr_eval_string(parahold),"cp_Rorder");
	
	sprintf(parahold,"{cp_TotalAmt_%d}",flag);
	lr_save_string(lr_eval_string(parahold),"cp_TotalAmt");
	
	sprintf(parahold,"{cp_custFName_%d}",flag);
	lr_save_string(lr_eval_string(parahold),"cp_custFName");
	
	sprintf(parahold,"{cp_custLName_%d}",flag);
	lr_save_string(lr_eval_string(parahold),"cp_custLName");
	
	sprintf(parahold,"{cp_custEmail_%d}",flag);
	lr_save_string(lr_eval_string(parahold),"cp_custEmail");
	
	sprintf(parahold,"{cp_custPhone_%d}",flag);
	lr_save_string(lr_eval_string(parahold),"cp_custPhone");
	
	sprintf(parahold,"{cp_custZip_%d}",flag);
	lr_save_string(lr_eval_string(parahold),"cp_custZip");
	
	lr_start_transaction("C61-1_Return_SelectHold");
	
	web_custom_request("wizardController.do_3", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t26.inf", 
		"Mode=HTTP", 
		"Body=scWizardDefId=isccs.return.wizards.returnSummary.ReturnSummaryWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.return.wizards.returnSummary.ReturnSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22DocumentType%22%3A%220003%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22OrderNo%22%3A%22R{cp_Rorder}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22{cp_TotalAmt}%22%7D%2C%22PersonInfoShipTo%22%3A%7B%22{cp_PersonInfoShip}Company%22%3A%22%22%7D%2C%22isHistory%22%3A%22N%22%2C%22CustomerFirstName%22%3A%22{cp_custFName}%22%2C%22CustomerLastName%22%3A%22{cp_custLName}%22%2C%22CustomerEMailID%22%3A%22{cp_custEmail}%22%2C%22CustomerPhoneNo%22%3A%22{cp_custPhone}%22%2C%22CustomerZipCode%22%3A%22{cp_custZip}%22%2C%22BillToID%22%3A%22%22%2C%22CustomerID%22%3A%22%22%2C%22EntryType%22%3A%22Call%20Center%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22TaxExe"
		"mptFlag%22%3A%22N%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);
	
	web_submit_data("isccs.return.details.ReturnSummaryLinesBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.details.ReturnSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_details_ReturnSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_return_details_ReturnSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCompleteOrderLineList\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":10,\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"OrderLine\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"Order\":{\"EnterpriseCode\":\"USWS\",\"SellerOrganizationCode\":\"USWS\"}"
		"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C61-1_Return_SelectHold",LR_AUTO);
	
	lr_think_time(10);

	lr_start_transaction("C61-2_Return_ResolveHold");

	web_custom_request("wizardController.do_4", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t29.inf", 
		"Mode=HTTP", 
		"Body=scWizardDefId=isccs.order.wizards.resolveHold.ResolveHoldWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.order.wizards.resolveHold.ResolveHoldWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22DocumentType%22%3A%220003%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22OrderNo%22%3A%22R{cp_Rorder}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22{cp_TotalAmt}%22%7D%2C%22PersonInfoShipTo%22%3A%7B%22{cp_PersonInfoShip}Company%22%3A%22%22%7D%2C%22isHistory%22%3A%22N%22%2C%22CustomerFirstName%22%3A%22{cp_custFName}%22%2C%22CustomerLastName%22%3A%22{cp_custLName}%22%2C%22CustomerEMailID%22%3A%22{cp_custEmail}%22%2C%22CustomerPhoneNo%22%3A%22{cp_custPhone}%22%2C%22CustomerZipCode%22%3A%22{cp_custZip}%22%2C%22BillToID%22%3A%22%22%2C%22CustomerID%22%3A%22%22%2C%22EntryType%22%3A%22Call%20Center%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22TaxExemptFl"
		"ag%22%3A%22N%22%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	lr_end_transaction("C61-2_Return_ResolveHold",LR_AUTO);
	
	//lr_think_time(10);


	lr_start_transaction("C61-3_Return_HoldConfirm");

	web_submit_data("isccs.order.orderHold.ResolveHoldBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.orderHold.ResolveHoldBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_orderHold_ResolveHoldBehaviorController\":{\"controllerId\":\"isccs_order_orderHold_ResolveHoldBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"resolveHolds_changeOrder\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.orderHold.ResolveHoldBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.orderHold.ResolveHoldBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_orderHold_ResolveHoldBehaviorController\":{\"controllerId\":\"isccs_order_orderHold_ResolveHoldBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getOrderDetails\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"DocumentType\":\"0003\",\"EnterpriseCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);
	
	web_custom_request("wizardController.do_5", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t31.inf", 
		"Mode=HTTP", 
		"Body=scWizardDefId=isccs.return.wizards.returnSummary.ReturnSummaryWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.return.wizards.returnSummary.ReturnSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22DocumentType%22%3A%220003%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22OrderNo%22%3A%22R{cp_Rorder}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22{cp_TotalAmt}%22%7D%2C%22PersonInfoShipTo%22%3A%7B%22{cp_PersonInfoShip}Company%22%3A%22%22%7D%2C%22isHistory%22%3A%22N%22%2C%22CustomerFirstName%22%3A%22{cp_custFName}%22%2C%22CustomerLastName%22%3A%22{cp_custLName}%22%2C%22CustomerEMailID%22%3A%22{cp_custEmail}%22%2C%22CustomerPhoneNo%22%3A%22{cp_custPhone}%22%2C%22CustomerZipCode%22%3A%22{cp_custZip}%22%2C%22BillToID%22%3A%22%22%2C%22CustomerID%22%3A%22%22%2C%22EntryType%22%3A%22Call%20Center%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22TaxExe"
		"mptFlag%22%3A%22N%22%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y",  
		LAST);

	web_submit_data("isccs.return.details.ReturnSummaryLinesBehaviorController.do_2", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.details.ReturnSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_details_ReturnSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_return_details_ReturnSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCompleteOrderLineList\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":10,\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"OrderLine\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"Order\":{\"EnterpriseCode\":\"USWS\",\"SellerOrganizationCode\":\"USWS\"}"
		"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C61-3_Return_HoldConfirm",LR_AUTO);
	
	lr_think_time(10);

	
	}
	
	else
	{
		
		FindReturn();
		
		return 0;
	}
	
	
	if(atoi(lr_eval_string("{p_iteration}"))>=1)
	{

	lr_start_transaction("C63-1_CancelReturn");
	
	web_custom_request("wizardController.do_7", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t41.inf", 
		"Mode=HTTP", 
		"Body=scWizardDefId=extn.wizards.cancelReturn.HPCancelReturnWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22extn.wizards.cancelReturn.HPCancelReturnWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22DocumentType%22%3A%220003%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22OrderNo%22%3A%22R{cp_Rorder}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22{cp_TotalAmt}%22%7D%2C%22PersonInfoShipTo%22%3A%7B%22{cp_PersonInfoShip}Company%22%3A%22%22%7D%2C%22isHistory%22%3A%22N%22%2C%22CustomerFirstName%22%3A%22{cp_custFName}%22%2C%22CustomerLastName%22%3A%22{cp_custLName}%22%2C%22CustomerEMailID%22%3A%22{cp_custEmail}%22%2C%22CustomerPhoneNo%22%3A%22{cp_custPhone}%22%2C%22CustomerZipCode%22%3A%22{cp_custZip}%22%2C%22BillToID%22%3A%22%22%2C%22CustomerID%22%3A%22%22%2C%22EntryType%22%3A%22Call%20Center%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22EnterpriseName%22%3A%22HP%20US%"
		"20Web%20Store%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	lr_end_transaction("C63-1_CancelReturn",LR_AUTO);
	
	//lr_think_time(10);

	lr_start_transaction("C63-2_CancelReturn_Next");

	web_custom_request("isccs.order.cancel.CancelOrderBaseScreenBehaviorController.do", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.order.cancel.CancelOrderBaseScreenBehaviorController.do", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_order_cancel_CancelOrderBaseScreenBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_order_cancel_CancelOrderBaseScreenBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22extn_cancelOrderMashupRef%22%2C%22Input%22%3A%7B%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22ModificationReasonCode%22%3A%22Suspicious%20order%22%2C%22Notes%22%3A%7B%22Note%22%3A%7B%22NoteText%22%3A%22test%22%2C%22Priority%22%3A%220%22%2C%22V"
		"isibleToAll%22%3A%22Y%22%2C%22ContactType%22%3A%22EMAIL%22%2C%22ContactReference%22%3A%22sskk%40mail.com%22%7D%7D%2C%22Action%22%3A%22CANCEL%22%7D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);
	
	web_custom_request("wizardController.do_8", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t43.inf", 
		"Mode=HTTP", 
		"Body=scWizardDefId=extn.wizards.cancelReturn.HPCancelReturnWizard&scWizardCurrPageId=Page1&scWizardAction=NEXT&scWizardInstanceKey=1&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22extn.wizards.cancelReturn.HPCancelReturnWizard%22%2C%22scWizardCurrPageId%22%3A%22Page1%22%2C%22scWizardAction%22%3A%22NEXT%22%2C%22scWizardInstanceKey%22%3A1%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22DocumentType%22%3A%220003%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22OrderNo%22%3A%22R{cp_Rorder}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22{cp_TotalAmt}%22%7D%2C%22PersonInfoShipTo%22%3A%7B%22{cp_PersonInfoShip}Company%22%3A%22%22%7D%2C%22isHistory%22%3A%22N%22%2C%22CustomerFirstName%22%3A%22{cp_custFName}%22%2C%22CustomerLastName%22%3A%22{cp_custLName}%22%2C%22CustomerEMailID%22%3A%22{cp_custEmail}%22%2C%22CustomerPhoneNo%22%3A%22{cp_custPhone}%22%2C%22CustomerZipCode%22%3A%22{cp_custZip}%22%2C%22BillToID%22%3A%22%22%2C%22CustomerID%22%3A%22%22%2C%22EntryType%22%3A%22Call%20Center%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	web_submit_data("isccs.payment.confirmation.PaymentConfirmationBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.payment.confirmation.PaymentConfirmationBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_payment_confirmation_PaymentConfirmationBehaviorController\":{\"controllerId\":\"isccs_payment_confirmation_PaymentConfirmationBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCommonCodeList\",\"Input\":{\"CommonCode\":{\"CodeType\":\"TOTAL_AMT_THRESHOLD\",\"OrganizationCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C63-2_CancelReturn_Next",LR_AUTO);
	


	lr_start_transaction("C63-3_CancelReturn_Confirm");
	
	web_custom_request("wizardController.do_9", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t47.inf", 
		"Mode=HTTP", 
		"Body=scWizardDefId=isccs.return.wizards.returnSummary.ReturnSummaryWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.return.wizards.returnSummary.ReturnSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22DocumentType%22%3A%220003%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22OrderNo%22%3A%22R{cp_Rorder}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22{cp_TotalAmt}%22%7D%2C%22PersonInfoShipTo%22%3A%7B%22{cp_PersonInfoShip}Company%22%3A%22%22%7D%2C%22isHistory%22%3A%22N%22%2C%22CustomerFirstName%22%3A%22{cp_custFName}%22%2C%22CustomerLastName%22%3A%22{cp_custLName}%22%2C%22CustomerEMailID%22%3A%22{cp_custEmail}%22%2C%22CustomerPhoneNo%22%3A%22{cp_custPhone}%22%2C%22CustomerZipCode%22%3A%22{cp_custZip}%22%2C%22BillToID%22%3A%22%22%2C%22CustomerID%22%3A%22%22%2C%22EntryType%22%3A%22Call%20Center%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22EnterpriseName%22%3A%22"
		"HP%20US%20Web%20Store%22%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	web_submit_data("isccs.return.details.ReturnSummaryLinesBehaviorController.do_3", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.details.ReturnSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_details_ReturnSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_return_details_ReturnSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCompleteOrderLineList\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":10,\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"OrderLine\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"Order\":{\"EnterpriseCode\":\"USWS\",\"SellerOrganizationCode\":\"USWS\"}"
		"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C63-3_CancelReturn_Confirm",LR_AUTO);
	lr_think_time(10);


}

	
	
	return 0;
}
