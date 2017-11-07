name=midiKeyGen
src=midival.c midiheader.c midivlq.c
srcs=$(addprefix src\/, $(src))
winCC=x86_64-w64-mingw32-gcc
winCCOpt=-s
nixCC=gcc
nixCCOpt=-Wall

all: nix

nix:
	@${nixCC} ${nixCCOpts} ${srcs} main.c -o ${name}

win64:
	@${winCC} ${winCCOpt} ${srcs} main.c -o ${name}.exe

clean: clean_nix clean_win
	rm -f tester

clean_nix:
	@rm -f ${name}

clean_win:
	@rm -f ${name}.exe

debug:
	@${nixCC} ${nixCCOpts} -g ${srcs} -o ${name}
	@gdb -tui ${name}

test:
	@${nixCC} ${nixCCOpts} ${srcs} src/tester.c -o tester
	@./tester

test_debug:
	@${nixCC} ${nixCCOpts} -g ${srcs} src/tester.c -o tester
	@gdb -tui tester
