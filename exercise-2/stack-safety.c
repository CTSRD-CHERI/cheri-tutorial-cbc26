#include <sys/param.h>

#include <stdio.h>
#include <stdlib.h>

/*
 * NB: Don't change these values. They should be updated when different compiler
 * flags are in use or when codegen differs with other toolchain versions.
 */
#define	STACK_CALLER_SIZE	0xa0
#define	STACK_CALLEE_SIZE	0x60
#define	STACK_SKIP_SIZE		0x50
#define	STACK_OVERWRITE_SIZE	(STACK_CALLER_SIZE - STACK_SKIP_SIZE)
#define	STACK_OVERWRITE_OFFSET	(STACK_CALLEE_SIZE + STACK_SKIP_SIZE)

void
overwrite(void)
{
	/*
	 * Note that with optimizations this function does not store anything on
	 * the stack.
	 */
	void *csp;
	int ii;

	/*
	 * Get the current capability stack pointer.
	 */
	asm ("mov	%0, csp" : "=C" (csp));
	printf("%9s: csp=%#p\n", __func__, csp);

	/*
	 * Overwrite the stack above the function's stack contents.
	 */
	for (ii = 0; ii < STACK_OVERWRITE_SIZE; ii++)
		*((char *)csp + STACK_OVERWRITE_OFFSET + ii) = 'B';
}

int
main(void)
{
	char c;
	void *csp;

	c = 'A';

	printf("%9s: c='%c'\n", __func__, c);
	printf("%9s: &c=0x%#p\n", __func__, &c);

	asm ("mov	%0, csp" : "=C" (csp));
	printf("%9s: csp=%#p\n", __func__, csp);

	overwrite();

	printf("%9s: c='%c'\n", __func__, c);

	/*
	 * Use exit(3) instead of return not to use potentially overwritten
	 * function return address from the stack.
	 */
	exit(0);
}
