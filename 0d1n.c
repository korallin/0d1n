/*
Author:Antonio Costa aka " Cooler_ "
contact: c00f3r[at]gmail[dot]com


    Copyright (C) 2012 0d1n authors,
    
    This file is part of 0d1n
    
    0d1n is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    0d1n is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.



What this IT ?
this is another Web POST,GET test tool lol

need libcurl to run

$ sudo apt-get install libcurl-dev
if rpm distro
$ sudo yum install libcurl-devel
$ make
$./0d1n


*/
#include <stdio.h> 
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include "spider.h"

void no_write_coredump (void) 
{
  	struct rlimit rlim;
   
	rlim.rlim_cur = 0; 
	rlim.rlim_max = 0; 
	setrlimit(RLIMIT_CORE, &rlim);

}

void init()
{
 puts(
 CYAN
   "       ~.             ~             \n"                      
   "         01...___|__..10.              \n" 
   "          1010   101   101             \n" 
   "           0101  :Bug  :Sec   `.oo'   \n"
   "           :101  |666  |101  ( (`-'   \n"
   " .---.    1010  ;110  ;010   `.`.     \n"
   "/ .-._)  111-\"\"\"|\"\"\"'-000      `.`.   \n"
   "( (`._) .-.  .-. |.-.  .-.  .-. ) ) \n"
   " \\ `---( 1 )( 0 )( 1 )( 1 )( 0 )-' /  \n"
   " `.    `-'  `-'  `-'  `-'  `-'  .'   \n"
   "   `---------------------------'     \n"
 YELLOW
 "Odin simple http inputs tester v 1.2 STABLE\n"
 LAST
 "--host :	host to scan\n"
 "--payloads :	payload list to inject\n"
 "--find_string_list :	strings list to find on response\n"
 "--find_regex_list :	regex list to find on response\n"
 "--cookie_jar :	 cookie jar file to load\n"
 "--post :	post method params  ex: 'var=!&x=!...'\n"
 "--log :	output of result\n"
 "--UserAgent :	custom UserAgent\n"
 "--CA_certificate :	Load CA certificate to work with SSL\n"
 "--SSL_version :	choice SSL version 2 or 3\n"
 "--timeout_response :	timeout of response\n"
 YELLOW
 "example:\n./odin --host 'http://site.com/view/1!/product/!/' --payloads sqli.txt --find_string_list response_sqli.txt --log site \n"
 CYAN
 "Coded by Cooler_\n c00f3r[at]gmail[dot]com\n "
 );
 puts(LAST);
}

static struct option long_options[] =
{
    {"host", required_argument, NULL, 'h'},
    {"payloads", required_argument, NULL, 'p'},
    {"find_string_list", required_argument, NULL, 'f'},
    {"find_regex_list", required_argument, NULL, 'z'},
    {"cookie_jar", required_argument, NULL, 'c'},
    {"post", required_argument, NULL, 'P'},
    {"log", required_argument, NULL, 'o'},
    {"UserAgent", required_argument, NULL, 'u'},
    {"CA_certificate", required_argument, NULL, 's'},
    {"SSL_version", required_argument, NULL, 'V'},
    {"timeout_response", required_argument, NULL, 'T'},
    {NULL, 0, NULL, 0}
};


int 
main(int argc, char ** argv)
{
 no_write_coredump ();
 char c;
 char *pack[11]; 

	if(argc < 7) 
	{
		init();
		DEBUG(" Need more arguments.\n");
		exit(0);
	}
 
 	short y=10;

 	while(y)
 	{
  		pack[y]=NULL;
  		y--;
 	}

 	opterr = 0;

 	while((c = getopt_long(argc, argv, "h:p:f:z:c:P:o:u:s:T:V:",long_options,NULL)) != -1)
  		switch(c) 
  		{
// Host
   			case 'h':
    				
				if ( strnlen(optarg,256)<= 128 )
				{
    					pack[0] = optarg;
    					printf("Host: %s \n",pack[0]);
    					
				} else {
					DEBUG("Error \nArgument Host very large : %s \n",optarg);
					exit(1);
				}
				break;
// payload list
			case 'p':
				if ( strnlen(optarg,256)<= 128 )
				{
    					pack[1] = optarg;
    					printf("Payloads: %s \n",optarg);
    					
				} else {
					DEBUG("Error \nArgument Payloads very large : %s \n",pack[1]);
					exit(1);
				}
				break;

   			case 'f':    				
				if ( strnlen(optarg,256)<= 128 )
				{
    					pack[2] = optarg;
    					printf("Find list: %s \n",optarg);
    				} else {
			
					DEBUG("Error \nArgument Find list very large : %s \n",pack[2]);
					exit(1);
				}
				break;

   			case 'z':			
				if ( strnlen(optarg,256)<= 128 )
				{
    					pack[10] = optarg;
    					printf("Regex list: %s \n",optarg);
    				} else {
					DEBUG("Error \nArgument Regex very large : %s \n",pack[10]);
					exit(1);
				}
				break;

   			case 'c':
				if ( strnlen(optarg,256)<= 128 )
				{
    					pack[3] = optarg;
				} else {

					DEBUG("Error \nArgument cookie jar file is very large : %s \n",pack[3]);
					exit(1);
				}
    				break;

   			case 'P':
				if ( strnlen(optarg,256)<= 128 )
				{
    					pack[4] = optarg;
				} else {
					DEBUG("Error \nArgument POST very large : %s \n",pack[4]);
					exit(1);
				}
    				break;

   			case 'o':
				if ( strnlen(optarg,256)<= 128 )
				{
    					pack[5] = optarg;
    					printf("Log file: %s \n",optarg);
    				} else {
					DEBUG("Error \nArgument Log file very large : %s \n",pack[5]);
					exit(1);
				}
				break;
   
   			case 'u':
				if ( strnlen(optarg,256)<= 128 )
				{
    					pack[6] = optarg;
    				} else {	
					DEBUG("Error \nArgument user agent is very large : %s \n",pack[6]);
					exit(1);
				}
 
   			case 's':
				if ( strnlen(optarg,256)<= 128 )
				{
    					pack[7] = optarg;
				} else {	
					DEBUG("Error \nArgument ca cert file name is very large : %s \n",pack[7]);
					exit(1);
				}
 
   			case 'T':
				if ( strnlen(optarg,4)<= 3 )
				{	
    					pack[8] = optarg;
				} else {	
					DEBUG("Error \nArgument timeout is very large need 3 digit : %s \n",pack[8]);
					exit(1);
				}
				
 
   			case 'V':
				if ( strnlen(optarg,3)<= 2 )
				{	
    					pack[9] = optarg;
				} else {	
					DEBUG("Error \nArgument SSL version one digit example 1,2,3 or 4 : %s \n",pack[8]);
					exit(1);
				}

   			case '?':
    				if(optopt == 'h' || optopt == 'p' || optopt == 'f' || optopt == 'c' || optopt == 'P' || optopt == 'o' || optopt=='s') 
    				{
     					init();
     					puts(RED);
     					DEBUG("Option -%c requires an argument.\n", optopt); 
     					puts(LAST);
     					exit(1);
    				}
  		}

	srand(time(NULL));
 

	if(strlen(pack[0]))
		scan((void *)pack);


 	exit(0);
}
