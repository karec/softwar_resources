#include <czmq.h>

int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Port parameter is mandatory\n");
    return 0;
  }

  printf("Connecting to echo...\n");
  zsock_t *req = zsock_new(ZMQ_REQ);
  zsock_set_identity(req, "test");
  zsock_connect(req, "tcp://localhost:%s", argv[1]);

  int request_nbr;
  for (request_nbr = 0; request_nbr != 10; request_nbr++) {
    zstr_sendf(req, "Hello world !");

    char *message = zstr_recv(req);
    printf("Received : %s\n", message);
    zstr_free(&message);
  }
  zsock_destroy(&req);
  return 0;
}
