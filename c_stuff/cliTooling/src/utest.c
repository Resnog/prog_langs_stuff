#include "unity.h"
#include "unity_internals.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/***************************************************************************/
// Debug helper functions
/***************************************************************************/

/***************************************************************************/
// Test setup
/***************************************************************************/

void setUp(){
}

void tearDown(){ 
}
/***************************************************************************/
// Tests
/***************************************************************************/
void test_version(void){
}

void test_coded1(void){
}

void test_coded2(void){
}

void test_coded3(void){
}

void test_coded4(void){
}

void test_coded5(void){
}
/***************************************************************************/
// Main test execution
/***************************************************************************/
int main(int argc, char *argv[])
{
    UNITY_BEGIN();

    RUN_TEST(test_version);
    RUN_TEST(test_coded1);
    RUN_TEST(test_coded2);
    RUN_TEST(test_coded3);
    RUN_TEST(test_coded4);
    RUN_TEST(test_coded5);

    // Process termination
    return UNITY_END();
}
