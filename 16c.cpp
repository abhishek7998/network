	#include <stdio.h>
    #include <stdlib.h>
    #include <sys/types.h>         
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <errno.h>
    #include <string.h>
    #include <arpa/inet.h>
    #include <unistd.h>
     
     
    int main(){
    int sock;      // client socket discriptor
    int a,b,i;
    char pwd[20];
    unsigned int len;
    char ch[4]="yes";
    char ch1[4];
     
    struct sockaddr_in client;
    if((sock=socket(AF_INET,SOCK_STREAM,0))==-1){  // client socket is created..
    perror("socket: ");
    exit(-1);
    }
     
    client.sin_family=AF_INET;
    client.sin_port=htons(10010);        // initializing  socket  parameters
    client.sin_addr.s_addr=INADDR_ANY;
    //inet_addr("127.0.0.1");
    bzero(&client.sin_zero,0); //appending 8 byte zeroes to 'struct sockaddr_in', to make it equal in size with 'struct sockaddr'..
     
     
    len=sizeof(struct sockaddr_in);
    if((connect(sock,(struct sockaddr *)&client,len))==-1){  //connecting to client
    perror("connect: ");
    exit(-1);
    }
    printf("\nenter server password\n");
    scanf("%s",pwd);
     
    send(sock,&pwd,sizeof(pwd),0);    // sending data back to client...
    recv(sock,&b,sizeof(b),0);
    if(b==0)
    {
    char say[3]="Hi";
    send(sock,&say,sizeof(say),0);
    char reply[6];
    recv(sock,&reply,sizeof(reply),0);
    printf("%s\n",reply);
    }
    //printf("%d\n",b);	// receiving data from client
     
    close(sock);
     
    }
