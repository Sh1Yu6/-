
/************************************************
#
#      Filename: tcpClient.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-03-07 19:56:18
# Last Modified: 2021-05-03 16:21:54
#***********************************************/
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <string>
//#include <sys/types.h>
using namespace std;

constexpr int kPort = 8888;
constexpr int kMessageLen = 1024;
int main(int argc, char *argv[])
{
    int socketFd = socket(PF_INET, SOCK_STREAM, 0);
    if(socketFd == -1){
        cout << "Failed to create socket!" << endl;
        exit(-1);
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(kPort);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    

    int ret = connect(socketFd, 
                     (struct sockaddr*)&serverAddr, 
                     sizeof(struct sockaddr));
    if(ret < 0){
        cout << "Failed to connect server!" << endl;
        exit(-1);
    }

    char sendBuf[kMessageLen];
    char recvBuf[kMessageLen];
    while(true){
        memset(recvBuf, 0, kMessageLen);
        cout << "input: ";
        string str;
        cin >> str;
        for(int i = 0; i < (int)str.size(); ++i){
            str[i] = str[i] ^ 0x10;
        }

        ret = send(socketFd, str.c_str(), str.size(), 0);
        if(ret <= 0){
            cout << "Failed to send data!" << endl;
            break;
        }
        if(strcmp(sendBuf, "quit") == 0){
            break;
        }
        //ret = recv(socketFd, recvBuf, kMessageLen-1, 0);
        //recvBuf[ret] = '\0';
        //cout << recvBuf << endl;
        //usleep(2000000);
    }
    close(socketFd);

    return 0;
}

