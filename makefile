ifeq ($(OS),Windows_NT)
	EXE=.exe
	RM=cmd /c del
else 
	EXE=
	RM=rm -f
endif

CC=g++

SRCS=$(wildcard ./*.cpp ascii_art/*.cpp board_games/*.cpp utils/*.cpp)
HEADERS=-Iascii_art -Iboard_games -Iutils

TARGET=game

all: $(TARGET)

$(TARGET) : $(SRCS)
	$(CC) $(HEADERS) $(SRCS) -o $(TARGET)$(EXE)

run: $(TARGET)

	./$(TARGET)$(EXE)

clean:
	$(RM) $(TARGET)$(EXE)