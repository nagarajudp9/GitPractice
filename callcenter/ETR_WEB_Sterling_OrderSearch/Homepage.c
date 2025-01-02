Homepage()
{
	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_reg_find("Text=IBM Call Center for Commerce",LAST);
	
	lr_start_transaction("C00_Homepage");

	web_url("login.do", 
		"URL=https://{p_SterlingHostName}/isccs/isccs/login.do", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	/*web_custom_request("LoginFrame.html", 
		"URL=https://{p_SterlingHostName}/isccs/isccs/app/templates/LoginFrame.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/login.do", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("TextBox.html", 
		"URL=https://{p_SterlingHostName}/isccs/ibmjs/idx/form/templates/TextBox.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/login.do", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("Dialog.html", 
		"URL=https://{p_SterlingHostName}/isccs/ibmjs/idx/widget/templates/Dialog.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/login.do", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("HoverHelpTooltip.html", 
		"URL=https://{p_SterlingHostName}/isccs/ibmjs/idx/widget/templates/HoverHelpTooltip.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{p_SterlingHostName}/isccs/isccs/login.do", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);*/
	
	lr_end_transaction("C00_Homepage",LR_AUTO);
	
	lr_think_time(10);

	
	return 0;
}
