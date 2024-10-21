#include <rvh_test.h>
#include <csrs.h> 
#define MCONTROL6_M          (1<<6)
#define MCONTROL6_S         (1<<4)
#define MCONTROL6_U         (1<<3)
#define MCONTROL6_VS        (1<<24)
#define MCONTROL6_VU        (1<<23)
#define MCONTROL6_LOAD       (1<<0)
#define MCONTROL6_STORE       (1<<1)
#define TRIGGER_LOAD  0
#define TRIGGER_STORE 1
#define TRIGGER_LOAD_AND_STORE 2
#define __riscv_xlen 64
#define TDATA1_TYPE 6ULL // mcontrol6
void setTrigger(unsigned long tdata2, int op){
    asm volatile(
        "csrw tselect, 1\n\t"
        "csrw tdata2, %0\n\t"
        "csrs mstatus, 8\n\t"
        :
        : "r"(tdata2)
        :
    );
    if (op == 0){
        // load
        asm volatile(
            "csrw tdata1, %0\n\t"
            :
            : "r"((TDATA1_TYPE << (__riscv_xlen - 4)) | MCONTROL6_VU | MCONTROL6_LOAD)
            :
        );
    } else if (op == 1){
        // store
        asm volatile(
            "csrw tdata1, %0\n\t"
            :
            : "r"((TDATA1_TYPE << (__riscv_xlen - 4)) | MCONTROL6_VU | MCONTROL6_STORE)
            :
        );
    } else if (op == 2){
        // load and store
        asm volatile(
            "csrw tdata1, %0\n\t"
            :
            : "r"((TDATA1_TYPE << (__riscv_xlen - 4)) | MCONTROL6_VU | MCONTROL6_LOAD | MCONTROL6_STORE)
            :
        );
    } else {
        printf(" Error: op should be 0 or 1\n");
    }
}

bool rva_trigger_tests() {
    TEST_START();

    printf("----------test sc----------\n");

    // Test 1: trigger off, normal sc
    goto_priv(PRIV_VU);
    asm volatile(
        "lr.d t0, (%0)\n\t"
        "sc.d t0, t1, (%0)\n\t"
        :
        :"r"(0x81000000ULL)
    );
    TEST_ASSERT("test1 ", excpt.triggered == false);


    // Test 2: trigger on, sc to trigger address
    goto_priv(PRIV_M);
    setTrigger(0x81000000ULL, TRIGGER_STORE);
    goto_priv(PRIV_VU);
    TEST_SETUP_EXCEPT();
    asm volatile(
        "lr.d t0, (%0)\n\t"
        "sc.d t0, t1, (%0)\n\t"
        :
        :"r"(0x81000000ULL)
    );
    TEST_ASSERT("test2 ", excpt.triggered == true && excpt.cause == CAUSE_BKP);

    // Test 3: trigger on, sc to non trigger address
    goto_priv(PRIV_M);
    setTrigger(0x82000000ULL, TRIGGER_STORE);
    goto_priv(PRIV_VU);
    TEST_SETUP_EXCEPT();
    asm volatile(
        "lr.d t0, (%0)\n\t"
        "sc.d t0, t1, (%0)\n\t"
        :
        :"r"(0x81000000ULL)
    );
    TEST_ASSERT("test3 ", excpt.triggered == false);

    // Test 4: trigger on, failure sc to trigger address
    goto_priv(PRIV_M);
    setTrigger(0x81000000ULL, TRIGGER_STORE);
    goto_priv(PRIV_VU);
    TEST_SETUP_EXCEPT();
    asm volatile(
        "sc.d t0, t1, (%0)\n\t"
        :
        :"r"(0x81000000ULL)
    );
    TEST_ASSERT("test4 ", excpt.triggered == true && excpt.cause == CAUSE_BKP);

    TEST_END();
}