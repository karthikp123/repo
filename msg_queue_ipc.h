#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/shm.h>

#define MSGQ_FILE_PATH "msg_q_file"
#define MSGQ_KEY 42
#define MAX 10

#define SHARED_SIZE 1024

#define VALUE
