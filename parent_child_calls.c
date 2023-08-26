#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

extern "C"
{
void  my_sigint_handler (int signal)
{
	if(signal == SIGINT)  //ctl+c
	{
		printf ("signal STDTINT hanldelr: %d called\n",signal);
	}
}

void my_sigtstp_handler(int signal)
{
	if(signal == SIGTSTP)   //ctl+z
	{
		printf ("signal STDTSTP hanldelr: %d called\n",signal);
	}
}

void my_sigchld_handler (int signal)
{
	if (signal == SIGCHLD)  //when child terminates
	{
		printf ("signal STDTCHLD hanldelr: %d called\n",signal);
	}
}



int parent_child_calls_main ()
{
	//initialize it anywhere in the code
	signal (SIGINT, my_sigint_handler);
	signal (SIGTSTP, my_sigtstp_handler);
	signal (SIGCHLD, my_sigchld_handler);		
	
	printf ("before exec\n");
	
	 char *args[]={"./testing",NULL};
	 
	 
	 
	int pid;
	
	pid = fork();
	
	int i;
	if (pid == 0)
	{
		printf ("hello from child\n");
		execvp(args[0],args);
		scanf ("%d",&i);
	}
	else
	{
		printf ("hello from parent\n");
		scanf ("%d",&i);
	}
	
	return 0;
}

#ifndef RELOCATABLE_OBJ

int main()
{
	parent_child_calls_main ();
}

#endif  //RELOCATABLE_OBJ

}
