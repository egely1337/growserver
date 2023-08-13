#ifndef _EVENTS_H
#define _EVENTS_H

#include <stdio.h>
#include <lib/enet.h>
#include <packets.h>

void event_connect_event(ENetEvent* event);
void event_receive_event(ENetEvent* event);
void event_disconnect_event(ENetEvent* event);

#endif