ManualRelease()
{
/*	
	pmax= atoi(lr_eval_string("{cp_Rorder_count}"));
	
	pextn= atoi(lr_eval_string("{cp_ExtnsnRel_count}"));
	
	prand= (rand()%pextn)+1;
	sprintf(spara,"{cp_ExtnsnRel_%d}",prand);
	lr_save_string(lr_eval_string(spara),"cp_ExtnsnRel");

	while(i<=pmax)
	{
		
		sprintf(spara,"{cp_Rorder_%d}",i);
		
		lr_save_string(lr_eval_string(spara),"cp_Rorder");
		               
		if(strcmp(lr_eval_string("{cp_Rorder}"),lr_eval_string("{cp_ExtnsnRel}"))==0)
		 {
		               	
		  flag=i;
		 }
		               
	      i++;
	      
	}
	
	sprintf(spara,"{cp_Rorder_%d}",flag);
	lr_save_string(lr_eval_string(spara),"cp_Rorder");
	
	sprintf(spara,"{cp_OrderHeaderKey_%d}",flag);
	lr_save_string(lr_eval_string(spara),"cp_OrderHeaderKey");
	
	*/
	
	
	lr_start_transaction("C62_Return_ManualRelease");
	
	web_submit_data("extn.return.release.manual.ReleaseReturnExtnBehaviorController.do", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/extn.return.release.manual.ReleaseReturnExtnBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"extn_return_release_manual_ReleaseReturnExtnBehaviorController\":{\"controllerId\":\"extn_return_release_manual_ReleaseReturnExtnBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_ServiceManualReleaseReturnMash\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey_1}\",\"RMA\":\"R{cp_Rorder_1}\",\"ReturnAgentID\":\"{p_SterlingUsers}\",\"Locale\":\"en_US_EST\",\"ReasonForRelease\":\"Lost/Stolen\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);

	web_submit_data("isccs.return.search.ReturnListScreenBehaviorController.do_4", 
		"Action=https://{p_SterlingHostName}/isccs/scuiimpl/controller/default/isccs.return.search.ReturnListScreenBehaviorController.do", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scCSRFToken={scCSRFToken}&scFlag=Y", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=scControllerData", "Value={\"isccs_return_search_ReturnListScreenBehaviorController\":{\"controllerId\":\"isccs_return_search_ReturnListScreenBehaviorController\",\"MashupRefs\":{\"MashupRef\":[{\"mashupRefId\":\"extn_returnSummary_getCompleteOrderDetails\",\"Input\":{\"Order\":{\"OrderHeaderKey\":\"{cp_OrderHeaderKey_1}\"}}}]}}}", ENDITEM, 
		"Name=scCSRFToken", "Value={scCSRFToken}", ENDITEM, 
		"Name=scFlag", "Value=Y", ENDITEM, 
		LAST);
	
	lr_end_transaction("C62_Return_ManualRelease",LR_AUTO);
	
	lr_think_time(10);
	
	
	return 0;
}
