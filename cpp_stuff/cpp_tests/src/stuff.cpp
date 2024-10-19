#include <iostream>
#include <stdint.h>

void use0bBinNumFormat(void){
    std::cout << "We can actually set numbers like this :" << 0b0101111 << std::endl;
    std::cout << "When we do something like: <uint8_t = 0b0101111>" << std::endl;
}

size_t sizeOfMultipleTypes(void){
    return (4*sizeof(uint8_t) + sizeof(uint16_t));
}
