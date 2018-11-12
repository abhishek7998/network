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
int main(){
int sock;
// client socket discriptor
int n;int i;int c[100];
int j;
i=0;
unsigned int len;
//char ch[3]="no";
//char ch1[3];
struct sockaddr_in client;
if((sock=socket(AF_INET,SOCK_STREAM,0))==-1){ // client socket is created..
perror("socket: ");
exit(-1);
}
client.sin_family=AF_INET;
client.sin_port=htons(10001);
// initializing socket parameters
client.sin_addr.s_addr=INADDR_ANY;
//inet_addr("127.0.0.1");
bzero(&client.sin_zero,0); //appending 8 byte zeroes to 'struct sockaddr_in', to make it equal in size with 'struct sockaddr'..
len=sizeof(struct sockaddr_in);
if((connect(sock,(struct sockaddr *)&client,len))==-1){ //conneting to client
perror("connect: ");
exit(-1);
}
while(i!=-1){
printf("Enter the composite number:\n");
scanf("%d",&n);
int k;
k=0;
send(sock,&n,sizeof(n),0);
// sending data back to client...
recv(sock,&c,sizeof(c),0);
recv(sock,&j,sizeof(j),0);
printf("prime factors of inputed composite number is:\n");
while(k<j)
{
printf("%d \n",c[k]);
k++;
}
int q;
printf("Press 0 to continue and 1 to exit\n");
scanf("%d",&q);
if(q==0)
i=0;
else
i=-1;
}
close(sock);
exit(0);
}
