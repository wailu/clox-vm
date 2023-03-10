CC=gcc
CFLAGS=-I.
LDFLAGS=

CCPATH=$(shell which $(CC))
$(info CC path: $(CCPATH))

SRC=$(wildcard *.c)
DEP=$(wildcard *.h)
OBJ=$(patsubst %.c, $(ODIR)/%.o, $(SRC))
ODIR=obj

$(ODIR)/%.o: %.c $(DEP) | $(ODIR)
	@echo "Building $@"
	$(CC) -c -o $@ $< $(CFLAGS)

clox-vm: $(OBJ)
	@echo "Linking object files to create the clox-vm executable..."
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)
	@echo "Done!"

$(ODIR):
	mkdir $@

.PHONY: clean
clean:
	rm -rf clox-vm $(ODIR)