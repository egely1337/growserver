#define ENET_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <lib/enet.h>
#include <packets.h>
#include <events.h>

#define MAX_CLIENTS 32

int main(int argc, char** argv) {
    if(enet_initialize() != 0) {
        fprintf(stderr, "Failed to initialize enet.");
        return 0;
    }

    ENetAddress address = {0};

    address.host = ENET_HOST_ANY;
    address.port = 1337;

    ENetHost* server = enet_host_create(&address, MAX_CLIENTS, 2, 0, 0);
    if(server == (void*)0) {
        fprintf(stderr, "Failed to bind server.");
        return 0;
    }

    ENetEvent event;
    while (1) {
        while(enet_host_service(server, &event, 60) > 0){
            switch(event.type) {
                case ENET_EVENT_TYPE_CONNECT:
                    event_connect_event(&event);
                    break;
                case ENET_EVENT_TYPE_RECEIVE:
                    event_receive_event(&event);
                    break;
                case ENET_EVENT_TYPE_DISCONNECT:
                    event_disconnect_event(&event);
                    break;
            }
        }
    }

    enet_host_destroy(server);
    enet_deinitialize();
}