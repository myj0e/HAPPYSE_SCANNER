#ifndef SEND_h
#define SEND_H

//add -lws2_32 after g++ while you compile this file

/*
/input: hostname like "192.168.1.1",port like "443"
/output:
    #define SUCCEED 0
    #define WSASTARTUP_ERROR 1
    #define GETADDRINFO_ERROR 2
    #define NSOCKET_ERROR 3
    #define CONNECT_ERROR 4

*/

int TcpScan(char* hostname,char* port);

#include"src/send.cc"
#endif