CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
INCLUDES = -Iinclude

SRC = src/main.c src/student.c
OBJDIR = build
OBJ = $(SRC:src/%.c=$(OBJDIR)/%.o)

TARGET = program

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Regola di compilazione degli object
$(OBJDIR)/%.o: src/%.c include/student.h | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Crea la directory build se non esiste
$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(TARGET) $(OBJDIR)
