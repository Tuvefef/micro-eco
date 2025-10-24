SRC = core.cc program/consoleFormat.cc program/creature.cc program/splants.cc program/smoosh.cc program/pmoosh.cc program/pplants.cc

BIN = creature
CC = g++

all: eco
eco:
	$(CC) $(SRC) -o $(BIN)

run:
	./$(BIN)

clean:
	rm -f $(BIN)