#ifndef ASSEMBLY
#include <mee/drivers/sifive,test0.h>
#include <mee/drivers/riscv,rv32,pmp.h>
/* From pmp@0 */
asm (".weak __mee_dt_pmp_0");
struct __mee_driver_riscv_rv32_pmp __mee_dt_pmp_0;

/* From teststatus@4000 */
asm (".weak __mee_dt_teststatus_4000");
struct __mee_driver_sifive_test0 __mee_dt_teststatus_4000;

/* From pmp@0 */
struct __mee_driver_riscv_rv32_pmp __mee_dt_pmp_0 = {
    .vtable = &__mee_driver_vtable_riscv_rv32_pmp,
    .pmp.vtable = &__mee_driver_vtable_riscv_rv32_pmp.pmp,
    .num_regions = 8UL,
};

/* From pmp@0 */
#define __MEE_DT_PMP_HANDLE (&__mee_dt_pmp_0.pmp)
/* From teststatus@4000 */
struct __mee_driver_sifive_test0 __mee_dt_teststatus_4000 = {
    .vtable = &__mee_driver_vtable_sifive_test0,
    .shutdown.vtable = &__mee_driver_vtable_sifive_test0.shutdown,
    .base = 16384UL,
    .size = 4096UL,
};

/* From teststatus@4000 */
#define __MEE_DT_SHUTDOWN_HANDLE (&__mee_dt_teststatus_4000.shutdown)
#endif/*ASSEMBLY*/
