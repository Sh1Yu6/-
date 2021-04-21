
/************************************************
#
#      Filename: wev_server.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2021-04-19 16:19:41
# Last Modified: 2021-04-19 17:22:54
#***********************************************/
#include <cerrno>
#include <cstdio>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <unistd.h>
#include <sys/epoll.h>
#include <cstring>
#include <signal.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <cstdlib>
#include <sstream>
using namespace std;

constexpr int kBufSize = 1024;
void http_request(int fd);

int main(int argc, char *argv[])
{
    int sockFd = socket( AF_INET, SOCK_STREAM, 0 );
    int op = 1;
    setsockopt( sockFd, SOL_SOCKET, SO_REUSEADDR, &op, sizeof(op) );

    
    struct sockaddr_in sockAddr;
    bzero(&sockAddr, sizeof(sockAddr));
    sockAddr.sin_port = htons(8888);
    sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind( sockFd, (sockaddr*)&sockAddr, sizeof(sockAddr) );

    listen( sockFd, 128 );
    
    int epfd = epoll_create(1024);
    
    struct epoll_event ev;
    ev.data.fd = sockFd;
    ev.events = EPOLLIN;
    epoll_ctl( epfd, EPOLL_CTL_ADD, sockFd, &ev );

    struct epoll_event events[1024];
    while(true){
        int nReady = epoll_wait( epfd, events, 1024, -1 );
        if( nReady < 0 ){
            if( errno == EINTR || errno == ECONNABORTED ){
                continue;
            }
            break;
        }

        for(int i = 0; i < nReady; ++i){

            int fd = events[i].data.fd;
            if( fd == sockFd ){
                int clientFd = accept( sockFd, nullptr, nullptr );

                struct epoll_event ev;
                ev.data.fd = clientFd;
                ev.events = EPOLLIN;
                epoll_ctl( epfd, EPOLL_CTL_ADD, clientFd, &ev );

            }else{
                http_request(fd);
            }
            
        }
    }

    close(sockFd);
    return 0;
}

void http_request(int fd){
    char buf[kBufSize];
    int n = read(fd, buf, kBufSize);
    if( n <= 0 ){
        close(fd);
        return;
    }
    istringstream is{buf}; 
    string reqType;
    string fileName;
    string protocal;
    is >> reqType >> fileName >> protocal;
    cout << reqType << " " << fileName << " " <<  protocal << endl;

    struct stat st;
    //if( stat(fileName.c_str(), &st) <0 ){
        cout << "a"<< endl;
        int a = sprintf(buf, "HTTP/1.1 403 forbidden");
        write(fd, buf, a);
    //}

}

