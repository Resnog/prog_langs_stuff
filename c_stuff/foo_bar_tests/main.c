#include <stdio.h> 
#include <stdint.h>

void foo(){

    char stuff[] = "I'm being called";

    printf("%s", stuff);
}

uint8_t fromNumberToASCII(uint8_t number){
    return number + 48;
}

typedef struct {
    uint8_t a;
    uint16_t b;
    uint8_t c;
    uint16_t d;
} myStruct1;

typedef struct {
    uint8_t e;
    uint16_t f;
} myStruct2;


struct myStruct3 {
    myStruct1 struct1;
    myStruct2 struct2;
};

union {
   myStruct1 struct1; 
   myStruct2 struct2;
} myUnion;

void printStruct3(myStruct1 *struct1){
    uint32_t *ptr = (uint32_t *)&struct1;
    printf("myStruct3 byte 1: %x\n", *(ptr));
}

int main(){

    char string[15] = "Hello, World!";
    uint8_t a = 12;
    string[13] = 2;
    string[14] = fromNumberToASCII(a);
    

    printf("%s\n", string);

    myUnion.struct1.a = 0xAA;
    myUnion.struct1.b = 0xBBBB;
    myUnion.struct1.c = 0xCC;
    myUnion.struct1.d = 0xDDDD;
    //myUnion.struct1.e = 0xEE;
    //myUnion.struct1.f = 0xFF;

    printf("myUnion.struct1.a: %x\n", myUnion.struct1.a);
    printf("myUnion.struct1.b: %x\n", myUnion.struct1.b);
    printf("myUnion.struct1.c: %x\n", myUnion.struct1.c);
    printf("myUnion.struct1.d: %x\n", myUnion.struct1.d);
    //printf("myUnion.struct1.e: %x\n", myUnion.struct1.e);
    //printf("myUnion.struct1.f: %x\n", myUnion.struct1.f);

    //myUnion.struct2.three = 0x3333;
    myUnion.struct2.e = 0xEE;// 0x22;
    myUnion.struct2.f = 0xFFFF;// 0x1111;

    printf("myUnion.struct2.three: %x\n", myUnion.struct2.e);
    printf("myUnion.struct2.two: %x\n", myUnion.struct2.f);
    //printf("myUnion.struct2.one: %x\n", myUnion.struct2.one);


    printf("myUnion.struct1.a: %x\n", myUnion.struct1.a);
    printf("myUnion.struct1.b: %x\n", myUnion.struct1.b);
    printf("myUnion.struct1.c: %x\n", myUnion.struct1.c);

    struct myStruct3 structTest;

    structTest.struct1.a = 0xAA;
    structTest.struct1.b = 0xBBBB;
    structTest.struct1.c = 0xCC;
    structTest.struct1.d = 0xDDDD;
    structTest.struct2.e = 0xEE;
    structTest.struct2.f = 0xFFFF;

    printStruct3(&structTest);
    return 0;
}
