# Makefile
#
# By Jonathon McDonald
PROJ_NAME = hello_open_gl
SRC_DIR = ./source
BIN_DIR = ./bin

# C Compiler
CC = clang

# Includes, libraries
INCS = -I/usr/local/include -I/opt/X11/include
LIBS = -L/usr/local/lib -L/opt/X11/lib

# Linker and compiler flags
CF = -Wall
LF = -framework OpenGL -lglfw3 -lglew

# All source code files
SRCS = $(wildcard $(SRC_DIR)/*.c)

all: $(SRCS) bin
	$(CC) $(SRCS) $(INCS) $(LIBS) $(CF) $(LF) -o $(BIN_DIR)/$(PROJ_NAME)

bin:
	mkdir $@
