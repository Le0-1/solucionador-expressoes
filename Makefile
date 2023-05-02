CC = g++
NAME = program
SRC_DIR = ./src
BIN_DIR = ./bin
INC_DIR = ./include
OBJ_DIR = ./obj
CFLAGS = -Wall -g
EXE = $(BIN_DIR)/$(NAME)

OBJS = \
	$(OBJ_DIR)/Pilha.o \
	$(OBJ_DIR)/Parser.o \
	$(OBJ_DIR)/Resolvedor.o \
	$(OBJ_DIR)/main.o

all: $(EXE)

run : all
	$(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $(EXE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/**/%.cpp $(INC_DIR)/%.hpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.hpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

clean:
	rm -f $(OBJS)
	rm -f $(EXE)