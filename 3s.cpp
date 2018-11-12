#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
int ssock,csock;
int a,b,c,fib1,fib2;
unsigned int len;
char ch[1];
struct sockaddr_in server,client;
if((ssock=socket(AF_INET,SOCK_STREAM,0))==-1)
{
perror("socket: is not created");
exit(-1);
}
server.sin_family=AF_INET;
server.sin_port=htons(10000);
server.sin_addr.s_addr=INADDR_ANY;
bzero(&server.sin_zero,0);
len=sizeof(struct sockaddr_in);
if((bind(ssock,(struct sockaddr *)&server,len))==-1)
{
perror("bind: ");
exit(-1);
}
if((listen(ssock,5))==-1)
{
perror("listen: ");
exit(-1);
}
if((csock=accept(ssock,(struct sockaddr *)&client,&len))==-1)
{
perror("accept: ");
exit(-1);
}
while(1)
{
recv(csock,&a,sizeof(a),0);
printf("\nMarks from client : %d ",a);
if( a>=85 && a<=100 )
c=65;
else if( a>=70 && a<=84 )
c=66;
else if( a>=60 && a<=69 )
c=67;
else if( a>=50 && a<=59 )
c=68;
else
c=70;
send(csock,&c,sizeof(c),0);
ch[0]=c;
printf("\nGrade sent to client %s ",ch);
}
close(ssock);
}

