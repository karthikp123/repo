#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>



extern "C"
{
#include <sys/types.h>
#include <sys/wait.h>

int pid;
int g_value = 10;


void mysigIntHandler( int signal)

{

    if( signal == SIGINT)

    {

        printf("Signal is sigint\n");

        exit(0);

    }



}


void mygenSigHandler( int signal)

{

    if( signal == SIGQUIT)

    {

        printf("Signal is sigquit\n");

        exit(0);

    }

    else if(signal == SIGCHLD)

    {

        printf("Child is killed\n");

    }

}

    

int signal_hanlder_main()

{

    signal(SIGINT, mysigIntHandler);

    signal(SIGQUIT, mygenSigHandler);

    signal(SIGCHLD, mygenSigHandler);

    

    printf("Before fork g_value is:%d \n", g_value);

    pid = fork();
    int status;



    printf("PID value is: %d\n", pid);

    if( pid > 0)

    {

        int parent_value;

        g_value = 20;

        printf("g_value in parent is:%d \n", g_value);

        printf("Parent child PID :%d\n", pid);               

        pid = wait(&status);

        printf("Parent child PID :%d exited\n", pid);

    }

    else

    {

        int child_value;
        char *const args[] = {"./testing.o", NULL};

        g_value = 30;

        printf("g_value in child is:%d \n", g_value);

        printf("Within child process\n"); 
	
        execvp("./testing.o", args); 

       scanf("%d",&child_value); 

        printf("%d\n", g_value);

    }  

}

#ifndef RELOCATABLE_OBJ

int main()
{
	signal_hanlder_main();
}

#endif  //RELOCATABLE_OBJ

}
