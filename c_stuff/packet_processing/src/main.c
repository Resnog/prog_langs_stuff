#include <stdio.h>
#include "header.h"

int main(){

    bgapiHeader packetHeader = 0;

    packetHeader = packetHeader | one;
    packetHeader = packetHeader | msgType1;
    uint8_t msgLen = 0x1A;
    packetHeader = packetHeader | devType1;
    packetHeader = packetHeader | (msgLen << 16);

    getPacketHeader(&packetHeader);
    // Process termination
    return 0x00;
}
