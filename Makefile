CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Iinclude
SRC = $(wildcard src/*.c)
TARGET = student_app

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	-@rm -f $(TARGET) *.o

.PHONY: all clean