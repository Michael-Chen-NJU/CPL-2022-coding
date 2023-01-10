/**
* file:uc-server.c
*
* Created by HW on 1/4/2023.
*/
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#pragma comment(lib, "ws2_32.lib")

int main() {
    const char *NAME = NULL; //ip(hostname)
    const char *SERVICE = "8000"; //port number

    struct addrinfo hints = {/*返回某一个标准的ip地址*/
            .ai_family = AF_INET, //如只关心“IPv4的地址”不关心“IPv6”
            .ai_socktype = SOCK_STREAM, // TCP (not UDP)
            .ai_flags = AI_PASSIVE // use "0.0.0.0" 只能够用于绑定操作
    };

    struct addrinfo *bind_addr; //把ip地址相关信息封装的结构体

    //修改bind_addr，使得其指向封装ip地址链表的头指针
    if (getaddrinfo(NAME, SERVICE, &hints, &bind_addr) != 0) {
        //printf: standard output
        //fprintf: standard error
        fprintf(stderr, "getaddrinfo() failed\n");
        exit(EXIT_FAILURE);
    }

    //create socket创建一个链接的门卫
    //socket_listen: file descriptor(文件描述符) >= 0; -1 :error
    unsigned long long socket_listen = socket(bind_addr->ai_family,/*IPv4*/
                                              bind_addr->ai_socktype,/*TCP*/
                                              bind_addr->ai_protocol);
    if (socket_listen == -1) {
        fprintf(stderr, "socket() failed\n");
        exit(EXIT_FAILURE);
    }

    //bind 绑定 0:success; -1:error
    //将门卫与指定的ip地址绑定
    if (bind(socket_listen,
             bind_addr->ai_addr,
             bind_addr->ai_addrlen) != 0) {
        fprintf(stderr, "bind() failed\n");
        exit(EXIT_FAILURE);
    }
    //freeaddrinfo(bind_addr);
    //listen 0：success ;-1 : error
    //第二个参数 ：限制有多少个请求可以在此等待，剩余的请求将被丢弃
    if (listen(socket_listen, 32) != 0) {
        fprintf(stderr, "listen() failed\n");
        exit(EXIT_FAILURE);
    }

    //accept :block until there is a new connection from the clients
    //accept : fd >= 0; -1 : error
    //return a socket_client
    //TODO:use select instead
    //two pointers
    unsigned long long socket_client = accept(socket_listen, NULL, NULL);
    if (socket_client == -1) {
        fprintf(stderr, "accept() failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Connection Established\n");
    char text[1024] = {0};
    int bytes_received = recv(socket_client, text, sizeof(text),0);//return how many bytes has received
    if(bytes_received == -1) {
        fprintf(stderr, "recv() failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Received %d bytes: %.*s\n",
           bytes_received,bytes_received,text);

    //close the socket
    //mind the time that the server and client must be closed at the same time
    close(socket_listen);
    close(socket_client);
    return 0;
}
