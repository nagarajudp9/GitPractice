ViewSearchReturn()
{
	
	web_reg_save_param("cp_ReturnInvoice","LB=\"OrderNo\":\"R","RB=\",\"Status\":\"Return Invoiced","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_OrderHeaderKey","LB=\"OrderHeaderKey\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_Rorder","LB=\"OrderNo\":\"R","RB=\",","ORD=ALL","Notfound=warning",LAST);

	web_reg_save_param("cp_TotalAmt","LB=\"TotalAmount\":\"","RB=\"},","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_custFName","LB=\"CustomerFirstName\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_custLName","LB=\"CustomerLastName\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_custEmail","LB=\"CustomerEMailID\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_custPhone","LB=\"CustomerPhoneNo\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	web_reg_save_param("cp_custZip","LB=\"CustomerZipCode\":\"","RB=\",","ORD=ALL","Notfound=warning",LAST);
	
	lr_start_transaction("C64-1_Return_ViewSearch");

	web_custom_request("isccs.return.search.ReturnListScreenBehaviorController.do_2", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.search.ReturnListScreenBehaviorController.do", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_return_search_ReturnListScreenBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_return_search_ReturnListScreenBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22getReturnList%22%2C%22scPaginationStrategy%22%3A%22NEXTPAGE%22%2C%22scPageSize%22%3A10%2C%22scPageNumber%22%3A1%2C%22scPreviousPageRecord%22%3A%7B%7D%2C%22Input%22%3A%7B%22Order%22%3A%7B%22ApplyQueryTimeout%22%3A%22Y%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22FromOrderDate%22%3A"
		"%222020-05-05%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22ReadFromHistory%22%3A%22N%22%2C%22Status%22%3A%22%20%22%2C%22OrderBy%22%3A%7B%22Attribute%22%3A%7B%22Name%22%3A%22OrderDate-Y%22%7D%7D%7D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);


	lr_end_transaction("C64-1_Return_ViewSearch",LR_AUTO);
	
	pmax= atoi(lr_eval_string("{cp_Rorder_count}"));
	
	pextn= atoi(lr_eval_string("{cp_ReturnInvoice_count}"));
	
	if(pextn>=0)
	{
	
	prand= pextn+1;
	
	sprintf(spara,"{cp_ReturnInvoice_%d}",prand);
	
	lr_save_string(lr_eval_string(spara),"cp_ReturnInvoice");

	while(i<=pmax)
	{
		
	sprintf(spara,"{cp_Rorder_%d}",i);
		
	lr_save_string(lr_eval_string(spara),"cp_Rorder");
		              
	if(strcmp(lr_eval_string("{cp_Rorder}"),lr_eval_string("{cp_ReturnInvoice}"))==0)
		              
	{
		               	
		flag=i;
		  
	}
		               
		i++;
	}
	
	sprintf(parahold,"{cp_OrderHeaderKey_%d}",flag);
	lr_save_string(lr_eval_string(parahold),"cp_OrderHeaderKey");
	
//	sprintf(parahold,"{cp_PersonInfoShip_%d}",flag);
//	lr_save_string(lr_eval_string(parahold),"cp_PersonInfoShip");
	
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
	
	
	
		
	lr_start_transaction("C64-2_Return_SelectReturnInvoiced");

	
	web_custom_request("wizardController.do_7", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t61.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.return.wizards.returnSummary.ReturnSummaryWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.return.wizards.returnSummary.ReturnSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22DocumentType%22%3A%220003%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22OrderNo%22%3A%22R{cp_Rorder}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22	%22%7D%2C%22PersonInfoShipTo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22Las"
		"tName%22%3A%22{cp_custLName}%22%2C%22EveningPhone%22%3A%22%22%2C%22AddressLine1%22%3A%22{cp_AddressLine1}%22%2C%22isHistory%22%3A%22N%22%2C%22AddressLine2%22%3A%22%22%2C%22City%22%3A%22{cp_City}%22%2C%22MobilePhone%22%3A%22%22%2C%22ZipCode%22%3A%22{cp_custZip}%22%2C%22AddressID%22%3A%22temp_chkOut_{cp_custFName}1509468122901%22%2C%22PersonID%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22State%22%3A%22TX%22%2C%22DayPhone%22%3A%22{cp_custPhone}%22%2C%22Department%22%3A%22%22%2C%22Country%22%3A%22US%22%2C%22EMailID%22%3A%22%22%2C%22Title%22%3A%22"
		"%22%2C%22FirstName%22%3A%22{cp_custFName}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey}%22%2C%22Company%22%3A%22%22%7D%2C%22isHistory%22%3A%22N%22%2C%22CustomerFirstName%22%3A%22{cp_custFName}%22%2C%22CustomerLastName%22%3A%22{cp_custLName}%22%2C%22CustomerEMailID%22%3A%22{cp_custEmail}%22%2C%22CustomerPhoneNo%22%3A%22%22%2C%22CustomerZipCode%22%3A%22{cp_custZip}%22%2C%22BillToID%22%3A%22%22%2C%22CustomerID%22%3A%22%22%2C%22EntryType%22%3A%22Call%20Center%22%2C%22SellerOrganizationCode%22%3A%22USWS%22"
		"%2C%22TaxExemptFlag%22%3A%22N%22%2C%22Extn%22%3A%7B%7D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);
	
	
	web_submit_data("isccs.return.details.ReturnSummaryLinesBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.details.ReturnSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t49.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_details_ReturnSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_return_details_ReturnSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCompleteOrderLineList\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":10,\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"OrderLine\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"Order\":{\"EnterpriseCode\":\"USWS\",\"SellerOrganizationCode\":\"USWS\""
		"}}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);
	

	lr_end_transaction("C64-2_Return_SelectReturnInvoiced",LR_AUTO);

	//web_set_max_html_param_len("99999");
	
	
	web_reg_save_param("cp_InvoiceKey","LB=\"LastOrderInvoiceKey\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_InvoiceNum","LB=\"InvoiceNo\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_InvoiceDate","LB=\"DateInvoiced\":\"","RB=\"","Notfound=warning",LAST);
	
	web_reg_save_param("cp_returnAmt","LB=\"TotalAmount\":\"","RB=\"","Notfound=warning",LAST);
	
	
	
	lr_start_transaction("C64-3_ViewAllInvoices");
		
		web_custom_request("wizardController.do_7", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t61.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.return.wizards.returnSummary.ReturnSummaryWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.return.wizards.returnSummary.ReturnSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22DocumentType%22%3A%220003%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22OrderNo%22%3A%22R{cp_Rorder}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22	%22%7D%2C%22PersonInfoShipTo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22Las"
		"tName%22%3A%22{cp_custLName}%22%2C%22EveningPhone%22%3A%22%22%2C%22AddressLine1%22%3A%22{cp_AddressLine1}%22%2C%22isHistory%22%3A%22N%22%2C%22AddressLine2%22%3A%22%22%2C%22City%22%3A%22{cp_City}%22%2C%22MobilePhone%22%3A%22%22%2C%22ZipCode%22%3A%22{cp_custZip}%22%2C%22AddressID%22%3A%22temp_chkOut_{cp_custFName}1509468122901%22%2C%22PersonID%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22State%22%3A%22TX%22%2C%22DayPhone%22%3A%22{cp_custPhone}%22%2C%22Department%22%3A%22%22%2C%22Country%22%3A%22US%22%2C%22EMailID%22%3A%22%22%2C%22Title%22%3A%22"
		"%22%2C%22FirstName%22%3A%22{cp_custFName}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey}%22%2C%22Company%22%3A%22%22%7D%2C%22isHistory%22%3A%22N%22%2C%22CustomerFirstName%22%3A%22{cp_custFName}%22%2C%22CustomerLastName%22%3A%22{cp_custLName}%22%2C%22CustomerEMailID%22%3A%22{cp_custEmail}%22%2C%22CustomerPhoneNo%22%3A%22%22%2C%22CustomerZipCode%22%3A%22{cp_custZip}%22%2C%22BillToID%22%3A%22%22%2C%22CustomerID%22%3A%22%22%2C%22EntryType%22%3A%22Call%20Center%22%2C%22SellerOrganizationCode%22%3A%22USWS%22"
		"%2C%22TaxExemptFlag%22%3A%22N%22%2C%22Extn%22%3A%7B%7D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);
		
		
		web_submit_data("isccs.invoice.InvoiceDetailsInitController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.invoice.InvoiceDetailsInitController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t51.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerInput", "Value={\"InvoiceDetail\":{\"OrderInvoiceKey\":\"{cp_InvoiceKey}\",\"Currency\":\"USD\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"InvoiceTypeDescription\":\"Return\",\"DocumentType\":\"0003\",\"DateInvoiced\":\"{cp_InvoiceDate}\",\"InvoiceType\":\"RETURN\",\"TotalAmount\":\"{cp_returnAmt}\",\"InvoiceNo\":\"{cp_InvoiceNum}\",\"EnterpriseCode\":\"USWS\"}}", ENDITEM, 
		"Name=scControllerData", "Value={\"isccs_invoice_InvoiceDetailsInitController\":{\"controllerId\":\"isccs_invoice_InvoiceDetailsInitController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrderInvoiceDetails\",\"Input\":{}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	

	web_submit_data("isccs.invoice.InvoiceDetailsBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.invoice.InvoiceDetailsBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t54.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_invoice_InvoiceDetailsBehaviorController\":{\"controllerId\":\"isccs_invoice_InvoiceDetailsBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrganizationList\",\"Input\":{\"Organization\":{\"OrganizationCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C64-3_ViewAllInvoices",LR_AUTO);
	
}


	

	else
	{
		FindReturn();
	}
	
	
	lr_think_time(10);

	return 0;
}
