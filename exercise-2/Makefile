CC=	clang-morello-c18n
PROG=	stack-safety

VARIANTS=cheri cheric18n
CFLAGS_CHERIC18N=-ffunction-sections -Wl,--compartment-policy=policy.txt

POLICY=	policy.txt

all: ${PROG}-cheri-elfctl ${PROG}-cheric18n-elfctl

${PROG}-cheri-elfctl: ${PROG}-cheri
	elfctl -e +nocheric18n ${PROG}-cheri

${PROG}-cheric18n-elfctl: ${PROG}-cheric18n
	elfctl -e +cheric18n ${PROG}-cheric18n

.include "../common.mk"
