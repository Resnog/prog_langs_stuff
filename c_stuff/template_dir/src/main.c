#include <stdio.h>
#include "header.h"

int main(){

    sayHelloWorld();
    lcd_display_fill_pattern_hlines(10, 10);
    lcd_display_fill_pattern_vlines(10, 10);
    // Process termination
    return 0x00;
}