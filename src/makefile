SRC = core.cc program/console.cc program/splants.cc program/smoosh.cc program/pmoosh.cc program/pplants.cc program/rplayer.cc program/rcreature.cc program/hmoosh.cc

BIN = creature
CC = g++

all: eco
eco:
	$(CC) $(SRC) -o $(BIN)

run:
	./$(BIN)

clean:
	rm -f $(BIN)