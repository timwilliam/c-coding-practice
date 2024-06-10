#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define BUF_SZ 256
#define FIFO_PATH "myfifo"

int main(void)
{
    int ret, fd;
    char buffer[BUF_SZ];

    strcpy(buffer, "Hello to pipe!");
        
    if((fd = open(FIFO_PATH, O_WRONLY)) == -1)
    {
        printf("open FIFO_PATH error!\n");
        return -1;
    }
    
    if((ret = write(fd, buffer, sizeof(buffer))) == -1)
    {
        printf("write error!\n");
        return -1;
    }

    printf("Written: %s\n", buffer);

    close(fd);
    return 0;
}
