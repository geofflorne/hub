void initialize_server();

void can_signal_create(char*);
void can_signal_set_value(char*, int);
uint16_t CAN_PARSE_UINT16(uint8_t*, int);
void create_keys();
void set_keys(canid_t, uint8_t*);
