#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;
int main(){

//void main(){
int sock;      // client socket discriptor
int n;int i=0;int c;
unsigned int len;
int l,k;
struct student
{
	int e_id;
	int t_l;
	int curr_bal;
	//int t_l;
	int ex_l;
};

//char ch[3]="no";
//char ch1[3];

struct sockaddr_in client;
if((sock=socket(AF_INET,SOCK_STREAM,0))==-1){  // client socket is created..
perror("socket: ");
exit(-1);
}

client.sin_family=AF_INET;
client.sin_port=htons(10001);        // initializing  socket  parameters
client.sin_addr.s_addr=INADDR_ANY;
//inet_addr("127.0.0.1");
bzero(&client.sin_zero,0); //appending 8 byte zeroes to 'struct sockaddr_in', to make it equal in size with 'struct sockaddr'..


len=sizeof(struct sockaddr_in);
if((connect(sock,(struct sockaddr *)&client,len))==-1){  //conneting to client
perror("connect: ");
exit(-1);
}
while(i!=1){
printf("enter employee id \n");
scanf("%d",&n);
printf("Enter the leave duration \n");
scanf("%d",&l);
send(sock,&n,sizeof(n),k);
send(sock,&l,sizeof(l),0);
recv(sock,&k,sizeof(k),0);
if(k==-1)
{
	printf("Leave can't be sanctioned \n");
}
else
{
	printf("Leave sanctioned \n");
	printf("Remaining balance %d\n",k);
}
printf("To exit press 1 and to continue press 0\n");
scanf("%d",&c);
i=c;

}
                           // receiving data from client
//printf("\ndo you want to exit...press 'no'\n");


//scanf("%s",ch1);
//printf("%s\n",ch1);
//printf("%s\n",ch);


close(sock);
exit(0);
}

