#include <czmq.h>

int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("port argument is mandatory\n");
    return 0;
  }

  zsock_t *router = zsock_new(ZMQ_ROUTER);
  zsock_bind(router, "tcp://*:%s", argv[1]);

  while (!zsys_interrupted) {
    zmsg_t *message = zmsg_recv(router);

    zframe_t *identity = zmsg_pop(message);
    zframe_t *identity2 = zframe_from("test");
    zframe_t *empty = zmsg_pop(message);
    zframe_t *content = zmsg_pop(message);

    zmsg_destroy(&message);
    printf("Content of message is : %s\n", zframe_strdup(content));
    sleep(1);

    zmsg_t *response = zmsg_new();

    zmsg_prepend(response, &identity2);
    zmsg_append(response, &empty);
    zmsg_append(response, &content);

    zmsg_send(&response, router);
    zmsg_destroy(&response);

    zframe_destroy(&identity);
    zframe_destroy(&empty);
    zframe_destroy(&content);
  }
  zsock_destroy(&router);
  return 0;
}
