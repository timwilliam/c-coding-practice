#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SZ 256
#define FIFO_PATH "myfifo"

int main(void)
{
    int ret, fd;
    char buffer[BUF_SZ];

    if((ret = mkfifo(FIFO_PATH, 0600)) == -1)
    {
        printf("mkfifo error!\n");
        return -1;
    }

    if((fd = open(FIFO_PATH, O_RDONLY)) == -1)
    {
        printf("open FIFO_PATH error!\n");
        return -1;
    }
    
    if((ret = read(fd, buffer, sizeof(buffer))) == -1)
    {
        printf("read error!\n");
        return -1;
    }

    printf("Received: %s\n", buffer);

    close(fd);
    return 0;
}
