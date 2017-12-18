#include <czmq.h>

int main(int argc, char* argv[])
{
  if (argc < 2) {
    printf("Port number is mandatory\n");
    return 0;
  }

  zsock_t *responder = zsock_new(ZMQ_REP);
  zsock_bind(responder, "tcp://*:%s", argv[1]);

  while (!zsys_interrupted) {
    char *message = zstr_recv(responder);
    printf("Received: %s\n", message);
    sleep(1);
    zstr_sendf(responder, "%s", message);
    zstr_free(&message);
  }
  zsock_destroy(&responder);
  return 0;
}
