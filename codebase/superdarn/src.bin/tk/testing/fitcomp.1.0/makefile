# Makefile for fitcomp
# =====================
#
#
include $(MAKECFG).$(SYSTEM)

INCLUDE=-I$(IPATH)/base -I$(IPATH)/general -I$(IPATH)/superdarn
OBJS = fitcomp.o

SRC=fitcomp.c

DSTPATH = $(BINPATH)
OUTPUT = fitcomp
LIBS=-loldraw.1 -loldfit.1 -lcfit.1 -lrscan.1 -lradar.1 -lfitacf.1 -lraw.1 -lfit.1 -ldmap.1 -lopt.1 -lrtime.1 -lrcnv.1 -llmfit.1 -lmpfit.1  -lrmath.1 -lfitacfex2.1
SLIB=-lm -lz


include $(MAKEBIN).$(SYSTEM)
