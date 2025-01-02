/* -------------------------------------------------------------------------------
	Script Title       : 
	Script Description : 
                        
                        
	Recorder Version   : 0
   ------------------------------------------------------------------------------- */

vuser_init()
{

	lr_start_transaction("C00_Homepage");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_url("login.do", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/login.do", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("LoginFrame.html", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/app/templates/LoginFrame.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/login.do", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_custom_request("Dialog.html", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/ibmjs/idx/widget/templates/Dialog.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/login.do", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("HoverHelpTooltip.html", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/ibmjs/idx/widget/templates/HoverHelpTooltip.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/login.do", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_custom_request("TextBox.html", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/ibmjs/idx/form/templates/TextBox.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/login.do", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("C00_Homepage",LR_AUTO);

	lr_start_transaction("C01_AgentLogin");

	web_submit_data("processLogin.do", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/processLogin.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/login.do", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=DisplayUserID", "Value=smbetr1Perfuser0201", ENDITEM, 
		"Name=Password", "Value=Passw0rd1", ENDITEM, 
		"Name=EnterpriseCode", "Value=", ENDITEM, 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("TextBox.html_2", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/ibmjs/idx/form/templates/TextBox.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_custom_request("CheckBox.html", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/ibmjs/idx/form/templates/CheckBox.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("ComboBox.html", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/ibmjs/idx/form/templates/ComboBox.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_custom_request("Textarea.html", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/ibmjs/idx/form/templates/Textarea.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("CurrencyTextBox.html", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/ibmjs/idx/form/templates/CurrencyTextBox.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("RadioButtonSet.html", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/ibmjs/idx/form/templates/RadioButtonSet.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("CheckBoxList.html", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/ibmjs/idx/form/templates/CheckBoxList.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("SCIAjax", 
		"Y");

	web_add_auto_header("SCIVer", 
		"0.9");

	web_submit_data("isccs.home.HomeInitController.do", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.home.HomeInitController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerInput", "Value={}", ENDITEM, 
		"Name=scControllerData", "Value={\"isccs_home_HomeInitController\":{\"controllerId\":\"isccs_home_HomeInitController\",\"MashupRefs\":{\"MashupRef\":[]},\"ChildControllers\":{\"ChildController\":[{\"controllerId\":\"isccs_home_portlets_OrderPortletInitController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrganizationList\",\"Input\":{},\"mashupRefObj\":{\"sourceNamespace\":\"getOrganizationList_output\",\"callSequence\":\"\",\"mashupRefId\":\"getOrganizationList\",\"sequence\":\"\",\""
		"sourceBindingOptions\":\"\",\"mashupId\":\"orderPortlet_getOrganizationList\"}}]}},{\"controllerId\":\"isccs_home_portlets_CustomerPortletInitController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCustomerOrganizationList\",\"Input\":{},\"mashupRefObj\":{\"sourceNamespace\":\"getHomeCustomerOrganizationList_output\",\"callSequence\":\"\",\"mashupRefId\":\"getCustomerOrganizationList\",\"sequence\":\"4\",\"sourceBindingOptions\":\"\",\"mashupId\":\"customerSearch_getOrganizationList\"}},"
		"{\"mashupRefId\":\"getDisplayRuleDetails\",\"Input\":{},\"mashupRefObj\":{\"sourceNamespace\":\"getHomeDisplayCustomerTypeRule_output\",\"callSequence\":\"\",\"mashupRefId\":\"getDisplayRuleDetails\",\"sequence\":\"6\",\"sourceBindingOptions\":\"\",\"mashupId\":\"customerSearch_getDisplayCustomerTypeRule\"}},{\"mashupRefId\":\"getDefaultRuleDetails\",\"Input\":{},\"mashupRefObj\":{\"sourceNamespace\":\"getHomeDefaultCustomerTypeRule_output\",\"callSequence\":\"\",\"mashupRefId\":\""
		"getDefaultRuleDetails\",\"sequence\":\"5\",\"sourceBindingOptions\":\"\",\"mashupId\":\"customerSearch_getDefaultCustomerTypeRule\"}}]}},{\"controllerId\":\"isccs_home_portlets_ReturnsPortletInitController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getReturnOrganizationList\",\"Input\":{},\"mashupRefObj\":{\"sourceNamespace\":\"getOrganizationList_output\",\"callSequence\":\"\",\"mashupRefId\":\"getReturnOrganizationList\",\"sequence\":\"\",\"sourceBindingOptions\":\"\",\"mashupId\":\""
		"orderPortlet_getOrganizationList\"}}]}},{\"controllerId\":\"isccs_home_portlets_ProductPortletInitController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrgList\",\"Input\":{},\"mashupRefObj\":{\"sourceNamespace\":\"enterpriseList\",\"callSequence\":\"\",\"mashupRefId\":\"getOrgList\",\"sequence\":\"\",\"sourceBindingOptions\":\"\",\"mashupId\":\"productBrowsing_getOrganizationList\"}}]}},{\"controllerId\":\"isccs_home_portlets_CouponPortletInitController\",\"MashupRefs\":{\"MashupRef\""
		":[{\"mashupRefId\":\"getOrgList\",\"Input\":{},\"mashupRefObj\":{\"cached\":\"PAGE\",\"sourceNamespace\":\"enterpriseList\",\"mashupRefId\":\"getOrgList\",\"mashupId\":\"orderPortlet_getOrganizationList\"}}]}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_revert_auto_header("SCIAjax");

	web_revert_auto_header("SCIVer");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("isccs.editors.HomeEditorBehaviorController.do", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.editors.HomeEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_HomeEditorBehaviorController\":{\"controllerId\":\"isccs_editors_HomeEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getEnterpriseList\",\"Input\":{\"Organization\":{}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_add_auto_header("SCIAjax", 
		"Y");

	web_add_auto_header("SCIVer", 
		"0.9");

	web_submit_data("isccs.home.portlets.MyAlertsPortletBehaviorController.do", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.home.portlets.MyAlertsPortletBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_home_portlets_MyAlertsPortletBehaviorController\":{\"controllerId\":\"isccs_home_portlets_MyAlertsPortletBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getMyAlertsAndQueues\",\"Input\":{\"getAlertStatisticsForUser\":{}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C01_AgentLogin",LR_AUTO);

	lr_start_transaction("C50_FindOrder");

	web_submit_data("isccs.home.portlets.OrderPortletBehaviorController.do", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.home.portlets.OrderPortletBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_home_portlets_OrderPortletBehaviorController\":{\"controllerId\":\"isccs_home_portlets_OrderPortletBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getOrderList\",\"Input\":{\"Order\":{\"EnterpriseCode\":\"USWS\",\"OrderNo\":\"H360004208\",\"MaximumRecords\":\"2\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_custom_request("wizardController.do", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=isccs.order.wizards.orderSummary.OrderSummaryWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22isccs.order.wizards.orderSummary.OrderSummaryWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EntryType%22%3A%22Web%22%2C%22CustomerFirstName%22%3A%22Firstthree%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22MultipleStatusesExist%22%3A%22N%22%2C%22AuthorizedClient%22%3A%22WCS%22%2C%22Extn%22%3A%7B%22ExtnWebProfileId%22%3A%22110283043%22%2C%22ExtnUSERTYPE%22%3A%22G%22%7D%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%2C%22Ta"
		"xExemptionCertificate%22%3A%22%22%2C%22PriceInfo%22%3A%7B%22TotalAmount%22%3A%222300.49%22%2C%22Currency%22%3A%22USD%22%7D%2C%22OrderNo%22%3A%22H360004208%22%2C%22CustomerPhoneNo%22%3A%221234567890%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22CustomerEMailID%22%3A%22perteststore20201203064815.912%40hmail.com%22%2C%22PersonInfoBillTo%22%3A%7B%22EMailID%22%3A%22perteststore20201203064815.912%40hmail.com%22%2C%22PersonInfoKey%22%3A%22202012030700194136576337%22%2C%22Suffix%22%3A%22%22%2C%22Country%22%3A%"
		"22US%22%2C%22DayPhone%22%3A%221234567890%22%2C%22LastName%22%3A%22Lastthree%22%2C%22ZipCode%22%3A%2234983%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22Port%20St%20Lucie%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22FL%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22Firstthree%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22NA%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%"
		"22%3A%22%22%7D%2C%22DocumentType%22%3A%220001%22%2C%22MaxOrderStatusDesc%22%3A%22Shipment%20Line%20Invoiced%22%2C%22MinOrderStatus%22%3A%223700.100%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22OrderHeaderKey%22%3A%22202012030700194136576194%22%2C%22CustomerPONo%22%3A%22%22%2C%22OrderDate%22%3A%222020-12-03T06%3A55%3A54%2B00%3A00%22%2C%22DisplayStatus%22%3A%22Shipment%20Line%20Invoiced%22%2C%22OverallStatus%22%3A%22%22%2C%22MaxOrderStatus%22%3A%223700.100%22%2C%22SellerOrganizationName%22%3A%22HP%20US%2"
		"0Web%20Store%22%2C%22PersonInfoShipTo%22%3A%7B%22EMailID%22%3A%22perteststore20201203064815.912%40hmail.com%22%2C%22PersonInfoKey%22%3A%22202012030700194136576218%22%2C%22Suffix%22%3A%22%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%221234567890%22%2C%22LastName%22%3A%22Lastthree%22%2C%22ZipCode%22%3A%2234983-3336%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22Port%20St%20Lucie%22%2C%22AddressID%22%3A%22EStore_STOO_GC_1606978367581%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22FL%22%2C%22Pers"
		"onID%22%3A%22%22%2C%22FirstName%22%3A%22Firstthree%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22Status%22%3A%22Shipment%20Line%20Invoiced%22%2C%22CustomerLastName%22%3A%22Lastthree%22%2C%22HoldFlag%22%3A%22N%22%2C%22CustomerZipCode%22%3A%2234983%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22OrderLines%22%3A%7B%2"
		"2OrderLine%22%3A%5B%7B%22IntentionalBackorder%22%3A%22N%22%2C%22InvoicedQuantity%22%3A%221.00%22%2C%22ItemGroupCode%22%3A%22PROD%22%2C%22OptionCapacityRequired%22%3A%220.00%22%2C%22Extn%22%3A%7B%22ExtnGCNumber%22%3A%22%22%7D%2C%22SegmentType%22%3A%22%22%2C%22Timezone%22%3A%22%22%2C%22ImportLicenseNo%22%3A%22%22%2C%22ReturnReason%22%3A%22%22%2C%22ReservationID%22%3A%22%22%2C%22PipelineKey%22%3A%2220131111160246124658%22%2C%22TranDiscrepancyQty%22%3A%220.00%22%2C%22TotalQtyToCancel%22%3A%220.00%22%2"
		"C%22CannotMeetAppt%22%3A%22%22%2C%22Purpose%22%3A%22%22%2C%22DependencyRatio%22%3A%220.00%22%2C%22DeliveryMethod%22%3A%22SHP%22%2C%22Lockid%22%3A%223%22%2C%22ReservationPool%22%3A%22%22%2C%22PersonalizeCode%22%3A%22%22%2C%22Segment%22%3A%22%22%2C%22OrderLineKey%22%3A%22202012030700194136576196%22%2C%22IsFirmPredefinedNode%22%3A%22Y%22%2C%22KitCode%22%3A%22%22%2C%22Createprogid%22%3A%22HPSCWCIntegrationServer%22%2C%22PrimeLineNo%22%3A%221%22%2C%22InvoiceBasedOnActuals%22%3A%22N%22%2C%22CustomerLine"
		"PONo%22%3A%22%22%2C%22LineType%22%3A%22%22%2C%22HoldFlag%22%3A%22N%22%2C%22BasicCapacityRequired%22%3A%220.00%22%2C%22SplitFromLineKey%22%3A%22%22%2C%22IsCostOverridden%22%3A%22N%22%2C%22PickableFlag%22%3A%22Y%22%2C%22Modifyprogid%22%3A%22CREATE_SHMNT_INVOICE.0001%22%2C%22Modifyuserid%22%3A%22HPAgentServer%22%2C%22ConditionVariable2%22%3A%22%22%2C%22ConditionVariable1%22%3A%22%22%2C%22ShipTogetherNo%22%3A%22%22%2C%22ShippedQuantity%22%3A%221.00%22%2C%22Modifyts%22%3A%222020-12-09T05%3A11%3A04%2B00"
		"%3A00%22%2C%22OrderedQty%22%3A%221.00%22%2C%22QuantityToSplit%22%3A%220.00%22%2C%22PackListType%22%3A%22%22%2C%22ReceivedAsComponents%22%3A%22%22%2C%22DepartmentCode%22%3A%22%22%2C%22HoldReasonCode%22%3A%22%22%2C%22SCAC%22%3A%22%22%2C%22Createuserid%22%3A%22HPSCWCIntegrationServer%22%2C%22CustomerPONo%22%3A%22%22%2C%22TransactionalLineId%22%3A%22%22%2C%22EarliestShipDate%22%3A%222020-12-03T07%3A00%3A19%2B00%3A00%22%2C%22IsPriceMatched%22%3A%22N%22%2C%22BackorderNotificationQty%22%3A%220.00%22%2C%2"
		"2InvoiceComplete%22%3A%22Y%22%2C%22PropagationToParentRequired%22%3A%22%22%2C%22SubLineNo%22%3A%221%22%2C%22GiftFlag%22%3A%22N%22%2C%22ReceivedQty%22%3A%220.00%22%2C%22ApptStatus%22%3A%22%22%2C%22CapacityUOM%22%3A%22%22%2C%22FixedPricingQtyPerLine%22%3A%220.00%22%2C%22SplitFromPrimeLineNo%22%3A%220%22%2C%22IsCapacityOverridden%22%3A%22N%22%2C%22FixedCapacityQtyPerLine%22%3A%220.00%22%2C%22EarliestDeliveryDate%22%3A%222020-12-03T07%3A00%3A19%2B00%3A00%22%2C%22PricingDate%22%3A%222020-12-03%22%2C%22"
		"FreightTerms%22%3A%22%22%2C%22CarrierAccountNo%22%3A%22%22%2C%22MaintainRatio%22%3A%22%22%2C%22SplitQty%22%3A%220.00%22%2C%22Createts%22%3A%222020-12-03T07%3A00%3A19%2B00%3A00%22%2C%22FillQuantity%22%3A%220.00%22%2C%22OrderClass%22%3A%22NEW%22%2C%22OverReceiptQuantity%22%3A%220.00%22%2C%22ShipNode%22%3A%22USDC01%22%2C%22CarrierServiceCode%22%3A%22%22%2C%22OtherCharges%22%3A%220.00%22%2C%22SchedFailureReasonCode%22%3A%22%22%2C%22WaitForSeqLine%22%3A%22N%22%2C%22SerialNo%22%3A%22%22%2C%22CanAddServi"
		"ceLines%22%3A%22N%22%2C%22PropagationQty%22%3A%220.00%22%2C%22LineSeqNo%22%3A%221.1%22%2C%22OrderHeaderKey%22%3A%22202012030700194136576194%22%2C%22OrderingUOM%22%3A%22EACH%22%2C%22OriginalOrderedQty%22%3A%221.00%22%2C%22IsStandaloneService%22%3A%22%22%2C%22SplitFromSubLineNo%22%3A%220%22%2C%22AddToOrderReleaseKey%22%3A%22%22%2C%22DeliveryCode%22%3A%22%22%2C%22ReservationMandatory%22%3A%22N%22%2C%22PersonalizeFlag%22%3A%22%22%2C%22InvoicedExtendedPrice%22%3A%222149.99%22%2C%22isHistory%22%3A%22N%2"
		"2%2C%22FulfillmentType%22%3A%22%22%2C%22ParentOfDependentGroup%22%3A%22N%22%7D%5D%7D%2C%22isHistory%22%3A%22N%22%2C%22OrderName%22%3A%22%22%7D%7D%7D&scCSRFToken=1607507008337cfdjunHbqZqRNZ9zvzmXETA&scFlag=Y", 
		LAST);

	web_custom_request("AddressDisplay.html", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/common/address/display/templates/AddressDisplay.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("isccs.editors.OrderEditorBehaviorController.do", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getEnterpriseList\",\"Input\":{\"Organization\":{}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_revert_auto_header("SCIAjax");

	web_revert_auto_header("SCIVer");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("isccs.editors.OrderEditorBehaviorController.do_2", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getRequiredEditorAttributes\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"202012030700194136576194\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("SCIAjax", 
		"Y");

	web_add_auto_header("SCIVer", 
		"0.9");

	web_submit_data("isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryLinesBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryLinesBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCompleteShipmentDetails\",\"Input\":{\"Order\":{\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\",\"OrderHeaderKey\":\"202012030700194136576194\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_revert_auto_header("SCIAjax");

	web_revert_auto_header("SCIVer");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("AddressDisplay.html_2", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/common/address/display/identifiers/US/AddressDisplay.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("SCIAjax", 
		"Y");

	web_add_auto_header("SCIVer", 
		"0.9");

	web_submit_data("isccs.order.details.OrderSummaryBehaviorController.do", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getCommonCodeList\",\"Input\":{\"CommonCodeList\":{\"CodeType\":\"CarrierServiceCode\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.editors.OrderEditorRTBehaviorController.do", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorRTBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorRTBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorRTBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_getOrderDetailsForCustomer\",\"Input\":{\"Order\":{\"OrderNo\":\"H360004208\",\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.details.OrderSummaryBehaviorController.do_2", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.details.OrderSummaryBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_pricingSummary\",\"Input\":{\"Order\":{\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\",\"OrderHeaderKey\":\"202012030700194136576194\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_revert_auto_header("SCIAjax");

	web_revert_auto_header("SCIVer");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("isccs.editors.OrderEditorRTBehaviorController.do_2", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorRTBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorRTBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorRTBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_customerDetails\",\"Input\":{\"Customer\":{\"CustomerKey\":\"perteststore20201203064815.912@hmail.com\",\"OrganizationCode\":\"USWS\",\"CustomerID\":\"WCS\",\"CustomerType\":\"02\",\"IgnoreOrdering\":\"Y\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C50_FindOrder",LR_AUTO);

	lr_start_transaction("C51-1_MC_ManageCharges");

	web_add_auto_header("SCIAjax", 
		"Y");

	web_add_auto_header("SCIVer", 
		"0.9");

	web_custom_request("wizardController.do_2", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/wizardController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"Body=scWizardDefId=extn.wizards.addModifyCharges.HPAddModifyChargesWizard&isWizard=true&wizardData="
		"%7B%22scWizardDefId%22%3A%22extn.wizards.addModifyCharges.HPAddModifyChargesWizard%22%2C%22isWizard%22%3Atrue%2C%22scControllerInput%22%3A%7B%22Order%22%3A%7B%22EntryType%22%3A%22Web%22%2C%22CustomerFirstName%22%3A%22Firstthree%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22AuthorizedClient%22%3A%22WCS%22%2C%22Extn%22%3A%7B%22ExtnWebProfileId%22%3A%22110283043%22%2C%22ExtnUSERTYPE%22%3A%22G%22%7D%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%2C%22TaxExemptionCertificate%22%3A%22%22%2C%"
		"22PriceInfo%22%3A%7B%22TotalAmount%22%3A%222300.49%22%2C%22Currency%22%3A%22USD%22%7D%2C%22OrderNo%22%3A%22H360004208%22%2C%22CustomerPhoneNo%22%3A%221234567890%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22CustomerEMailID%22%3A%22perteststore20201203064815.912%40hmail.com%22%2C%22PersonInfoBillTo%22%3A%7B%22EMailID%22%3A%22perteststore20201203064815.912%40hmail.com%22%2C%22PersonInfoKey%22%3A%22202012030700194136576337%22%2C%22Suffix%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%22Country%22%3A%22US%2"
		"2%2C%22DayPhone%22%3A%221234567890%22%2C%22LastName%22%3A%22Lastthree%22%2C%22ZipCode%22%3A%2234983%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22Port%20St%20Lucie%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22FL%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22Firstthree%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22NA%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%"
		"22%22%7D%2C%22DocumentType%22%3A%220001%22%2C%22MaxOrderStatusDesc%22%3A%22Shipment%20Line%20Invoiced%22%2C%22MinOrderStatus%22%3A%223700.100%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22OrderHeaderKey%22%3A%22202012030700194136576194%22%2C%22CustomerPONo%22%3A%22%22%2C%22DisplayStatus%22%3A%22Draft%20Order%20Created%22%2C%22DisplayEntryType%22%3A%22Web%22%2C%22MaxOrderStatus%22%3A%223700.100%22%2C%22SellerOrganizationName%22%3A%22HP%20US%20Web%20Store%22%2C%22PersonInfoShipTo%22%3A%7B%22EMailID%22%3A%"
		"22perteststore20201203064815.912%40hmail.com%22%2C%22PersonInfoKey%22%3A%22202012030700194136576218%22%2C%22Suffix%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%22LastName%22%3A%22Lastthree%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%221234567890%22%2C%22ZipCode%22%3A%2234983-3336%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22Port%20St%20Lucie%22%2C%22AddressID%22%3A%22EStore_STOO_GC_1606978367581%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22FL%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%"
		"22%3A%22Firstthree%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22CustomerLastName%22%3A%22Lastthree%22%2C%22CustomerZipCode%22%3A%2234983%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22isHistory%22%3A%22N%22%2C%22OrderName%22%3A%22%22%7D%7D%7D&scCSRFToken=1607507008337cfdjunHbqZqRNZ9zvzmXETA&scFlag=Y", 
		LAST);

	web_custom_request("OrderTotal_NoOrderPricingSummaryLink.html", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/order/details/templates/OrderTotal_NoOrderPricingSummaryLink.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("isccs.editors.OrderEditorBehaviorController.do_3", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.editors.OrderEditorBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_editors_OrderEditorBehaviorController\":{\"controllerId\":\"isccs_editors_OrderEditorBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getRequiredEditorAttributes\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"202012030700194136576194\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_revert_auto_header("SCIAjax");

	web_revert_auto_header("SCIVer");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("isccs.order.details.OrderPricingSummaryLinesBehaviorController.do", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.details.OrderPricingSummaryLinesBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_order_details_OrderPricingSummaryLinesBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_order_details_OrderPricingSummaryLinesBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22getCompleteOrderLineList%22%2C%22scPaginationStrategy%22%3A%22NEXTPAGE%22%2C%22scPageSize%22%3A10%2C%22scPageNumber%22%3A1%2C%22scPreviousPageRecord%22%3A%7B%7D%2C%22Input%22%3A%7B%22OrderLine%22%3A%7B%22Order%22%3A%7B%22EnterpriseCode%22%3A%22USWS%22%7D%2C%22Orde"
		"rHeaderKey%22%3A%22202012030700194136576194%22%7D%7D%7D%5D%7D%7D%7D&scControllerInput="
		"%7B%22Order%22%3A%7B%22EntryType%22%3A%22Web%22%2C%22CustomerFirstName%22%3A%22Firstthree%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22AuthorizedClient%22%3A%22WCS%22%2C%22Extn%22%3A%7B%22ExtnWebProfileId%22%3A%22110283043%22%2C%22ExtnUSERTYPE%22%3A%22G%22%7D%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%2C%22TaxExemptionCertificate%22%3A%22%22%2C%22PriceInfo%22%3A%7B%22TotalAmount%22%3A%222300.49%22%2C%22Currency%22%3A%22USD%22%7D%2C%22OrderNo%22%3A%22H360004208%22%2C%22CustomerPhon"
		"eNo%22%3A%221234567890%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22CustomerEMailID%22%3A%22perteststore20201203064815.912%40hmail.com%22%2C%22PersonInfoBillTo%22%3A%7B%22EMailID%22%3A%22perteststore20201203064815.912%40hmail.com%22%2C%22PersonInfoKey%22%3A%22202012030700194136576337%22%2C%22Suffix%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%221234567890%22%2C%22LastName%22%3A%22Lastthree%22%2C%22ZipCode%22%3A%2234983%22%2C%22Title%22%3A%22%22%2C%22City%22"
		"%3A%22Port%20St%20Lucie%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22FL%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22Firstthree%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22NA%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22DocumentType%22%3A%220001%22%2C%22MaxOrderStatusDesc%22%3A%22Shipment%20Line%20Invoiced%22%2C%22MinOrderStatus%22%3A%223700."
		"100%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22OrderHeaderKey%22%3A%22202012030700194136576194%22%2C%22CustomerPONo%22%3A%22%22%2C%22DisplayStatus%22%3A%22Draft%20Order%20Created%22%2C%22DisplayEntryType%22%3A%22Web%22%2C%22MaxOrderStatus%22%3A%223700.100%22%2C%22SellerOrganizationName%22%3A%22HP%20US%20Web%20Store%22%2C%22PersonInfoShipTo%22%3A%7B%22EMailID%22%3A%22perteststore20201203064815.912%40hmail.com%22%2C%22PersonInfoKey%22%3A%22202012030700194136576218%22%2C%22Suffix%22%3A%22%22%2C%22Countr"
		"yDesc%22%3A%22US%22%2C%22LastName%22%3A%22Lastthree%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%221234567890%22%2C%22ZipCode%22%3A%2234983-3336%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22Port%20St%20Lucie%22%2C%22AddressID%22%3A%22EStore_STOO_GC_1606978367581%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22FL%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22Firstthree%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%2"
		"2Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22CustomerLastName%22%3A%22Lastthree%22%2C%22CustomerZipCode%22%3A%2234983%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22isHistory%22%3A%22N%22%2C%22OrderName%22%3A%22%22%7D%7D&scCSRFToken=1607507008337cfdjunHbqZqRNZ9zvzmXETA&scFlag=Y", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("SCIAjax", 
		"Y");

	web_add_auto_header("SCIVer", 
		"0.9");

	web_submit_data("isccs.order.details.OrderPricingSummaryBehaviorController.do", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.details.OrderPricingSummaryBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_details_OrderPricingSummaryBehaviorController\":{\"controllerId\":\"isccs_order_details_OrderPricingSummaryBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_customerDetails\",\"Input\":{\"Customer\":{\"CustomerID\":\"WCS\",\"CustomerType\":\"02\",\"IgnoreOrdering\":\"Y\",\"CustomerKey\":\"perteststore20201203064815.912@hmail.com\",\"OrganizationCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("OrderPricingSummaryAdjustments_LineTax.html", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/order/details/templates/OrderPricingSummaryAdjustments_LineTax.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("C51-1_MC_ManageCharges",LR_AUTO);

	lr_start_transaction("C51-2_MC_AddModify");

	web_custom_request("isccs.order.addModifyCharges.AddModifyChargesPopupInitController.do", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupInitController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		"Body=scControllerInput=%7B%22LineMode%22%3A%22Y%22%2C%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22202012030700194136576194%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22OrderLines%22%3A%7B%22OrderLine%22%3A%7B%22OrderLineKey%22%3A%22202012030700194136576196%22%2C%22ItemDetails%22%3A%7B%22PrimaryInformation%22%3A%7B%22ExtendedDisplayDescription%22%3A%22HP%20Color%20LaserJet%20Enterprise%20M653x%20(J8A05A%23BGJ)"
		"%22%7D%7D%7D%7D%2C%22DocumentType%22%3A%220001%22%2C%22OrderNo%22%3A%22H360004208%22%2C%22Extn%22%3A%7B%7D%7D%7D&scControllerData="
		"%7B%22isccs_order_addModifyCharges_AddModifyChargesPopupInitController%22%3A%7B%22controllerId%22%3A%22isccs_order_addModifyCharges_AddModifyChargesPopupInitController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%5D%7D%2C%22ChildControllers%22%3A%7B%22ChildController%22%3A%5B%7B%22controllerId%22%3A%22isccs_common_notes_OrderNoteInitController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22getOrderNoteMashup%22%2C%22Input%22%3A%7B%7D%2C%22mashupRefObj%22%3A%7B%22sour"
		"ceNamespace%22%3A%22getContactTypeList_output%22%2C%22callSequence%22%3A%22%22%2C%22mashupRefId%22%3A%22getOrderNoteMashup%22%2C%22sequence%22%3A%225%22%2C%22sourceBindingOptions%22%3A%22%22%2C%22mashupId%22%3A%22common_getContactTypeList%22%7D%7D%2C%7B%22mashupRefId%22%3A%22getCustomerSatisfactionList%22%2C%22Input%22%3A%7B%7D%2C%22mashupRefObj%22%3A%7B%22sourceNamespace%22%3A%22getNoteCustomerSatisfactionList_output%22%2C%22callSequence%22%3A%22%22%2C%22mashupRefId%22%3A%22getCustomerSatisfactio"
		"nList%22%2C%22sequence%22%3A%22%22%2C%22sourceBindingOptions%22%3A%22%22%2C%22mashupId%22%3A%22common_getNoteCustomerSatisfactionList%22%7D%7D%5D%7D%7D%5D%7D%7D%7D&scCSRFToken=1607507008337cfdjunHbqZqRNZ9zvzmXETA&scFlag=Y", 
		LAST);

	web_custom_request("AddModifyChargesPopup_LineMode.html", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/order/addModifyCharges/templates/AddModifyChargesPopup_LineMode.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t35.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\":{\"controllerId\":\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getCompleteOrderLineDetails\",\"Input\":{\"OrderLineDetail\":{\"OrderLineKey\":\"202012030700194136576196\"},\"LineMode\":\"Y\"}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_2", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\":{\"controllerId\":\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_addModifyCharges_getUserHierarchy\",\"Input\":{\"User\":{}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_3", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\":{\"controllerId\":\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_addModifyCharges_GetReturnOrderList\",\"Input\":{\"Order\":{\"OrderLine\":{\"DerivedFromOrderHeaderKey\":\"202012030700194136576194\",\"DerivedFromOrderLineKey\":\"202012030700194136576196\"}}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_4", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t39.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\":{\"controllerId\":\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_addModifyCharges_GetReversalLimitMatrix\",\"Input\":{\"CommonCode\":{\"ComplexQuery\":{\"Or\":{\"Exp\":[{\"Name\":\"CodeShortDescription\",\"Value\":\"HP-SUPERUSER-GROUP\"},{\"Name\":\"CodeShortDescription\",\"Value\":\"HP-CSR-MANUALREL-RET-GRP\"}]}}}"
		"}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_5", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\":{\"controllerId\":\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_paymentdetails\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"202012030700194136576194\",\"DocumentType\":\"0001\",\"EnterpriseCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_custom_request("isccs.order.addModifyCharges.ChargeFieldsInitController.do", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.ChargeFieldsInitController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		"Body=scControllerInput="
		"%7B%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22202012030700194136576194%22%2C%22DocumentType%22%3A%220001%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22Extn%22%3A%7B%22ExtnIsTaxExemptOrder%22%3A%22false%22%7D%2C%22OrderLines%22%3A%7B%22OrderLine%22%3A%7B%22HasRelatedLines%22%3A%22N%22%2C%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22202012030700194136576194%22%2C%22PriceInfo%22%3A%7B%22Currency%22%3A%22USD%22%7D%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22AuthorizedClient%22%3A%22WCS%22%2C%22DocumentType%22"
		"%3A%220001%22%2C%22Extn%22%3A%7B%22ExtnIsTaxExemptOrder%22%3A%22false%22%7D%7D%2C%22LineCharges%22%3A%7B%7D%2C%22MaxLineStatus%22%3A%223700.100%22%2C%22ItemGroupCode%22%3A%22PROD%22%2C%22OrderDates%22%3A%7B%22OrderDate%22%3A%5B%7B%22DateTypeId%22%3A%22HP_EST_DELIVERY_DATE%22%7D%2C%7B%22ActualDate%22%3A%222020-12-09T05%3A08%3A18%2B00%3A00%22%2C%22DateTypeId%22%3A%22YCD_COMPLETELY_SHIPPED_OR_CANCELLED%22%7D%5D%7D%2C%22OrderedQty%22%3A%221.00%22%2C%22ShipNode%22%3A%22USDC01%22%2C%22CarrierServiceCode"
		"%22%3A%22%22%2C%22OpenQty%22%3A%220.00%22%2C%22OrderLineKey%22%3A%22202012030700194136576196%22%2C%22ComputedPrice%22%3A%7B%22LineTotal%22%3A%222300.49%22%2C%22ExtendedPrice%22%3A%222149.99%22%2C%22Tax%22%3A%22150.50%22%2C%22Discount%22%3A%220.00%22%2C%22UnitPrice%22%3A%222149.99%22%2C%22Charges%22%3A%220.00%22%7D%2C%22DeliveryMethodName%22%3A%22Shipping%22%2C%22KitCode%22%3A%22%22%2C%22PrimeLineNo%22%3A%221%22%2C%22IsBundleComponent%22%3A%22N%22%2C%22MaxLineStatusDesc%22%3A%22Shipment%20Line%20In"
		"voiced%22%2C%22DisplayStatus%22%3A%22Shipment%20Line%20Invoiced%22%2C%22IsPriceMatched%22%3A%22N%22%2C%22LinePriceInfo%22%3A%7B%22ListPrice%22%3A%222149.99%22%2C%22InvoicedLineTotal%22%3A%222300.49%22%2C%22RepricingQty%22%3A%221.00%22%2C%22TaxableFlag%22%3A%22N%22%2C%22UnitPrice%22%3A%222149.99%22%2C%22IsLinePriceForInformationOnly%22%3A%22N%22%2C%22InvoicedPricingQty%22%3A%221.00%22%2C%22PricingQtyConversionFactor%22%3A%220.00%22%2C%22PricingUOM%22%3A%22EACH%22%2C%22SettledQuantity%22%3A%220.00%2"
		"2%2C%22LineTotal%22%3A%222300.49%22%2C%22SettledAmount%22%3A%220.00%22%2C%22BundleTotal%22%3A%220.00%22%2C%22OrderedPricingQty%22%3A%221.00%22%2C%22ActualPricingQty%22%3A%221.00%22%2C%22RetailPrice%22%3A%222149.99%22%2C%22DiscountPercentage%22%3A%220.00%22%2C%22IsPriceLocked%22%3A%22Y%22%7D%2C%22OverallStatus%22%3A%22%22%2C%22ShipnodeFullDescription%22%3A%22HP%20US%20DC%2CMillington%22%2C%22GiftFlag%22%3A%22N%22%2C%22PersonInfoShipTo%22%3A%7B%22EMailID%22%3A%22perteststore20201203064815.912%40hmai"
		"l.com%22%2C%22PersonInfoKey%22%3A%22202012030700194136576218%22%2C%22Suffix%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%22LastName%22%3A%22Lastthree%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%221234567890%22%2C%22ZipCode%22%3A%2234983-3336%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22Port%20St%20Lucie%22%2C%22AddressID%22%3A%22EStore_STOO_GC_1606978367581%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22FL%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22Firstthree%22%2C%22isHistory%22"
		"%3A%22N%22%2C%22EveningPhone%22%3A%22%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22LineTaxes%22%3A%7B%22LineTax%22%3A%5B%7B%22ChargeName%22%3A%22%22%2C%22ChargeCategory%22%3A%22Price%22%2C%22ChargeNameKey%22%3A%22%22%2C%22Tax%22%3A%22150.50%22%2C%22InvoicedTax%22%3A%22150.50%22%2C%22TaxName%22%3A%22Sales%20Tax%22%7D%5D%7D%2C%22Status%22%3A%22Shipment%20Line%20Invoice"
		"d%22%2C%22MinLineStatus%22%3A%223700.100%22%2C%22ShipnodeDescription%22%3A%22HP%20US%20DC%22%2C%22HoldFlag%22%3A%22N%22%2C%22IsRelatedLine%22%3A%22N%22%2C%22IsOpenBox%22%3A%22N%22%2C%22DeliveryMethod%22%3A%22SHP%22%2C%22IsBundleParent%22%3A%22N%22%7D%7D%7D%7D&scControllerData="
		"%7B%22isccs_order_addModifyCharges_ChargeFieldsInitController%22%3A%7B%22controllerId%22%3A%22isccs_order_addModifyCharges_ChargeFieldsInitController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22getChargeCategoryList%22%2C%22Input%22%3A%7B%7D%7D%2C%7B%22mashupRefId%22%3A%22extn_getChargeCategoryToHide%22%2C%22Input%22%3A%7B%7D%7D%5D%7D%7D%7D&scCSRFToken=1607507008337cfdjunHbqZqRNZ9zvzmXETA&scFlag=Y", 
		LAST);

	web_custom_request("ChargeFields_IsNewChargeInLineMode.html", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/order/addModifyCharges/templates/ChargeFields_IsNewChargeInLineMode.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("C51-2_MC_AddModify",LR_AUTO);

	lr_start_transaction("C51-3_MC_AddCharges");

	web_submit_data("isccs.order.addModifyCharges.ChargeFieldsBehaviorController.do", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.ChargeFieldsBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_addModifyCharges_ChargeFieldsBehaviorController\":{\"controllerId\":\"isccs_order_addModifyCharges_ChargeFieldsBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"getChargeNameList\",\"Input\":{\"ChargeName\":{\"ChargeCategory\":\"LineReversal\",\"DocumentType\":\"0001\",\"CallingOrganizationCode\":\"USWS\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	lr_end_transaction("C51-3_MC_AddCharges",LR_AUTO);

	lr_start_transaction("C51-4_MC_Apply");

	web_custom_request("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_6", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22lineCharges_changeOrder%22%2C%22Input%22%3A%7B%22Order%22%3A%7B%22Notes%22%3A%5B%7B%22Note%22%3A%7B%22NoteText%22%3A%22test%22%2C%22Priority%22%3A%220%22%2C%22VisibleToAll%22%3A%22Y%22%2C%22ContactType%22%3A%22EMAIL%22%2C%22ContactReference%22%3A%22tes"
		"t%40test.com%22%7D%7D%5D%2C%22HeaderCharges%22%3A%7B%22HeaderCharge%22%3A%7B%22ChargeCategory%22%3A%22LineReversal%22%2C%22ChargeName%22%3A%22Agent-related%20Adjustments%22%2C%22ChargeAmount%22%3A10%2C%22IsNewCharge%22%3A%22Y%22%2C%22ChargeType%22%3A%22CPL%22%7D%2C%22OrderLineKey%22%3A%22202012030700194136576196%22%7D%2C%22OrderHeaderKey%22%3A%22202012030700194136576194%22%2C%22BypassPricing%22%3A%22Y%22%2C%22OrderLines%22%3A%7B%22OrderLine%22%3A%7B%22LineCharges%22%3A%5B%5D%2C%22LineTaxes%22%3A%5"
		"B%7B%22LineTax%22%3A%5B%7B%22ChargeName%22%3A%22%22%2C%22ChargeCategory%22%3A%22Price%22%2C%22ChargeNameKey%22%3A%22%22%2C%22Tax%22%3A%22150.50%22%2C%22InvoicedTax%22%3A%22150.50%22%2C%22TaxName%22%3A%22Sales%20Tax%22%7D%5D%7D%5D%2C%22LinePriceInfo%22%3A%7B%22ListPrice%22%3A%222149.99%22%2C%22InvoicedLineTotal%22%3A%222300.49%22%2C%22RepricingQty%22%3A%221.00%22%2C%22TaxableFlag%22%3A%22N%22%2C%22UnitPrice%22%3A%222149.99%22%2C%22IsLinePriceForInformationOnly%22%3A%22N%22%2C%22InvoicedPricingQty%2"
		"2%3A%221.00%22%2C%22PricingQtyConversionFactor%22%3A%220.00%22%2C%22PricingUOM%22%3A%22EACH%22%2C%22SettledQuantity%22%3A%220.00%22%2C%22LineTotal%22%3A%222300.49%22%2C%22SettledAmount%22%3A%220.00%22%2C%22BundleTotal%22%3A%220.00%22%2C%22OrderedPricingQty%22%3A%221.00%22%2C%22ActualPricingQty%22%3A%221.00%22%2C%22RetailPrice%22%3A%222149.99%22%2C%22DiscountPercentage%22%3A%220.00%22%2C%22IsPriceLocked%22%3A%22Y%22%7D%2C%22IsBundleParent%22%3A%22N%22%2C%22ComputedPrice%22%3A%7B%22LineTotal%22%3A%2"
		"22300.49%22%2C%22ExtendedPrice%22%3A%222149.99%22%2C%22Tax%22%3A%22150.50%22%2C%22Discount%22%3A%220.00%22%2C%22UnitPrice%22%3A%222149.99%22%2C%22Charges%22%3A%220.00%22%7D%7D%7D%2C%22ReversalLimitMatrix%22%3A%7B%22bShipReversalPercentage%22%3A100%2C%22bRecycleFeeReversalPercentage%22%3A0%2C%22bLineReversalPercentage%22%3A100%2C%22bLineTaxReversalPercentage%22%3A0%2C%22bShipReversalValue%22%3A99999%2C%22bRecycleFeeReversalValue%22%3A0%2C%22bLineReversalValue%22%3A99999%2C%22bLineTaxReversalValue%2"
		"2%3A0%7D%7D%7D%7D%5D%7D%7D%7D&scCSRFToken=1607507008337cfdjunHbqZqRNZ9zvzmXETA&scFlag=Y", 
		LAST);

	web_custom_request("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_7", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22extn_addModifyCharges_recordInvoiceCreation%22%2C%22Input%22%3A%7B%22PendingInvoiceCreation%22%3A%7B%22LineChargesList%22%3A%7B%22LineCharge%22%3A%5B%7B%22ChargeAmount%22%3A%2210%22%2C%22ChargeName%22%3A%22Agent-related%20Adjustments(Reversal)"
		"%5B1%5D%22%2C%22IsNewCharge%22%3A%22Y%22%2C%22ChargeCategory%22%3A%22LineReversal%22%2C%22IsDiscount%22%3A%22N%22%2C%22ChargePerUnit%22%3A%220%22%2C%22InvoicedChargePerLine%22%3A%2210%22%2C%22ChargePerLine%22%3A%2210%22%2C%22IsManual%22%3A%22Y%22%2C%22InvoicedChargeAmount%22%3A%2210%22%2C%22IsBillable%22%3A%22N%22%7D%5D%7D%2C%22LineTaxesList%22%3A%7B%22LineTax%22%3A%5B%7B%22ChargeCategory%22%3A%22LineTaxReversal%22%2C%22Tax%22%3A%220.70%22%2C%22InvoicedTax%22%3A%220.70%22%2C%22TaxName%22%3A%22Line"
		"TaxReversal(Reversal)%5B1%5D%22%7D%5D%7D%2C%22OrderHeaderKey%22%3A%22202012030700194136576194%22%2C%22OrderLineKey%22%3A%22202012030700194136576196%22%2C%22OrderedQty%22%3A%221.00%22%7D%7D%7D%5D%7D%7D%7D&scCSRFToken=1607507008337cfdjunHbqZqRNZ9zvzmXETA&scFlag=Y", 
		LAST);

	web_submit_data("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_8", 
		"Action=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t46.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\":{\"controllerId\":\"isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_addModifyCharges_ChangeOrderInvoice\",\"Input\":{\"OrderInvoice\":{\"InvoiceNo\":\"M311247452\",\"OrderInvoiceKey\":\"202012090969473266325815\",\"Extn\":{\"ExtnMOrderNo\":\"M311247452\",\"IsNewCAASMisc\":\"FALSE\"}}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value=1607507008337cfdjunHbqZqRNZ9zvzmXETA", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_revert_auto_header("SCIAjax");

	web_revert_auto_header("SCIVer");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do_9", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.addModifyCharges.AddModifyChargesPopupBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t47.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_order_addModifyCharges_AddModifyChargesPopupBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22saveOrderNote%22%2C%22Input%22%3A%7B%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22202012030700194136576194%22%2C%22Notes%22%3A%7B%22Note%22%3A%7B%22NoteText%22%3A%22%3Cdiv%3E%3Cb%3E%20Reason%20%3A%20%3C%2Fb%3ELineReversal%20-%20Agent-related%20Adjustments"
		"(Reversal)"
		"%5B1%5D%3Cbr%2F%3E%3Cb%3E%20%24%20Value%20%3A%20%3C%2Fb%3E10.00%3Cbr%2F%3E%3Cb%3E%20%24%20Tax%20value%20%3A%20%3C%2Fb%3E0.70%3Cbr%2F%3E%3Cb%3E%20%24%20Total%20%3A%20%3C%2Fb%3E10.70%3Cbr%2F%3E%3Cb%3E%20Date%20%3A%20%3C%2Fb%3EDec-09-2020%3Cbr%2F%3E%3Cb%3E%20User%20ID%3A%20%3C%2Fb%3Esmbetr1Perfuser0201%3Cbr%2F%3E%3Cb%3E%20Notes%20%3A%20%3C%2Fb%3Etest%3Cbr%2F%3E%3Cb%3E%20Order%20%23%20%3A%20%3C%2Fb%3EH360004208%20-%20M311247452%3Cbr%2F%3E%3Cb%3E%20Product%20Details%20%3A%20%3C%2Fb%3EHP%20Color%20Laser"
		"Jet%20Enterprise%20M653x%20(J8A05A%23BGJ)%3C%2Fdiv%3E%22%2C%22Priority%22%3A%220%22%2C%22VisibleToAll%22%3A%22Y%22%2C%22ContactType%22%3A%22EMAIL%22%2C%22ContactReference%22%3A%22test%40test.com%22%2C%22ContactUser%22%3A%22smbetr1Perfuser0201%22%2C%22ReasonCode%22%3A%22CREDIT_NOTE%22%7D%7D%2C%22SelectMethod%22%3A%22WAIT%22%7D%7D%7D%5D%7D%7D%7D&scCSRFToken=1607507008337cfdjunHbqZqRNZ9zvzmXETA&scFlag=Y", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_header("SCIAjax", 
		"Y");

	web_add_header("SCIVer", 
		"0.9");

	web_custom_request("isccs.order.details.OrderPricingSummaryBehaviorController.do_2", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/scuiimpl/controller/default/isccs.order.details.OrderPricingSummaryBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		"Body=scControllerData="
		"%7B%22isccs_order_details_OrderPricingSummaryBehaviorController%22%3A%7B%22controllerId%22%3A%22isccs_order_details_OrderPricingSummaryBehaviorController%22%2C%22MashupRefs%22%3A%7B%22MashupRef%22%3A%5B%7B%22mashupRefId%22%3A%22getCompleteOrderDetails%22%2C%22Input%22%3A%7B%22Order%22%3A%7B%22OrderHeaderKey%22%3A%22202012030700194136576194%22%7D%7D%7D%2C%7B%22mashupRefId%22%3A%22getCompleteOrderLineList%22%2C%22scPaginationStrategy%22%3A%22NEXTPAGE%22%2C%22scPageSize%22%3A%2210%22%2C%22scPageNumbe"
		"r%22%3A1%2C%22scPreviousPageRecord%22%3A%7B%7D%2C%22Input%22%3A%7B%22OrderLine%22%3A%7B%22OrderHeaderKey%22%3A%22202012030700194136576194%22%7D%7D%7D%5D%7D%7D%7D&scControllerInput="
		"%7B%22Order%22%3A%7B%22EntryType%22%3A%22Web%22%2C%22CustomerFirstName%22%3A%22Firstthree%22%2C%22SellerOrganizationCode%22%3A%22USWS%22%2C%22AuthorizedClient%22%3A%22WCS%22%2C%22Extn%22%3A%7B%22ExtnWebProfileId%22%3A%22110283043%22%2C%22ExtnUSERTYPE%22%3A%22G%22%7D%2C%22EnterpriseName%22%3A%22HP%20US%20Web%20Store%22%2C%22TaxExemptionCertificate%22%3A%22%22%2C%22PriceInfo%22%3A%7B%22TotalAmount%22%3A%222300.49%22%2C%22Currency%22%3A%22USD%22%7D%2C%22OrderNo%22%3A%22H360004208%22%2C%22CustomerPhon"
		"eNo%22%3A%221234567890%22%2C%22DraftOrderFlag%22%3A%22N%22%2C%22CustomerEMailID%22%3A%22perteststore20201203064815.912%40hmail.com%22%2C%22PersonInfoBillTo%22%3A%7B%22EMailID%22%3A%22perteststore20201203064815.912%40hmail.com%22%2C%22PersonInfoKey%22%3A%22202012030700194136576337%22%2C%22Suffix%22%3A%22%22%2C%22CountryDesc%22%3A%22US%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%221234567890%22%2C%22LastName%22%3A%22Lastthree%22%2C%22ZipCode%22%3A%2234983%22%2C%22Title%22%3A%22%22%2C%22City%22"
		"%3A%22Port%20St%20Lucie%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22FL%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22Firstthree%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22NA%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%22Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22DocumentType%22%3A%220001%22%2C%22MaxOrderStatusDesc%22%3A%22Shipment%20Line%20Invoiced%22%2C%22MinOrderStatus%22%3A%223700."
		"100%22%2C%22TaxExemptFlag%22%3A%22N%22%2C%22OrderHeaderKey%22%3A%22202012030700194136576194%22%2C%22CustomerPONo%22%3A%22%22%2C%22DisplayStatus%22%3A%22Draft%20Order%20Created%22%2C%22DisplayEntryType%22%3A%22Web%22%2C%22MaxOrderStatus%22%3A%223700.100%22%2C%22SellerOrganizationName%22%3A%22HP%20US%20Web%20Store%22%2C%22PersonInfoShipTo%22%3A%7B%22EMailID%22%3A%22perteststore20201203064815.912%40hmail.com%22%2C%22PersonInfoKey%22%3A%22202012030700194136576218%22%2C%22Suffix%22%3A%22%22%2C%22Countr"
		"yDesc%22%3A%22US%22%2C%22LastName%22%3A%22Lastthree%22%2C%22Country%22%3A%22US%22%2C%22DayPhone%22%3A%221234567890%22%2C%22ZipCode%22%3A%2234983-3336%22%2C%22Title%22%3A%22%22%2C%22City%22%3A%22Port%20St%20Lucie%22%2C%22AddressID%22%3A%22EStore_STOO_GC_1606978367581%22%2C%22MiddleName%22%3A%22%22%2C%22State%22%3A%22FL%22%2C%22PersonID%22%3A%22%22%2C%22FirstName%22%3A%22Firstthree%22%2C%22isHistory%22%3A%22N%22%2C%22EveningPhone%22%3A%22%22%2C%22MobilePhone%22%3A%22%22%2C%22Company%22%3A%22%22%2C%2"
		"2Department%22%3A%22%22%2C%22AddressLine1%22%3A%226118%20NW%20Duke%20Circle%22%2C%22AddressLine2%22%3A%22%22%7D%2C%22CustomerLastName%22%3A%22Lastthree%22%2C%22CustomerZipCode%22%3A%2234983%22%2C%22EnterpriseCode%22%3A%22USWS%22%2C%22isHistory%22%3A%22N%22%2C%22OrderName%22%3A%22%22%7D%7D&scCSRFToken=1607507008337cfdjunHbqZqRNZ9zvzmXETA&scFlag=Y", 
		LAST);

	lr_end_transaction("C51-4_MC_Apply",LR_AUTO);

	return 0;
}
