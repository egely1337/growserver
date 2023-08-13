#ifndef _PACKETS_H
#define _PACKETS_H

#include <stdint.h>


#define CONNECT_EVENT 0


typedef struct TANK_PACKET {
    uint8_t packet_type;
    uint8_t t1;
    uint8_t t2;
    uint8_t t3;
    uint32_t NetID;
    uint32_t t4;
    uint32_t t5;
    uint32_t t6;
    uint32_t t7;
    float t8;
    float t9;
    float t10;
    float t11;
    float t12;
    uint32_t t13;
    uint32_t t14;
    uint32_t t15;
} tank_packet_t __attribute__((packed));

#endif