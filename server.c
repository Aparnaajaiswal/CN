#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#define MAX 1024

int main(){
    int sd,bd,ad;
    char buff[MAX];
    struct socketaddr_in servaddr, cliaddr;
    socklen_t clilen;
    clilen= sizeof(cliaddr);
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family= AF_INET;
    servaddr.sin_port= htons(9999);
    servaddr.sin_addr.s_addr= INADDR_ANY;

    sd=socket(AF_INET, SOCK_STREAM,0);
    bd=bind(sd,(struct sockaddr*),&servaddr,sizeof(servaddr));
    listen(sd,5);
    ad=accept(sd,(struct sockaddr*),&cliaddr,&clilen);

    while(1){
        bzero(&buff,sizeof(buff));
        recv(ad,buff,sizeof(buff));
        printf("message recieved is: %s",buff);
        
    }
    close(sd);
}
