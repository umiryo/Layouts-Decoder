TARGET = ldec

CC = gcc
CFLAGS = -Wall -O2

SRC = ldec.c

PREFIX = /usr/local

all: $(TARGET)

$(TARGET): $(SRC)
	@$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

install: $(TARGET)
	@sudo install -m 755 $(TARGET) $(PREFIX)/bin

uninstall:
	@sudo rm -f $(PREFIX)/bin/$(TARGET)

clean:
	@rm -f $(TARGET)
