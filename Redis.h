/*
 * Redis.h
 *
 *  Created on: 2016年4月17日
 *      Author: hankin
 */

#ifndef REDIS_H_
#define REDIS_H_

#include<string>
#include<iostream>
#include<stdio.h>
#include <hiredis/hiredis.h>

namespace redis {

class Redis {
public:
	Redis();
	virtual ~Redis();

public:
	bool connect(std::string host, int port);
	std::string get(std::string key);
	void set(std::string key, std::string value);
	void lpush(std::string list_mem, std::string value);

private:
	redisContext* _connect;
	redisReply* _reply;
};

} /* namespace redis */

#endif /* REDIS_H_ */
