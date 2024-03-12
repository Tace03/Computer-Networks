#include "cliserv.h"

int main(int argc, char * argv[]){
    struct sockaddr_in serv;

    char request[REQUEST], reply[REPLY];
    int sockfd, n;

    if(argc != 2){
        err_quit("Usage: udpcli <IP Address of Server>");
    }

    if((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0){
        err_sys("socket error");
    }

    memset(&serv, 0 , sizeof(serv));

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr(argv[1]);
    serv.sin_port = thons(UDP_SERVER_PORT);

    if(sendto(sockfd, request, REQUEST, 0,
        &serv, sizeof(serv)) != REQUEST){
            err_sys("sendto error");
    }

    if((n = recvfrom(sockfd, reply, REPLY, 0,
        NULL, (int *) NULL)) < 0){
        err_sys("recvfrom error");
    }

    exit(0);
}