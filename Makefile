CC		:= gcc
CFLAGS	:= -Wall -Wextra -g

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=

SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)
LIBDIRS		:= $(shell find $(LIB) -type d)

CINCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))
CLIBS		:= $(patsubst %,-L%, $(LIBDIRS:%/=%))

SOURCES		:= $(wildcard $(patsubst %,%/*.c, $(SOURCEDIRS)))
OBJECTS		:= $(SOURCES:%.c=%.o)


all: $(BIN)/main $(BIN)/heater $(BIN)/pump $(BIN)/sprayarms 

.PHONY: clean
clean:
	-$(RM) $(BIN)/main
	-$(RM) $(BIN)/heater
	-$(RM) $(BIN)/pump
	-$(RM) $(BIN)/sprayarms
	-$(RM) $(OBJECTS)


run: all
	./$(BIN)/main
	./$(BIN)/heater
	./$(BIN)/pump
	./$(BIN)/sprayarms

$(BIN)/main: $(SOURCEDIRS)/main.o
	$(CC) $(CFLAGS) $(CINCLUDES) $(CLIBS) $^ -o $@ $(LIBRARIES)

$(BIN)/heater: $(SOURCEDIRS)/heater.o
	$(CC) $(CFLAGS) $(CINCLUDES) $(CLIBS) $^ -o $@ $(LIBRARIES)

$(BIN)/pump: $(SOURCEDIRS)/pump.o
	$(CC) $(CFLAGS) $(CINCLUDES) $(CLIBS) $^ -o $@ $(LIBRARIES)

$(BIN)/sprayarms: $(SOURCEDIRS)/sprayarms.o
	$(CC) $(CFLAGS) $(CINCLUDES) $(CLIBS) $^ -o $@ $(LIBRARIES)