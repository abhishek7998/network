#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
int main()
{
int ssock,csock;
int a,b,c;
unsigned int len;
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
{ // binding port & IP
perror("bind: ");
exit(-1);
}
if((listen(ssock,5))==-1)
{ // listening for client
perror("listen: ");
exit(-1);
}
if((csock=accept(ssock,(struct sockaddr *)&client,&len))==-1)
{ // accepting connectn
perror("accept: ");
exit(-1);
}
while(1)
{
recv(csock,&a,sizeof(a),0);
c=1;
for(b=1;b<=a;b++)
c*=b;
send(csock,&c,sizeof(c),0);
// sending data to client...
printf("\nSent Factorial is=: %d\n",c);
}
close(ssock);
}


