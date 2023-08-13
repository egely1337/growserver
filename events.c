#include <events.h>


void
event_connect_event
(
    ENetEvent* event
)
{
    fprintf(stdout, "Someone connected to server.\n\r");
}

void
event_receive_event
(
    ENetEvent* event
) 
{
    fprintf(stdout, "Receive a packet.\n\r");

    
    tank_packet_t* receive_packet = (tank_packet_t*)event->packet->data;
    
    switch(receive_packet->packet_type) {
        case CONNECT_EVENT:
            break;
        default:
            break;
    }
}

void 
event_disconnect_event
(
    ENetEvent* event
)
{
    fprintf(stdout, "Someone disconnected from server.\n\r");
}