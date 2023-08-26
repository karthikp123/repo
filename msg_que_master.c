#include "msg_queue_ipc.h"

extern "C"
{

struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;

int sendmsg (int msgid)
{
	msgsnd(msgid, &message, sizeof(message), 0);
	return 0;
}
 

int msg_que_master_main(int argc , char *argv[])
{
    key_t key;
    int msgid;
    int pid;
    pid = getpid();
    
    //char str[] = "karthik";
    
    key = ftok(MSGQ_FILE_PATH, MSGQ_KEY);
    
    
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;
    
    printf("Write Data : ");
    //fgets(message.mesg_text,MAX,stdin);
    
    int count = 0;
    while (count < 10000)
    {
        sprintf (message.mesg_text, "from PID: %d index:%d message:%s",pid,count,argv[1]);
        sendmsg(msgid);
        sleep(1);
    	count++;
    }
  
    printf("Data send is : %s \n", message.mesg_text);
  
    return 0;
}

#ifndef RELOCATABLE_OBJ

int main(int argc , char *argv[])
{
	msg_que_master_main(argc ,argv);
}

#endif //RELOCATABLE_OBJ

}


