#ifndef SHARED_MSG_H
#define SHARED_MSG_H

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include <unistd.h>

#define KEY_SIZE 42
#define RD_WT_BUFF_SIZE 512
#define SHM_MAX_SIZE 1028
#define SHM_INT_PATTERN (0xAEABA63D)

char *shmptr;
int *intptr;
int *readoffptr;
int *writeoffptr;

#endif
