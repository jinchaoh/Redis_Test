/*
 * Redis.cpp
 *
 *  Created on: 2016年4月17日
 *      Author: hankin
 */

#include "Redis.h"

namespace redis {

Redis::Redis() {
	// TODO Auto-generated constructor stub

}

Redis::~Redis() {
	// TODO Auto-generated destructor stub
	freeReplyObject(this->_reply);
	this->_connect = NULL;
	this->_reply = NULL;
}

bool Redis::connect(std::string host, int port)
  {
      this->_connect = redisConnect(host.c_str(), port);
    if(this->_connect != NULL && this->_connect->err)
    {
        printf("connect error: %s\n", this->_connect->errstr);
      return 0;
    }
    return 1;
  }

void Redis::set_auth(std::string password)
{
this->_reply = (redisReply*)redisCommand(this->_connect, "AUTH %s", password.c_str());
if (this->_reply ->type == REDIS_REPLY_ERROR) {
    /* Authentication failed */
	std::cout<<"authentication failed!"<<std::endl;
}
std::string str = this->_reply->str;
}

    std::string Redis::get(std::string key)
  {
    this->_reply = (redisReply*)redisCommand(this->_connect, "GET %s", key.c_str());
    std::string str = this->_reply->str;
   // freeReplyObject(this->_reply);
    return str;
  }

  void Redis::set(std::string key, std::string value)
  {
	  redisCommand(this->_connect, "SET %s %s", key.c_str(), value.c_str());
  }

  void Redis::lpush(std::string list_mem, std::string value)
  {
	  redisCommand(this->_connect, "LPUSH %s %s", list_mem.c_str(), value.c_str());
  }

} /* namespace redis */
