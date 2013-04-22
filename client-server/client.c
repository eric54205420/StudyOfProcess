#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc,char **argv){
    int z;
    char *srvr_addr = "127.0.0.1";//定义主机地址
    char *srvr_port = "1121";//定义端口,自己的学号后四位
    struct sockaddr_in adr_srvr;
    int len_inet;
    int s;
    char dtbuf[128]="2010201211";//要发送的信息,学号
    
    s = socket(PF_INET,SOCK_STREAM,0);//定义套接字
    memset(&adr_srvr,0,sizeof(adr_srvr));
    adr_srvr.sin_family = AF_INET;//初始化family 为AF_INET
    adr_srvr.sin_port = htons(atoi(srvr_port));//初始化端口为 srvr_port
    adr_srvr.sin_addr.s_addr = inet_addr(srvr_addr);//初始化地址为srvr_addr
    len_inet = sizeof(adr_srvr);
    z = connect(s,(void *)&adr_srvr,len_inet);//连接服务器
    //printf("---\n");
    z = write(s,dtbuf,15);//将学号写入到s，并发送到服务器端
    //printf("%d\n",z);
    //z = read(s,&dtbuf,sizeof(dtbuf)-1);
    //dtbuf[z]=0;
    //printf("Data & Time is: ---%s---\n",dtbuf);
    printf("The student number has been sent\n"); //反馈，已经发送成功
    close(s);//关闭套接字
    puts("");

    return 0;
}

