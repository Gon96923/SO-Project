#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


// int main(int argc, char * argv[]) {
//     char buf[1024];
//     int bytes_read;
    
//     if(mkfifo("fifo", 0777)<0) perror("mkfifo");

//     int fd_log = open("log.txt", O_CREAT | O_TRUNC | O_WRONLY, 0600);
//     int fd_npipe = open("fifo", O_RDONLY); //server lê do pipe

//     while((bytes_read=read(fd_npipe, buf, 1024))>0) {
//         write(fd_log, buf, bytes_read);
//     }
//     close(fd_log);
//     close(fd_npipe);

//     return 0;
// }

#define nop 1
#define bcompress 2
#define bdecompress 3
#define gcompress 4
#define gdecompress 5
#define encrypt 2
#define decrypt 3



int main(int argc, char * argv[])
{
    int fd1;
    int i = 0;
    char *source = malloc(sizeof(char) * 100);
    char *destiny = malloc(sizeof(char) * 100);

    char * myfifo = "/tmp/myfifo";

    mkfifo(myfifo, 0666);

    char *str1[1024];
    while (1)
    {
        fd1 = open(myfifo,O_RDONLY);
        if (read(fd1, str1, sizeof(str1)) < 0) {
            source = str1[0];
            destiny = str1[1];
            for (i=2;i<sizeof(str1)-2;i++) {
            if (strcmp(str1[i],"bcompress")) {
                execl("bcompress.o",NULL); //não faço ideia disto
            }
            else if (strcmp(str1[i],"bdecompress")) {

            }
            else if (strcmp(str1[i],"decrypt")) {

            }
            else if (strcmp(str1[i],"encrypt")) {

            }
            else if (strcmp(str1[i],"gcompress")) {

            }
            else if (strcmp(str1[i],"gdecompress")) {

            }
            else if (strcmp(str1[i],"nop")) {

            }
            }
        }


        close(fd1);
        
    }
    return 0;
}