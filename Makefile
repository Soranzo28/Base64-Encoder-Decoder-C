CC = gcc
CFLAGS = -Wall -g
TARGET = base64
DEPS = ./src/base64.h

ODIR = ./output

SRCS = $(wildcard ./src/*.c)

OBJS = $(patsubst %.c, $(ODIR)/%.o, $(notdir $(SRCS)))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(ODIR)/%.o: ./src/%.c $(DEPS)
	@mkdir -p $(ODIR) 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)
	rm -rf $(ODIR)