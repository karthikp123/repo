#include "shared_msg.h"

extern "C"
{

int shared_mem_receiver_main(int argc, char **argv)
{
	// ftok to generate unique key
	key_t key = ftok("msg_q_file",KEY_SIZE);

	// shmget returns an identifier in shmid
	int shmid = shmget(key,1024,0666|IPC_CREAT);

	// shmat to attach to shared memory
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

        char readbuffer[RD_WT_BUFF_SIZE + 1];
	int readbuffersize = atoi(argv[2]);
	
	int i,j;
	int curoffset,nextoffset;
	int readofmax = SHM_MAX_SIZE - (sizeof(int)*3) - readbuffersize;
	
	for(i = 0; i < 1000; i++)
	{
	    curoffset = *readoffptr;
	    nextoffset = curoffset + readbuffersize;
	    
	    *readoffptr = (nextoffset > readofmax ) ? 0 : nextoffset;
	    
	    memcpy(readbuffer, shmptr + curoffset, readbuffersize);
	    
	    readbuffer[readbuffersize - 1] = '\0';
	    printf("SHM Read byte from [%d] : %s\n", curoffset, readbuffer);
	   
	    
	    sleep(1);
	    
	    
	}
	
	
	return 0;
}

#ifndef RELOCATABLE_OBJ

int main (int argc, char **argv)
{
	shared_mem_receiver_main(argc,argv);
}

#endif //RELOCATABLE_OBJ

}
