//
// Created by chenbaby on 1/10/23.
//

#ifndef UNTITLED_NETWORKING_H
#define UNTITLED_NETWORKING_H
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int RECEIVE(int socket_client,char *text);
int SEND(int socket_server,char *text);
#endif //UNTITLED_NETWORKING_H
