UserDetails()
{
	web_set_sockets_option("SSL_VERSION", "TLS1.2");	
	
	web_cache_cleanup();
	web_cleanup_auto_headers();
	web_cleanup_cookies();	
	
	return 0;
}
