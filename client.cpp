
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>
#include<arpa/inet.h>
#include <string>

int main(){
  int clientSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;



  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  


  serverAddr.sin_family = AF_INET;

  serverAddr.sin_port = htons(60000);

  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  


  addr_size = sizeof serverAddr;
while(1){
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
printf("\n Enter the name of file which has the data :");
char data[1024];
gets(data);
::send(clientSocket,data, strlen(data),0);
  recv(clientSocket, buffer, 1024, 0);


  printf("\n Data received: %s      \n",buffer);   
  printf("\n");

usleep(2000000);
  }
  return 0;
}
