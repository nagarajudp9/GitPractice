Direct_CTO()
{
	
	lr_save_string(lr_eval_string("{p_CatEntryID}"), "cp_CatEntryID");
	
	web_set_max_html_param_len("999999");
	
	lr_think_time(15);
	
	if(strcmp(lr_eval_string("{p_PartNumber}"),"")==0 || strcmp(lr_eval_string("{p_MRLastParam}"),"")==0 || strcmp(lr_eval_string("{p_ModelRef}"),"")==0 || strcmp(lr_eval_string("{LeadSku}"),"")==0 || strcmp(lr_eval_string("{FinalarrComponent}"),"")==0 || strcmp(lr_eval_string("{SortedPrimarySku}"),"")==0 || strcmp(lr_eval_string("{FinalarrPriceSku}"),"")==0 || strcmp(lr_eval_string("{p_ConfigSKUS}"),"")==0)
	{
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	web_convert_param("p_MRLastParam",
	                  "SourceString={p_MRLastParam}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
	
	web_convert_param("p_PartNumber_URL",
	                  "SourceString={p_PartNumber}",
	                  "SourceEncoding=HTML",
	                  "TargetEncoding=URL",
	                  LAST);
		
	web_convert_param("cp_ModelRefParam",
		              "SourceString={p_ModelRef}",
		              "SourceEncoding=HTML",
		              "TargetEncoding=URL",
		              LAST);
	
	
	CTO();
	
	return 0;
}
