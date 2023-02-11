CC=gcc
CFLAGS=-I.
LDFLAGS=

SRC=$(wildcard *.c)
DEPS=$(wildcard *.h)
OBJ=$(patsubst %.c, $(ODIR)/%.o, $(SRC))
ODIR=obj

$(ODIR)/%.o: %.c $(DEPS) | $(ODIR)
	@echo "Building $@"
	$(CC) -c -o $@ $< $(CFLAGS)
	@echo "\n"

clox-vm: $(OBJ)
	@echo "Linking object files to create the clox-vm executable..."
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)
	@echo "Done!"

$(ODIR):
	mkdir -p $@

.PHONY: clean
clean:
	rm -rf clox-vm $(ODIR)