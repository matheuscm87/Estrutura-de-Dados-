EXEC = lista

SRC = main.c lista.c

CC = gcc

CFLAGS = -Wall -g

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
	rm -f $(EXEC)
