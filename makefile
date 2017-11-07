name=midiKeyGen
src=main.c midival.c midiheader.c midivlq.c
srcs=$(addprefix src\/, $(src))
winCC=x86_64-w64-mingw32-gcc
winCCOpt=-s
nixCC=gcc
nixCCOpt=-Wall

all: nix

nix:
	@${nixCC} ${nixCCOpts} ${srcs} -o ${name}

win64:
	@${winCC} ${winCCOpt} ${srcs} -o ${name}.exe

clean: clean_nix clean_win

clean_nix:
	@rm -f ${name}

clean_win:
	@rm -f ${name}.exe

debug:
	@${nixCC} ${nixCCOpts} -g ${srcs} -o ${name}
	@gdb -tui ${name}
