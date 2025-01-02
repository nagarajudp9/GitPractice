vuser_end()
{

	lr_start_transaction("C07_Logout");

	lr_end_transaction("C07_Logout",LR_AUTO);

	lr_start_transaction("C07_Logout");

	web_url("logout.do", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/logout.do?scFlag=Y", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/container/home.do?scFlag=Y", 
		"Snapshot=t49.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("LoginFrame.html_2", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/app/templates/LoginFrame.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/login.do?scFlag=Y", 
		"Snapshot=t50.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("Dialog.html_2", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/ibmjs/idx/widget/templates/Dialog.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/login.do?scFlag=Y", 
		"Snapshot=t51.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("HoverHelpTooltip.html_2", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/ibmjs/idx/widget/templates/HoverHelpTooltip.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/login.do?scFlag=Y", 
		"Snapshot=t52.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("TextBox.html_3", 
		"URL=https://glbecom-perf-oms.inc.hpicorp.net/isccs/ibmjs/idx/form/templates/TextBox.html", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://glbecom-perf-oms.inc.hpicorp.net/isccs/isccs/login.do?scFlag=Y", 
		"Snapshot=t53.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("C07_Logout",LR_AUTO);

	return 0;
}