#include "comsumer.h"

class ExampleConsumeCb2 : public RdKafka::ConsumeCb {
 public:
  void consume_cb (RdKafka::Message &msg, void *opaque) {
		cout<<"call back\n";
		msg_consume(&msg, opaque);
  }
};
void msg_consume(RdKafka::Message* message, void* opaque) {
  const RdKafka::Headers *headers;
	cout<<"msg_consume\n";
  switch (message->err()) {
    case RdKafka::ERR__TIMED_OUT:
		break;

    case RdKafka::ERR_NO_ERROR:
		/* Real message */
		std::cout << "Read msg at offset " << message->offset() << std::endl;
		if (message->key()) {
			std::cout << "Key: " << *message->key() << std::endl;
		}
		headers = message->headers();
		if (headers) {
			std::vector<RdKafka::Headers::Header> hdrs = headers->get_all();
			for (size_t i = 0 ; i < hdrs.size() ; i++) {
				const RdKafka::Headers::Header hdr = hdrs[i];
			
				if (hdr.value() != NULL)
				printf(" Header: %s = \"%.*s\"\n",
						hdr.key().c_str(),
						(int)hdr.value_size(), (const char *)hdr.value());
				else
				printf(" Header:  %s = NULL\n", hdr.key().c_str());
			}
		}
		printf("%.*s\n",
		static_cast<int>(message->len()),
		static_cast<const char *>(message->payload()));
		break;

    default:
      /* Errors */
      std::cerr << "Consume failed: " << message->errstr() << std::endl;
  }
}
void TestComsumer(){
	RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
	RdKafka::Conf *tconf = RdKafka::Conf::create(RdKafka::Conf::CONF_TOPIC);
	int64_t start_offset = RdKafka::Topic::OFFSET_BEGINNING;
	string errstr;
	string topic_str="test_kafka";
	int32_t partition = RdKafka::Topic::PARTITION_UA;
	string brokers = "localhost";
	partition=0;
	
	conf->set("metadata.broker.list", brokers, errstr);
	
	RdKafka::Consumer *consumer=nullptr;
	consumer = RdKafka::Consumer::create(conf, errstr);	
	if (consumer==nullptr) {
		std::cerr << "Failed to create consumer: " << errstr << std::endl;
		exit(1);
    }
	
	RdKafka::Topic *topic = RdKafka::Topic::create(consumer, topic_str,
						   tconf, errstr);						   
	if (!topic) {
		std::cerr << "Failed to create topic: " << errstr << std::endl;
		exit(1);
    }					 
	
	RdKafka::ErrorCode resp = consumer->start(topic, partition, start_offset);
    if (resp != RdKafka::ERR_NO_ERROR) {
		std::cerr << "Failed to start consumer: " <<
		RdKafka::err2str(resp) << std::endl;
		exit(1);
    }
	
	int use_ccb=1;
	
	for(;;){
		RdKafka::Message *msg = consumer->consume(topic, partition, 1000);
        msg_consume(msg, NULL);
		consumer->poll(0);
		//sleep(1);
	}
	
    consumer->stop(topic, partition);
    consumer->poll(1000);

    delete topic;
    delete consumer;
		
}