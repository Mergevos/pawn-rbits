#define RUN_TESTS
#include <a_samp>
#include "rBits.inc"
#include <YSI_Core\y_testing>

#define MAX_TESTING_INDEXES 2

main() {
    return;
}

new 
    Bit1: g_Bit1TestVar<MAX_TESTING_INDEXES>,
    Bit2: g_Bit2TestVar<MAX_TESTING_INDEXES>,
    Bit4: g_Bit4TestVar<MAX_TESTING_INDEXES>,
    Bit8: g_Bit8TestVar<MAX_TESTING_INDEXES>,
    Bit16: g_Bit16TestVar<MAX_TESTING_INDEXES>;

// To clarify: testvalue is value being set to Bit Array. 
// retval is desired return value which will be compared to the real one. 
// ret is real return value;


Test: TestBit1Array() {
    new 
        testvalue = 1,
        retval = 1;
    Bit1_Set(g_Bit1TestVar, 0, testvalue);
    new ret = Bit1_Get(g_Bit1TestVar, 0);
    ASSERT(ret == retval);
}

Test: TestBit2Array() {
    new 
        testvalue = 2,
        retval = 2;
    Bit2_Set(g_Bit2TestVar, 0, testvalue);
    new ret = Bit2_Get(g_Bit2TestVar, 0);
    ASSERT(ret == retval);
}

Test: TestBit4Array() {
    new 
        testvalue = 13,
        retval = 13;
    Bit4_Set(g_Bit4TestVar, 0, testvalue);
    new ret = Bit4_Get(g_Bit4TestVar, 0);
    ASSERT(ret == retval);
}

Test: TestBit8Array() {
    new 
        testvalue = 234,
        retval = 234;
    Bit8_Set(g_Bit8TestVar, 0, testvalue);
    new ret = Bit8_Get(g_Bit8TestVar, 0);
    ASSERT(ret == retval);
}

Test: TestBit16Array() {
    new 
        testvalue = 44000,
        retval = 44000;
    Bit16_Set(g_Bit16TestVar, 0, testvalue);
    new ret = Bit16_Get(g_Bit16TestVar, 0);
    ASSERT(ret == retval);
}