#include <stdio.h>
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
void main()
{
int ssock,csock;
int a,b,c,n,i,j;
unsigned int len;
char arr[100];
// creating server and clinet socket discriptor
struct sockaddr_in server,client; // creating server & client socket object
if((ssock=socket(AF_INET,SOCK_STREAM,0))==-1)
{
perror("socket: is not created");
exit(-1);
}
server.sin_family=AF_INET;
server.sin_port=htons(10000);
// initializing server socket parameters..
server.sin_addr.s_addr=INADDR_ANY;
//inet_addr("127.0.0.1");
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
recv(csock,&n,sizeof(n),0);
a=(2*n)-1;
for(i=0;i<n;i++){
a--;
for(j=0;j<2*n;j++)
arr[j]=' ';
for(j=i;j<=a;j+=2)
arr[j]='*';
send(csock,arr,sizeof(arr),0);
}
printf("The pattern is sent\n");
}
close(ssock);
}

