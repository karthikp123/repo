/* Creation of the deamon process */


extern "C"
{
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BD_NO_CHDIR          01 /* Don't chdir ("/") */
#define BD_NO_CLOSE_FILES    02 /* Don't close all open files */
#define BD_NO_REOPEN_STD_FDS 04 /* Don't reopen stdin, stdout, and stderr
                                   to /dev/null */
#define BD_NO_UMASK0        010 /* Don't do a umask(0) */
#define BD_MAX_CLOSE       8192 /* Max file descriptors to close if
                                   sysconf(_SC_OPEN_MAX) is indeterminate */



int become_deamon (int flags)
{
	int maxfd, fd;	
	
	
	
	switch (fork())
	{
		case -1: 
			return -1;
		case 0:
			break;
		default:
			 _exit(EXIT_SUCCESS);
		
	}
	
	if(setsid() == -1)               
    		return -1;
	
	switch(fork())
	{
		case -1:
			return -1;
		case 0:
			break;
		default:
			 _exit(EXIT_SUCCESS);
	}
	
	
	if(!(flags & BD_NO_UMASK0))
    		umask(0);                      	 

  	if(!(flags & BD_NO_CHDIR))
    		chdir("/");                     	

  	if(!(flags & BD_NO_CLOSE_FILES))  		
  	{
   		maxfd = sysconf(_SC_OPEN_MAX);
   		
    		if(maxfd == -1)
     			 maxfd = BD_MAX_CLOSE; 
     			         			
    		for(fd = 0; fd < maxfd; fd++)
      			close(fd);
  	}
  	
  	
  	
  	if(!(flags & BD_NO_REOPEN_STD_FDS))
  	{
    	
    		close(STDIN_FILENO);

    		fd = open("/dev/null", O_RDWR);
    		if(fd != STDIN_FILENO)
     			 return -1;
    		if(dup2(STDIN_FILENO, STDOUT_FILENO) != STDOUT_FILENO)
     			 return -2;
    		if(dup2(STDIN_FILENO, STDERR_FILENO) != STDERR_FILENO)
      			return -3;
  	}
  	
 	
 	
 	return 0;
	
}

int create_deamon_main ()
{
	int ret;
	
	ret = become_deamon (0);
	
	
	while(1)
  	{
    		sleep(60);
    		syslog(LOG_USER | LOG_INFO, "running");
  	}

 	 return EXIT_SUCCESS;
	
	
}

#ifndef RELOCATABALE_OBJ

int main ()
{
	 create_deamon_main ();
}

#endif //RELOCATABALE_OBJ


}
