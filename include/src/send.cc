#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x501
#include<windows.h>
#include<winsock2.h>
#include<ws2tcpip.h>
#include<stdio.h>
#include<stdlib.h>


#pragma comment(lib,"Ws2_32.lib")
#pragma comment(lib,"Mswsock.lib")
#pragma comment(lib,"AdvApi32.lib")



#define DEFAULT_BUFLEN 512


#define SUCCEED 0
#define WSASTARTUP_ERROR 1
#define GETADDRINFO_ERROR 2
#define NSOCKET_ERROR 3
#define CONNECT_ERROR 4



int TcpScan(char* hostname,char* port){
    WSADATA wsaData;//初始化socket存储数据结构
    SOCKET ConnectSocket =INVALID_SOCKET;
    struct addrinfo *result=NULL,*ptr =NULL,hints;
    //char* sendbuf="This is a test";
    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen=DEFAULT_BUFLEN;
    //验证参数合法性
    /*
    if (argc!=2){
        printf("usage: %s server-name\n",argv[0]);
        return 1;
    }
    */
    //初始化套接字
    iResult = WSAStartup(MAKEWORD(2,2),&wsaData);
    if(iResult !=0){
        //printf("WSASrartup failed with error:%d\n",iResult);
        return WSASTARTUP_ERROR;
    }
    ZeroMemory(&hints,sizeof(hints));
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_protocol=IPPROTO_TCP;
    //解析服务器的地址和端口号
    iResult=getaddrinfo(hostname,port,&hints,&result);
    if ( iResult!=0){
        //printf("getaddrinfo failed with error:%d\n",iResult);
        WSACleanup();
        return GETADDRINFO_ERROR;
    }
    //设置超时




    //尝试连接服务器地址，直到成功
    for(ptr=result;ptr!=NULL;ptr=ptr->ai_next){
        //创建套接字
        ConnectSocket=socket(ptr->ai_family,ptr->ai_socktype,ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET){
            //printf("socket failed with error:%ld\n",WSAGetLastError());
            WSACleanup();
            return NSOCKET_ERROR;
        }
        //向服务器发送请求
        iResult=connect(ConnectSocket,ptr->ai_addr,(int)ptr->ai_addrlen);
        if (iResult==SOCKET_ERROR){
            closesocket(ConnectSocket);
            ConnectSocket=INVALID_SOCKET;
            //continue;
        }
        break;
    }

/*
    ptr=result;
    ConnectSocket=socket(ptr->ai_family,ptr->ai_socktype,ptr->ai_protocol);
    if
    */
    freeaddrinfo(result);
    if(ConnectSocket==INVALID_SOCKET){
        //printf("Unable to connect to server!\n");
        WSACleanup();
        return CONNECT_ERROR;
    }
    //成功连接
    //printf("Successed connected\n");
    closesocket(ConnectSocket);
    WSACleanup();
    return SUCCEED;
}

