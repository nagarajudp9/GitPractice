vuser_init()
{
	web_set_max_html_param_len("99999");
	
	Homepage();
	Login();
	
	return 0;
}
