
CC=gcc

all: eight-off viewcards

eight-off : LDFLAGS=-L$(HOME)/eight-off/lib -L$(HOME)/gsl-1.15/lib

eight-off : CFLAGS+=-I$(HOME)/eight-off/include -I$(HOME)/gsl-1.15/include

eight-off : LIBS=-lrt -lgsl -lgslcblas

eight-off : eight-off.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

viewcards : LIBS=-lrt

viewcards : CFLAGS+=-I$(HOME)/eight-off/include

viewcards : viewcards.o clientloop_destination.o headers.h.gch
	$(CC) -o $@ $^ $(LIBS)

.PHONY: release
release: viewcards.c eight-off.c headers.h
	@echo Creating tar.bz2 from files $<
	@tar --create \
	--gzip \
	--file=- \
	--exclude=CVS \
	--exclude=semantic.cache \
	--exclude=*~ \
	$< | bzip2 -9 > ../eight-off-snapshot.tar.bz2
	@ls -l ../eight-off-snapshot.tar.bz2

