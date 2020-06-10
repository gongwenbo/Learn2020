#include "client.h"
Client::Client(string ip,int port){
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr(ip.c_str()); 
	servaddr.sin_port = htons(port);
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("connection with the server failed...\n"); 
		exit(0); 
	} 			
	
}
int Client::SentData(string data){
	write(sockfd, data.c_str(), data.size()+1); 
	 
}
int Client::RecieveData(string& rec_d){
	char buff[1024];
	read(sockfd, buff, sizeof(buff));
	cout<<"RecieveData"<<buff<<"\n";
}