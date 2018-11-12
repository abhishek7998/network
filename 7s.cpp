#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;
int isprime(int n)
{
int i;
for(i=2;i*i<=n;i++)
{
if(n%i==0)
return 0;
}
return 1;
}
int main(){
int ssock,csock;
// creating server and clinet socket discriptor
int n,c[100];
int i,j;
unsigned int len;
struct sockaddr_in server,client; // creating server & client socket object
if((ssock=socket(AF_INET,SOCK_STREAM,0))==-1){
perror("socket: is not created");
exit(-1);
}
server.sin_family=AF_INET;
server.sin_port=htons(10001);
// initializing server socket parameters..
server.sin_addr.s_addr=INADDR_ANY;
//inet_addr("127.0.0.1");
bzero(&server.sin_zero,0); //appending 8 byte zeroes to 'struct sockaddr_in', to make it equal in size with 'struct sockaddr'..
len=sizeof(struct sockaddr_in);
if((bind(ssock,(struct sockaddr *)&server,len))==-1){ // binding port & IP
perror("bind: ");
exit(-1);
}
if((listen(ssock,5))==-1){
// listening for client
perror("listen: ");
exit(-1);
}
if((csock=accept(ssock,(struct sockaddr *)&client,&len))==-1){ // accepting connectn
perror("accept: ");
exit(-1);
}
while(1){
i=2;j=0;
recv(csock,&n,sizeof(n),0);
while(n!=1)
{
if(isprime(i)==1)
{
while(n%i==0&&n!=1)
{
n=n/i;
c[j]=i;
j++;
}
i++;
}
else if(isprime(i)==0)
{
i++;
}
}
int k;
k=0;
printf("Sent Value:\n");
while(k<j)
{
printf("%d ",c[k]);
k++;
}
printf("\n");
send(csock,&c,sizeof(c),0);
send(csock,&j,sizeof(j),0);
}
close(ssock);
}

