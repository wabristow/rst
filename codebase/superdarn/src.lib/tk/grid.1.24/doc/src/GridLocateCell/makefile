# Makefile for GridLocateCell
# ========================
# by R.J.Barnes
#
#
include $(MAKECFG).$(SYSTEM)

INCLUDE=-I$(IPATH)/base -I$(IPATH)/general -I$(IPATH)/superdarn 
IGNVER=1
OBJS = GridLocateCell.o
OUTPUT = GridLocateCell
LIBS= -lgrd.1 -lrtime.1 -ldmap.1 -lrcnv.1 
SLIB=-lm
 
include $(MAKELIB).$(SYSTEM)
