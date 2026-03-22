CC?=		cc
CFLAGS=		-g -O0
VARIANTS?=	baseline cheri
CFLAGS_BASELINE=-mabi=aapcs
CFLAGS_CHERI=
POLICY?=

SRCS+=		${PROG}.c

.for variant in ${VARIANTS}
CLEANFILES+=	${PROG}-${variant}

all: ${PROG}-${variant}

${PROG}-${variant}: ${SRCS} ${POLICY}
	${CC} -o ${.TARGET} ${SRCS} ${CFLAGS} ${CFLAGS_${variant:tu}}
.endfor

clean:
	rm -f ${CLEANFILES}

.PHONY: all clean
