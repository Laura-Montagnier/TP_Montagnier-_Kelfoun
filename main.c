
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"
#include <string.h>
#include "ratp.h"
#include "age.h"


void recupAge(int * age)
{
    *age = (int) mock();
}

static int setup(void **state) {
    (void) state;
    printf("setUp");
    return 0;
}
static int teardown(void **state) {
    (void) state;
    printf("tearDown");
    return 0;
}

/*
A test case that does nothing and succeeds.

static void null_test_success(void **state) {
    (void) state;
} 
*/

/*
static void Test_adulte(void **state){
    assert_float_equal(1.2, computePrice(13, 0), 0);
}

static void Test_adulteTouriste(void **state){
    assert_float_equal(2.4, computePrice(13, 1), 0);
}

static void Test_enfant(void **state){
    assert_float_equal(0.6, computePrice(11, 0), 0);
}

static void Test_enfantTouriste(void **state){
    assert_float_equal(1.2, computePrice(11, 1), 0);
}
*/ 

/*
static void test1 (void **state)
{
    (void) state;
    float prix;
    prix= computePrice(20.0,0);
    assert_float_equal (1.5,prix,0.001); 
} 
*/


static void testMock(void **state) {
    will_return(recupAge, 12);
    assert_float_equal(1.2, newComputePrice(72), 0);
}


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(testMock),
    };
 //   cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests_name("toto",tests, setup, teardown);

}
