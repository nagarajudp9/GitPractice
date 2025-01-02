FindOrder()
{

	lr_think_time(43);

	lr_start_transaction("clk_findorder");

	web_submit_data("isccs.home.portlets.OrderPortletBehaviorController.do", 
		"Action=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/scuiimpl/controller/default/isccs.home.portlets.OrderPortletBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_home_portlets_OrderPortletBehaviorController\":{\"controllerId\":\"isccs_home_portlets_OrderPortletBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrderList\",\"Input\":{\"Order\":{\"OrderNo\":\"H329194799\",\"EnterpriseCode\":\"USWS\",\"MaximumRecords\":\"2\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1512721390372jRCx1Sk6LfrGSulrM6jehp", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		EXTRARES, 
		"Url=/isccs//isccs/resources/css/icons/images/order48x48.png", "Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", ENDITEM, 
		"Url=/isccs/isccs/resources/css/icons/images/contactByPhone.png", "Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", ENDITEM, 
		"Url=/isccs/isccs/resources/css/icons/images/contactByEmail.png", "Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.editors.OrderEditorBehaviorController.do", 
		"Action=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getRequiredEditorAttributes\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"201712071150014252545659\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1512721390372jRCx1Sk6LfrGSulrM6jehp", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_custom_request("wizardController.do", 
		"URL=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.order.wizards.orderSummary.OrderSummaryWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.order.wizards.orderSummary.OrderSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22201712071150014252545659%22%2C%22PersonInfoBillTo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22LastName%22%3A%22Perflast%22%2C%22EveningPhone%22%3A%22%22%2C%22AddressLine1%22%3A%22Perfdrive%22%2C%22isHistory%22%3A%22N%22%2C%22AddressLine2%22%3A%22%22%2C%22City%22%3A%22Newyork%22%2C%22MobilePhone%22%3A%22%22%2C%22ZipCode%22%3A"
		"%2210007%22%2C%22PersonID%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22State%22%3A%22NY%22%2C%22DayPhone%22%3A%221234567890%22%2C%22Department%22%3A%22%22%2C%22Country%22%3A%22US%22%2C%22EMailID%22%3A%22perftestingestoretru%40mail.com%22%2C%22Title%22%3A%22%22%2C%22FirstName%22%3A%22Perffirst%22%2C%22PersonInfoKey%22%3A%22201712071040084252476117%22%2C%22Company%22%3A%22%22%7D%2C%22isHistory%22%3A%22N%22%2C%22Extn%22%3A%7B%22ExtnUSERTYPE%22%3A%22G%22%2C%22ExtnWebProfileId%22%3A%2250187741%22%7D%2C%22E"
		"nterpriseCode%22%3A%22USWS%22%2C%22OrderNo%22%3A%22H329194799%22%2C%22CustomerZipCode%22%3A%2210007%22%2C%22Status%22%3A%22Backordered%22%2C%22DocumentType%22%3A%220001%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22OrderName%22%3A%22%22%2C%22SellerOrganizationName%22%3A%22HP%20US%20Web%20Store%22%2C%22CustomerPONo%22%3A%22%22%2C%22CustomerLastName%22%3A%22Perflast%22%2C%22AuthorizedClient%22%3A%22WCS%22%2C%22MultipleStatusesExist%22%3A%22N%22%2C%22HoldFlag%22%3A%22Y%22%2"
		"C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%2C%22EntryType%22%3A%22Web%22%2C%22MaxOrderStatusDesc%22%3A%22Backordered%22%2C%22CustomerPhoneNo%22%3A%221234567890%22%2C%22OrderLines%22%3A%7B%22OrderLine%22%3A%5B%7B%22PersonalizeCode%22%3A%22%22%2C%22OrderHeaderKey%22%3A%22201712071150014252545659%22%2C%22IsPriceMatched%22%3A%22N%22%2C%22isHistory%22%3A%22N%22%2C%22Createprogid%22%3A%22HPSCWCIntegrationServer%22%2C%22Segment%22%3A%22%22%2C%22PrimeLineNo%22%3A%221%22%2C%22DeliveryMethod%22%3A%"
		"22SHP%22%2C%22SubLineNo%22%3A%221%22%2C%22ShipTogetherNo%22%3A%22%22%2C%22FulfillmentType%22%3A%22%22%2C%22ItemGroupCode%22%3A%22PROD%22%2C%22Timezone%22%3A%22%22%2C%22CustomerPONo%22%3A%22%22%2C%22MaintainRatio%22%3A%22%22%2C%22DeliveryCode%22%3A%22%22%2C%22FreightTerms%22%3A%22%22%2C%22BackorderNotificationQty%22%3A%220.00%22%2C%22PickableFlag%22%3A%22Y%22%2C%22OrderedQty%22%3A%221.00%22%2C%22OptionCapacityRequired%22%3A%220.00%22%2C%22OtherCharges%22%3A%220.00%22%2C%22CustomerLinePONo%22%3A%22%"
		"22%2C%22QuantityToSplit%22%3A%220.00%22%2C%22PipelineKey%22%3A%2220131111160246124658%22%2C%22Createuserid%22%3A%22HPSCWCIntegrationServer%22%2C%22CarrierServiceCode%22%3A%22%22%2C%22AddToOrderReleaseKey%22%3A%22%22%2C%22IsCostOverridden%22%3A%22N%22%2C%22FillQuantity%22%3A%220.00%22%2C%22Modifyprogid%22%3A%22SCHEDULE.0001%22%2C%22OverReceiptQuantity%22%3A%220.00%22%2C%22PackListType%22%3A%22%22%2C%22SplitQty%22%3A%220.00%22%2C%22WaitForSeqLine%22%3A%22N%22%2C%22DependencyRatio%22%3A%220.00%22%2C%"
		"22ParentOfDependentGroup%22%3A%22N%22%2C%22ApptStatus%22%3A%22%22%2C%22InvoiceComplete%22%3A%22N%22%2C%22SplitFromLineKey%22%3A%22%22%2C%22AllocationLeadTime%22%3A%220%22%2C%22PropagationQty%22%3A%220.00%22%2C%22LineType%22%3A%22%22%2C%22SCAC%22%3A%22%22%2C%22PricingDate%22%3A%222017-12-07%22%2C%22ConditionVariable1%22%3A%22%22%2C%22ConditionVariable2%22%3A%22%22%2C%22ShipNode%22%3A%22USDC01%22%2C%22DepartmentCode%22%3A%22%22%2C%22OrderingUOM%22%3A%22EACH%22%2C%22Modifyuserid%22%3A%22HPAgentServer"
		"%22%2C%22PersonalizeFlag%22%3A%22%22%2C%22IsStandaloneService%22%3A%22%22%2C%22ReceivedAsComponents%22%3A%22%22%2C%22FixedPricingQtyPerLine%22%3A%220.00%22%2C%22Extn%22%3A%7B%22ExtnGCNumber%22%3A%22%22%7D%2C%22ReservationMandatory%22%3A%22N%22%2C%22IntentionalBackorder%22%3A%22N%22%2C%22HoldReasonCode%22%3A%22%22%2C%22PropagationToParentRequired%22%3A%22%22%2C%22TranDiscrepancyQty%22%3A%220.00%22%2C%22Createts%22%3A%222017-12-07T11%3A50%3A00%2B00%3A00%22%2C%22ImportLicenseNo%22%3A%22%22%2C%22Canno"
		"tMeetAppt%22%3A%22%22%2C%22EarliestShipDate%22%3A%222017-12-07T11%3A50%3A00%2B00%3A00%22%2C%22InvoicedQuantity%22%3A%220.00%22%2C%22SchedFailureReasonCode%22%3A%22NOT_ENOUGH_PRODUCT_CHOICES%22%2C%22Lockid%22%3A%221%22%2C%22BasicCapacityRequired%22%3A%220.00%22%2C%22ReturnReason%22%3A%22%22%2C%22CanAddServiceLines%22%3A%22N%22%2C%22OrderLineKey%22%3A%22201712071150014252545662%22%2C%22IsBlindLine%22%3A%22Y%22%2C%22InvoiceBasedOnActuals%22%3A%22N%22%2C%22KitCode%22%3A%22%22%2C%22ReservationID%22%3A%"
		"22%22%2C%22LineSeqNo%22%3A%221.1%22%2C%22AllocationDate%22%3A%222017-12-07T00%3A00%3A00%2B00%3A00%22%2C%22SplitFromPrimeLineNo%22%3A%220%22%2C%22SplitFromSubLineNo%22%3A%220%22%2C%22EarliestDeliveryDate%22%3A%222017-12-07T11%3A50%3A00%2B00%3A00%22%2C%22CarrierAccountNo%22%3A%22%22%2C%22InvoicedExtendedPrice%22%3A%220.00%22%2C%22CapacityUOM%22%3A%22%22%2C%22Modifyts%22%3A%222017-12-07T11%3A51%3A04%2B00%3A00%22%2C%22OriginalOrderedQty%22%3A%221.00%22%2C%22GiftFlag%22%3A%22N%22%2C%22ShippedQuantity%2"
		"2%3A%220.00%22%2C%22TotalQtyToCancel%22%3A%220.00%22%2C%22ReservationPool%22%3A%22%22%2C%22FixedCapacityQtyPerLine%22%3A%220.00%22%2C%22OrderClass%22%3A%22NEW%22%2C%22HoldFlag%22%3A%22N%22%2C%22SegmentType%22%3A%22%22%2C%22IsFirmPredefinedNode%22%3A%22Y%22%2C%22ReceivedQty%22%3A%220.00%22%2C%22SerialNo%22%3A%22%22%2C%22TransactionalLineId%22%3A%22%22%2C%22IsCapacityOverridden%22%3A%22N%22%2C%22Purpose%22%3A%22%22%7D%5D%7D%2C%22DisplayStatus%22%3A%22Backordered%22%2C%22PriceInfo%22%3A%7B%22Currency"
		"%22%3A%22USD%22%2C%22TotalAmount%22%3A%221469.80%22%7D%2C%22TaxExemptionCertificate%22%3A%22%22%2C%22CustomerEMailID%22%3A%22perftestingestoretru%40mail.com%22%2C%22PersonInfoShipTo%22%3A%7B%22MiddleName%22%3A%22%22%2C%22LastName%22%3A%22Perflast%22%2C%22EveningPhone%22%3A%22%22%2C%22AddressLine1%22%3A%22Perfdrive%22%2C%22isHistory%22%3A%22N%22%2C%22AddressLine2%22%3A%22%22%2C%22City%22%3A%22Newyork%22%2C%22MobilePhone%22%3A%22%22%2C%22ZipCode%22%3A%2210007%22%2C%22AddressID%22%3A%22temp_chkOut_Pe"
		"rffirst1512647200144%22%2C%22PersonID%22%3A%22%22%2C%22Suffix%22%3A%22%22%2C%22State%22%3A%22NY%22%2C%22DayPhone%22%3A%221234567890%22%2C%22Department%22%3A%22%22%2C%22Country%22%3A%22US%22%2C%22EMailID%22%3A%22perftestingestoretru%40mail.com%22%2C%22Title%22%3A%22%22%2C%22FirstName%22%3A%22Perffirst%22%2C%22PersonInfoKey%22%3A%22201712071150014252545663%22%2C%22Company%22%3A%22%22%7D%2C%22OrderDate%22%3A%222017-12-07T11%3A47%3A09%2B00%3A00%22%2C%22CustomerFirstName%22%3A%22Perffirst%22%2C%22Selle"
		"rOrganizationCode%22%3A%22USWS%22%2C%22OverallStatus%22%3A%22%22%7D%7D%7D&scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		LAST);

	web_custom_request("AddressDisplay.html", 
		"URL=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/common/address/display/templates/AddressDisplay.html?scFlag=Y", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded", 
		LAST);

	web_custom_request("AddressDisplay.html_2", 
		"URL=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/common/address/display/identifiers/US/AddressDisplay.html?scFlag=Y", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded", 
		EXTRARES, 
		"Url=/isccs/dojo/gridx/resources/images/sprite_icons.png", "Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/dojo/gridx/resources/Gridx_opt.css?scetag=ac999baeff5f48550a409025b70ae2df813c6321", ENDITEM, 
		"Url=https://safebrowsing.googleapis.com/v4/fullHashes:find?$req=ChwKDGdvb2dsZWNocm9tZRIMNjIuMC4zMjAyLjk0GigIAQgCCAMIBggHCAgICQgKCA0QARAIGgYKBC4HU4sgASADIAQgBSAG&$ct=application/x-protobuf&key=AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw", "Referer=", ENDITEM, 
		"Url=/isccs/ibmjs/idx/themes/oneui/idx/form/images/buttonIcons.png", "Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/ibmjs/idx/themes/oneui/oneui_opt.css?scetag=6f44c2812a532466be224d4a5f005d9db3248601", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Action=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCompleteShipmentDetails\",\"Input\":{\"Order\":{\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\",\"OrderHeaderKey\":\"201712071150014252545659\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1512721390372jRCx1Sk6LfrGSulrM6jehp", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryBehaviorController.do", 
		"Action=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCommonCodeList\",\"Input\":{\"CommonCodeList\":{\"CodeType\":\"CarrierServiceCode\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1512721390372jRCx1Sk6LfrGSulrM6jehp", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryLinesBehaviorController.do_2", 
		"Action=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCompleteOrderLineList\",\"scPaginationStrategy\":\"NEXTPAGE\",\"scPageSize\":10,\"scPageNumber\":1,\"scPreviousPageRecord\":{},\"Input\":{\"OrderLine\":{\"OrderHeaderKey\":\"201712071150014252545659\",\"Order\":{\"EnterpriseCode\":\"USWS\",\"SellerOrganizationCode\":\"USWS\"}}}}"
		"]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1512721390372jRCx1Sk6LfrGSulrM6jehp", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		EXTRARES, 
		"Url=/isccs/isccs/resources/css/icons/images/icon-selected.png", "Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", ENDITEM, 
		"Url=/isccs/isccs/resources/css/icons/images/orderhold.png", "Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", ENDITEM, 
		"Url=/isccs//isccs/resources/css/icons/images/priceOverridden.png", "Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.editors.OrderEditorRTBehaviorController.do", 
		"Action=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorRTBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorRTBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorRTBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getOrderDetailsForCustomer\",\"Input\":{\"Order\":{\"OrderNo\":\"H329194799\",\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1512721390372jRCx1Sk6LfrGSulrM6jehp", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryBehaviorController.do_2", 
		"Action=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_pricingSummary\",\"Input\":{\"Order\":{\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\",\"OrderHeaderKey\":\"201712071150014252545659\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1512721390372jRCx1Sk6LfrGSulrM6jehp", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.editors.OrderEditorRTBehaviorController.do_2", 
		"Action=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorRTBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecomtran-sterling-uat2.houston.hp.com/isccs/isccs/container/home.do?scCSRFToken=1512721390372jRCx1Sk6LfrGSulrM6jehp&scFlag=Y", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorRTBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorRTBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_customerDetails\",\"Input\":{\"Customer\":{\"CustomerKey\":\"perftestingestoretru@mail.com\",\"OrganizationCode\":\"USWS\",\"CustomerID\":\"WCS\",\"CustomerType\":\"02\",\"IgnoreOrdering\":\"Y\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1512721390372jRCx1Sk6LfrGSulrM6jehp", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("clk_findorder",LR_AUTO);

	web_custom_request("update2", 
		"URL=https://update.googleapis.com/service/update2?cup2key=7:3882411754&cup2hreq=43b0d5dcd35102ec1cafd0ba2efeacf945e309a2029cd6f098172d557064b0ac", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		"EncType=application/xml", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><request protocol=\"3.1\" dedup=\"cr\" acceptformat=\"crx2,crx3\" version=\"chrome-62.0.3202.94\" prodversion=\"62.0.3202.94\" requestid=\"{2e0c0cf1-183b-47fc-ada8-a6ddf9912753}\" lang=\"en-US\" updaterchannel=\"\" prodchannel=\"\" os=\"win\" arch=\"x64\" nacl_arch=\"x86-64\" domainjoined=\"1\"><hw physmemory=\"64\"/><os platform=\"Windows\" arch=\"x86_64\" version=\"6.1.7601.23934\" sp=\"Service Pack 1\"/><updater autoupdatecheckenabled=\"1\" "
		"lastchecked=\"0\" laststarted=\"0\" name=\"Omaha\" updatepolicy=\"-1\" version=\"1.3.33.7\"/><app appid=\"oimompecagnajdejgnnjijobebaeigek\" version=\"1.4.8.1029\" brand=\"GGLS\"><updatecheck/><ping rd=\"3991\" ping_freshness=\"{03ee606a-b384-44c9-9fd2-a4c7bd6acb4f}\"/></app><app appid=\"hnimpnehoodheedghdeeijklkeaacbdc\" version=\"0.57.44.2492\" brand=\"GGLS\"><updatecheck/><ping rd=\"3991\" ping_freshness=\"{c8d255d6-33c6-47b5-ad60-cb51624d78ad}\"/><packages><package fp=\""
		"1.1cd7dc2056afaa0f6a705c9a17d22bba6578b33f5dae9e2d6518a0bfcced2396\"/></packages></app><app appid=\"gcmjkmgdlgnkkcocmoeiminaijmmjnii\" version=\"7.54\" brand=\"GGLS\" cohort=\"1:bm1:\" cohortname=\"M54AndAbove\"><updatecheck/><ping rd=\"3991\" ping_freshness=\"{6ef25f00-6049-4bae-ad5f-d75da089e99a}\"/><packages><package fp=\"1.e5ac6a4f2e3fd1eef8a61bf912c880dcbe57adcee6415d892c84e7e85ea476dc\"/></packages></app><app appid=\"hfnkpimlhhgieaddgfemjhofmfblmnib\" version=\"4138\" brand=\"GGLS\" cohort="
		"\"1:jcl:\" cohortname=\"Auto\"><updatecheck/><ping rd=\"3991\" ping_freshness=\"{539bad5e-5868-46e9-b61e-ac5b0dadb3c3}\"/></app><app appid=\"llkgjffcdpffmhiakmfcdcblohccpfmo\" version=\"0.0.0.0\" brand=\"GGLS\"><updatecheck/><ping rd=\"3991\" ping_freshness=\"{30259580-56e9-498f-be8e-31c65a3fe83e}\"/></app><app appid=\"mimojjlkmoijpicakmndhoigimigcmbb\" version=\"27.0.0.187\" brand=\"GGLS\" cohort=\"1:d0j:\" cohortname=\"Chrome [M50... M99]\"><updatecheck/><ping rd=\"3991\" ping_freshness=\""
		"{8ca4069f-46a2-4322-9c24-0b717c3f7279}\"/><packages><package fp=\"1.d99d67d0d35496e2893287ee63f467cfa8a2278aa45435536b24814cab1549f6\"/></packages></app><app appid=\"giekcmmlnklenlaomppkphknjmnnpneh\" version=\"4\" brand=\"GGLS\" cohort=\"1:j5l:\" cohortname=\"Auto\"><updatecheck/><ping rd=\"3991\" ping_freshness=\"{8be77acd-81a2-492e-aaeb-c0af17b53813}\"/><packages><package fp=\"1.3e0bc577e6a70f1ee3aea6e88b1d6e9390695692881a998f4c0e3c6d7cab7ad5\"/></packages></app><app appid=\""
		"khaoiebndkojlmppeemjhbpbandiljpe\" version=\"14\" brand=\"GGLS\" cohort=\"1:cux:\" cohortname=\"Auto\"><updatecheck/><ping rd=\"3991\" ping_freshness=\"{29f8d99c-cf59-450b-9df4-7904dfa034fa}\"/><packages><package fp=\"1.d7c36605203ab964e78695e5dbfe1253a0097a3b2f5fff882bbf51b7a240b45e\"/></packages></app><app appid=\"gkmgaooipdjhmangpemjhigmamcehddo\" version=\"23.135.200\" brand=\"GGLS\" tag=\"stable_eset\" cohort=\"1:lsl:\" cohortname=\"ESET Stable\"><updatecheck/><ping rd=\"3991\" ping_freshness"
		"=\"{fc996b67-2dd8-4349-99a0-91496a70ad33}\"/><packages><package fp=\"1.f3c7f9772f0086e6a063b747340fcef0a8de058f25503d6b434522320decc495\"/></packages></app><app appid=\"ojjgnpkioondelmggbekfhllhdaimnho\" version=\"591\" brand=\"GGLS\" cohort=\"1:0:\" cohortname=\"Auto\"><updatecheck/><ping rd=\"3991\" ping_freshness=\"{0aedf2d8-f281-4be7-8370-4d7cba4df9a0}\"/><packages><package fp=\"1.a8f486a63dea14fa219e657b8c4a4d0cc3cadabf4f9f208a621f22fd160acd02\"/></packages></app><app appid=\""
		"npdjjkjlcidkjlamlmmdelcjbcpdjocm\" version=\"0.0.0.0\" brand=\"GGLS\"><updatecheck/><ping rd=\"3991\" ping_freshness=\"{6ffacaa9-6251-44ce-a090-6157287fc2e0}\"/></app></request>", 
		EXTRARES, 
		"Url=http://r3---sn-q4flrnes.gvt1.com/edgedl/release2/chrome_component/C6i2DLqLB1A_4143/4143_all_crl-set-delta-4138-4129474611280194260.data.crx3?cms_redirect=yes&expire=1512736102&ip=15.65.252.11&ipbits=0&mm=28&mn=sn-q4flrnes&ms=nvh&mt=1512721520&mv=m&pl=21&shardbypass=yes&sparams=expire,ip,ipbits,mm,mn,ms,mv,pl,shardbypass&signature=672807497A9CB679AA9C2B4CB588D0BF3F62EC27.5485897D71E4789C9618A78175B4E2020CA82131&key=cms1", "Referer=", ENDITEM, 
		LAST);

	web_custom_request("update2_2", 
		"URL=https://update.googleapis.com/service/update2", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"EncType=application/xml", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><request protocol=\"3.1\" dedup=\"cr\" acceptformat=\"crx2,crx3\" version=\"chrome-62.0.3202.94\" prodversion=\"62.0.3202.94\" requestid=\"{5515984b-0e43-47a0-8283-39681db25738}\" lang=\"en-US\" updaterchannel=\"\" prodchannel=\"\" os=\"win\" arch=\"x64\" nacl_arch=\"x86-64\"><hw physmemory=\"64\"/><os platform=\"Windows\" arch=\"x86_64\" version=\"6.1.7601.23934\" sp=\"Service Pack 1\"/><app appid=\"hfnkpimlhhgieaddgfemjhofmfblmnib\" version=\"4138\""
		" nextversion=\"4143\"><event eventtype=\"14\" eventresult=\"1\" downloader=\"direct\" url=\"http://redirector.gvt1.com/edgedl/release2/chrome_component/C6i2DLqLB1A_4143/4143_all_crl-set-delta-4138-4129474611280194260.data.crx3\" downloaded=\"6858\" total=\"6858\" download_time_ms=\"2222\"/><event eventtype=\"3\" eventresult=\"1\" nextfp=\"1.f2950fcab39642a1ff5006e200f9f91429e5a70451d30d004c6924a7b7bba0c0\"/></app></request>", 
		LAST);

	lr_think_time(25);

	web_custom_request("update2_3", 
		"URL=https://update.googleapis.com/service/update2", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"EncType=application/xml", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><request protocol=\"3.1\" dedup=\"cr\" acceptformat=\"crx2,crx3\" version=\"chrome-62.0.3202.94\" prodversion=\"62.0.3202.94\" requestid=\"{6d01a2b7-d502-4d5b-9027-eecfa0adb551}\" lang=\"en-US\" updaterchannel=\"\" prodchannel=\"\" os=\"win\" arch=\"x64\" nacl_arch=\"x86-64\"><hw physmemory=\"64\"/><os platform=\"Windows\" arch=\"x86_64\" version=\"6.1.7601.23934\" sp=\"Service Pack 1\"/><app appid=\"gkmgaooipdjhmangpemjhigmamcehddo\" version=\""
		"23.135.200\" nextversion=\"24.136.201\"><event eventtype=\"14\" eventresult=\"1\" downloader=\"bits\" url=\"http://redirector.gvt1.com/edgedl/release2/chrome_component/BTVPp0Ebtk0_24.136.201/24.136.201_win64_SoftwareReporter.crx3\" downloaded=\"5555154\" total=\"5555154\" download_time_ms=\"24102\"/><event eventtype=\"3\" eventresult=\"1\" previousfp=\"1.f3c7f9772f0086e6a063b747340fcef0a8de058f25503d6b434522320decc495\" nextfp=\"1.c209b4af59e1d1355688a15e08f804c2a112f903ad27e150a02cbb3b0fd57d6f\"/"
		"></app></request>", 
		LAST);

	lr_think_time(28);

	web_custom_request("update2_4", 
		"URL=https://update.googleapis.com/service/update2", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		"EncType=application/xml", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><request protocol=\"3.1\" dedup=\"cr\" acceptformat=\"crx2,crx3\" version=\"chrome-62.0.3202.94\" prodversion=\"62.0.3202.94\" requestid=\"{fb97230c-157b-44a7-aeaa-80cecfadf849}\" lang=\"en-US\" updaterchannel=\"\" prodchannel=\"\" os=\"win\" arch=\"x64\" nacl_arch=\"x86-64\"><hw physmemory=\"64\"/><os platform=\"Windows\" arch=\"x86_64\" version=\"6.1.7601.23934\" sp=\"Service Pack 1\"/><app appid=\"ojjgnpkioondelmggbekfhllhdaimnho\" version=\"591\" "
		"nextversion=\"593\"><event eventtype=\"14\" eventresult=\"1\" downloader=\"bits\" url=\"http://redirector.gvt1.com/edgedl/release2/chrome_component/AOaoyH4YM6As_593/593_all_sthset.crx3\" downloaded=\"15184\" total=\"15184\" download_time_ms=\"4031\"/><event eventtype=\"3\" eventresult=\"1\" previousfp=\"1.a8f486a63dea14fa219e657b8c4a4d0cc3cadabf4f9f208a621f22fd160acd02\" nextfp=\"1.026336d5319da7fed0089d037473d9f74ed052737f82da07d2e04fefb65e6f3a\"/></app></request>", 
		LAST);

	return 0;
}
