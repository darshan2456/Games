ifeq ($(OS),Windows_NT)
	EXE=.exe
	RM=cmd /c del
else
	EXE=
	RM=rm -f
endif

CC=g++

SRCS=$(wildcard ./*.cpp  BoardGames/TicTacToe/*.cpp  BoardGames/ConnectFour/*.cpp utils/*.cpp)
HEADERS= -IBoardGames/TicTacToe -Iutils

TARGET=game

all: $(TARGET)

$(TARGET) : $(SRCS)
	$(CC) $(HEADERS) $(SRCS) -o $(TARGET)$(EXE)

run: $(TARGET)

	./$(TARGET)$(EXE)

clean:
	$(RM) $(TARGET)$(EXE)
