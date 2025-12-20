CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
INCLUDES = -Iinclude

SRC = src/main.c 
OBJDIR = build
OBJ = $(SRC:src/%.c=$(OBJDIR)/%.o)

TARGET = program

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(TARGET) $(OBJDIR)
