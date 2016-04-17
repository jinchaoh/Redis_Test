/*
 * main.cpp
 *
 *  Created on: 2016年4月17日
 *      Author: hankin
 */
#include "Redis.h"

using namespace redis;
int main()
{
  Redis *r = new Redis();
  if(!r->connect("127.0.0.1", 6379))
  {
    printf("connect error!\n");
    return 0;
  }
  r->set_auth("hankin");
  r->set("name", "Mayuyu");
  int i;
  char buf[10];
  std::string str;
  for(i=0;i<100;i++)
  {
	  sprintf(buf,"%d",i);
	  str = buf;
	  r->lpush("mylist",str);
  }

  printf("Get the name is %s\n", r->get("name").c_str());
  delete r;
  return 0;
}



