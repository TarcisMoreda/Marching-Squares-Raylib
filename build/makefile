CC=clang
CCFLAGS=-g -Wall -O2
LIBS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC=../src
INC=../include
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
HDRS=$(wildcard $(INC)/*.h)
BIN=MarchingSquares

all: $(BIN)

$(BIN): $(OBJS) $(OBJ)
	$(CC) $(CCFLAGS) $(OBJS) -o $(BIN) $(LIBS)

$(OBJ)/%.o: $(SRC)/%.c $(OBJ)
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ)
	$(RM) $(BIN)