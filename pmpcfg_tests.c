#include <rvh_test.h>
#include <csrs.h> 

bool pmpcfg_exception_tests() {

    TEST_START();

    goto_priv(PRIV_M);
    TEST_SETUP_EXCEPT();CSRR(0x3a0);TEST_ASSERT("access pmpcfg0 is OK", excpt.triggered == false);
    TEST_SETUP_EXCEPT();CSRR(0x3a1);TEST_ASSERT("access pmpcfg1 will cause EX_II", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    TEST_SETUP_EXCEPT();CSRR(0x3a2);TEST_ASSERT("access pmpcfg2 is OK", excpt.triggered == false);
    TEST_SETUP_EXCEPT();CSRR(0x3a3);TEST_ASSERT("access pmpcfg3 will cause EX_II", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    TEST_SETUP_EXCEPT();CSRR(0x3a4);TEST_ASSERT("access pmpcfg4 will cause EX_II", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    TEST_SETUP_EXCEPT();CSRR(0x3a5);TEST_ASSERT("access pmpcfg5 will cause EX_II", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    TEST_SETUP_EXCEPT();CSRR(0x3a6);TEST_ASSERT("access pmpcfg6 will cause EX_II", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    TEST_SETUP_EXCEPT();CSRR(0x3a7);TEST_ASSERT("access pmpcfg7 will cause EX_II", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    TEST_SETUP_EXCEPT();CSRR(0x3a8);TEST_ASSERT("access pmpcfg8 will cause EX_II", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    TEST_SETUP_EXCEPT();CSRR(0x3a9);TEST_ASSERT("access pmpcfg9 will cause EX_II", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    TEST_SETUP_EXCEPT();CSRR(0x3aa);TEST_ASSERT("access pmpcfg10 will cause EX_II", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    TEST_SETUP_EXCEPT();CSRR(0x3ab);TEST_ASSERT("access pmpcfg11 will cause EX_II", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    TEST_SETUP_EXCEPT();CSRR(0x3ac);TEST_ASSERT("access pmpcfg12 will cause EX_II", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    TEST_SETUP_EXCEPT();CSRR(0x3ad);TEST_ASSERT("access pmpcfg13 will cause EX_II", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    TEST_SETUP_EXCEPT();CSRR(0x3ae);TEST_ASSERT("access pmpcfg14 will cause EX_II", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    TEST_SETUP_EXCEPT();CSRR(0x3af);TEST_ASSERT("access pmpcfg15 will cause EX_II", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    
    TEST_END();
}