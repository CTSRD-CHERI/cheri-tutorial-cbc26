CC=	clang-morello-c18n
PROG=	stack-safety

POLICY=	policy.txt

VARIANTS=cheri cheric18n
CFLAGS_CHERIC18N=-ffunction-sections -Wl,--compartment-policy=${POLICY}

all: ${PROG}-cheri-elfctl ${PROG}-cheric18n-elfctl

${PROG}-cheri-elfctl: ${PROG}-cheri
	elfctl -e +nocheric18n ${PROG}-cheri

${PROG}-cheric18n-elfctl: ${PROG}-cheric18n
	elfctl -e +cheric18n ${PROG}-cheric18n

.include "../common.mk"
