SRC = core.cc program/consoleFormat.cc program/creature.cc program/plants.cc
BIN = creature
CC = g++

all: eco
eco:
	$(CC) $(SRC) -o $(BIN)

run:
	./$(BIN)

clean:
	rm -f $(BIN)