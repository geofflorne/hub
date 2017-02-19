#include "main.h"
#include "hiredis.h"
/* gcc main.c -I /usr/local/include/hiredis/ -L /usr/local/lib/ -l hiredis -o redis-example */
#include <stdint.h>

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <net/if.h>
#include <linux/can.h>
#include <linux/can/raw.h>

int soc;
int read_can_port;

#define can_socket_port "vcan0"

int open_port(const char *port)
{
    struct ifreq ifr;
    struct sockaddr_can addr;
    /* open socket */
    soc = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if(soc < 0)
    {
        return (-1);
    }
    addr.can_family = AF_CAN;
    strcpy(ifr.ifr_name, port);
    if (ioctl(soc, SIOCGIFINDEX, &ifr) < 0)
    {
        return (-1);
    }
    addr.can_ifindex = ifr.ifr_ifindex;
    fcntl(soc, F_SETFL, O_NONBLOCK);
    if (bind(soc, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        return (-1);
    }
    return 0;
}
int send_port(struct can_frame *frame)
{
    int retval;
   retval = write(soc, frame, sizeof(struct can_frame));
    if (retval != sizeof(struct can_frame))
    {
        return (-1);
    }
    else
    {
        return (0);
    }
}
/* this is just an example, run in a thread */
void read_port()
{
    struct can_frame frame_rd;
    int recvbytes = 0;
    read_can_port = 1;
    while(read_can_port)
    {
        struct timeval timeout = {1, 0};
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(soc, &readSet);
        if (select((soc + 1), &readSet, NULL, NULL, &timeout) >= 0)
        {
            if (!read_can_port)
            {
                break;
            }
            if (FD_ISSET(soc, &readSet))
            {
                recvbytes = read(soc, &frame_rd, sizeof(struct can_frame));
                if(recvbytes)
                {
                    printf("number of frames = %d address = %d  ",
                              frame_rd.can_dlc, frame_rd.can_id);
                    printf("data = ");
                    fflush(stdout);

                    for (int i = 0; i < frame_rd.can_dlc; i++) {

                      printf("%X ", frame_rd.data[i]);

                    }
                    printf("\n");
                    fflush(stdout);

                    set_keys(frame_rd.can_id, frame_rd.can_data[]);
                }
            }
        }
    }
}

int close_port()
{
    close(soc);
    return 0;
}


int CAN_PARSE_UINT16(){

}

int main() {
  // initialize the hiredis server
  initialize_server();

  // open the port
  open_port(can_socket_port);

  // initialize the keys in the server
  create_keys();

  for (;;) {
    // read messages from can
    read_port();
  }
  close_port();
  return 0;


}
