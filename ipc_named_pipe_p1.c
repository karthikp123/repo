#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

extern "C"
{

int ipc_named_pipe_p1_main()
{
    int fd;

    char * myfifo = "/home/karthi/Downloads/myfifo";


    mkfifo(myfifo, 0666);

    char arr1[80], arr2[80];
    while (1)
    {
        fd = open(myfifo, O_WRONLY);

        fgets(arr2, 80, stdin);

        write(fd, arr2, strlen(arr2)+1);
        close(fd);

        fd = open(myfifo, O_RDONLY);

        read(fd, arr1, sizeof(arr1));

        printf("User2: %s\n", arr1);
        close(fd);
    }
    return 0;
}

#ifndef RELOCATABLE_OBJ

int main ()
{
	ipc_named_pipe_p1_main();
}

#endif //RELOCATABLE_OBJ

}
