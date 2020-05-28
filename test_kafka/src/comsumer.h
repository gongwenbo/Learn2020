#pragma once 
#include "common.h"

void msg_consume(RdKafka::Message* message, void* opaque); 
class ExampleConsumeCb : public RdKafka::ConsumeCb {
 public:
  void consume_cb (RdKafka::Message &msg, void *opaque) {
    msg_consume(&msg, opaque);
  }
};

void TestComsumer();