// #include <unistd.h>
// #include <fcntl.h>
// #include <string.h>
// #include <stdio.h>


// int main (int argc, char argv[]) {
//     char buffer[4000];

//         int bRead = 0;
//         while((bRead = read(STDIN_FILENO, buffer, 4000)) > 0) {
//             if(buffer[bRead - 1] == '\n') buffer[--bRead] = 0;
//         }


//         int client_server_fifo = open("fifo_cl-sv", O_WRONLY);
//         int server_client_fifo = open("fifo_sv-cl", O_RDONLY);
//         write(client_server_fifo, buffer, bRead);
//         close(client_server_fifo);

//         while((bRead = read(server_client_fifo, buffer, 4000)) > 0)
//         write(STDOUT_FILENO, buffer, bRead);
//         close(server_client_fifo);
// }

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char * argv[]) {
    char buf[1024];
    int bytes_read;
    
    if(mkfifo("fifo", 0777)<0) perror("mkfifo");

    int fd_npipe = open("fifo", O_WRONLY); //cliente escreve para o pipe

    while((bytes_read=read(0, buf, 1024))>0) {
        write(fd_npipe, buf, bytes_read);
    }
    
    close(fd_npipe);

    return 0;
}