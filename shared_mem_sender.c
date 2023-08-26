#include "shared_msg.h"

extern "C"
{

int shared_mem_sender_main(int argc, char *argv[])
{
    
	
	key_t key = ftok("shmfile",KEY_SIZE);

	
	int shmid = shmget(key,1024,0666|IPC_CREAT);

	
	shmptr = (char*) shmat(shmid,(void*)0,0);
	intptr = (int *)shmptr;
	shmptr +=sizeof(int);
	readoffptr = (int *)shmptr;
	shmptr +=sizeof(int);
	writeoffptr =(int *)shmptr;
	shmptr +=sizeof(int);
	
	
	if(*intptr != SHM_INT_PATTERN)
	{
	    *intptr = SHM_INT_PATTERN;
	    *readoffptr = 0;
	    *writeoffptr = 0;
	    
	}
	int writemax;
	char writebuffer[RD_WT_BUFF_SIZE + 1];
	int writebuffersize = atoi(argv[1]);
	int *intptr = &writebuffersize;
	int i,j;
	int curoffset,nextoffset;
	int writeoffmax = SHM_MAX_SIZE - (sizeof(int)*3) - writebuffersize;
	
	/*for(i = 0; i < writebuffersize; i++)
	{
	    writebuffer[i] = argv[1][0];
	}*/
	
	for(i = 0; i < 10000; i++)
	{
	    curoffset = *writeoffptr;
	    nextoffset = curoffset + writebuffersize;
	    *writeoffptr = (nextoffset > writeoffmax) ? 0 : nextoffset;
	        
	    memcpy(shmptr+curoffset, writebuffer, writebuffersize);
	
	    writebuffer[writebuffersize - 1] = '\0';
	    printf("SHM Write byte from [%d] : %s\n" , curoffset, writebuffer);
	    
	    sleep(1);
	}
	
	
	


	return 0;
}

#ifndef RELOCATABLE_OBJ

int main(int argc, char *argv[])
{
	shared_mem_sender_main(argc, argv);
}

#endif //RELOCATABLE_OBJ

}
