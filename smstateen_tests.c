#include <rvh_test.h>
#include <csrs.h> 
#include <stdbool.h>

bool smstateen_exception_tests() {
    TEST_START();


    printf("----------test se0----------\n");
{
    goto_priv(PRIV_M);
    asm volatile(
        "csrc mstateen0, %0\n\t"
        :
        :"r"(0x8000000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 11", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 12", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 13", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 14", excpt.triggered == true && excpt.cause == CAUSE_ILI);

    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(hstateen0); TEST_ASSERT("test se0 21", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(hstateen0); TEST_ASSERT("test se0 22", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(hstateen0); TEST_ASSERT("test se0 23", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(hstateen0); TEST_ASSERT("test se0 24", excpt.triggered == true && excpt.cause == CAUSE_ILI);

    goto_priv(PRIV_M);
    asm volatile(
        "csrs mstateen0, %0\n\t"
        :
        :"r"(0x8000000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 31", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 32", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 33", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 34", excpt.triggered == true && excpt.cause == CAUSE_VRTI);

    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(hstateen0); TEST_ASSERT("test se0 41", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(hstateen0); TEST_ASSERT("test se0 42", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(hstateen0); TEST_ASSERT("test se0 43", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(hstateen0); TEST_ASSERT("test se0 44", excpt.triggered == true && excpt.cause == CAUSE_VRTI);

    goto_priv(PRIV_M);
    asm volatile(
        "csrc hstateen0, %0\n\t"
        :
        :"r"(0x8000000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 51", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 52", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 53", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 54", excpt.triggered == true && excpt.cause == CAUSE_VRTI);

    goto_priv(PRIV_M);
    asm volatile(
        "csrs hstateen0, %0\n\t"
        :
        :"r"(0x8000000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 51", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 52", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 53", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(sstateen0); TEST_ASSERT("test se0 54", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
}
    printf("----------test envcfg----------\n");
{
    goto_priv(PRIV_M);
    asm volatile(
        "csrc mstateen0, %0\n\t"
        :
        :"r"(0x4000000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 11", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 12", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 13", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 14", excpt.triggered == true && excpt.cause == CAUSE_ILI);

    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(henvcfg); TEST_ASSERT("test se0 21", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(henvcfg); TEST_ASSERT("test se0 22", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(henvcfg); TEST_ASSERT("test se0 23", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(henvcfg); TEST_ASSERT("test se0 24", excpt.triggered == true && excpt.cause == CAUSE_ILI);

    goto_priv(PRIV_M);
    asm volatile(
        "csrs mstateen0, %0\n\t"
        :
        :"r"(0x4000000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 31", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 32", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 33", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 34", excpt.triggered == true && excpt.cause == CAUSE_VRTI);

    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(henvcfg); TEST_ASSERT("test se0 41", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(henvcfg); TEST_ASSERT("test se0 42", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(henvcfg); TEST_ASSERT("test se0 43", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(henvcfg); TEST_ASSERT("test se0 44", excpt.triggered == true && excpt.cause == CAUSE_VRTI);

    goto_priv(PRIV_M);
    asm volatile(
        "csrc hstateen0, %0\n\t"
        :
        :"r"(0x4000000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 51", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 52", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 53", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 54", excpt.triggered == true && excpt.cause == CAUSE_VRTI);

    goto_priv(PRIV_M);
    asm volatile(
        "csrs hstateen0, %0\n\t"
        :
        :"r"(0x4000000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 51", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 52", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 53", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(senvcfg); TEST_ASSERT("test se0 54", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
}
    printf("----------test aia----------\n");
{
    goto_priv(PRIV_M);
    asm volatile(
        "csrc mstateen0, %0\n\t"
        :
        :"r"(0x0800000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 11", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 12", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 13", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 14", excpt.triggered == true && excpt.cause == CAUSE_ILI);

    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(vstopi); TEST_ASSERT("test se0 21", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(vstopi); TEST_ASSERT("test se0 22", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(vstopi); TEST_ASSERT("test se0 23", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(vstopi); TEST_ASSERT("test se0 24", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(hvien); TEST_ASSERT("test se0 21", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(hvien); TEST_ASSERT("test se0 22", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(hvien); TEST_ASSERT("test se0 23", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(hvien); TEST_ASSERT("test se0 24", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(hvictl); TEST_ASSERT("test se0 21", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(hvictl); TEST_ASSERT("test se0 22", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(hvictl); TEST_ASSERT("test se0 23", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(hvictl); TEST_ASSERT("test se0 24", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(hviprio1); TEST_ASSERT("test se0 21", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(hviprio1); TEST_ASSERT("test se0 22", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(hviprio1); TEST_ASSERT("test se0 23", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(hviprio1); TEST_ASSERT("test se0 24", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(hviprio2); TEST_ASSERT("test se0 21", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(hviprio2); TEST_ASSERT("test se0 22", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(hviprio2); TEST_ASSERT("test se0 23", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(hviprio2); TEST_ASSERT("test se0 24", excpt.triggered == true && excpt.cause == CAUSE_ILI);

    goto_priv(PRIV_M);
    asm volatile(
        "csrs mstateen0, %0\n\t"
        :
        :"r"(0x0800000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 31", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 32", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 33", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 34", excpt.triggered == true && excpt.cause == CAUSE_VRTI);

    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(vstopi); TEST_ASSERT("test se0 41", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(vstopi); TEST_ASSERT("test se0 42", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(vstopi); TEST_ASSERT("test se0 43", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(vstopi); TEST_ASSERT("test se0 44", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(hvien); TEST_ASSERT("test se0 41", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(hvien); TEST_ASSERT("test se0 42", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(hvien); TEST_ASSERT("test se0 43", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(hvien); TEST_ASSERT("test se0 44", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(hvictl); TEST_ASSERT("test se0 41", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(hvictl); TEST_ASSERT("test se0 42", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(hvictl); TEST_ASSERT("test se0 43", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(hvictl); TEST_ASSERT("test se0 44", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(hviprio1); TEST_ASSERT("test se0 41", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(hviprio1); TEST_ASSERT("test se0 42", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(hviprio1); TEST_ASSERT("test se0 43", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(hviprio1); TEST_ASSERT("test se0 44", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(hviprio2); TEST_ASSERT("test se0 41", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(hviprio2); TEST_ASSERT("test se0 42", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(hviprio2); TEST_ASSERT("test se0 43", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(hviprio2); TEST_ASSERT("test se0 44", excpt.triggered == true && excpt.cause == CAUSE_VRTI);

    goto_priv(PRIV_M);
    asm volatile(
        "csrc hstateen0, %0\n\t"
        :
        :"r"(0x0800000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 51", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 52", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 53", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 54", excpt.triggered == true && excpt.cause == CAUSE_VRTI);

    goto_priv(PRIV_M);
    asm volatile(
        "csrs hstateen0, %0\n\t"
        :
        :"r"(0x0800000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 51", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 52", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 53", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(stopi); TEST_ASSERT("test se0 54", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
}
    printf("----------test imsic----------\n");
{
    goto_priv(PRIV_M);
    asm volatile(
        "csrc mstateen0, %0\n\t"
        :
        :"r"(0x0400000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 11", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 12", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 13", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 14", excpt.triggered == true && excpt.cause == CAUSE_ILI);

    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(vstopei); TEST_ASSERT("test se0 21", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(vstopei); TEST_ASSERT("test se0 22", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(vstopei); TEST_ASSERT("test se0 23", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(vstopei); TEST_ASSERT("test se0 24", excpt.triggered == true && excpt.cause == CAUSE_ILI);

    goto_priv(PRIV_M);
    asm volatile(
        "csrs mstateen0, %0\n\t"
        :
        :"r"(0x0400000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 31", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 32", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 33", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 34", excpt.triggered == true && excpt.cause == CAUSE_VRTI);

    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(vstopei); TEST_ASSERT("test se0 41", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(vstopei); TEST_ASSERT("test se0 42", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(vstopei); TEST_ASSERT("test se0 43", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(vstopei); TEST_ASSERT("test se0 44", excpt.triggered == true && excpt.cause == CAUSE_VRTI);

    goto_priv(PRIV_M);
    asm volatile(
        "csrc hstateen0, %0\n\t"
        :
        :"r"(0x0400000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 51", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 52", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 53", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 54", excpt.triggered == true && excpt.cause == CAUSE_VRTI);

    goto_priv(PRIV_M);
    asm volatile(
        "csrs hstateen0, %0\n\t"
        :
        :"r"(0x0400000000000000ULL)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 51", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 52", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 53", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(stopei); TEST_ASSERT("test se0 54", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
}
    printf("----------test custom----------\n");
{
    goto_priv(PRIV_M);
    asm volatile(
        "csrc mstateen0, %0\n\t"
        :
        :"r"(1)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 11", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 12", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 13", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 14", excpt.triggered == true && excpt.cause == CAUSE_ILI);

    goto_priv(PRIV_M);
    asm volatile(
        "csrs mstateen0, %0\n\t"
        :
        :"r"(1)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 31", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 32", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 33", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 34", excpt.triggered == true && excpt.cause == CAUSE_VRTI);

    goto_priv(PRIV_M);
    asm volatile(
        "csrc hstateen0, %0\n\t"
        :
        :"r"(1)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 51", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 52", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 53", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 54", excpt.triggered == true && excpt.cause == CAUSE_VRTI);

    goto_priv(PRIV_M);
    asm volatile(
        "csrs hstateen0, %0\n\t"
        :
        :"r"(1)
    );
    goto_priv(PRIV_M); goto_priv(PRIV_HS); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 51", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_HU); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 52", excpt.triggered == true && excpt.cause == CAUSE_ILI);
    goto_priv(PRIV_M); goto_priv(PRIV_VS); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 53", excpt.triggered == false);
    goto_priv(PRIV_M); goto_priv(PRIV_VU); TEST_SETUP_EXCEPT(); CSRR(0x5c0); TEST_ASSERT("test se0 54", excpt.triggered == true && excpt.cause == CAUSE_VRTI);
}

    TEST_END();
}