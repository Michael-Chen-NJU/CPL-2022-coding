/**
 * file:uc-client.c
 *
*Created by HW on 1/7/2023.
*/
#include "basic/networking.h"
//网络通信需要包含的头文件


int main(int argc, char *argv[]) {
    //传递ip地址和端口号
    //argv[0]：程序名 argv[1]：ip地址  argv[2]：port
    if (argc < 3) {
        fprintf(stderr, "Usage: uc-client hostname port\n");
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints = {
            .ai_socktype = SOCK_STREAM  // TCP (not UDP)
    };
    struct addrinfo *server_addr;//得到需要链接的server端的信息
    if (getaddrinfo(argv[1], argv[2], &hints, &server_addr) != 0) {
        fprintf(stderr, "getaddrinfo() failed\n");
        exit(EXIT_FAILURE);
    }/*返回某一个标准的ip地址链表的头指针*/

    //create socket创建一个链接的门卫
    //socket_server: file descriptor(文件描述符) >= 0; -1 :error
    int socket_server = socket(server_addr->ai_family,/*IPv4*/
                               server_addr->ai_socktype,/*TCP*/
                               server_addr->ai_protocol);/*协议*/
    if (socket_server == -1) {
        fprintf(stderr, "socket() failed\n");
        exit(EXIT_FAILURE);
    }
    //与server端建立链接
    if (connect(socket_server, server_addr->ai_addr, server_addr->ai_addrlen) == -1) {
        fprintf(stderr, "connect() failed\n");
        exit(EXIT_FAILURE);
    }
    freeaddrinfo(server_addr);
    printf("Connection Established\n");
    for (int i = 0; i < 10; ++i) {
        //use an ultimate loop to keep send and receive
        printf("Now send a text message to the server.\n");

        char text[1024];
        scanf("%s",text);
        //chances are that the text is too big that the message can't be sent at one time
        SEND(socket_server, text);
        RECEIVE(socket_server, text);
    }

    //close the socket
    close(socket_server);
    return 0;
}
