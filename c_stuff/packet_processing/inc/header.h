#ifndef HEADER_H
#define HEADER_H

#include <stddef.h>
#include <stdint.h>
// Some header file template

const uint32_t packetHeaderDevTypeMask = 0x000000FF;
const uint32_t packetHeaderMsgTypeMask = 0x0000FF00;
const uint32_t packetHeaderMsgLenMask = 0x00FF0000;
const uint32_t packetHeaderMsgIDMask = 0xFF000000;

enum msgId {
    one = 0x01000000,
    two = 0x02000000,
    three = 0x03000000,
};

enum msgType {
    msgType1 = 0x00001100,
    msgType2 = 0x00002200,
    msgType3 = 0x00003300,
};

enum devType {
    devType1 = 0x000000aa,
    devType2 = 0x000000bb,
    devType3 = 0x000000cd,
};


typedef uint32_t bgapiHeader;

void getPacketHeader(bgapiHeader* header);

#endif //  HEADER_H
