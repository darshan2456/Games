ifeq ($(OS),Windows_NT)
	EXE=.exe
	RM=cmd /c del
else 
	EXE=
	RM=rm -f
endif

CC=gcc

SRCS=$(wildcard *.c)

TARGET=game

all: $(TARGET)

$(TARGET) : $(SRCS)
	$(CC) $(SRCS) -o $(TARGET)$(EXE)

clean:
	$(RM) $(TARGET)$(EXE)