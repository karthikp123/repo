
#include "msg_queue_ipc.h"

extern "C"
{

struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;
 
 int rcvmsg (int msgid)
 {
 	msgrcv(msgid, &message, sizeof(message), 1, 0);
 	return 0;
 }
  
int msg_que_slave_main()
{
    key_t key;
    int msgid;
  
   
    key = ftok(MSGQ_FILE_PATH, MSGQ_KEY);
  
    
    msgid = msgget(key, 0666 | IPC_CREAT);
  
    
    
    
    int count = 0;
    while (1)
    {
    	rcvmsg(msgid);
    	printf("Data Received is : %s \n",  message.mesg_text);
    }
    
    printf("Data Received is : %s \n",  message.mesg_text);
    
 
    msgctl(msgid, IPC_RMID, NULL);
  
    return 0;
}

#ifndef RELOCATABLE_OBJ

int main()
{
	msg_que_slave_main();
}

#endif //RELOCATABLE_OBJ

}
