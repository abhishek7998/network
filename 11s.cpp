#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h> #include <unistd.h>
#include<bits/stdc++.h>
using namespace std;
//int main(){
struct list
{ int word; int meaning;
};
int main()
{ int ssock,csock; int b,c,n,x,i; struct list mylist[20];
for(i=0;i<15;i++)
{ mylist[i].word=i+65; mylist[i].meaning=i+65+1;
}
for(i=15;i<20;i++)
{ mylist[i].word=i+65; mylist[i].meaning=-1;
} unsigned int len; struct sockaddr_in server,client;
if((ssock=socket(AF_INET,SOCK_STREAM,0))==-1)
{ perror("socket: is not created");
exit(-1);
} server.sin_family=AF_INET; server.sin_port=htons(10000);	// initializing server socket parameters.. server.sin_addr.s_addr=INADDR_ANY;
bzero(&server.sin_zero,0); len=sizeof(struct sockaddr_in);
if((bind(ssock,(struct sockaddr *)&server,len))==-1)
{ perror("bind: ");
exit(-1);
}
if((listen(ssock,5))==-1)
{
perror("listen: "); exit(-1);
}
if((csock=accept(ssock,(struct sockaddr *)&client,&len))==-1)
{ perror("accept: "); exit(-1);
} while(1)
{ char data[1]; int ret,mean;
recv(csock,&data,sizeof(data),0);
int val=data[0]-65; ret=mylist[val].meaning;
if(ret!=-1)
{
send(csock,&ret,sizeof(ret),0); recv(csock,&mean,sizeof(mean),0); mylist[val].meaning=mean;
}
else
send(csock,&ret,sizeof(ret),0);
} close(ssock); }
