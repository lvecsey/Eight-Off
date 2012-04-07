
CC=gcc

all: eight-off viewcards description

description : description.o
	$(CC) -o $@ $^

eight-off : LDFLAGS=-L$(HOME)/eight-off/lib -L$(HOME)/gsl-1.15/lib

eight-off : CFLAGS+=-I$(HOME)/eight-off/include -I$(HOME)/gsl-1.15/include

eight-off : CFLAGS+=-Wall -O2

eight-off : LIBS=-lrt -lgsl -lgslcblas

eight-off : eight-off.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

show_card.o : card_names.h

viewcards : LIBS=-lrt

viewcards : CFLAGS+=-I$(HOME)/eight-off/include

viewcards : CFLAGS+=-Wall

viewcards : viewcards.o show_card.o card_names.h
	$(CC) -o $@ $^ $(LIBS)

clean :
	-rm viewcards eight-off *.o

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

