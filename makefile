name=midiKeyGen
src=src\/main.c src\/midival.c
winCC=x86_64-w64-mingw32-gcc
winCCOpt=-s
nixCC=gcc
nixCCOpt=-Wall

all:

nix:
	@${nixCC} ${nixCCOpts} ${src} -o ${name}

win64:
	@${winCC} ${winCCOpt} ${src} -o ${name}.exe

clean: clean_nix clean_win

clean_nix:
	@rm -f ${name}

clean_win:
	@rm -f ${name}.exe

debug:
	@${nixCC} ${nixCCOpts} -g ${src} -o ${name}
	@gdb -tui ${name}
