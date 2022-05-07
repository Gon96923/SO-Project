#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>


int main (int argc, char argv[]) {
    char string[4000];

        int bytesRead = 0;
        while((bytesRead = read(STDIN_FILENO, string, 4000)) > 0) {
            if(string[bytesRead - 1] == '\n') string[--bytesRead] = 0;
        }


        int client_server_fifo = open("client_server_fifo", O_WRONLY);
        int server_client_fifo = open("server_client_fifo", O_RDONLY);
        write(client_server_fifo, string, bytesRead);
        close(client_server_fifo);

        while((bytesRead = read(server_client_fifo, string, 4000)) > 0)
        write(STDOUT_FILENO, string, bytesRead);
        close(server_client_fifo);
}