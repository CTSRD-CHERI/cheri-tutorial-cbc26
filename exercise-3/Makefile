CC=/usr/local64/llvm-morello-c18n/bin/clang
CFLAGS=-ffunction-sections
CFLAGS+=-target aarch64-unknown-freebsd15.0 -march=morello -mabi=purecap
CFLAGS+=-cheri-codeptr-relocs -Xclang -morello-vararg=new -Xclang -morello-bounded-memargs

all: main.c policy.txt
	${CC} ${CFLAGS} -g main.c -o normal -Wl,--compartment-policy=policy.txt
	cp normal compart
	elfctl -e +nocheric18n ./normal
	elfctl -e +cheric18n ./compart

clean:
	rm -f normal compart *.core
