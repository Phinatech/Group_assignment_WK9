# Compiler & flags (switch -std=c11 to -std=gnu89 if your checker requires it)
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -std=c11
INCDIR  := include
SRCDIR  := src
BUILDDIR:= build
TARGET  := net_salary

SRC := $(SRCDIR)/main.c $(SRCDIR)/deductions.c $(SRCDIR)/net_salary.c
OBJ := $(SRC:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

.PHONY: all run clean format test

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -I$(INCDIR) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/salary.h
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -rf $(BUILDDIR) $(TARGET)

# Optional: clang-format C files if you use it
format:
	clang-format -i $(SRCDIR)/*.c $(INCDIR)/*.h || true

# Tiny smoke test
test: all
	@echo "350" | ./$(TARGET) | grep -q "Net Salary:" && echo "OK" || (echo "Test failed"; exit 1)