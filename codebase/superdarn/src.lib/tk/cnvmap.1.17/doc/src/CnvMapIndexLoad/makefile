# Makefile for CnvMapIndexLoad
# ============================
# by R.J.Barnes
#
#
include $(MAKECFG).$(SYSTEM)

INCLUDE=-I$(IPATH)/base -I$(IPATH)/general -I$(IPATH)/superdarn 
IGNVER=1
OBJS = CnvMapIndexLoad.o
OUTPUT = CnvMapIndexLoad
LIBS=-lcnvmap.1 -lgrd.1 -lrtime.1 -ldmap.1 -lrcnv.1 
SLIB=-lm
 
include $(MAKELIB).$(SYSTEM)
