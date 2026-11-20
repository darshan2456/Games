ifeq ($(OS),Windows_NT)
	EXE=.exe
	RM=cmd /c del
else
	EXE=
	RM=rm -f
endif

CC=g++

SRCS=$(wildcard ./*.cpp  BoardGames/TicTacToe/*.cpp  BoardGames/ConnectFour/*.cpp utils/*.cpp ArcadeGames/Snake/*.cpp)
HEADERS= -IBoardGames/TicTacToe -IBoardGames/ConnectFour -IArcadeGames/Snake -Iutils

RAYLIB_FLAGS=-I/usr/local/include -L/usr/local/lib
RAYLIB_LIBS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11


TARGET=game

all: $(TARGET)

$(TARGET) : $(SRCS)
	$(CC) $(HEADERS) $(SRCS) -o $(TARGET)$(EXE) $(RAYLIB_FLAGS) $(RAYLIB_LIBS)

run: $(TARGET)

	./$(TARGET)$(EXE)

clean:
	$(RM) $(TARGET)$(EXE)
