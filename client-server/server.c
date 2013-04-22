#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc,char **argv){
    int z;
    char *srvr_addr="127.0.0.1";//定义主机地址
    char *srvr_port="1121";//定义端口，自己学号后四位
    struct sockaddr_in adr_srvr;
    struct sockaddr_in adr_clnt;
    int len_inet;
    int s;
    int c;
    int n;
    time_t td;
    char dtbuf[128];
    
    s = socket(PF_INET,SOCK_STREAM,0);//定义socket
    memset(&adr_srvr,0,sizeof(adr_srvr));
    adr_srvr.sin_family = AF_INET;//初始化family 为 AF_INET
    adr_srvr.sin_port = htons(atoi(srvr_port));//初始化端口 为*srvr_port
    adr_srvr.sin_addr.s_addr = inet_addr(srvr_addr);//初始化地址 为*srvr_addr
    adr_srvr.sin_addr.s_addr = INADDR_ANY;
    len_inet = sizeof(adr_srvr);
    z = bind(s,(struct sockaddr *)&adr_srvr,len_inet);//socket绑定到指派的地址上
    z = listen(s,10);//准备套接字，等待连接请求
    while(1){//循环等待请求
	//printf("---\n");
        len_inet = sizeof(adr_clnt);
        //printf("---\n");
	c = accept(s,(struct sockaddr *)&adr_clnt,&len_inet); //等待客户连接请求，请求存入c中
       	//printf("---\n"); 
        //time(&td);
        //n = (int)strftime(dtbuf,sizeof(dtbuf),"time:%A %b %d %H:%M:%S %Y\n",localtime(&td));
        z = read(c,&dtbuf,15); //读取c中的dtbuf信息
	//printf("---%d---\n",z);
        //z = write(c,dtbuf,n);
	printf("Getting a student number: %s\n",dtbuf);//打印信息
        close(c);
    }
    return 0;
}

