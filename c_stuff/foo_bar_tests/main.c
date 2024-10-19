#include <stdio.h> 
#include <stdint.h>

void foo(){

    char stuff[] = "I'm being called";

    printf("%s", stuff);
}

uint8_t fromNumberToASCII(uint8_t number){
    return number + 48;
}

int main(){

    char string[15] = "Hello, World!";
    uint8_t a = 12;
    string[13] = 2;
    string[14] = fromNumberToASCII(a);
    

    printf("%s\n", string);

    return 0;
}
