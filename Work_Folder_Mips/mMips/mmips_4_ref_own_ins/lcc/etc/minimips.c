#include <string.h>

char *suffixes[] = { ".c", ".i", ".s", ".o", ".out", 0 };
char inputs[256] = "";
char *cpp[] = { 
	LCCDIR "/cpp", 
	"-D__STDC__=1",
	"-DLANGUAGE_C",
	"-DMIPSEB",
	"-D_CFE",
	"-D_LANGUAGE_C",
	"-D_MIPSEB",
	"-D_MIPS_FPSET=16",
	"-D_MIPS_ISA=_MIPS_ISA_MIPS1",
	"-D_MIPS_SIM=_MIPS_SIM_ABI32",
	"-D_MIPS_SZINT=32",
	"-D_MIPS_SZLONG=32",
	"-D_MIPS_SZPTR=32",
	"-D__mips=1",
	"-Dmips",
	"-D__minimips=1",
	"-Dminimips",
	"$1", "$2", "$3", 0 };
char *com[] = 
{ 
	LCCDIR "/rcc", "-target=minimips", "$1", "$2", "$3", "", 0 
};
char *include[] = 
{ 	
	"-I" LCCDIR "/include", 0
};
char *as[] = 
{ 	
	LCCDIR "/mips-as", "-o", "$3", "$1", "$2", 0
};
char *ld[] = 
{ 
	LCCDIR "/mips-ld", 
	"-o", "$3",
	LCCDIR "/crt0.o", "$1", "$2",
	"-T", LCCDIR "/minimips.link", 
	"-L" LCCDIR, "-lc", "-llcc", "-lc", 0
};

extern char *concat(char *, char *);

int option(char *arg) {
	if (strncmp(arg, "-lccdir=", 8) == 0) {
		cpp[0] = concat(&arg[8], "/cpp");
		com[0] = concat(&arg[8], "/rcc");
		include[0] = concat("-I", concat(&arg[8], "/include"));
		as[0] = concat(&arg[8], "/mips-as");
		ld[0] = concat(&arg[8], "/mips-ld");
		ld[3] = concat(&arg[8], "/crt0.o");
		ld[7] = concat(&arg[8], "/minimips.link");
		ld[8] = concat("-L", &arg[8]);
	} else if (strcmp(arg, "-g") == 0)
		;
	else if (strcmp(arg, "-b") == 0)
		;
	else
		return 0;
	return 1;
}
