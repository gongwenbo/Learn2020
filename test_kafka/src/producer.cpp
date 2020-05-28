#include "producer.h"
#include "rdkafkacpp.h"
void TestKafkaClient(){
	string brokers="127.0.0.1:9092";
	string topic="test_kafka";
	std::string errstr;
	RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
	
	if (conf->set("bootstrap.servers", brokers, errstr) !=
		RdKafka::Conf::CONF_OK) {
		std::cerr << errstr << std::endl;
		exit(1);
	}
	
	ExampleDeliveryReportCb ex_dr_cb;
	
	if (conf->set("dr_cb", &ex_dr_cb, errstr) != RdKafka::Conf::CONF_OK) {
		std::cerr << errstr << std::endl;
		exit(1);
	}
	
	RdKafka::Producer *producer = RdKafka::Producer::create(conf, errstr);
	if (!producer) {
		std::cerr << "Failed to create producer: " << errstr << std::endl;
		exit(1);
	}
	
	delete conf;
	
	for (std::string line; std::getline(std::cin, line);) {
		if (line.empty()) {
			producer->poll(0);
			continue;
		}
	    RdKafka::ErrorCode err =producer->produce( topic,
						RdKafka::Topic::PARTITION_UA,
                        RdKafka::Producer::RK_MSG_COPY,
                        const_cast<char *>(line.c_str()), line.size(),
                        NULL, 0, 0,NULL,NULL);
		if (err != RdKafka::ERR_NO_ERROR) {
			std::cerr << "% Failed to produce to topic " << topic << ": " <<
			RdKafka::err2str(err) << std::endl;
		}
			
	}
	producer->flush(1*1000 /* wait for max 10 seconds */);
	delete producer;	
}