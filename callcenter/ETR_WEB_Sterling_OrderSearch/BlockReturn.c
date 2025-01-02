BlockReturn()
{
	
	lr_start_transaction("C58-1_BlockReturn");	
	
	web_custom_request("extn.order.blockReturn.blockUnblockReturnScreenInitController.do_2", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/extn.order.blockReturn.blockUnblockReturnScreenInitController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t36.inf", 
		"Mode=HTTP", 
		"Body=scControllerInput="
		"%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%2C%22DocumentType%22%3A%220001%22%2C%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22OrderNo%22%3A%22{cp_OrderNo}%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%2C%22TotalAmount%22%3A%22{cp_TotalAmount}%22%7D%2C%22PersonInfoShipTo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22EveningPhone%22%3A%22%22%2C%22AddressLine1%22%3A%22{cp_AddressLine1}%22%2C%22isHistory%22%3A%22N%22%2C%22AddressLi"
		"ne2%22%3A%22{cp_AddressLine2}%22%2C%22City%22%3A%22{cp_City}%22%2C%22MobilePhone%22%3A%22{cp_MobilePhone}%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22AddressID%22%3A%22{cp_AddressID}%22%2C%22PersonID%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22DayPhone%22%3A%22{cp_DayPhone}%22%2C%22Department%22%3A%22%22%2C%22Country%22%3A%22{cp_Country}%22%2C%22EMailID%22%3A%22{cp_EMailID}%22%2C%22Title%22%3A%22%22%2C%22FirstName%22%3A%22{cp_FirstName}%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey}%22%2C%22Company%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%2"
		"2HasMultipleAddresses%22%3A%22N%22%7D%2C%22isHistory%22%3A%22N%22%2C%22CustomerFirstName%22%3A%22{cp_FirstName}%22%2C%22CustomerLastName%22%3A%22{cp_CustomerLastName}%22%2C%22CustomerEMailID%22%3A%22{cp_CustomerEMailID}%22%2C%22CustomerPhoneNo%22%3A%22{cp_DayPhone}%22%2C%22CustomerZipCode%22%3A%22{cp_ZipCode}%22%2C%22BillToID%22%3A%22%22%2C%22CustomerID%22%3A%22%22%2C%22EntryType%22%3A%22Call%20Center%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%"
		"2C%22PersonInfoBillTo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22LastName%22%3A%22{cp_LastName}%22%2C%22EveningPhone%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%22AddressLine1%22%3A%22{cp_AddressLine1}%22%2C%22isHistory%22%3A%22N%22%2C%22AddressLine2%22%3A%22{cp_AddressLine2}%22%2C%22City%22%3A%22{cp_City}%22%2C%22MobilePhone%22%3A%22%22%2C%22ZipCode%22%3A%22{cp_ZipCode}%22%2C%22PersonID%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22State%22%3A%22{cp_State}%22%2C%22DayPhone%22%3A%22{cp_DayPhone}%22%2C%22Department%22%3A%22%22%2C%22Country%22%3A%22US%22"
		"%2C%22EMailID%22%3A%22{cp_CustomerEMailID}%22%2C%22Title%22%3A%22%22%2C%22FirstName%22%3A%22etr%22%2C%22PersonInfoKey%22%3A%22{cp_PersonInfoKey}%22%2C%22Company%22%3A%22%22%7D%2C%22HasPendingChanges%22%3A%22N%22%2C%22DisplayEntryType%22%3A%22Call%20Center%22%2C%22CarrierServiceCode%22%3A%22HD%22%2C%22Status%22%3A%22Shipment%20Line%20Invoiced%22%2C%22SupportLevel%22%3A%22Full%22%2C%22ReturnOrders%22%3A%7B%7D%2C%22SellerOrganizationName%22%3A%22HP%20US%20Web%20Store%22%2C%22MultipleStatusesEx"
		"ist%22%3A%22N%22%2C%22ShipToKey%22%3A%22{cp_PersonInfoKey}%22%2C%22HoldFlag%22%3A%22N%22%2C%22OrderHoldTypes%22%3A%7B%22OrderHoldType%22%3A%5B%7B%22Status%22%3A%221300%22%7D%2C%7B%22Status%22%3A%221300%22%7D%5D%7D%2C%22MaxOrderStatusDesc%22%3A%22Shipment%20Line%20Invoiced%22%2C%22DisplayStatus%22%3A%22Shipment%20Line%20Invoiced%22%2C%22Modifications%22%3A%7B%7D%2C%22OverallTotals%22%3A%7B%22GrandTotal%22%3A%22{cp_TotalAmount}%22%7D%2C%22OrderDate%22%3A%22{cp_OrderDate}%22%2C%22OverallSt"
		"atus%22%3A%22%22%7D%7D&scControllerData=%7B%22extn_order_blockReturn_blockUnblockReturnScreenInitController%22%3A%7B%22controllerId%22%3A%22extn_order_blockReturn_blockUnblockReturnScreenInitController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22extn_blockUnblock_getCompleteOrderLineList_RefId%22%2C%22Input%22%3A%7B%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);
	
	web_reg_save_param("cp_ItemID","LB=\"ItemID\":\"","RB=\"",LAST);
	
	
	
	web_submit_data("extn.order.blockReturn.blockUnblockReturnScreenBehaviorController.do_3", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/extn.order.blockReturn.blockUnblockReturnScreenBehaviorController.do", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t72.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"extn_order_blockReturn_blockUnblockReturnScreenBehaviorController\":{\"controllerId\":\"extn_order_blockReturn_blockUnblockReturnScreenBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_blockUnblock_getCompleteOrderLineList_RefId\",\"Input\":{\"OrderLine\":{\"ComplexQuery\":{\"Or\":{\"Exp\":[{\"Name\":\"Status\",\"Value\":\"3700\",\"StatusQryType\":\"EQ\"},{\"Name\":\"Status\",\"Value\":\"3700.10\",\"StatusQryType\":\"EQ\"}]}},\""
		"BundleParentOrderLineKeyQryType\":\"ISNULL\",\"OrderHeaderKey\":\"{cp_OrderHeaderKey}\",\"Status\":\"\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C58-1_BlockReturn",LR_AUTO);

	lr_start_transaction("C58-2_BlockReturn_UpdateOrder");
	
	web_custom_request("extn.order.blockReturn.blockUnblockReturnScreenBehaviorController.do_4", 
		"URL=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/extn.order.blockReturn.blockUnblockReturnScreenBehaviorController.do", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t39.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22extn_order_blockReturn_blockUnblockReturnScreenBehaviorController%22%3A%7B%22controllerId%22%3A%22extn_order_blockReturn_blockUnblockReturnScreenBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22changeOrder%22%2C%22Input%22%3A%7B%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22{cp_OrderHeaderKey}%22%2C%22OrderLines%22%3A%7B%22OrderLine%22%3A%5B%7B%22OrderLineKey%22%3A%22{cp_OrderLineKey}%22%2C%22Extn%22%3A%7B%22ExtnIsReturnBlocked%22%3A%22Y%22"
		"%2C%22ExtnBlockedById%22%3A%22Blocked%20By%3A%20{p_SterlingUsers}%22%7D%7D%5D%7D%2C%22Notes%22%3A%7B%22Note%22%3A%7B%22NoteText%22%3A%221%20%3A%20Blocked%20Item%3A%20{cp_ItemID}%20%20Notes%3A%20LoadTesting_By_{p_SterlingUsers}%22%2C%22ContactUser%22%3A%22{p_SterlingUsers}%22%2C%22Priority%22%3A%221%22%7D%7D%7D%7D%7D%5D%7D%7D%7D&scCSRFToken={scCSRFToken}&scFlag=Y", 
		LAST);

	lr_end_transaction("C58-2_BlockReturn_UpdateOrder",LR_AUTO);
	
	lr_think_time(10);
	
	
	return 0;
}
