#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

#define FIFO_PATH "/tmp/myfifo"
#define BUFF_SZ 16

static pthread_t g_tid_recv;
static pthread_t g_tid_send;

static void *fifo_server_runner(void *arg);
static void *dummy_sender(void *arg);

static int fifo_srv_fd;

static void *fifo_server_runner(void *arg)
{
    char buffer[BUFF_SZ];
    int ret;
    char *ptr;

    if((fifo_srv_fd = open(FIFO_PATH, O_RDONLY)) == -1)
    {
        perror("Error open FIFO_PATH: ");
        exit(-1);
    }

    while(1){
        if((ret = read(fifo_srv_fd, buffer, sizeof(buffer))) == -1)
        {
            printf("Reset FIFO!\n");
            close(fifo_srv_fd);
            
            if((fifo_srv_fd = open(FIFO_PATH, O_RDONLY)) == -1)
            {
                perror("Error: ");
                exit(-1);
            }

            continue;
        }
	
        /* remove newline character and replace it with terminating character */
        if((ptr = strchr(buffer, '\n')) != NULL)
        {
            *ptr = '\0';
        }

        printf("Received: %s (len=%d)\n", buffer, (int) strlen(buffer));
    }

    close(fifo_srv_fd);
    pthread_exit(NULL);
}

static void *dummy_sender(void *arg)
{
    int dummy_fd;

    if((dummy_fd = open(FIFO_PATH, O_WRONLY)) == -1)
    {
        perror("Error dummy: ");
        exit(-1);
    }

    while(1)
    {
        sleep(10000);
    }
    
    close(dummy_fd);
    pthread_exit(NULL);
}

int main(void)
{
    int ret;
    
    if((ret = mkfifo(FIFO_PATH, 0600)) == -1)
    {
        if(errno == EEXIST)
        {
            printf("FIFO already exist, skip creating\n");
        }
        else
        {
            perror("Error main: ");
            return -1;
        }
    }

    pthread_create(&g_tid_recv, NULL, fifo_server_runner, NULL);
    pthread_create(&g_tid_send, NULL, dummy_sender, NULL);

    while(1)
    {
        sleep(10000);
    }

    unlink(FIFO_PATH);
    return 0;
}
