Logout()
{
	
	web_reg_find("Text=IBM Call Center for Commerce",LAST);
	
	lr_start_transaction("C07_Logout");

	
	web_url("logout.do", 
		"URL=https://{p_SterlingHostName}/isccs/isccs/logout.do?scFlag=Y", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t49.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	
	lr_end_transaction("C07_Logout",LR_AUTO);
	
	
	return 0;
}
