#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SERVER_IP "127.0.0.1"
#define PORT 9999
#define MAX_CONNECTION 5






char buffer[1024];


void* recv_client(void *client_sock_arg){

    int client_sock = *((int *)client_sock_arg);

    while(1){
        sleep(100);
    }
    
}


int main(){

    char *ip = SERVER_IP;
    int port = PORT; 

    int server_sock,client_sock;
    struct sockaddr_in server_addr,client_addr;
    socklen_t addr_size;
    int n;

    // server socket creaated
    server_sock = socket(AF_INET,SOCK_STREAM,0);

    if (server_sock<0){
        perror("[-] socket creation failed.\n");
        exit(1);
    }

    printf("[+] TCP Socket created.\n");


    // setting server sock_addr on given ip and port
    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    // inet_pton(AF_INET,ip,&server_addr.sin_addr);

    // binding socket and server_addr together

    n = bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr));

    if (n<0){
        perror("[-] Binding failed.\n");
        exit(1);
    }

    printf("[+] Binding Success.\n");

    listen(server_sock,MAX_CONNECTION);
    printf("[+] Listening for Connections...\n");

    while(1){

        addr_size = sizeof(client_addr);
        client_sock = accept(server_sock,(struct sockaddr*)&client_addr,&addr_size);

        if (client_sock<0){
            perror("[-] Client Acception Failed.\n");
            continue;
        }

        printf("[+] new client connected.\n");

        pthread_t recv_client;

        int *pclient = malloc(sizeof(int));
        *pclient = client_sock;

        pthread_create(&recv_client,NULL,&recv_client,pclient);        

        /* 
            -store all client in an array of max connections length
            -then handle all recv operations in recv thread.
            -store all incoming messages from each client to a queue.
            -send whenever the queue has elements in it using sperate thread 
                for handling brodcast 
            -handle race conditions
        */
    }

    return 0;
}