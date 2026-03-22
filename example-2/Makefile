PROG=	use-after-free

all: ${PROG}-cheri
	elfctl -e +cherirevoke ${PROG}-cheri

.include "../common.mk"
