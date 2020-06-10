#include "common.h"
#include "client.h"
int main(){
	string ip="127.0.0.1";
	int port=999;
	string buf;
	auto cli=make_shared<Client>(ip,port);
	cli->SentData("I am client");
	cli->RecieveData(buf);
}