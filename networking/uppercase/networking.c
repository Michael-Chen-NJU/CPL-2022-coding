//
// Created by chenbaby on 1/10/23.
//

#include "networking.h"
int RECEIVE(int socket_client,char *text){
    int bytes_received = recv(socket_client, text, 1024,0);//return how many bytes has received
    if(bytes_received == -1) {
        fprintf(stderr, "recv() failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Received %d bytes: %.*s\n",
           bytes_received,bytes_received,text);
    return bytes_received;
}
int SEND(int socket_server,char *text){
    int bytes_sent = send(socket_server, text, 1024,0);//1.the previous build element 2.the information that will be sent 3.
    //to know how many bytes has been sent
    if(bytes_sent == -1){
        fprintf(stderr,"send() failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Send %d bytes\n",bytes_sent);
    return bytes_sent;
}
