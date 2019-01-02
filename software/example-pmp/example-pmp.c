#include <stdio.h>

#include <mee/pmp.h>

/* Mark the variable volatile to ensure that we access the memory location
 * on write */
volatile int protected_global;

/* TODO: Create a PMP exception handler */

int main()
{
	int rc;
	struct mee_pmp *pmp;

	/* Shift the address right two bits */
	size_t protected_addr = ((size_t) &protected_global) >> 2;

	printf("PMP Driver Example\n");

	/* Get PMP device handle */
	pmp = mee_pmp_get_device();
	if(!pmp) {
		printf("Unable to get PMP Device\n");
		return 2;
	}

	/* Initialize PMP */
	mee_pmp_init(pmp);

	/* Perform a write to the memory we're about to protect access to */
	protected_global = 0;

	/* Configure PMP 0 to only allow reads to protected_global. The
	 * PMP region is locked so that the configuration applies to M-mode
	 * accesses. */
	struct mee_pmp_config config = {
		.L = MEE_PMP_LOCKED,
		.A = MEE_PMP_NA4,
		.X = 0,
		.W = 0,
		.R = 1,
	};
	rc = mee_pmp_set_region(pmp, 0, config, protected_addr);
	if(rc != 0) {
		printf("Failed to configure PMP 0: %d\n", rc);
		return 3;
	}

	printf("Attempting to write to protected address\n");

	/* Attempt to write to protected_global. This should generate a store
	 * access fault exception. */
	protected_global = 1;

	/* TODO: Control will not return here until an exception handler
	 * is defined */

	/* If execution returns to here, print and return the value of protected
	 * global to demonstrate that we can still read the value */
	printf("The value of the protected memory is %d\n", protected_global);

	return protected_global;
}
