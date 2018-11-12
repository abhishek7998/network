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
int sock;      // client socket discriptor
int a,b,i;
int add,sub,mul,div;

unsigned int len;
char ch[4]="yes";
char ch1[4];

struct sockaddr_in client;
if((sock=socket(AF_INET,SOCK_STREAM,0))==-1){  // client socket is created..
perror("socket: ");
exit(-1);
}

client.sin_family=AF_INET;
client.sin_port=htons(10000);        // initializing  socket  parameters 
client.sin_addr.s_addr=INADDR_ANY;
//inet_addr("127.0.0.1");
bzero(&client.sin_zero,0); //appending 8 byte zeroes to 'struct sockaddr_in', to make it equal in size with 'struct sockaddr'.. 


len=sizeof(struct sockaddr_in);
if((connect(sock,(struct sockaddr *)&client,len))==-1){  //conneting to client
perror("connect: ");
exit(-1);
}
while(1){
printf("enter number n and m:\n");
scanf("%d%d",&a,&b);

send(sock,&a,sizeof(a),0);    // sending data back to client...
send(sock,&b,sizeof(b),0);

recv(sock,&add,sizeof(add),0);
printf("n+m : %d\n",add);	// receiving data from client
recv(sock,&sub,sizeof(sub),0);
printf("n-m : %d\n",sub);
recv(sock,&mul,sizeof(mul),0);
printf("n*m : %d\n",mul);
recv(sock,&div,sizeof(div),0);
printf("n/m : %d\n",div);

printf("\ndo you want to exit...press 'yes'\n");


scanf("%s",ch1);
//printf("%s\n",ch1);
//printf("%s\n",ch);

if((i=strcmp(ch,ch1))==0){
close(sock);
exit(0);
}

}

}
