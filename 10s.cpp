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

int ssock,csock;       // creating server and clinet socket discriptor
int n,c;int l,k;
unsigned int len;
struct student
{
	int e_id;
	int t_l;
	int curr_bal;
	int ex_l;
};

struct sockaddr_in server,client;   // creating server & client socket object

if((ssock=socket(AF_INET,SOCK_STREAM,0))==-1){
	perror("socket: is not created");
	exit(-1);
}

server.sin_family=AF_INET;
server.sin_port=htons(10001);       // initializing server socket parameters..
server.sin_addr.s_addr=INADDR_ANY;
//inet_addr("127.0.0.1");
bzero(&server.sin_zero,0); //appending 8 byte zeroes to 'struct sockaddr_in', to make it equal in size with 'struct sockaddr'..
len=sizeof(struct sockaddr_in);
if((bind(ssock,(struct sockaddr *)&server,len))==-1){  // binding port & IP  
	perror("bind: ");
	exit(-1);
}
if((listen(ssock,5))==-1){     // listening for client
	perror("listen: ");                     
	exit(-1);
}
if((csock=accept(ssock,(struct sockaddr *)&client,&len))==-1){  // accepting connectn
	perror("accept: ");                         
	exit(-1);
}
struct student s[11];
s[0].e_id=1;
s[0].t_l=30;
s[0].curr_bal=13;
s[0].ex_l=2;
s[1].e_id=2;
s[1].t_l=30;
s[1].curr_bal=11;
s[1].ex_l=4;
s[2].e_id=3;
s[2].t_l=30;
s[2].curr_bal=9;
s[2].ex_l=0;
s[3].e_id=4;
s[3].t_l=30;
s[3].curr_bal=5;
s[3].ex_l=0;
s[4].e_id=5;
s[4].t_l=30;
s[4].curr_bal=29;
s[4].ex_l=10;
s[5].e_id=6;
s[5].t_l=30;
s[5].curr_bal=17;
s[5].ex_l=12;
s[6].e_id=7;
s[6].curr_bal=32;
s[6].t_l=40;
s[6].ex_l=0;
/*
s[7].r_no=8;
s[7].section=2;
s[7].ogpa=8.21;
s[7].branch='A';
s[7].name='K';
s[8].r_no=9;
s[8].section=2;
s[8].ogpa=3.14;
s[8].branch='E';
s[8].name='T';
s[9].r_no=10;
s[9].section=2;
s[9].ogpa=9.99;
s[9].branch='E';
s[9].name='Q';*/
while(1){
	recv(csock,&n,sizeof(n),0);
	recv(csock,&l,sizeof(l),0);
	struct student a=s[n-1];
	printf("Details\n");
	printf("Total leaves %d\n",a.t_l);
	printf("Current balance %d\n",a.curr_bal);
	printf("Extra leaves %d\n",a.ex_l);
	if(a.curr_bal+a.ex_l<l)
	{
		printf("Leave can't be sanctioned \n");
		k=-1;
		send(csock,&k,sizeof(k),0);
	}
	else
	{
		printf("Leave sanctioned\n");
		k=0;
		a.curr_bal=a.curr_bal-l;
		k=a.curr_bal;
		send(csock,&k,sizeof(k),0);
	}
}
close(ssock);
}

