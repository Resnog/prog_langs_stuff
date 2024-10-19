/**
 * @author      : segonzal (segonzal@$HOSTNAME)
 * @file        : 
 * @created     : Wednesday Dec 21, 2022 09:00:11 EET
 */

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

struct something {
	uint8_t  a;
	uint8_t  b;
	uint16_t c;
	bool d;
};

void show_struct(uint8_t *p, uint8_t len) {
	printf("\nThe struct:");
	for(int i = 0; i <= len ;i++) {
			printf("%x ", *(p+i) );
	}
}

void show_array(uint8_t *arr, const size_t len) {
	printf("\nThe array:");
	for(int i = 0; i < len ;i++) {
		printf("%x  ", arr[i]);
	}
}

int main() {
	
	struct something some;
	
	some.a = 0x12;
	some.b = 0x34;
	some.c = 0x5678;
	some.d = false;
	
	const size_t len = 5;
	uint8_t array[len] = {0x12, 0x34, 0x56, 0x78, 0x00};
	
	uint8_t *p = &some;
	
	show_array(array, len);	
	show_struct(p, len);

}
