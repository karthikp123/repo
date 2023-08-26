#include <stdio.h>
#include <pthread.h>

extern "C"
{

void * function (void * arg)
{
	int i;
	printf ("hello from process X\n");
}

void * function_2 (void * data)
{
	char * ch = (char *) (data);
	
	printf ("hello from process %c\n", *ch);
}

int threads_test_main ()
{
	pthread_t t1,t2;
	
	char chy = 'Y';
	//char chx = 'X';
	
	pthread_create (&t1, NULL, function, NULL);
	
	pthread_create (&t2, NULL, function_2, (void *)(&chy));
	
	//to make the main process wait until the thread terminates.
	pthread_join (t1, NULL);
	pthread_join (t2, NULL);
	
	//to cancel a thread
	pthread_cancel(t1);
	
	
	return 0;
}

#ifndef RELOCATABLE_OBJ

int main ()
{
	threads_test_main ();
}

#endif //RELOCATABLE_OBJ

}
