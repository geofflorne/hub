#include "main.h"
#include "hiredis.h"

/* gcc main.c -I /usr/local/include/hiredis/ -L /usr/local/lib/ -l hiredis -o redis-example */

int main() {
  // initialize the hiredis server
  initialize_server();

  // initialize the keys
  create_keys();


}

void can_signal_create(char* signal, char* name, char* transform) {
  //create a key for the signal sent

  set_key_value(signal, 0);


}

void CAN_PARSE_UINT16(){

}