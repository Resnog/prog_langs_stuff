#include <stdio.h>
#include "header.h"

uint8_t getPacketHeaderDevType(bgapiHeader *header) {
    return (uint8_t) (*header & packetHeaderDevTypeMask);
}

uint8_t getPacketHeaderMsgType(bgapiHeader *header) {
    return (uint8_t) ((*header & packetHeaderMsgTypeMask) >> 8U);
}

uint8_t getPacketHeaderMsgLen(bgapiHeader *header) {
    return (uint8_t) ((*header & packetHeaderMsgLenMask) >> 16U);
}

uint8_t getPacketHeaderMsgID(bgapiHeader *header) {
    return (uint8_t) ((*header & packetHeaderMsgIDMask) >> 24U);
}


void getPacketHeader(bgapiHeader *header) {
    printf("> Packet Header\n");
    printf(">> DevType:%x\n", getPacketHeaderDevType(header));
    printf(">> MsgType:%x\n", getPacketHeaderMsgType(header));
    printf(">> MsgLen:%x\n", getPacketHeaderMsgLen(header));
    printf(">> MsgID:%x\n", getPacketHeaderMsgID(header));
}
