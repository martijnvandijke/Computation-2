
PROCESSOR_H = ../../../processors/minimips-lcc.h
SOFTFLOAT_MACROS = ../softfloat-macros

OBJ = .o
INCLUDES = -I. -I..
COMPILE_C = lcc -w -c -o $@ $(INCLUDES) -I- # -tserial_out
LINK = lcc -o $@

#------------------------------------------------------------------------------
# Probably okay below here.
#------------------------------------------------------------------------------

ALL: softfloat$(OBJ)

milieu.h: $(PROCESSOR_H)
	touch milieu.h

softfloat$(OBJ): milieu.h softfloat.h softfloat-specialize $(SOFTFLOAT_MACROS) ../softfloat.c
	$(COMPILE_C) ../softfloat.c

