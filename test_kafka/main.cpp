#include "common.h"
#include "producer.h"
#include "comsumer.h"
int main(int argc,char ** argv){
	if(argc<2){
		cout<<"add argc\n";
		return 0;
	}
	int i=atoi(argv[1]);
	if(i==0){
		cout<<"producer\n";
		TestKafkaClient();		
	}else{
		cout<<"comsumer\n";
		TestComsumer();
	}

}

