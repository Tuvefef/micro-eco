SOURCES = core.cpp cppw/eplant.cpp cppw/eplayer.cpp cppw/epreys.cpp cppw/epred.cpp cppw/safemush.cpp cppw/toxicmush.cpp cppw/hallmush.cpp
BIN = micro
CPP = g++

all: eco
eco:
	$(CPP) $(SOURCES) -o $(BIN)

run:
	./$(BIN)

clean:
	rm -f $(BIN)