#pragma once
#include "common.h"
#define SA struct sockaddr 
class Client{
	public:
		Client(string ip,int port);
		int SentData(string data);
		int RecieveData(string& rec_d);
	private:

		int sockfd, connfd; 
		struct sockaddr_in servaddr, cli; 
};