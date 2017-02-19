/* gcc hiredis.c -I /usr/local/include/hiredis/ -L /usr/local/lib/ -l hiredis -c */
#include <hiredis.h>
#include <stdlib.h>

redisContext *c;

void initialize_server() {

  char *hostname = "127.0.0.1";
  int port = 6379;
  struct timeval timeout = { 1, 500000 }; // 1.5 seconds
  redisReply *reply;

  c = redisConnectWithTimeout(hostname, port, timeout);

  printf("Hostname: %s", hostname);

  // error checking
  if (c == NULL || c->err) {
      if (c) {
          printf("Connection error: %s\n", c->errstr);
          redisFree(c);
      } else {
          printf("Connection error: can't allocate redis context\n");
      }
      exit(1);
  }

  // test PING/* PING server */
  reply = redisCommand(c,"PING");
  printf("PING: %s\n", reply->str);
  freeReplyObject(reply);

  // should implement a "press q to quit" option
}

void can_signal_create(char* sig){
  redisReply *reply;
  reply = redisCommand(c, "SET %s 0", sig);
  freeReplyObject(reply);
}

void can_signal_set_value(char* sig, int value) {
  redisReply *reply;
  reply = redisCommand(c, "SET %s %d", sig, value);
  freeReplyObject(reply);
}
