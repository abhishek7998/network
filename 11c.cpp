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
{ int word;
};
int main()
{ int sock;	// client socket discriptor struct list mylist[20]; int a,b,i,n; for(i=0;i<20;i++) mylist[i].word=i+65;
unsigned int len; char ch[3]="ex"; char match[4]="no"; char ch1[3]; struct sockaddr_in client;
if((sock=socket(AF_INET,SOCK_STREAM,0))==-1)
{ perror("socket: "); exit(-1);
}
client.sin_family=AF_INET;
	client.sin_port=htons(10000);	// initializing	socket	parameters
client.sin_addr.s_addr=INADDR_ANY;
bzero(&client.sin_zero,0); len=sizeof(struct sockaddr_in);
if((connect(sock,(struct sockaddr *)&client,len))==-1)
{ perror("connect: ");
exit(-1);
} while(1)
{ printf("List of words is->\n"); for(i=0;i<20;i++) printf("%d. %c\n",i+1,mylist[i].word);
char wd[2],mean[1]; int ans,t=65;
printf("Choose Word from list:\n"); scanf("%s",wd); send(sock,&wd,sizeof(wd),0);
recv(sock,&ans,sizeof(ans),0); if(ans==-1)
{ printf("Meaning Of word not found in dict .\n");
scanf("%d",&t); send(sock,&t,sizeof(t),0); printf("Meaning Stored!\n");
}
else
{ printf("Meaning Found in dict.\n Meaning is-> %c",ans);
}
printf("\nDo you want to exit...press 'ex'\n"); scanf("%s",ch1); if((i=strcmp(ch,ch1))==0)
{ close(sock);
exit(0); }
else
printf("\n");
}
}
